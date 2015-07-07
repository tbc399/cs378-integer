#include <iostream> // cout, endl
#include <sstream>  // istringtstream, ostringstream
#include <string>   // string
#include <utility>  // pair

#include "gtest/gtest.h"

#include "Integer.h"

using namespace std;

TEST(IntegerFixture, construct_1) {
    Integer<int> i(0);
    ostringstream os;
    os << i;
    ASSERT_EQ("0", os.str());
}

TEST(IntegerFixture, construct_2) {
    Integer<int> i(238543);
    ostringstream os;
    os << i;
    ASSERT_EQ("238543", os.str());
}

TEST(IntegerFixture, construct_3) {
    Integer<int> i(-28376);
    ostringstream os;
    os << i;
    ASSERT_EQ("-28376", os.str());
}

TEST(IntegerFixture, e_construct_1) {
    Integer<int> i("-34");
    ostringstream os;
    os << i;
    ASSERT_EQ("-34", os.str());
}

TEST(IntegerFixture, e_construct_2) {
    Integer<int> i("0");
    ostringstream os;
    os << i;
    ASSERT_EQ("0", os.str());
}

TEST(IntegerFixture, e_construct_3) {
    Integer<int> i("238856793473");
    ostringstream os;
    os << i;
    ASSERT_EQ("238856793473", os.str());
}

TEST(IntegerFixture, negation_1) {
    Integer<int> i(0);
    Integer<int> j = -i;
    ostringstream os;
    os << j;
    ASSERT_EQ("0", os.str());
}

TEST(IntegerFixture, negation_2) {
    Integer<int> i(-5);
    Integer<int> j = -i;
    ostringstream os;
    os << j;
    ASSERT_EQ("5", os.str());
}

TEST(IntegerFixture, negation_3) {
    Integer<int> i(7);
    Integer<int> j = -i;
    ostringstream os;
    os << j;
    ASSERT_EQ("-7", os.str());
}

TEST(IntegerFixture, equals_1) {
    Integer<int> i(9);
    Integer<int> j("9");
    ASSERT_TRUE(i == j);
}

TEST(IntegerFixture, equals_2) {
    Integer<int> i(-999834);
    Integer<int> j("999834");
    ASSERT_FALSE(i == j);
}

TEST(IntegerFixture, equals_3) {
    Integer<int> i("92837462083247");
    Integer<int> j("92837462083247");
    ASSERT_TRUE(i == j);
}

TEST(IntegerFixture, equals_4) {
    Integer<int> i("92837465083247");
    Integer<int> j("92837462083247");
    ASSERT_FALSE(i == j);
}

TEST(IntegerFixture, plus_equal_1) {
    Integer<int> i(5);
    Integer<int> j(3);
    i += j;
    Integer<int> v(8);
    ASSERT_EQ(v, i);
}

TEST(IntegerFixture, plus_equal_2) {
    Integer<int> i(-45);
    Integer<int> j(10);
    i += j;
    Integer<int> v(-35);
    ASSERT_EQ(v, i);
}

TEST(IntegerFixture, plus_equal_3) {
    Integer<int> i(10);
    Integer<int> j(-45);
    i += j;
    Integer<int> v(-35);
    ASSERT_EQ(v, i);
}

TEST(IntegerFixture, plus_equal_4) {
    Integer<int> i(-5);
    Integer<int> j(-3);
    i += j;
    Integer<int> v(-8);
    ASSERT_EQ(v, i);
}

TEST(IntegerFixture, plus_equal_5) {
    Integer<int> i(-567932);
    Integer<int> j(100298827);
    i += j;
    Integer<int> v(99730895);
    ASSERT_EQ(v, i);
}

TEST(IntegerFixture, plus_equal_6) {
    Integer<int> i(567932);
    Integer<int> j(100298827);
    i += j;
    Integer<int> v(100866759);
    ASSERT_EQ(v, i);
}

TEST(IntegerFixture, minus_equal_1) {
    Integer<int> i(4);
    Integer<int> j(0);
    i -= j;
    Integer<int> v(4);
    ASSERT_EQ(v, i);
}

TEST(IntegerFixture, minus_equal_2) {
    Integer<int> i(0);
    Integer<int> j(4);
    i -= j;
    Integer<int> v(-4);
    ASSERT_EQ(v, i);
}

TEST(IntegerFixture, minus_equal_3) {
    Integer<int> i(0);
    Integer<int> j(0);
    i -= j;
    Integer<int> v(0);
    ASSERT_EQ(v, i);
}

TEST(IntegerFixture, minus_equal_4) {
    Integer<int> i(25);
    Integer<int> j(22);
    i -= j;
    Integer<int> v(3);
    ASSERT_EQ(v, i);
}

TEST(IntegerFixture, minus_equal_5) {
    Integer<int> i(-25);
    Integer<int> j(-23);
    i -= j;
    Integer<int> v(-2);
    ASSERT_EQ(v, i);
}

TEST(IntegerFixture, minus_equal_6) {
    Integer<int> i(1000);
    Integer<int> j(1001);
    i -= j;
    Integer<int> v(-1);
    ASSERT_EQ(v, i);
}

TEST(IntegerFixture, minus_equal_7) {
    Integer<int> i(-5);
    Integer<int> j(5);
    i -= j;
    Integer<int> v(-10);
    ASSERT_EQ(v, i);
}

TEST(IntegerFixture, minus_equal_8) {
    Integer<int> i(5);
    Integer<int> j(-5);
    i -= j;
    Integer<int> v(10);
    ASSERT_EQ(v, i);
}

TEST(IntegerFixture, pre_inc_1) {
    Integer<int> i(0);
    ++i;
    ASSERT_EQ(1, i);
}

TEST(IntegerFixture, pre_inc_2) {
    Integer<int> i(-1);
    ++i;
    ASSERT_EQ(0, i);
}

TEST(IntegerFixture, pre_inc_3) {
    Integer<int> i(-5);
    ++i;
    ASSERT_EQ(-4, i);
}

TEST(IntegerFixture, pre_inc_4) {
    Integer<int> i(-1);
    ++++i;
    ASSERT_EQ(1, i);
}

TEST(IntegerFixture, post_inc_1) {
    Integer<int> i(0);
    Integer<int> j = i++;
    ASSERT_EQ(1, i);
    ASSERT_EQ(0, j);
}

TEST(IntegerFixture, post_inc_2) {
    Integer<int> i(-1);
    Integer<int> j = i++;
    ASSERT_EQ(0, i);
    ASSERT_EQ(-1, j);
}

TEST(IntegerFixture, post_inc_3) {
    Integer<int> i(-5);
    Integer<int> j = i++;
    ASSERT_EQ(-4, i);
    ASSERT_EQ(-5, j);
}

TEST(IntegerFixture, pre_dec_1) {
    Integer<int> i(0);
    --i;
    ASSERT_EQ(-1, i);
}

TEST(IntegerFixture, pre_dec_2) {
    Integer<int> i(-1);
    --i;
    ASSERT_EQ(-2, i);
}

TEST(IntegerFixture, pre_dec_3) {
    Integer<int> i(-5);
    --i;
    ASSERT_EQ(-6, i);
}

TEST(IntegerFixture, pre_dec_4) {
    Integer<int> i(1);
    ----i;
    ASSERT_EQ(-1, i);
}

TEST(IntegerFixture, post_dec_1) {
    Integer<int> i(0);
    Integer<int> j = i--;
    ASSERT_EQ(-1, i);
    ASSERT_EQ(0, j);
}

TEST(IntegerFixture, post_dec_2) {
    Integer<int> i(-1);
    Integer<int> j = i--;
    ASSERT_EQ(-2, i);
    ASSERT_EQ(-1, j);
}

TEST(IntegerFixture, post_dec_3) {
    Integer<int> i(-5);
    Integer<int> j = i--;
    ASSERT_EQ(-6, i);
    ASSERT_EQ(-5, j);
}

TEST(IntegerFixture, multiply_eq_1) {
    Integer<int> i(0);
    Integer<int> j(9);
    i *= j;
    ASSERT_EQ(0, i);
}

TEST(IntegerFixture, multiply_eq_2) {
    Integer<int> i(0);
    Integer<int> j(-9);
    i *= j;
    ASSERT_EQ(0, i);
}

TEST(IntegerFixture, multiply_eq_3) {
    Integer<int> i(0);
    Integer<int> j(0);
    i *= j;
    ASSERT_EQ(0, i);
}

TEST(IntegerFixture, multiply_eq_4) {
    Integer<int> i(5);
    Integer<int> j(5);
    i *= j;
    ASSERT_EQ(25, i);
}

TEST(IntegerFixture, multiply_eq_5) {
    Integer<int> i(-5);
    Integer<int> j(5);
    i *= j;
    ASSERT_EQ(-25, i);
}

TEST(IntegerFixture, multiply_eq_6) {
    Integer<int> i(5);
    Integer<int> j(-5);
    i *= j;
    ASSERT_EQ(-25, i);
}

TEST(IntegerFixture, multiply_eq_7) {
    Integer<int> i(-5);
    Integer<int> j(-5);
    i *= j;
    ASSERT_EQ(25, i);
}

TEST(IntegerFixture, multiply_eq_8) {
    Integer<int> i(100);
    Integer<int> j(900);
    i *= j;
    ASSERT_EQ(90000, i);
}

TEST(IntegerFixture, multiply_eq_9) {
    Integer<int> i(123456789);
    Integer<int> j(987654321);
    i *= j;
    ASSERT_EQ(Integer<int>("121932631112635269"), i);
}