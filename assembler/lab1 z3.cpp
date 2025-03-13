#include <iostream>
using namespace std;

int main()
{
    short int x; //ecx
    int y;       //cx

    cin >> x;

    _asm
    {
        mov ECX, 0  //ЕСХ - 32 разр - 4 байта
        mov CX, x   //СХ - 16 разр - 2 байта
        mov y, ECX  
    }

    cout << "y = " << y;
}