#include <iostream>
#include "conio.h"
#include "stdio.h"
int main()
{
    double x;
    double q = 0;
    std::cout << "Vvedite argument  x\n";
    std::cin >> x;
    __asm
    {
        fld1
        fadd st(0), st(0)
        fld x
        fptan
        fxch st(1)
        fmul st(0), st(2)
        fst st(1)
        fyl2x
        fld1
        fld x
        fmul st(0), st(0)
        fld x
        fmul st(0), st(1)
        fadd st(0), st(2)
        fsqrt
        fcos
        fmul st(0), st(1)
        f2xm1
        fadd st(0), st(2)
        fdiv st(0), st(3)
        fsqrt
        fld x
        fsub st(0), st(3)
        fcos
        fmul st(0), st(0)
        fsubr st(0), st(1)
        fstp q
    }
    std::cout << "q = " << q << "\n";
    _getch();
}
