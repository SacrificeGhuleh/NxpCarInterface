#pragma once

#include "ui_NxpCarInterface.h"
#include "UDPClient.h"
#include "NxpImage.h"
#include "Region.h"

namespace cv {
    class Mat;
}

class NxpCarInterface : public QMainWindow {
Q_OBJECT

public:
    NxpCarInterface(QWidget* parent = Q_NULLPTR);

public slots:
    void slotSerialData(s_data serialData);
    void slotSettingData(s_setting data);
    void slotControlData(s_control controlData);
    void slotFreescaleData(nxpbc::SendData sendData);
    void slotUdpConnect();
    void slotUdpDisconnect();
public:
    void resizeEvent(QResizeEvent* event) override;
private:
    Ui::NxpCarInterfaceClass* ui_;
    UDPClient* client_;

    cv::Mat originalPlotMat_;
    cv::Mat thresholdedPlotMat_;

    cv::Mat originalHistoryMat_;
    cv::Mat thresholdedHistoryMat_;
    cv::Mat servoHistoryMat_;
    cv::Mat leftPwmHistoryMat_;
    cv::Mat rightPwmHistoryMat_;
    cv::Mat voltagePwmHistoryMat_;

    int historySize_;
    int imgWidth_;

    std::list<s_data> sDataHistoryList_;

    std::list<nxpbc::NxpImage> sNxpImageList_;
    std::list<std::vector<nxpbc::Region>> sNxpLinesList_;
    std::list<std::pair<nxpbc::Region, uint8_t>> sNxpBiggestRegionsList_;

    bool connected_;


    void showMat(QGraphicsView* view, cv::Mat mat);

	template <typename T, size_t size>
    cv::Mat getPlot(const T(&vals)[size], uint min, uint max) {
		auto it = std::minmax_element(std::begin(vals), std::end(vals));
		float scale = 1. / ceil(*it.second - *it.first);
		float bias = *it.first;
		uint YRange[2] = { MIN(min, max),MAX(min,max) };
		int rows = YRange[1] - YRange[0] + 1;
		cv::Mat image = cv::Mat::zeros(rows, 128, CV_8UC3);
		image.setTo(0);
		for (int i = 0; i < (int)size - 1; i++)
		{
			cv::line(image, cv::Point(i, rows - 1 - (vals[i] - bias)*scale*YRange[1]), cv::Point(i + 1, rows - 1 - (vals[i + 1] - bias)*scale*YRange[1]), cv::Scalar(255, 0, 0), 1);
		}

		return image;
	}
    //cv::Mat getPlot(uint8_t(&rawImage)[CAMERA_LINE_LENGTH]/*, int YRange[2]*/);
};
