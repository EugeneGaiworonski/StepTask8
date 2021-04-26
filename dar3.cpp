//Задание 3:
// Дана матрица порядка MxN (M строк, N столбцов). 
// Необходимо заполнить ее значениями и написать функцию, 
// осуществляющую циклический сдвиг строк и/или столбцов массива указанное количество раз 
// и в указанную сторону.

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

/*Циклический сдвиг массива*/
/*Адрес массива, число строк, число столбцов, направление сдвига, количество сдвигов*/
void RotateArray(int**, int, int, int, int);

#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4

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
  RotateArray(iArr, iDY, iDX, UP, 1);
  PrintArray(iArr, iDY, iDX);
  NewLine();
  RotateArray(iArr, iDY, iDX, RIGHT, 2);
  PrintArray(iArr, iDY, iDX);
  NewLine();
  RotateArray(iArr, iDY, iDX, LEFT, 3);
  PrintArray(iArr, iDY, iDX);
  NewLine();
  RotateArray(iArr, iDY, iDX, DOWN, 4);
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

void RotateArray(int** iArr, int iY, int iX, int iDir, int iQty)
{
	int* iBuffer = new int[iY+iX];
	switch (iDir) {
            case 1: // up
					//int table[5][5] = {0};
				 //int buffer[5] = {0};
				for (int x0 = 0; x0 < iQty; x0++){
					for (int x = 0; x < iX; x++) iBuffer[x] = iArr[0][x]; // 0 x

					for(int ym = 0; ym < (iY-1); ym++) {
						for(int xm = 0; xm < iX; xm++) {
							iArr[ym][xm]=iArr[ym+1][xm];
                            }
                        }

					for (int x1 = 0; x1 < iX; x1++) iArr[iY-1][x1] = iBuffer[x1];
                }
				break;
				
            case 2: // down
				for (int x0 = 0; x0 < iQty; x0++){
					for (int x = 0; x < iX; x++) iBuffer[x] = iArr[iY-1][x];
                        
					for(int ym = iY-1; ym > 0; ym--) {
						for(int xm = 0; xm < iX; xm++) {
							iArr[ym][xm]=iArr[ym-1][xm];
                            }
                        }
					for (int i = 0; i < iX; i++) iArr[0][i] = iBuffer[i];
                }
				break;
            case 3: // left
				for (int y0 = 0; y0 < iQty; y0++){
					for (int y = 0; y < iY; y++) iBuffer[y] = iArr[y][0];
                        
					for (int ym = 0; ym < iY; ym++) {
						for (int xm = 0; xm < iX-1; xm++) {
							iArr[ym][xm]=iArr[ym][xm+1];
                            }
                        }
					for (int y1 = 0; y1 < iY; y1++) iArr[y1][iX-1] = iBuffer[y1];
                }
				break;
			case 4: // right
				for (int y0 = 0; y0 < iQty; y0++){
                    for (int y = 0; y < iY; y++) iBuffer[y] = iArr[y][iX-1];
					for (int ym = 0; ym < iY; ym++) {
						for (int xm = iX-1; xm > 0; xm--) {
							iArr[ym][xm]=iArr[ym][xm-1];
                            }
                        }
					for (int i = 0; i < iY; i++) iArr[i][0] = iBuffer[i];
                }
				break;
            default:
                break;
        }
	delete[] iBuffer;
}
