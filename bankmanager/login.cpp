#include "login.h"
#include "ui_login.h"
#include "getcardnum.h"
login::login(int mode, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
    this->mode = mode;
    this->setWindowTitle("登录界面");
    this->resize(500, 300);
}

login::~login()
{
    delete ui;
}

void login::on_pushButton_clicked()
{
    QString cardnum = ui->card->text();
    QString password = ui->pass->text();
    ui->card->clear();
    ui->pass->clear();
    if(cardnum.size() != 10) {
        QMessageBox message(QMessageBox::NoIcon, "警告", "卡号格式不对");
        message.exec();
    }
    else if(password == "") {
        QMessageBox message(QMessageBox::NoIcon, "警告", "密码不能为空");
        message.exec();
    }
    else {
        model = new QSqlTableModel(this);
        model->setTable("userdata");
        model->select();
            int flag = 0;
            for(int i = 0;i < model->rowCount();i++) {
                QString num = model->record(i).value("cardnum").toString();
                if(num == cardnum) {
                    flag = 1;
                    QString code = model->record(i).value("code").toString();
                    if(code != password) {
                        QMessageBox message(QMessageBox::NoIcon, "警告", "密码错误");
                        message.exec();
                    }
                    else {
                        //QMessageBox message(QMessageBox::NoIcon, "提示", "登录成功");
                        //message.exec();
                        atm = new ATM(cardnum);
                        atm->setModal(true);
                        atm->setStyleSheet("QDialog{border-image: url(:/4.jpg);}");
                        atm->show();
                    }
                }
            }
            if(!flag){
                 QMessageBox message(QMessageBox::NoIcon, "警告", "请确认你的卡号");
                 message.exec();
            }
       }
}

void login::on_pushButton_2_clicked()
{
    this->close();
}

void login::on_pushButton_3_clicked()
{
    getcardnum *get;
    get = new getcardnum();
    get->setModal(true);
    get->show();
}
