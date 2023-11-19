#include "Test.h"

#include <iostream>
#include <cassert>
#include "StringEx.h"

void Test002() {
    assert(NumberTextAlternaor{}.countPositiveSign("") == 0);
    assert(NumberTextAlternaor{}.countPositiveSign("0123456+0123456@0123456++@@") == 3);
    assert(NumberTextAlternaor{}.setPositiveSign("@").countPositiveSign("0123456+0123456@0123456++@@") == 6);
    assert(NumberTextAlternaor{}.setPositiveSign("@@").countPositiveSign("0@@1234560123456@0123456@@") == 2);

    assert(NumberTextAlternaor{}.countNegativeSign("") == 0);
    assert(NumberTextAlternaor{}.countNegativeSign("0123456-0123456@0123456--@@") == 3);
    assert(NumberTextAlternaor{}.setNegativeSign("@").countNegativeSign("0123456+0123456@0123456--@@") == 5);
    assert(NumberTextAlternaor{}.setNegativeSign("@@").countNegativeSign("0@@1234560123456@0123456@@") == 2);

    assert(NumberTextAlternaor{}.countZeroSign("") == 0);
    assert(NumberTextAlternaor{}.countZeroSign("0123456-0123456@0123456±±@@") == 0);
    assert(NumberTextAlternaor{}.setZeroSign("±").countZeroSign("0123456±0123456@0123456±±@@") == 3);

    assert(StringEx::count("", "cd") == 0);
    assert(StringEx::count("abcdefgabcdefgabcdefg", "") == 0);
    assert(StringEx::count("abcdefgabcdefgabcdefg", "cd") == 3);
    assert(StringEx::count("0123456789012345678901234567890", "1234567890") == 3);

    assert(StringEx::containts("", "cd") == false);
    assert(StringEx::containts("abcdefgabcdefgabcdefg", "") == false);
    assert(StringEx::containts("abcdefgabcdefgabcdefg", "cd") == true);
    assert(StringEx::containts("abcdefgabcdefgabcdefg", "01") == false);

    assert(StringEx::replace("abcdefgabcdefgabcdefg", "cd", "0123") == "ab0123efgab0123efgab0123efg");
    assert(StringEx::trimAll("   a b cdef g a bcde  fga bcdefg    ") == "abcdefgabcdefgabcdefg");

    assert(StringEx::getDefaultPositiveSignNumberText() == "+");
    assert(StringEx::getDefaultNegativeSignNumberText() == "-");
    assert(StringEx::getDefaultPointNumberText() == ".");
    assert(StringEx::getDefaultZeroNumberText() == "0");
    assert(StringEx::getDefaultInfinityNumberText() == "inf");
    assert(StringEx::getDefaultNanNumberText() == "nan");

    assert(StringEx::validateNumberText("", NumberTextAlternaor{}) == false);
    assert(StringEx::validateNumberText("+", NumberTextAlternaor{}) == false);
    assert(StringEx::validateNumberText("＋", NumberTextAlternaor{}.setPositiveSign("＋")) == false);
    assert(StringEx::validateNumberText("-", NumberTextAlternaor{}) == false);
    assert(StringEx::validateNumberText("－", NumberTextAlternaor{}.setNegativeSign("－")) == false);
    assert(StringEx::validateNumberText("±", NumberTextAlternaor{}.setZeroSign("±")) == false);

    assert(StringEx::validateNumberText("1", NumberTextAlternaor{}) == true);
    assert(StringEx::validateNumberText("+1", NumberTextAlternaor{}) == true);
    assert(StringEx::validateNumberText("＋1", NumberTextAlternaor{}.setPositiveSign("＋")) == true);
    assert(StringEx::validateNumberText("-2", NumberTextAlternaor{}) == true);
    assert(StringEx::validateNumberText("－2", NumberTextAlternaor{}.setNegativeSign("－")) == true);
    assert(StringEx::validateNumberText("±0", NumberTextAlternaor{}.setZeroSign("±")) == true);
    assert(StringEx::validateNumberText("±0.0", NumberTextAlternaor{}.setZeroSign("±")) == true);

    assert(StringEx::validateNumberText("++1", NumberTextAlternaor{}) == false);
    assert(StringEx::validateNumberText("+-1", NumberTextAlternaor{}) == false);
    assert(StringEx::validateNumberText("＋＋1", NumberTextAlternaor{}.setPositiveSign("＋")) == false);
    assert(StringEx::validateNumberText("＋－1", NumberTextAlternaor{}.setPositiveSign("＋").setNegativeSign("－")) == false);
    assert(StringEx::validateNumberText("--2", NumberTextAlternaor{}) == false);
    assert(StringEx::validateNumberText("-+2", NumberTextAlternaor{}) == false);
    assert(StringEx::validateNumberText("－－2", NumberTextAlternaor{}.setNegativeSign("－")) == false);
    assert(StringEx::validateNumberText("－＋2", NumberTextAlternaor{}.setNegativeSign("－").setPositiveSign("＋")) == false);
    assert(StringEx::validateNumberText("±±0", NumberTextAlternaor{}.setZeroSign("±")) == false);
    assert(StringEx::validateNumberText("±±0.0", NumberTextAlternaor{}.setZeroSign("±")) == false);

    assert(StringEx::validateNumberText("±3", NumberTextAlternaor{}.setZeroSign("±")) == true);

    assert(StringEx::validateNumberText("4+", NumberTextAlternaor{}) == false);
    assert(StringEx::validateNumberText("4＋", NumberTextAlternaor{}.setPositiveSign("＋")) == false);
    assert(StringEx::validateNumberText("5-", NumberTextAlternaor{}) == false);
    assert(StringEx::validateNumberText("5－", NumberTextAlternaor{}.setNegativeSign("－")) == false);
    assert(StringEx::validateNumberText("6±", NumberTextAlternaor{}.setZeroSign("±")) == false);

    assert(StringEx::validateNumberText("", NumberTextAlternaor{}) == false);
    assert(StringEx::validateNumberText("A", NumberTextAlternaor{}) == false);
    assert(StringEx::validateNumberText("A10", NumberTextAlternaor{}) == false);
    assert(StringEx::validateNumberText("10A", NumberTextAlternaor{}) == true); // TODO false

    assert(StringEx::validateNumberText("10", NumberTextAlternaor{}) == true);
    assert(StringEx::validateNumberText("10.5", NumberTextAlternaor{}) == true);
    assert(StringEx::validateNumberText("+10", NumberTextAlternaor{}) == true);
    assert(StringEx::validateNumberText("+10.5", NumberTextAlternaor{}) == true);
    assert(StringEx::validateNumberText("＋10", NumberTextAlternaor{}.setPositiveSign("＋")) == true);
    assert(StringEx::validateNumberText("＋10.5", NumberTextAlternaor{}.setPositiveSign("＋")) == true);
    assert(StringEx::validateNumberText("-10", NumberTextAlternaor{}) == true);
    assert(StringEx::validateNumberText("-10.5", NumberTextAlternaor{}) == true);
    assert(StringEx::validateNumberText("－10", NumberTextAlternaor{}.setPositiveSign("－")) == true);
    assert(StringEx::validateNumberText("－10.5", NumberTextAlternaor{}.setPositiveSign("－")) == true);
    assert(StringEx::validateNumberText("0", NumberTextAlternaor{}) == true);
    assert(StringEx::validateNumberText("0.0", NumberTextAlternaor{}) == true);
    assert(StringEx::validateNumberText("-0", NumberTextAlternaor{}) == true);
    assert(StringEx::validateNumberText("-0.0", NumberTextAlternaor{}) == true);
    assert(StringEx::validateNumberText("±0.0", NumberTextAlternaor{}.setZeroSign("±")) == true);
    assert(StringEx::validateNumberText("nan", NumberTextAlternaor{}) == true);
    assert(StringEx::validateNumberText("ＮＡＮ", NumberTextAlternaor{}.setNan("ＮＡＮ")) == true);
    assert(StringEx::validateNumberText("inf", NumberTextAlternaor{}) == true);
    assert(StringEx::validateNumberText("+inf", NumberTextAlternaor{}) == true);
    assert(StringEx::validateNumberText("-inf", NumberTextAlternaor{}) == true);
    assert(StringEx::validateNumberText("ｉｎｆ", NumberTextAlternaor{}.setInfinity("ｉｎｆ")) == true);
    assert(StringEx::validateNumberText("10．5", NumberTextAlternaor{}.setPoint("．")) == true);

    assert(StringEx::isPositiveNumberText("1", NumberTextAlternaor{}) == true);
    assert(StringEx::isPositiveNumberText("+1", NumberTextAlternaor{}) == true);
    assert(StringEx::isPositiveNumberText("＋1", NumberTextAlternaor{}.setPositiveSign("＋")) == true);
    assert(StringEx::isPositiveNumberText("10．5", NumberTextAlternaor{}.setPoint("．")) == true);

    assert(StringEx::isPositiveNumberText("nan", NumberTextAlternaor{}) == false);
    assert(StringEx::isPositiveNumberText("ＮＡＮ", NumberTextAlternaor{}.setNan("ＮＡＮ")) == false);

    assert(StringEx::isPositiveNumberText("inf", NumberTextAlternaor{}) == true);
    assert(StringEx::isPositiveNumberText("+inf", NumberTextAlternaor{}) == true);
    assert(StringEx::isPositiveNumberText("ｉｎｆ", NumberTextAlternaor{}.setInfinity("ｉｎｆ")) == true);

    assert(StringEx::isNegativeNumberText("-2", NumberTextAlternaor{}) == true);
    assert(StringEx::isNegativeNumberText("－2", NumberTextAlternaor{}.setNegativeSign("－")) == true);
    assert(StringEx::isNegativeNumberText("-10．5", NumberTextAlternaor{}.setPoint("．")) == true);

    assert(StringEx::isNegativeNumberText("nan", NumberTextAlternaor{}) == false);
    assert(StringEx::isNegativeNumberText("ＮＡＮ", NumberTextAlternaor{}.setNan("ＮＡＮ")) == false);

    assert(StringEx::isNegativeNumberText("-inf", NumberTextAlternaor{}) == true);
    assert(StringEx::isNegativeNumberText("－ｉｎｆ", NumberTextAlternaor{}.setInfinity("ｉｎｆ").setNegativeSign("－")) == true);

    assert(StringEx::isPositiveNumberText("±0", NumberTextAlternaor{}.setZeroSign("±")) == true);
    assert(StringEx::isPositiveNumberText("±0.0", NumberTextAlternaor{}.setZeroSign("±")) == true);

    assert(StringEx::isPositiveNumberText("±3", NumberTextAlternaor{}.setZeroSign("±")) == true);
    assert(StringEx::isNegativeNumberText("±3", NumberTextAlternaor{}.setZeroSign("±")) == false);

    assert(StringEx::isZeroNumberText("", NumberTextAlternaor{}) == false);

    assert(StringEx::isZeroNumberText("0", NumberTextAlternaor{}) == true);
    assert(StringEx::isZeroNumberText("0.0", NumberTextAlternaor{}) == true);
    assert(StringEx::isZeroNumberText("+0", NumberTextAlternaor{}) == true);
    assert(StringEx::isZeroNumberText("+0.0", NumberTextAlternaor{}) == true);
    assert(StringEx::isZeroNumberText("-0", NumberTextAlternaor{}) == true);
    assert(StringEx::isZeroNumberText("-0.0", NumberTextAlternaor{}) == true);
    assert(StringEx::isZeroNumberText("±0", NumberTextAlternaor{}.setZeroSign("±")) == true);
    assert(StringEx::isZeroNumberText("±0.0", NumberTextAlternaor{}.setZeroSign("±")) == true);

    assert(StringEx::isZeroNumberText("1", NumberTextAlternaor{}) == false);
    assert(StringEx::isZeroNumberText("0.1", NumberTextAlternaor{}) == false);
    assert(StringEx::isZeroNumberText("+1", NumberTextAlternaor{}) == false);
    assert(StringEx::isZeroNumberText("+0.1", NumberTextAlternaor{}) == false);
    assert(StringEx::isZeroNumberText("-1", NumberTextAlternaor{}) == false);
    assert(StringEx::isZeroNumberText("-1.0", NumberTextAlternaor{}) == false);
    assert(StringEx::isZeroNumberText("±1", NumberTextAlternaor{}.setZeroSign("±")) == false);
    assert(StringEx::isZeroNumberText("±0.1", NumberTextAlternaor{}.setZeroSign("±")) == false);

    assert(StringEx::isInfinityNumberText("", {}) == false);
    assert(StringEx::isInfinityNumberText("inf", {}) == true);
    assert(StringEx::isInfinityNumberText(" inf ", {}) == true);
    assert(StringEx::isInfinityNumberText("abc", {}) == false);
    assert(StringEx::isInfinityNumberText("abc", NumberTextAlternaor{}.setInfinity("abc")) == true);
    assert(StringEx::isInfinityNumberText("012", NumberTextAlternaor{}.setInfinity("012")) == true);

    assert(StringEx::isInfinityNumberText("-inf", {}) == true);
    assert(StringEx::isInfinityNumberText(" - inf ", {}) == true);
    assert(StringEx::isInfinityNumberText("abc", {}) == false);
    assert(StringEx::isInfinityNumberText("-abc", NumberTextAlternaor{}.setInfinity("abc")) == true);
    assert(StringEx::isInfinityNumberText("-012", NumberTextAlternaor{}.setInfinity("012")) == true);

    assert(StringEx::isNanNumberText("", {}) == false);

    assert(StringEx::isNanNumberText("nan", {}) == true);
    assert(StringEx::isNanNumberText(" nan  ", {}) == true);
    assert(StringEx::isNanNumberText("abc", {}) == false);
    assert(StringEx::isNanNumberText("abc", NumberTextAlternaor{}.setNan("abc")) == true);
    assert(StringEx::isNanNumberText("012", NumberTextAlternaor{}.setNan("012")) == true);

    assert(StringEx::isNumberText("", {}) == false);

    assert(StringEx::isNumberText("0", NumberTextAlternaor{}) == true);
    assert(StringEx::isNumberText("0.0", NumberTextAlternaor{}) == true);
    assert(StringEx::isNumberText("+0", NumberTextAlternaor{}) == true);
    assert(StringEx::isNumberText("+0.0", NumberTextAlternaor{}) == true);
    assert(StringEx::isNumberText("-0", NumberTextAlternaor{}) == true);
    assert(StringEx::isNumberText("-0.0", NumberTextAlternaor{}) == true);
    assert(StringEx::isNumberText("±0", NumberTextAlternaor{}.setZeroSign("±")) == true);
    assert(StringEx::isNumberText("±0.0", NumberTextAlternaor{}.setZeroSign("±")) == true);

    assert(StringEx::isNumberText("1", NumberTextAlternaor{}) == true);
    assert(StringEx::isNumberText("0.1", NumberTextAlternaor{}) == true);
    assert(StringEx::isNumberText("+1", NumberTextAlternaor{}) == true);
    assert(StringEx::isNumberText("+0.1", NumberTextAlternaor{}) == true);
    assert(StringEx::isNumberText("-1", NumberTextAlternaor{}) == true);
    assert(StringEx::isNumberText("-1.0", NumberTextAlternaor{}) == true);
    assert(StringEx::isNumberText("±1", NumberTextAlternaor{}.setZeroSign("±")) == true);
    assert(StringEx::isNumberText("±0.1", NumberTextAlternaor{}.setZeroSign("±")) == true);

    assert(StringEx::isNumberText("inf", {}) == true);
    assert(StringEx::isNumberText(" inf ", {}) == true);
    assert(StringEx::isNumberText("abc", {}) == false);
    assert(StringEx::isNumberText("abc", NumberTextAlternaor{}.setInfinity("abc")) == true);
    assert(StringEx::isNumberText("012", NumberTextAlternaor{}.setInfinity("012")) == true);

    assert(StringEx::isNumberText("-inf", {}) == true);
    assert(StringEx::isNumberText(" - inf ", {}) == true);
    assert(StringEx::isNumberText("abc", {}) == false);
    assert(StringEx::isNumberText("-abc", NumberTextAlternaor{}.setInfinity("abc")) == true);
    assert(StringEx::isNumberText("-012", NumberTextAlternaor{}.setInfinity("012")) == true);

    assert(StringEx::isNumberText("nan", {}) == true);
    assert(StringEx::isNumberText(" nan  ", {}) == true);
    assert(StringEx::isNumberText("abc", {}) == false);
    assert(StringEx::isNumberText("abc", NumberTextAlternaor{}.setNan("abc")) == true);
    assert(StringEx::isNumberText("012", NumberTextAlternaor{}.setNan("012")) == true);

    assert(StringEx::isNumberText("ABC", {}) == false);

    assert(StringEx::deleteSignPartNumberText("+012", NumberTextAlternaor{}) == "012");
    assert(StringEx::deleteSignPartNumberText("-012", NumberTextAlternaor{}) == "012");
    assert(StringEx::deleteSignPartNumberText("＋012", NumberTextAlternaor{}.setPositiveSign("＋")) == "012");
    assert(StringEx::deleteSignPartNumberText("－012", NumberTextAlternaor{}.setNegativeSign("－")) == "012");
    assert(StringEx::deleteSignPartNumberText("±0", NumberTextAlternaor{}.setZeroSign("±")) == "0");
}
