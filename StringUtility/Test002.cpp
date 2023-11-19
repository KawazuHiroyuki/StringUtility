#include "Test.h"

#include <iostream>
#include "StringEx.h"

void Test002() {
    std::cout << StringEx::count("abcdefgabcdefgabcdefg", "cd") << std::endl;
    std::cout << StringEx::count("0123456789012345678901234567890", "1234567890") << std::endl;
    std::cout << StringEx::containts("abcdefgabcdefgabcdefg", "cd") << std::endl;
    std::cout << StringEx::containts("abcdefgabcdefgabcdefg", "01") << std::endl;
    std::cout << StringEx::replace("abcdefgabcdefgabcdefg", "cd", "0123") << std::endl;
    std::cout << StringEx::trimAll("   a b cdef g a bcde  fga bcdefg    ") << std::endl;

    std::cout << StringEx::getDefaultPositiveSignNumberText() << std::endl;
    std::cout << StringEx::getDefaultNegativeSignNumberText() << std::endl;
    std::cout << StringEx::getDefaultPointNumberText() << std::endl;
    std::cout << StringEx::getDefaultZeroNumberText() << std::endl;
    std::cout << StringEx::getDefaultInfinityNumberText() << std::endl;
    std::cout << StringEx::getDefaultNanNumberText() << std::endl;

    std::cout << StringEx::isInfinityNumberText("", {}) << std::endl;
    std::cout << StringEx::isInfinityNumberText("inf", {}) << std::endl;
    std::cout << StringEx::isInfinityNumberText(" inf ", {}) << std::endl;
    std::cout << StringEx::isInfinityNumberText("abc", {}) << std::endl;
    std::cout << StringEx::isInfinityNumberText("abc", NumberTextAlternaor{}.setInfinity("abc").setInfinity("012")) << std::endl;
    std::cout << StringEx::isInfinityNumberText("012", NumberTextAlternaor{}.setInfinity("abc").setInfinity("012")) << std::endl;

    std::cout << StringEx::isInfinityNumberText("-inf", {}) << std::endl;
    std::cout << StringEx::isInfinityNumberText(" - inf ", {}) << std::endl;
    std::cout << StringEx::isInfinityNumberText("abc", {}) << std::endl;
    std::cout << StringEx::isInfinityNumberText("-abc", NumberTextAlternaor{}.setInfinity("abc").setInfinity("012")) << std::endl;
    std::cout << StringEx::isInfinityNumberText("-012", NumberTextAlternaor{}.setInfinity("abc").setInfinity("012")) << std::endl;

    std::cout << StringEx::isNanNumberText("", {}) << std::endl;
    std::cout << StringEx::isNanNumberText("nan", {}) << std::endl;
    std::cout << StringEx::isNanNumberText(" nan  ", {}) << std::endl;
    std::cout << StringEx::isNanNumberText("abc", {}) << std::endl;
    std::cout << StringEx::isNanNumberText("abc", NumberTextAlternaor{}.setNan("abc").setNan("012")) << std::endl;
    std::cout << StringEx::isNanNumberText("012", NumberTextAlternaor{}.setNan("abc").setNan("012")) << std::endl;
}
