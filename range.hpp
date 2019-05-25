#pragma once
#include <iostream>
using namespace std;

namespace itertools
{

template <typename R>
class range
{
public:
    R startIter, endIter;
    range<R>(R start, R end) : startIter(start), endIter(end){};

    class iterator
    {
    private:
        R iterR;

    public:
        iterator()
        {
        }
        iterator(R other)
        {
            iterR = other;
        }

        iterator &operator++()
        {
            iterR++;
            return *this;
        }
        const iterator operator++(int)
        {
            iterator tmpIter = *this;
            iterR = iterR++;
            return tmpIter;
        }

        bool operator==(const iterator &other) const
        {
            return other.iterR == iterR;
        }
        bool operator!=(const iterator &other) const
        {
            return other.iterR != iterR;
        }

        R operator*() const
        {
            return iterR;
        }
    };

    iterator begin() const
    {
        return range<R>::iterator(startIter);
    }

    iterator end() const
    {
        return range<R>::iterator(endIter);
    }
};

} // namespace itertools
