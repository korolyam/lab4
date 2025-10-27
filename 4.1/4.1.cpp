#include <iostream>
#include "conio.h"
#include "stdio.h"
#include <iomanip>
#include <cstdlib>
int main()
{
    double p;
    double S;
    double help = 1.05;
    double sum = 0;
    double number = 1;
    std::cout << "Vvedite p(1st deposit) and S (Sum of money needed)\n";
    std::cin >> p >> S;
    __asm
    {
        fld p
        fld sum
        fadd st(0), st(1)
        fcom S
        fstsw ax
        sahf
        fstp sum
        ja Hvatilo_srazu
        fstp p
        Ne_hvataet :
        fld help
            fld p
            fmul st(0), st(1)
            fstp p
            fld p
            fld sum
            fld number
            fld1
            faddp st(1), st(0)
            fstp number
            fadd st(0), st(1)
            fcom S
            fstsw ax
            sahf
            fstp sum
            fstp p
            jb Ne_hvataet
            Hvatilo_srazu :
    }
    std::cout << "Month = " << number << "\n";
    _getch();
    return 0;
}
