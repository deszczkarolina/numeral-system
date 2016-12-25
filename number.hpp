/** \file
 * Name: number.hpp
 * Purpose: Number - deklaracja klasy Number
 * @author Karolina Deszcz
*/

#ifndef number_hpp
#define number_hpp
#define Maxlength 5
#include <iostream>
#include <vector>
#include <string>
#include "digit.hpp"


/// \brief Klasa liczby
class Number
{
    private:
        /// \brief system liczbowy w którym zapisana jest liczba (2-255)
        unsigned char base;
        /// \brief wektor cyfr o maksymalnej długości Maxlength (5), pierwsza cyfra w wektorze jest cyfrą najmniej znaczącą
        std:: vector <Digit> number;

    public:
        /// \brief konstruktor dwuargumentowy (system liczbowy, wartość cyfry)
        Number (unsigned short int numbersbase, unsigned short int digit);
        /// \brief metoda dodająca cyfrę do wektora (na jego koniec)
        void AddDigit (Digit newdigit);
        /// \brief metoda zwracjąca system liczbowy w którym zapisana jest liczba
        unsigned char GetBase () const;
        /// \brief metoda zwracjąca cyfrę znajdującą się na i-tej pozycji w liczbie
        Digit GetSingleDigit (int i) const;
        /// \brief metoda zamieniająca liczbę na long int
        long int CastNumber () const;
        /// \brief metoda zapisująca liczbę w postaci tekstowej (string)
        std:: string toString() const;
        /// \brief przeciążony operator long
        operator long () const;
        /// \brief Metoda która dodaje dwie liczby
        Number operator + (const Number & second) const;
};

/// \brief funkcja pomocnicza, która podnosi do potęgi liczbę całkowitą
long int power (unsigned short int base, int power);
#endif
