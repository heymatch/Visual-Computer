/**
 * Bit
 * Bitset
 * Integer
 * Node
 * 
 */

#ifndef BASIC
#define BASIC

#include <cstdlib>
#include <ostream>
#include <iomanip>
#include "exception.h"

struct Bit{
    Bit(int instance = 0);
    inline Bit operator&(const Bit &right) { return _instance & right._instance; }
    inline Bit &operator&=(const Bit &right) { return *this = *this & right; }
    inline Bit operator|(const Bit &right) { return _instance | right._instance; }
    inline Bit &operator|=(const Bit &right) { return *this = *this | right; }
    inline Bit operator^(const Bit &right) { return _instance ^ right._instance; }
    inline Bit &operator^=(const Bit &right) { return *this = *this ^ right; }
    inline bool operator==(const Bit &right) { return _instance == right._instance; }
    inline bool operator!=(const Bit &right) { return _instance != right._instance; }

    int _instance;
};

std::ostream &operator<<(std::ostream &out, const Bit &right);

struct Bitset{
    Bitset(size_t size = 1);
    Bitset operator&(const Bitset &right);
    inline Bitset operator&=(const Bitset &right){ return *this = *this & right; }
    Bitset operator|(const Bitset &right);
    inline Bitset operator|=(const Bitset &right){ return *this = *this | right; }
    Bitset operator^(const Bitset &right);
    inline Bitset operator^=(const Bitset &right){ return *this = *this ^ right; }

    Bitset operator<<(size_t shift);
    
    inline Bit operator[](size_t index) const { return _instance[index]; }
    inline Bit &operator[](size_t index) { return _instance[index]; }

    Bitset extend(size_t size) const;

    size_t _size;
    Bit *_instance;
};

std::ostream &operator<<(std::ostream &out, const Bitset &right);

struct Byte : Bitset{
    Byte();
};

struct Word : Bitset{
    Word();
};

struct Integer{
    Integer(size_t size = 2, int immediate = 0, size_t base = 2);

    Integer &operator=(const int &right);
    Integer &operator=(const Integer &right);
    Integer operator+(const Integer &right);

    Integer extend(size_t size) const;

    size_t _size;
    size_t _base;
    Bitset _instance;
};

std::ostream &operator<<(std::ostream &out, const Integer &right);

#endif