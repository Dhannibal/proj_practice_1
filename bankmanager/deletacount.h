#ifndef DELETACOUNT_H
#define DELETACOUNT_H

#include <QDialog>

namespace Ui {
class deletacount;
}

class deletacount : public QDialog
{
    Q_OBJECT

public:
    explicit deletacount(QWidget *parent = 0);
    ~deletacount();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::deletacount *ui;
};

#endif // DELETACOUNT_H
