#include "gamemanager.h"
#include <QDebug>

GameManager::GameManager(QObject *parent)
	: QObject{parent}, m_clientID(QString()), m_clientInLobby(QStringList()), m_roomLobbyCode(QString())
{
	m_messageHandler = new MessageProcessHandler(this);
	connect(m_messageHandler, &MessageProcessHandler::uniqueIdRegistration, this, &GameManager::registerUniqueID);
	connect(m_messageHandler, &MessageProcessHandler::newLobby, this, &GameManager::lobbyJoined);
	connect(m_messageHandler, &MessageProcessHandler::updateClientList, this, &GameManager::setClientsInLobby);
}

GameManager::~GameManager()
{
	m_messageHandler->deleteLater();
}

QString GameManager::roomLobbyCode()
{
	return m_roomLobbyCode;
}

QStringList GameManager::clientsInLobby()
{
	return m_clientInLobby;
}

void GameManager::createGameRequest()
{
	//"type:createGame;payLoad:0;sender:1111"
	emit newMessageReadyToSend("type:createGame;payLoad:0;sender:" + m_clientID);
}

void GameManager::joinLobbyRequest(QString lobbyID)
{
	// type:joinGame;payLoad:4000;sender:5555
	emit newMessageReadyToSend("type:joinGame;payLoad:" + lobbyID + ";sender:" + m_clientID);
}

void GameManager::setRoomLobbyCode(QString lobbyCode)
{
	if (m_roomLobbyCode != lobbyCode)
	{
		m_roomLobbyCode = lobbyCode;
		emit roomLobbyCodeChanged();
	}
}

void GameManager::setClientsInLobby(QStringList clientsList)
{
	if (m_clientInLobby != clientsList)
	{
		m_clientInLobby = clientsList;
		emit clientsInLobbyChanged();
	}
}

void GameManager::processSocketMessage(QString message)
{
	m_messageHandler->processMessage(message);
}

void GameManager::registerUniqueID(QString uniqueID)
{
	qDebug() << "Client App: Unique ID received: " + uniqueID;
	m_clientID = uniqueID;
}

void GameManager::lobbyJoined(QString lobbyID, QStringList clients)
{
	setRoomLobbyCode(lobbyID);
	setClientsInLobby(clients);
	emit inGameLobby();
}
