#include <iostream> // cout, endl
#include <sstream>  // istringtstream, ostringstream
#include <string>   // string
#include <utility>  // pair
#include <iterator>
#include <deque>

#include "gtest/gtest.h"

#include "Integer.h"

typedef vector<int>::iterator VI;

using namespace std;

// ----------
// Integer(int v)
// ----------

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

// ----------
// explicit Integer(const string& v)
// ----------

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

// ----------
// -
// ----------

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

// ----------
// +=
// ----------

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

// ----------
// -=
// ----------

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

TEST(IntegerFixture, minus_equal_9) {
    Integer<int> i(-56);
    Integer<int> j(-5);
    i -= j;
    Integer<int> v(-51);
    ASSERT_EQ(v, i);
}
    
// ----------
// ++
// ----------

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

// ----------
// ++(int)
// ----------

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

// ----------
// --
// ----------

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

// ----------
// --(int)
// ----------

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

// ----------
// *=
// ----------

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
    Integer<int> i(12345);
    Integer<int> j(6789);
    i *= j;
    ASSERT_EQ(83810205, i);
}

TEST(IntegerFixture, multiply_eq_9) {
    Integer<int> i(123456789);
    Integer<int> j(987654321);
    i *= j;
    ASSERT_EQ(Integer<int>("121932631112635269"), i);
}

TEST(IntegerFixture, multiply_eq_10) {
    Integer<int> i(900);
    Integer<int> j(100);
    i *= j;
    ASSERT_EQ(90000, i);
}

// ----------
// /=
// ----------

TEST(IntegerFixture, divide_eq_1) {
    Integer<int> i(0);
    Integer<int> j(1);
    i /= j;
    ASSERT_EQ(0, i);
}

TEST(IntegerFixture, divide_eq_2) {
    Integer<int> i(0);
    Integer<int> j(-1);
    i /= j;
    ASSERT_EQ(0, i);
}

TEST(IntegerFixture, divide_eq_3) {
    Integer<int> i(5);
    Integer<int> j(5);
    i /= j;
    ASSERT_EQ(1, i);
}

TEST(IntegerFixture, divide_eq_4) {
    Integer<int> i(10);
    Integer<int> j(5);
    i /= j;
    ASSERT_EQ(2, i);
}

TEST(IntegerFixture, divide_eq_5) {
    Integer<int> i(10);
    Integer<int> j(-5);
    i /= j;
    ASSERT_EQ(-2, i);
}

TEST(IntegerFixture, divide_eq_6) {
    Integer<int> i(-10);
    Integer<int> j(5);
    i /= j;
    ASSERT_EQ(-2, i);
}

TEST(IntegerFixture, divide_eq_7) {
    Integer<int> i(-10);
    Integer<int> j(-5);
    i /= j;
    ASSERT_EQ(2, i);
}

TEST(IntegerFixture, divide_eq_8) {
    Integer<int> i(12);
    Integer<int> j(-5);
    i /= j;
    ASSERT_EQ(-2, i);
}

TEST(IntegerFixture, divide_eq_9) {
    Integer<int> i(1);
    Integer<int> j(-5);
    i /= j;
    ASSERT_EQ(0, i);
}

TEST(IntegerFixture, divide_eq_10) {
    Integer<int> i(533492);
    Integer<int> j(9923);
    i /= j;
    ASSERT_EQ(53, i);
}

// ----------
// %=
// ----------

TEST(IntegerFixture, mod_eq_1) {
    Integer<int> i(-10);
    Integer<int> j(5);
    i %= j;
    ASSERT_EQ(0, i);
}

TEST(IntegerFixture, mod_eq_2) {
    Integer<int> i(22);
    Integer<int> j(5);
    i %= j;
    ASSERT_EQ(2, i);
}

TEST(IntegerFixture, mod_eq_3) {
    Integer<int> i(-12);
    Integer<int> j(5);
    i %= j;
    ASSERT_EQ(-2, i);
}

TEST(IntegerFixture, mod_eq_4) {
    Integer<int> i(-17);
    Integer<int> j(5);
    i %= j;
    ASSERT_EQ(-2, i);
}

TEST(IntegerFixture, mod_eq_5) {
    Integer<int> i(87573);
    Integer<int> j(9934);
    i %= j;
    ASSERT_EQ(8101, i);
}

TEST(IntegerFixture, mod_eq_6) {
    Integer<int> i(3);
    Integer<int> j(5);
    i %= j;
    ASSERT_EQ(3, i);
}

// ----------
// <<=
// ----------

TEST(IntegerFixture, shift_left_eq_1) {
    Integer<int> i(17);
    i <<= 4;
    ASSERT_EQ(272, i);
}

TEST(IntegerFixture, shift_left_eq_2) {
    Integer<int> i(1);
    i <<= 5;
    ASSERT_EQ(32, i);
}

TEST(IntegerFixture, shift_left_eq_3) {
    Integer<int> i(-32);
    i <<= 4;
    ASSERT_EQ(-512, i);
}

TEST(IntegerFixture, shift_left_eq_4) {
    Integer<int> i(-17);
    i <<= 4;
    ASSERT_EQ(-272, i);
}

// ----------
// >>=
// ----------

TEST(IntegerFixture, shift_right_eq_1) {
    Integer<int> i(17);
    i >>= 4;
    ASSERT_EQ(1, i);
}

TEST(IntegerFixture, shift_right_eq_2) {
    Integer<int> i(25);
    i >>= 5;
    ASSERT_EQ(0, i);
}

TEST(IntegerFixture, shift_right_eq_3) {
    Integer<int> i(-32);
    i >>= 4;
    ASSERT_EQ(-2, i);
}

TEST(IntegerFixture, shift_right_eq_4) {
    Integer<int> i(5000);
    i >>= 4;
    ASSERT_EQ(312, i);
}

// ----------
// abs
// ----------

TEST(IntegerFixture, abs_1) {
    Integer<int> i(0);
    i.abs();
    ASSERT_EQ(0, i);
}

TEST(IntegerFixture, abs_2) {
    Integer<int> i(-4);
    i.abs();
    ASSERT_EQ(4, i);
}

TEST(IntegerFixture, abs_3) {
    Integer<int> i(4);
    i.abs();
    ASSERT_EQ(4, i);
}

// ----------
// pow
// ----------

TEST(IntegerFixture, pow_1) {
    Integer<int> i(0);
    i.pow(4);
    ASSERT_EQ(0, i);
}

TEST(IntegerFixture, pow_2) {
    Integer<int> i(1);
    i.pow(4);
    ASSERT_EQ(1, i);
}

TEST(IntegerFixture, pow_3) {
    Integer<int> i(3);
    i.pow(4);
    ASSERT_EQ(81, i);
}

TEST(IntegerFixture, pow_4) {
    Integer<int> i(-3);
    i.pow(4);
    ASSERT_EQ(81, i);
}

TEST(IntegerFixture, pow_5) {
    Integer<int> i(-3);
    i.pow(3);
    ASSERT_EQ(-27, i);
}

TEST(IntegerFixture, pow_6) {
    Integer<int> i(2);
    i.pow(30);
    ASSERT_EQ(1073741824, i);
}

TEST(IntegerFixture, pow_7) {
    Integer<int> i(10);
    i.pow(8);
    ASSERT_EQ(100000000, i);
}

// ----------
// friend ==
// ----------

TEST(IntegerFixture, f_equals_1) {
    Integer<int> i(9);
    Integer<int> j("9");
    ASSERT_TRUE(i == j);
}

TEST(IntegerFixture, f_equals_2) {
    Integer<int> i(-999834);
    Integer<int> j("999834");
    ASSERT_FALSE(i == j);
}

TEST(IntegerFixture, f_equals_3) {
    Integer<int> i("92837462083247");
    Integer<int> j("92837462083247");
    ASSERT_TRUE(i == j);
}

TEST(IntegerFixture, f_equals_4) {
    Integer<int> i("92837465083247");
    Integer<int> j("92837462083247");
    ASSERT_FALSE(i == j);
}

// ----------
// friend !=
// ----------

TEST(IntegerFixture, f_not_equals_1) {
    Integer<int> i(8);
    Integer<int> j("9");
    ASSERT_TRUE(i != j);
}

TEST(IntegerFixture, f_not_equals_2) {
    Integer<int> i(-999834);
    Integer<int> j("999834");
    ASSERT_TRUE(i != j);
}

TEST(IntegerFixture, f_not_equals_3) {
    Integer<int> i("92837462083247");
    Integer<int> j("92837462083247");
    ASSERT_FALSE(i != j);
}

TEST(IntegerFixture, f_not_equals_4) {
    Integer<int> i("92837465083247");
    Integer<int> j("92837462083247");
    ASSERT_TRUE(i != j);
}

// ----------
// friend <
// ----------

TEST(IntegerFixture, f_less_than_1) {
    Integer<int> i(8);
    Integer<int> j("9");
    ASSERT_TRUE(i < j);
}

TEST(IntegerFixture, f_less_than_2) {
    Integer<int> i(-999834);
    Integer<int> j("999834");
    ASSERT_TRUE(i < j);
}

TEST(IntegerFixture, f_less_than_3) {
    Integer<int> i("92837452083247");
    Integer<int> j("92837462083247");
    ASSERT_TRUE(i < j);
}

// ----------
// friend <=
// ----------

TEST(IntegerFixture, f_less_than_eq_1) {
    Integer<int> i(0);
    Integer<int> j("9");
    ASSERT_TRUE(i <= j);
}

TEST(IntegerFixture, f_less_than_eq_2) {
    Integer<int> i(999834);
    Integer<int> j("999834");
    ASSERT_TRUE(i <= j);
}

TEST(IntegerFixture, f_less_than_eq_3) {
    Integer<int> i("92837452083247");
    Integer<int> j("92837462083247");
    ASSERT_TRUE(i <= j);
}

// ----------
// friend >
// ----------

TEST(IntegerFixture, f_greater_than_1) {
    Integer<int> i(9);
    Integer<int> j("8");
    ASSERT_TRUE(i > j);
}

TEST(IntegerFixture, f_greater_than_2) {
    Integer<int> i(-999834);
    Integer<int> j("999834");
    ASSERT_TRUE(j > i);
}

TEST(IntegerFixture, f_greater_than_3) {
    Integer<int> i("92837452083247");
    Integer<int> j("92837462083247");
    ASSERT_TRUE(j > i);
}

// ----------
// friend >=
// ----------

TEST(IntegerFixture, f_greater_than_eq_1) {
    Integer<int> i(8);
    Integer<int> j("8");
    ASSERT_TRUE(i >= j);
}

TEST(IntegerFixture, f_greater_than_eq_2) {
    Integer<int> i(-999834);
    Integer<int> j("999834");
    ASSERT_TRUE(j >= i);
}

TEST(IntegerFixture, f_greater_than_eq_3) {
    Integer<int> i("92837452083247");
    Integer<int> j("92837462083247");
    ASSERT_TRUE(j >= i);
}

// ----------
// friend +
// ----------

TEST(IntegerFixture, f_plus_1) {
    Integer<int> i(5);
    Integer<int> j(3);
    Integer<int> v(8);
    ASSERT_EQ(v, i + j);
}

TEST(IntegerFixture, f_plus_2) {
    Integer<int> i(-45);
    Integer<int> j(10);
    Integer<int> v(-35);
    ASSERT_EQ(v, i + j);
}

TEST(IntegerFixture, f_plus_3) {
    Integer<int> i(10);
    Integer<int> j(-45);
    Integer<int> v(-35);
    ASSERT_EQ(v, i + j);
}

TEST(IntegerFixture, f_plus_4) {
    Integer<int> i(-5);
    Integer<int> j(-3);
    Integer<int> v(-8);
    ASSERT_EQ(v, i + j);
}

TEST(IntegerFixture, f_plus_5) {
    Integer<int> i(-567932);
    Integer<int> j(100298827);
    Integer<int> v(99730895);
    ASSERT_EQ(v, i + j);
}

TEST(IntegerFixture, f_plus_6) {
    Integer<int> i(567932);
    Integer<int> j(100298827);
    Integer<int> v(100866759);
    ASSERT_EQ(v, i + j);
}

// ----------
// friend -
// ----------

TEST(IntegerFixture, f_minus_1) {
    Integer<int> i(4);
    Integer<int> j(0);
    Integer<int> v(4);
    ASSERT_EQ(v, i - j);
}

TEST(IntegerFixture, f_minus_2) {
    Integer<int> i(0);
    Integer<int> j(4);
    Integer<int> v(-4);
    ASSERT_EQ(v, i - j);
}

TEST(IntegerFixture, f_minus_3) {
    Integer<int> i(0);
    Integer<int> j(0);
    Integer<int> v(0);
    ASSERT_EQ(v, i - j);
}

TEST(IntegerFixture, f_minus_4) {
    Integer<int> i(25);
    Integer<int> j(22);
    Integer<int> v(3);
    ASSERT_EQ(v, i - j);
}

TEST(IntegerFixture, f_minus_5) {
    Integer<int> i(-25);
    Integer<int> j(-23);
    Integer<int> v(-2);
    ASSERT_EQ(v, i - j);
}

TEST(IntegerFixture, f_minus_6) {
    Integer<int> i(1000);
    Integer<int> j(1001);
    Integer<int> v(-1);
    ASSERT_EQ(v, i - j);
}

TEST(IntegerFixture, f_minus_7) {
    Integer<int> i(-5);
    Integer<int> j(5);
    Integer<int> v(-10);
    ASSERT_EQ(v, i - j);
}

TEST(IntegerFixture, f_minus_8) {
    Integer<int> i(5);
    Integer<int> j(-5);
    Integer<int> v(10);
    ASSERT_EQ(v, i - j);
}

TEST(IntegerFixture, f_minus_9) {
    Integer<int> i(-56);
    Integer<int> j(-5);
    Integer<int> v(-51);
    ASSERT_EQ(v, i - j);
}

// ----------
// friend *
// ----------

TEST(IntegerFixture, f_multiply_1) {
    Integer<int> i(0);
    Integer<int> j(9);
    ASSERT_EQ(0, i * j);
}

TEST(IntegerFixture, f_multiply_2) {
    Integer<int> i(0);
    Integer<int> j(-9);
    ASSERT_EQ(0, i * j);
}

TEST(IntegerFixture, f_multiply_3) {
    Integer<int> i(0);
    Integer<int> j(0);
    ASSERT_EQ(0, i * j);
}

TEST(IntegerFixture, f_multiply_4) {
    Integer<int> i(5);
    Integer<int> j(5);
    ASSERT_EQ(25, i * j);
}

TEST(IntegerFixture, f_multiply_5) {
    Integer<int> i(-5);
    Integer<int> j(5);
    ASSERT_EQ(-25, i * j);
}

TEST(IntegerFixture, f_multiply_6) {
    Integer<int> i(5);
    Integer<int> j(-5);
    ASSERT_EQ(-25, i * j);
}

TEST(IntegerFixture, f_multiply_7) {
    Integer<int> i(-5);
    Integer<int> j(-5);
    ASSERT_EQ(25, i * j);
}

TEST(IntegerFixture, f_multiply_8) {
    Integer<int> i(100);
    Integer<int> j(900);
    ASSERT_EQ(90000, i * j);
}

TEST(IntegerFixture, f_multiply_9) {
    Integer<int> i(123456789);
    Integer<int> j(987654321);
    ASSERT_EQ(Integer<int>("121932631112635269"), i * j);
}

// ----------
// friend /
// ----------

TEST(IntegerFixture, f_divide_1) {
    Integer<int> i(0);
    Integer<int> j(1);
    ASSERT_EQ(0, i / j);
}

TEST(IntegerFixture, f_divide_2) {
    Integer<int> i(0);
    Integer<int> j(-1);
    ASSERT_EQ(0, i / j);
}

TEST(IntegerFixture, f_divide_3) {
    Integer<int> i(5);
    Integer<int> j(5);
    ASSERT_EQ(1, i / j);
}

TEST(IntegerFixture, f_divide_4) {
    Integer<int> i(10);
    Integer<int> j(5);
    ASSERT_EQ(2, i / j);
}

TEST(IntegerFixture, f_divide_5) {
    Integer<int> i(10);
    Integer<int> j(-5);
    ASSERT_EQ(-2, i / j);
}

TEST(IntegerFixture, f_divide_6) {
    Integer<int> i(-10);
    Integer<int> j(5);
    ASSERT_EQ(-2, i / j);
}

TEST(IntegerFixture, f_divide_7) {
    Integer<int> i(-10);
    Integer<int> j(-5);
    ASSERT_EQ(2, i / j);
}

TEST(IntegerFixture, f_divide_8) {
    Integer<int> i(12);
    Integer<int> j(-5);
    ASSERT_EQ(-2, i / j);
}

TEST(IntegerFixture, f_divide_9) {
    Integer<int> i(1);
    Integer<int> j(-5);
    ASSERT_EQ(0, i / j);
}

TEST(IntegerFixture, f_divide_10) {
    Integer<int> i(533492);
    Integer<int> j(9923);
    ASSERT_EQ(53, i / j);
}

// ----------
// friend %
// ----------

TEST(IntegerFixture, f_mod_1) {
    Integer<int> i(-10);
    Integer<int> j(5);
    ASSERT_EQ(0, i % j);
}

TEST(IntegerFixture, f_mod_2) {
    Integer<int> i(22);
    Integer<int> j(5);
    ASSERT_EQ(2, i % j);
}

TEST(IntegerFixture, f_mod_3) {
    Integer<int> i(-12);
    Integer<int> j(5);
    ASSERT_EQ(-2, i % j);
}

TEST(IntegerFixture, f_mod_4) {
    Integer<int> i(-17);
    Integer<int> j(5);
    ASSERT_EQ(-2, i % j);
}

TEST(IntegerFixture, f_mod_5) {
    Integer<int> i(87573);
    Integer<int> j(9934);
    ASSERT_EQ(8101, i % j);
}

TEST(IntegerFixture, f_mod_6) {
    Integer<int> i(3);
    Integer<int> j(5);
    ASSERT_EQ(3, i % j);
}

// ----------
// friend <<
// ----------

TEST(IntegerFixture, f_shift_left_1) {
    Integer<int> i(17);
    ASSERT_EQ(272, i << 4);
}

TEST(IntegerFixture, f_shift_left_2) {
    Integer<int> i(1);
    ASSERT_EQ(32, i << 5);
}

TEST(IntegerFixture, f_shift_left_3) {
    Integer<int> i(-32);
    ASSERT_EQ(-512, i << 4);
}

TEST(IntegerFixture, f_shift_left_4) {
    Integer<int> i(-17);
    ASSERT_EQ(-272, i << 4);
}

// ----------
// friend >>
// ----------

TEST(IntegerFixture, f_shift_right_1) {
    Integer<int> i(17);
    ASSERT_EQ(1, i >> 4);
}

TEST(IntegerFixture, f_shift_right_2) {
    Integer<int> i(25);
    ASSERT_EQ(0, i >> 5);
}

TEST(IntegerFixture, f_shift_right_3) {
    Integer<int> i(-32);
    ASSERT_EQ(-2, i >> 4);
}

TEST(IntegerFixture, f_shift_right_4) {
    Integer<int> i(5000);
    ASSERT_EQ(312, i >> 4);
}

// ----------
// friend << (ostream)
// ----------

TEST(IntegerFixture, ostream_1) {
    Integer<int> i(17);
    ostringstream os;
    os << i;
    ASSERT_EQ("17", os.str());
}

TEST(IntegerFixture, ostream_2) {
    Integer<int> i(-893);
    ostringstream os;
    os << i;
    ASSERT_EQ("-893", os.str());
}

TEST(IntegerFixture, ostream_3) {
    Integer<int> i("-8237592358989034562378562376548236589235664235543");
    ostringstream os;
    os << i;
    ASSERT_EQ("-8237592358989034562378562376548236589235664235543", os.str());
}

// ----------
// friend abs
// ----------

TEST(IntegerFixture, f_abs_1) {
    Integer<int> i(0);
    ASSERT_EQ(0, abs(i));
}

TEST(IntegerFixture, f_abs_2) {
    Integer<int> i(-4);
    ASSERT_EQ(4, abs(i));
}

TEST(IntegerFixture, f_abs_3) {
    Integer<int> i(4);
    ASSERT_EQ(4, abs(i));
}

// ----------
// friend pow
// ----------

TEST(IntegerFixture, f_pow_1) {
    Integer<int> i(0);
    ASSERT_EQ(0, pow(i, 4));
}

TEST(IntegerFixture, f_pow_2) {
    Integer<int> i(1);
    ASSERT_EQ(1, pow(i, 4));
}

TEST(IntegerFixture, f_pow_3) {
    Integer<int> i(3);
    ASSERT_EQ(81,  pow(i, 4));
}

TEST(IntegerFixture, f_pow_4) {
    Integer<int> i(-3);
    ASSERT_EQ(81,  pow(i, 4));
}

TEST(IntegerFixture, f_pow_5) {
    Integer<int> i(-3);
    ASSERT_EQ(-27, pow(i, 3));
}

// ----------
// shift_left_digits
// ----------

TEST(IntegerFixture, shift_left_digits_1) {
    vector<int> v{3, 2};
    vector<int> r(3);
    shift_left_digits<VI,VI>(v.begin(), v.end(), 4, r.begin());
    vector<int> x{5, 1, 2};
    ASSERT_TRUE(equal(r.begin(), r.end(), x.begin()));
}

// ----------
// shift_right_digits
// ----------

TEST(IntegerFixture, shift_right_digits_1) {
    vector<int> v{5, 0, 0, 0};
    vector<int> r(3);
    shift_right_digits<VI,VI>(v.begin(), v.end(), 4, r.begin());
    vector<int> x{3, 1, 2};
    ASSERT_TRUE(equal(r.begin(), r.end(), x.begin()));
}

// ----------
// plus_digits
// ----------

TEST(IntegerFixture, plus_digits_1) {
    vector<int> a{1,9,3,7,8,7,4,9,2,6,7,4,8,9,5,7,2,9};
    vector<int> b{7,7,3,6,2,8,9,6,6,5,8,9,2,6,4,8,1,4,4,3};
    vector<int> r(20);
    plus_digits<VI,VI>(a.begin(), a.end(), b.begin(), b.end(), r.begin());
    vector<int> x{7,7,5,5,6,6,8,4,1,5,1,6,0,1,3,7,7,1,7,2};
    ASSERT_TRUE(equal(r.begin(), r.end(), x.begin()));
}

// ----------
// minus_digits
// ----------

TEST(IntegerFixture, minus_digits_1) {
    vector<int> a{7,7,3,6,2,8,9,6,6,5,8,9,2,6,4,8,1,4,4,3};
    vector<int> b{1,9,3,7,8,7,4,9,2,6,7,4,8,9,5,7,2,9};
    vector<int> r(20);
    minus_digits<VI,VI>(a.begin(), a.end(), b.begin(), b.end(), r.begin());
    vector<int> x{7,7,1,6,9,1,0,9,1,6,6,2,5,1,5,8,5,7,1,4};
    ASSERT_TRUE(equal(r.begin(), r.end(), x.begin()));
}

// ----------
// multiply_digits
// ----------

TEST(IntegerFixture, multiply_digits_1) {
    vector<int> a{7,7,3,6,2,8,9,4,4,3};
    vector<int> b{1,9,4,8,9,5,7,2,9};
    vector<int> r(19);
    multiplies_digits<VI,VI>(a.begin(), a.end(), b.begin(), b.end(), r.begin());
    vector<int> x{1,5,0,7,7,6,9,7,7,0,7,4,8,4,8,8,9,4,7};
    ASSERT_TRUE(equal(r.begin(), r.end(), x.begin()));
}

// ----------
// divide_digits
// ----------

TEST(IntegerFixture, divide_digits_1) {
    vector<int> a{7,7,3,6,2,8,9,4,4,3};
    vector<int> b{9,4,8,9,5,7,2,9,9};
    vector<int> r(1);
    divides_digits<VI,VI>(a.begin(), a.end(), b.begin(), b.end(), r.begin());
    vector<int> x{8};
    ASSERT_TRUE(equal(r.begin(), r.end(), x.begin()));
}

TEST(IntegerFixture, mersenne_20_vector_timing) {
    Integer<int> n = Integer<int>(2).pow(4423) - 1;
    //Integer<int>(2).pow(4423) - 1;
    ASSERT_TRUE(true);
}

TEST(IntegerFixture, mersenne_20_deque_timing) {
    Integer<int, deque<int>> n = Integer<int, deque<int>>(2).pow(4423) - 1;
    //Integer<int, deque<int>>(2).pow(4423) - 1;
    ASSERT_TRUE(true);
}
/*
TEST(IntegerFixture, mersenne_30_vector_timing) {
	Integer<int> n = Integer<int>(2).pow(132049) - 1;
	ASSERT_TRUE(true);
}
*/