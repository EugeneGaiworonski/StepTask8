// Задание 2:
// Реализовать структуру  «Автомобиль»  (длина,  клиренс  (высота  посадки),  
// объем  двигателя, мощность двигателя, диаметр колес, цвет, тип коробки передач). 
// Создайте функции для задания значений, отображения значений, поиска значений.

#include <iostream>
#include <conio.h>
#include <string>
using std::cin; using std::cout;
enum transmission {
	MANUAL = 1 ,
	AUTOMATIC = 2, 
	OTHER = 8
};

enum color {
	RED = 1,
    BROWN = 2,
    GRAY = 3,
    WHITE = 4,
    YELLOW = 5,
    SILVER = 6,
    BLUE = 7,
    OTHER = 8
};

struct CarData{
	int iLength; 
	short int iClearance; 
	int iEngVolume;
	int iPower;
	short int iWheel;
	color eColor; 
	transmission eTrans;
};

void SetTransmission(CarData value)
{
	int t = 0;
	cout <<"\nSelect transmission type:";
	cout <<"\n 1-manual, 2-automatic, 3-other";
	cout <<"\n>";cin >> t;
	value.eTrans = static_cast<transmission>(t);
}

void PrintTransmission(CarData value)
{
	cout << "\nTransmission: ";
	switch (value.eTrans) {
	case MANUAL:
		cout << "manual";
		break;
	case AUTOMATIC:
		cout << "automatic";
		break;
	default:
		cout << "undefined";
		break;
	}
}

bool IsColor(CarData value, transmission Trans)
{
	if (value.eTrans == Trans) return true;
	else return false;
}


void SetWheel(CarData value)
{
	int w = 0;
	cout <<"\nInput wheel diameter in inches:";
	cout <<"\n>";cin >> w;
	value.iWheel = w;
}

void PrintWheel(CarData value)
{
	cout << "\nWheel diameterEngine (in): " << value.iWheel;
}

bool IsPower(CarData value, int Wheel)
{
	if (value.iWheel == Wheel) return true;
	else return false;
}

void SetPower(CarData value)
{
	int hp = 0;
	cout <<"\nInput engine power in HP:";
	cout <<"\n>";cin >> hp;
	value.iPower = hp;
}

void PrintPower(CarData value)
{
	cout << "\nEngine power (HP): " << value.iPower;
}

bool IsPower(CarData value, int Power)
{
	if (value.iPower == Power) return true;
	else return false;
}

void SetEngVolume(CarData value)
{
	int ev = 0;
	cout <<"\nInput engine volume in cubic mm:";
	cout <<"\n>";cin >> ev;
	value.iEngVolume = ev;
}

void PrintEngVolume(CarData value)
{
	cout << "\nEngine volume (c. mm): " << value.iEngVolume;
}

bool IsEngVolume(CarData value, int EVolume)
{
	if (value.iEngVolume == EVolume) return true;
	else return false;
}

void SetClearance(CarData value)
{
	int c = 0;
	cout <<"\nInput clearance in mm:";
	cout <<"\n>";cin >> c;
	value.iClearance = c;
}

void PrintClearance(CarData value)
{
	cout << "\nClearance (mm): " << value.iClearance;
}

bool IsClearance(CarData value, int Clearance)
{
	if (value.iClearance == Clearance) return true;
	else return false;
}


void SetLength(CarData value)
{
	int l = 0;
	cout <<"\nInput length in mm:";
	cout <<"\n>";cin >> l;
	value.iLength = l;
}

void PrintLength(CarData value)
{
	cout << "\nLength (mm): " << value.iLength;
}

bool IsLength(CarData value, int Length)
{
	if (value.iLength == Length) return true;
	else return false;
}

void SetColor(CarData value)
{
	int v = 0;
	cout <<"\nSelect color:";
	cout <<"\n 1-red, 2-brown, 3-gray, 4-white, 5-yellow, 6-silver, 7-blue, 8-other";
	cout <<"\n>";cin >> v;
	value.eColor = static_cast<color>(v);
}

void PrintColor(CarData value)
{
	cout << "\nColor: ";
	switch (value.eColor) {
	case RED:
		cout << "red";
		break;
	case BROWN:
		cout << "brown";
		break;
	case GRAY:
		cout << "gray";
		break;
	case WHITE:
		cout << "white";
		break;
	case YELLOW:
		cout << "yellow";
		break;
	case SILVER:
		cout << "silver";
		break;
	case BLUE:
		cout << "blue";
		break;
	case OTHER:
		cout << "other";
		break;
	default:
		cout << "undefined";
		break;
	}
}

bool IsColor(CarData value, color Color)
{
	if (value.eColor == Color) return true;
	else return false;
}

int main(void)
{
	CarData car;
		
	_getche();
	return 0;
}
