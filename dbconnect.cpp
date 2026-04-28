#include "dbconnect.h"


DbConnect::DbConnect() {
    if(Connect(db_)){
        InitValues();
    }
}

bool DbConnect::Connect(QSqlDatabase& db) const{
    db = QSqlDatabase::addDatabase("QPSQL");
    db.setHostName(db_data_.hostname);
    db.setDatabaseName(db_data_.db_name);
    db.setUserName(db_data_.db_user);
    db.setPassword(db_data_.db_passwd);
    db.setPort(db_data_.port);
    if (!db.open()) {
          qDebug() << "Error connecting to database:" << db.lastError().text();
          return false;
      }
    qDebug() << "Successfully connected to PostgreSQL!";
      return true;

}

void DbConnect::InitValues() const{
    QStringList tableList = db_.tables();
    foreach (const QString &tableName, tableList) {
        QSqlQuery query;
        QString sql = QString("DROP TABLE IF EXISTS %1").arg(tableName);
        if (query.exec(sql)) {
              qDebug() << " delete table name:" << tableName;
         } else {
             qDebug() << "Error deleting table:" << query.lastError().text();
         }
    }

    QSqlQuery query;
    QString sql;
    sql = "CREATE TABLE time_ranges (time_id SERIAL PRIMARY KEY, name VARCHAR(50) NULL)";
    query.exec(sql);
    sql = "INSERT INTO time_ranges (name)"
          "VALUES ('8:20'), ('8:40'),('9:00'),('9:20'), ('9:40'),('10:00'),('10:20'), ('10:40'),('11:00'),('11:20'), ('11:40'),('12:00')"
            "('12:20'), ('12:40'),('13:00'),('13:20'), ('13:40'),('14:00'),('14:20'), ('14:40'),('15:00'),('16:20'), ('16:40'),('17:00')";
    query.exec(sql);

    sql = "CREATE TABLE sсhemas (id SERIAL PRIMARY KEY, name VARCHAR(50) NULL, times integer )";


}



