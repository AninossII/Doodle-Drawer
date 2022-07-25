#pragma once

#include <QObject>

#include "Controllers/messageprocesshandler.h"

class GameManager  : public QObject
{
	Q_OBJECT
	Q_PROPERTY(QString roomLobbyCode READ roomLobbyCode WRITE setRoomLobbyCode NOTIFY roomLobbyCodeChanged)

public:
	GameManager(QObject* parent = nullptr);
	~GameManager();

	QString roomLobbyCode();
	Q_INVOKABLE void createGameRequest();

public slots:
	void setRoomLobbyCode(QString lobbyCode);
	void processSocketMessage(QString message);
	void registerUniqueID(QString uniqueID);

	void lobbyJoined(QString lobbyID);

signals:
	void roomLobbyCodeChanged();
	void newMessageReadyToSend(QString message);
	void inGameLobby();

private:
	QString m_clientID;
	QString m_roomLobbyCode;
	MessageProcessHandler* m_messageHandler;
};
