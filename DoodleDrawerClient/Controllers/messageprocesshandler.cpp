#include "messageprocesshandler.h"
#include <QDebug>

MessageProcessHandler::MessageProcessHandler(QObject *parent)
	: QObject{parent}
{
}

void MessageProcessHandler::processMessage(QString message)
{
	// type:uniqueID;payload:4444
	// type:uniqueID;garbage:4444
	// type:newLobbyCreated;payload:1111;clientList:1111,2222,3333
	// type:joinSuccess;payload:111;clientList:1111,2222,3333

	QStringList separated = message.split(QRegExp(";"));
	if (separated.first() == "type:uniqueID")
	{
		// Unique id registration
		qDebug() << "Client App: unique ID Registration " + separated[1];

		separated.pop_front();
		if (separated.front().contains("payload:"))
		{
			QString newClientID = separated.first().remove("payload:");
			qDebug() << "Client App: Id " + newClientID;
			emit uniqueIdRegistration(newClientID);
		}
	}
	else if (separated.first().contains("type:newLobbyCreated") || separated.front().contains("type:joinSuccess"))
	{
		qDebug() << "Client App: New lobby was created";

		QString newLobbyID = QString();
		QStringList lobbyClients = QStringList();

		separated.pop_front();
		if (separated.front().contains("payload:"))
		{
			newLobbyID = separated.first().remove("payload:");
			qDebug() << "Client App: Lobby ID: " + newLobbyID;
			emit newLobby(newLobbyID);
		}

		separated.pop_front();
		if (separated.front().contains("clientList:"))
		{
			QString clients = separated.first();
			clients = clients.remove("clientList:");
			lobbyClients = clients.split(QRegExp(";"));
		}
	}
}
