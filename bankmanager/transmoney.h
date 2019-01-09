#ifndef TRANSMONEY_H
#define TRANSMONEY_H

#include <QDialog>
#include <QSqlTableModel>
#include <QSqlQuery>
#include <QMessageBox>
#include <QSqlRecord>
namespace Ui {
class transmoney;
}

class transmoney : public QDialog
{
    Q_OBJECT

public:
    explicit transmoney(QString cardnum,double money, int flag,  QWidget *parent = 0);
    int serchcardId(QString x);
    void transmoneyTo(QString cardnum1, double money);
    ~transmoney();
signals:
     void closed(double count);
private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::transmoney *ui;
    QString cardnum;
    double money;
    int flag;
    QSqlTableModel *model;
};

#endif // TRANSMONEY_H
