// Задание 5:
// Создайте  динамический  массив,  хранящий  в  первой  строке  имя,  
// а во второй - телефон.
// Организуйте поиск по имени и по номеру телефона 
// и возможность ввода и изменения данных.

#include <conio.h>
#include <iostream>
#include <string>
#define SPACE ' ';

using std::cin; using std::cout; using std::string;

const int NAME = 0;
const int PHONE = 1;


/* Переход на новую строку*/
void inline NewLine();

/*поиск по имени*/
/*Адрес массива, длина массива, имя*/
void SearchName(string**, int, string);

/*поиск по имени*/
/*Адрес массива, длина массива, телефон*/
void SearchPhone(string**, int, string);

/*Вывод массива на экран*/
/*Адрес массива, число строк*/
void PrintArray(string**, int);

/*Вывод элемента массива на экран*/
/*Адрес массива, номер элемента*/
void PrintItem(string**, int);

/*Ввод элемента массива на экран*/
/*Адрес массива, номер элемента*/
void ReadItem(string**, int);

/*Создает массив и возвращает его адрес*/
/*число строк, число столбцов*/
string** CreateArray(int, int);


int main()
{
  
  int iLines = 0; // количество строк
  int iDX = 0; // количество столбцов
  
  cout << "Rows quantity: "; cin >> iLines;
  
  string** sData = CreateArray(iLines, 2);
  
  for (int qt = 0; qt < iLines; qt++) {
		NewLine(); cout << qt<<':';
		ReadItem(sData,qt);
  }

  
  PrintArray(sData, iLines);
  NewLine();
  

  delete[] sData;
  _getche();
  return 0;
}

string** CreateArray(int iY, int iX)
{
  string** sArr = NULL;
  sArr = new string* [iY];
  for (int i = 0; i < iY; i ++) sArr[i] = new string[iX];
  return sArr;
}

void PrintArray(string** sArr, int iY)
{
	NewLine();
	for (int i = 0; i < iY; i++) {
		PrintItem(sArr, i);
        }
      NewLine();
}


void PrintItem(string** sArr, int iPos)
{
	NewLine();
	cout << sArr[iPos][NAME] << '\n' << sArr[iPos][PHONE];

}

void ReadItem(string** sArr, int iPos)
{
	NewLine();
	cout << "Name: "; getline(cin, sArr[iPos][NAME]);
	cout << "Phone: "; getline(cin, sArr[iPos][PHONE]);
}

void SearchPhone(string** sArr, int iLines, string sPhone)
{
	int iFound = 0;
	string sLookFor;
	for (int i = 0; i < iLines; i++) {
		sLookFor = sArr[i][PHONE];
		if (sLookFor.find(sPhone) != std::string::npos ) {
			NewLine();
			PrintItem(sArr, i);
			iFound++;
		}
	}
	NewLine();
	cout <<"Found " << iFound <<" records";
}

void SearchName(string** sArr, int iLines, string sName)
{
	int iFound = 0;
	string sLookFor;
	for (int i = 0; i < iLines; i++) {
		sLookFor = sArr[i][NAME];
		if (sLookFor.find(sName) != std::string::npos ) {
			NewLine();
			PrintItem(sArr, i);
			iFound++;
		}
	}
	NewLine();
	cout <<"Found " << iFound <<" records";
}


void inline NewLine()
{
  cout << '\n';
}

