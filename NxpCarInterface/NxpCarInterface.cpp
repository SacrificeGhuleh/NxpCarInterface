#include "pch.h"
#include "NxpCarInterface.h"
#include <ctime>

long map(long x, long in_min, long in_max, long out_min, long out_max) {
    return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

NxpCarInterface::NxpCarInterface(QWidget* parent) : QMainWindow(parent),
                                                    ui_{new Ui::NxpCarInterfaceClass},
                                                    client_{nullptr},
                                                    historySize_{499},
                                                    imgWidth_{128},
                                                    connected_{false} {
    ui_->setupUi(this);

    QSize originalHistoryRect = ui_->originalHistory->size();
    originalPlotMat_ = cv::Mat(imgWidth_, imgWidth_,CV_8UC3, cv::Scalar(255, 255, 0));

    ui_->originalPlot->setScene(new QGraphicsScene());
    ui_->originalHistory->setScene(new QGraphicsScene());

    ui_->thresholdedHistory->setScene(new QGraphicsScene());
    ui_->thresholdedPlot->setScene(new QGraphicsScene());

    ui_->normalizedHistory->setScene(new QGraphicsScene());
    ui_->normalizedPlot->setScene(new QGraphicsScene());

    ui_->linesHistory->setScene(new QGraphicsScene());

    showMat(ui_->originalPlot, originalPlotMat_);
    showMat(ui_->thresholdedPlot, originalPlotMat_);
    showMat(ui_->normalizedPlot, originalPlotMat_);

    connect(ui_->connectBtn, &QPushButton::clicked, this, &NxpCarInterface::slotUdpConnect);
    //connect(ui_->disconnectBtn, &QPushButton::clicked, this, &NxpCarInterface::slotUdpDisconnect);

}

void NxpCarInterface::slotSerialData(s_data serialData) {
    const clock_t begin_time = clock();

    QSize originalHistoryRect = ui_->originalHistory->size();
    int historySize = originalHistoryRect.height();

    ui_->voltageValueLabel->setText(QString::number(serialData.getVoltage(), 'f', 3));
    sDataHistoryList_.push_front(serialData);
    sNxpImageList_.push_front(nxpbc::NxpImage(serialData.image));
    if (sDataHistoryList_.size() > historySize) {
        sDataHistoryList_.pop_back();
        sNxpImageList_.pop_back();
    }

    cv::Mat imgRawBw = cv::Mat(historySize, imgWidth_, CV_8UC1, cv::Scalar(0));
    cv::Mat imgNormalizedBw = cv::Mat(historySize, imgWidth_, CV_8UC1, cv::Scalar(0));
    cv::Mat imgThresholdedBw = cv::Mat(historySize, imgWidth_, CV_8UC1, cv::Scalar(0));

    std::list<nxpbc::NxpImage>::iterator historyListIterator = sNxpImageList_.begin();

    for (int i = 0; i < historySize; i++) {
        if (i >= sDataHistoryList_.size())
            break;
        cv::Mat imgRawBwRow = imgRawBw.row(i);
        cv::Mat imgNormalizedBwRow = imgNormalizedBw.row(i);
        cv::Mat imgThresholdedBwRow = imgThresholdedBw.row(i);

        for (int j = 0; j < 128; j++) {
            //row.at<unsigned char>(j) = static_cast<unsigned char>(map(it->image[j], 0, 0xfff, 0, 0xff));
            imgRawBwRow.at<unsigned char>(j) = static_cast<unsigned char>(historyListIterator->at(
                j, nxpbc::ImgType::Raw) >> 4);
            imgNormalizedBwRow.at<unsigned char>(j) = static_cast<unsigned char>(historyListIterator->at(
                j, nxpbc::ImgType::Normalized));
            imgThresholdedBwRow.at<unsigned char>(j) = static_cast<unsigned char>(historyListIterator->at(
                j, nxpbc::ImgType::Thresholded));
        }
        ++historyListIterator;
        imgRawBw.row(i) = imgRawBwRow;
        imgNormalizedBw.row(i) = imgNormalizedBwRow;
        imgThresholdedBw.row(i) = imgThresholdedBwRow;
    }
    //imshow("img", imgBw);
    cv::Mat rgbRawMat(historySize, imgWidth_, CV_8UC3, cv::Scalar(0));
    cv::Mat rgbNormalizedMat(historySize, imgWidth_, CV_8UC3, cv::Scalar(0));
    cv::Mat rgbThresholdedMat(historySize, imgWidth_, CV_8UC3, cv::Scalar(0));

    //cv::cvtColor(imgBw, rgbMat, CV_GRAY2RGB);
    cv::cvtColor(imgRawBw, rgbRawMat, cv::COLOR_GRAY2RGB);
    cv::cvtColor(imgNormalizedBw, rgbNormalizedMat, cv::COLOR_GRAY2RGB);
    cv::cvtColor(imgThresholdedBw, rgbThresholdedMat, cv::COLOR_GRAY2RGB);

    showMat(ui_->originalHistory, rgbRawMat);
    showMat(ui_->thresholdedHistory, rgbThresholdedMat);
    showMat(ui_->normalizedHistory, rgbNormalizedMat);

    historyListIterator = sNxpImageList_.begin();

    showMat(ui_->originalPlot, getPlot(historyListIterator->rawImage_, 0, 0xfff));
    showMat(ui_->thresholdedPlot, getPlot(historyListIterator->thresholdedImage_, 0, 0xff));
    showMat(ui_->normalizedPlot, getPlot(historyListIterator->normalizedImage_, 0, 0xff));

    //showMat(ui_->originalHistory, imgBw);
    std::cout << float(clock() - begin_time) / CLOCKS_PER_SEC << "ms\n";
}

void NxpCarInterface::slotSettingData(s_setting data) {}

void NxpCarInterface::slotControlData(s_control controlData) {
    ui_->leftPWMValueLabel->setText(QString::number(controlData.pwm_a));
    ui_->rightPwmValueLabel->setText(QString::number(controlData.pwm_b));

    ui_->servoValueLabel->setText(QString::number(controlData.servo_pos[0]));
}

void NxpCarInterface::slotUdpConnect() {
    if (connected_)
        return;
    //ui_->connectLineAddress->text();
    bool portOk = false;
    int port = ui_->connectPort->text().toInt(&portOk);
    if (!portOk)
        port = 4444;

    client_ = new UDPClient(port, this);
    /*
    if (ui_->connectLineAddress->text() != "") {
        client_ = new UDPClient(ui_->connectLineAddress->text(), port, this);
    }
    else {
    }
    */
    connect(client_, &UDPClient::signalSerialData, this, &NxpCarInterface::slotSerialData);
    connect(client_, &UDPClient::signalSettingData, this, &NxpCarInterface::slotSettingData);
    connect(client_, &UDPClient::signalControlData, this, &NxpCarInterface::slotControlData);
    connect(client_, &UDPClient::signalFreescaleData, this, &NxpCarInterface::slotFreescaleData);

    //client_->helloUdp();
    connected_ = true;

}

void NxpCarInterface::slotUdpDisconnect() {
    if (!connected_)
        return;

    connected_ = false;
}

void NxpCarInterface::resizeEvent(QResizeEvent* event) {
    QWidget::resizeEvent(event);
    QSize originalHistoryRect = ui_->originalHistory->size();
    historySize_ = originalHistoryRect.height();
    std::cout << "original history rect" << originalHistoryRect.width() << " " << originalHistoryRect.height() << "\n";

}

void NxpCarInterface::sendDataToCsv(nxpbc::SendData& data) {
    if (!outFile_.is_open())
        return;

    for (int i = 0; i < nxpbc::anLast; i++) {
        outFile_ << data.adc[i] << ',';

    }

    outFile_ << data.leftPwm << ',';
    outFile_ << data.rightPwm << ',';
    outFile_ << data.motorSpeed << ',';
    outFile_ << data.servo << ',';
    for (int i = 0; i < 3; i++)
        outFile_ << data.accelValues[i] << ',';
    outFile_ << data.gyroValues[0] << ',';
    outFile_ << data.gyroValues[1] << ',';
    outFile_ << data.magnetoValues[0] << ',';
    outFile_ << data.magnetoValues[1] << ',';
    outFile_ << (int)data.currentState << '\n';

}

void NxpCarInterface::showMat(QGraphicsView* view, cv::Mat mat) {

    QGraphicsScene* scene = view->scene();
    scene->clear();

    QGraphicsPixmapItem* item = scene->addPixmap(
        QPixmap::fromImage(QImage(mat.data, mat.cols, mat.rows, QImage::Format_RGB888)));

    item->setPos(0, 0);
    view->setScene(scene);
    //view->fitInView(scene->itemsBoundingRect(), Qt::KeepAspectRatioByExpanding);
    view->show();
}

void NxpCarInterface::slotFreescaleData(nxpbc::SendData sendData) {
    s_data serialData(sendData);
    s_control controlData(sendData);

    //slotSerialData(serialData);
    //slotControlData(controlData);

    const clock_t begin_time = clock();

    /*
     *  ------------
     *  Control data
     *  ------------
     */
    ui_->leftPWMValueLabel->setText(QString::number(controlData.pwm_a));
    ui_->rightPwmValueLabel->setText(QString::number(controlData.pwm_b));
    ui_->servoValueLabel->setText(QString::number(controlData.servo_pos[0]));
    ui_->motorSpeedValueLabel->setText(QString::number(sendData.motorSpeed));
    ui_->errorValueLabel->
         setText(QString::number(static_cast<float>(static_cast<int>(sendData.error * 100.f) / 100.f)));

    ui_->regionSizeLabel->setText(QString::number(sendData.biggestRegion.getSize()));
    ui_->regionCenterLabel->setText(QString::number(sendData.biggestRegion.getCenter()));
    ui_->leftDistanceValueLabel->setText(QString::number(sendData.biggestRegion.left));
    ui_->rightDistanceValueLabel->setText(QString::number(sendData.biggestRegion.right));

    ui_->diversityValueLabel->setText(QString::number(sendData.imageDiversity));

    ui_->leftMedianValueLabel->setText(QString::number(sendData.regionMedian[0]));
    ui_->rightMedianValueLabel->setText(QString::number(sendData.regionMedian[1]));

    ui_->leftAverageValueLabel->setText(QString::number(sendData.regionAverage[0]));
    ui_->rightAverageValueLabel->setText(QString::number(sendData.regionAverage[1]));

    ui_->blackRegionsCountValueLabel->setText(QString::number(sendData.blackRegionsCount));
    ui_->whiteRegionsCountValueLabel->setText(QString::number(sendData.whiteRegionsCount));

    ui_->leftPotLabel->setText(QString::number(serialData.ReadPot_i(0)));

    int pRegulator = ((serialData.ReadPot_f(1) + 1.f) * 100.f) / 2.f;
    /*Zaokrouhlit na desitky*/
    pRegulator /= 10;
    pRegulator *= 10;
    ui_->rightPotLabel->setText(QString::number((serialData.ReadPot_f(1) + 1.f) / 2.f * 100));
#define SHOW_IR_VOLTAGE 0

#if SHOW_IR_VOLTAGE
    ui_->ir1ValueLabel->setText(QString::number((static_cast<float>(sendData.adc[nxpbc::anIR_1])) / static_cast<float>(ADC_MAXVAL) * 3.3f, 'f', 2) + " V");
    ui_->ir2ValueLabel->setText(QString::number((static_cast<float>(sendData.adc[nxpbc::anIR_2])) / static_cast<float>(ADC_MAXVAL) * 3.3f, 'f', 2) + " V");
    ui_->ir3ValueLabel->setText(QString::number((static_cast<float>(sendData.adc[nxpbc::anIR_3])) / static_cast<float>(ADC_MAXVAL) * 3.3f, 'f', 2) + " V");
#else
    ui_->ir1ValueLabel->setText(QString::number(sendData.adc[nxpbc::anIR_1]));
    ui_->ir2ValueLabel->setText(QString::number(sendData.adc[nxpbc::anIR_2]));
    ui_->ir3ValueLabel->setText(QString::number(sendData.adc[nxpbc::anIR_3]));
#endif

    ui_->voltageValueLabel->setText(QString::number(serialData.getVoltage(), 'f', 2) + " V");

    ui_->accel0ValueLabel->setText(QString::number(sendData.accelValues[0], 'f', 2));
    ui_->accel1ValueLabel->setText(QString::number(sendData.accelValues[1], 'f', 2));
    ui_->accel2ValueLabel->setText(QString::number(sendData.accelValues[2], 'f', 2));

    ui_->gyro0ValueLabel->setText(QString::number(sendData.gyroValues[0], 'f', 2));
    ui_->gyro1ValueLabel->setText(QString::number(sendData.gyroValues[1], 'f', 2));

    ui_->angleValueLabel->setText(QString::number(sendData.angle, 'f', 2));

    ui_->mag0ValueLabel->setText(QString::number(sendData.magnetoValues[0], 'f', 2));
    ui_->mag1ValueLabel->setText(QString::number(sendData.magnetoValues[1], 'f', 2));
    ui_->mag2ValueLabel->setText(QString::number(sendData.magnetoValues[2], 'f', 2));

    ui_->leftFeedbackValueLabel->setText(QString::number(sendData.adc[nxpbc::anFB_A]));
    ui_->rightFeedbackValueLabel->setText(QString::number(sendData.adc[nxpbc::anFB_B]));

    QString lbl = "";
    switch (sendData.modeSetting_.mode_) {
    case nxpbc::modeSpeedZone: {
        lbl = "Speed zone";
        break;
    }
    case nxpbc::modeFigEight: {
        lbl = "Fig 8";
        break;
    }
    case nxpbc::modeObstacle: {
        lbl = "Obstacle";
        break;
    }
    case nxpbc::modeRideOne: {
        lbl = "Ride 1";
        break;
    }
    case nxpbc::modeRideTwo: {
        lbl = "Ride 2";
        break;
    }
    case nxpbc::modeRideThree: {
        lbl = "Ride 3";
        break;
    }
    case nxpbc::modeRideSetting: {
        lbl = "Ride setting";
        break;
    }
    case nxpbc::modeDiagBtns: {
        lbl = "Diag btns";
        break;
    }
    case nxpbc::modeDiagServo: {
        lbl = "Diag servo";
        break;
    }
    case nxpbc::modeDiagMotors: {
        lbl = "Diag motors";
        break;
    }
    case nxpbc::modeDiagCam: {
        lbl = "Diag cam";
        break;
    }
    default:
        lbl = "WTF";
        break;
    }

    ui_->modesModeValueLabel->setText(lbl);
    ui_->modesDiffCoefValueLabel->setText(QString::number(sendData.modeSetting_.diffCoef_, 'f', 2));
    ui_->modesPwmBaseValueLabel->setText(QString::number(sendData.modeSetting_.maxSpeed_, 'f', 2));
    ui_->modesPValueLabel->setText(QString::number(sendData.modeSetting_.regulatorP_, 'f', 2));
    ui_->modesIValueLabel->setText(QString::number(sendData.modeSetting_.regulatorI_, 'f', 2));
    ui_->modesDValueLabel->setText(QString::number(sendData.modeSetting_.regulatorD_, 'f', 2));

    /*
     *  -----------
     *  Serial data
     *  -----------
     */

    QSize originalHistoryRect = ui_->originalHistory->size();
    int historySize = originalHistoryRect.height();

    sDataHistoryList_.push_front(serialData);

    nxpbc::NxpImage image = nxpbc::NxpImage(serialData.image);

    ui_->imgMinValueLabel->setText(QString::number(image.min_));
    ui_->imgMaxValueLabel->setText(QString::number(image.max_));
    ui_->imgAvgValueLabel->setText(QString::number(image.threshValue_));

    QString curState;

    switch (sendData.currentState) {
    case 0: {
        if (outFile_.is_open())
            outFile_.close();
        curState = "STOP";
        break;
    }
    case 1: {
        if (!outFile_.is_open()) {
            //outFile_.open(std::string("recording_") + QDateTime::currentDateTime().toString().toStdString()+ std::string(".csv"));
            outFile_.open("recording.csv");

            outFile_ <<
                "pot1,pot2,fb1,fb2,bat,ir1,ir2,ir3,leftPwm,rightPwm,motorSpeed,servo,accelX,accelY,accelZ,gyroX,gyroY,speedX,speedY,state\n";

        }
        curState = "ACCL";
        break;
    }
    case 2: {
        curState = "RIDE";
        break;
    }
    case 3: {
        curState = "DCCL";
        break;
    }
    default: {
        curState = "WTF";
        break;
    }
    }

    sendDataToCsv(sendData);

    ui_->currentStateLabel->setText(curState);

    sNxpImageList_.push_front(image);
    sNxpLinesList_.push_front(std::vector<nxpbc::Region>(std::begin(sendData.regions),
                                                         std::begin(sendData.regions) + sendData.whiteRegionsCount));
    sNxpBiggestRegionsList_.push_front(std::pair<nxpbc::Region, uint8_t>(sendData.biggestRegion, sendData.bits));
    if (sDataHistoryList_.size() > historySize) {
        sDataHistoryList_.pop_back();
        sNxpImageList_.pop_back();
        sNxpLinesList_.pop_back();
        sNxpBiggestRegionsList_.pop_back();
    }

    cv::Mat imgRawBw = cv::Mat(historySize, imgWidth_, CV_8UC1, cv::Scalar(0));
    cv::Mat imgNormalizedBw = cv::Mat(historySize, imgWidth_, CV_8UC1, cv::Scalar(0));
    cv::Mat imgThresholdedBw = cv::Mat(historySize, imgWidth_, CV_8UC1, cv::Scalar(0));

    std::list<nxpbc::NxpImage>::iterator historyListIterator = sNxpImageList_.begin();

    for (int i = 0; i < historySize; i++) {
        if (i >= sDataHistoryList_.size())
            break;
        cv::Mat imgRawBwRow = imgRawBw.row(i);
        cv::Mat imgNormalizedBwRow = imgNormalizedBw.row(i);
        cv::Mat imgThresholdedBwRow = imgThresholdedBw.row(i);

        for (int j = 0; j < 128; j++) {
            //row.at<unsigned char>(j) = static_cast<unsigned char>(map(it->image[j], 0, 0xfff, 0, 0xff));
            imgRawBwRow.at<unsigned char>(j) = static_cast<unsigned char>(historyListIterator->at(
                j, nxpbc::ImgType::Raw) >> 4);
            imgNormalizedBwRow.at<unsigned char>(j) = static_cast<unsigned char>(historyListIterator->at(
                j, nxpbc::ImgType::Normalized));
            imgThresholdedBwRow.at<unsigned char>(j) = static_cast<unsigned char>(historyListIterator->at(
                j, nxpbc::ImgType::Thresholded));
        }
        ++historyListIterator;
        imgRawBw.row(i) = imgRawBwRow;
        imgNormalizedBw.row(i) = imgNormalizedBwRow;
        imgThresholdedBw.row(i) = imgThresholdedBwRow;
    }
    //imshow("img", imgBw);
    cv::Mat rgbRawMat(historySize, imgWidth_, CV_8UC3, cv::Scalar(0));
    cv::Mat rgbNormalizedMat(historySize, imgWidth_, CV_8UC3, cv::Scalar(0));
    cv::Mat rgbThresholdedMat(historySize, imgWidth_, CV_8UC3, cv::Scalar(0));
    //cv::Mat rgbLinesMat(historySize, imgWidth_, CV_8UC3, cv::Scalar(255,255,255));

    //cv::cvtColor(imgBw, rgbMat, CV_GRAY2RGB);
    cv::cvtColor(imgRawBw, rgbRawMat, cv::COLOR_GRAY2RGB);
    cv::cvtColor(imgNormalizedBw, rgbNormalizedMat, cv::COLOR_GRAY2RGB);
    cv::cvtColor(imgThresholdedBw, rgbThresholdedMat, cv::COLOR_GRAY2RGB);
    cv::Mat rgbLinesMat = rgbRawMat.clone();

#define EDGE_COLOR cv::Vec3b(0,128,128)
#define CENTER_COLOR cv::Vec3b(128,0,128)

#define BIGGEST_CENTER_COLOR_FOUND cv::Vec3b(255,0,0)       //cervena
#define BIGGEST_EDGE_COLOR_FOUND cv::Vec3b(0,0,255)         //modra
#define BIGGEST_CENTER_COLOR_COMPUTED cv::Vec3b(255,255,0)  //zluta
#define BIGGEST_EDGE_COLOR_COMPUTED cv::Vec3b(255,0,255)    //ruzova

#define SHOW_LINES 1

#if SHOW_LINES

	//cv::Mat alphaOverlay = rgbLinesMat.clone();
	//alphaOverlay = { 0 };

    auto regionsListIterator = sNxpLinesList_.begin();
    auto biggestRegionListIterator = sNxpBiggestRegionsList_.begin();
    for (int i = 0; i < MIN(sNxpLinesList_.size(), sNxpBiggestRegionsList_.size()); i++) {
        //nxpbc::Region biggestWhiteRegion = regionsListIterator->at(0);
        
        /*
         * Vykresleni vsech regionu
         */
        for (nxpbc::Region r : *regionsListIterator) {
            rgbLinesMat.row(i).at<cv::Vec3b>(r.left) = EDGE_COLOR;
            rgbLinesMat.row(i).at<cv::Vec3b>(r.right) = EDGE_COLOR;
            rgbLinesMat.row(i).at<cv::Vec3b>(r.getCenter()) = CENTER_COLOR;
        }

        /*
         * If turning
         */

        
        cv::Vec3b regionColorVec3;
        if (biggestRegionListIterator->second & 1 << 1) {
            regionColorVec3 = cv::Vec3b(128, 0, 0);
        }
        else {
            regionColorVec3 = cv::Vec3b(0, 128, 0);
        }
        
        for (int pixIdx = biggestRegionListIterator->first.left; pixIdx <= biggestRegionListIterator->first.right;
             pixIdx++) {
			/*alphaOverlay*/rgbLinesMat.row(i).at<cv::Vec3b>(pixIdx) = regionColorVec3;
        }
        
        if (!biggestRegionListIterator->second & 1 << 0) {
            for (int bold = -1; bold <= 1; bold++) {
                rgbLinesMat.row(i).at<cv::Vec3b>(biggestRegionListIterator->first.left + bold) =
                    BIGGEST_EDGE_COLOR_FOUND;
                rgbLinesMat.row(i).at<cv::Vec3b>(biggestRegionListIterator->first.right + bold) =
                    BIGGEST_EDGE_COLOR_FOUND;
                rgbLinesMat.row(i).at<cv::Vec3b>(biggestRegionListIterator->first.getCenter() + bold) =
                    BIGGEST_CENTER_COLOR_FOUND;
            }
        }
        else {
            for (int bold = -1; bold <= 1; bold++) {
                rgbLinesMat.row(i).at<cv::Vec3b>(biggestRegionListIterator->first.left + bold) =
                    BIGGEST_EDGE_COLOR_COMPUTED;
                rgbLinesMat.row(i).at<cv::Vec3b>(biggestRegionListIterator->first.right + bold) =
                    BIGGEST_EDGE_COLOR_COMPUTED;
                rgbLinesMat.row(i).at<cv::Vec3b>(biggestRegionListIterator->first.getCenter() + bold) =
                    BIGGEST_CENTER_COLOR_COMPUTED;
            }
        }
        
        ++regionsListIterator;
        ++biggestRegionListIterator;
    }
	double alpha = 0.3f;
	//cv::addWeighted(rgbLinesMat, alpha, alphaOverlay, 1.0 - alpha, 0.0, rgbLinesMat);
#endif
    showMat(ui_->originalHistory, rgbRawMat);
    showMat(ui_->thresholdedHistory, rgbThresholdedMat);
    showMat(ui_->normalizedHistory, rgbNormalizedMat);
    showMat(ui_->linesHistory, rgbLinesMat);

    historyListIterator = sNxpImageList_.begin();

    showMat(ui_->originalPlot, getPlot(historyListIterator->rawImage_, 0, 0xfff));
    showMat(ui_->thresholdedPlot, getPlot(historyListIterator->thresholdedImage_, 0, 0xff));
    showMat(ui_->normalizedPlot, getPlot(historyListIterator->normalizedImage_, 0, 0xff));

    //showMat(ui_->originalHistory, imgBw);
    std::cout << float(clock() - begin_time) / CLOCKS_PER_SEC << "ms\n";

}
