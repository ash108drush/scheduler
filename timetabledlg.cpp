#include "timetabledlg.h"
#include "ui_timetabledlg.h"
#include <QListView>



TimeTableDlg::TimeTableDlg(QWidget *parent, QStringList list):
    QDialog(parent),ui(new Ui::TimeTableDlg){

    ui->setupUi(this);
    model_ = new QStringListModel(list);
   // ui->lv_timetable->setModel(model_);

}

TimeTableDlg::~TimeTableDlg()
{
    delete ui;
}



void TimeTableDlg::on_btn_add_time_clicked(){
    QString line = ui->le_time_edit->text();
    ++current_row_;
    model_->insertRow(current_row_);
    QModelIndex index = model_->index(current_row_);
    model_->setData(index, line);

}


void TimeTableDlg::on_btn_del_time_clicked(){
    model_->removeRow(current_row_);
}



void TimeTableDlg::on_buttonBox_accepted()
{

    QDialog::accept();
}


void TimeTableDlg::on_buttonBox_rejected()
{
    QDialog::reject();
}


void TimeTableDlg::on_lv_timetable_clicked(const QModelIndex &index){
    ui->le_time_edit->setText(model_->data(index).toString());
    current_row_ = index.row();
}


void TimeTableDlg::on_btn_change_time_clicked() {
    QString line = ui->le_time_edit->text();
    QModelIndex index = model_->index(current_row_);
    model_->setData(index, line);

}


void TimeTableDlg::on_tbl_timetable_clicked(const QModelIndex &index)
{

}

