#include "NumberTextAlternate.h"

#include "StringEx.h"

std::string NumberTextAlternate::deletePositiveSign(std::string_view text) const {
    std::string text2 = std::string{ text };
    text2 = StringEx::replace(text2, m_positiveSign, "");
    return text2;
}

bool NumberTextAlternate::startsWithPositiveSign(std::string_view text) const
{
    if (text.starts_with(m_positiveSign)) {
        return true;
    }
    return false;
}

bool NumberTextAlternate::startsWithNegativeSign(std::string_view text) const
{
    if (text.starts_with(m_negativeSign)) {
        return true;
    }
    return false;
}

std::string NumberTextAlternate::deleteNegativeSign(std::string_view text) const {
    std::string text2 = std::string{ text };
    text2 = StringEx::replace(text2, m_negativeSign, "");
    return text2;
}

bool NumberTextAlternate::startsWithZeroSign(std::string_view text) const
{
    if (text.starts_with(m_zeroSign)) {
        return true;
    }
    return false;
}

std::string NumberTextAlternate::deleteZeroSign(std::string_view text) const {
    std::string text2 = std::string{ text };
    text2 = StringEx::replace(text2, m_zeroSign, "");
    return text2;
}


bool NumberTextAlternate::isInfinity(std::string_view text) const {
    if (m_infinity == text) {
        return true;
    }
    return false;
}


bool NumberTextAlternate::isNan(std::string_view text) const {
    if (m_nan == text) {
        return true;
    }
    return false;
}
