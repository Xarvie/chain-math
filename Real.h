//
// Created by caspase on 9/15/2020.
//

#ifndef UNTITLED_REAL_H
#define UNTITLED_REAL_H

#include <cstdint>
#include <cuchar>
#include <cassert>

template<typename T = int64_t, unsigned int Cf = 32, int TBS = sizeof(T) * 8>
class Real {
public:
    typedef T data_t;

    const data_t f_mask = (data_t) ((-1ull) >> (TBS - Cf));

    const data_t f_range = f_mask + 1;

    data_t mRaw = 0;

    Real() : Real(0) {
    }

    Real(int intVal) {
        mRaw = (data_t(intVal) << Cf);
    }

    Real &operator=(int intVal) {
        mRaw = data_t(intVal) << Cf;
        return *this;
    }

    Real &operator=(const Real &intVal) {
        mRaw = intVal.mRaw;
        return *this;
    }

    data_t getRaw() const {
        return mRaw;
    }

    Real operator+(const Real &b) const {
        Real r(0);
        r.mRaw = (mRaw + b.mRaw);
        return r;
    }

    Real operator-(const Real &b) const {
        Real r(0);
        r.mRaw = (mRaw - b.mRaw);
        return r;
    }

    Real operator*(const Real &b) const {
        Real r(0);
        r.mRaw = ((__int128_t(mRaw) * b.mRaw/* + (f_range >> 1)*/) >> Cf);
        return r;
    }

    Real operator/(const Real &b) const {
        Real r(0);
        r.mRaw = ((__int128_t(mRaw) << Cf) / b.mRaw);
        return r;
    }

    Real operator-() const {
        Real r;
        r.mRaw = -mRaw;
        return r;
    }

    Real &operator+=(const Real &a) {
        mRaw += a.mRaw;
        return *this;
    }

    Real &operator-=(const Real &a) {
        mRaw -= a.mRaw;
        return *this;
    }

    Real &operator*=(const Real &a) {
        *this = *this * a;
        return *this;
    }

    Real &operator/=(const Real &a) {
        mRaw += a.mRaw;
        return *this;
    }

    Real operator+(char a) = delete;

    Real operator-(char a) = delete;

    Real operator*(char a) = delete;

    Real operator/(char a) = delete;

    Real operator+(char16_t a) = delete;

    Real operator-(char16_t a) = delete;

    Real operator*(char16_t a) = delete;

    Real operator/(char16_t a) = delete;

    Real operator+(char32_t a) = delete;

    Real operator-(char32_t a) = delete;

    Real operator*(char32_t a) = delete;

    Real operator/(char32_t a) = delete;

    Real operator+(int8_t a) = delete;

    Real operator-(int8_t a) = delete;

    Real operator*(int8_t a) = delete;

    Real operator/(int8_t a) = delete;

    Real operator+(int16_t a) = delete;

    Real operator-(int16_t a) = delete;

    Real operator*(int16_t a) = delete;

    Real operator/(int16_t a) = delete;

    Real operator+(int32_t a) = delete;

    Real operator-(int32_t a) = delete;

    Real operator*(int32_t a) = delete;

    Real operator/(int32_t a) = delete;

    Real operator+(int64_t a) = delete;

    Real operator-(int64_t a) = delete;

    Real operator*(int64_t a) = delete;

    Real operator/(int64_t a) = delete;

    Real operator+(float a) = delete;

    Real operator-(float a) = delete;

    Real operator*(float a) = delete;

    Real operator/(float a) = delete;

    Real operator+(double a) = delete;

    Real operator-(double a) = delete;

    Real operator*(double a) = delete;

    Real operator/(double a) = delete;

    Real operator+=(char a) = delete;

    Real operator-=(char a) = delete;

    Real operator*=(char a) = delete;

    Real operator/=(char a) = delete;

    Real operator+=(char16_t a) = delete;

    Real operator-=(char16_t a) = delete;

    Real operator*=(char16_t a) = delete;

    Real operator/=(char16_t a) = delete;

    Real operator+=(char32_t a) = delete;

    Real operator-=(char32_t a) = delete;

    Real operator*=(char32_t a) = delete;

    Real operator/=(char32_t a) = delete;

    Real operator+=(int8_t a) = delete;

    Real operator-=(int8_t a) = delete;

    Real operator*=(int8_t a) = delete;

    Real operator/=(int8_t a) = delete;

    Real operator+=(int16_t a) = delete;

    Real operator-=(int16_t a) = delete;

    Real operator*=(int16_t a) = delete;

    Real operator/=(int16_t a) = delete;

    Real operator+=(int32_t a) = delete;

    Real operator-=(int32_t a) = delete;

    Real operator*=(int32_t a) = delete;

    Real operator/=(int32_t a) = delete;

    Real operator+=(int64_t a) = delete;

    Real operator-=(int64_t a) = delete;

    Real operator*=(int64_t a) = delete;

    Real operator/=(int64_t a) = delete;

    Real operator+=(float a) = delete;

    Real operator-=(float a) = delete;

    Real operator*=(float a) = delete;

    Real operator/=(float a) = delete;

    Real operator+=(double a) = delete;

    Real operator-=(double a) = delete;

    Real operator*=(double a) = delete;

    Real operator/=(double a) = delete;

    Real(float intVal) = delete;

    Real(double intVal) = delete;


    bool operator==(const Real &b) const {
        return mRaw == b.mRaw;
    }

    bool operator!=(const Real &b) const {
        return mRaw != b.mRaw;
    }

    bool operator<(const Real &b) const {
        return mRaw < b.mRaw;
    }

    bool operator>(const Real &b) const {
        return mRaw > b.mRaw;
    }

    bool operator<=(const Real &b) const {
        return mRaw <= b.mRaw;
    }

    bool operator>=(const Real &b) const {
        return mRaw >= b.mRaw;
    }

    explicit operator double() const {
        return (double) (mRaw >> Cf) + (mRaw & f_mask) / (double) f_range;
    }

    static constexpr data_t doubleToData(double f) {
        return f * (data_t(1u) << Cf);
    }

    static constexpr Real PI() {
        Real a;
        a.mRaw = doubleToData(3.1415926535897932);
        return a;
    }

    static constexpr Real HALF_PI() { return PI() / Real(2); }

    static constexpr Real TWO_PI() { return PI() * Real(2); }

    static constexpr Real E() {
        Real a;
        a.mRaw = doubleToData(2.7182818284590452);
        return a;
    }

    static Real fmod(const Real &a, const Real &b) {
        Real r;
        r.mRaw = a.mRaw % b.mRaw;
        return r;
    }

    static Real abs(const Real &a) {
        Real r = (a >= Real(0)) ? a : -a;
        return r;
    }

    static Real sin(const Real a) {
        Real x = Real::fmod(a, Real::TWO_PI());
        x = x / Real::HALF_PI();
        if (x < Real(0))
            x += Real(4);
        int sign = +1;
        if (x > Real(2)) {
            sign = -1;
            x -= Real(2);
        }

        if (x > Real(1)) {
            x = Real(2) - x;
        }

        Real x2 = x * x;
        Real bb =
                Real(sign) * x * (Real::PI() - x2 * (Real::TWO_PI() - Real(5) - x2 * (Real::PI() - Real(3)))) / Real(2);
        return bb;
    }

    static Real cos(const Real &a) {
        return sin(Real::HALF_PI() + a);
    }

    static Real tan(const Real &a) {
        Real cx = cos(a);
        Real c2 = abs(cx);
        assert(c2.mRaw > 1);
        return sin(a) / cx;
    }


    static Real atan(const Real &x) {
        if (x < Real(0)) {
            return -atan(-x);
        }

        if (x > Real(1)) {
            return Real::HALF_PI() - atan(Real(1) / x);
        }

        constexpr auto fA = Real::doubleToData(0.0776509570923569);
        constexpr auto fB = Real::doubleToData(-0.287434475393028);
        constexpr auto fC = Real::doubleToData(PI() / Real(4) - fA - fB);

        const auto xx = x * x;
        return ((fA * xx + fB) * xx + fC) * x;
    }

    static Real asin(const Real &x) {
        assert(x >= Real(-1) && x <= Real(+1));

        const auto yy = Real(1) - x * x;
        if (yy == Real(0)) {
            return copysign(Real::HALF_PI(), x);
        }
        return atan(x / sqrt(yy));
    }

    static Real acos(const Real &x) {
        assert(x >= Real(-1) && x <= Real(+1));

        if (x == Real(-1)) {
            return Real::PI();
        }
        const auto yy = Real(1) - x * x;
        return Real(2) * atan(sqrt(yy) / (Real(1) + x));
    }

    static Real atan2(const Real &x, const Real &y) {
        if (x == Real(0)) {
            assert(y != Real(0));
            return (y > Real(0)) ? Real::HALF_PI() : -Real::HALF_PI();
        }
        auto ret = atan(y / x);
        if (x < Real(0)) {
            return (y >= Real(0)) ? ret + Real::PI() : ret - Real::PI();
        }
        return ret;
    }

    //stupid version
    static Real pow(const Real &x, int y) {
        assert(y > 0);
        if(y == 0)
            return Real(1);
        if(y == 1)
            return x;
        Real r = x;
        for(int i = 0; i < y - 1; i++)
        {
            r *= x;
        }
        return r;
    }

};


#endif //UNTITLED_REAL_H
