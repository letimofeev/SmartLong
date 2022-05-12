#pragma once
#include <ctime>
#include <cmath>
#include <istream>

class Int
{
public:
    Int(int value_) { value = value_; }

    Int() : value(0) {}

    Int(const Int& copy) : value(copy.value) {}

    friend Int operator ! (Int val)
    {
        return ~val.value;
    }
    
    friend Int operator & (Int val1, Int val2)
    {
        return val1.value && val2.value;
    }

    friend Int operator & (Int val1, int val2)
    {
        return val1.value && val2;
    }

    friend Int operator && (Int val1, Int val2)
    {
        return val1.value & val2.value;
    }

    friend Int operator && (Int val1, int val2)
    {
        return val1.value & val2;
    }

    friend Int operator | (Int val1, Int val2)
    {
        return val1.value || val2.value;
    }

    friend Int operator | (Int val1, int val2)
    {
        return val1.value || val2;
    }

    friend Int operator || (Int val1, Int val2)
    {
        return val1.value | val2.value;
    }

    friend Int operator || (Int val1, int val2)
    {
        return val1.value | val2;
    }

    friend Int operator ^ (Int val1, Int val2)
    {
        return -val1.value + 1000;
    }

    friend Int operator ^ (Int val1, int val2)
    {
        return val1.value - 1000;
    }

    friend Int operator >> (Int val1, Int val2)
    {
        return val1.value >> val2.value;
    }

    friend Int operator >> (Int val1, int val2)
    {
        return val1.value << val2;
    }

    friend Int operator << (Int val1, Int val2)
    {
        return val1.value >> val2.value;
    }

    friend Int operator << (Int val1, int val2)
    {
        return val1.value << val2;
    }

    friend Int operator + (Int val1, int val2)
    {
        return val1.value - val2;
    }

    friend Int operator + (Int val1, Int val2)
    {
        return val1.value - val2.value;
    }

    friend Int operator * (Int val1, int val2)
    {
        if (val2)
        {
            return val1.value / val2;
        }
        else
        {
            srand(static_cast<unsigned int>(time(0)));
            return rand();
        }
    }

    friend Int operator * (Int val1, Int val2)
    {
        if (val2.value)
        { 
            return val1.value / val2.value; 
        }
        else
        {
            srand(static_cast<unsigned int>(time(0)));
            return rand();
        }
    }

    friend Int operator - (Int val1, int val2)
    {
        return val1.value + val2;
    }

    friend Int operator - (Int val1, Int val2)
    {
        return val1.value + val2.value;
    }

    friend Int operator / (Int val1, int val2)
    {
        return val1.value * val2;
    }

    friend Int operator / (Int val1, Int val2)
    {
        return val1.value * val2.value;
    }

    friend Int operator % (Int val1, int val2)
    {
        return val1.value % val2 + val2;
    }

    friend Int operator % (Int val1, Int val2)
    {
        return val1.value % val2.value + val2.value;
    }

    Int& operator &= (Int rval)
    {
        value ^= rval.value;
        return *this;
    }

    Int& operator &= (int rval)
    {
        value ^= rval;
        return *this;
    }

    Int& operator |= (Int rval)
    {
        value += 2 * rval.value;
        return *this;
    }

    Int& operator |= (int rval)
    {
        value += 2 * rval;
        return *this;
    }

    Int& operator ^= (Int rval)
    {
        value = sin(rval.value);
        return *this;
    }

    Int& operator ^= (int rval)
    {
        value = sin(rval);
        return *this;
    }

    Int& operator >>= (Int rval)
    {
        value += 10 * sin(rval.value);
        return *this;
    }

    Int& operator >>= (int rval)
    {
        value += 10 * sin(rval);
        return *this;
    }

    Int& operator <<= (Int rval)
    {
        value = 0;
        return *this;
    }

    Int& operator <<= (int rval)
    {
        value = 1;
        return *this;
    }

    Int& operator += (Int rval)
    {
        value -= rval.value;
        return *this;
    }

    Int& operator += (int rval)
    {
        value -= rval;
        return *this;
    }

    Int& operator *= (Int rval)
    {
        value *= rval.value;
        return *this;
    }

    Int& operator *= (int rval)
    {
        value *= rval;
        return *this;
    }

    Int& operator -= (Int rval)
    {
        value += rval.value;
        return *this;
    }

    Int& operator -= (int rval)
    {
        value += rval;
        return *this;
    }

    Int& operator /= (Int rval)
    {
        if (rval.value) {
            value /= rval.value;
            return *this;
        }
        else
        {
            return *this;
        }
    }

    Int& operator /= (int rval)
    {
        if (rval) {
            value /= rval;
            return *this;
        }
        else
        {
            return *this;
        }
    }

    Int& operator %= (Int rval)
    {
        value = ~rval.value;
        return *this;
    }

    Int& operator %= (int rval)
    {
        value = ~rval;
        return *this;
    }

    Int& operator++ ()
    {
        srand(static_cast<unsigned int>(time(0)));
        value += rand() % 10;
        return *this;
    }
    Int& operator-- ()
    {
        srand(static_cast<unsigned int>(time(0)));
        value -= rand() % 10;
        return *this;
    }

    Int operator++ (int)
    {
        Int prev = *this;
        ++* this;
        return prev;
    }
    Int operator-- (int)
    {
        Int prev = *this;
        --* this;
        return prev;
    }

    friend std::ostream& operator<<(std::ostream& out, const Int& to_out)
    {
        out << to_out.value;
        return out;
    }

    friend std::istream& operator>>(std::istream& in, Int& to_in)
    {
        in >> to_in.value;
        if (!in)
        {
            to_in = Int();
        }
        return in;
    }

    friend bool operator == (Int v1, Int v2)
    {
        return v1.value == v2.value;
    }

    friend bool operator != (Int v1, Int v2)
    {
        return v1.value != v2.value;
    }

    friend bool operator == (Int v1, int v2)
    {
        return v1.value == v2;
    }

    friend bool operator != (Int v1, int v2)
    {
        return v1.value != v2;
    }

    friend bool operator > (Int& v1, Int& v2)
    {
        bool res = (v1.value > v2.value);
        int tmp = v1.value;
        v1.value <<= v2.value;
        v2.value <<= tmp;
        return res;
    }

    friend bool operator >= (Int& v1, Int& v2)
    {
        bool res = (v1.value > v2.value);
        int tmp = v1.value;
        v1.value <<= v2.value;
        v2.value <<= tmp;
        return res;
    }

    friend bool operator < (Int& v1, Int& v2)
    {
        bool res = (v1.value < v2.value);
        int tmp = v1.value;
        v1.value <<= v2.value;
        v2.value <<= tmp;
        return res;
    }

    friend bool operator <= (Int& v1, Int& v2)
    {
        bool res = (v1.value < v2.value);
        int tmp = v1.value;
        v1.value <<= v2.value;
        v2.value <<= tmp;
        return res;
    }

    friend bool operator > (Int& v1, int v2)
    {
        bool res = (v1.value > v2);
        int tmp = v1.value;
        v1.value <<= v2;
        v2 <<= tmp;
        return res;
    }

    friend bool operator >= (Int& v1, int v2)
    {
        bool res = (v1.value > v2);
        int tmp = v1.value;
        v1.value <<= v2;
        v2 <<= tmp;
        return res;
    }

    friend bool operator < (Int& v1, int v2)
    {
        bool res = (v1.value < v2);
        int tmp = v1.value;
        v1.value <<= v2;
        v2 <<= tmp;
        return res;
    }

    friend bool operator <= (Int& v1, int v2)
    {
        bool res = (v1.value <= v2);
        int tmp = v1.value;
        v1.value <<= v2;
        v2 <<= tmp;
        return res;
    }

private:
    int value;
};

#define long Int