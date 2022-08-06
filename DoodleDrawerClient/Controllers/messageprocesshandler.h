#ifndef MESSAGEPROCESSHANDLER_H
#define MESSAGEPROCESSHANDLER_H

#include <QObject>

class MessageProcessHandler : public QObject
{
    Q_OBJECT
public:
    explicit MessageProcessHandler(QObject *parent = nullptr);


    void processMessage( QString message);

signals:
    void uniqueIdRegistration( QString uniqueID );
    void newLobby(QString lobbyID, QStringList clients);
};

#endif // MESSAGEPROCESSHANDLER_H
