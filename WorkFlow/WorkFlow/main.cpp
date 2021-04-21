// Задание 4:
// Транспонирование  матрицы – это  операция,  
// после  которой  столбцы  прежней  матрицы становятся строками, 
// а строки столбцами. 
//
// Напишите функцию транспонирования матрицы.

#include <iostream>
#include <conio.h>
#define SPACE ' ';

using std::cin; using std::cout;

/* Переход на новую строку*/
void inline NewLine();

/*Вывод массива на экран*/
/*Адрес массива, число строк, число столбцов*/
template <typename TYPE> 
void PrintArray(TYPE**, int, int);

/*Инициализация массива заданным значением*/
/*Адрес массива, число строк, число столбцов, значение для заполнения*/
template <typename TYPE>
void InitArray(TYPE**, int, int, int);

/*Инициализация массива случайными значениями в интервале 0..9*/
/*Адрес массива, число строк, число столбцов*/
template <typename TYPE>
void InitArray(TYPE**, int, int);

/*Создает массив и возвращает его адрес*/
/*число строк, число столбцов*/
template <typename TYPE> 
TYPE** CreateArray(int, int);

/*Вставка столбца в указанной позиции*/
/*Адрес массива, число строк, число столбцов, позиция вставки, значение для заполнения*/
template <typename TYPE> 
void InsertColumn(TYPE**, int, int, int, int);

/*Удаление столбца в указанной позиции*/
/*Адрес массива, число строк, число столбцов, позиция удаления*/
template <typename TYPE> 
void DeleteColumn(TYPE**, int, int, int);

/*Транспонирование матрицы*/
/*Адрес матрицы, число строк, число столбцов*/
template <typename TYPE> 
TYPE** TranspArray(TYPE**,int, int);

int main()
{
	int iDX = 0;
	int iDY = 0;
	cout << "Matrix size" << '\n' << "Rows: "; cin >> iDX;
	cout << "Cols: "; cin >> iDX;
	int** iArray = CreateArray<int>(iDY,iDX);
	InitArray<int>(iArray,iDY,iDX);
	PrintArray<int>(iArray,iDY,iDX);
	_getche();
	delete[] iArray;
	return 0;
}

template <typename TYPE> 
TYPE** TranspArray(TYPE** tArray,int iY, int iX)
{int i,j = {0};
 TYPE** tBuffer;
 tBuffer = new TYPE *[iY];
   for (i = 0; i < iY; i++)
     tBuffer[i] = new TYPE[iX];
   for (i = 0; i < iY; i++)
     for (j = 0; j < iX; j++)
       tBuffer[j][i] = tArray[i][j];
 return tBuffer;
}

template <typename TYPE> 
void DeleteColumn(TYPE** tArr, int iY, int iX, int iPos)
{
  TYPE* tBuffer = new TYPE[iX+1]; for (int i = 0; i <= iX; i++) tBuffer[i] = 0;
  for (int y = 0; y < iY; y++) {
      for (int x = 0; x < iX; x++) {
        *(tBuffer+x) = *(*(tArr+y)+x);
        }
      for (int x = iPos; x < iX-1; x++) *(tBuffer+x) = *(tBuffer+x+1);
      delete[] *(tArr+y);
	  *(tArr+y) = new TYPE[iX+1];
      for (int x = 0; x < iX-1; x++) *(*(tArr+y)+x) = *(tBuffer+x);
    }
}

template <typename TYPE> 
void InsertColumn(TYPE** tArr, int iY, int iX, int iPos, int iValue)
{
	TYPE* tBuffer = new int[iX+1]; 
    for (int i = 0; i <= iX; i++) tBuffer[i] = 0;
    for (int y = 0; y < iY; y++) {
      for (int x = 0; x < iX; x++) tBuffer[x] = tArr[y][x];
	  delete[] *(tArr+y);
	  *(tArr+y) = new TYPE[iX+1];
      for (int x = 0; x < iPos; x++) tArr[y][x] = tBuffer[x];
      tArr[y][iPos] = iValue;
      for (int x = iPos+1; x <= iX; x++) tArr[y][x] = tBuffer[x-1];	 
   }
  delete[] tBuffer;
}

template <typename TYPE>
TYPE** CreateArray(int iY, int iX)
{
  TYPE** tArr = NULL;
  tArr = new TYPE* [iY];
  for (int i = 0; i < iY; i ++) tArr[i] = new TYPE[iX];
  return tArr;
}

template <typename TYPE>
void PrintArray(TYPE** tArr, int iY, int iX)
{
  for (int i = 0; i < iY; i++) {
      for (int j = 0; j < iX; j++) {
          cout << tArr[i][j] << SPACE;
        }
      NewLine();
    }
}

template <typename TYPE>
void InitArray(TYPE** tArr, int iY, int iX, int iValue)
{
  for (int i = 0; i < iY; i++) {
      for (int j = 0; j < iX; j++) {
          tArr[i][j] = iValue;
        }
    }
}

template <typename TYPE>
void InitArray(TYPE** tArr, int iY, int iX)
{
  srand(9);
  for (int i = 0; i < iY; i++) {
      for (int j = 0; j < iX; j++) {
          tArr[i][j] = rand() % 10;
		  //iArr[i][j] = j;  
	  }
    }
}

void inline NewLine()
{
  cout << '\n';
}