
namespace itertools{

template  <typename T,typename U> class chain{

private:
T iter1;
U iter2;

public: 
chain<T,U>(T start, U end) : iter1(start),iter2(end){};

//inner class iterator
class iterator{
public:
T firstIter;
U secondIter;
bool isEnded;
iterator(T a,U b):firstIter(a),secondIter(b),isEnded(false){}

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
    return other.firstIter == firstIter;
}
bool operator!=(const iterator &other) const //ok?
{
    if(firstIter && firstIter != other.firstIter){
        return true;
    }
    if(!firstIter && secondIter != other.secondIter){
        return true;
    }
    return false;
}

auto operator*() const //ok?
{
    if(firstIter) return *firstIter;
    else return *secondIter;
}

};//end iterator class

public:
auto begin()const {return iter1.begin();} // return iterator(iterable1, iterable2)
auto end()const{return iter1.end();} // return iterator(iterable1, iterable2, false)
};//end class chain

};//end namespace itertools
