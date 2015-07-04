#include <iostream> // cout, endl
#include <sstream>  // istringtstream, ostringstream
#include <string>   // string
#include <utility>  // pair

#include "gtest/gtest.h"

#include "Integer.h"

using namespace std;

TEST(IntegerFixture, construct_1) {
    Integer i(0);
    ostringstream os;
    os << i;
    ASSERT_EQ("0", os);
}

TEST(IntegerFixture, construct_2) {
    Integer i(238543);
    ostringstream os;
    os << i;
    ASSERT_EQ("238543", os);
}

TEST(IntegerFixture, construct_3) {
    Integer i(-28376);
    ostringstream os;
    os << i;
    ASSERT_EQ("-28376", os);
}

TEST(IntegerFixture, e_construct_1) {
    Integer i("-34");
    ostringstream os;
    os << i;
    ASSERT_EQ("-34", os);
}

TEST(IntegerFixture, e_construct_2) {
    Integer i("0");
    ostringstream os;
    os << i;
    ASSERT_EQ("0", os);
}

TEST(IntegerFixture, e_construct_3) {
    Integer i("238856793473");
    ostringstream os;
    os << i;
    ASSERT_EQ("238856793473", os);
}