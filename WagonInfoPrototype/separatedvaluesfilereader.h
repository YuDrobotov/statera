#ifndef SEPARATEDVALUESFILEREADER_H
#define SEPARATEDVALUESFILEREADER_H

//#include<iostream>
//#include<string>
//#include<array>
#include<memory>
#include<vector>
using namespace std;


template <typename T> class SeparatedValuesFileReader
{
public:
    // Поля
    /// Каталог с файлом, предназначенным для прочтения.
    string str_workingFolder;

    /// Глубина чтения файла -- количество строк.
    unsigned short us_depth = 0;

    /// Разделитель данных в файле.
    char delimiter = ',';

    // Конструкторы
    SeparatedValuesFileReader();
    SeparatedValuesFileReader(char delimiter = ',', string workingFolder = "", unsigned short depth = 0);

    /// Установить фиксированную глубину чтения.
    void setDepth(SeparatedValuesFileReader&);

    // Основной функционал
    /// Прочитать файл, название которого указано в аргументе метода.
    unique_ptr<vector<T>> Read(string fileName, unsigned short = 0);
};

#endif // SEPARATEDVALUESFILEREADER_H
