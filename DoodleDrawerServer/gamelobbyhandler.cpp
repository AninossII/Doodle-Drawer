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
