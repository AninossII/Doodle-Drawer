#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "Controllers/gamemanager.h"
#include "Controllers/websockethandler.h"

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);

    WebSocketHandler socketHandler;
    socketHandler.connectToServer("ws://127.0.0.1:9000");

    GameManager gameManager; //Video 16

    QObject::connect(&socketHandler, &WebSocketHandler::newMessageReadyForProcessing, &gameManager, &GameManager::processSocketMessage);
    QObject::connect(&gameManager, &GameManager::newMessageReadyToSend, &socketHandler, &WebSocketHandler::sendMessageToServer);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    QQmlContext* context = engine.rootContext();
    context->setContextProperty("webSocketHandler", &socketHandler);
    context->setContextProperty("gameManager", &gameManager);

    return app.exec();
}
