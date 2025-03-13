#include <iostream>
#include <string>
using namespace std;

int main()
{
	int a, b, c, d;

	cout << "Enter a, b: ";
	cin >> a >> b;
	cout << "Enter c, d: ";
	cin >> c >> d;

	int s; //счетчик

	_asm
	{
		mov s, 0
		mov eax, a
		mov ebx, b

		//jle проверяет флаги SF, OF, ZF

		jle w1	    //переходим к проверке первого условия

	//первое условие
	//(d > a) && (c > b)
	w1: 
		cmp d, eax  // (d > a) ??
		jle p_1	    // (d > a) = 1, (c > b)??
		jmp u	    // (d > a) = 0, проверка второго условия
	w2: 
		cmp c, ebx  // (с > b) ??
		jle p1		// (d > a)&(c > b), s=1
		jmp u		// иначе переходим ко второму условию

	p_1 :
		mov s, 1    // ()&&() = 1
		jmp endd    // переход в конец
	

	//второе условие
	//(с > a) && ( d > b)
	u :
		//е1
		cmp c, eax  // (c > a) ??
		jle e_2     // (c > a) = 1, (d > b)??
		jmp p_2     // (c > a) = 0

	e_2 :
		cmp d, ebx  // (d > b) ??
		jle p_1     // (d > b) = 1
		jmp p_2     // (d > b) = 0

	p_2 :
		mov s, 0	// ()&&() = 0
		jmp endd	// выходим из всех условий

		endd :		// конец всех условий

	}

	if (s > 0)
		cout << "No";
	else
		cout << "Yes";

	return 0;
}