#ifndef NEWACCOUNT_H
#define NEWACCOUNT_H

#include <QDialog>
#include <QSqlTableModel>
#include <QSqlRecord>
namespace Ui {
class newaccount;
}

class newaccount : public QDialog
{
    Q_OBJECT

public:
    explicit newaccount(QWidget *parent = 0);
    ~newaccount();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::newaccount *ui;
};

#endif // NEWACCOUNT_H
