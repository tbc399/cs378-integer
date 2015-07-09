// ------------------------------
// projects/c++/integer/Integer.h
// Copyright (C) 2015
// Glenn P. Downing
// ------------------------------

#ifndef Integer_h
#define Integer_h

// --------
// includes
// --------

#include <cassert>   // assert
#include <iostream>  // ostream
#include <sstream>
#include <stdexcept> // invalid_argument
#include <string>    // string
#include <vector>    // vector
#include <algorithm>
#include <cstdlib>
#include <iterator>

using namespace std;

// -------
// Integer
// -------

template < typename T, typename C = vector<T> >
class Integer {
    // -----------
    // operator ==
    // -----------

    /**
     * Check to see if two Integers have the same sign and content
     * @param lhs the left hand side of the predicate
     * @param rhs the right hand side of the predicate
     * @return true if the Integers are the same
     */
    friend bool operator == (const Integer& lhs, const Integer& rhs) {
        // <your code>
        if ((!lhs.positive && rhs.positive) || (lhs.positive && !rhs.positive))
            return false;
        else if (lhs._x.size() != rhs._x.size())
            return false;
        else {
            return equal(lhs._x.begin(), lhs._x.end(), rhs._x.begin());
        }
    }

    // -----------
    // operator !=
    // -----------

    /**
     * Check to see if two Integers are not equal
     * @param lhs the left hand side of the predicate
     * @param rhs the right hand side of the predicate
     * @return true if the Integers are NOT the same
     */
    friend bool operator != (const Integer& lhs, const Integer& rhs) {
        return !(lhs == rhs);}

    // ----------
    // operator <
    // ----------

    /**
     * Check to see if one Integer is less than another
     * @param lhs the left hand side of the predicate
     * @param rhs the right hand side of the predicate
     * @return true if lhs is less than rhs
     */
    friend bool operator < (const Integer& lhs, const Integer& rhs) {
        // <your code>
        if (!lhs.positive && rhs.positive)
            return true;
        else if (lhs.positive && !rhs.positive)
            return false;
        else if (!lhs.positive && (lhs._x.size() > rhs._x.size()))
            return true;
        else if (!lhs.positive && (lhs._x.size() < rhs._x.size()))
            return false;
        else if (lhs.positive && (lhs._x.size() > rhs._x.size()))
            return false;
        else if (lhs.positive && (lhs._x.size() < rhs._x.size()))
            return true;
        else {
            typename C::const_iterator lb = lhs._x.begin();
            typename C::const_iterator le = lhs._x.end();
            typename C::const_iterator rb = rhs._x.begin();
            while (lb < le) {
                if (*lb < *rb)
                    return true;
                if (*lb > *rb)
                    return false;
                ++lb;
                ++rb;
            }
            return false;
        }
        
    }

    // -----------
    // operator <=
    // -----------

    /**
     * Check to see if one Integer is less than or equal to another
     * @param lhs the left hand side of the predicate
     * @param rhs the right hand side of the predicate
     * @return true if lhs is less than OR is equal to rhs
     */
    friend bool operator <= (const Integer& lhs, const Integer& rhs) {
        return !(rhs < lhs);}

    // ----------
    // operator >
    // ----------

    /**
     * Check to see if one Integer is greater than another
     * @param lhs the left hand side of the predicate
     * @param rhs the right hand side of the predicate
     * @return true if rhs is greater than lhs
     */
    friend bool operator > (const Integer& lhs, const Integer& rhs) {
        return (rhs < lhs);}

    // -----------
    // operator >=
    // -----------

    /**
     * Check to see if one Integer is greater than or equal to another
     * @param lhs the left hand side of the predicate
     * @param rhs the right hand side of the predicate
     * @return true if rhs is greater than OR is equal to lhs
     */
    friend bool operator >= (const Integer& lhs, const Integer& rhs) {
        return !(lhs < rhs);}

    // ----------
    // operator +
    // ----------

    /**
     * Adds two Integers together
     * @param lhs the left hand side of the addition
     * @param rhs the right had side of the addition
     * @return an Integer representing the sum of lhs and rhs
     */
    friend Integer operator + (Integer lhs, const Integer& rhs) {
        return lhs += rhs;}

    // ----------
    // operator -
    // ----------

    /**
     * Subtracts an Integer from another Integer
     * @param lhs the left hand side of the subtraction
     * @param rhs the right hand side of the subtraction
     * @return an Integer representing the difference of lhs and rhs
     */
    friend Integer operator - (Integer lhs, const Integer& rhs) {
        return lhs -= rhs;}

    // ----------
    // operator *
    // ----------

    /**
     * Multiplies an Integer by another Integer
     * @param lhs the left hand side of the multiplication
     * @param rhs the right hand side of the multiplication
     * @return an Integer representing the product of lhs and rhs
     */
    friend Integer operator * (Integer lhs, const Integer& rhs) {
        return lhs *= rhs;}

    // ----------
    // operator /
    // ----------

    /**
     * Divides an Integer by another Integer
     * @param lhs the dividend
     * @param rhs the divisor
     * @return an Integer representing the quotient of lhs / rhs
     * @throws invalid_argument if (rhs == 0)
     */
    friend Integer operator / (Integer lhs, const Integer& rhs) {
        return lhs /= rhs;}

    // ----------
    // operator %
    // ----------

    /**
     * Performs the modulus operation on two Integers
     * @param lhs the left hand side of the operation
     * @param rhs the right hand side of the operation
     * @return an Integer representing the result of lhs modulo rhs
     *  which is effectively the remainder of lhs / rhs
     * @throws invalid_argument if (rhs <= 0)
     */
    friend Integer operator % (Integer lhs, const Integer& rhs) {
        return lhs %= rhs;}

    // -----------
    // operator <<
    // -----------

    /**
     * Shift an Integer to the left
     * @param lhs the Integer to be shifted
     * @param rhs the number of bits to left shift lhs
     * @return an Integer representing lhs shifted left by rhs bits
     * @throws invalid_argument if (rhs < 0)
     */
    friend Integer operator << (Integer lhs, int rhs) {
        return lhs <<= rhs;}

    // -----------
    // operator >>
    // -----------

    /**
     * Shift an Integer to the right
     * @param lhs the Integer to be shifted
     * @param rhs the number of bits to right shift lhs
     * @return an Integer representing lhs shifted right by rhs bits
     * @throws invalid_argument if (rhs < 0)
     */
    friend Integer operator >> (Integer lhs, int rhs) {
        return lhs >>= rhs;}

    // -----------
    // operator <<
    // -----------

    /**
     * Write out an Integer to an ostream object
     * @param lhs the ostream to write out to
     * @param rhs the Integer to write out
     * @return the ostream object pasted in through lhs
     */
    friend ostream& operator << (ostream& lhs, const Integer& rhs) {
        // <your code>
        string s;
        if (!rhs.positive)
            s += "-";
        for (const T& t : rhs._x) {
            s += to_string(t);
        }
        return lhs << s;
    }

    // ---
    // abs
    // ---

    /**
     * Absolute value
     * @param x an Integer
     * @return the absolute value of the Integer x
     */
    friend Integer abs (Integer x) {
        return x.abs();}

    // ---
    // pow
    // ---

    /**
     * Power
     * @param x an Integer
     * @param e an int
     * @return an Integer representing x raised to e
     * @throws invalid_argument if ((x == 0) && (e == 0)) || (e < 0)
     */
    friend Integer pow (Integer x, int e) {
        return x.pow(e);}

    private:
        // ----
        // data
        // ----

        C _x; // the backing container
        
        // <your data>
        bool positive;

    private:
        // -----
        // valid
        // -----

        bool valid () const { // class invariant
            
            // <your code>
            if (_x.size() == 1 && _x[0] == 0 && !positive)
                return false;
            if (_x.size() > 1 && _x[0] == 0)
                return false;
            
            for (const T& t : _x) {
                if (t < 0 || t > 9)
                    return false;
            }
            
            return true;
        
        }
        
        /**
         * A helper function to *= that implements simple addition
         * @param lhs the left hand side of the sum
         * @param rhs the right hand side of the sum
         * @return the sum of lhs and rhs stored in lhs
         */
        Integer& basic_plus_eq(Integer& lhs, const Integer& rhs) {
            C rev_sum;
            bool carry = false;
            int sum;
            typename C::iterator lb = lhs._x.begin();
            typename C::const_iterator rb = rhs._x.begin();
            typename C::iterator le = --lhs._x.end(); // -- to point at the last element
            typename C::const_iterator re = --rhs._x.end();
            
            while (le >= lb || re >= rb) {
                
                sum = 0;
                if (le >= lb) {
                    sum += *le;
                    --le;
                }
                
                if (re >= rb) {
                    sum += *re;
                    --re;
                }
                
                if (carry) {
                    sum += 1;
                    carry = false;
                }
                
                if (sum > 9) {
                    rev_sum.push_back(sum - 10);
                    carry = true;
                } else {
                    rev_sum.push_back(sum);
                }
            }
            
            if (carry)
                rev_sum.push_back(1);
            
            lhs._x.resize(rev_sum.size());
                
            reverse_copy(rev_sum.begin(), rev_sum.end(), lhs._x.begin());
            
            return lhs;
        }
        
        /**
         * A helper function to -= that implements simple subtraction
         * @param lhs the left hand side of the subtraction
         * @param rhs the right hand side of the subtraction
         * @return the difference of lhs and rhs stored in lhs
         */
        Integer& basic_minus_eq (Integer& lhs, const Integer& rhs) {
            C rev_diff;
            bool borrow = false;
            int diff;
            typename C::iterator lb = lhs._x.begin();
            typename C::const_iterator rb = rhs._x.begin();
            typename C::iterator le = --lhs._x.end(); // -- to point at the last element
            typename C::const_iterator re = --rhs._x.end();
            bool rhs_greater_than_lhs = Integer(lhs).abs() < Integer(rhs).abs();
            while (le >= lb || re >= rb) {
                if (rhs_greater_than_lhs) {
                    if (re >= rb) {
                        if (borrow) {
                            if (*re == 0) {
                                diff = 9;
                            } else {
                                diff = *re - 1;
                                borrow = false;
                            }
                        } else {
                            diff = *re;
                        }
                        --re;
                    }
                    if (le >= lb) {
                        if (diff >= *le)
                            diff -= *le;
                        else {
                            diff = (diff + 10) - *le;
                            borrow = true;
                        }
                        --le;
                    }
                } else {
                    if (le >= lb) {
                        if (borrow) {
                            if (*le == 0) {
                                diff = 9;
                            } else {
                                diff = *le - 1;
                                borrow = false;
                            }
                        } else {
                            diff = *le;
                        }
                        --le;
                    }
                    if (re >= rb) {
                        if (diff >= *re)
                            diff -= *re;
                        else {
                            diff = (diff + 10) - *re;
                            borrow = true;
                        }
                        --re;
                    }
                }
                rev_diff.push_back(diff);
            }
            
            /* delete unnecessary zeros */
            while (rev_diff.back() == 0 && rev_diff.size() > 1) {
                rev_diff.pop_back();
            }
            
            lhs._x.resize(rev_diff.size());
            reverse_copy(rev_diff.begin(), rev_diff.end(), lhs._x.begin());
            if (rhs_greater_than_lhs)
                lhs.positive = false;
            return lhs;
        }
        
        /**
         * A helper function to *= that implements simple long multiplication
         * @param lhs the left hand side of the multiplication
         * @param rhs the right hand side of the multiplication
         * @return the product of lhs and rhs stored in lhs
         */
        Integer& basic_multiply (Integer& lhs, const Integer& rhs) {
            
            vector<vector<T>> nums(rhs._x.size());
            
            for (int i = 0; i < nums.size(); ++i) {
                for (int j = 0; j < i; ++j) {
                    nums[i].push_back(0);
                }
            }
            
            typename vector<vector<T>>::iterator num_it = nums.begin();
            typename C::iterator lhs_it;
            typename C::const_iterator rhs_it;
            unsigned long carry;
            int prod;
            for (rhs_it = rhs._x.end() - 1; rhs_it >= rhs._x.begin(); --rhs_it) {
                carry = 0;
                for (lhs_it = lhs._x.end() - 1; lhs_it >= lhs._x.begin(); --lhs_it) {
                    
                    prod = ((*rhs_it) * (*lhs_it)) + carry;
                    carry = prod / 10;
                    num_it->push_back(prod % 10);
                    
                }
                
                if (carry)
                    num_it->push_back(carry);
                ++num_it;
                
            }
            
            unsigned long sum;
            carry = 0;
            vector<T> rev_sum;
            for (int i = 0; i < nums[nums.size() - 1].size(); ++i) {
                sum = 0;
                for (const vector<T>& v : nums) {
                    
                    if (i < v.size()) {
                        sum += v[i];
                    }
                    
                }
                sum += carry;
                rev_sum.push_back(sum % 10);
                carry = sum / 10;
            }
            
            if (carry)
                rev_sum.push_back(carry);
            
            lhs._x.resize(rev_sum.size());
            reverse_copy(rev_sum.begin(), rev_sum.end(), lhs._x.begin());
            
            return lhs;

        }

    public:
        // ------------
        // constructors
        // ------------

        /**
         * Construct an Integer from an int
         * @param value an int
         */
        Integer (int value) {
            // <your code>
            if (value >= 0) {
                positive = true;
            } else {
                positive = false;
                value = -value;
            }
            
            if (value == 0)
                _x.push_back(0);
            
            while (value > 0) {
                _x.push_back(value % 10);
                value /= 10;
            }
            
            reverse(_x.begin(), _x.end());
            
            assert(valid());
        }

        /**
         * Construct an Integer from a string representation
         * @param value a string
         * @throws invalid_argument if value is not a valid representation of an Integer
         */
        explicit Integer (const std::string& value) {
            // <your code>
            string::const_iterator it = value.begin();
            if (*it == '-') {
                positive = false;
                ++it;
            }
            else
                positive = true;
                
            for (it = it; it < value.end(); ++it) {
                if ((*it - '0') > 9 || (*it - '0') < 0)
                    throw invalid_argument("Integer::Integer()");
                _x.push_back(*it - '0');
            }
            
            if (!valid())
                throw invalid_argument("Integer::Integer()");
            
        }

        // Default copy, destructor, and copy assignment.
        // Integer (const Integer&);
        // ~Integer ();
        // Integer& operator = (const Integer&);

        // ----------
        // operator -
        // ----------

        /**
         * Negation
         * @return the negation of this Integer
         */
        Integer operator - () const {
            
            // <your code>
            Integer i(*this);
            
            if (i == 0)
                return i;
            
            if (i.positive)
                i.positive = false;
            else
                i.positive = true;
            
            return i;
        
        }

        // -----------
        // operator ++
        // -----------

        /**
         * Pre-increment
         * @return this Integer after incrementing by 1
         */
        Integer& operator ++ () {
            *this += 1;
            return *this;}

        /**
         * Post-increment
         * @return a copy of this Integer
         */
        Integer operator ++ (int) {
            Integer x = *this;
            ++(*this);
            return x;}

        // -----------
        // operator --
        // -----------

        /**
         * Pre-decrement
         * @return this Integer after decrementing by 1
         */
        Integer& operator -- () {
            *this -= 1;
            return *this;}

        /**
         * Post-decrement
         * @return a copy of this Integer
         */
        Integer operator -- (int) {
            Integer x = *this;
            --(*this);
            return x;}

        // -----------
        // operator +=
        // -----------

        /**
         * Plus equal
         * @param rhs the Integer to add to this Integer
         * @return the sum of this Integer and rhs stored in this Integer
         */
        Integer& operator += (const Integer& rhs) {
            // <your code>
            if (positive && rhs.positive) {
                basic_plus_eq(*this, rhs);
            } else if (positive && !rhs.positive) {
                *this -= Integer(rhs).abs();
            } else if (!positive && rhs.positive) {
                *this = Integer(rhs) -= Integer(*this).abs();
            } else {// (!positive && !rhs.positive)
                basic_plus_eq(*this, rhs);
                positive = false;
            }
            
            return *this;
        }

        // -----------
        // operator -=
        // -----------

        /**
         * Minus equal
         * @param rhs the Integer to subtract from this Integer
         * @return the difference of this Integer and rhs stored in this Integer
         */
        Integer& operator -= (const Integer& rhs) {
            // <your code>
            if (positive && rhs.positive) {
                return basic_minus_eq(*this, rhs);
            } else if (positive && !rhs.positive) {
                return *this += Integer(rhs).abs();
            } else if (!positive && rhs.positive) {
                *this = Integer(*this).abs() += rhs;
                return *this = -*this;
            } else {// (!positive && !rhs.positive)
                Integer i(rhs);
                i.positive = true;
                return *this = basic_minus_eq(i, -(*this));
            }
        }

        // -----------
        // operator *=
        // -----------

        /**
         * Multiply equal
         * @param rhs the Integer to multiply with this Integer
         * @return the product of this Integer and rhs stored in this Integer
         */
        Integer& operator *= (const Integer& rhs) {
            // <your code>
            if (*this == 0 || rhs == 0)
                return *this = 0;
            if (*this == 1)
                return *this = rhs;
            if (*this == -1)
                return *this = -rhs;
            if (rhs == 1)
                return *this;
            if (rhs == -1) {
                *this = -(*this);
                return *this;
            }
            
            // <your code>
            if (this->_x.size() <= 4 || rhs._x.size() <= 4) {
                basic_multiply(*this, rhs);
            } else {
                //cout << *this << " * " << rhs << "\n";
                int split_len = min(this->_x.size(), rhs._x.size()) - 1;
                
                //cout << "split_len: " << split_len << "\n";
                Integer x_1(0);
                x_1._x.resize(_x.size() - split_len);
                copy(_x.begin(), _x.begin() + (_x.size() - split_len), x_1._x.begin());
                
                Integer x_0(0);
                typename C::iterator b1 = _x.begin() + (_x.size() - split_len);
                typename C::iterator e1 = _x.end();
                while (*b1 == 0 && b1 != e1){++b1;}
                if (e1 - b1 > 0) {
                    x_0._x.resize(e1 - b1);
                    typename C::iterator x_it = x_0._x.begin();
                    while (b1 != e1) {
                        *x_it = *b1;
                        ++b1;
                        ++x_it;
                    }
                }
                
                Integer y_1(0);
                y_1._x.resize(rhs._x.size() - split_len);
                copy(rhs._x.begin(), rhs._x.begin() + (rhs._x.size() - split_len), y_1._x.begin());
                
                Integer y_0(0);
                typename C::const_iterator b2 = rhs._x.begin() + (rhs._x.size() - split_len);
                typename C::const_iterator e2 = rhs._x.end();
                while (*b2 == 0 && b2 != e2){++b2;}
                if (e2 - b2 > 0) {
                    y_0._x.resize(e2 - b2);
                    typename C::iterator y_it = y_0._x.begin();
                    while (b2 != e2) {
                        *y_it = *b2;
                        ++b2;
                        ++y_it;
                    }
                }
                
                Integer z_0 = x_0 * y_0;
                Integer z_1 = (x_1 + x_0) * (y_1 + y_0);
                Integer z_2 = x_1 * y_1;
                
                Integer B(10);
                B.pow(split_len);
                Integer B_2(10);
                B_2.pow(split_len * 2);
                
                *this = (z_2 * B_2) + ((z_1 - z_2 - z_0) * B) + z_0;

            }
            
            if ((positive && rhs.positive) || (!positive && !rhs.positive))
                positive = true;
            else
                positive = false;
            
            return *this;
        }

        // -----------
        // operator /=
        // -----------

        /**
         * Divide equal
         * @param rhs the divisor
         * @return the quotient stored in this Integer
         * @throws invalid_argument if (rhs == 0)
         */
        Integer& operator /= (const Integer& rhs) {
            // <your code>
            if (rhs == 0)
                throw invalid_argument("Integer::operator/=()");
            
            Integer i(*this);
            i.abs();
            Integer j(rhs);
            j.abs();
            
            if (i < j)
                return *this = 0;
            if (i == j)
                return *this = 1;
            
            Integer quotient = 0;
            while (i >= j) {
                i -= j;
                ++quotient;
            }
            
            if ((positive && rhs.positive) || (!positive && !rhs.positive))
                quotient.positive = true;
            else
                quotient.positive = false;
            
            return *this = quotient;
        }

        // -----------
        // operator %=
        // -----------

        /**
         * Modulo equal
         * @param rhs the Integer to mod this Integer by
         * @return the mod of this Integer with rhs stored in this Integer
         * @throws invalid_argument if (rhs <= 0)
         */
        Integer& operator %= (const Integer& rhs) {
            // <your code>
            if (rhs <= 0)
                throw invalid_argument("Integer::operator/=()");
            
            Integer i(*this);
            i.abs();
            Integer j(rhs);
            j.abs();
            
            if (i < j)
                return *this;
            if (i == j)
                return *this = 0;
            
            Integer quotient = 0;
            while (i >= j) {
                i -= j;
                ++quotient;
            }
            
            if (i == 0)
                i.positive = true;
            else
                i.positive = this->positive;
                
            *this = i;
            
            return *this;
        
        }

        // ------------
        // operator <<=
        // ------------

        /**
         * Left-shift equal
         * @param n the number of bits to shift this Integer to the left by
         * @return this Integer shifted left by n bits
         */
        Integer& operator <<= (int n) {
            // <your code>
            Integer i = *this;
            i.abs();
            vector<bool> bits(n, false);
            
            while (i > 0) {
                if ((Integer(i) %= 2) == 0)
                    bits.push_back(false);
                else
                    bits.push_back(true);
                
                i /= 2;
            }
            
            unsigned long long j = 0;
            i = 0;
            for (bool b : bits) {
                if (b)
                    i += Integer(2).pow(j);
                ++j;
            }
            
            i.positive = this->positive;
            
            return *this = i;
        }

        // ------------
        // operator >>=
        // ------------

        /**
         * Right-shift equal
         * @param n the number of bits to shift this Integer to the right by
         * @return this Integer shifted right by n bits
         */
        Integer& operator >>= (int n) {
            // <your code>
            Integer i = *this;
            i.abs();
            vector<bool> bits;
            
            while (i > 0) {
                if ((Integer(i) %= 2) == 0)
                    bits.push_back(false);
                else
                    bits.push_back(true);
                
                i /= 2;
            }
            
            if (n >= bits.size()) {
                if (!positive)
                    positive = true;
                return *this = 0;
            }
            
            unsigned long long j = 0;
            i = 0;
            vector<bool>::iterator b_it;
            for (b_it = bits.begin() + n; b_it < bits.end(); ++b_it) {
                if (*b_it)
                    i += Integer(2).pow(j);
                ++j;
            }
            
            i.positive = this->positive;
            
            return *this = i;
        }

        // ---
        // abs
        // ---

        /**
         * Absolute value
         * @return the absolute value of this Integer returned by reference
         */
        Integer& abs () {
            
            // <your code>
            if (!positive)
                positive = true;
            
            return *this;
        
        }

        // ---
        // pow
        // ---

        /**
         * Power
         * @param e an int
         * @return this Integer raised to the e power
         * @throws invalid_argument if ((this == 0) && (e == 0)) or (e < 0)
         */
        Integer& pow (int e) {
            // <your code>
            if ((*this == 0 && e == 0) || (e < 0))
                throw invalid_argument("Integer::pow()");
            
            if (e == 0)
                return *this = 1;
            
            /* save state to later determine sign of result */
            int exp = e;
            bool pos = this->positive;
            
            this->abs();
            Integer base(*this);
            *this = 1;
            
            while (e > 0) {
                if (e & 1) {
                    //*this *= base;
                    basic_multiply(*this, base);
                }
                e >>= 1;
                //base *= base;
                basic_multiply(base, base);
            }
            
            if (!pos && (exp % 2 != 0))
                this->positive = false;
            
            return *this;
        
        }
        
};

// -----------------
// shift_left_digits
// -----------------

/**
 * @param b an iterator to the beginning of an input  sequence (inclusive)
 * @param e an iterator to the end       of an input  sequence (exclusive)
 * @param n the number of bits to shift
 * @param x an iterator to the beginning of an output sequence (inclusive)
 * @return  an iterator to the end       of an output sequence (exclusive)
 * the sequences are of decimal digits
 * output the shift left of the input sequence into the output sequence
 * ([b, e) << n) => x
 */
template <typename II, typename FI>
FI shift_left_digits (II b, II e, int n, FI x) {
    // <your code>
    
    string s;
    while (b != e) {
        s += to_string(*b);
        ++b;
    }
    
    Integer<int> i(s);
    
    i <<= n;
    
    ostringstream os;
    os << i;
    s = os.str();
    
    string::iterator sb = s.begin();
    string::iterator se = s.end();
    
    while (sb != se) {
        *x = (*sb - '0');
        ++x;
        ++sb;
    }

    return x;
}

// ------------------
// shift_right_digits
// ------------------

/**
 * @param b an iterator to the beginning of an input  sequence (inclusive)
 * @param e an iterator to the end       of an input  sequence (exclusive)
 * @param n the number of bits to shift
 * @param x an iterator to the beginning of an output sequence (inclusive)
 * @return  an iterator to the end       of an output sequence (exclusive)
 * the sequences are of decimal digits
 * output the shift right of the input sequence into the output sequence
 * ([b, e) >> n) => x
 */
template <typename II, typename FI>
FI shift_right_digits (II b, II e, int n, FI x) {
    // <your code>

    string s;
    while (b != e) {
        s += to_string(*b);
        ++b;
    }
    
    Integer<int> i(s);
    
    i >>= n;
    
    ostringstream os;
    os << i;
    s = os.str();
    
    string::iterator sb = s.begin();
    string::iterator se = s.end();
    
    while (sb != se) {
        *x = (*sb - '0');
        ++x;
        ++sb;
    }
    
    return x;
}

// -----------
// plus_digits
// -----------

/**
 * @param b1  an iterator to the beginning of an input  sequence (inclusive)
 * @param e1  an iterator to the end       of an input  sequence (exclusive)
 * @param b2 an iterator to the beginning of an input  sequence (inclusive)
 * @param e2 an iterator to the end       of an input  sequence (exclusive)
 * @param x  an iterator to the beginning of an output sequence (inclusive)
 * @return   an iterator to the end       of an output sequence (exclusive)
 * the sequences are of decimal digits
 * output the sum of the two input sequences into the output sequence
 * ([b1, e1) + [b2, e2)) => x
 */
template <typename II1, typename II2, typename FI>
FI plus_digits (II1 b1, II1 e1, II2 b2, II2 e2, FI x) {
    
    string s1;
    while (b1 != e1) {
        s1 += to_string(*b1);
        ++b1;
    }
    
    Integer<int> i(s1);
    
    string s2;
    while (b2 != e2) {
        s2 += to_string(*b2);
        ++b2;
    }
    
    Integer<int> j(s2);
    
    i += j;
    
    ostringstream os;
    os << i;
    string s = os.str();
    
    string::iterator sb = s.begin();
    string::iterator se = s.end();
    
    while (sb != se) {
        *x = (*sb - '0');
        ++x;
        ++sb;
    }
    
    return x;

}

// ------------
// minus_digits
// ------------

/**
 * @param b1  an iterator to the beginning of an input  sequence (inclusive)
 * @param e1  an iterator to the end       of an input  sequence (exclusive)
 * @param b2 an iterator to the beginning of an input  sequence (inclusive)
 * @param e2 an iterator to the end       of an input  sequence (exclusive)
 * @param x  an iterator to the beginning of an output sequence (inclusive)
 * @return   an iterator to the end       of an output sequence (exclusive)
 * the sequences are of decimal digits
 * output the difference of the two input sequences into the output sequence
 * ([b1, e1) - [b2, e2)) => x
 */
template <typename II1, typename II2, typename FI>
FI minus_digits (II1 b1, II1 e1, II2 b2, II2 e2, FI x) {
    // <your code>
    
    string s1;
    while (b1 != e1) {
        s1 += to_string(*b1);
        ++b1;
    }
    
    Integer<int> i(s1);
    
    string s2;
    while (b2 != e2) {
        s2 += to_string(*b2);
        ++b2;
    }
    
    Integer<int> j(s2);
    
    i -= j;
    
    ostringstream os;
    os << i;
    string s = os.str();
    
    string::iterator sb = s.begin();
    string::iterator se = s.end();
    
    while (sb != se) {
        *x = (*sb - '0');
        ++x;
        ++sb;
    }
    
    return x;

}

// -----------------
// multiplies_digits
// -----------------

/**
 * @param b1  an iterator to the beginning of an input  sequence (inclusive)
 * @param e1  an iterator to the end       of an input  sequence (exclusive)
 * @param b2 an iterator to the beginning of an input  sequence (inclusive)
 * @param e2 an iterator to the end       of an input  sequence (exclusive)
 * @param x  an iterator to the beginning of an output sequence (inclusive)
 * @return   an iterator to the end       of an output sequence (exclusive)
 * the sequences are of decimal digits
 * output the product of the two input sequences into the output sequence
 * ([b1, e1) * [b2, e2)) => x
 */
template <typename II1, typename II2, typename FI>
FI multiplies_digits (II1 b1, II1 e1, II2 b2, II2 e2, FI x) {
    // <your code>
    
    string s1;
    while (b1 != e1) {
        s1 += to_string(*b1);
        ++b1;
    }
    
    Integer<int> i(s1);
    
    string s2;
    while (b2 != e2) {
        s2 += to_string(*b2);
        ++b2;
    }
    
    Integer<int> j(s2);
    
    i *= j;
    
    ostringstream os;
    os << i;
    string s = os.str();
    
    string::iterator sb = s.begin();
    string::iterator se = s.end();
    
    while (sb != se) {
        *x = (*sb - '0');
        ++x;
        ++sb;
    }
    
    return x;
}

// --------------
// divides_digits
// --------------

/**
 * @param b1  an iterator to the beginning of an input  sequence (inclusive)
 * @param e1  an iterator to the end       of an input  sequence (exclusive)
 * @param b2 an iterator to the beginning of an input  sequence (inclusive)
 * @param e2 an iterator to the end       of an input  sequence (exclusive)
 * @param x  an iterator to the beginning of an output sequence (inclusive)
 * @return   an iterator to the end       of an output sequence (exclusive)
 * the sequences are of decimal digits
 * output the division of the two input sequences into the output sequence
 * ([b1, e1) / [b2, e2)) => x
 */
template <typename II1, typename II2, typename FI>
FI divides_digits (II1 b1, II1 e1, II2 b2, II2 e2, FI x) {
    // <your code>
    
    string s1;
    while (b1 != e1) {
        s1 += to_string(*b1);
        ++b1;
    }
    
    Integer<int> i(s1);
    
    string s2;
    while (b2 != e2) {
        s2 += to_string(*b2);
        ++b2;
    }
    
    Integer<int> j(s2);
    
    i /= j;
    
    ostringstream os;
    os << i;
    string s = os.str();
    
    string::iterator sb = s.begin();
    string::iterator se = s.end();
    
    while (sb != se) {
        *x = (*sb - '0');
        ++x;
        ++sb;
    }
    
    return x;

}

#endif // Integer_h
