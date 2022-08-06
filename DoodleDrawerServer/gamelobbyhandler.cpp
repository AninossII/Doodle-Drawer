#include "gamelobbyhandler.h"

GameLobbyHandler::GameLobbyHandler(QString lobbyID, QObject* parent)
    :QObject{ parent }, m_lobbyID(lobbyID)
{

}

void GameLobbyHandler::addClient(QString clientID)
{
    if(!m_gameClientList.contains(clientID))
        m_gameClientList.append(clientID);
}

QString GameLobbyHandler::clientInLobby()
{
    QString ret;
    foreach(const QString & client, m_gameClientList)
        ret.append(client + ",");

    ret.chop(1);
	return ret;
}
