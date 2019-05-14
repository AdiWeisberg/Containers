namespace itertools{

template  <typename E,typename M> class product{

private:
E iter1;
M iter2;

public: 
product<E,M>(E start, M end) : iter1(start),iter2(end){};

//inner class iterator
class iterator{
public:
E firstIter;
M secondIter;
iterator(E a,M b):firstIter(a),secondIter(b){}

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
bool operator!=(const iterator &other) const
{
    return other.firstIter != firstIter;
}

auto operator*() const
{
    return firstIter;
}

};//end iterator class

public:
auto begin()const {return iter1.begin();} // return iterator(iterable1, iterable2)
auto end()const{return iter1.end();} // return iterator(iterable1, iterable2, false)
};//end class chain

};//end namespace itertools