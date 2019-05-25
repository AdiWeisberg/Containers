#pragma once
#include <iostream>
#include <utility>
#include <ostream>
using std::pair;
#include "chain.hpp"

namespace itertools
{
template <typename T, typename U>
class zip
{

public:
    const T container1;
    const U container2;

    zip(const T &a, const U &b) : container1(a), container2(b) {}
    

    // inner iterator class
    class iterator
    {

    public:
        decltype(container1.begin()) iter1;
        decltype(container2.begin()) iter2;

        iterator(const T &a, const U &b): iter1(a.begin()), iter2(b.begin()) {}

        iterator(const T &a, const U &b, int i) : iter1(a.end()), iter2(b.end()) {}

        auto operator*() const
        {

            return make_pair(*iter1, *iter2);
        }

        iterator &operator++()
        {
            ++iter1;
            ++iter2;
             return *this;
        }

        bool operator!=(const iterator &other)
        {
            return (iter1 != other.iter1 && iter2 != other.iter2);
        }
    };

    //end of class iterator

    iterator begin() const
    {
        return iterator{container1, container2};
    }
    iterator end() const
    {
        return iterator{container1, container2, 1};
    }

};


template <typename T, typename U>
ostream &operator<<(ostream &os, const pair<T, U> &pair)
{
    os << pair.first << "," << pair.second;
    return os;
}

} // namespace itertools
