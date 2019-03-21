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
    connect(ui_->disconnectBtn, &QPushButton::clicked, this, &NxpCarInterface::slotUdpDisconnect);

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

    if (ui_->connectLineAddress->text() != "") {
        client_ = new UDPClient(ui_->connectLineAddress->text(), port, this);
    }
    else {
        client_ = new UDPClient(ui_->connectComboBoxAddress->currentText(), port, this);
    }

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

    ui_->regionSizeLabel->setText(QString::number(sendData.biggestRegion.getSize()));
    ui_->regionCenterLabel->setText(QString::number(sendData.biggestRegion.getCenter()));

	uint8_t blackCount = 0, whiteCount = 0;

	for (int i = 0; i < MIN(sendData.regionsCount, SEND_REGIONS_NUM); i++) {
		if (sendData.regions[i].isWhite()) {
			whiteCount++;
		}
		else {
			blackCount++;
		}
	}

    ui_->blackRegionsCountValueLabel->setText(QString::number(blackCount));
    ui_->whiteRegionsCountValueLabel->setText(QString::number(whiteCount));
    ui_->leftPotLabel->setText(QString::number(serialData.ReadPot_i(0)));
    ui_->rightPotLabel->setText(QString::number((serialData.ReadPot_f(1) + 1.f) / 2.f * 100));

    /*
     *  -----------
     *  Serial data
     *  -----------
     */

    QSize originalHistoryRect = ui_->originalHistory->size();
    int historySize = originalHistoryRect.height();

    ui_->voltageValueLabel->setText(QString::number(serialData.getVoltage(), 'f', 3));
    sDataHistoryList_.push_front(serialData);
    sNxpImageList_.push_front(nxpbc::NxpImage(serialData.image));
    sNxpLinesList_.push_front(std::vector<nxpbc::Region>(std::begin(sendData.regions),
                                                         std::begin(sendData.regions) + sendData.regionsCount));
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
    auto regionsListIterator = sNxpLinesList_.begin();
    auto biggestRegionListIterator = sNxpBiggestRegionsList_.begin();
    for (int i = 0; i < MIN(sNxpLinesList_.size(), sNxpBiggestRegionsList_.size()); i++) {
        //nxpbc::Region biggestWhiteRegion = regionsListIterator->at(0);
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

        for(int pixIdx = biggestRegionListIterator->first.left; pixIdx <= biggestRegionListIterator->first.right; pixIdx++) {
			rgbLinesMat.row(i).at<cv::Vec3b>(pixIdx) = regionColorVec3;
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
