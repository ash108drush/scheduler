#ifndef FORMTABLE_H
#define FORMTABLE_H

#include <QWidget>

namespace Ui {
class FormTable;
}

class FormTable : public QWidget
{
    Q_OBJECT

public:
    explicit FormTable(QWidget *parent = nullptr);
    ~FormTable();

private:
    Ui::FormTable *ui;
};

#endif // FORMTABLE_H
