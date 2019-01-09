#include "transmoney.h"
#include "ui_transmoney.h"
#include <QMessageBox>
#include <QDebug>
transmoney::transmoney(QString cardnum, double money, int flag, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::transmoney),cardnum(cardnum)
{
    ui->setupUi(this);
    this->setWindowTitle("转账");
    this->flag = flag;
    this->money = money;
    QBrush myBrush;
    QPalette palette;
    myBrush = QBrush(Qt::black,Qt::DiagCrossPattern);
    palette.setBrush(QPalette::Text,  myBrush);
    ui->lineEdit->setPalette(palette);
    ui->lineEdit_2->setPalette(palette);
}

transmoney::~transmoney()
{
    delete ui;
}

void transmoney::on_pushButton_2_clicked()
{
    this->close();
}

void transmoney::transmoneyTo(QString cardnum1, double money) {
    int num = serchcardId(cardnum1);
    QSqlTableModel *model;
    model = new QSqlTableModel();
    model->setTable("userdata");
    model->select();
    QSqlRecord record = model->record(num);
    record.setValue("balance",record.value("balance").toDouble()+money);
    model->setRecord(num, record);
    if(model->submitAll()) qDebug()<<"修改成功";
    else qDebug()<<"失败 ";
    free(model);
}
int transmoney::serchcardId(QString x) {
    QSqlTableModel *model;
    model = new QSqlTableModel();
    model->setTable("userdata");
    model->select();
    for(int i = 0; i < model->rowCount(); i++) {
        if(model->record(i).value("cardnum").toString() == x) return i;
    }
    return -1;
    free(model);
}
void transmoney::on_pushButton_clicked()
{
    if(ui->lineEdit_2->text().toStdString().size() == 0) {
        QMessageBox message(QMessageBox::NoIcon, "警告", "请输入金额");
        message.exec();
        return;
    }
    double transBS = ui->lineEdit_2->text().toFloat();
    QString CDnum = ui->lineEdit->text();
    qDebug()<<"金额"<< transBS;
    qDebug()<<"账号"+CDnum;
    if(CDnum.size() != 10) {
        QMessageBox message(QMessageBox::NoIcon, "警告", "请确定卡号是否正确");
        message.exec();
    }
    else{
        if(serchcardId(CDnum) == -1) {
            QMessageBox message(QMessageBox::NoIcon, "警告", "对方卡号不存在");
            message.exec();
        }
        else if(transBS <= 0) {
            QMessageBox message(QMessageBox::NoIcon, "警告", "输入金额不正确");
            message.exec();
        }
        else {
            if(money-transBS < (flag?-5000:0)) {
                QMessageBox message(QMessageBox::NoIcon, "警告", "超出金额限制");
                 message.exec();
            }
            else {
                transmoneyTo(CDnum, transBS);
                transmoneyTo(cardnum, -transBS);
                emit closed(-transBS);
                QMessageBox message(QMessageBox::NoIcon, "提示", "转账成功");
                 message.exec();
                 this->close();
            }
        }
    }
}
