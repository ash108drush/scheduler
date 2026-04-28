#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dbconnect.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow){
    ui->setupUi(this);
    DbConnect db = DbConnect();

}

MainWindow::~MainWindow()
{
    delete ui;
}

