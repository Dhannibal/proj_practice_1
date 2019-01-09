#include "drawmoney.h"
#include "ui_drawmoney.h"
#include <QMessageBox>
drawmoney::drawmoney(QString cardnum, double money, int flag, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::drawmoney),cardnum(cardnum),money(money),flag(flag)
{                                   //初始化
    ui->setupUi(this);
    this->setWindowTitle("取钱");
    QBrush myBrush;
    QPalette palette;
    myBrush = QBrush(Qt::black,Qt::DiagCrossPattern);
    palette.setBrush(QPalette::Text,  myBrush);
    ui->lineEdit->setPalette(palette);
}

drawmoney::~drawmoney()
{
    delete ui;
}

void drawmoney::transmoneyTo(QString cardnum1, double money1) {//转钱给账号cardnum1
    int num = serchcardId(cardnum1);
    QSqlTableModel *model;
    model = new QSqlTableModel();
    model->setTable("userdata");
    model->select();
    QSqlRecord record = model->record(num);
    record.setValue("balance",record.value("balance").toDouble()+money1);
    model->setRecord(num, record);
    if(model->submitAll()) qDebug()<<"修改成功";
    else qDebug()<<"失败 ";
}

int drawmoney::serchcardId(QString x) {
    QSqlTableModel *model;
    model = new QSqlTableModel();
    model->setTable("userdata");
    model->select();
    for(int i = 0; i < model->rowCount(); i++) {
        if(model->record(i).value("cardnum").toString() == x) return i;
    }
    return -1;
}

void drawmoney::on_pushButton_clicked()
{
    if(ui->lineEdit->text().size() == 0) {
        QMessageBox message(QMessageBox::NoIcon, "警告", "请输入金额");
        message.exec();
        return;
    }
    else if(ui->lineEdit->text().toDouble()<0) {
        QMessageBox message(QMessageBox::NoIcon, "警告", "请输入正确金额");
        message.exec();
        return;
    }
    double acount = ui->lineEdit->text().toDouble();
    if(money-acount < (flag?-5000:0)) {
        qDebug()<<" money"<<money;
        qDebug()<<" flag"<<flag;
        qDebug()<<"money-amount"<<money-acount;
        QMessageBox message(QMessageBox::NoIcon, "警告", "超出金额限制");
         message.exec();
        return;
    }
    transmoneyTo(cardnum, -acount);
    emit closed(-acount);
    QMessageBox message(QMessageBox::NoIcon, "提示", "取款成功");
    message.exec();
    this->close();
}

void drawmoney::on_pushButton_2_clicked()
{
    this->close();
}
