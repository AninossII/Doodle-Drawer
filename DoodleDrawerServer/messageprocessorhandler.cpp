#include "messageprocessorhandler.h"
#include <QDebug>

MessageProcessorHandler::MessageProcessorHandler(QObject *parent)
    : QObject{parent}
{

}

void MessageProcessorHandler::processMessage(QString message)
{
    //type:createGame;payLoad:0;sender:5555
    //type:joinGame;payLoad:4000;sender:5555
    //type:message;payLoad:HelloWOrld;sender:5555
    
    QStringList separated = message.split(QRegExp(";"));
    if(separated.first() == "type:createGame"){
        //Create Game
        separated.pop_front();
        separated.pop_front();
        if(separated.front().contains("sender:"))
        {
            QString senderID = separated.front();
            senderID = senderID.remove("sender:");

        	qDebug() << "Server: Create game request";
        	emit createGameRequest(senderID);
        }       
    }else if(separated.first() == "type:joinGame"){
        //Join Game
        separated.pop_front();
        QString lobbyID;
        if(separated.front().contains("payLoad:"))
        {
            lobbyID = separated.front();
            lobbyID = lobbyID.remove("payLoad:");
            separated.pop_front();

            if (separated.front().contains("sender:"))
            {
                QString senderID = separated.front();
                senderID = senderID.remove("sender:");

                qDebug() << "Server: Join game request";
                emit joinGameRequest(lobbyID, senderID);
            }
        }       
        
    }else if(separated.first() == "type:message"){
        //Message to lobby
        qDebug() << "Server: Message request";
    }
    //qDebug() << "Server: Type" << separated.first();
    //qDebug() << "Server: PayLoad" << separated[1];
    //qDebug() << "Server: Sender" << separated.last();
    //qDebug() << "Server: Message to Process " << message;
}
