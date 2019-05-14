namespace itertools{

template  <typename T,typename U> class zip{

private:
T iter1;
U iter2;

public: 
zip<T,U>(T start, U end) : iter1(start),iter2(end){};

//inner class iterator
class iterator{
public:
T firstIter;
U secondIter;
iterator(T a,U b):firstIter(a),secondIter(b){}

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