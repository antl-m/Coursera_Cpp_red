//#include "test_runner.h"
//
//#include <ostream>
//using namespace std;
//
//#define PRINT_VALUES(out, x, y) \
//            if(true){           \
//            out << (x) << endl; \
//            out << (y) << endl; \
//            } else

#define f(a, b) a##b
#define g(a) #a
#define h(a) g(a)

int main() {

    f(1,2);
    g(f(1,2));
    h(f(1,2));



//  TestRunner tr;
//  tr.RunTest([] {
//    ostringstream output;
//    PRINT_VALUES(output, 5, "red belt");
//    ASSERT_EQUAL(output.str(), "5\nred belt\n");
//  }, "PRINT_VALUES usage example");
}
