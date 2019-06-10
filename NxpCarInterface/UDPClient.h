#ifndef NXP_UDP_CLIENT_H
#define NXP_UDP_CLIENT_H

#include <QUdpSocket>
#include "s_data.h"
#include "../../../CLionProjects/RemoteNxpCupRaspi/src/NxpSendFrame.h"

class UDPClient : public QObject {
Q_OBJECT

public:
    UDPClient(QString address, int port, QObject* parent);
    UDPClient(int port, QObject* parent);
    ~UDPClient();

    void helloUdp();

signals:
    void signalSerialData(s_data data);
    void signalSettingData(s_setting data);
    void signalControlData(s_control data);
    void signalFreescaleData(nxpbc::SendData data);
public slots:
    void readyRead();

private:
    QUdpSocket* socket_;

    int port_;
    QHostAddress hostAddress_;
};

#endif
