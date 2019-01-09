#include "atm.h"
#include "ui_atm.h"
ATM::ATM( QString cardnum, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ATM)
{                                               //初始化
    ui->setupUi(this);
    this->resize(500, 300);
    this->setWindowTitle("person");
    this->cardnum = cardnum;
    model = new QSqlTableModel(this);
    model->setTable("userdata");
    model->select();
    for(int i = 0; i < model->rowCount(); i++) {
        if(model->record(i).value("cardnum").toString() == cardnum) {
            money = model->record(i).value("balance").toDouble();
            idcard = model->record(i).value("idcard").toString();
            phonenum = model->record(i).value("phonenum").toString();
            flag = model->record(i).value("flag").toInt();
            name = model->record(i).value("username").toString();
            id = i;
            Gender = model->record(i).value("Gender").toInt();
            qDebug()<<"Gender"<<Gender;
            break;
        }
    }
    if(Gender)
        ui->label->setText("欢迎你"+name+"\n卡号:"+cardnum+"\n性别:男");
        else ui->label->setText("欢迎你"+name+"\n卡号:"+cardnum+"\n性别:女");
    if(flag)
        ui->label_2->setText("您的卡种为:信用卡");
    else ui->label_2->setText("您的卡种为:普通储蓄卡");
     ui->label_3->setText("您的余额为:"+QString::number(money, 'f', 2));
}

ATM::~ATM()
{
    delete ui;
}

void ATM::on_pushButton_clicked()
{
    trans = new transmoney(cardnum, money, flag);
    connect(trans, &transmoney::closed, this, &ATM::renew);
    trans->setModal(true);
    trans->show();
}

void ATM::on_pushButton_2_clicked() {
    save = new Save(cardnum);
    connect(save, &Save::closed, this, &ATM::renew);
    save->setModal(true);
    save->show();
}

void ATM:: renew(double count) {//刷新信号
    money += count;
   ui->label_3->setText("您的余额为:"+QString::number(money, 'f', 2));
}

void ATM::on_pushButton_4_clicked()
{
   this->hide();
}

void ATM::on_pushButton_3_clicked()
{
    draw = new drawmoney(cardnum, money, flag);
    connect(draw, &drawmoney::closed, this, &ATM::renew);
    draw->setModal(true);
    draw->show();
}

