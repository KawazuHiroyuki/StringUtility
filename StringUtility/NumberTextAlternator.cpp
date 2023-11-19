#include "NumberTextAlternator.h"

#include "StringEx.h"

std::size_t NumberTextNormalizer::countPositiveSign(std::string_view text) const
{
    std::size_t count = StringEx::count(text, m_positiveSign) + StringEx::count(text, StringEx::getDefaultPositiveSignNumberText());
    return count;
}

bool NumberTextNormalizer::containtsPositiveSign(std::string_view text) const
{
    if (!m_positiveSign.empty() && StringEx::containts(text, m_positiveSign)) {
        return true;
    }
    if (StringEx::containts(text, StringEx::getDefaultPositiveSignNumberText())) {
        return true;
    }
    return false;
}

bool NumberTextNormalizer::startsWithPositiveSign(std::string_view text) const
{
    if (!m_positiveSign.empty() && text.starts_with(m_positiveSign)) {
        return true;
    }
    if (text.starts_with(StringEx::getDefaultPositiveSignNumberText())) {
        return true;
    }
    return false;
}

std::string NumberTextNormalizer::deletePositiveSign(std::string_view text) const 
{
    std::string text2 = std::string{ text };
    text2 = StringEx::replace(text2, m_positiveSign, "");
    text2 = StringEx::replace(text2, StringEx::getDefaultPositiveSignNumberText(), "");
    return text2;
}

std::string NumberTextNormalizer::pickupPositiveSign(std::string_view text) const
{
    if (!m_positiveSign.empty() && StringEx::containts(text, m_positiveSign)) {
        return m_positiveSign;
    }
    if (StringEx::containts(text, StringEx::getDefaultPositiveSignNumberText())) {
        return StringEx::getDefaultPositiveSignNumberText();
    }
    return "";
}

std::size_t NumberTextNormalizer::countNegativeSign(std::string_view text) const
{
    std::size_t count = StringEx::count(text, m_negativeSign) + StringEx::count(text, StringEx::getDefaultNegativeSignNumberText());
    return count;
}

bool NumberTextNormalizer::containtsNegativeSign(std::string_view text) const
{
    if (!m_negativeSign.empty() && StringEx::containts(text, m_negativeSign)) {
        return true;
    }
    if (StringEx::containts(text, StringEx::getDefaultNegativeSignNumberText())) {
        return true;
    }
    return false;
}

bool NumberTextNormalizer::startsWithNegativeSign(std::string_view text) const
{
    if (!m_negativeSign.empty() && text.starts_with(m_negativeSign)) {
        return true;
    }
    if (text.starts_with(StringEx::getDefaultNegativeSignNumberText())) {
        return true;
    }
    return false;
}

std::string NumberTextNormalizer::deleteNegativeSign(std::string_view text) const {
    std::string text2 = std::string{ text };
    text2 = StringEx::replace(text2, m_negativeSign, "");
    text2 = StringEx::replace(text2, StringEx::getDefaultNegativeSignNumberText(), "");
    return text2;
}

std::string NumberTextNormalizer::pickupNegativeSign(std::string_view text) const
{
    if (!m_negativeSign.empty() && StringEx::containts(text, m_negativeSign)) {
        return m_negativeSign;
    }
    if (StringEx::containts(text, StringEx::getDefaultNegativeSignNumberText())) {
        return StringEx::getDefaultNegativeSignNumberText();
    }
    return "";
}

std::size_t NumberTextNormalizer::countZeroSign(std::string_view text) const
{
    std::size_t count = StringEx::count(text, m_zeroSign);
    return count;
}

bool NumberTextNormalizer::containtsZeroSign(std::string_view text) const
{
    if (!m_zeroSign.empty() && StringEx::containts(text, m_zeroSign)) {
        return true;
    }
    return false;
}

bool NumberTextNormalizer::startsWithZeroSign(std::string_view text) const
{
    if (!m_zeroSign.empty() && text.starts_with(m_zeroSign)) {
        return true;
    }
    return false;
}

std::string NumberTextNormalizer::deleteZeroSign(std::string_view text) const {
    std::string text2 = std::string{ text };
    text2 = StringEx::replace(text2, m_zeroSign, "");
    return text2;
}

std::string NumberTextNormalizer::pickupZeroSign(std::string_view text) const
{
    if (!m_zeroSign.empty() && StringEx::containts(text, m_zeroSign)) {
        return m_zeroSign;
    }
    return "";
}

std::size_t NumberTextNormalizer::countPoint(std::string_view text) const
{
    std::size_t count = StringEx::count(text, m_point) + StringEx::count(text, StringEx::getDefaultPointNumberText());
    return count;
}

bool NumberTextNormalizer::containtsPoint(std::string_view text) const
{
    if (!m_point.empty() && StringEx::containts(text, m_point)) {
        return true;
    }
    if (StringEx::containts(text, StringEx::getDefaultPointNumberText())) {
        return true;
    }
    return false;
}

bool NumberTextNormalizer::containtsInfinity(std::string_view text) const
{
    if (!m_infinity.empty() && StringEx::containts(text, m_infinity)) {
        return true;
    }
    if (StringEx::containts(text, StringEx::getDefaultInfinityNumberText())) {
        return true;
    }
    return false;
}

bool NumberTextNormalizer::isInfinity(std::string_view text) const
{
    if (!m_infinity.empty() && m_infinity == text) {
        return true;
    }
    if (StringEx::getDefaultInfinityNumberText() == text) {
        return true;
    }
    return false;
}

bool NumberTextNormalizer::containtsNan(std::string_view text) const
{
    if (!m_nan.empty() && StringEx::containts(text, m_nan)) {
        return true;
    }
    if (StringEx::containts(text, StringEx::getDefaultNanNumberText())) {
        return true;
    }
    return false;
}

bool NumberTextNormalizer::isNan(std::string_view text) const
{
    if (!m_nan.empty() && m_nan == text) {
        return true;
    }
    if (StringEx::getDefaultNanNumberText() == text) {
        return true;
    }
    return false;
}

std::string NumberTextNormalizer::replace(std::string_view text) const
{
    std::string text2 = std::string{ text };
    text2 = StringEx::replace(text2, m_positiveSign, StringEx::getDefaultPositiveSignNumberText());
    text2 = StringEx::replace(text2, m_negativeSign, StringEx::getDefaultNegativeSignNumberText());
    text2 = StringEx::replace(text2, m_zeroSign, "");
    text2 = StringEx::replace(text2, m_point, StringEx::getDefaultPointNumberText());
    text2 = StringEx::replace(text2, m_infinity, StringEx::getDefaultInfinityNumberText());
    text2 = StringEx::replace(text2, m_nan, StringEx::getDefaultNanNumberText());
    return text2;
}

std::string NumberTextNormalizer::normalize(std::string_view text) const
{
    std::string text2 = std::string{ text };
    if (m_keepPositiveSign) {
        text2 = StringEx::replace(text2, m_positiveSign, StringEx::getDefaultPositiveSignNumberText());
    } else {
        text2 = deletePositiveSign(text2);
    }
    text2 = StringEx::replace(text2, m_negativeSign, StringEx::getDefaultNegativeSignNumberText());
    text2 = StringEx::replace(text2, m_zeroSign, "");
    text2 = StringEx::replace(text2, m_point, StringEx::getDefaultPointNumberText());
    text2 = StringEx::replace(text2, m_infinity, StringEx::getDefaultInfinityNumberText());
    text2 = StringEx::replace(text2, m_nan, StringEx::getDefaultNanNumberText());
    return text2;
}
