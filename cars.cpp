#include <iostream>
#include <string>
#include <algorithm>

using std::string; using std::cout; using std::cin; using std::sort;

void inline NewLine()
{
	cout << '\n';
}

class Cars {
	string brand;
	int mileage;
public:
	int year;
	string country;
	int power;
public:
	void GetData();
	void OutData();
	     Cars();
};

Cars::Cars()
{
	brand = " ";
	mileage = 0;
	year = 1900;
	country = "USA";
	power = 0;
}

void Cars::GetData()
{
	NewLine();
	NewLine();
	cout << "Brand: "; cin.ignore(32767, '\n'); getline(cin, brand);
	NewLine();
	cout << "Mileage: "; cin >> mileage;
	NewLine();
	cout << "Year: "; cin >> year;
	NewLine();
	cout << "Country: "; cin.ignore(32767, '\n'); getline(cin,country);
	NewLine();
	cout << "Power: "; cin >> power;
}

void Cars::OutData()
{
	NewLine();
	NewLine();
	cout << "Brand: ";  cout << brand;
	NewLine();
	cout << "Mileage: "; cout << mileage;
	NewLine();
	cout << "Year: "; cout << year;
	NewLine();
	cout << "Country: "; cout << country;
	NewLine();
	cout << "Power: "; cout << power;
}

int main()
{
	int iCarQty;
	cout << "Cars quantity: "; cin >> iCarQty;
	Cars* cCarArray = new Cars[iCarQty];
	for (int i = 0; i < iCarQty; i++) cCarArray[i].GetData();
	for (int i = 0; i < iCarQty; i++) cCarArray[i].OutData();
	/* сортировка */
	for (int i = 0; i < iCarQty; i++) {
		for (int j = 0; j < iCarQty-1; j++) {
			if  (cCarArray[j].year > cCarArray[j + 1].year) {
				Cars b = cCarArray[j]; // создали дополнительную переменную
				cCarArray[j] = cCarArray[j + 1]; // меняем местами
				cCarArray[j + 1] = b; // значения элементов
			}
		}
	}
	/* end сортировка */
	NewLine();
	cout << "Sorted";
	NewLine();
	for (int i = 0; i < iCarQty; i++) cCarArray[i].OutData();
	return 0;
}
