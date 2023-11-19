#include "Test.h"

#include <iostream>
#include <cassert>
#include "StringEx.h"

void Test002() {
    //assert(NumberTextNormalizer{}.countPositiveSign("") == 0);
    //assert(NumberTextNormalizer{}.countPositiveSign("0123456+0123456@0123456++@@") == 3);
    //assert(NumberTextNormalizer{}.setPositiveSign("@").countPositiveSign("0123456+0123456@0123456++@@") == 6);
    //assert(NumberTextNormalizer{}.setPositiveSign("@@").countPositiveSign("0@@1234560123456@0123456@@") == 2);

    //assert(NumberTextNormalizer{}.countNegativeSign("") == 0);
    //assert(NumberTextNormalizer{}.countNegativeSign("0123456-0123456@0123456--@@") == 3);
    //assert(NumberTextNormalizer{}.setNegativeSign("@").countNegativeSign("0123456+0123456@0123456--@@") == 5);
    //assert(NumberTextNormalizer{}.setNegativeSign("@@").countNegativeSign("0@@1234560123456@0123456@@") == 2);

    //assert(NumberTextNormalizer{}.countZeroSign("") == 0);
    //assert(NumberTextNormalizer{}.countZeroSign("0123456-0123456@0123456±±@@") == 0);
    //assert(NumberTextNormalizer{}.setZeroSign("±").countZeroSign("0123456±0123456@0123456±±@@") == 3);

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

    assert(StringEx::isZeroNumberText("0", NumberTextNormalizer{}) == true);
    assert(StringEx::isZeroNumberText("0.0", NumberTextNormalizer{}) == true);
    assert(StringEx::isZeroNumberText("+0", NumberTextNormalizer{}) == true);
    assert(StringEx::isZeroNumberText("+0.0", NumberTextNormalizer{}) == true);
    assert(StringEx::isZeroNumberText("-0", NumberTextNormalizer{}) == true);
    assert(StringEx::isZeroNumberText("-0.0", NumberTextNormalizer{}) == true);
    assert(StringEx::isZeroNumberText("±0", NumberTextNormalizer{}.setZeroSign("±")) == true);
    assert(StringEx::isZeroNumberText("±0.0", NumberTextNormalizer{}.setZeroSign("±")) == true);

    assert(StringEx::isZeroNumberText("1", NumberTextNormalizer{}) == false);
    assert(StringEx::isZeroNumberText("0.1", NumberTextNormalizer{}) == false);
    assert(StringEx::isZeroNumberText("+1", NumberTextNormalizer{}) == false);
    assert(StringEx::isZeroNumberText("+0.1", NumberTextNormalizer{}) == false);
    assert(StringEx::isZeroNumberText("-1", NumberTextNormalizer{}) == false);
    assert(StringEx::isZeroNumberText("-1.0", NumberTextNormalizer{}) == false);
    assert(StringEx::isZeroNumberText("±1", NumberTextNormalizer{}.setZeroSign("±")) == false);
    assert(StringEx::isZeroNumberText("±0.1", NumberTextNormalizer{}.setZeroSign("±")) == false);

    assert(StringEx::isNegativeZeroNumberText("0", NumberTextNormalizer{}) == false);
    assert(StringEx::isNegativeZeroNumberText("0.0", NumberTextNormalizer{}) == false);
    assert(StringEx::isNegativeZeroNumberText("+0", NumberTextNormalizer{}) == false);
    assert(StringEx::isNegativeZeroNumberText("+0.0", NumberTextNormalizer{}) == false);
    assert(StringEx::isNegativeZeroNumberText("-0", NumberTextNormalizer{}) == true);
    assert(StringEx::isNegativeZeroNumberText("-0.0", NumberTextNormalizer{}) == true);
    assert(StringEx::isNegativeZeroNumberText("±0", NumberTextNormalizer{}.setZeroSign("±")) == false);
    assert(StringEx::isNegativeZeroNumberText("±0.0", NumberTextNormalizer{}.setZeroSign("±")) == false);

    assert(StringEx::isPositiveNumberText("1", NumberTextNormalizer{}) == true);
    assert(StringEx::isPositiveNumberText("+1", NumberTextNormalizer{}) == true);
    assert(StringEx::isPositiveNumberText("＋1", NumberTextNormalizer{}.setPositiveSign("＋")) == true);
    assert(StringEx::isPositiveNumberText("10．5", NumberTextNormalizer{}.setPoint("．")) == true);

    assert(StringEx::isPositiveNumberText("nan", NumberTextNormalizer{}) == false);
    assert(StringEx::isPositiveNumberText("ＮＡＮ", NumberTextNormalizer{}.setNan("ＮＡＮ")) == false);

    assert(StringEx::isPositiveNumberText("inf", NumberTextNormalizer{}) == true);
    assert(StringEx::isPositiveNumberText("+inf", NumberTextNormalizer{}) == true);
    assert(StringEx::isPositiveNumberText("ｉｎｆ", NumberTextNormalizer{}.setInfinity("ｉｎｆ")) == true);

    assert(StringEx::isNegativeNumberText("-2", NumberTextNormalizer{}) == true);
    assert(StringEx::isNegativeNumberText("－2", NumberTextNormalizer{}.setNegativeSign("－")) == true);
    assert(StringEx::isNegativeNumberText("-10．5", NumberTextNormalizer{}.setPoint("．")) == true);

    assert(StringEx::isNegativeNumberText("nan", NumberTextNormalizer{}) == false);
    assert(StringEx::isNegativeNumberText("ＮＡＮ", NumberTextNormalizer{}.setNan("ＮＡＮ")) == false);

    assert(StringEx::isNegativeNumberText("-inf", NumberTextNormalizer{}) == true);
    assert(StringEx::isNegativeNumberText("－ｉｎｆ", NumberTextNormalizer{}.setInfinity("ｉｎｆ").setNegativeSign("－")) == true);

    assert(StringEx::isPositiveNumberText("±0", NumberTextNormalizer{}.setZeroSign("±")) == true);
    assert(StringEx::isPositiveNumberText("±0.0", NumberTextNormalizer{}.setZeroSign("±")) == true);

    assert(StringEx::isPositiveNumberText("±3", NumberTextNormalizer{}.setZeroSign("±")) == true);
    assert(StringEx::isNegativeNumberText("±3", NumberTextNormalizer{}.setZeroSign("±")) == false);

    //assert(StringEx::isInfinityNumberText("", {}) == false);
    assert(StringEx::isInfinityNumberText("inf", {}) == true);
    assert(StringEx::isInfinityNumberText(" inf ", {}) == true);
    //assert(StringEx::isInfinityNumberText("abc", {}) == false);
    assert(StringEx::isInfinityNumberText("abc", NumberTextNormalizer{}.setInfinity("abc")) == true);
    assert(StringEx::isInfinityNumberText("012", NumberTextNormalizer{}.setInfinity("012")) == true);

    assert(StringEx::isInfinityNumberText("-inf", {}) == true);
    assert(StringEx::isInfinityNumberText(" - inf ", {}) == true);
    //assert(StringEx::isInfinityNumberText("abc", {}) == false);
    assert(StringEx::isInfinityNumberText("-abc", NumberTextNormalizer{}.setInfinity("abc")) == true);
    assert(StringEx::isInfinityNumberText("-012", NumberTextNormalizer{}.setInfinity("012")) == true);

    //assert(StringEx::isNanNumberText("", {}) == false);

    assert(StringEx::isNanNumberText("nan", {}) == true);
    assert(StringEx::isNanNumberText(" nan  ", {}) == true);
    //assert(StringEx::isNanNumberText("abc", {}) == false);
    assert(StringEx::isNanNumberText("abc", NumberTextNormalizer{}.setNan("abc")) == true);
    assert(StringEx::isNanNumberText("012", NumberTextNormalizer{}.setNan("012")) == true);

    assert(StringEx::isNumberText("", {}) == false);
    assert(StringEx::isNumberText("ABC", {}) == false);

    assert(StringEx::isNumberText("0", NumberTextNormalizer{}) == true);
    assert(StringEx::isNumberText("0.0", NumberTextNormalizer{}) == true);
    assert(StringEx::isNumberText("+0", NumberTextNormalizer{}) == true);
    assert(StringEx::isNumberText("+0.0", NumberTextNormalizer{}) == true);
    assert(StringEx::isNumberText("-0", NumberTextNormalizer{}) == true);
    assert(StringEx::isNumberText("-0.0", NumberTextNormalizer{}) == true);
    assert(StringEx::isNumberText("±0", NumberTextNormalizer{}.setZeroSign("±")) == true);
    assert(StringEx::isNumberText("±0.0", NumberTextNormalizer{}.setZeroSign("±")) == true);

    assert(StringEx::isNumberText("1", NumberTextNormalizer{}) == true);
    assert(StringEx::isNumberText("0.1", NumberTextNormalizer{}) == true);
    assert(StringEx::isNumberText("+1", NumberTextNormalizer{}) == true);
    assert(StringEx::isNumberText("+0.1", NumberTextNormalizer{}) == true);
    assert(StringEx::isNumberText("-1", NumberTextNormalizer{}) == true);
    assert(StringEx::isNumberText("-1.0", NumberTextNormalizer{}) == true);
    assert(StringEx::isNumberText("±1", NumberTextNormalizer{}.setZeroSign("±")) == true);
    assert(StringEx::isNumberText("±0.1", NumberTextNormalizer{}.setZeroSign("±")) == true);

    assert(StringEx::isNumberText("inf", {}) == true);
    assert(StringEx::isNumberText(" inf ", {}) == true);
    assert(StringEx::isNumberText("abc", {}) == false);
    assert(StringEx::isNumberText("abc", NumberTextNormalizer{}.setInfinity("abc")) == true);
    assert(StringEx::isNumberText("012", NumberTextNormalizer{}.setInfinity("012")) == true);

    assert(StringEx::isNumberText("-inf", {}) == true);
    assert(StringEx::isNumberText(" - inf ", {}) == true);
    assert(StringEx::isNumberText("abc", {}) == false);
    assert(StringEx::isNumberText("-abc", NumberTextNormalizer{}.setInfinity("abc")) == true);
    assert(StringEx::isNumberText("-012", NumberTextNormalizer{}.setInfinity("012")) == true);

    assert(StringEx::isNumberText("nan", {}) == true);
    assert(StringEx::isNumberText(" nan  ", {}) == true);
    assert(StringEx::isNumberText("abc", {}) == false);
    assert(StringEx::isNumberText("abc", NumberTextNormalizer{}.setNan("abc")) == true);
    assert(StringEx::isNumberText("012", NumberTextNormalizer{}.setNan("012")) == true);

    assert(StringEx::deleteSignPartNumberText("+012", NumberTextNormalizer{}) == "012");
    assert(StringEx::deleteSignPartNumberText("-012", NumberTextNormalizer{}) == "012");
    assert(StringEx::deleteSignPartNumberText("＋012", NumberTextNormalizer{}.setPositiveSign("＋")) == "012");
    assert(StringEx::deleteSignPartNumberText("－012", NumberTextNormalizer{}.setNegativeSign("－")) == "012");
    assert(StringEx::deleteSignPartNumberText("±0", NumberTextNormalizer{}.setZeroSign("±")) == "0");


    //assert(StringEx::normalizeNumberText("", false, {}) == "");
    //assert(StringEx::normalizeNumberText("ABC", false, {}) == "");

    assert(StringEx::normalizeNumberText("0", NumberTextNormalizer{}) == "0");
    assert(StringEx::normalizeNumberText("0.0", NumberTextNormalizer{}) == "0.0");
    assert(StringEx::normalizeNumberText("+0", NumberTextNormalizer{}) == "0");
    assert(StringEx::normalizeNumberText("+0.0", NumberTextNormalizer{}) == "0.0");
    assert(StringEx::normalizeNumberText("-0", NumberTextNormalizer{}) == "0");
    assert(StringEx::normalizeNumberText("-0.0", NumberTextNormalizer{}) == "0.0");
    assert(StringEx::normalizeNumberText("±0", NumberTextNormalizer{}.setZeroSign("±")) == "0");
    assert(StringEx::normalizeNumberText("±0.0", NumberTextNormalizer{}.setZeroSign("±")) == "0.0");

    assert(StringEx::normalizeNumberText("1", NumberTextNormalizer{}) == "1");
    assert(StringEx::normalizeNumberText("0.1", NumberTextNormalizer{}) == "0.1");
    assert(StringEx::normalizeNumberText("+1", NumberTextNormalizer{}) == "1");
    assert(StringEx::normalizeNumberText("+0.1", NumberTextNormalizer{}) == "0.1");
    assert(StringEx::normalizeNumberText("-1", NumberTextNormalizer{}) == "-1");
    assert(StringEx::normalizeNumberText("-1.0", NumberTextNormalizer{}) == "-1.0");
    assert(StringEx::normalizeNumberText("±1", NumberTextNormalizer{}.setZeroSign("±")) == "1");
    assert(StringEx::normalizeNumberText("±0.1", NumberTextNormalizer{}.setZeroSign("±")) == "0.1");

    assert(StringEx::normalizeNumberText("inf", NumberTextNormalizer{}) == "inf");
    assert(StringEx::normalizeNumberText(" inf ", NumberTextNormalizer{}) == "inf");
    //assert(StringEx::normalizeNumberText("abc", NumberTextAlternaor{}) == "");
    assert(StringEx::normalizeNumberText("abc", NumberTextNormalizer{}.setInfinity("abc")) == "inf");
    assert(StringEx::normalizeNumberText("012", NumberTextNormalizer{}.setInfinity("012")) == "inf");

    assert(StringEx::normalizeNumberText("-inf", NumberTextNormalizer{}) == "-inf");
    assert(StringEx::normalizeNumberText(" - inf ", NumberTextNormalizer{}) == "-inf");
    //assert(StringEx::normalizeNumberText("abc", NumberTextAlternaor{}) == "");
    assert(StringEx::normalizeNumberText("-abc", NumberTextNormalizer{}.setInfinity("abc")) == "-inf");
    assert(StringEx::normalizeNumberText("-012", NumberTextNormalizer{}.setInfinity("012")) == "-inf");

    assert(StringEx::normalizeNumberText("nan", NumberTextNormalizer{}) == "nan");
    assert(StringEx::normalizeNumberText(" nan  ", NumberTextNormalizer{}) == "nan");
    //assert(StringEx::normalizeNumberText("abc", NumberTextAlternaor{}) == "");
    assert(StringEx::normalizeNumberText("abc", NumberTextNormalizer{}.setNan("abc")) == "nan");
    assert(StringEx::normalizeNumberText("012", NumberTextNormalizer{}.setNan("012")) == "nan");


    //assert(StringEx::normalizeNumberText("", true, {}) == "");
    //assert(StringEx::normalizeNumberText("ABC", true, {}) == "");

    assert(StringEx::normalizeNumberText(".", NumberTextNormalizer{}.setFixupFixedPoint()) == "0.0");
    assert(StringEx::normalizeNumberText("1.", NumberTextNormalizer{}.setFixupFixedPoint()) == "1.0");
    assert(StringEx::normalizeNumberText(".1", NumberTextNormalizer{}.setFixupFixedPoint()) == "0.1");

    assert(StringEx::normalizeNumberText("0", NumberTextNormalizer{}.setFixupFixedPoint()) == "0.0");
    assert(StringEx::normalizeNumberText("0.0", NumberTextNormalizer{}.setFixupFixedPoint()) == "0.0");
    assert(StringEx::normalizeNumberText("+0", NumberTextNormalizer{}.setFixupFixedPoint()) == "0.0");
    assert(StringEx::normalizeNumberText("+0.0", NumberTextNormalizer{}.setFixupFixedPoint()) == "0.0");
    assert(StringEx::normalizeNumberText("-0", NumberTextNormalizer{}.setFixupFixedPoint()) == "0.0");
    assert(StringEx::normalizeNumberText("-0.0", NumberTextNormalizer{}.setFixupFixedPoint()) == "0.0");
    assert(StringEx::normalizeNumberText("±0", NumberTextNormalizer{}.setFixupFixedPoint().setZeroSign("±")) == "0.0");
    assert(StringEx::normalizeNumberText("±0.0", NumberTextNormalizer{}.setFixupFixedPoint().setZeroSign("±")) == "0.0");

    assert(StringEx::normalizeNumberText("1", NumberTextNormalizer{}.setFixupFixedPoint()) == "1.0");
    assert(StringEx::normalizeNumberText("0.1", NumberTextNormalizer{}.setFixupFixedPoint()) == "0.1");
    assert(StringEx::normalizeNumberText("+1", NumberTextNormalizer{}.setFixupFixedPoint()) == "1.0");
    assert(StringEx::normalizeNumberText("+0.1", NumberTextNormalizer{}.setFixupFixedPoint()) == "0.1");
    assert(StringEx::normalizeNumberText("-1", NumberTextNormalizer{}.setFixupFixedPoint()) == "-1.0");
    assert(StringEx::normalizeNumberText("-1.0", NumberTextNormalizer{}.setFixupFixedPoint()) == "-1.0");
    assert(StringEx::normalizeNumberText("±1", NumberTextNormalizer{}.setFixupFixedPoint().setZeroSign("±")) == "1.0");
    assert(StringEx::normalizeNumberText("±0.1", NumberTextNormalizer{}.setFixupFixedPoint().setZeroSign("±")) == "0.1");

    assert(StringEx::normalizeNumberText("inf", NumberTextNormalizer{}.setFixupFixedPoint()) == "inf");
    assert(StringEx::normalizeNumberText(" inf ", NumberTextNormalizer{}.setFixupFixedPoint()) == "inf");
    //assert(StringEx::normalizeNumberText("abc", NumberTextAlternaor{}.setFixupFixedPoint()) == "");
    assert(StringEx::normalizeNumberText("abc", NumberTextNormalizer{}.setFixupFixedPoint().setInfinity("abc")) == "inf");
    assert(StringEx::normalizeNumberText("012", NumberTextNormalizer{}.setFixupFixedPoint().setInfinity("012")) == "inf");

    assert(StringEx::normalizeNumberText("-inf", NumberTextNormalizer{}.setFixupFixedPoint()) == "-inf");
    assert(StringEx::normalizeNumberText(" - inf ", NumberTextNormalizer{}.setFixupFixedPoint()) == "-inf");
    //assert(StringEx::normalizeNumberText("abc", NumberTextAlternaor{}.setFixupFixedPoint()) == "");
    assert(StringEx::normalizeNumberText("-abc", NumberTextNormalizer{}.setFixupFixedPoint().setInfinity("abc")) == "-inf");
    assert(StringEx::normalizeNumberText("-012", NumberTextNormalizer{}.setFixupFixedPoint().setInfinity("012")) == "-inf");

    assert(StringEx::normalizeNumberText("nan", NumberTextNormalizer{}.setFixupFixedPoint()) == "nan");
    assert(StringEx::normalizeNumberText(" nan  ", NumberTextNormalizer{}.setFixupFixedPoint()) == "nan");
    //assert(StringEx::normalizeNumberText("abc", NumberTextAlternaor{}.setFixupFixedPoint()) == "");
    assert(StringEx::normalizeNumberText("abc", NumberTextNormalizer{}.setFixupFixedPoint().setNan("abc")) == "nan");
    assert(StringEx::normalizeNumberText("012", NumberTextNormalizer{}.setFixupFixedPoint().setNan("012")) == "nan");


    assert(StringEx::getSignPartNumberText("nan", NumberTextNormalizer{}) == "");
    assert(StringEx::getSignPartNumberText("-inf", NumberTextNormalizer{}) == "-");
    assert(StringEx::getSignPartNumberText("-10.5", NumberTextNormalizer{}) == "-");
    assert(StringEx::getSignPartNumberText("-0", NumberTextNormalizer{}) == "-");

    assert(StringEx::getSignPartNumberText("0", NumberTextNormalizer{}) == "");
    assert(StringEx::getSignPartNumberText("+0", NumberTextNormalizer{}) == "");
    assert(StringEx::getSignPartNumberText("10.5", NumberTextNormalizer{}) == "");
    assert(StringEx::getSignPartNumberText("+10.5", NumberTextNormalizer{}) == "");
    assert(StringEx::getSignPartNumberText("inf", NumberTextNormalizer{}) == "");
    assert(StringEx::getSignPartNumberText("+inf", NumberTextNormalizer{}) == "");

    assert(StringEx::getSignPartNumberText("0", NumberTextNormalizer{}.setKeepPositiveSign()) == "");
    assert(StringEx::getSignPartNumberText("+0", NumberTextNormalizer{}.setKeepPositiveSign()) == "+");
    assert(StringEx::getSignPartNumberText("10.5", NumberTextNormalizer{}.setKeepPositiveSign()) == "");
    assert(StringEx::getSignPartNumberText("+10.5", NumberTextNormalizer{}.setKeepPositiveSign()) == "+");
    assert(StringEx::getSignPartNumberText("inf", NumberTextNormalizer{}.setKeepPositiveSign()) == "");
    assert(StringEx::getSignPartNumberText("+inf", NumberTextNormalizer{}.setKeepPositiveSign()) == "+");

    //assert(StringEx::getSignPartNumberText(".", NumberTextNormalizer{}) == "");
    //assert(StringEx::getSignPartNumberText("0.", NumberTextNormalizer{}) == "");
    //assert(StringEx::getSignPartNumberText(".0", NumberTextNormalizer{}) == "");

    assert(StringEx::getIntegerPartNumberText("nan", NumberTextNormalizer{}) == "");
    assert(StringEx::getIntegerPartNumberText("-inf", NumberTextNormalizer{}) == "");
    assert(StringEx::getIntegerPartNumberText("-10.5", NumberTextNormalizer{}) == "10");
    assert(StringEx::getIntegerPartNumberText("-0", NumberTextNormalizer{}) == "0");
    assert(StringEx::getIntegerPartNumberText("0", NumberTextNormalizer{}) == "0");
    assert(StringEx::getIntegerPartNumberText("+0", NumberTextNormalizer{}) == "0");
    assert(StringEx::getIntegerPartNumberText("10.5", NumberTextNormalizer{}) == "10");
    assert(StringEx::getIntegerPartNumberText("+10.5", NumberTextNormalizer{}) == "10");
    assert(StringEx::getIntegerPartNumberText("inf", NumberTextNormalizer{}) == "");
    assert(StringEx::getIntegerPartNumberText("+inf", NumberTextNormalizer{}) == "");

    assert(StringEx::getDecimalPartNumberText("nan", NumberTextNormalizer{}) == "");
    assert(StringEx::getDecimalPartNumberText("-inf", NumberTextNormalizer{}) == "");
    assert(StringEx::getDecimalPartNumberText("-10.5", NumberTextNormalizer{}) == "5");
    assert(StringEx::getDecimalPartNumberText("-0", NumberTextNormalizer{}) == "");
    assert(StringEx::getDecimalPartNumberText("0", NumberTextNormalizer{}) == "");
    assert(StringEx::getDecimalPartNumberText("+0", NumberTextNormalizer{}) == "");
    assert(StringEx::getDecimalPartNumberText("10.5", NumberTextNormalizer{}) == "5");
    assert(StringEx::getDecimalPartNumberText("+10.5", NumberTextNormalizer{}) == "5");
    assert(StringEx::getDecimalPartNumberText("inf", NumberTextNormalizer{}) == "");
    assert(StringEx::getDecimalPartNumberText("+inf", NumberTextNormalizer{}) == "");
}
