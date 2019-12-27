#include "sqlhandler.h"
#include <QtSql/QSqlError>
#include<QtWidgets/QMessageBox>
#include <QVariant>
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

QVector<WagonInfo> SQLHandler::getAllWagons(int trainID, bool closeConnection = true)
{
    // Составляем команду и выполняем запрос:
    QString order = QString("select trains.id, trains.direction, wagons.mass from trains, "
                            "wagons where trains.id = %1 and wagons.train_id = trains.id;").arg(trainID);
    QSqlQuery query = executeArbitraryQuery(order);

    // Если необходимо, уничтожаем соединение с БД (по умолчанию, необходимо):
    if(closeConnection) closeAndDispose();

    // Обрабатываем результат запроса и уничтожаем запрос:
    QVector<double> massVector = QVector<double>();
    while (query.next())
        massVector.append(query.value(2).toDouble());
    query.clear();

    // Формируем вывод:
    QVector<WagonInfo> result = QVector<WagonInfo>(massVector.length());
    for(int i = 0; i < result.length(); i++)
        result[i] = WagonInfo(massVector[i]);

    // Освобождаем память и возвращаем вывод:
    massVector.squeeze();
    return result;
}
