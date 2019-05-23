# include <iostream>

namespace itertools{

template  <typename R,typename V> 
class chain{

private:
R iter1;
V iter2;

public:
chain<R,V>(const R start,const V end) : iter1(start),iter2(end){};

//inner class iterator
template  <typename T,typename U> class iterator{
public:
    T firstIter;
    U secondIter;
    bool isEnded;
   
    iterator(T a,U b):firstIter(a),secondIter(b),isEnded(false){}
   
    iterator& operator++() //ok
    {
        if(isEnded){
            ++secondIter;
        }
        else{
            ++firstIter;
        }
        return *this;
    }
   
    const iterator operator++(int) //ok
    {
        if(isEnded){
            secondIter++;
        }
        else{
            firstIter++;
        }
        return *this;
    }
   
    bool operator!=(const chain::iterator<T,U> &other) //ok?
    {
        if(!(firstIter != other.firstIter)){
            isEnded = true;
        }
        if(!isEnded){
            return (firstIter != other.firstIter);
        }
        else return (secondIter != other.secondIter);
       
    }
   
    auto operator*() const
    {
        if(isEnded){
            return *secondIter;
        }
        else{
            return *firstIter;
        }
    }

};//end iterator class

public:
    auto begin()const {
        return iterator<decltype(iter1.begin()), decltype(iter2.begin())>(iter1.begin(), iter2.begin());
       
    }
   
    auto end()const{
        return iterator<decltype(iter1.end()), decltype(iter2.end())>(iter1.end(), iter2.end());
    }
   
};//end class chain

};//end namespace itertool