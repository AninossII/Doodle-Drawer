#ifndef MESSAGEPROCESSHANDLER_H
#define MESSAGEPROCESSHANDLER_H

#include <QObject>
#include <QRegularExpression>

class MessageProcessHandler : public QObject
{
    Q_OBJECT
public:
    explicit MessageProcessHandler(QObject *parent = nullptr);


    void processMessage( QString message );

signals:
    void uniqueIdRegistration( QString uniqueID );
};

#endif // MESSAGEPROCESSHANDLER_H
