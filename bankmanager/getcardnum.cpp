#include "getcardnum.h"
#include "ui_getcardnum.h"
#include <QMessageBox>
getcardnum::getcardnum(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::getcardnum)
{
    ui->setupUi(this);
    this->setWindowTitle("找回卡号");
}

getcardnum::~getcardnum()
{
    delete ui;
}

void getcardnum::on_pushButton_clicked()
{
    QString id = ui->lineEdit->text();
    QString phone = ui->lineEdit_2->text();
    if(id.size() != 18||phone.size()!=11) {
        QMessageBox message(QMessageBox::NoIcon, "警告", "请输入正确格式");
        message.exec();
        return;
    }
    model = new QSqlTableModel(this);
    model->setTable("userdata");
    model->select();
    for(int i = 0; i < model->rowCount(); i++) {
        if(id == model->record(i).value("idcard").toString()&&phone == model->record(i).value("phonenum").toString()) {
            QMessageBox message(QMessageBox::NoIcon, "警告", "您的卡号为"+model->record(i).value("cardnum").toString());
            message.exec();
            this->close();
            return;
        }
    }
    QMessageBox message(QMessageBox::NoIcon, "警告", "找不到信息");
    message.exec();
}

void getcardnum::on_pushButton_2_clicked()
{
    this->close();
}
