#ifndef WAGONINFO_H
#define WAGONINFO_H
#include <string>
#include<array>
using namespace std;

/// Класс, представляющий "коммерческую" информацию о вагоне.
class WagonInfo
{
public:
#define FOLDINGSTART { // Описание вагона (поля):

    /// Имя типа вагона.
    string str_wagonType = "";

    /// Регистрационный номер вагона.
    unsigned short us_regNumber = 0;

    /// Вес вагона.
    double d_weight = 0.0;

    /// Грузоподъёмность вагона.
    double d_capacity = 0.0;

    /// Имя типа перевозимого груза.
    string str_cargoType = "";

    /// Имя организации-отправителя.
    string str_sender = "";

    /// Имя организации-адресата.
    string str_receiver = "";

    /// Примечания.
    string str_notion = "";

    /// Поле хранит результат проверки заданного регистрационного номера на соответствие нормативным критериям.
    /// Заполняется вместе с инициализацией поля us_regNumber.
    bool b_isTheRegNumberCorrect = false;

    /// Поле хранит результат проверки соответствия введённого пользователем типа вагона зашифрованному в номере.
    bool b_doesTheWagonTypeMatchTheRegNumber = false;

    // /// Поле, которое хранит результат всех проверок информации и которое востребовано перед записью информации в архив.
    // bool b_isSpecificationCorrect = false;

    // /// Массив тестов, заполняемый по мере введения информации пользователем и оповещающий о проблеме при внесении информации в архив.
    // /// Порядок значений в архиве: тип вагона, регистрационный номер, вес, грузоподъёмность, перевозимый груз, организация-отправитель, получатель.
    // array<bool, 7> array_tests = {false, false, false, false, false, false, false}; //TODO: Использован array, т.к. vector<bool> может быть исключён из стандартной библиотеки

#define FOLDINGEND }

#define FOLDINGSTART { // Конструкторы:

    WagonInfo();

    WagonInfo(string wagon_type, unsigned short reg_number,
              double weight = 0.0, double capacity = 0.0,
              string cargo_type = "",
              string sender = "", string receiver = "");

#define FOLDINGEND }

#define FOLDINGSTART { // Функционал чтения-записи (прототипы):

    /// Задать регистрационный номер вагона, ссылка на который передаётся вторым аргументом, целым числом.
    void setRegNumber(unsigned short regNumber, WagonInfo& wagon);

    /// Задать регистрационный номер вагона, ссылка на который передаётся вторым аргументом, строкой (будет распарсена).
    void setRegNumber(string regNumber, WagonInfo& wagon);

    /// Прочитать всю информацию о вагоне (реализация зависит от пожеланий).
    void setValues(WagonInfo& wagon);

    /// Получить (вывести) всю информацию о вагоне (например, в консоль).
    void getValues(const WagonInfo& wagon);

#define FOLDINGEND }

#define FOLDINGSTART { // Функционал проверки вводимых данных:

    /// Проверить, верно ли задан регистрационный номер.
    bool isRegNumberCorrect(unsigned short reg_number);

    /// Проверить, соответствует ли тип вагона регистрационному номеру (согласно существующему нормативу).
    /// Использовать результат проверки для инициализации поля b_isSpecificationCorrect и инициировать какое-нибудь событие,
    /// чтобы сообщить пользователю о проблеме конкретно в данном месте.
    void doesWagonTypeMatchRegNumber(WagonInfo& wagon);

#define FOLDINGEND }
};

#endif // WAGONINFO_H
