#include "NumberTextAlternate.h"

#include "StringEx.h"

std::string NumberTextAlternate::deletePositiveSign(std::string_view text) const {
    std::string text2 = std::string{ text };
    for (auto&& positiveSign : m_positiveSigns) {
        text2 = StringEx::replace(text2, positiveSign, "");
    }
    return text2;
}

bool NumberTextAlternate::startsWithPositiveSign(std::string_view text) const
{
    for (auto&& positiveSign : m_positiveSigns) {
        if (text.starts_with(positiveSign)) {
            return true;
        }
    }
    return false;
}

bool NumberTextAlternate::startsWithNegativeSign(std::string_view text) const
{
    for (auto&& negativeSign : m_negativeSigns) {
        if (text.starts_with(negativeSign)) {
            return true;
        }
    }
    return false;
}

std::string NumberTextAlternate::deleteNegativeSign(std::string_view text) const {
    std::string text2 = std::string{ text };
    for (auto&& negativeSign : m_negativeSigns) {
        text2 = StringEx::replace(text2, negativeSign, "");
    }
    return text2;
}

bool NumberTextAlternate::startsWithZeroSign(std::string_view text) const
{
    for (auto&& zeroSign : m_zeroSigns) {
        if (text.starts_with(zeroSign)) {
            return true;
        }
    }
    return false;
}

std::string NumberTextAlternate::deleteZeroSign(std::string_view text) const {
    std::string text2 = std::string{ text };
    for (auto&& zeroSign : m_zeroSigns) {
        text2 = StringEx::replace(text2, zeroSign, "");
    }
    return text2;
}


bool NumberTextAlternate::isInfinity(std::string_view text) const {
    for (auto&& infinity : m_infinities) {
        if (infinity == text) {
            return true;
        }
    }
    return false;
}


bool NumberTextAlternate::isNan(std::string_view text) const {
    for (auto&& nan : m_nans) {
        if (nan == text) {
            return true;
        }
    }
    return false;
}
