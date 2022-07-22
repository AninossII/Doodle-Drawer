#ifndef WEBSOCKETHANDLER_H
#define WEBSOCKETHANDLER_H

#include <QObject>
#include <QtWebSockets/QWebSocketServer>
#include <QtWebSockets/QWebSocket>
#include <QMap>

class WebSocketHandler : public QObject
{
    Q_OBJECT
public:
    explicit WebSocketHandler(QObject *parent = nullptr);
    ~WebSocketHandler();
signals:
    void newMessageToProcess( QString message );
public slots:
    void onNewSocketConnection();

    void onTextMessageRecived(QString);
    void onSocketDisconnected();

private:
    QWebSocketServer* m_socketServer;
    QMap<QString, QWebSocket*> m_clientList;

};

#endif // WEBSOCKETHANDLER_H
