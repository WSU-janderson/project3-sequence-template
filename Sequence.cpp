/**
 * Sequence.cpp
 * Project 3
 * CS 3100
 */
#include "Sequence.h"

#include <iostream>
#include <exception>

using namespace std;

Sequence::Sequence(size_t sz)
{

}

Sequence::Sequence(const Sequence& s)
{

}

Sequence::~Sequence()
{

}

Sequence& Sequence::operator=(const Sequence& s)
{
    return *this;
}

int& Sequence::operator[](size_t position)
{
    throw exception();
}

void Sequence::push_back(const int& value)
{
}

void Sequence::pop_back()
{
    throw exception();
}

void Sequence::insert(size_t position, int value)
{
    throw exception();
}

int Sequence::front() const
{
    throw exception();
}

int Sequence::back() const
{
    throw exception();
}

bool Sequence::empty() const
{
    return false;
}

size_t Sequence::size() const
{
    return -1;
}

void Sequence::clear()
{

}

void Sequence::erase(size_t position)
{
    throw exception();
}

void Sequence::erase(size_t position, size_t count)
{
    throw exception();
}

ostream& operator<<(ostream& os, const Sequence& s)
{
    return os;
}
