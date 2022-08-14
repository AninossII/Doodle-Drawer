#include "websockethandler.h"
#include <QDebug>

WebSocketHandler::WebSocketHandler(QObject *parent)
    : QObject{parent}
{
    m_webSocket = new QWebSocket();

    connect(m_webSocket, &QWebSocket::connected, this, &WebSocketHandler::onConnected);
    connect(m_webSocket, &QWebSocket::textMessageReceived, this, &WebSocketHandler::onTextMessageReceived);
}

WebSocketHandler::~WebSocketHandler()
{
    m_webSocket->deleteLater();
}

void WebSocketHandler::connectToServer(QString hostAddress)
{
    m_webSocket->open(hostAddress);
    qDebug() << "Client App: Connecting to server " << hostAddress;
}

void WebSocketHandler::onConnected()
{
    qDebug() << "Client App: connection established!";
    // m_webSocket->sendTextMessage("type:createGame;payload:0;sender:Anas");
}

// Receiving message from Server
void WebSocketHandler::onTextMessageReceived(QString message)
{
    qDebug() << "Client App: Received message " << message;
    emit newMessageReadyForProcessing(message);
}

void WebSocketHandler::sendMessageToServer(QString message)
{
    m_webSocket->sendTextMessage(message);
}
