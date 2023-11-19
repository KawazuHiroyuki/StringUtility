#include "Test.h"

#include <iostream>
#include "StringEx.h"

void Test002() {
    std::cout << NumberTextAlternaor{}.countPositiveSign("") << std::endl;
    std::cout << NumberTextAlternaor{}.countPositiveSign("0123456+0123456@0123456++@@") << std::endl;
    std::cout << NumberTextAlternaor{}.setPositiveSign("@").countPositiveSign("0123456+0123456@0123456++@@") << std::endl;
    std::cout << NumberTextAlternaor{}.setPositiveSign("@@").countPositiveSign("0@@1234560123456@0123456@@") << std::endl;

    std::cout << NumberTextAlternaor{}.countNegativeSign("") << std::endl;
    std::cout << NumberTextAlternaor{}.countNegativeSign("0123456-0123456@0123456--@@") << std::endl;
    std::cout << NumberTextAlternaor{}.setNegativeSign("@").countNegativeSign("0123456+0123456@0123456--@@") << std::endl;
    std::cout << NumberTextAlternaor{}.setNegativeSign("@@").countNegativeSign("0@@1234560123456@0123456@@") << std::endl;

    std::cout << NumberTextAlternaor{}.countZeroSign("") << std::endl;
    std::cout << NumberTextAlternaor{}.countZeroSign("0123456-0123456@0123456±±@@") << std::endl;
    std::cout << NumberTextAlternaor{}.setZeroSign("±").countZeroSign("0123456±0123456@0123456±±@@") << std::endl;

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

    std::cout << StringEx::validateSingPartNumberText("", NumberTextAlternaor{}) << std::endl;
    std::cout << StringEx::validateSingPartNumberText("+", NumberTextAlternaor{}) << std::endl;
    std::cout << StringEx::validateSingPartNumberText("＋", NumberTextAlternaor{}.setPositiveSign("＋")) << std::endl;
    std::cout << StringEx::validateSingPartNumberText("-", NumberTextAlternaor{}) << std::endl;
    std::cout << StringEx::validateSingPartNumberText("－", NumberTextAlternaor{}.setNegativeSign("－")) << std::endl;
    std::cout << StringEx::validateSingPartNumberText("±", NumberTextAlternaor{}.setZeroSign("±")) << std::endl;
    std::cout << StringEx::validateSingPartNumberText("+1", NumberTextAlternaor{}) << std::endl;
    std::cout << StringEx::validateSingPartNumberText("＋1", NumberTextAlternaor{}.setPositiveSign("＋")) << std::endl;
    std::cout << StringEx::validateSingPartNumberText("-2", NumberTextAlternaor{}) << std::endl;
    std::cout << StringEx::validateSingPartNumberText("－2", NumberTextAlternaor{}.setNegativeSign("－")) << std::endl;
    std::cout << StringEx::validateSingPartNumberText("±0", NumberTextAlternaor{}.setZeroSign("±")) << std::endl;
    std::cout << StringEx::validateSingPartNumberText("±0.0", NumberTextAlternaor{}.setZeroSign("±")) << std::endl;

    std::cout << StringEx::validateSingPartNumberText("±3", NumberTextAlternaor{}.setZeroSign("±")) << std::endl;

    std::cout << StringEx::validateSingPartNumberText("4+", NumberTextAlternaor{}) << std::endl;
    std::cout << StringEx::validateSingPartNumberText("4＋", NumberTextAlternaor{}.setPositiveSign("＋")) << std::endl;
    std::cout << StringEx::validateSingPartNumberText("5-", NumberTextAlternaor{}) << std::endl;
    std::cout << StringEx::validateSingPartNumberText("5－", NumberTextAlternaor{}.setNegativeSign("－")) << std::endl;
    std::cout << StringEx::validateSingPartNumberText("6±", NumberTextAlternaor{}.setZeroSign("±")) << std::endl;

    std::cout << StringEx::validateNumberPartNumberText("", NumberTextAlternaor{}) << std::endl;
    std::cout << StringEx::validateNumberPartNumberText("A", NumberTextAlternaor{}) << std::endl;
    std::cout << StringEx::validateNumberPartNumberText("A10", NumberTextAlternaor{}) << std::endl;
    std::cout << StringEx::validateNumberPartNumberText("10A", NumberTextAlternaor{}) << std::endl;

    std::cout << StringEx::validateNumberPartNumberText("10", NumberTextAlternaor{}) << std::endl;
    std::cout << StringEx::validateNumberPartNumberText("10.5", NumberTextAlternaor{}) << std::endl;
    std::cout << StringEx::validateNumberPartNumberText("+10", NumberTextAlternaor{}) << std::endl;
    std::cout << StringEx::validateNumberPartNumberText("+10.5", NumberTextAlternaor{}) << std::endl;
    std::cout << StringEx::validateNumberPartNumberText("＋10", NumberTextAlternaor{}.setPositiveSign("＋")) << std::endl;
    std::cout << StringEx::validateNumberPartNumberText("＋10.5", NumberTextAlternaor{}.setPositiveSign("＋")) << std::endl;
    std::cout << StringEx::validateNumberPartNumberText("-10", NumberTextAlternaor{}) << std::endl;
    std::cout << StringEx::validateNumberPartNumberText("-10.5", NumberTextAlternaor{}) << std::endl;
    std::cout << StringEx::validateNumberPartNumberText("－10", NumberTextAlternaor{}.setPositiveSign("－")) << std::endl;
    std::cout << StringEx::validateNumberPartNumberText("－10.5", NumberTextAlternaor{}.setPositiveSign("－")) << std::endl;
    std::cout << StringEx::validateNumberPartNumberText("0", NumberTextAlternaor{}) << std::endl;
    std::cout << StringEx::validateNumberPartNumberText("0.0", NumberTextAlternaor{}) << std::endl;
    std::cout << StringEx::validateNumberPartNumberText("-0", NumberTextAlternaor{}) << std::endl;
    std::cout << StringEx::validateNumberPartNumberText("-0.0", NumberTextAlternaor{}) << std::endl;
    std::cout << StringEx::validateNumberPartNumberText("±0.0", NumberTextAlternaor{}.setZeroSign("±")) << std::endl;
    std::cout << StringEx::validateNumberPartNumberText("nan", NumberTextAlternaor{}) << std::endl;
    std::cout << StringEx::validateNumberPartNumberText("ＮＡＮ", NumberTextAlternaor{}.setNan("ＮＡＮ")) << std::endl;
    std::cout << StringEx::validateNumberPartNumberText("inf", NumberTextAlternaor{}) << std::endl;
    std::cout << StringEx::validateNumberPartNumberText("+inf", NumberTextAlternaor{}) << std::endl;
    std::cout << StringEx::validateNumberPartNumberText("-inf", NumberTextAlternaor{}) << std::endl;
    std::cout << StringEx::validateNumberPartNumberText("ｉｎｆ", NumberTextAlternaor{}.setInfinity("ｉｎｆ")) << std::endl;
    std::cout << StringEx::validateNumberPartNumberText("10．5", NumberTextAlternaor{}.setPoint("．")) << std::endl;

    std::cout << StringEx::isPositiveNumberText("1", NumberTextAlternaor{}) << std::endl;
    std::cout << StringEx::isPositiveNumberText("+1", NumberTextAlternaor{}) << std::endl;
    std::cout << StringEx::isPositiveNumberText("＋1", NumberTextAlternaor{}.setPositiveSign("＋")) << std::endl;
    std::cout << StringEx::isPositiveNumberText("10．5", NumberTextAlternaor{}.setPoint("．")) << std::endl;

    std::cout << StringEx::isPositiveNumberText("nan", NumberTextAlternaor{}) << std::endl;
    std::cout << StringEx::isPositiveNumberText("ＮＡＮ", NumberTextAlternaor{}.setNan("ＮＡＮ")) << std::endl;

    std::cout << StringEx::isPositiveNumberText("inf", NumberTextAlternaor{}) << std::endl;
    std::cout << StringEx::isPositiveNumberText("+inf", NumberTextAlternaor{}) << std::endl;
    std::cout << StringEx::isPositiveNumberText("ｉｎｆ", NumberTextAlternaor{}.setInfinity("ｉｎｆ")) << std::endl;

    std::cout << StringEx::isNegativeNumberText("-2", NumberTextAlternaor{}) << std::endl;
    std::cout << StringEx::isNegativeNumberText("－2", NumberTextAlternaor{}.setNegativeSign("－")) << std::endl;
    std::cout << StringEx::isNegativeNumberText("-10．5", NumberTextAlternaor{}.setPoint("．")) << std::endl;

    std::cout << StringEx::isNegativeNumberText("nan", NumberTextAlternaor{}) << std::endl;
    std::cout << StringEx::isNegativeNumberText("ＮＡＮ", NumberTextAlternaor{}.setNan("ＮＡＮ")) << std::endl;

    std::cout << StringEx::isNegativeNumberText("-inf", NumberTextAlternaor{}) << std::endl;
    std::cout << StringEx::isNegativeNumberText("－ｉｎｆ", NumberTextAlternaor{}.setInfinity("ｉｎｆ").setNegativeSign("－")) << std::endl;

    std::cout << StringEx::isPositiveNumberText("±0", NumberTextAlternaor{}.setZeroSign("±")) << std::endl;
    std::cout << StringEx::isPositiveNumberText("±0.0", NumberTextAlternaor{}.setZeroSign("±")) << std::endl;

    //std::cout << StringEx::isPositiveNumberText("±3", NumberTextAlternaor{}.setZeroSign("±")) << std::endl;

    std::cout << StringEx::isInfinityNumberText("", {}) << std::endl;
    std::cout << StringEx::isInfinityNumberText("inf", {}) << std::endl;
    std::cout << StringEx::isInfinityNumberText(" inf ", {}) << std::endl;
    std::cout << StringEx::isInfinityNumberText("abc", {}) << std::endl;
    std::cout << StringEx::isInfinityNumberText("abc", NumberTextAlternaor{}.setInfinity("abc")) << std::endl;
    std::cout << StringEx::isInfinityNumberText("012", NumberTextAlternaor{}.setInfinity("012")) << std::endl;

    std::cout << StringEx::isInfinityNumberText("-inf", {}) << std::endl;
    std::cout << StringEx::isInfinityNumberText(" - inf ", {}) << std::endl;
    std::cout << StringEx::isInfinityNumberText("abc", {}) << std::endl;
    std::cout << StringEx::isInfinityNumberText("-abc", NumberTextAlternaor{}.setInfinity("abc")) << std::endl;
    std::cout << StringEx::isInfinityNumberText("-012", NumberTextAlternaor{}.setInfinity("012")) << std::endl;

    std::cout << StringEx::isNanNumberText("", {}) << std::endl;
    std::cout << StringEx::isNanNumberText("nan", {}) << std::endl;
    std::cout << StringEx::isNanNumberText(" nan  ", {}) << std::endl;
    std::cout << StringEx::isNanNumberText("abc", {}) << std::endl;
    std::cout << StringEx::isNanNumberText("abc", NumberTextAlternaor{}.setNan("abc")) << std::endl;
    std::cout << StringEx::isNanNumberText("012", NumberTextAlternaor{}.setNan("012")) << std::endl;

    std::cout << StringEx::deleteSignPartNumberText("+012", NumberTextAlternaor{}) << std::endl;
    std::cout << StringEx::deleteSignPartNumberText("-012", NumberTextAlternaor{}) << std::endl;
    std::cout << StringEx::deleteSignPartNumberText("＋012", NumberTextAlternaor{}.setPositiveSign("＋")) << std::endl;
    std::cout << StringEx::deleteSignPartNumberText("－012", NumberTextAlternaor{}.setNegativeSign("－")) << std::endl;
    std::cout << StringEx::deleteSignPartNumberText("±0", NumberTextAlternaor{}.setZeroSign("±")) << std::endl;
}
