#include "check.h"
#include "ui_check.h"
check::check(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::check)
{
    ui->setupUi(this);
    this->setWindowTitle("check");
}

check::~check()
{
    delete ui;
}

void check::on_pushButton_clicked()
{
    QString code = ui->code->text();
    if(code == "123456") {
        mast = new master();
        mast->setModal(true);
        mast->setStyleSheet("QDialog{border-image: url(:/2.jpg);}");
        mast->show();
    }
    else {
        QMessageBox message(QMessageBox::NoIcon, "message", "密码错误！");
        message.exec();
    }
}

void check::on_pushButton_2_clicked() {
    this->close();
}
