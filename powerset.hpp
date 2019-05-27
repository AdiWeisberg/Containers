#pragma once
#include <math.h>
namespace itertools{

template  <typename T> class powerset{

private:
T iter1;

public: 
powerset<T>(T power) : iter1(power){};

//inner class iterator
class iterator{
public:
T powerIter;
iterator(T a):powerIter(a){}

iterator& operator++()
{
    return *this;
}
const iterator operator++(int)
{
    return *this;
}

bool operator==(const iterator &other) const
{
    return other.powerIter == powerIter;
}
bool operator!=(const iterator &other) const
{
    return other.powerIter != powerIter;
}

auto operator*() const
{
    return powerIter;
}

};//end iterator class

public:
auto begin()const {return iter1.begin();} // return iterator(iterable1, iterable2)
auto end()const{return iter1.end();} // return iterator(iterable1, iterable2, false)
};//end class chain

};//end namespace itertools
