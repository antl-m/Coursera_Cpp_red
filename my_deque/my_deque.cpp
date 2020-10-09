#include "my_deque.h"
#include <vector>

#define BOOST_TEST_MAIN
#include "boost/test/unit_test.hpp"

BOOST_AUTO_TEST_SUITE(MyDequeTest);

    BOOST_AUTO_TEST_CASE(At_exception_test){
        std::vector v(5, "sss");
        Deque<int> d;
        BOOST_CHECK_THROW(d.At(1), std::out_of_range);
        BOOST_CHECK_THROW(d.At(0), std::out_of_range);
        BOOST_CHECK_THROW(d.At(-1), std::out_of_range);
        d.PushBack(5);
        BOOST_CHECK_THROW(d.At(1), std::out_of_range);
        BOOST_CHECK_EQUAL(d.At(0), 5);
        BOOST_CHECK_THROW(d.At(-1), std::out_of_range);
    }

BOOST_AUTO_TEST_SUITE_END();