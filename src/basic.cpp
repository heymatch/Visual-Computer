#include "basic.h"

Bit::Bit(int instance){
    _instance = instance;
}

std::ostream &operator<<(std::ostream &out, const Bit &right){
    out << right._instance;
    return out;
}

Bitset::Bitset(size_t size){
    _size = size;
    _instance = new Bit[size];
}

Bitset Bitset::operator&(const Bitset &right){
    Bitset temp = *this;
    for(size_t i = 0; i < _size; ++i)
        temp._instance[i] &= right._instance[i];
    return temp; 
}

Bitset Bitset::operator|(const Bitset &right){
    Bitset temp = *this;
    for(size_t i = 0; i < _size; ++i)
        temp._instance[i] |= right._instance[i];
    return temp; 
}

Bitset Bitset::operator^(const Bitset &right){
    Bitset temp = *this;
    for(size_t i = 0; i < _size; ++i)
        temp._instance[i] ^= right._instance[i];
    return temp; 
}

Bitset Bitset::operator<<(size_t shift){
    Bitset temp = *this;
    for(size_t i = 0; i < _size; ++i){
        temp._instance[i] = i + shift < _size ? temp._instance[i+shift] : Bit(0);
    }

    return temp;
}

Bitset Bitset::extend(size_t size) const{
    Bitset temp(size);
    for(size_t i = 0; i < _size; ++i){
        temp._instance[i] = _instance[i];
    }

    return temp;
}

std::ostream &operator<<(std::ostream &out, const Bitset &right){
    for(size_t i = 0; i < right._size; ++i)
        out << right._instance[i];
    return out;
}

Byte::Byte() : Bitset(8){}

Word::Word() : Bitset(32){}

Integer::Integer(size_t size, int immediate, size_t base){
    _size = size;
    _base = base;
    _instance = Bitset(size);
    *this = immediate;
}

Integer &Integer::operator=(const int &right){
    _instance[0] = right < 0 ? Bit(1) : Bit(0);
    int temp = right;
    for(size_t i = 1; i < _size && temp > 0; ++i){
        _instance[i] = Bit(temp % 2);
        temp /= 2;
    }
    return *this;
}

Integer &Integer::operator=(const Integer &right){
    _size = right._size;
    _base = right._base;
    for(size_t i = 0; i < _size; ++i){
        _instance[i] = right._instance[i];
    }
    return *this;
}

Integer Integer::operator+(const Integer &right){
    size_t size = _size > right._size ? _size : right._size;
    Integer tempA = this->extend(size), tempB = right.extend(size), tempC(size);
    Bit carry(0);
    for(size_t i = 0; i < size; ++i){
        tempC._instance[i] = tempA._instance[i] ^ tempB._instance[i] ^ carry;
        carry =  (tempA._instance[i] & tempB._instance[i]) | ((tempA._instance[i] ^ tempB._instance[i]) & carry);
    }

    return tempC;
}

Integer Integer::extend(size_t size) const{
    Integer temp = *this;
    temp._size = size;
    temp._instance = temp._instance.extend(size);

    return temp;
}

std::ostream &operator<<(std::ostream &out, const Integer &right){
    if(right._instance[0] != Bit(0))
        out << '-';
    for(size_t i = 1; i < right._size; ++i)
        out << right._instance[i];
    return out;
}