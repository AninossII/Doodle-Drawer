#include "gamelobbyhandler.h"

GameLobbyHandler::GameLobbyHandler(QObject *parent)
    : QObject{parent}
{

}

void GameLobbyHandler::addClient(QString clientID)
{
    if(m_gameClientList.contains(clientID))
        m_gameClientList.append(clientID);
}
