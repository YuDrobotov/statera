#include <QCoreApplication>
#include <QVector>
#include<QtDebug>
#include <wagoninfo.cpp>
#include <sqlhandler.cpp>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // QVector<WagonInfo> *wagons = new QVector<WagonInfo>();
    SQLHandler *sqlHandler = new SQLHandler("connection");

    QVector<WagonInfo> wagons = sqlHandler->getAllWagons(1);

    foreach (WagonInfo wagon, wagons)
        qDebug() <<  wagon.getWeight();

    return a.exec();
}
