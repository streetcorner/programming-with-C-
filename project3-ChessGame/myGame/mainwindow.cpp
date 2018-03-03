#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QMouseEvent>
#include <QDebug>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Chess");
/*
    ui->widget->setAutoFillBackground(true);
    QPalette p = ui->widget->palette();
    p.setColor(QPalette::Active, QPalette::Background, Qt::blue);
    ui->widget->setPalette(p);
*/
    connect(ui->pushFive, SIGNAL(clicked(bool)), ui->widget, SLOT(chooseFive()));
    connect(ui->pushGo, SIGNAL(clicked(bool)), ui->widget, SLOT(chooseGo()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

//点击玩五子棋按钮
void MainWindow::on_pushFive_clicked()
{
    qDebug()<<"pushFive";
    ui->widget->isFive = true;
    ui->widget->isGo = false;

}

//点击玩围棋
void MainWindow::on_pushGo_clicked()
{
    qDebug()<<"pushGo";
    ui->widget->isFive = false;
    ui->widget->isGo = true;
}
