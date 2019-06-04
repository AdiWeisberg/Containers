#pragma once

#include <math.h>
#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using std::ostream;
using std::vector;
using namespace std;


namespace itertools{
    template<typename T>
    class powerset{
        private: 
            T container;
        
        template<typename U>
        class iterator{
            private:
                const U firstIter; // start location
                const U lastIter; // end location
                unsigned int index; // curr place of the iterator
                unsigned int setSize; // the total size of the set.
            public:
                iterator(U _first, U _last) : firstIter(_first), lastIter(_last), index(0), setSize(0){
                    //calculate the size of the set: 
                    unsigned int counter = 0; 
                    U curr = firstIter;
                    while(curr != lastIter){
                        ++counter;
                        ++curr;
                    }
                    setSize = pow(2, counter); // 2^containerSize is the number of all the combinations.
                }
                
                auto operator*() const {
                    vector<typename remove_const<typename remove_reference<decltype(*firstIter)>::type>::type> setPower; //get the original element’s type (not a const reference to it).
                    U curr_iter = firstIter; // start location
                    unsigned int i = index; //the current index
                    while(curr_iter != lastIter){
                        if(i){ // 0 = false, 1 = true.
                            set.emplace_back(*curr_iter); //add directly to the end without create new object and copy it.
                        }
                        i = i >> 1; // divide by 2 using shift-left.
                        ++curr_iter;
                    }
                    return set;
                }
                
                //operators for iterator: operator!=, operator*, operator++:
                
                bool operator !=(iterator<U> const& other) const{
                    return(setSize - index != other.setSize  - other.index -1);
                }
                
                iterator<U> &operator++(){
                    ++index;
                    return *this;
                }
                
        }; //end of iterator class
        
        public: 
            powerset(const T _container) container(_container); // constructor for set
            
            auto begin() const {
                return iterator<decltype(container.begin())>(container.begin(), container.end()));
            }
            auto end() const {
                return iterator<decltype(container.end())>(container.end(), container.end()));
            }
    }; //end of powerset class
    
    template<typename T>
    ostream &operator<<(std::ostream &os, const std::vector<T> &set){
        os << "{"; // start output
        auto curr = set.begin();
        if(curr != set.end()){ // first iteration 
            os << *curr;
            ++curr;
        }
        while(curr != set.end()){ 
            os << ',' << *curr;
            ++curr;
        }
        os << "}";
        return os;
    }

}; // end of itertools namespace
