#ifndef WEBSOCKETHANDLER_H
#define WEBSOCKETHANDLER_H

#include <QObject>
#include <QWebSocket>

#include "messageprocesshandler.h"

class WebSocketHandler : public QObject
{
    Q_OBJECT
public:
    explicit WebSocketHandler(QObject *parent = nullptr);
    ~WebSocketHandler();

    Q_INVOKABLE void connectToServer(QString hostAddress);

public slots:
    void onConnected();
    void onTextMessageReceived(QString message);
    void registerID( QString id );

signals:

private:
    QWebSocket* m_webSocket;
    QString m_clientID;
    MessageProcessHandler* m_messageProcessor;
};

#endif // WEBSOCKETHANDLER_H
