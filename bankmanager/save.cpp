#include "save.h"
#include "ui_save.h"

Save::Save(QString cardnum, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Save)
{
    ui->setupUi(this);
    this->cardnum = cardnum;
    this->setWindowTitle("存钱");
    QBrush myBrush;
    QPalette palette;
    myBrush = QBrush(Qt::black,Qt::DiagCrossPattern);
    palette.setBrush(QPalette::Text,  myBrush);
    ui->lineEdit->setPalette(palette);
    //ui->lineEdit->setFont(QFont( "Timers" , 28 ,  QFont::Bold) );
}

Save::~Save()
{
    delete ui;
}

void Save::on_pushButton_clicked()
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
    double money = ui->lineEdit->text().toDouble();
    transmoneyTo(cardnum, money);
    emit closed(money);
    QMessageBox message(QMessageBox::NoIcon, "提示", "存款成功");
    message.exec();
    this->close();
}

void Save::transmoneyTo(QString cardnum1, double money) {
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
int Save::serchcardId(QString x) {
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

void Save::on_pushButton_2_clicked()
{
    this->close();
}
