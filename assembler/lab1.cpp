#include <iostream>
using namespace std;

int main()
{
	short int x;

	 //ассемблерная вставка
	_asm
	{
	//    eax               ah  (ax)  al
	//     |_____________|________|________|

		//AL - 1 байт
		//АХ - 2 байта

		mov AL, 0xAB //помещаем в регистр значение 0хАВ
		mov AH, 0    //очищаем чтобы не выводилось лишнее
		mov x, AX    //записываем в х AX
	}

	cout << "AL = " << x;
}