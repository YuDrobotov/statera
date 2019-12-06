#include "wagoninfo.h"
#include <string>
#include<exception>
using namespace std;

#define FOLDINGSTART {// Реализация конструкторов

    WagonInfo::WagonInfo() {}

    WagonInfo::WagonInfo(string wagonTypeName, unsigned short regNumber,
                     double weight, double capacity,
                     string sender, string receiver,
                     string notion)
    {
        str_wagonType = wagonTypeName;
        us_regNumber = regNumber; //TODO: Возможно, стоит добавить проверку регистрационного номера в конструктор:
                                  //      выбрасывать исключение, если получен (любым способом) неверный номер, и заставлять метод,
                                  //      которым вводится номер, отлавливать и обрабатывать его.

        d_weight = weight;
        d_capacity = capacity;
        str_sender = sender;
        str_receiver = receiver;
        str_notion = notion;
    }

#define FOLDINGEND }



/// Проверить, может ли аргумент функции рассматриваться как регистрационный номер вагона.
bool WagonInfo::isRegNumberCorrect(unsigned short regNumber) //TODO: Переделать метод на основе информации, полученной от коллег.
{
    if(regNumber == 0) return false; // Примитивная проверка, чтобы хоть что-то было.
    return true;
}

/// Метод проверяет корректность поданного в качестве первого аргумента регистрационного номера
/// и записывает его значение в поле вагона, поданного в качестве второго аргумента.
void WagonInfo::setRegNumber(unsigned short regNumber, WagonInfo& wagon)
{
    isRegNumberCorrect(regNumber) ? wagon.us_regNumber = regNumber : throw new exception(); //TODO: Разработать тип исключения.
}
