#include <iostream>
using namespace std;

int main()
{
	short int n; //минуты
	cin >> n;
	short int a; //угол

	_asm
	{
		mov AX, n
		mov BX, 6
		mul BX;
		mov a, AX
	}

	cout << a;


}