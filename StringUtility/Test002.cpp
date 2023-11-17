#include "Test.h"

#include <iostream>
#include "StringEx.h"

void Test002() {
    std::cout << StringEx::replace("abcdefgabcdefgabcdefg", "cd", "0123") << std::endl;
    std::cout << StringEx::trimAll("   a b cdef g a bcde  fga bcdefg    ") << std::endl;

    std::cout << StringEx::getDefaultPositiveSignNumberText() << std::endl;
    std::cout << StringEx::getDefaultNegativeSignNumberText() << std::endl;
    std::cout << StringEx::getDefaultPointNumberText() << std::endl;
    std::cout << StringEx::getDefaultZeroNumberText() << std::endl;
    std::cout << StringEx::getDefaultInfinityNumberText() << std::endl;
    std::cout << StringEx::getDefaultNanNumberText() << std::endl;
}
