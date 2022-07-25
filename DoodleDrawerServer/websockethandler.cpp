#include "websockethandler.h"
#include <random>
#include <QDateTime>
#include <QDebug>

using namespace std;

WebSocketHandler::WebSocketHandler(QObject *parent) : QObject{parent}
{
    m_socketServer = new QWebSocketServer("DoodleDrawerServer", QWebSocketServer::NonSecureMode, this);

    connect(m_socketServer, &QWebSocketServer::newConnection, this, &WebSocketHandler::onNewSocketConnection);

    if(m_socketServer->listen(QHostAddress::Any, 9000)){
        qDebug() <<"Server runing on port: " << m_socketServer->serverPort();
    }else{
        qDebug() <<"Server unable to start";
    }
}

WebSocketHandler::~WebSocketHandler()
{
    m_socketServer->deleteLater();
}


void WebSocketHandler::onNewSocketConnection(){

    // Generate Random Client ID
    default_random_engine generator;
    generator.seed( QDateTime::currentMSecsSinceEpoch() );

    uniform_int_distribution<int> idGenerator(1000,9999);
    QString newClientID = QString::number( idGenerator( generator ) );

    while(m_clientList.keys().contains( newClientID ) ){
        newClientID = QString::number( idGenerator( generator ) );
    }

    // New Client Functionality 
    auto nextClient= m_socketServer->nextPendingConnection();
    nextClient->setParent(this);

    connect(nextClient, &QWebSocket::textMessageReceived, this, &WebSocketHandler::onTextMessageRecived);
    connect(nextClient, &QWebSocket::disconnected, this, &WebSocketHandler::onSocketDisconnected);

    // Sending id to Client App
    nextClient->sendTextMessage("type:uniqueID;payload:"+newClientID);

    // Add the new client to ClientList
    m_clientList[ newClientID ] = nextClient;
    qDebug() << "Server: New client ID: " <<  newClientID << " connected!";
}

// Receiving message from Client App
void WebSocketHandler::onTextMessageRecived(QString message)
{
    qDebug() << "Server: Received new client message:" << message;
    emit newMessageToProcess( message );
}

// Send text message to Client App
void WebSocketHandler::sendTextMessageToClient(QString message, QString clientID)
{
    if (m_clientList.contains(clientID))
    {
        QWebSocket* existingClient = m_clientList[clientID];
        existingClient->sendTextMessage(message);
    }
}

// Deleting client from ClientList
void WebSocketHandler::onSocketDisconnected()
{
    auto client = qobject_cast<QWebSocket*>(sender());
    if(client){        
        for(QMap<QString, QWebSocket*>::iterator mapIterator = m_clientList.begin();
            mapIterator != m_clientList.end();
            mapIterator ++){
            if(mapIterator.value() == client){
                QString id = mapIterator.key();
                m_clientList.remove( id );
                qDebug() << "Server: Client ID:" << id << " Desconnected!";
                client->deleteLater();
            }
        }
    }
}
