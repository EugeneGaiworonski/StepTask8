#include <iostream>
#include <string>
class my_cl
{
public:
	int a;
	float b;
public:
	my_cl(int num1, float num2);
	const my_cl& operator+(const my_cl& i)
	{
		my_cl np(0,0);
		np.a = a + i.a;
		np.b = b + i.b;
		return np;
	}
};

my_cl::my_cl(int num1, float num2)
{
	a = num1;
	b = num2;
}

int main()
{
	my_cl a(5, 5.5), b(-100, 50.7);
	a = a + b;
	std::cout << a.a << " " << a.b;
}
