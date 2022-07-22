#include "gamemanager.h"

GameManager::GameManager(QObject *parent): QObject{parent}
{
    m_socketHandler = new WebSocketHandler( this );
    m_messageProcessHandler = new MessageProcessorHandler( this );

    connect(m_socketHandler, &WebSocketHandler::newMessageToProcess, m_messageProcessHandler, &MessageProcessorHandler::processMessage);
}

GameManager::~GameManager()
{
    m_socketHandler->deleteLater();
}
