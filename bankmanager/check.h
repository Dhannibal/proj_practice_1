#ifndef CHECK_H
#define CHECK_H

#include <QDialog>
#include <QMessageBox>
#include "master.h"
namespace Ui {
class check;
}

class check : public QDialog
{
    Q_OBJECT

public:
    explicit check(QWidget *parent = 0);
    ~check();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::check *ui;
    master *mast;
};

#endif // CHECK_H
