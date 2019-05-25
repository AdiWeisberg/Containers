#pragma once
#include <iostream>
#include <utility>
#include <ostream>


namespace itertools
{
template <typename T, typename R>
class chain
{

public:
    const T container1;
    const R container2;

    chain(const T &a, const R &b) : container1(a), container2(b) {}
    

    // inner iterator class
    class iterator
    {

    public:
        decltype(container1.begin()) iter1;
        decltype(container2.begin()) iter2;
        bool isEnded;

        iterator(const T &a, const R &b): iter1(a.begin()), iter2(b.begin()),isEnded(false) {}

        iterator(const T &a, const R &b, int i) : iter1(a.end()), iter2(b.end()),isEnded(true) {}

        auto operator*() const
        {

            if(isEnded){
                return *iter2;
            }
            else return *iter1;
        }

        iterator &operator++()
        {
           if(isEnded){
                ++iter2;
            }
            else ++iter1;
            return *this;
        }

        bool operator!=(const iterator &other)
        {
            if(!(iter1!=other.iter1)){
                isEnded = true;
            }
            if(!isEnded){
                return (iter1!=other.iter1);
            }
            else return (iter2 != other.iter2);
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


} // namespace itertools
