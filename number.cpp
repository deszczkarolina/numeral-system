/** \file
 * Name: number.cpp
 * Purpose: Number - metody
 * @author Karolina Deszcz
*/


#define Maxlength 5
#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include "number.hpp"
using namespace std;

Number:: Number (unsigned  short int numbersbase, unsigned short int digit)
{
    /// gdy system liczbowy jest mniejszy od 2, to jest on automatycznie ustawiany na 2
    if (numbersbase < 2)
    {
#ifdef DEBUG_
        cout << "base should be bigger than 1, base is set on 2 now" << endl;
#endif
        base = 2;
    }
     /// gdy system liczbowy jest większy od 256, to jest on automatycznie ustawiany na 255
    else if (numbersbase > 255)
    {
#ifdef DEBUG_
        cout << "base should be smaller than 256, base is set on 255 now" << endl;
#endif
        base = 255;
    }
    else base = numbersbase;

    if (digit < numbersbase ) number.push_back (digit);
    else number.push_back (0); //when digit doesn't belong to the system it's replaced by 0


#ifdef DEBUG_
     cout << "New number has been created" <<endl;
#endif
}

unsigned char Number::GetBase () const
{
    return base;
}

Digit Number::GetSingleDigit (int i) const
{
 /// gdy liczba ma mniej niż i cyfr funkcja zwraca 0
    if (number.size() < i)
    {
#ifdef DEBUG_
        cout << "Number has less than i digits " << endl;
#endif
        return Digit(0);
    }

    return number[i];
}

void Number:: AddDigit (Digit newdigit)
{
     /// gdy liczba składa się już z maksymalnej liczby cyfr funkcja zakończy swoje działanie nie dokonując żadnych zmian
    if (number.size() == (Maxlength))
    {
#ifdef DEBUG_
        cout << "cannot add more digits to number" << endl;
#endif
        return ;
    }

    if (newdigit.GetDigit() >= base)
    {
#ifdef DEBUG_
        cout << "digit has to be smaller than the base" << endl;
#endif
    return; /// gdy cyfra nienależy do systemu w którym zapisana jest liczba, funkcja zakończy swoje działanie nie dokonując żadnych zmian
    }

    else number.push_back (newdigit);
}

long int power (unsigned short int base, int power)
{
    int i, result=1;
    for (i=1; i <= power; i++)
        result = result * base;
    return result;

}

long int Number:: CastNumber() const
{

    long int i,n=0, length;
    length = number.size();
    /// Idąc od najmniej znaczącej cyfry, do wartosci liczby dodawana jest (wartosc cyfry) * ((system liczbowy liczby) do potegi (indeks cyfry)).
    for ( i = 0 ; i < length; i++)
        n = n + (number[i].GetDigit())*power(base, i);

    return n;
}

/// funkcja "przepisuje" kolejne cyfry wektora, idąc "od tyłu", poszczególne cyfry oddzielone są spacjami
string Number:: toString() const
{
    string result = "";
    int length = number.size();
    int i;
    for (i = length - 1; i >= 0 ; i--)
        result = result + std:: to_string( (unsigned short int) (number[i].GetDigit() )) + " ";
    return result;
}

Number:: operator  long () const
{
    long int i,n=0, length;
    length = number.size();

    for ( i = 0 ; i < length; i++)
        n = n + (number[i].GetDigit())*power(base, i);

    return n;
}

 Number Number::operator + (Number second) const
{

    Number sum(base,0);
    long int x, a, b;
    int i = 0;
    a = this->CastNumber();
    b = second.CastNumber();
    x = a + b;
    sum.number.pop_back();
    while (x != 0 )
    {
        sum.number.push_back(x % base);
        x = x/(long int)base;

    }
    return sum;
}






