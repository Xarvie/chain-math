# chain-math

chain-math is a fast, simple and safe fixed-point library.

it provides the same function interface as the standard <cmath.h>, so that you can easily refactor the old code.

It's written in the modern C++ 20 standard, so compiler required GCC >= 10.1 or clang 10.0+, VS2019 16.7 above.

### Quick start:

Copy the file Real.h to your project and insert code:
``` cpp
int main() {
    Real r = "1234567.8987654321E2"_r;
    r /= 4567_r;
    r *= Real::PI();
    r += Real::HALF_PI();
    r -= Real::E();
    r *= 10000;
    r = -r;
    r = Real::fmod(r, 12345678_r);
    r = Real::abs(r);//9729069.047150019556284
    std::cout <<
              "data:" << r.data() <<"\n" <<
              "double:"<< static_cast<double>(r) << std::endl;

    return 0;
}
```
Running results： 
```
data:41786033378035216
double:9729069.047150019556284
```
