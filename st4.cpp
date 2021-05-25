// Задание 4:
// Реализовать структуру «Машина» (цвет, модель, номер). 
// Номер машины может представлять из себя или пятизначный номер или слово до 8 символов. 
// Рекомендации: номер реализовать как объединение.Создать экземпляр структуры «Машина» и 
// реализовать для него следующие функции:
//   Заполнение машины
//   Печать машины

// Создать массив из 10 экземпляров структуры «Машина» и реализовать для него следующие функции:
//   Редактировать машину
//   Печать всех машин
//   Поиск машины по номеру

#include <iostream>

#include <string>

#include <conio.h>

using std::string;
using std::cin;
using std::cout;

const int carsQuantity = 10;

union Number {
    short int si;
     char ch[9];
};

struct TNumber {
    union Number uNumber;
     bool isChar;
};

struct Car {
     string sModel;
     string sColor;
    TNumber uNum;
       void Edit();
       void Print();
       bool IsNumber(Number, bool);
    Car();
};

Car::Car() {
    this -> sModel = "Undefined";
    this -> sColor = "Undefined";
    this -> uNum.isChar = false;
    this -> uNum.uNumber.si = 0;
}

void NewLine();

bool Car::IsNumber(Number num, bool isChar) {
    bool result = false;
    switch (isChar) {
    case false:
        if (this -> uNum.uNumber.si == num.si) result = true;
        break;
    case true:
        if (this -> uNum.uNumber.ch == num.ch) result = true;
    }
    return result;
}
void Car::Edit() {
    int inp = 0;
    NewLine();
    cout << "Model?: ";
    cin >> this -> sModel;
    NewLine();
    cout << "Color?: ";
    cin >> this -> sColor;
    NewLine();
    cout << "Number? (1-char, 2-num):";
    cin >> inp;
    switch (inp) {
    case 1:
        this -> uNum.isChar = true;
        cout << "8 characters: ";
        cin >> this -> uNum.uNumber.ch;
        break;
    case 2:
        this -> uNum.isChar = false;
        cout << " 5-digit number: ";
        cin >> this -> uNum.uNumber.si;
        break;
    default:
        ;
    }
}

void Car::Print() {
    NewLine();
    cout << "Model: " << this -> sModel << " | color: " << this -> sColor << " | number: ";
    if (this -> uNum.isChar) {
        cout << this->uNum.uNumber.ch;
    } else {
        cout << this->uNum.uNumber.si;
    }
}

void NewLine() {
    cout << '\n';
}

void NewLine(int qty) {
    for (int i = 0; i < qty; i++)
        cout << '\n';
}

void PrintAll(Car * cr) {
    for (int i = 0; i < carsQuantity; i++) {
        cr[i].Print();
    }
}

void main() {

    Car * cars = new Car[carsQuantity];
    PrintAll(cars);
    cars[0].Edit();
    NewLine(2);
    cars[0].Print();
    delete[] cars;
    cars = nullptr;
    _getche();
}
