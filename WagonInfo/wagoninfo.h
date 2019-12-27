#include<QString>

#ifndef WAGONINFO_H
#define WAGONINFO_H


class WagonInfo
{
public:
    WagonInfo();
    WagonInfo(double weight);
    QString getWeight();

private:
    double dbl_weight;
};

#endif // WAGONINFO_H
