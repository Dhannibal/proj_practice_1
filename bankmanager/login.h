#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include <QSqlTableModel>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QMessageBox>
#include<QDebug>
#include "atm.h"
namespace Ui {
class login;
}

class login : public QDialog
{
    Q_OBJECT

public:
    explicit login(int mode, QWidget *parent = nullptr);
    ~login();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::login *ui;
    QSqlTableModel *model;
    ATM *atm;
    int mode;
};

#endif // LOGIN_H
