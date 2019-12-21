#include "sqlhandler.h"
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>
#include<QList>
#include<QtWidgets/QMessageBox>
#include<QObject>
#include "wagoninfo.h"

SQLHandler::SQLHandler(QString connectionName,
                       QString driverType = "QPSQL",
                       QString hostName = "localhost",
                       QString nameOfDB = "statera_wim", QString userName = "statera_user", QString password = "staterapass")
{
    dataBase = QSqlDatabase::addDatabase(driverType, connectionName);
    dataBase.setHostName(hostName);
    dataBase.setDatabaseName(nameOfDB);
    dataBase.setUserName(userName);
    dataBase.setPassword(password);
}

bool SQLHandler::openDB()
{
    bool ok = dataBase.open();
    if(ok == false)
    {
        // Получить возникшую ошибку в случае неудачи:
        QSqlError error = dataBase.lastError();
        // Отобразить ошибку в окне с сообщением:
        QMessageBox msgBox;
        msgBox.setWindowTitle("Ошибка при соединении с базой данных!");
        msgBox.setText(error.text());
        msgBox.exec();
    }
    return ok;
}

void SQLHandler::closeAndDispose()
{
    dataBase.close();
    QSqlDatabase::removeDatabase(dataBase.connectionName());
}

QSqlQuery SQLHandler::executeArbitraryQuery(QString query)
{
    QSqlQuery qr = QSqlQuery(query, dataBase);
    if(!qr.exec())
    {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Ошибка при выполнении запроса!");
        msgBox.setText(qr.lastError().text());
        msgBox.exec();
    }
    return qr;
}

QList<WagonInfo> SQLHandler::getAllWagons(int trainID)
{
    QSqlQuery query = executeArbitraryQuery("SELECT ALL * from");

}
