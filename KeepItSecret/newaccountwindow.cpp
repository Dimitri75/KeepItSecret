#include "newaccountwindow.h"
#include "ui_newaccountwindow.h"
#include <QMessageBox>
#include "kis_user.h"

NewAccountWindow::NewAccountWindow(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::NewAccountWindow)
{
    ui->setupUi(this);
}

NewAccountWindow::~NewAccountWindow()
{
    delete ui;
}

void NewAccountWindow::on_pushButton_clicked()
{
    QMessageBox mb;
    QString login = ui->lineEdit_log->text();
    QString pwd1 = ui->lineEdit_pwd1->text();
    QString pwd2 = ui->lineEdit_pwd2->text();


    if (!login.isNull() && !login.isEmpty()
            && !pwd1.isNull() && !pwd1.isEmpty()
            && !pwd2.isNull() && !pwd2.isEmpty()
            && pwd1.compare(pwd2) == 0){

        client->addUser(login, pwd1);

        /*
        //CREATE LOCAL USER
        UserKIS user(login, pwd1);
        if (user.save())
            this->close();
        else{
            mb.setText("Un compte avec ce nom existe déjà.");
            mb.exec();
        }
        */
    }
    else{
        mb.setText("Les champs du formulaire ne sont pas bien remplis.");
        mb.exec();
    }
}

void NewAccountWindow::setClient(Client *_client)
{
    client = _client;
    connect(client,SIGNAL(addUserSignal(bool)),this,SLOT(adduser(bool)));
}

void NewAccountWindow::adduser(bool isAdded){
    if (isAdded)
        this->close();
    else {
        QMessageBox mb;
        mb.setText("Un compte avec ce nom existe déjà.");
        mb.exec();
    }
}
