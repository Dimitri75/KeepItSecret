#include "chatdialog.h"
#include "ui_chatdialog.h"
#include <QDateTime>
#include <QTextCodec>

ChatDialog::ChatDialog(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ChatDialog)
{
    ui->setupUi(this);
}

/**
 * Set a client to the chat window and performs actions
 * @brief ChatDialog::setClient
 * @param _client
 */
void ChatDialog::setClient(Client *_client)
{
    client = _client;
    connect(client,SIGNAL(newMessageSignal(QString,QString,QString)),SLOT(newmessage(QString,QString,QString)));
}

/**
 * Set a partner to the chat window and performs actions
 * @brief ChatDialog::setPartner
 * @param _partner
 */
void ChatDialog::setPartner(const QString &_partner)
{
    partner = _partner;
    ui->partnerLabel->setText("to : " + partner);
    client->askLogs(partner);
}

ChatDialog::~ChatDialog()
{
    delete ui;
}

/**
 * Action performed when the user clicks on the button to send a message
 * @brief ChatDialog::on_sendButton_clicked
 */
void ChatDialog::on_sendButton_clicked()
{
    QDateTime date;
    QString currentDate = date.currentDateTime().toLocalTime().toString("yyyy/MM/dd hh:mm:ss");

    QString text = ui->sendText->text().trimmed();

    if (!text.isNull() && !text.isEmpty()){

        CryptoUtils crypto;
        QString encryptedMsg = crypto.encrypt(client->secretKey, text);

        client->sendMessage(partner, currentDate, encryptedMsg);

        ui->chat->appendHtml("<b>Vous : [" + currentDate + "] : </b>" + text);
        ui->sendText->clear();
    }
}

/**
 * Action performed when the user receives a new message
 * @brief ChatDialog::newmessage
 * @param partner
 * @param date
 * @param encryptedMsg
 */
void ChatDialog::newmessage(QString partner, QString date, QString encryptedMsg){
    CryptoUtils crypto;
    QString msg = crypto.decrypt(client->secretKey, encryptedMsg);

    ui->chat->appendHtml("<b>" + partner.toUtf8() + " [" + date.toUtf8() + "] : </b>" + msg);
}

/**
 * Action performed on click in the 'Quit' button
 * @brief ChatDialog::on_quitButton_clicked
 */
void ChatDialog::on_quitButton_clicked()
{
    this->close();
}
