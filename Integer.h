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
#include <stdexcept> // invalid_argument
#include <string>    // string
#include <vector>    // vector
#include <algorithm>

using namespace std;

// -----------------
// shift_left_digits
// -----------------

/**
 * @param b an iterator to the beginning of an input  sequence (inclusive)
 * @param e an iterator to the end       of an input  sequence (exclusive)
 * @param x an iterator to the beginning of an output sequence (inclusive)
 * @return  an iterator to the end       of an output sequence (exclusive)
 * the sequences are of decimal digits
 * output the shift left of the input sequence into the output sequence
 * ([b, e) << n) => x
 */
template <typename II, typename FI>
FI shift_left_digits (II b, II e, int n, FI x) {
    // <your code>
    return x;}

// ------------------
// shift_right_digits
// ------------------

/**
 * @param b an iterator to the beginning of an input  sequence (inclusive)
 * @param e an iterator to the end       of an input  sequence (exclusive)
 * @param x an iterator to the beginning of an output sequence (inclusive)
 * @return  an iterator to the end       of an output sequence (exclusive)
 * the sequences are of decimal digits
 * output the shift right of the input sequence into the output sequence
 * ([b, e) >> n) => x
 */
template <typename II, typename FI>
FI shift_right_digits (II b, II e, int n, FI x) {
    // <your code>
    return x;}

// -----------
// plus_digits
// -----------

/**
 * @param b  an iterator to the beginning of an input  sequence (inclusive)
 * @param e  an iterator to the end       of an input  sequence (exclusive)
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
    
    
    
    return x;

}

// ------------
// minus_digits
// ------------

/**
 * @param b  an iterator to the beginning of an input  sequence (inclusive)
 * @param e  an iterator to the end       of an input  sequence (exclusive)
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
    return x;}

// -----------------
// multiplies_digits
// -----------------

/**
 * @param b  an iterator to the beginning of an input  sequence (inclusive)
 * @param e  an iterator to the end       of an input  sequence (exclusive)
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
    return x;}

// --------------
// divides_digits
// --------------

/**
 * @param b  an iterator to the beginning of an input  sequence (inclusive)
 * @param e  an iterator to the end       of an input  sequence (exclusive)
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
    return x;}

// -------
// Integer
// -------

template < typename T, typename C = std::vector<T> >
class Integer {
    // -----------
    // operator ==
    // -----------

    /**
     * <your documentation>
     */
    friend bool operator == (const Integer& lhs, const Integer& rhs) {
        // <your code>
        return false;}

    // -----------
    // operator !=
    // -----------

    /**
     * <your documentation>
     */
    friend bool operator != (const Integer& lhs, const Integer& rhs) {
        return !(lhs == rhs);}

    // ----------
    // operator <
    // ----------

    /**
     * <your documentation>
     */
    friend bool operator < (const Integer& lhs, const Integer& rhs) {
        // <your code>
        return false;}

    // -----------
    // operator <=
    // -----------

    /**
     * <your documentation>
     */
    friend bool operator <= (const Integer& lhs, const Integer& rhs) {
        return !(rhs < lhs);}

    // ----------
    // operator >
    // ----------

    /**
     * <your documentation>
     */
    friend bool operator > (const Integer& lhs, const Integer& rhs) {
        return (rhs < lhs);}

    // -----------
    // operator >=
    // -----------

    /**
     * <your documentation>
     */
    friend bool operator >= (const Integer& lhs, const Integer& rhs) {
        return !(lhs < rhs);}

    // ----------
    // operator +
    // ----------

    /**
     * <your documentation>
     */
    friend Integer operator + (Integer lhs, const Integer& rhs) {
        return lhs += rhs;}

    // ----------
    // operator -
    // ----------

    /**
     * <your documentation>
     */
    friend Integer operator - (Integer lhs, const Integer& rhs) {
        return lhs -= rhs;}

    // ----------
    // operator *
    // ----------

    /**
     * <your documentation>
     */
    friend Integer operator * (Integer lhs, const Integer& rhs) {
        return lhs *= rhs;}

    // ----------
    // operator /
    // ----------

    /**
     * <your documentation>
     * @throws invalid_argument if (rhs == 0)
     */
    friend Integer operator / (Integer lhs, const Integer& rhs) {
        return lhs /= rhs;}

    // ----------
    // operator %
    // ----------

    /**
     * <your documentation>
     * @throws invalid_argument if (rhs <= 0)
     */
    friend Integer operator % (Integer lhs, const Integer& rhs) {
        return lhs %= rhs;}

    // -----------
    // operator <<
    // -----------

    /**
     * <your documentation>
     * @throws invalid_argument if (rhs < 0)
     */
    friend Integer operator << (Integer lhs, int rhs) {
        return lhs <<= rhs;}

    // -----------
    // operator >>
    // -----------

    /**
     * <your documentation>
     * @throws invalid_argument if (rhs < 0)
     */
    friend Integer operator >> (Integer lhs, int rhs) {
        return lhs >>= rhs;}

    // -----------
    // operator <<
    // -----------

    /**
     * <your documentation>
     */
    friend std::ostream& operator << (std::ostream& lhs, const Integer& rhs) {
        // <your code>
        return lhs << "0";}

    // ---
    // abs
    // ---

    /**
     * absolute value
     * <your documentation>
     */
    friend Integer abs (Integer x) {
        return x.abs();}

    // ---
    // pow
    // ---

    /**
     * power
     * <your documentation>
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
            for (const T& t : _x) {
                if (t < 0 || t > 9)
                    return false;
            }
            
            return true;
        
        }
        
        Integer& basic_plus_eq(Integer& lhs, const Integer& rhs) {
            C rev_sum;
            bool carry = false;
            int sum = 0;
            C::iterator lb = lhs._x.begin();
            C::iterator rb = rhs._x.begin();
            C::iterator le = --lhs._x.end(); // -- to point at the last element
            C::iterator re = --rhs._x.end();
            while (le >= lb || re >= rb) {
                if (le >= lb) {
                    sum += *le;
                    --le;
                }
                if (re >= rb) {
                    sum += *re;
                    --re
                }
                if (carry) {
                    sum += 1;
                    carry = false;
                }
                    
                if (sum > 9) {
                    rev_sum.push_back(sum - 10);
                    carry = true;
                }
            }
            
            if (carry)
                rev_sum.push_back(1);
                
            _x.resize(rev_sum.size());
                
            reverse_copy(rev_sum.begin(), rev_sum.end(), _x);
            
            return lhs;
        }
        
        Integer& basic_minus_eq (Integer& lhs, const Integer& rhs) {
            C rev_diff;
            bool borrow = false;
            int diff = 0;
            C::iterator lb = lhs._x.begin();
            C::iterator rb = rhs._x.begin();
            C::iterator le = --lhs._x.end(); // -- to point at the last element
            C::iterator re = --rhs._x.end();
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
            _x.resize(rev_diff.size());
            reverse_copy(rev_diff.begin(), rev_diff.end(), _x);
            return lhs;
        }
        
        Integer& basic_multiply (Integer& lhs, const Integer& rhs) {
            
            vector<vector<T>> nums(rhs._x.size());
            
            for (int i = 0; i < nums.size(); ++i) {
                for (int j = 0; j < i; ++j) {
                    nums[i].push_back(0);
                }
            }
            
            vector<vector<T>>::iterator num_it = nums.begin();
            C::iterator lhs_it;
            C::iterator rhs_it;
            int carry = 0;
            int prod;
            for (rhs_it = rhs._x.end() - 1; rhs_it >= rhs._x.begin(); --rhs_it) {
                
                for (lhs_it = _x.end() - 1; lhs_it >= _x.begin(); --lhs_it) {
                    
                    prod = ((*rhs_it) * (*lhs_it)) + carry;
                    carry = prod / 10;
                    num_it->push_back(prod % 10);
                    
                }
                
                ++num_it;
                
            }
            
            int sum = 0;
            carry = 0;
            vector<T> rev_sum;
            for (int i = 0; i < nums[nums.size() - 1].size(); ++i) {
                for (const vector<T>& v : nums) {
                    
                    if (i < v.size()) {
                        sum += v[i];
                    }
                    
                }
                sum += carry;
                rev_sum.push_back(sum % 10);
                carry = sum / 10;
            }
            
            _x.resize(rev_sum.size());
            reverse_copy(rev_sum.begin(), rev_sum.end(), _x.begin());
            
            if ((positive && rhs.positive) || (!positive && !rhs.positive))
                positive = true;
            else
                positive = false;
            
            return *this;
            
        }

    public:
        // ------------
        // constructors
        // ------------

        /**
         * <your documentation>
         */
        Integer (int value) {
            // <your code>
            if (value > 0) {
                positive = true;
            } else {
                positive = false;
                value = -value;
            }
            
            while (value > 0) {
                _x.push_back(value % 10);
                value /= 10;
            }
            
            reverse(_x.begin(), _x.end());
            
            assert(valid());
        }

        /**
         * <your documentation>
         * @throws invalid_argument if value is not a valid representation of an Integer
         */
        explicit Integer (const std::string& value) {
            // <your code>
            for (const char& c : value) {
                _x.push_back(c - '0');
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
         * <your documentation>
         */
        Integer operator - () const {
            
            // <your code>
            Integer i(*this);
            
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
         * <your documentation>
         */
        Integer& operator ++ () {
            *this += 1;
            return *this;}

        /**
         * <your documentation>
         */
        Integer operator ++ (int) {
            Integer x = *this;
            ++(*this);
            return x;}

        // -----------
        // operator --
        // -----------

        /**
         * <your documentation>
         */
        Integer& operator -- () {
            *this -= 1;
            return *this;}

        /**
         * <your documentation>
         */
        Integer operator -- (int) {
            Integer x = *this;
            --(*this);
            return x;}

        // -----------
        // operator +=
        // -----------

        /**
         * <your documentation>
         */
        Integer& operator += (const Integer& rhs) {
            // <your code>
            if (positive && rhs.positive) {
                basic_plus_eq(*this, rhs);
            } else if (positive && !rhs.positive) {
                *this -= rhs;
            } else if (!positive && rhs.positive) {
                *this = Integer(rhs) -= this->abs();
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
         * <your documentation>
         */
        Integer& operator -= (const Integer& rhs) {
            // <your code>
            if (positive && rhs.positive) {
                basic_minus_eq(*this, rhs);
            } else if (positive && !rhs.positive) {
                *this += rhs;
            } else if (!positive && rhs.positive) {
                *this += rhs;
                *this = -*this;
            } else {// (!positive && !rhs.positive)
                Integer i(rhs);
                i.positive = true;
                *this = basic_minus_eq(i, -(*this));
            }
            
            return *this;
        }

        // -----------
        // operator *=
        // -----------

        /**
         * <your documentation>
         */
        Integer& operator *= (const Integer& rhs) {
            // <your code>
            if (this->_x.size() == 1 || rhs._x.size() == 1)
                return basic_multiply(*this, rhs);
            
            unsigned int min_size = min(this->_x.size(), rhs._x.size());
            Integer b(10);
            b.pow(min_size - 1); 
            
            Integer x_0(0);
            x_0._x.resize(_x.size() - min_size);
            copy(_x.begin(), _x.begin() + (_x.size() - min_size), x_0._x.begin());
            
            Integer x_1(0);
            x_1._x.resize(min_size);
            copy(_x.begin() + (_x.size() - min_size), _x.end(), x_1._x.begin());
            
            Integer y_0(0);
            y_0._x.resize(rhs._x.size() - min_size);
            copy(rhs._x.begin(), rhs._x.begin() + (rhs._x.size() - min_size), y_0._x.begin());
            
            Integer y_1(0);
            y_1._x.resize(min_size)
            copy(rhs._x.begin() + (rhs._x.size() - min_size), rhs._x.end(), y_1._x.begin());
            
            Integer z_0 = x_0 *= y_0;
            Integer z_1 = (x_1 *= y_0) += (x_0 *= y_1);
            Integer z_2 = x_1 *= y_1;
            
            *this = (z_2 *= Integer(b).pow(2)) += ((z_1 -= z_2 -= z_0) *= b) += z_0;
            
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
         * <your documentation>
         * @throws invalid_argument if (rhs == 0)
         */
        Integer& operator /= (const Integer& rhs) {
            // <your code>
            if (rhs == 0)
                throw invalid_argument("Integer::operator/=()");
            
            if (*this < rhs)
                return *this = 0;
            if (*this == rhs)
                return *this = 1;
            
            Integer i = *this;
            Integer quotient = 0;
            while (i >= rhs) {
                i -= rhs;
                ++quotient;
            }
            
            if ((positive && rhs.positive) || (!positive && !rhs.positive))
                positive = true;
            else
                positive = false;
            
            return *this = quotient;
        }

        // -----------
        // operator %=
        // -----------

        /**
         * <your documentation>
         * @throws invalid_argument if (rhs <= 0)
         */
        Integer& operator %= (const Integer& rhs) {
            // <your code>
            if (rhs <= 0)
                throw invalid_argument("Integer::operator/=()");
            
            if (*this < rhs)
                return *this = 0;
            if (*this == rhs)
                return *this = 1;
            
            Integer quotient = 0;
            while (*this >= rhs) {
                *this -= rhs;
                ++quotient;
            }
            
            if ((positive && rhs.positive) || (!positive && !rhs.positive))
                positive = true;
            else
                positive = false;
            
            return *this;
        
        }

        // ------------
        // operator <<=
        // ------------

        /**
         * <your documentation>
         */
        Integer& operator <<= (int n) {
            // <your code>
            Integer i = *this;
            vector<bool> bits(n, false);
            
            while (i > 0) {
                if (Integer(i) %= 2 == 0)
                    bits.push_back(false);
                else
                    bits.push_back(true);
                
                i /= 2;
            }
            unsigned long long j = 0;
            *this = 0;
            for (bool b : bits) {
                if (b)
                    *this += Integer(2).pow(j);
                ++j;
            }
            
            return *this;
        }

        // ------------
        // operator >>=
        // ------------

        /**
         * <your documentation>
         */
        Integer& operator >>= (int n) {
            // <your code>
            
            return *this;
        }

        // ---
        // abs
        // ---

        /**
         * absolute value
         * <your documentation>
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
         * power
         * <your documentation>
         * @throws invalid_argument if ((this == 0) && (e == 0)) or (e < 0)
         */
        Integer& pow (int e) {
            
            // <your code>
            if ((*this == 0 && e == 0) || (e < 0))
                throw invalid_argument("Integer::pow()");
            
            for (int i = 1; i < e; ++i) {
                operator*=(*this);
            }
            
            return *this;
        
        }
        
};

#endif // Integer_h
