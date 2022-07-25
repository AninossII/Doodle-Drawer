#include "messageprocesshandler.h"
#include <QDebug>

MessageProcessHandler::MessageProcessHandler(QObject* parent)
	: QObject{parent}
{
}

void MessageProcessHandler::processMessage(QString message)
{
	//type:uniqueID;payload:4444
	//type:uniqueID;garbage:4444
	//type:newLobbyCreated;payload:1111
	//type:joinSuccess;payload:111

	QStringList separated = message.split(QRegExp(";"));
	if (separated.first() == "type:uniqueID")
	{
		//Unique id registration
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

		separated.pop_front();
		if (separated.front().contains("payload:"))
		{
			QString newLobbyID = separated.first().remove("payload:");
			qDebug() << "Client App: Lobby ID: " + newLobbyID;
			emit newLobby( newLobbyID);
		}
	}
}
