// ������� 4:
// ����������������  ������� � ���  ��������,  
// �����  �������  �������  �������  ������� ���������� ��������, 
// � ������ ���������. 
//
// �������� ������� ���������������� �������.

#include <iostream>
#include <conio.h>
#define SPACE ' ';

using std::cin; using std::cout;

/* ������� �� ����� ������*/
void inline NewLine();

/*����� ������� �� �����*/
/*����� �������, ����� �����, ����� ��������*/
template <typename TYPE> 
void PrintArray(TYPE**, int, int);

/*������������� ������� �������� ���������*/
/*����� �������, ����� �����, ����� ��������, �������� ��� ����������*/
template <typename TYPE>
void InitArray(TYPE**, int, int, int);

/*������������� ������� ���������� ���������� � ��������� 0..9*/
/*����� �������, ����� �����, ����� ��������*/
template <typename TYPE>
void InitArray(TYPE**, int, int);

/*������� ������ � ���������� ��� �����*/
/*����� �����, ����� ��������*/
template <typename TYPE> 
TYPE** CreateArray(int, int);

/*������� ������� � ��������� �������*/
/*����� �������, ����� �����, ����� ��������, ������� �������, �������� ��� ����������*/
template <typename TYPE> 
void InsertColumn(TYPE**, int, int, int, int);

/*�������� ������� � ��������� �������*/
/*����� �������, ����� �����, ����� ��������, ������� ��������*/
template <typename TYPE> 
void DeleteColumn(TYPE**, int, int, int);

/*���������������� �������*/
/*����� �������, ����� �����, ����� ��������*/
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