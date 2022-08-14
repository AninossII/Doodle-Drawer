#pragma once

#include <QObject>

#include "Controllers/messageprocesshandler.h"

class GameManager : public QObject
{
	Q_OBJECT
	Q_PROPERTY(QString roomLobbyCode READ roomLobbyCode WRITE setRoomLobbyCode NOTIFY roomLobbyCodeChanged)
	Q_PROPERTY(QStringList clientsInLobby READ clientsInLobby WRITE setClientsInLobby NOTIFY clientsInLobbyChanged)

public:
	GameManager(QObject *parent = nullptr);
	~GameManager();

	QString roomLobbyCode();
	QStringList clientsInLobby();
	Q_INVOKABLE void createGameRequest();
	Q_INVOKABLE void joinLobbyRequest(QString lobbyID);

public slots:
	void setRoomLobbyCode(QString lobbyCode);
	void setClientsInLobby(QStringList clientsList);

	void processSocketMessage(QString message);
	void registerUniqueID(QString uniqueID);

	void lobbyJoined(QString lobbyID, QStringList clients);

signals:
	void roomLobbyCodeChanged();
	void clientsInLobbyChanged();

	void newMessageReadyToSend(QString message);
	void inGameLobby();

private:
	QString m_clientID;
	QStringList m_clientInLobby;
	QString m_roomLobbyCode;
	MessageProcessHandler *m_messageHandler;
};
