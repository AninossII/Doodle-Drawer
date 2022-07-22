#include "messageprocesshandler.h"
#include <QDebug>
MessageProcessHandler::MessageProcessHandler(QObject *parent)
    : QObject{parent}
{

}

void MessageProcessHandler::processMessage(QString message)
{
    //type:uniqueID;payload:4444
    //type:uniqueID;garbage:4444
    QRegularExpression ex(";");
    QStringList separated = message.split( ex );
    if(separated.first() == "type:uniqueID"){
        //Unique id registration
        qDebug() << "Client App: unique ID Registration " + separated[1];
        separated.pop_front();
        if(separated.front().contains( "payload:" )){
            QString newClientID = separated.first();
            newClientID = newClientID.remove("payload:");
            qDebug() << "Client App: Id " + newClientID;
            emit uniqueIdRegistration(newClientID);
        }
    }
}
