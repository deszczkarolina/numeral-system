/** \file
 * Name: digit.cpp
 * Purpose: Digit - metody
 * @author Karolina Deszcz
*/



#include <iostream>
#include "digit.hpp"
using namespace std;

Digit::Digit (unsigned short int newdigit )
{
    digit = newdigit % 255;

#ifdef DEBUG_
    cout << "new digit has been created" << endl;
#endif // DEBUG_
}

unsigned char Digit::GetDigit () const
{
    return digit;
}


Digit Digit::operator + (Digit second) const
{
    Digit sum = (((unsigned short int)digit + (unsigned short int)second.digit)% 255);
    return sum;
}
