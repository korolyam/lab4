#include <iostream>
#include "conio.h"
#include "stdio.h"
int main()
{
    double trash;
    double a = 0;
    double b = 1;
    int n = 11;
    double sum = 0;
    double help = -1;
    double temp;
    __asm
    {
        mov ecx, n
        loopa:
        fld1
        fld a
        fld b
        fadd st(0), st(2)
        fadd st(1), st(2)
        fstp b
        fst a
        fld b
        fdivr st(0), st(1)
        fstp temp
        mov n, ecx
        and ecx, 1
        cmp ecx, 0
        je shmeven
        fld temp
        fld help
        fmul st(1), st(0)
        fstp help
        fstp temp
        shmeven:
        mov ecx, n
        fld temp
        fld sum
        fadd st(0), st(1)
        fstp sum
        fstp trash
        fstp trash
        fstp trash
        loop loopa
    }
    std::cout << "Sum = " << sum << "\n";
    _getch();
    return 0;
}
