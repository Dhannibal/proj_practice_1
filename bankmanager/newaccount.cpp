#include "newaccount.h"
#include "ui_newaccount.h"
#include <QMessageBox>
#include <QDebug>
#include <QSqlQuery>
newaccount::newaccount(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::newaccount)
{
    ui->setupUi(this);
}

newaccount::~newaccount()
{
    delete ui;
}

void newaccount::on_pushButton_clicked()
{
    QString name = ui->name->text();
    QString id = ui->idcard->text();
    QString phonenum = ui->phone->text();
    QString code1 = ui->code1->text();
    QString code2 = ui->code2->text();
    int flag= ui->flag->currentIndex();
    int Gender = ui->Gender->currentIndex();
    if(name.size()==0) {
        QMessageBox message(QMessageBox::NoIcon, "message", "请输入姓名");
        message.exec();
        return;
    }
    else if(id.size() != 18) {
        QMessageBox message(QMessageBox::NoIcon, "message", "请输入正确的身份证号码");
        message.exec();
        return;
    }
    else {
        int f = 0;
        for(int i = 0; i < 18; i++) {
            if(id[i]>'9'||id[i]<'0') {
                f = 1;
                break;
            }
        }
        if(f) {
            QMessageBox message(QMessageBox::NoIcon, "message", "请输入正确的身份证号码");
            message.exec();
            return;
        }
    }
    if(phonenum.size() != 11) {
        QMessageBox message(QMessageBox::NoIcon, "message", "请输入正确的手机号码");
        message.exec();
        return;
    }
    if(code1 != code2) {
        QMessageBox message(QMessageBox::NoIcon, "message", "两次密码不同");
        message.exec();
        return;
    }
    QSqlTableModel *model;
    model = new QSqlTableModel();
    model->setTable("userdata");
    QString cardnum;
    int f = 0;
    model->select();
    for(int i = 0; i < model->rowCount(); i++) {
        if(phonenum == model->record(i).value("phonenum").toString()) {
            QMessageBox message(QMessageBox::NoIcon, "message", "您的手机号已绑定银行卡");
            message.exec();
            return;
        }
    }
    while(!f) {
        cardnum = "";
        for(int i = 0; i < 10; i++) {
            int x = random();
            cardnum += '0'+x%10;
        }
        model->select();
        int f1 = 0;
        for(int i = 0; i < model->rowCount(); i++) {
            if(cardnum == model->record(i).value("cardnum").toString()) {
                f1 = 1;
                break;
            }
        }
        if(!f1) f = 1;
    }
    qDebug()<<"生成card:"<<cardnum;
    model->select();
    int x = model->rowCount();
    model->insertRow(x);
    model->setData(model->index(x, 0), cardnum);
    model->setData(model->index(x, 1), code1);
    model->setData(model->index(x, 2), phonenum);
    model->setData(model->index(x, 3), id);
    model->setData(model->index(x, 4), 0.00);
    model->setData(model->index(x, 5), flag);
    model->setData(model->index(x, 6), name);
    model->setData(model->index(x, 7), Gender);
    if(model->submitAll()) {
        qDebug()<<"YES";
        QMessageBox message(QMessageBox::NoIcon, "message", "开户成功\n您的卡号为:"+cardnum);
        message.exec();
        this->close();
    }
    else qDebug()<<"No";
}

void newaccount::on_pushButton_2_clicked()
{
    this->close();
}
