#ifndef MASTER_H
#define MASTER_H

#include <QDialog>
#include "deletacount.h"
#include "newaccount.h"
#include "login.h"
namespace Ui {
class master;
}

class master : public QDialog
{
    Q_OBJECT

public:
    explicit master(QWidget *parent = 0);
    ~master();

private slots:
    void on_pushButton_6_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();


private:
    Ui::master *ui;
    deletacount *del;
    newaccount *account;
    login *log;
};

#endif // MASTER_H
