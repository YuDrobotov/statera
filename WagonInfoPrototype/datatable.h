#ifndef DATATABLE_H
#define DATATABLE_H

#include<vector>
using namespace std;

template<typename T>
class DataTable
{
public:
    virtual T getElement(unsigned short rowNumber, unsigned short columnNumber) const = 0;

    virtual void setElement(unsigned short rowNumber, unsigned short columnNumber, T value) = 0;

    virtual vector<T> getRow(unsigned short rowNumber) const = 0;

    virtual void setRow(unsigned short rowNumber, vector<T> value) = 0;

    DataTable();
};

#endif // DATATABLE_H
