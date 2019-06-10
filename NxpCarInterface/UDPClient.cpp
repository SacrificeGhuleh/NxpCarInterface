#include "pch.h"
#include "UDPClient.h"
#include "../../../CLionProjects/RemoteNxpCupRaspi/src/NxpSendFrame.h"

UDPClient::UDPClient(QString address, int port, QObject* parent): QObject(parent),
                                                                  socket_{new QUdpSocket(this)},
                                                                  hostAddress_{QHostAddress(address)},
                                                                  port_{port} {

    // create a QUDP socket
    //socket = new QUdpSocket(this);

    // The most common way to use QUdpSocket class is 
    // to bind to an address and port using bind()
    // bool QAbstractSocket::bind(const QHostAddress & address, 
    //     quint16 port = 0, BindMode mode = DefaultForPlatform)
    //socket_->bind(hostAddress_, port);
    socket_->bind(QHostAddress::Any, port, QUdpSocket::ShareAddress);

    connect(socket_, &QUdpSocket::readyRead, this, &UDPClient::readyRead);
}

UDPClient::UDPClient(int port, QObject* parent) : QObject(parent),
                                                  socket_{new QUdpSocket(this)},
                                                  hostAddress_{QHostAddress::Any},
                                                  port_{port} {

    // create a QUDP socket
    //socket = new QUdpSocket(this);

    // The most common way to use QUdpSocket class is 
    // to bind to an address and port using bind()
    // bool QAbstractSocket::bind(const QHostAddress & address, 
    //     quint16 port = 0, BindMode mode = DefaultForPlatform)
    //socket_->bind(hostAddress_, port);
    socket_->bind(QHostAddress::Any, port, QUdpSocket::ShareAddress);

    connect(socket_, &QUdpSocket::readyRead, this, &UDPClient::readyRead);
}

UDPClient::~UDPClient() {}

void UDPClient::helloUdp() {
    QByteArray Data;
    Data.append("Hello from UDP");

    // Sends the datagram datagram 
    // to the host address and at port.
    // qint64 QUdpSocket::writeDatagram(const QByteArray & datagram, 
    //                      const QHostAddress & host, quint16 port)
    socket_->writeDatagram(Data, hostAddress_, port_);
}

void UDPClient::readyRead() {
    // when data comes in
    QByteArray buffer;
    buffer.resize(socket_->pendingDatagramSize());

    QHostAddress sender;
    quint16 senderPort;

    // qint64 QUdpSocket::readDatagram(char * data, qint64 maxSize, 
    //                 QHostAddress * address = 0, quint16 * port = 0)
    // Receives a datagram no larger than maxSize bytes and stores it in data. 
    // The sender's host address and port is stored in *address and *port 
    // (unless the pointers are 0).

    socket_->readDatagram(buffer.data(), buffer.size(), &sender, &senderPort);

    //std::cout << "Received " << buffer.size() << " bytes: " << buffer.toStdString() << std::endl;

    if (buffer.size() <= 1)
        return;

    if (buffer.size() == sizeof(nxpbc::SendData)) {
        const nxpbc::SendData data = *reinterpret_cast<nxpbc::SendData*>(buffer.data());
        //memcpy(buffer.data(), &data, sizeof(SendData));

        emit signalFreescaleData(data);
        /*
        s_data sData(data);
        //s_setting sSetting(data);
        s_control sControl(data);
        //emit signalFreescaleData(data);

        emit signalSerialData(sData);
        emit signalControlData(sControl);*/
        return;
    }

    if (!(buffer.at(0) == static_cast<char>(STX) && buffer.at(buffer.size() - 1) == static_cast<char>(ETX)))
        return;

    buffer.remove(buffer.size() - 1, 1);
    buffer.remove(0, 4);

    char cmd = buffer.at(3);

    switch (cmd) {
    case CMD_DATA: {
        const s_data data(reinterpret_cast<s_data*>(buffer.data()));
        emit signalSerialData(data);
        break;
    }
    case CMD_SETTING: {
        const s_setting data(reinterpret_cast<s_setting*>(buffer.data()));
        emit signalSettingData(data);
        break;
    }
    case CMD_CONTROL: {
        const s_control data(reinterpret_cast<s_control*>(buffer.data()));
        emit signalControlData(data);
        break;
    }
    default:
        break;
    }
}
