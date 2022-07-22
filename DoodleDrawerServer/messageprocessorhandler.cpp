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
    QRegularExpression ex( ";" );
    QStringList separated = message.split( ex );
    if(separated.first() == "type:createGame"){
        //Create Game
        qDebug() << "Server: Create game requist";
    }else if(separated.first() == "type:joinGame"){
        //Join Game
        qDebug() << "Server: Join game requist";
    }else if(separated.first() == "type:message"){
        //Message to lobby
        qDebug() << "Server: Message requist";
    }
    //qDebug() << "Server: Type" << separated.first();
    //qDebug() << "Server: PayLoad" << separated[1];
    //qDebug() << "Server: Sender" << separated.last();
    //qDebug() << "Server: Message to Process " << message;
}
