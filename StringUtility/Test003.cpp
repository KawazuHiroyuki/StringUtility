#include "Test.h"

#include <iostream>

#include "SIPrefixUtility.h"
#include "BinaryPrefixUtility.h"

void Test003() {
    auto test1 = [](SIPrefix prefix) {
        std::cout << "====== Start: " << SIPrefixUtility::getName(prefix) << " =====" << std::endl;
        std::cout << " getText: " << SIPrefixUtility::getText(prefix) << std::endl;
        std::cout << " getValue: " << SIPrefixUtility::getValue(prefix) << std::endl;
        std::cout << " to: " << SIPrefixUtility::to(4200.0, prefix) << std::endl;
        std::cout << " to: " << SIPrefixUtility::to(4200, prefix) << std::endl;
        std::cout << "====== End: " << SIPrefixUtility::getName(prefix) << " =====" << std::endl;
    };

    test1(SIPrefix::Atto);
    test1(SIPrefix::Femto);
    test1(SIPrefix::Pico);
    test1(SIPrefix::Nano);
    test1(SIPrefix::Micro);
    test1(SIPrefix::Milli);
    test1(SIPrefix::Centi);
    test1(SIPrefix::Deci);
    test1(SIPrefix::Base);
    test1(SIPrefix::Deca);
    test1(SIPrefix::Hecto);
    test1(SIPrefix::Kilo);
    test1(SIPrefix::Mega);
    test1(SIPrefix::Giga);
    test1(SIPrefix::Tera);
    test1(SIPrefix::Peta);
    test1(SIPrefix::Exa);

    {
        auto b00 = SIPrefixUtility::readbable(0.00000000000000000000000000001);
        auto b01 = SIPrefixUtility::readbable(0.0000000000000000000000000001);
        auto b02 = SIPrefixUtility::readbable(0.000000000000000000000000001);
        auto b03 = SIPrefixUtility::readbable(0.00000000000000000000000001);
        auto b04 = SIPrefixUtility::readbable(0.0000000000000000000000001);
        auto b05 = SIPrefixUtility::readbable(0.000000000000000000000001);
        auto b06 = SIPrefixUtility::readbable(0.00000000000000000000001);
        auto b07 = SIPrefixUtility::readbable(0.0000000000000000000001);
        auto b08 = SIPrefixUtility::readbable(0.000000000000000000001);
        auto b09 = SIPrefixUtility::readbable(0.00000000000000000001);
        auto b10 = SIPrefixUtility::readbable(0.0000000000000000001);
        auto b11 = SIPrefixUtility::readbable(0.000000000000000001);
        auto b12 = SIPrefixUtility::readbable(0.00000000000000001);
        auto b13 = SIPrefixUtility::readbable(0.0000000000000001);
        auto b14 = SIPrefixUtility::readbable(0.000000000000001);
        auto b15 = SIPrefixUtility::readbable(0.00000000000001);
        auto b16 = SIPrefixUtility::readbable(0.0000000000001);
        auto b17 = SIPrefixUtility::readbable(0.000000000001);
        auto b18 = SIPrefixUtility::readbable(0.00000000001);
        auto b19 = SIPrefixUtility::readbable(0.0000000001);
        auto b20 = SIPrefixUtility::readbable(0.000000001);
        auto b21 = SIPrefixUtility::readbable(0.00000001);
        auto b22 = SIPrefixUtility::readbable(0.0000001);
        auto b23 = SIPrefixUtility::readbable(0.000001);
        auto b24 = SIPrefixUtility::readbable(0.00001);
        auto b25 = SIPrefixUtility::readbable(0.0001);
        auto b26 = SIPrefixUtility::readbable(0.001);
        auto b27 = SIPrefixUtility::readbable(0.01);
        auto b28 = SIPrefixUtility::readbable(0.1);
        auto b29 = SIPrefixUtility::readbable(0);
        auto bE = 0;
    }
    auto a00 = SIPrefixUtility::readbable(                        1);
    auto a01 = SIPrefixUtility::readbable(                       10);
    auto a02 = SIPrefixUtility::readbable(                      100);
    auto a03 = SIPrefixUtility::readbable(                    1'000);
    auto a04 = SIPrefixUtility::readbable(                   10'000);
    auto a05 = SIPrefixUtility::readbable(                  100'000);
    auto a06 = SIPrefixUtility::readbable(                1'000'000);
    auto a07 = SIPrefixUtility::readbable(               10'000'000);
    auto a08 = SIPrefixUtility::readbable(              100'000'000);
    auto a09 = SIPrefixUtility::readbable(             1'000'000'000);
    auto a10 = SIPrefixUtility::readbable(            10'000'000'000);
    auto a11 = SIPrefixUtility::readbable(           100'000'000'000);
    auto a12 = SIPrefixUtility::readbable(         1'000'000'000'000);
    auto a13 = SIPrefixUtility::readbable(     1'000'000'000'000'000);
    auto a14 = SIPrefixUtility::readbable( 1'000'000'000'000'000'000);
    auto a15 = SIPrefixUtility::readbable(10'000'000'000'000'000'000);

    auto test2 = [](BinaryPrefix prefix) {
        std::cout << "====== Start: " << BinaryPrefixUtility::getName(prefix) << " =====" << std::endl;
        std::cout << " getText: " << BinaryPrefixUtility::getText(prefix) << std::endl;
        std::cout << " getSIPrefixLikeText: " << BinaryPrefixUtility::getSIPrefixLikeText(prefix) << std::endl;
        std::cout << " getValue: " << BinaryPrefixUtility::getValue(prefix) << std::endl;
        std::cout << " to: " << BinaryPrefixUtility::to(2048.5, prefix) << std::endl;
        std::cout << " to: " << BinaryPrefixUtility::to(2048, prefix) << std::endl;
        std::cout << "====== End: " << BinaryPrefixUtility::getName(prefix) << " =====" << std::endl;
    };

    test2(BinaryPrefix::Base);
    test2(BinaryPrefix::Kibi);
    test2(BinaryPrefix::Mebi);
    test2(BinaryPrefix::Gibi);
    test2(BinaryPrefix::Tebi);
    test2(BinaryPrefix::Pebi);
    test2(BinaryPrefix::Exbi);
}
