#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <dbtools.h>
#include <kis_user.h>

class Server : public QTcpServer
{

public:
    Server();
    ~Server();
public slots:
    void connectionHandler();
    void readClient();
    void clientDisconnection();
    void executeInstructions(QString line, QTcpSocket *client);

private:
    QList<QTcpSocket *> clientConnections;
    QMap<QTcpSocket*, QTcpSocket*> conversations;
};

#endif // SERVER_H
