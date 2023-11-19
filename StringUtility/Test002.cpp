#include "Test.h"

#include <iostream>
#include <cassert>
#include "StringEx.h"

void Test002() {
    assert(StringEx::toNumber("4") == 4.0);
    assert(StringEx::toNumber("4.2") == 4.2);
    assert(StringEx::toNumber("4.") == 4.0);
    assert(StringEx::toNumber(".2") == 0.2);
    //assert(StringEx::toNumber(".") == 0.0); // NG

    assert(StringEx::toNumber("-4") == -4.0);
    assert(StringEx::toNumber("-4.2") == -4.2);
    assert(StringEx::toNumber("-4.") == -4.0);
    assert(StringEx::toNumber("-.2") == -0.2);
    //assert(StringEx::toNumber("-.") == -0.0); // NG

    assert(StringEx::toNumber("0") == 0.0);
    assert(StringEx::toNumber("0.0") == 0.0);
    assert(StringEx::toNumber("0.") == 0.0);
    assert(StringEx::toNumber(".0") == 0.0);

    assert(StringEx::toNumber("-0") == -0.0);
    assert(StringEx::toNumber("-0.0") == -0.0);
    assert(StringEx::toNumber("-0.") == -0.0);
    assert(StringEx::toNumber("-.0") == -0.0);
    
    //assert(NumberTextNormalizer{}.countPositiveSign("") == 0);
    //assert(NumberTextNormalizer{}.countPositiveSign("0123456+0123456@0123456++@@") == 3);
    //assert(NumberTextNormalizer{}.setAlternatePositiveSignText("@").countPositiveSign("0123456+0123456@0123456++@@") == 6);
    //assert(NumberTextNormalizer{}.setAlternatePositiveSignText("@@").countPositiveSign("0@@1234560123456@0123456@@") == 2);

    //assert(NumberTextNormalizer{}.countNegativeSign("") == 0);
    //assert(NumberTextNormalizer{}.countNegativeSign("0123456-0123456@0123456--@@") == 3);
    //assert(NumberTextNormalizer{}.setAlternateNegativeSignText("@").countNegativeSign("0123456+0123456@0123456--@@") == 5);
    //assert(NumberTextNormalizer{}.setAlternateNegativeSignText("@@").countNegativeSign("0@@1234560123456@0123456@@") == 2);

    //assert(NumberTextNormalizer{}.countZeroSign("") == 0);
    //assert(NumberTextNormalizer{}.countZeroSign("0123456-0123456@0123456±±@@") == 0);
    //assert(NumberTextNormalizer{}.setAlternateZeroSignText("±").countZeroSign("0123456±0123456@0123456±±@@") == 3);

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

    //assert(StringEx::isZeroNumberText(".", NumberTextNormalizer{}) == true);
    assert(StringEx::isZeroNumberText("0.", NumberTextNormalizer{}) == true);
    assert(StringEx::isZeroNumberText(".0", NumberTextNormalizer{}) == true);
    //assert(StringEx::isZeroNumberText("-.", NumberTextNormalizer{}) == true);
    assert(StringEx::isZeroNumberText("-0.", NumberTextNormalizer{}) == true);
    assert(StringEx::isZeroNumberText("-.0", NumberTextNormalizer{}) == true);

    assert(StringEx::isZeroNumberText("0", NumberTextNormalizer{}) == true);
    assert(StringEx::isZeroNumberText("0.0", NumberTextNormalizer{}) == true);
    assert(StringEx::isZeroNumberText("+0", NumberTextNormalizer{}) == true);
    assert(StringEx::isZeroNumberText("+0", NumberTextNormalizer{}.setKeepPositiveSign()) == true);
    assert(StringEx::isZeroNumberText("+0.0", NumberTextNormalizer{}) == true);
    assert(StringEx::isZeroNumberText("+0.0", NumberTextNormalizer{}.setKeepPositiveSign()) == true);
    assert(StringEx::isZeroNumberText("-0", NumberTextNormalizer{}) == true);
    assert(StringEx::isZeroNumberText("-0.0", NumberTextNormalizer{}) == true);
    assert(StringEx::isZeroNumberText("±0", NumberTextNormalizer{}.setAlternateZeroSignText("±")) == true);
    assert(StringEx::isZeroNumberText("±0.0", NumberTextNormalizer{}.setAlternateZeroSignText("±")) == true);

    assert(StringEx::isZeroNumberText("1", NumberTextNormalizer{}) == false);
    assert(StringEx::isZeroNumberText("0.1", NumberTextNormalizer{}) == false);
    assert(StringEx::isZeroNumberText("+1", NumberTextNormalizer{}) == false);
    assert(StringEx::isZeroNumberText("+1", NumberTextNormalizer{}.setKeepPositiveSign()) == false);
    assert(StringEx::isZeroNumberText("+0.1", NumberTextNormalizer{}) == false);
    assert(StringEx::isZeroNumberText("+0.1", NumberTextNormalizer{}.setKeepPositiveSign()) == false);
    assert(StringEx::isZeroNumberText("-1", NumberTextNormalizer{}) == false);
    assert(StringEx::isZeroNumberText("-1.0", NumberTextNormalizer{}) == false);
    assert(StringEx::isZeroNumberText("±1", NumberTextNormalizer{}.setAlternateZeroSignText("±")) == false);
    assert(StringEx::isZeroNumberText("±0.1", NumberTextNormalizer{}.setAlternateZeroSignText("±")) == false);

    //assert(StringEx::isNegativeZeroNumberText("0", NumberTextNormalizer{}) == false);
    //assert(StringEx::isNegativeZeroNumberText("0.0", NumberTextNormalizer{}) == false);
    //assert(StringEx::isNegativeZeroNumberText("+0", NumberTextNormalizer{}) == false);
    //assert(StringEx::isNegativeZeroNumberText("+0.0", NumberTextNormalizer{}) == false);
    //assert(StringEx::isNegativeZeroNumberText("-0", NumberTextNormalizer{}) == true);
    //assert(StringEx::isNegativeZeroNumberText("-0.0", NumberTextNormalizer{}) == true);
    //assert(StringEx::isNegativeZeroNumberText("±0", NumberTextNormalizer{}.setAlternateZeroSignText("±")) == false);
    //assert(StringEx::isNegativeZeroNumberText("±0.0", NumberTextNormalizer{}.setAlternateZeroSignText("±")) == false);

    ////assert(StringEx::isNegativeZeroNumberText(".", NumberTextNormalizer{}) == true);
    //assert(StringEx::isNegativeZeroNumberText("0.", NumberTextNormalizer{}) == false);
    //assert(StringEx::isNegativeZeroNumberText(".0", NumberTextNormalizer{}) == false);
    ////assert(StringEx::isNegativeZeroNumberText("-.", NumberTextNormalizer{}) == true);
    //assert(StringEx::isNegativeZeroNumberText("-0.", NumberTextNormalizer{}) == true);
    //assert(StringEx::isNegativeZeroNumberText("-.0", NumberTextNormalizer{}) == true);

    assert(StringEx::isPositiveNumberText("1", NumberTextNormalizer{}) == true);
    assert(StringEx::isPositiveNumberText("+1", NumberTextNormalizer{}) == true);
    assert(StringEx::isPositiveNumberText("+1", NumberTextNormalizer{}.setKeepPositiveSign()) == true);
    assert(StringEx::isPositiveNumberText("＋1", NumberTextNormalizer{}.setAlternatePositiveSignText("＋")) == true);
    assert(StringEx::isPositiveNumberText("＋1", NumberTextNormalizer{}.setKeepPositiveSign().setAlternatePositiveSignText("＋")) == true);
    assert(StringEx::isPositiveNumberText("10．5", NumberTextNormalizer{}.setAlternatePointText("．")) == true);

    assert(StringEx::isPositiveNumberText("nan", NumberTextNormalizer{}) == false);
    assert(StringEx::isPositiveNumberText("ＮＡＮ", NumberTextNormalizer{}.setAlternateNanText("ＮＡＮ")) == false);

    assert(StringEx::isPositiveNumberText("inf", NumberTextNormalizer{}) == true);
    assert(StringEx::isPositiveNumberText("+inf", NumberTextNormalizer{}) == true);
    assert(StringEx::isPositiveNumberText("+inf", NumberTextNormalizer{}.setKeepPositiveSign()) == true);
    assert(StringEx::isPositiveNumberText("ｉｎｆ", NumberTextNormalizer{}.setAlternateInfinityText("ｉｎｆ")) == true);

//    assert(StringEx::isPositiveNumberText(".", NumberTextNormalizer{}) == true);
    assert(StringEx::isPositiveNumberText("0.", NumberTextNormalizer{}) == true);
    assert(StringEx::isPositiveNumberText(".0", NumberTextNormalizer{}) == true);
//    assert(StringEx::isPositiveNumberText("-.", NumberTextNormalizer{}) == false);
    assert(StringEx::isPositiveNumberText("-0.", NumberTextNormalizer{}) == false);
    assert(StringEx::isPositiveNumberText("-.0", NumberTextNormalizer{}) == false);

    assert(StringEx::isNegativeNumberText("-2", NumberTextNormalizer{}) == true);
    assert(StringEx::isNegativeNumberText("－2", NumberTextNormalizer{}.setAlternateNegativeSignText("－")) == true);
    assert(StringEx::isNegativeNumberText("-10．5", NumberTextNormalizer{}.setAlternatePointText("．")) == true);

    assert(StringEx::isNegativeNumberText("nan", NumberTextNormalizer{}) == false);
    assert(StringEx::isNegativeNumberText("ＮＡＮ", NumberTextNormalizer{}.setAlternateNanText("ＮＡＮ")) == false);

    assert(StringEx::isNegativeNumberText("-inf", NumberTextNormalizer{}) == true);
    assert(StringEx::isNegativeNumberText("－ｉｎｆ", NumberTextNormalizer{}.setAlternateInfinityText("ｉｎｆ").setAlternateNegativeSignText("－")) == true);

    assert(StringEx::isPositiveNumberText("±0", NumberTextNormalizer{}.setAlternateZeroSignText("±")) == true);
    assert(StringEx::isPositiveNumberText("±0.0", NumberTextNormalizer{}.setAlternateZeroSignText("±")) == true);

    assert(StringEx::isPositiveNumberText("±3", NumberTextNormalizer{}.setAlternateZeroSignText("±")) == true);

    //    assert(StringEx::isNegativeNumberText(".", NumberTextNormalizer{}) == false);
    assert(StringEx::isNegativeNumberText("0.", NumberTextNormalizer{}) == false);
    assert(StringEx::isNegativeNumberText(".0", NumberTextNormalizer{}) == false);
    //    assert(StringEx::isNegativeNumberText("-.", NumberTextNormalizer{}) == true);
    assert(StringEx::isNegativeNumberText("-0.", NumberTextNormalizer{}) == true);
    assert(StringEx::isNegativeNumberText("-.0", NumberTextNormalizer{}) == true);

    assert(StringEx::isNegativeNumberText("±0", NumberTextNormalizer{}.setAlternateZeroSignText("±")) == false);
    assert(StringEx::isNegativeNumberText("±0.0", NumberTextNormalizer{}.setAlternateZeroSignText("±")) == false);

    assert(StringEx::isNegativeNumberText("±3", NumberTextNormalizer{}.setAlternateZeroSignText("±")) == false);

    //assert(StringEx::isInfinityNumberText("", {}) == false);
    assert(StringEx::isInfinityNumberText("inf", {}) == true);
    assert(StringEx::isInfinityNumberText(" inf ", {}) == true);
    //assert(StringEx::isInfinityNumberText("abc", {}) == false);
    assert(StringEx::isInfinityNumberText("abc", NumberTextNormalizer{}.setAlternateInfinityText("abc")) == true);
    assert(StringEx::isInfinityNumberText("012", NumberTextNormalizer{}.setAlternateInfinityText("012")) == true);

    assert(StringEx::isInfinityNumberText("-inf", {}) == true);
    assert(StringEx::isInfinityNumberText(" - inf ", {}) == true);
    //assert(StringEx::isInfinityNumberText("abc", {}) == false);
    assert(StringEx::isInfinityNumberText("-abc", NumberTextNormalizer{}.setAlternateInfinityText("abc")) == true);
    assert(StringEx::isInfinityNumberText("-012", NumberTextNormalizer{}.setAlternateInfinityText("012")) == true);

    //assert(StringEx::isNanNumberText("", {}) == false);

    assert(StringEx::isNanNumberText("nan", {}) == true);
    assert(StringEx::isNanNumberText(" nan  ", {}) == true);
    //assert(StringEx::isNanNumberText("abc", {}) == false);
    assert(StringEx::isNanNumberText("abc", NumberTextNormalizer{}.setAlternateNanText("abc")) == true);
    assert(StringEx::isNanNumberText("012", NumberTextNormalizer{}.setAlternateNanText("012")) == true);

    assert(StringEx::isValidNumberText("", {}) == false);
    assert(StringEx::isValidNumberText("ABC", {}) == false);

    //assert(StringEx::isValidNumberText(".", NumberTextNormalizer{}) == true);
    assert(StringEx::isValidNumberText("0.", NumberTextNormalizer{}) == true);
    assert(StringEx::isValidNumberText(".0", NumberTextNormalizer{}) == true);
    //assert(StringEx::isValidNumberText("-.", NumberTextNormalizer{}) == true);
    assert(StringEx::isValidNumberText("-0.", NumberTextNormalizer{}) == true);
    assert(StringEx::isValidNumberText("-.0", NumberTextNormalizer{}) == true);

    assert(StringEx::isValidNumberText("0", NumberTextNormalizer{}) == true);
    assert(StringEx::isValidNumberText("0.0", NumberTextNormalizer{}) == true);
    assert(StringEx::isValidNumberText("+0", NumberTextNormalizer{}) == true);
    assert(StringEx::isValidNumberText("+0.0", NumberTextNormalizer{}) == true);
    assert(StringEx::isValidNumberText("-0", NumberTextNormalizer{}) == true);
    assert(StringEx::isValidNumberText("-0.0", NumberTextNormalizer{}) == true);
    assert(StringEx::isValidNumberText("±0", NumberTextNormalizer{}.setAlternateZeroSignText("±")) == true);
    assert(StringEx::isValidNumberText("±0.0", NumberTextNormalizer{}.setAlternateZeroSignText("±")) == true);

    assert(StringEx::isValidNumberText("1", NumberTextNormalizer{}) == true);
    assert(StringEx::isValidNumberText("0.1", NumberTextNormalizer{}) == true);
    assert(StringEx::isValidNumberText("+1", NumberTextNormalizer{}) == true);
    assert(StringEx::isValidNumberText("+0.1", NumberTextNormalizer{}) == true);
    assert(StringEx::isValidNumberText("-1", NumberTextNormalizer{}) == true);
    assert(StringEx::isValidNumberText("-1.0", NumberTextNormalizer{}) == true);
    assert(StringEx::isValidNumberText("±1", NumberTextNormalizer{}.setAlternateZeroSignText("±")) == true);
    assert(StringEx::isValidNumberText("±0.1", NumberTextNormalizer{}.setAlternateZeroSignText("±")) == true);

    assert(StringEx::isValidNumberText("inf", {}) == true);
    assert(StringEx::isValidNumberText(" inf ", {}) == true);
    assert(StringEx::isValidNumberText("abc", {}) == false);
    assert(StringEx::isValidNumberText("abc", NumberTextNormalizer{}.setAlternateInfinityText("abc")) == true);
    assert(StringEx::isValidNumberText("012", NumberTextNormalizer{}.setAlternateInfinityText("012")) == true);

    assert(StringEx::isValidNumberText("-inf", {}) == true);
    assert(StringEx::isValidNumberText(" - inf ", {}) == true);
    assert(StringEx::isValidNumberText("abc", {}) == false);
    assert(StringEx::isValidNumberText("-abc", NumberTextNormalizer{}.setAlternateInfinityText("abc")) == true);
    assert(StringEx::isValidNumberText("-012", NumberTextNormalizer{}.setAlternateInfinityText("012")) == true);

    assert(StringEx::isValidNumberText("nan", {}) == true);
    assert(StringEx::isValidNumberText(" nan  ", {}) == true);
    assert(StringEx::isValidNumberText("abc", {}) == false);
    assert(StringEx::isValidNumberText("abc", NumberTextNormalizer{}.setAlternateNanText("abc")) == true);
    assert(StringEx::isValidNumberText("012", NumberTextNormalizer{}.setAlternateNanText("012")) == true);

    assert(StringEx::deleteSignPartNumberText("+012", NumberTextNormalizer{}) == "012");
    assert(StringEx::deleteSignPartNumberText("-012", NumberTextNormalizer{}) == "012");
    assert(StringEx::deleteSignPartNumberText("＋012", NumberTextNormalizer{}.setAlternatePositiveSignText("＋")) == "012");
    assert(StringEx::deleteSignPartNumberText("－012", NumberTextNormalizer{}.setAlternateNegativeSignText("－")) == "012");
    assert(StringEx::deleteSignPartNumberText("±0", NumberTextNormalizer{}.setAlternateZeroSignText("±")) == "0");


    //assert(StringEx::normalizeNumberText("", false, {}) == "");
    //assert(StringEx::normalizeNumberText("ABC", false, {}) == "");

    assert(StringEx::normalizeNumberText("0", NumberTextNormalizer{}) == "0");
    assert(StringEx::normalizeNumberText("0.0", NumberTextNormalizer{}) == "0.0");
    assert(StringEx::normalizeNumberText("+0", NumberTextNormalizer{}) == "0");
    assert(StringEx::normalizeNumberText("+0", NumberTextNormalizer{}.setKeepPositiveSign()) == "+0");
    assert(StringEx::normalizeNumberText("+0.0", NumberTextNormalizer{}) == "0.0");
    assert(StringEx::normalizeNumberText("+0.0", NumberTextNormalizer{}.setKeepPositiveSign()) == "+0.0");
    assert(StringEx::normalizeNumberText("-0", NumberTextNormalizer{}) == "0");
    assert(StringEx::normalizeNumberText("-0.0", NumberTextNormalizer{}) == "0.0");
    assert(StringEx::normalizeNumberText("±0", NumberTextNormalizer{}.setAlternateZeroSignText("±")) == "0");
    assert(StringEx::normalizeNumberText("±0.0", NumberTextNormalizer{}.setAlternateZeroSignText("±")) == "0.0");

    assert(StringEx::normalizeNumberText("-0", NumberTextNormalizer{}.setKeepNegativeZero()) == "-0");
    assert(StringEx::normalizeNumberText("-0.0", NumberTextNormalizer{}.setKeepNegativeZero()) == "-0.0");

    assert(StringEx::normalizeNumberText("1", NumberTextNormalizer{}) == "1");
    assert(StringEx::normalizeNumberText("0.1", NumberTextNormalizer{}) == "0.1");
    assert(StringEx::normalizeNumberText("+1", NumberTextNormalizer{}) == "1");
    assert(StringEx::normalizeNumberText("+1", NumberTextNormalizer{}.setKeepPositiveSign()) == "+1");
    assert(StringEx::normalizeNumberText("+0.1", NumberTextNormalizer{}) == "0.1");
    assert(StringEx::normalizeNumberText("+0.1", NumberTextNormalizer{}.setKeepPositiveSign()) == "+0.1");
    assert(StringEx::normalizeNumberText("-1", NumberTextNormalizer{}) == "-1");
    assert(StringEx::normalizeNumberText("-1.0", NumberTextNormalizer{}) == "-1.0");
    assert(StringEx::normalizeNumberText("±1", NumberTextNormalizer{}.setAlternateZeroSignText("±")) == "1");
    assert(StringEx::normalizeNumberText("±0.1", NumberTextNormalizer{}.setAlternateZeroSignText("±")) == "0.1");

    assert(StringEx::normalizeNumberText("inf", NumberTextNormalizer{}) == "inf");
    assert(StringEx::normalizeNumberText("+inf", NumberTextNormalizer{}) == "inf");
    assert(StringEx::normalizeNumberText("+inf", NumberTextNormalizer{}.setKeepPositiveSign()) == "+inf");
    assert(StringEx::normalizeNumberText(" inf ", NumberTextNormalizer{}) == "inf");
    //assert(StringEx::normalizeNumberText("abc", NumberTextAlternaor{}) == "");
    assert(StringEx::normalizeNumberText("abc", NumberTextNormalizer{}.setAlternateInfinityText("abc")) == "inf");
    assert(StringEx::normalizeNumberText("012", NumberTextNormalizer{}.setAlternateInfinityText("012")) == "inf");

    assert(StringEx::normalizeNumberText("-inf", NumberTextNormalizer{}) == "-inf");
    assert(StringEx::normalizeNumberText(" - inf ", NumberTextNormalizer{}) == "-inf");
    //assert(StringEx::normalizeNumberText("abc", NumberTextAlternaor{}) == "");
    assert(StringEx::normalizeNumberText("-abc", NumberTextNormalizer{}.setAlternateInfinityText("abc")) == "-inf");
    assert(StringEx::normalizeNumberText("-012", NumberTextNormalizer{}.setAlternateInfinityText("012")) == "-inf");

    assert(StringEx::normalizeNumberText("nan", NumberTextNormalizer{}) == "nan");
    assert(StringEx::normalizeNumberText(" nan  ", NumberTextNormalizer{}) == "nan");
    //assert(StringEx::normalizeNumberText("abc", NumberTextAlternaor{}) == "");
    assert(StringEx::normalizeNumberText("abc", NumberTextNormalizer{}.setAlternateNanText("abc")) == "nan");
    assert(StringEx::normalizeNumberText("012", NumberTextNormalizer{}.setAlternateNanText("012")) == "nan");


    //assert(StringEx::normalizeNumberText("", true, {}) == "");
    //assert(StringEx::normalizeNumberText("ABC", true, {}) == "");

    //assert(StringEx::normalizeNumberText(".", NumberTextNormalizer{}) == "0.0");
    assert(StringEx::normalizeNumberText("0.", NumberTextNormalizer{}) == "0.0");
    assert(StringEx::normalizeNumberText(".0", NumberTextNormalizer{}) == "0.0");
    //assert(StringEx::normalizeNumberText("-.", NumberTextNormalizer{}) == "0.0");
    assert(StringEx::normalizeNumberText("-0.", NumberTextNormalizer{}) == "0.0");
    assert(StringEx::normalizeNumberText("-.0", NumberTextNormalizer{}) == "0.0");

    assert(StringEx::normalizeNumberText("1.", NumberTextNormalizer{}) == "1.0");
    assert(StringEx::normalizeNumberText(".1", NumberTextNormalizer{}) == "0.1");
    assert(StringEx::normalizeNumberText("-1.", NumberTextNormalizer{}) == "-1.0");
    assert(StringEx::normalizeNumberText("-.1", NumberTextNormalizer{}) == "-0.1");

    assert(StringEx::normalizeNumberText("0", NumberTextNormalizer{}.setFixupFixedPoint()) == "0.0");
    assert(StringEx::normalizeNumberText("0.0", NumberTextNormalizer{}.setFixupFixedPoint()) == "0.0");
    assert(StringEx::normalizeNumberText("+0", NumberTextNormalizer{}.setFixupFixedPoint()) == "0.0");
    assert(StringEx::normalizeNumberText("+0.0", NumberTextNormalizer{}.setFixupFixedPoint()) == "0.0");
    assert(StringEx::normalizeNumberText("-0", NumberTextNormalizer{}.setFixupFixedPoint()) == "0.0");
    assert(StringEx::normalizeNumberText("-0.0", NumberTextNormalizer{}.setFixupFixedPoint()) == "0.0");
    assert(StringEx::normalizeNumberText("±0", NumberTextNormalizer{}.setFixupFixedPoint().setAlternateZeroSignText("±")) == "0.0");
    assert(StringEx::normalizeNumberText("±0.0", NumberTextNormalizer{}.setFixupFixedPoint().setAlternateZeroSignText("±")) == "0.0");

    assert(StringEx::normalizeNumberText("1", NumberTextNormalizer{}.setFixupFixedPoint()) == "1.0");
    assert(StringEx::normalizeNumberText("0.1", NumberTextNormalizer{}.setFixupFixedPoint()) == "0.1");
    assert(StringEx::normalizeNumberText("+1", NumberTextNormalizer{}.setFixupFixedPoint()) == "1.0");
    assert(StringEx::normalizeNumberText("+1", NumberTextNormalizer{}.setKeepPositiveSign().setFixupFixedPoint()) == "+1.0");
    assert(StringEx::normalizeNumberText("+0.1", NumberTextNormalizer{}.setFixupFixedPoint()) == "0.1");
    assert(StringEx::normalizeNumberText("+0.1", NumberTextNormalizer{}.setKeepPositiveSign().setFixupFixedPoint()) == "+0.1");
    assert(StringEx::normalizeNumberText("-1", NumberTextNormalizer{}.setFixupFixedPoint()) == "-1.0");
    assert(StringEx::normalizeNumberText("-1.0", NumberTextNormalizer{}.setFixupFixedPoint()) == "-1.0");
    assert(StringEx::normalizeNumberText("±1", NumberTextNormalizer{}.setFixupFixedPoint().setAlternateZeroSignText("±")) == "1.0");
    assert(StringEx::normalizeNumberText("±0.1", NumberTextNormalizer{}.setFixupFixedPoint().setAlternateZeroSignText("±")) == "0.1");

    assert(StringEx::normalizeNumberText("inf", NumberTextNormalizer{}.setFixupFixedPoint()) == "inf");
    assert(StringEx::normalizeNumberText(" inf ", NumberTextNormalizer{}.setFixupFixedPoint()) == "inf");
    //assert(StringEx::normalizeNumberText("abc", NumberTextAlternaor{}.setFixupFixedPoint()) == "");
    assert(StringEx::normalizeNumberText("abc", NumberTextNormalizer{}.setFixupFixedPoint().setAlternateInfinityText("abc")) == "inf");
    assert(StringEx::normalizeNumberText("012", NumberTextNormalizer{}.setFixupFixedPoint().setAlternateInfinityText("012")) == "inf");

    assert(StringEx::normalizeNumberText("-inf", NumberTextNormalizer{}.setFixupFixedPoint()) == "-inf");
    assert(StringEx::normalizeNumberText(" - inf ", NumberTextNormalizer{}.setFixupFixedPoint()) == "-inf");
    //assert(StringEx::normalizeNumberText("abc", NumberTextAlternaor{}.setFixupFixedPoint()) == "");
    assert(StringEx::normalizeNumberText("-abc", NumberTextNormalizer{}.setFixupFixedPoint().setAlternateInfinityText("abc")) == "-inf");
    assert(StringEx::normalizeNumberText("-012", NumberTextNormalizer{}.setFixupFixedPoint().setAlternateInfinityText("012")) == "-inf");

    assert(StringEx::normalizeNumberText("nan", NumberTextNormalizer{}.setFixupFixedPoint()) == "nan");
    assert(StringEx::normalizeNumberText(" nan  ", NumberTextNormalizer{}.setFixupFixedPoint()) == "nan");
    //assert(StringEx::normalizeNumberText("abc", NumberTextAlternaor{}.setFixupFixedPoint()) == "");
    assert(StringEx::normalizeNumberText("abc", NumberTextNormalizer{}.setFixupFixedPoint().setAlternateNanText("abc")) == "nan");
    assert(StringEx::normalizeNumberText("012", NumberTextNormalizer{}.setFixupFixedPoint().setAlternateNanText("012")) == "nan");

    assert(StringEx::splitPartNumberText("nan", NumberTextNormalizer{}) == std::vector<std::string>({"", "", ""}));
    assert(StringEx::splitPartNumberText("-inf", NumberTextNormalizer{}) == std::vector<std::string>({ "-", "", "" }));
    assert(StringEx::splitPartNumberText("-10.5", NumberTextNormalizer{}) == std::vector<std::string>({ "-", "10", "5" }));
    assert(StringEx::splitPartNumberText("-0", NumberTextNormalizer{}) == std::vector<std::string>({ "-", "0", "" }));
    assert(StringEx::splitPartNumberText("0", NumberTextNormalizer{}) == std::vector<std::string>({ "", "0", "" }));
    assert(StringEx::splitPartNumberText("+0", NumberTextNormalizer{}) == std::vector<std::string>({ "+", "0", "" }));
    assert(StringEx::splitPartNumberText("10.5", NumberTextNormalizer{}) == std::vector<std::string>({ "", "10", "5" }));
    assert(StringEx::splitPartNumberText("+10.5", NumberTextNormalizer{}) == std::vector<std::string>({ "+", "10", "5" }));
    assert(StringEx::splitPartNumberText("inf", NumberTextNormalizer{}) == std::vector<std::string>({ "", "", "" }));
    assert(StringEx::splitPartNumberText("+inf", NumberTextNormalizer{}) == std::vector<std::string>({ "+", "", "" }));

    //assert(StringEx::splitPartNumberText(".", NumberTextNormalizer{}) == std::vector<std::string>({ "", "", "" }));
    assert(StringEx::splitPartNumberText("0.", NumberTextNormalizer{}) == std::vector<std::string>({ "", "0", "0" }));
    assert(StringEx::splitPartNumberText(".0", NumberTextNormalizer{}) == std::vector<std::string>({ "", "0", "0" }));
    assert(StringEx::splitPartNumberText("+0.", NumberTextNormalizer{}) == std::vector<std::string>({ "+", "0", "0" }));
    assert(StringEx::splitPartNumberText("+.0", NumberTextNormalizer{}) == std::vector<std::string>({ "+", "0", "0" }));
    //assert(StringEx::splitPartNumberText("-.", NumberTextNormalizer{}) == std::vector<std::string>({ "", "", "" }));
    assert(StringEx::splitPartNumberText("-0.", NumberTextNormalizer{}) == std::vector<std::string>({ "-", "0", "0" }));
    assert(StringEx::splitPartNumberText("-.0", NumberTextNormalizer{}) == std::vector<std::string>({ "-", "0", "0" }));

    assert(StringEx::splitPartNumberText("-1", NumberTextNormalizer{}.setFixupFixedPoint()) == std::vector<std::string>({ "-", "1", "0" }));
    assert(StringEx::splitPartNumberText("1", NumberTextNormalizer{}.setFixupFixedPoint()) == std::vector<std::string>({ "", "1", "0" }));
    assert(StringEx::splitPartNumberText("+1", NumberTextNormalizer{}.setFixupFixedPoint()) == std::vector<std::string>({ "+", "1", "0" }));
    assert(StringEx::splitPartNumberText("+1", NumberTextNormalizer{}.setKeepPositiveSign().setFixupFixedPoint()) == std::vector<std::string>({ "+", "1", "0" }));

    assert(StringEx::splitPartNumberText("1.", NumberTextNormalizer{}) == std::vector<std::string>({ "", "1", "0" }));
    assert(StringEx::splitPartNumberText(".1", NumberTextNormalizer{}) == std::vector<std::string>({ "", "0", "1" }));
    assert(StringEx::splitPartNumberText("+1.", NumberTextNormalizer{}) == std::vector<std::string>({ "+", "1", "0" }));
    assert(StringEx::splitPartNumberText("+.1", NumberTextNormalizer{}) == std::vector<std::string>({ "+", "0", "1" }));
    assert(StringEx::splitPartNumberText("-1.", NumberTextNormalizer{}) == std::vector<std::string>({ "-", "1", "0" }));
    assert(StringEx::splitPartNumberText("-.1", NumberTextNormalizer{}) == std::vector<std::string>({ "-", "0", "1" }));

    assert(StringEx::getSignPartNumberText("nan", NumberTextNormalizer{}) == "");
    assert(StringEx::getSignPartNumberText("-inf", NumberTextNormalizer{}) == "-");
    assert(StringEx::getSignPartNumberText("-10.5", NumberTextNormalizer{}) == "-");
    assert(StringEx::getSignPartNumberText("-0", NumberTextNormalizer{}) == "-");

    assert(StringEx::getSignPartNumberText("0", NumberTextNormalizer{}) == "");
    assert(StringEx::getSignPartNumberText("+0", NumberTextNormalizer{}) == "+");
    assert(StringEx::getSignPartNumberText("10.5", NumberTextNormalizer{}) == "");
    assert(StringEx::getSignPartNumberText("+10.5", NumberTextNormalizer{}) == "+");
    assert(StringEx::getSignPartNumberText("inf", NumberTextNormalizer{}) == "");
    assert(StringEx::getSignPartNumberText("+inf", NumberTextNormalizer{}) == "+");

    assert(StringEx::getSignPartNumberText("0", NumberTextNormalizer{}.setKeepPositiveSign()) == "");
    assert(StringEx::getSignPartNumberText("+0", NumberTextNormalizer{}.setKeepPositiveSign()) == "+");
    assert(StringEx::getSignPartNumberText("10.5", NumberTextNormalizer{}.setKeepPositiveSign()) == "");
    assert(StringEx::getSignPartNumberText("+10.5", NumberTextNormalizer{}.setKeepPositiveSign()) == "+");
    assert(StringEx::getSignPartNumberText("inf", NumberTextNormalizer{}.setKeepPositiveSign()) == "");
    assert(StringEx::getSignPartNumberText("+inf", NumberTextNormalizer{}.setKeepPositiveSign()) == "+");

//    assert(StringEx::getSignPartNumberText(".", NumberTextNormalizer{}) == "");
    assert(StringEx::getSignPartNumberText("0.", NumberTextNormalizer{}) == "");
    assert(StringEx::getSignPartNumberText(".0", NumberTextNormalizer{}) == "");
    assert(StringEx::getSignPartNumberText("+0.", NumberTextNormalizer{}) == "+");
    assert(StringEx::getSignPartNumberText("+.0", NumberTextNormalizer{}) == "+");
//    assert(StringEx::getSignPartNumberText("-.", NumberTextNormalizer{}) == "-");
    assert(StringEx::getSignPartNumberText("-0.", NumberTextNormalizer{}) == "-");
    assert(StringEx::getSignPartNumberText("-.0", NumberTextNormalizer{}) == "-");

    assert(StringEx::getSignPartNumberText("1.", NumberTextNormalizer{}) == "");
    assert(StringEx::getSignPartNumberText(".1", NumberTextNormalizer{}) == "");
    assert(StringEx::getSignPartNumberText("+1.", NumberTextNormalizer{}) == "+");
    assert(StringEx::getSignPartNumberText("+.1", NumberTextNormalizer{}) == "+");
    assert(StringEx::getSignPartNumberText("-1.", NumberTextNormalizer{}) == "-");
    assert(StringEx::getSignPartNumberText("-.1", NumberTextNormalizer{}) == "-");

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

//    assert(StringEx::getIntegerPartNumberText(".", NumberTextNormalizer{}) == "");
    assert(StringEx::getIntegerPartNumberText("0.", NumberTextNormalizer{}) == "0");
    assert(StringEx::getIntegerPartNumberText(".0", NumberTextNormalizer{}) == "0");
    assert(StringEx::getIntegerPartNumberText("+0.", NumberTextNormalizer{}) == "0");
    assert(StringEx::getIntegerPartNumberText("+.0", NumberTextNormalizer{}) == "0");
    //assert(StringEx::getIntegerPartNumberText("-.", NumberTextNormalizer{}) == "-");
    assert(StringEx::getIntegerPartNumberText("-0.", NumberTextNormalizer{}) == "0");
    assert(StringEx::getIntegerPartNumberText("-.0", NumberTextNormalizer{}) == "0");

    assert(StringEx::getIntegerPartNumberText("1.", NumberTextNormalizer{}) == "1");
    assert(StringEx::getIntegerPartNumberText(".1", NumberTextNormalizer{}) == "0");
    assert(StringEx::getIntegerPartNumberText("+1.", NumberTextNormalizer{}) == "1");
    assert(StringEx::getIntegerPartNumberText("+.1", NumberTextNormalizer{}) == "0");
    assert(StringEx::getIntegerPartNumberText("-1.", NumberTextNormalizer{}) == "1");
    assert(StringEx::getIntegerPartNumberText("-.1", NumberTextNormalizer{}) == "0");

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

//    assert(StringEx::getDecimalPartNumberText(".", NumberTextNormalizer{}) == "");
    assert(StringEx::getDecimalPartNumberText("0.", NumberTextNormalizer{}) == "0");
    assert(StringEx::getDecimalPartNumberText(".0", NumberTextNormalizer{}) == "0");
    assert(StringEx::getDecimalPartNumberText("+0.", NumberTextNormalizer{}) == "0");
    assert(StringEx::getDecimalPartNumberText("+.0", NumberTextNormalizer{}) == "0");
//    assert(StringEx::getDecimalPartNumberText("-.", NumberTextNormalizer{}) == "-");
    assert(StringEx::getDecimalPartNumberText("-0.", NumberTextNormalizer{}) == "0");
    assert(StringEx::getDecimalPartNumberText("-.0", NumberTextNormalizer{}) == "0");

    assert(StringEx::getDecimalPartNumberText("1.", NumberTextNormalizer{}) == "0");
    assert(StringEx::getDecimalPartNumberText(".1", NumberTextNormalizer{}) == "1");
    assert(StringEx::getDecimalPartNumberText("+1.", NumberTextNormalizer{}) == "0");
    assert(StringEx::getDecimalPartNumberText("+.1", NumberTextNormalizer{}) == "1");
    assert(StringEx::getDecimalPartNumberText("-1.", NumberTextNormalizer{}) == "0");
    assert(StringEx::getDecimalPartNumberText("-.1", NumberTextNormalizer{}) == "1");
}
