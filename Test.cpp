//tests
#include <iostream>
using namespace std;

#include "zip.hpp"
#include "product.hpp"
#include "chain.hpp"
#include "powerset.hpp"
#include "range.hpp"
#include "badkan.hpp"

int main(){

    badkan::TestCase testcase;
	int grade=0;
	int signal = setjmp(badkan::longjmp_buffer);
	if (signal == 0) {

        

    /**
     * put tests here,
     * template:
     * testcase.setname()
     * .testname
     * ;
     */


    grade = testcase.grade();
	} else {
		testcase.print_signal(signal);
		grade = 0;
	}
	cout << "Your grade is: "  << grade << endl;
	return 0;
}
