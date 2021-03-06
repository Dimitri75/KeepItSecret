#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include "cryptoutils.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit_password->setEchoMode(QLineEdit::Password);
    ui->lineEdit_password->setInputMethodHints(Qt::ImhHiddenText| Qt::ImhNoPredictiveText|Qt::ImhNoAutoUppercase);

    client = new Client;
    connect(client,SIGNAL(signinSignal(bool)),this,SLOT(signin(bool)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::openNewAccountView()
{
   newAccountWindow = new NewAccountWindow();
   newAccountWindow->setClient(client);
   newAccountWindow->show();
}

void MainWindow::openContactsView()
{
   contactsWindow = new ContactsWindow();
   contactsWindow->setClient(client);
   contactsWindow->show();
   this->hide();
}

void MainWindow::on_pushButton_submit_clicked()
{
    QMessageBox mb;
    QString login = ui->lineEdit_login->text();
    QString password = ui->lineEdit_password->text();

    if (login.isNull() || login.isEmpty() || password.isNull() || password.isEmpty()){
        mb.setText("Le formulaire n'est pas correctement remplis.");
        mb.exec();
    }
    else if (password.length() < 6){
        mb.setText("Le mot de passe doit faire au moins 6 caractères.");
        mb.exec();
    }
    else
        client->tryToSignIn(login, password);
}

void MainWindow::on_pushButton_newAccount_clicked()
{
    openNewAccountView();
}

void MainWindow::signin(bool isOk)
{
    if (isOk)
        openContactsView();
    else {
        QMessageBox mb;
        mb.setText("Vos identifiants sont invalides.\nRééssayez ou créez un nouveau compte.");
        mb.exec();
    }
}
