# include <iostream>
#include "range.hpp"
#include <utility>
using std::pair;
using namespace std;
namespace itertools{

template<typename T, typename U> class mypair;

template <typename T,typename U>  
class zip{

private:
T iter1;
U iter2;

public:
zip<T,U>(const T start,const U end) : iter1(start),iter2(end){};

//inner class iterator

class iterator{
    private:
        decltype(iter1.begin()) firstIter;
        decltype(iter2.begin()) secondIter;

    public:

        iterator(decltype(iter1.begin()) a,decltype(iter2.begin()) b):firstIter(a),secondIter(b){}
    
        iterator& operator++() 
        {
            ++firstIter;
            ++secondIter;
            return *this;
        }

        bool operator==(const iterator &other){
            return (firstIter==other.firstIter);
        }
    
        bool operator!=(const iterator &other) const //ok?
        {
        return  (firstIter!=other.firstIter);
        }
    
        auto operator*() const
        {
            return make_pair(*firstIter,*secondIter);
        }

};//end iterator class


    public:
        iterator begin()  {
            return iterator(iter1.begin(), iter2.begin());
        
        }
    
        iterator end() {
            return iterator(iter1.end(), iter2.end());
        }
    
};//end class zip

//     template<typename Q, typename A> class mypair{
//     private:
//         Q first;
//         A second;
//     public:
//         mypair<Q,A>(const Q f, const A s): first(f), second(s){} //constructor


// };//end mypair class

        template <typename T,typename U>
        ostream& operator<<(ostream& os ,const pair<T,U> &p){
            os<<p.first << ","<<p.second;
            return os;
        }

};//end namespace itertool