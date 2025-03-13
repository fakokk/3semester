#include <iostream>
using namespace std;


int main()
{
	//AH - 1 байт
	char x1, x2;
	//BX - 2 байта 
	unsigned short int y1, y2;
	//EDX - 4 байта
	unsigned int z1, z2;

	cin >> x1 >> y1 >> z1;

	_asm
	{
		//в регистры AH, BX, EDX поместить высокоуровневые переменные
		mov AH, x1
		mov x2, AH

		mov BX, y1
		mov y2, BX

		mov EDX, z1
		mov z2, EDX
	}
	
	cout << x2 << endl << y2 << endl << z2;
}