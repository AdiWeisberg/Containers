#pragma once
#include <math.h>
namespace itertools{

template  <typename T> class powerset{

private:
T container1;
int subsetNum;

public: 
powerset<T>(T power) : iter1(power){
    subsetNum = pow(2,container1.length())
};

//inner class iterator
class iterator{
public:
decltype(container1.begin()) iterPower;
decltype(container1.begin()) iterBegin;
int finish;
int start;

iterator(const T &a,int num):iterPower(a.begin()),iterBegin(a.begin()){
    start = num;
    finish = pow(2,a.length());
}

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
    return other.iterPower == iterPower;
}
bool operator!=(const iterator &other) const
{
    return other.iterPower != iterPower;
}

auto operator*() const
{
    return powerIter;
}

};//end iterator class

public:
  iterator begin() const
    {
        return iterator{container1, 0};
    }
    iterator end() const
    {
        return iterator{container1,subsetNum};
    }
};//end class chain

};//end namespace itertools