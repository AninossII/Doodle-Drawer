#include "websockethandler.h"
#include <QDebug>
WebSocketHandler::WebSocketHandler(QObject *parent)
    : QObject{parent}
    , m_clientID( QString() )
{
    m_webSocket = new QWebSocket();
    m_messageProcessor = new MessageProcessHandler( this );

    connect(m_webSocket, &QWebSocket::connected, this, &WebSocketHandler::onConnected);
    connect(m_webSocket, &QWebSocket::textMessageReceived, this, &WebSocketHandler::onTextMessageReceived);
    connect(m_messageProcessor, &MessageProcessHandler::uniqueIdRegistration, this, &WebSocketHandler::registerID);
}

WebSocketHandler::~WebSocketHandler(){
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
    //m_webSocket->sendTextMessage("type:createGame;payload:0;sender:anas");
}

void WebSocketHandler::onTextMessageReceived(QString message)
{
    qDebug() << "Client App: Received message " << message;
    m_messageProcessor->processMessage( message );
}

void WebSocketHandler::registerID(QString id)
{
    m_clientID = id;
    qDebug() << "Client App: New client id: " + m_clientID;
}
