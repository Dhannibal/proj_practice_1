#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{

    log = new login(0);
    log->setModal(true);
    log->show();
}

void MainWindow::on_pushButton_2_clicked()
{
    ch = new check();
    ch->exec();
}
