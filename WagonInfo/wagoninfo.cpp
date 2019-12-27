#include "wagoninfo.h"

WagonInfo::WagonInfo()
{
    dbl_weight = 0.0;
}

WagonInfo::WagonInfo(double weight)
{
    dbl_weight = weight;
}

QString WagonInfo::getWeight()
{
    return QString::number(dbl_weight);
}
