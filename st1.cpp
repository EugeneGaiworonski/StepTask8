// Задание 1: 
// Создайте структуру, описывающую комплексное число. 
// Реализуйте арифметические операции с комплексными числами: 
// сумму, разность, умножение, деление.

#include <iostream>
#include <conio.h>

class compl 
{
public:
	compl ()
	{
		Re = 0.0;
		Im = 0.0;
	}
	~compl ()
	{
		;
	}
	compl operator + (const compl& b)
	{
		compl sum;
		sum.Re = this->Re + b.Re;
		sum.Im = this->Im + b.Im;
		return sum;
	}
	compl operator - (const compl& b)
	{
		compl diff;
		diff.Re = this->Re - b.Re;
		diff.Im = this->Im - b.Im;
		return diff;
	}
	compl operator * (const compl& b)
	{
		compl prod;
		prod.Re = (this->Re * b.Re) - (this->Im * b.Im);
		prod.Im = (this->Re * b.Im) + (this->Im * b.Re);
		return prod;
	}
	compl operator / (const compl& b)
	{
		compl quot;
		quot.Re = ((this->Re * b.Re) + (this->Im * b.Im))/((b.Re * b.Re) + (b.Im * b.Im));
		quot.Im = ((this->Im * b.Re) - (this->Re * b.Im))/((b.Re * b.Re) + (b.Im * b.Im));
		return quot;
	}
	

private:
	float Re;
	float Im;
public:
	friend std::ostream& operator<< (std::ostream& out, const compl& val)
	{
		out << val.Re;
		if (val.Im >= 0) out <<'+';
		out	<< val.Im << 'i';
		return out;
	}
	friend std::istream& operator>> (std::istream& in, compl& val)
	{
		in >> val.Re; in >> val.Im;
		return in;
	}
};


int main()
{
	compl a,b,r;
	std::cout << "\na = ";
	std::cin >> a;
	std::cout << '\n' << a;
	std::cout << "\nb = ";
	std::cin >> b;
	std::cout << '\n' << b;
	r = a + b;
	std::cout << "\na + b = " << r; 
	r = a - b;
	std::cout << "\na - b = " << r; 
	r = a * b;
	std::cout << "\na * b = " << r; 
	r = a / b;
	std::cout << "\na / b = " << r;
	_getche();
	return 0;
}
