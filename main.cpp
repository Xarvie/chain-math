#include <iostream>
#include <iomanip>
#include "Real.h"


int main() {
    std::cout <<  std::fixed << std::setprecision(9);

    std::cout << "PI = " << static_cast<double>(Real<>::PI()) << std::endl;
    std::cout << "E = " << static_cast<double>(Real<>::E()) << std::endl;

    //-10
    Real a = -10; std::cout << "a = " << static_cast<double>(a) << std::endl;

    //3
    Real b = 3; std::cout << "b = " << static_cast<double>(b) << std::endl;

    //-13
    Real c = a+b; std::cout << "-10 + 3 = " << static_cast<double>(c) << std::endl;

    //-7
    Real d = a-b; std::cout << "-10 - 3 = " << static_cast<double>(d) << std::endl;

    //-30
    Real e = a*b; std::cout << "-10 * 3 = " << static_cast<double>(e) << std::endl;

    //-3.33333
    Real f = a/b; std::cout << "-10 / 3 = " << static_cast<double>(f) << std::endl;

    //-0.33333
    Real g = Real<>::fmod(f,b); std::cout << "-3.333333 % 3 = "  << static_cast<double>(g) << std::endl;

    //0.33333
    Real h = Real<>::abs(g); std::cout << "|-0.33333| = "  << static_cast<double>(h) << std::endl;

    //0.8414
    Real i = Real<>::sin(Real(1)); std::cout << "Sin(1) = "  << static_cast<double>(i) << std::endl;

    //0.5403
    Real j = Real<>::cos(Real(1));; std::cout << "Cos(1) = "  << static_cast<double>(j) << std::endl;

    //1.5574
    Real k = Real<>::tan(Real(1)); std::cout << "tan(1) = "  << static_cast<double>(k) << std::endl;

    //8.0
    Real l = Real<>::pow(Real(2), 3); std::cout << "2^3 = "  << static_cast<double>(l) << std::endl;
    return 0;
}
