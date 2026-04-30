#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow){
    ui->setupUi(this);
    db_ = std::make_unique<DbConnect>(DbConnect());

}

MainWindow::~MainWindow(){
    delete ui;
}


void MainWindow::on_actionnew_window_triggered(){

    FormTable *formTable = new FormTable();
    ui->mdiArea->addSubWindow(formTable);
    formTable->show();
}


void MainWindow::on_action_time_table_triggered(){
    QStringList list = { "8:00", "8:20", "8:40" };
    TimeTableDlg *timetable = new TimeTableDlg(this,list);
    timetable->exec();
    ui->mdiArea->addSubWindow(timetable);

    if(timetable->Accepted){
       // qDebug() << "Timetable accepted";
        list = timetable->GetStringList();
        db_->UpdateTimeTable(list);

    }
    if(timetable->Rejected){
       // qDebug() << "Timetable rejected";

    }
    //timetable->close();
   // timetable->done(1);
   // timetable->hide();
    delete timetable;


}

