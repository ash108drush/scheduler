#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include "formtable.h"
#include "timetabledlg.h"

#include "dbconnect.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }

QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionnew_window_triggered();

    void on_action_time_table_triggered();

private:
    Ui::MainWindow *ui;
    std::unique_ptr<DbConnect > db_;


};
#endif // MAINWINDOW_H
