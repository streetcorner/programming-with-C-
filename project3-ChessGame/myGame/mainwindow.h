#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    const int SIZE =30;
    const int WIDTH=540;
    const int X0 =60, Y0= 60;


    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
private slots:

    void on_pushFive_clicked();
    void on_pushGo_clicked();

signals:

};

#endif // MAINWINDOW_H
