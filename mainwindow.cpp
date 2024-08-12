#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    col = ui->table->columnCount(); // Initialize 'col'
    connect(ui->ok, SIGNAL(clicked()), this, SLOT(plot()));
    connect(ui->adder, SIGNAL(clicked()), this, SLOT(addColumn())); // Connect to a custom slot
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow:: getData(){

    for(int i = 0;i<col;i++){
        datax.push_back(ui->table->item(0,i)->text().toDouble());
        datay.push_back(ui->table->item(1,i)->text().toDouble());
    }
}
void MainWindow:: plot(){
    getData();
    ui->plot->addGraph();
    ui->plot->graph(0)->setData(datax,datay);
    ui->plot->replot();
}
void MainWindow::addColumn() {
    ui->table->insertColumn(col); // Insert column
    col++; // Update 'col'
}
