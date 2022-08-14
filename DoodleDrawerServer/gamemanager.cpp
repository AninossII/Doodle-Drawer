#include "gamemanager.h"
#include <random>
#include <QDate>

GameManager::GameManager(QObject *parent) : QObject{parent}
{
    m_socketHandler = new WebSocketHandler(this);
    m_messageProcessHandler = new MessageProcessorHandler(this);

    connect(m_socketHandler, &WebSocketHandler::newMessageToProcess, m_messageProcessHandler, &MessageProcessorHandler::processMessage);
    connect(m_messageProcessHandler, &MessageProcessorHandler::createGameRequest, this, &GameManager::createGameLobbyRequest);
    connect(m_messageProcessHandler, &MessageProcessorHandler::joinGameRequest, this, &GameManager::joinGameLobbyRequest);  
}

GameManager::~GameManager()
{
    m_socketHandler->deleteLater();
}

void GameManager::createGameLobbyRequest(QString uniqueID)
{
    // Generate Random Client ID
    default_random_engine generator;
    generator.seed(QDateTime::currentMSecsSinceEpoch());

    uniform_int_distribution<int> idGenerator(1000, 9999);
    QString newLobbyID = QString::number(idGenerator(generator));

    while (m_gameLobbyMap.keys().contains(newLobbyID))
    {
        newLobbyID = QString::number(idGenerator(generator));
    }

    GameLobbyHandler *newGameLobby = new GameLobbyHandler(newLobbyID, this);
    newGameLobby->addClient(uniqueID);

    m_gameLobbyMap[newLobbyID] = newGameLobby;

    qDebug() << "Server: New game lobby ID: " << newLobbyID << " Created";
    m_socketHandler->sendTextMessageToClient("type:newLobbyCreated;payload:" + newLobbyID + ";clientList:" + newGameLobby->clientInLobby(), uniqueID);
}

void GameManager::joinGameLobbyRequest(QString lobbyID, QString uniqueID)
{
    if (m_gameLobbyMap.contains(lobbyID))
    {
        GameLobbyHandler *existingLobby = m_gameLobbyMap[lobbyID];
        existingLobby->addClient(uniqueID);

        qDebug() << "Server: Lobby List Updated";
        m_socketHandler->sendTextMessageToClients("type:updatedClientList;payload:" + existingLobby->clientInLobby(), existingLobby->clientInLobbyList());
        m_socketHandler->sendTextMessageToClient("type:joinSuccess;payload:" + lobbyID + ";clientList:" + existingLobby->clientInLobby(), uniqueID);
    }
    else
    {
        m_socketHandler->sendTextMessageToClient("type:joinError;payload:DNE", uniqueID);
    }
}