// Задание4:
// Транспонирование  матрицы – это  операция,  после  которой  столбцы  прежней  матрицы 
// становятся строками, а строки столбцами. 
// Напишите функцию транспонирования матрицы.

#include <conio.h>
#include <iostream>
#include <string>
#define SPACE ' ';
using std::cin; using std::cout;

/* Переход на новую строку*/
void inline NewLine();

/*Вывод массива на экран*/
/*Адрес массива, число строк, число столбцов*/
void PrintArray(int**, int, int);

/*Инициализация массива случайными значениями в интервале 0..9*/
/*Адрес массива, число строк, число столбцов*/
void InitArray(int**, int, int);

/*Создает массив и возвращает его адрес*/
/*число строк, число столбцов*/
int** CreateArray(int, int);

/*Транспонирует массив*/
/*Адрес массива, число строк, число столбцов*/
void TransposeArray(int**, int, int);


int main()
{
  int iDY = 10; // количество строк
  int iDX = 10; // количество столбцов
  
  cout << "Rows quantity: "; cin >> iDY;
  cout << "Columns quantity: "; cin >> iDX;
  int** iArr = CreateArray(iDY, iDX);
  InitArray(iArr, iDY, iDX);
  PrintArray(iArr, iDY, iDX);
  NewLine();
  TransposeArray(iArr,iDY,iDX);
  PrintArray(iArr, iDY, iDX);


  delete[] iArr;
  _getche();
  return 0;
}

int** CreateArray(int iY, int iX)
{
  int** iArr = NULL;
  iArr = new int* [iY];
  for (int i = 0; i < iY; i ++) iArr[i] = new int[iX];
  return iArr;
}

void PrintArray(int** iArr, int iY, int iX)
{
  for (int i = 0; i < iY; i++) {
      for (int j = 0; j < iX; j++) {
          cout << *(*(iArr+i)+j) << SPACE;
        }
      NewLine();
    }
}

void InitArray(int** iArr, int iY, int iX)
{
  srand(9);
  for (int i = 0; i < iY; i++) {
      for (int j = 0; j < iX; j++) {
          iArr[i][j] = rand() % 10;
		  //iArr[i][j] = j;  
	  }
    }
}

void inline NewLine()
{
  cout << '\n';
}

void TransposeArray(int** iArr, int iY, int iX)
{
	int** iBuffer = CreateArray(iY, iX);
	for (int i = 0; i < iY; i++) {
		for(int j = 0; j < iX; j++) {
			iBuffer[j][i] = iArr[i][j];
		}
	}
	for (int i = 0; i < iY; i++) {
		for(int j = 0; j < iX; j++) {
			iArr[i][j] = iBuffer[i][j];
		}
	}
	delete[] iBuffer;
}
