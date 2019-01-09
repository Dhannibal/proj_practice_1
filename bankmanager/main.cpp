#include "mainwindow.h"
#include <QApplication>
#include<QStyleFactory>
#include <QSqlDatabase>
#include <QMessageBox>
#include <QSqlQuery>
#include <QProcess>
#include <QDebug>
bool connect_mysql()
{
    QSqlDatabase db=QSqlDatabase::addDatabase("QMYSQL");
       db.setHostName("127.0.0.1");
       db.setPort(3306);
       db.setDatabaseName("bankmannager");
       db.setUserName("root");
       db.setPassword("628032.com");
       if(!db.open()) return false;
       else return true;
}

int main(int argc, char *argv[])
{
    QApplication::addLibraryPath("./plugins");
    QApplication a(argc, argv);
    if(!connect_mysql()) {qDebug()<<"连接失败";return a.exec();}
    else qDebug()<<"连接成功";
    MainWindow w;
    w.setWindowTitle("欢迎界面");
    w.setStyleSheet("QMainWindow{border-image: url(:/11.jpg);}");
    w.show();
    return a.exec();
}
