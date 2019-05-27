#pragma once
#include <iostream>
#include <utility>
#include <ostream>
using std::pair;


namespace itertools
{
template <typename T, typename U>
class product
{

public:
    const T container1;
    const U container2;

    product(const T &a, const U &b) : container1(a), container2(b) {}

    // inner iterator class
    class iterator
    {

    public:
        decltype(container1.begin()) iter1;
        decltype(container1.end()) iter1_end;
        decltype(container2.begin()) iter2;
        decltype(container2.begin()) iter2Begin;
        decltype(container2.end()) iter2end;
        //bool finished;

        iterator(const T &a, const U &b) : 
        iter1(a.begin()), iter2(b.begin()), iter1_end(a.end()), iter2end(b.end()), iter2Begin(b.begin()) {}

        iterator(const T &a, const U &b, int i) : iter1(a.end()), iter1_end(a.end()), iter2(b.end()),iter2end(b.end()),iter2Begin(b.begin()) {}

        auto operator*() const
        {

            return make_pair(*iter1, *iter2);
        }

        iterator &operator++()
        {
           
   
            if(iter1 != iter1_end){
                ++iter2;
            }

            if(iter2 == iter2end){
                iter2 = iter2Begin;
                ++iter1;
            }

            return *this;

        }

        bool operator!=(const iterator &other)
        {

            return (iter1 != other.iter1 && iter2 != other.iter2);
        }

        bool operator==(const iterator &other)
        {

            return (iter1 == other.iter1 && iter2 == other.iter2);
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

// template <typename T, typename U>
// ostream &operator<<(ostream &os, const pair<T, U> &pair)
// {
//     os << pair.first << "," << pair.second;
//     return os;
//}

} // namespace itertools

