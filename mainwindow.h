#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private:
    Ui::MainWindow *ui;
    void getData();
    QVector <double> datax;
    QVector <double> datay;
    int col;
    //void plot();

public slots:
    void plot();
    void addColumn();
};
#endif // MAINWINDOW_H
