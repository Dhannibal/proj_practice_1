#ifndef GETCARDNUM_H
#define GETCARDNUM_H

#include <QDialog>
#include <QSqlTableModel>
#include <QSqlRecord>
namespace Ui {
class getcardnum;
}

class getcardnum : public QDialog
{
    Q_OBJECT

public:
    explicit getcardnum(QWidget *parent = 0);
    ~getcardnum();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::getcardnum *ui;
    QSqlTableModel *model;
};

#endif // GETCARDNUM_H
