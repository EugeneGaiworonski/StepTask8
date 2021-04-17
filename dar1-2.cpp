// Задание 1:
// Написать функцию, добавляющую столбец двухмерному массиву
// в указанную позицию.

// Задание 2:
// Написать функцию, удаляющую столбец двухмерного массива
// по указанному номеру.

#include <iostream>
#include <string>
#define SPACE ' ';
using std::cin; using std::cout;

/* Переход на новую строку*/
void inline NewLine();

/*Вывод массива на экран*/
/*Адрес массива, число строк, число столбцов*/
void PrintArray(int**, int, int);

/*Инициализация массива заданным значением*/
/*Адрес массива, число строк, число столбцов, значение для заполнения*/
void InitArray(int**, int, int, int);

/*Инициализация массива случайными значениями в интервале 0..9*/
/*Адрес массива, число строк, число столбцов*/
void InitArray(int**, int, int);

/*Создает массив и возвращает его адрес*/
/*число строк, число столбцов*/
int** CreateArray(int, int);

/*Вставка столбца в указанной позиции*/
/*Адрес массива, число строк, число столбцов, позиция вставки, значение для заполнения*/
void InsertColumn(int**, int, int, int, int);

/*Удаление столбца в указанной позиции*/
/*Адрес массива, число строк, число столбцов, позиция удаления*/
void DeleteColumn(int**, int, int, int);

int main()
{
  const int iDY = 10; // количество строк
  const int iDX = 10; // количество столбцов

  int** iArr = CreateArray(iDY, iDX);
  InitArray(iArr, iDY, iDX);
  PrintArray(iArr, iDY, iDX);
  NewLine();
  InsertColumn(iArr, iDY, iDX, 0, 7);
  PrintArray(iArr, iDY, iDX+1);
  NewLine();
  DeleteColumn(iArr,iDY, iDX+1, 3);
  PrintArray(iArr, iDY, iDX);
  delete[] iArr;
  return 0;
}

void DeleteColumn(int** iArr, int iY, int iX, int iPos)
{
  int* iBuffer = new int[iX+1]; for (int i = 0; i <= iX; i++) iBuffer[i] = 0;
  for (int y = 0; y < iY; y++) {
      for (int x = 0; x < iX; x++) {
        *(iBuffer+x) = *(*(iArr+y)+x);
        }
      for (int x = iPos; x < iX-1; x++) *(iBuffer+x) = *(iBuffer+x+1);
      delete[] *(iArr+y);
      *(iArr+y) = new int[iX+1];
      for (int x = 0; x < iX-1; x++) *(*(iArr+y)+x) = *(iBuffer+x);
    }
}


void InsertColumn(int** iArr, int iY, int iX, int iPos, int iValue)
{
  int* iBuffer = new int[iX+1]; for (int i = 0; i <= iX; i++) iBuffer[i] = 0;
  for (int y = 0; y < iY; y++) {
      for (int x = 0; x < iX; x++) {
        *(iBuffer+x) = *(*(iArr+y)+x);
        }
      delete[] *(iArr+y);
      *(iArr+y) = new int[iX+1];
      for (int x = 0; x < iPos; x++) *(*(iArr+y)+x) = *(iBuffer+x);
      *(*(iArr+y)+iPos) = iValue;
      for (int x = iPos+1; x < iX; x++) *(*(iArr+y)+x) = *(iBuffer+x);
    }
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

void InitArray(int** iArr, int iY, int iX, int iValue)
{
  for (int i = 0; i < iY; i++) {
      for (int j = 0; j < iX; j++) {
          iArr[i][j] = iValue;
        }
    }
}

void InitArray(int** iArr, int iY, int iX)
{
  srand(9);
  for (int i = 0; i < iY; i++) {
      for (int j = 0; j < iX; j++) {
          iArr[i][j] = rand() % 10;
        }
    }
}

void inline NewLine()
{
  cout << '\n';
}
