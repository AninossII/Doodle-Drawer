#ifndef GAMELOBBYHANDLER_H
#define GAMELOBBYHANDLER_H

#include <QObject>

class GameLobbyHandler : public QObject
{
    Q_OBJECT
public:
    explicit GameLobbyHandler(QString lobbyID, QObject *parent);
    void addClient( QString clientID );
    QString clientInLobby();

signals:

private:
    QList< QString > m_gameClientList;
    QString m_lobbyID;
};

#endif // GAMELOBBYHANDLER_H
