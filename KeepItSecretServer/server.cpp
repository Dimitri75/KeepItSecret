#include "server.h"
#include "options.h"

#define SEPARATOR "[|#|]"

Server::Server(QTextEdit *_logger)
{
    logger = _logger;
    // Emits a signal when a user connects
    connect(this, SIGNAL(newConnection()),
            this, SLOT(clientConnection()));

    if(!this->listen(QHostAddress::Any, 22))
        logger->append("Server could not start\n");
    else
        logger->append("Server started\n");
}


/**
 * Handle client connections
 * @brief Server::connectionHandler
 */
void Server::clientConnection()
{
    logger->append("A new client arrived !\n");

    // Get next pending connection
    QTcpSocket *socket = this->nextPendingConnection();

    QTextStream flux(socket);
    flux << "You are now connected to the server." << endl;

    // Get ready to read
    connect(socket, SIGNAL(disconnected()), this, SLOT(clientDisconnection()));
    connect(socket, SIGNAL(readyRead()),this, SLOT(readClient()));
}


/**
 * Read what the client sent and execute instructions
 * @brief Server::readClient
 */
void Server::readClient()
{
    QTcpSocket *client = qobject_cast<QTcpSocket *>(sender());

    if (!client)
        return;

    QString line;

    // Read what the client sent
    while(client->canReadLine())
    {
        line = client->readLine();
    }

    Options options(client, &connectedUsers, logger);
    options.parseLine(line);
}


/**
 * Handle client disconnection
 * @brief Server::clientDisconnection
 */
void Server::clientDisconnection()
{
    QTcpSocket *client = qobject_cast<QTcpSocket *>(sender());

    if (!client)
        return;

    connectedUsers.removeAll(client);

    /*Options options(client, &connectedUsers, logger);
    options.sendUserListToClients();*/

    logger->append("A client logged out : " + client->objectName());
}

Server::~Server()
{

}
