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

    assert(StringEx::split("", ".") == std::vector<std::string>({}));
    assert(StringEx::split("abcdefg.abcdefg.abcdefg", "") == std::vector<std::string>({ "abcdefg.abcdefg.abcdefg" }));
    assert(StringEx::split("a", ".") == std::vector<std::string>({ "a" }));
    assert(StringEx::split(".abcdefg.abcdefg.abcdefg", ".") == std::vector<std::string>({ "","abcdefg", "abcdefg", "abcdefg"}));
    assert(StringEx::split("abcdefg.abcdefg.abcdefg", ".") == std::vector<std::string>({ "abcdefg", "abcdefg", "abcdefg" }));
    assert(StringEx::split("abcdefg.abcdefg.abcdefg.", ".") == std::vector<std::string>({ "abcdefg", "abcdefg", "abcdefg",""}));

    assert(StringEx::replace("abcdefgabcdefgabcdefg", "cd", "0123") == "ab0123efgab0123efgab0123efg");
    assert(StringEx::trimAll("   a b cdef g a bcde  fga bcdefg    ") == "abcdefgabcdefgabcdefg");

    assert(StringEx::getDefaultPositiveSignNumberText() == "+");
    assert(StringEx::getDefaultNegativeSignNumberText() == "-");
    assert(StringEx::getDefaultPointNumberText() == ".");
    assert(StringEx::getDefaultZeroNumberText() == "0");
    assert(StringEx::getDefaultInfinityNumberText() == "inf");
    assert(StringEx::getDefaultNanNumberText() == "nan");

    //assert(StringEx::isZeroNumberText("", NumberTextAlternaor{}) == false);

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

    assert(StringEx::isNegativeZeroNumberText("0", NumberTextAlternaor{}) == false);
    assert(StringEx::isNegativeZeroNumberText("0.0", NumberTextAlternaor{}) == false);
    assert(StringEx::isNegativeZeroNumberText("+0", NumberTextAlternaor{}) == false);
    assert(StringEx::isNegativeZeroNumberText("+0.0", NumberTextAlternaor{}) == false);
    assert(StringEx::isNegativeZeroNumberText("-0", NumberTextAlternaor{}) == true);
    assert(StringEx::isNegativeZeroNumberText("-0.0", NumberTextAlternaor{}) == true);
    assert(StringEx::isNegativeZeroNumberText("±0", NumberTextAlternaor{}.setZeroSign("±")) == false);
    assert(StringEx::isNegativeZeroNumberText("±0.0", NumberTextAlternaor{}.setZeroSign("±")) == false);

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

    //assert(StringEx::isInfinityNumberText("", {}) == false);
    assert(StringEx::isInfinityNumberText("inf", {}) == true);
    assert(StringEx::isInfinityNumberText(" inf ", {}) == true);
    //assert(StringEx::isInfinityNumberText("abc", {}) == false);
    assert(StringEx::isInfinityNumberText("abc", NumberTextAlternaor{}.setInfinity("abc")) == true);
    assert(StringEx::isInfinityNumberText("012", NumberTextAlternaor{}.setInfinity("012")) == true);

    assert(StringEx::isInfinityNumberText("-inf", {}) == true);
    assert(StringEx::isInfinityNumberText(" - inf ", {}) == true);
    //assert(StringEx::isInfinityNumberText("abc", {}) == false);
    assert(StringEx::isInfinityNumberText("-abc", NumberTextAlternaor{}.setInfinity("abc")) == true);
    assert(StringEx::isInfinityNumberText("-012", NumberTextAlternaor{}.setInfinity("012")) == true);

    //assert(StringEx::isNanNumberText("", {}) == false);

    assert(StringEx::isNanNumberText("nan", {}) == true);
    assert(StringEx::isNanNumberText(" nan  ", {}) == true);
    //assert(StringEx::isNanNumberText("abc", {}) == false);
    assert(StringEx::isNanNumberText("abc", NumberTextAlternaor{}.setNan("abc")) == true);
    assert(StringEx::isNanNumberText("012", NumberTextAlternaor{}.setNan("012")) == true);

    assert(StringEx::isNumberText("", {}) == false);
    assert(StringEx::isNumberText("ABC", {}) == false);

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

    assert(StringEx::deleteSignPartNumberText("+012", NumberTextAlternaor{}) == "012");
    assert(StringEx::deleteSignPartNumberText("-012", NumberTextAlternaor{}) == "012");
    assert(StringEx::deleteSignPartNumberText("＋012", NumberTextAlternaor{}.setPositiveSign("＋")) == "012");
    assert(StringEx::deleteSignPartNumberText("－012", NumberTextAlternaor{}.setNegativeSign("－")) == "012");
    assert(StringEx::deleteSignPartNumberText("±0", NumberTextAlternaor{}.setZeroSign("±")) == "0");


    //assert(StringEx::normalizeNumberText("", false, {}) == "");
    //assert(StringEx::normalizeNumberText("ABC", false, {}) == "");

    assert(StringEx::normalizeNumberText("0", false, NumberTextAlternaor{}) == "0");
    assert(StringEx::normalizeNumberText("0.0", false, NumberTextAlternaor{}) == "0.0");
    assert(StringEx::normalizeNumberText("+0", false, NumberTextAlternaor{}) == "0");
    assert(StringEx::normalizeNumberText("+0.0", false, NumberTextAlternaor{}) == "0.0");
    assert(StringEx::normalizeNumberText("-0", false, NumberTextAlternaor{}) == "0");
    assert(StringEx::normalizeNumberText("-0.0", false, NumberTextAlternaor{}) == "0.0");
    assert(StringEx::normalizeNumberText("±0", false, NumberTextAlternaor{}.setZeroSign("±")) == "0");
    assert(StringEx::normalizeNumberText("±0.0", false, NumberTextAlternaor{}.setZeroSign("±")) == "0.0");

    assert(StringEx::normalizeNumberText("1", false, NumberTextAlternaor{}) == "1");
    assert(StringEx::normalizeNumberText("0.1", false, NumberTextAlternaor{}) == "0.1");
    assert(StringEx::normalizeNumberText("+1", false, NumberTextAlternaor{}) == "1");
    assert(StringEx::normalizeNumberText("+0.1", false, NumberTextAlternaor{}) == "0.1");
    assert(StringEx::normalizeNumberText("-1", false, NumberTextAlternaor{}) == "-1");
    assert(StringEx::normalizeNumberText("-1.0", false, NumberTextAlternaor{}) == "-1.0");
    assert(StringEx::normalizeNumberText("±1", false, NumberTextAlternaor{}.setZeroSign("±")) == "1");
    assert(StringEx::normalizeNumberText("±0.1", false, NumberTextAlternaor{}.setZeroSign("±")) == "0.1");

    assert(StringEx::normalizeNumberText("inf", false, NumberTextAlternaor{}) == "inf");
    assert(StringEx::normalizeNumberText(" inf ", false, NumberTextAlternaor{}) == "inf");
    //assert(StringEx::normalizeNumberText("abc", false, NumberTextAlternaor{}) == "");
    assert(StringEx::normalizeNumberText("abc", false, NumberTextAlternaor{}.setInfinity("abc")) == "inf");
    assert(StringEx::normalizeNumberText("012", false, NumberTextAlternaor{}.setInfinity("012")) == "inf");

    assert(StringEx::normalizeNumberText("-inf", false, NumberTextAlternaor{}) == "-inf");
    assert(StringEx::normalizeNumberText(" - inf ", false, NumberTextAlternaor{}) == "-inf");
    //assert(StringEx::normalizeNumberText("abc", false, NumberTextAlternaor{}) == "");
    assert(StringEx::normalizeNumberText("-abc", false, NumberTextAlternaor{}.setInfinity("abc")) == "-inf");
    assert(StringEx::normalizeNumberText("-012", false, NumberTextAlternaor{}.setInfinity("012")) == "-inf");

    assert(StringEx::normalizeNumberText("nan", false, NumberTextAlternaor{}) == "nan");
    assert(StringEx::normalizeNumberText(" nan  ", false, NumberTextAlternaor{}) == "nan");
    //assert(StringEx::normalizeNumberText("abc", false, NumberTextAlternaor{}) == "");
    assert(StringEx::normalizeNumberText("abc", false, NumberTextAlternaor{}.setNan("abc")) == "nan");
    assert(StringEx::normalizeNumberText("012", false, NumberTextAlternaor{}.setNan("012")) == "nan");


    //assert(StringEx::normalizeNumberText("", true, {}) == "");
    //assert(StringEx::normalizeNumberText("ABC", true, {}) == "");

    assert(StringEx::normalizeNumberText(".", true, NumberTextAlternaor{}) == "0.0");
    assert(StringEx::normalizeNumberText("1.", true, NumberTextAlternaor{}) == "1.0");
    assert(StringEx::normalizeNumberText(".1", true, NumberTextAlternaor{}) == "0.1");

    assert(StringEx::normalizeNumberText("0", true, NumberTextAlternaor{}) == "0.0");
    assert(StringEx::normalizeNumberText("0.0", true, NumberTextAlternaor{}) == "0.0");
    assert(StringEx::normalizeNumberText("+0", true, NumberTextAlternaor{}) == "0.0");
    assert(StringEx::normalizeNumberText("+0.0", true, NumberTextAlternaor{}) == "0.0");
    assert(StringEx::normalizeNumberText("-0", true, NumberTextAlternaor{}) == "0.0");
    assert(StringEx::normalizeNumberText("-0.0", true, NumberTextAlternaor{}) == "0.0");
    assert(StringEx::normalizeNumberText("±0", true, NumberTextAlternaor{}.setZeroSign("±")) == "0.0");
    assert(StringEx::normalizeNumberText("±0.0", true, NumberTextAlternaor{}.setZeroSign("±")) == "0.0");

    assert(StringEx::normalizeNumberText("1", true, NumberTextAlternaor{}) == "1.0");
    assert(StringEx::normalizeNumberText("0.1", true, NumberTextAlternaor{}) == "0.1");
    assert(StringEx::normalizeNumberText("+1", true, NumberTextAlternaor{}) == "1.0");
    assert(StringEx::normalizeNumberText("+0.1", true, NumberTextAlternaor{}) == "0.1");
    assert(StringEx::normalizeNumberText("-1", true, NumberTextAlternaor{}) == "-1.0");
    assert(StringEx::normalizeNumberText("-1.0", true, NumberTextAlternaor{}) == "-1.0");
    assert(StringEx::normalizeNumberText("±1", true, NumberTextAlternaor{}.setZeroSign("±")) == "1.0");
    assert(StringEx::normalizeNumberText("±0.1", true, NumberTextAlternaor{}.setZeroSign("±")) == "0.1");

    assert(StringEx::normalizeNumberText("inf", true, NumberTextAlternaor{}) == "inf");
    assert(StringEx::normalizeNumberText(" inf ", true, NumberTextAlternaor{}) == "inf");
    //assert(StringEx::normalizeNumberText("abc", true, NumberTextAlternaor{}) == "");
    assert(StringEx::normalizeNumberText("abc", true, NumberTextAlternaor{}.setInfinity("abc")) == "inf");
    assert(StringEx::normalizeNumberText("012", true, NumberTextAlternaor{}.setInfinity("012")) == "inf");

    assert(StringEx::normalizeNumberText("-inf", true, NumberTextAlternaor{}) == "-inf");
    assert(StringEx::normalizeNumberText(" - inf ", true, NumberTextAlternaor{}) == "-inf");
    //assert(StringEx::normalizeNumberText("abc", true, NumberTextAlternaor{}) == "");
    assert(StringEx::normalizeNumberText("-abc", true, NumberTextAlternaor{}.setInfinity("abc")) == "-inf");
    assert(StringEx::normalizeNumberText("-012", true, NumberTextAlternaor{}.setInfinity("012")) == "-inf");

    assert(StringEx::normalizeNumberText("nan", true, NumberTextAlternaor{}) == "nan");
    assert(StringEx::normalizeNumberText(" nan  ", true, NumberTextAlternaor{}) == "nan");
    //assert(StringEx::normalizeNumberText("abc", true, NumberTextAlternaor{}) == "");
    assert(StringEx::normalizeNumberText("abc", true, NumberTextAlternaor{}.setNan("abc")) == "nan");
    assert(StringEx::normalizeNumberText("012", true, NumberTextAlternaor{}.setNan("012")) == "nan");


    assert(StringEx::getSignPartNumberText("nan", NumberTextAlternaor{}) == "");
    assert(StringEx::getSignPartNumberText("-inf", NumberTextAlternaor{}) == "-");
    assert(StringEx::getSignPartNumberText("-10.5", NumberTextAlternaor{}) == "-");
    assert(StringEx::getSignPartNumberText("-0", NumberTextAlternaor{}) == "-");
    assert(StringEx::getSignPartNumberText("0", NumberTextAlternaor{}) == "");
    assert(StringEx::getSignPartNumberText("+0", NumberTextAlternaor{}) == "+");
    assert(StringEx::getSignPartNumberText("10.5", NumberTextAlternaor{}) == "");
    assert(StringEx::getSignPartNumberText("+10.5", NumberTextAlternaor{}) == "+");
    assert(StringEx::getSignPartNumberText("inf", NumberTextAlternaor{}) == "");
    assert(StringEx::getSignPartNumberText("+inf", NumberTextAlternaor{}) == "+");

    //assert(StringEx::getSignPartNumberText(".", NumberTextAlternaor{}) == "");
    //assert(StringEx::getSignPartNumberText("0.", NumberTextAlternaor{}) == "");
    //assert(StringEx::getSignPartNumberText(".0", NumberTextAlternaor{}) == "");

    assert(StringEx::getIntegerPartNumberText("nan", NumberTextAlternaor{}) == "");
    assert(StringEx::getIntegerPartNumberText("-inf", NumberTextAlternaor{}) == "");
    assert(StringEx::getIntegerPartNumberText("-10.5", NumberTextAlternaor{}) == "10");
    assert(StringEx::getIntegerPartNumberText("-0", NumberTextAlternaor{}) == "0");
    assert(StringEx::getIntegerPartNumberText("0", NumberTextAlternaor{}) == "0");
    assert(StringEx::getIntegerPartNumberText("+0", NumberTextAlternaor{}) == "0");
    assert(StringEx::getIntegerPartNumberText("10.5", NumberTextAlternaor{}) == "10");
    assert(StringEx::getIntegerPartNumberText("+10.5", NumberTextAlternaor{}) == "10");
    assert(StringEx::getIntegerPartNumberText("inf", NumberTextAlternaor{}) == "");
    assert(StringEx::getIntegerPartNumberText("+inf", NumberTextAlternaor{}) == "");

    assert(StringEx::getDecimalPartNumberText("nan", NumberTextAlternaor{}) == "");
    assert(StringEx::getDecimalPartNumberText("-inf", NumberTextAlternaor{}) == "");
    assert(StringEx::getDecimalPartNumberText("-10.5", NumberTextAlternaor{}) == "5");
    assert(StringEx::getDecimalPartNumberText("-0", NumberTextAlternaor{}) == "");
    assert(StringEx::getDecimalPartNumberText("0", NumberTextAlternaor{}) == "");
    assert(StringEx::getDecimalPartNumberText("+0", NumberTextAlternaor{}) == "");
    assert(StringEx::getDecimalPartNumberText("10.5", NumberTextAlternaor{}) == "5");
    assert(StringEx::getDecimalPartNumberText("+10.5", NumberTextAlternaor{}) == "5");
    assert(StringEx::getDecimalPartNumberText("inf", NumberTextAlternaor{}) == "");
    assert(StringEx::getDecimalPartNumberText("+inf", NumberTextAlternaor{}) == "");
}
