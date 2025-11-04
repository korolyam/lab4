#include <iostream>
#include "conio.h"
#include "stdio.h"
int main()
{
    double trash;
    double a;
    double n = 1;
    std::cout << "Vvedite border a\n";
    std::cin >> a;
    if (a <= 1 || a >= 1.5)
    {
        std::cout << "Given progression will never be larger than a\n";
        _getch();
        return 0;
    }
    __asm
    {
        do_this:
        fld1
        fld n
        fadd st(0), st(1)
        fst n
        fdivr st(0), st(1)
        fadd st(0), st(1)
        fcom a
        fstsw ax
        sahf
        fstp trash
        fstp trash
        jae do_this
    }
    std::cout << "n = " << n << "\n";
    _getch();
    return 0;
}
