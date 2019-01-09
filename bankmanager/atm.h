#ifndef ATM_H
#define ATM_H

#include <QDialog>
#include <QSqlTableModel>
#include <QSqlRecord>
#include "transmoney.h"
#include "save.h"
#include "drawmoney.h"
namespace Ui {
class ATM;
}

class ATM : public QDialog
{
    Q_OBJECT

public:
    explicit ATM(QString cardnum, QWidget *parent = 0);
    ~ATM();
private slots:
    void  renew(double money);
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();


private:
    Ui::ATM *ui;
    QString cardnum;
    QString name;
    double money;
    QString phonenum;
    int flag;
    QString idcard;
    QSqlTableModel *model;
    transmoney *trans;
    Save *save;
    int id;
    drawmoney *draw;
    int Gender;
};

#endif // ATM_H
