//tests
#include <iostream>

using namespace std;
#include <string>
#include "zip.hpp"
#include "product.hpp"
#include "chain.hpp"
#include "powerset.hpp"
#include "range.hpp"
#include "badkan.hpp"
using namespace itertools;

template <typename Iterable>
string iterable_to_string(const Iterable &iterable)
{
    ostringstream ostr;
    for (auto i : iterable)
        ostr << i << " ";
    return ostr.str();
}

int main()
{

    badkan::TestCase testcase;
    int grade = 0;
    int signal = setjmp(badkan::longjmp_buffer);
    if (signal == 0)
    {
        //the answers we expect from range
        string ans1 = "1 2 3 4 5 6 7 8 ";
        string ans2 = "a b c d e f ";
        string ans3 = "1.2 2.2 3.2 4.2 ";
        string ans4 = "B C ";
        string ans5 = "( ) ";
        string ans6 = "? @ A B ";

        testcase.setname("range tests")
            .CHECK_EQUAL(iterable_to_string(range(1, 9)), ans1)
            .CHECK_EQUAL(iterable_to_string(range('a', 'g')), ans2)
            .CHECK_EQUAL(iterable_to_string(range(1.2, 5.2)), ans3)
            .CHECK_EQUAL(iterable_to_string(range('B', 'D')), ans4)
            .CHECK_EQUAL(iterable_to_string(range('(', '*')), ans5)
            .CHECK_EQUAL(iterable_to_string(range('?', 'C')), ans6);

        //the answers we expect from chain
        string ansCh1 = "1 2 3 5 6 7 ";
        
        string ansCh2 = "A B C C B A ";
        string ansCh3 = "a d i m i c h a l ";

        testcase.setname("chain tests")
            .CHECK_EQUAL(iterable_to_string(chain(range(1, 4), range(5, 8))), ansCh1)
            .CHECK_EQUAL(iterable_to_string(chain(range('A', 'D'), string("CBA"))), ansCh2)
            .CHECK_EQUAL(iterable_to_string(chain(string("adi"), string("michal"))), ansCh3);

        //the answers we expect from zip
        string ansZip1 = "1,5 2,6 3,7 ";
        string ansZip2 = "1,11 2,12 3,13 4,14 ";
        string ansZip3 = "a,1 b,2 c,3 d,4 ";
        string ansZip4 = "1,x,a,6 2,y,b,7 3,z,c,8 ";

        testcase.setname("zip tests")
            .CHECK_EQUAL(iterable_to_string(zip(range(1,4), range(5, 8))), ansZip1)
            .CHECK_EQUAL(iterable_to_string(zip(chain(range(1,3),range(3, 5)),chain(range(11,13),range(13,15)))), ansZip2)
            .CHECK_EQUAL(iterable_to_string(zip(chain(range('a','c'), range('c','e')),range(1,5))), ansZip3)
            .CHECK_EQUAL(iterable_to_string(zip(zip(range(1,4), string("xyz")),zip(string("abc"),range(6,9)))), ansZip4);

        // //the answers we expect from product
        // string ansPro1 = "1,h 1,i 2,h 2,i ";
        // string ansPro2 = "#,4 #,5 $,4 $,5 ";
        // string ansPro3 = "C,d C,o C,g A,d A,o A,g T,d T,o T,g ";

        // testcase.setname("product tests")
        //     .CHECK_EQUAL(iterable_to_string(product(range(1,3), string("hi"))), ansPro1)
        //     .CHECK_EQUAL(iterable_to_string(product(range('#','%'), range(4,6))), ansPro2)
        //     .CHECK_EQUAL(iterable_to_string(product(string("CAT"), string("dog"))), ansPro2);

        // //the answers we expect from product
        // string ansPower1 = "{} {&} {@} {!} {&,@} {&,!} {@,!} {&,@,!} ";
        // string ansPower2 = "{} {a} {b} {c} {d} {a,b} {a,c} {a,d} {b,c} {b,d} {c,d} {a,b,c} {a,b,d} {a,c,d} {b,c,d} {a,b,c,d} ";
        // string ansPower3 = "{} {7} {8} {9} {7,8} {7,9} {8,9} {7,8,9} ";
        // string ansPower4 = "{} {a} {b} {x} {y} {a,b} {a,x} {a,y} {b,x} {b,y} {x,y} {a,b,x} {a,b,y} {a,x,y} {b,x,y} {a,b,x,y} ";

        // testcase.setname("powerSet tests")
        //     .CHECK_EQUAL(iterable_to_string(powerset(string("&@!"))),ansPower1)
        //     .CHECK_EQUAL(iterable_to_string(powerset(string("abcd"))),ansPower2)
        //     .CHECK_EQUAL(iterable_to_string(powerset(range(7,10))),ansPower3)
        //     .CHECK_EQUAL(iterable_to_string(powerset(chain(range('a','c'),range('x','z')))),ansPower4);

        grade = testcase.grade();
    }
    else
    {
        testcase.print_signal(signal);
        grade = 0;
    }
    cout << "Your grade is: " << grade << endl;
    return 0;
}
