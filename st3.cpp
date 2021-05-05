// Задание 3: Разработайте  программу  «Библиотека».  
// Создайте  структуру  «Книга»  (название,  автор, издательство, жанр). 
// Создайте массив из 10 книг. Реализуйте для него следующие возможности: 
// -Редактировать книгу
// -Печать всех книг
// -Поиск книг по автору
// -Поиск книги по названию
// -Сортировка массива по названию книг
// -Сортировка массива по автору
// -Сортировка массива по издательству

#include <iostream>
#include <string> 
using std::string;
using std::cin;
using std::cout;

#define LIBSIZE 10
void NewLine();
void NewLine(int);
void PrintHelp();

struct Book {
	string sTitle;
	string sAuthor;
	string sPublisher;
	string sGenre;
	bool bUsed;
	Book() {
		sTitle = "";
		sAuthor = "";
		sPublisher = "";
		sGenre = "";
		bUsed = false;
	}
	~Book() {
		sTitle = "";
		sAuthor = "";
		sPublisher = "";
		sGenre = "";
		bUsed = false;
	}
	void Edit();
	void Print();
	bool IsAuthor(string);
	bool IsTitle(string);
};

 
int main()
{
	Book* lib = new Book[LIBSIZE];	
	char cCom = 0x0;
	short iPos = -1;
	string sStr = "";
	Book tlib;

	do {
		cout << "\nlib>";
		cin >> cCom;
		switch (cCom) {
		case 'e': //edit
			while ((iPos < 0)||(iPos > LIBSIZE-1)) {
				cout << "\nNo.:"; cin >> iPos;
			}
			lib[iPos].Print();
			lib[iPos].Edit();
		break;

		case 'p': //print	
			for (int i = 0; i < LIBSIZE; i++) { 
				NewLine(2); cout << "No. "<< i;
				lib[i].Print();
			}
		break;
		
		case 'a': //search for author
			cout << "Author to find: "; cin >> sStr;
			iPos = 0;
			for (int i = 0; i < LIBSIZE; i++) {
				if (lib[i].IsAuthor(sStr)) {
				iPos++;
				NewLine();
				lib[i].Print();
				}
			}
			cout << iPos << " found";
		break;

		case 't': //search for title
			cout << "Title to find: "; cin >> sStr;
			iPos = 0;
			for (int i = 0; i < LIBSIZE; i++) {
				if (lib[i].IsTitle(sStr)) {
				iPos++;
				NewLine();
				lib[i].Print();
				}
			}
			cout << '\n' << iPos << " found";
		break;

		case 'b': //sort by author
			for (int i = 0; i <LIBSIZE; i++)
				for (int j = i; j > 0 && lib[j-1].sAuthor > lib[j].sAuthor; j--) {
					tlib.sAuthor =  lib[j-1].sAuthor;
					tlib.sTitle = lib[j-1].sTitle;
					tlib.sPublisher = lib[j-1].sPublisher;
					tlib.sGenre = lib[j-1].sGenre;
					
					lib[j-1].sAuthor =  lib[j].sAuthor;
					lib[j-1].sTitle = lib[j].sTitle;
					lib[j-1].sPublisher = lib[j].sPublisher;
					lib[j-1].sGenre = lib[j].sGenre;
					
					lib[j].sAuthor =  tlib.sAuthor;
					lib[j].sTitle = tlib.sTitle;
					lib[j].sPublisher = tlib.sPublisher;
					lib[j].sGenre = tlib.sGenre;
				}			
		break;
		
		case 'c': //sort by title
			for (int i = 0; i <LIBSIZE; i++)
				for (int j = i; j > 0 && lib[j-1].sTitle > lib[j].sTitle; j--) {
					tlib.sAuthor =  lib[j-1].sAuthor;
					tlib.sTitle = lib[j-1].sTitle;
					tlib.sPublisher = lib[j-1].sPublisher;
					tlib.sGenre = lib[j-1].sGenre;
					
					lib[j-1].sAuthor =  lib[j].sAuthor;
					lib[j-1].sTitle = lib[j].sTitle;
					lib[j-1].sPublisher = lib[j].sPublisher;
					lib[j-1].sGenre = lib[j].sGenre;
					
					lib[j].sAuthor =  tlib.sAuthor;
					lib[j].sTitle = tlib.sTitle;
					lib[j].sPublisher = tlib.sPublisher;
					lib[j].sGenre = tlib.sGenre;
				}			
		break;

		case 'd': //sort by publisher
			for (int i = 0; i <LIBSIZE; i++)
				for (int j = i; j > 0 && lib[j-1].sPublisher > lib[j].sPublisher; j--) {
					tlib.sAuthor =  lib[j-1].sAuthor;
					tlib.sTitle = lib[j-1].sTitle;
					tlib.sPublisher = lib[j-1].sPublisher;
					tlib.sGenre = lib[j-1].sGenre;
					
					lib[j-1].sAuthor =  lib[j].sAuthor;
					lib[j-1].sTitle = lib[j].sTitle;
					lib[j-1].sPublisher = lib[j].sPublisher;
					lib[j-1].sGenre = lib[j].sGenre;
					
					lib[j].sAuthor =  tlib.sAuthor;
					lib[j].sTitle = tlib.sTitle;
					lib[j].sPublisher = tlib.sPublisher;
					lib[j].sGenre = tlib.sGenre;
				}			
		break;

		case '0': //debug
			lib[0].sTitle = "The Great Gatsby"; 
			lib[0].sAuthor = "F. Scott Fitzgerald";
			lib[0].sPublisher = "GN20";
			lib[0].sGenre = "Novel";
			lib[0].bUsed = true;
			lib[1].sTitle = "The Catcher In The Rye";
			lib[1].sAuthor = "J.D. Salinger";
			lib[1].sPublisher = "GN20";
			lib[1].sGenre = "Novel";
			lib[1].bUsed = true;
			lib[2].sTitle = "The Grapes Of Wrath"; 
			lib[2].sAuthor = "John Steinbeck ";
			lib[2].sPublisher = "GN20";
			lib[2].sGenre = "novel";
			lib[2].bUsed = true;
			lib[3].sTitle = "1984";
			lib[3].sAuthor = "George Orwell";
			lib[3].sPublisher = "GN20";
			lib[3].sGenre = "novel";
			lib[3].bUsed = true;
			lib[4].sTitle = "Brave New World";
			lib[4].sAuthor = "Aldous Huxley";
			lib[4].sPublisher = "GN20";
			lib[4].sGenre = "novel";
			lib[4].bUsed = true;
			lib[5].sTitle = "Ulysses"; 
			lib[5].sAuthor = "James Joyce";
			lib[5].sPublisher = "GN20";
			lib[5].sGenre = "novel";
			lib[5].bUsed = true;
			lib[6].sTitle = "The Sun Also Rises";
			lib[6].sAuthor = "Ernest Hemingway";
			lib[6].sPublisher = "GN20";
			lib[6].sGenre = "novel";
			lib[6].bUsed = true;
			lib[7].sTitle = "Tropic Of Cancer";
			lib[7].sAuthor = "Henry Miller";
			lib[7].sPublisher = "GN20";
			lib[7].sGenre = "novel";
			lib[7].bUsed = true;
			lib[8].sTitle = "Gone With The Wind";
			lib[8].sAuthor = "Margaret Mitchell";
			lib[8].sPublisher = "GN20";
			lib[8].sGenre = "novel";
			lib[8].bUsed = true;
			lib[9].sTitle = "Beloved";
			lib[9].sAuthor = "Toni Morrison";
			lib[9].sPublisher = "GN20";
			lib[9].sGenre = "novel";
			lib[9].bUsed = true;
		break;
		
		default:
			PrintHelp();
		}
	} while (cCom != 'x');
	lib = nullptr;
	delete[] lib;
	return 0;
}

void Book::Edit()
{
	cout << "Title: "; getline(cin, sTitle);
	cout << "Author: "; getline(cin, sAuthor);
	cout << "Publisher: "; getline(cin, sPublisher);
	cout << "Genre: "; getline(cin, sGenre);
	bUsed = true;
}

void Book::Print()
{
	cout << "\nTitle: " << sTitle;
	cout << "\nAuthor: " << sAuthor;
	cout << "\nPublisher: " << sPublisher;
	cout << "\nGenre: " << sGenre;
}

bool Book::IsAuthor(string sValue)
{
	if (sAuthor == sValue) return true; else return false;
}

bool Book::IsTitle(string sValue)
{
	if (sTitle == sValue) return true; else return false;
}

void NewLine()
{
	cout << '\n';
}

void NewLine(int qty)
{
	for (int i = 0; i < qty; i++)
	cout << '\n';
}

void PrintHelp()
{
	cout << "\n e - edit record";
	cout << "\n p - print all records";
	cout << "\n a - search for author";
	cout << "\n t - search for title";
	cout << "\n b - sort by author";
	cout << "\n c - sort by title";
	cout << "\n d - sort by publisher";
	cout << "\n x - exit";
	cout << "\n 0 - !cheat! - fills array with books!!!";
}

