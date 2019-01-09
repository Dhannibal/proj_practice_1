#include "master.h"
#include "ui_master.h"
#include <QMessageBox>
master::master(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::master)
{
    ui->setupUi(this);
    this->setWindowTitle("柜员模式");
}

master::~master()
{
    delete ui;
}

void master::on_pushButton_6_clicked()
{
    del = new deletacount();
    del->setModal(true);
    del->show();
}

void master::on_pushButton_2_clicked()
{
    account = new newaccount();
    account->setModal(true);
    account->setWindowTitle("newaccount");
    account->show();
}

void master::on_pushButton_clicked()
{
    log = new login(1);
    log->setModal(true);
    log->show();
}

