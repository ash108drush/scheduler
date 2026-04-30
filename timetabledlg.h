#ifndef TIMETABLEDLG_H
#define TIMETABLEDLG_H

#include <QDialog>
#include <QStringListModel>

namespace Ui {
class TimeTableDlg;
}

class TimeTableDlg : public QDialog
{
    Q_OBJECT

public:
    explicit TimeTableDlg(QWidget *parent = nullptr,QStringList list = {});
    ~TimeTableDlg();
    QStringList GetStringList() const{
        return model_->stringList();
    }

private slots:
    void on_btn_add_time_clicked();

    void on_btn_del_time_clicked();

    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

    void on_lv_timetable_clicked(const QModelIndex &index);

    void on_btn_change_time_clicked();

    void on_tbl_timetable_clicked(const QModelIndex &index);

private:
    Ui::TimeTableDlg *ui;
    QStringListModel *model_;
    int current_row_ = 0;

};

#endif // TIMETABLEDLG_H
