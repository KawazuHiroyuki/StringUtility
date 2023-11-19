#include "NumberTextAlternator.h"

#include "StringEx.h"

std::string NumberTextAlternaor::deletePositiveSign(std::string_view text) const {
    std::string text2 = std::string{ text };
    text2 = StringEx::replace(text2, m_positiveSign, "");
    return text2;
}

std::size_t NumberTextAlternaor::countPositiveSign(std::string_view text) const
{
    if (StringEx::containts(text, m_positiveSign)) {
        return true;
    }
    if (StringEx::containts(text, StringEx::getDefaultPositiveSignNumberText())) {
        return true;
    }
    return false;
}

bool NumberTextAlternaor::containtsPositiveSign(std::string_view text) const
{
    if (StringEx::containts(text, m_positiveSign)) {
        return true;
    }
    if (StringEx::containts(text, StringEx::getDefaultPositiveSignNumberText())) {
        return true;
    }
    return false;
}

bool NumberTextAlternaor::startsWithPositiveSign(std::string_view text) const
{
    if (text.starts_with(m_positiveSign)) {
        return true;
    }
    return false;
}

bool NumberTextAlternaor::containtsNegativeSign(std::string_view text) const
{
    if (StringEx::containts(text, m_negativeSign)) {
        return true;
    }
    if (StringEx::containts(text, StringEx::getDefaultNegativeSignNumberText())) {
        return true;
    }
    return false;
}

bool NumberTextAlternaor::startsWithNegativeSign(std::string_view text) const
{
    if (text.starts_with(m_negativeSign)) {
        return true;
    }
    return false;
}

std::string NumberTextAlternaor::deleteNegativeSign(std::string_view text) const {
    std::string text2 = std::string{ text };
    text2 = StringEx::replace(text2, m_negativeSign, "");
    return text2;
}

bool NumberTextAlternaor::containtsZeroSign(std::string_view text) const
{
    if (StringEx::containts(text, m_zeroSign)) {
        return true;
    }
    return false;
}
bool NumberTextAlternaor::startsWithZeroSign(std::string_view text) const
{
    if (text.starts_with(m_zeroSign)) {
        return true;
    }
    return false;
}

std::string NumberTextAlternaor::deleteZeroSign(std::string_view text) const {
    std::string text2 = std::string{ text };
    text2 = StringEx::replace(text2, m_zeroSign, "");
    return text2;
}


bool NumberTextAlternaor::isInfinity(std::string_view text) const {
    if (m_infinity == text) {
        return true;
    }
    if (StringEx::getDefaultInfinityNumberText() == text) {
        return true;
    }
    return false;
}


bool NumberTextAlternaor::isNan(std::string_view text) const {
    if (m_nan == text) {
        return true;
    }
    if (StringEx::getDefaultNanNumberText() == text) {
        return true;
    }
    return false;
}
