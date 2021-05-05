#include <iostream>
#include <conio.h>

volatile int Add(int, int, int&);

int main()
{
	int a = INT_MAX; int b = INT_MAX;
	int s = 0;
	int ovf = 1;
	s = Add(a,b, ovf);
	std::cout << a <<' '<< b << ' ' << s;
	if (ovf==1) { std::cout << " OV";} 
	if (ovf==0) {std::cout << " NO";}
	_getche();
	return 0;
}

volatile int Add(int x, int y, int& ov)
{
	_asm {
		mov ov,0
		mov eax,x
		mov ebx,y
		add eax,ebx
		mov x, eax
		jno lb1
		mov ov, 1
	lb1:
		mov ov,1
		xor eax,eax
	}
	return x;
}
