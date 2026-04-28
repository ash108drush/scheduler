#ifndef DBCONNECT_H
#define DBCONNECT_H
#include <QtSql>
#include <QDebug>


struct db_data{
    const QString hostname = "localhost";
    const QString db_name = "scheduler_db";
    const QString db_user = "scheduler_user";
    const QString db_passwd = "schedpasswd";
    const int port = 5432;
};

class DbConnect
{
public:
    DbConnect();

    void InitValues() const;
private:
    db_data db_data_;

    bool Connect(QSqlDatabase& db) const;
    QSqlDatabase db_;
};

#endif // DBCONNECT_H
