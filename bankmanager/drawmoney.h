#ifndef DRAWMONEY_H
#define DRAWMONEY_H

#include <QDialog>
#include <QMessageBox>
#include <QDialog>
#include <QSqlTableModel>
#include <QSqlRecord>
#include <QDebug>
#include <QCloseEvent>
namespace Ui {
class drawmoney;
}

class drawmoney : public QDialog
{
    Q_OBJECT

public:
    int serchcardId(QString x);
    void transmoneyTo(QString cardnum1, double money);
    explicit drawmoney(QString cardnum, double money, int flag,  QWidget *parent = 0);
    ~drawmoney();
signals:
    void closed(double money);
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::drawmoney *ui;
    QString cardnum;
    double money;
    int flag;
};

#endif // DRAWMONEY_H
