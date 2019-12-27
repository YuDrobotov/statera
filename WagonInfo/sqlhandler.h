#ifndef SQLHANDLER_H
#define SQLHANDLER_H
#include <QString>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include<QList>
#include "wagoninfo.h"


class SQLHandler
{
public:
    SQLHandler(QString connectionName, QString driverType, QString hostName, QString nameOfDB, QString userName, QString password);

    /// Метод открывает объект соединения.
    bool openDB();

    /// Метод закрывает соединение с базой данных и удаляет его.
    void closeAndDispose();

    /// Произвести произвольный запрос, аргументом передаётся текст SQL-запроса.
    QSqlQuery executeArbitraryQuery(QString query);

    /// Получить все вагоны из базы.
    QVector<WagonInfo> getAllWagons(int trainID, bool closeConnection);

private:
    /// База данных.
    QSqlDatabase dataBase;
};

#endif // SQLHANDLER_H
