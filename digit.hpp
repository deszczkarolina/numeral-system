/** \file
 * Name: digit.hpp
 * Purpose: deklaracja klasy Digit
 * @author Karolina Deszcz
*/

#ifndef digit_hpp
#define digit_hpp
#include <iostream>

/// \brief Klasa cyfry
class Digit
{
    private:
        /// \brief wartość cyfry
        unsigned char digit;

    public:
        /// \brief konstruktor jednoargumentowy
        ///przy podaniu cyfry większej od 255, konstruktor zamienia wartość cyfry na cyfrę % 255
        Digit (unsigned short int  newdigit );
        /// \brief metoda zwracająca wartość cyfry
        unsigned char GetDigit () const;
        /// \brief metoda dodająca dwie cyfry
        /// Metoda tworzy nową cyfrę, której wartość jest sumą wartosci dodawnanych cyfr modulo 255. Funkcja zwraca nowoutworzoną cyfrę
        Digit operator +(Digit second) const ;
};
#endif
