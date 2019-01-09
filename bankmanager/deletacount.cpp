#include "deletacount.h"
#include "ui_deletacount.h"
#include <QMessageBox>
#include <QSqlTableModel>
#include <QSqlRecord>
deletacount::deletacount(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::deletacount)
{
    ui->setupUi(this);
    this->setWindowTitle("delet");
}

deletacount::~deletacount()
{
    delete ui;
}

void deletacount::on_pushButton_2_clicked()
{
    this->close();
}

void deletacount::on_pushButton_clicked()
{
    QString cardnum = ui->lineEdit->text();
    if(cardnum.size() != 10) {
        QMessageBox message(QMessageBox::NoIcon, "message", "卡号格式不正确");
        message.exec();
    }
    else{
        QSqlTableModel *model;
        model = new QSqlTableModel();
        model->setTable("userdata");
        model->select();
        int pos = -1;
        for(int i = 0; i < model->rowCount(); i++) {
            QString ss = model->record(i).value("cardnum").toString();
            if(ss == cardnum) {
                pos = i;
                break;
            }
        }
        if(pos != -1) {
            model->removeRow(pos);
            model->submitAll();
            QMessageBox message(QMessageBox::NoIcon, "message", "销户成功");
            message.exec();
            ui->lineEdit->clear();
            this->close();
        }
        else {
            QMessageBox::information(NULL, "message", "卡号不存在", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
        }
    }
}
