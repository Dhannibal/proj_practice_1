#ifndef SAVE_H
#define SAVE_H

#include <QDialog>
#include <QMessageBox>
#include <QDialog>
#include <QSqlTableModel>
#include <QSqlRecord>
#include <QDebug>
#include <QCloseEvent>

namespace Ui {
class Save;
}

class Save : public QDialog
{
    Q_OBJECT
public:
    explicit Save(QString cardnum, QWidget *parent = 0);
    ~Save();
    int serchcardId(QString x);
    void transmoneyTo(QString cardnum1, double money);
signals:
    void closed(double count);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Save *ui;
    QString cardnum;
};

#endif // SAVE_H
