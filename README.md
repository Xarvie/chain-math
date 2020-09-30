# chain-math

chain-math is a fast, simple and safe fixed-point library.

it provides the same function interface as the standard C <math.h>, so that you can easily refactor the old code.

It's written in the modern C++ 20 standard, compiler required GCC >= 10.1 or clang 10.0+, VS2019 16.7 above.

### Quick start:

Copy the file Real.h to your project and insert code:
``` cpp
#include <iostream>
#include <iomanip>
#include <Real.h>

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Real r = "1234567.8987654321E2"_r;
    r /= 4567_r;
    r *= Real::PI();
    r += Real::HALF_PI();
    r -= Real::E();
    r *= 10000;
    r = -r;
    r = Real::fmod(r, 12345678_r);
    r = Real::abs(r);
    r = Real::sin(r);
    r *= 10000000;
    r = Real::cos(r);
    r *= 10000000;
    r = Real::tan(r);
    r *= 10000000;
    r = Real::fmod(Real::abs(r), 1);
    r = Real::asin(r);
    r *= 10000000;
    r = Real::fmod(Real::abs(r), 1);
    r = Real::acos(r);
    r *= 10000000;
    r = Real::fmod(Real::abs(r), 1);
    r = Real::atan(r);
    r *= 10000000;
    r = Real::fmod(Real::abs(r), 1);
    r = Real::atan2(r, "0.5"_r);
    r = Real::atan2(r, "0.5"_r);
    r = Real::pownf(r, r==0?0:-2);
    r = Real::pow("1.4"_r, "5.6"_r);
    r = Real::exp(r);
    r = Real::exp2(r);
    r /= 10000;
    r = Real::expm1(r);
    r = Real::log2(r);
    r = Real::log(r);
    r = Real::log10(r);
    r = Real::log1p(r);
    r *= 100;
    r = Real::sqrt(r);


    std::cout <<
              "data:" << r.data() <<"\n" <<
              "double:"<< static_cast<double>(r) << std::endl;
    //data:25669275131
    //double:5.976593850878999

    return 0;
}
```
Running results： 
```
data:25669275131
double:5.976593850878999
```
