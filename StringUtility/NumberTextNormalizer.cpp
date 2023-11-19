#include "NumberTextNormalizer.h"

#include <algorithm>
#include <stdexcept>
#include "StringEx.h"

void NumberTextNormalizer::validateNumberText(std::string_view text) const
{
    if (!isNumberText(text)) {
        throw std::runtime_error("invalid number text.");
    }
}

bool NumberTextNormalizer::isNumberText(std::string_view text) const
{
    std::string text2 = StringEx::trimAll(text);

    // 符号重複チェック
    int positive = countPositiveSign(text2);
    int negative = countNegativeSign(text2);
    int zero = countZeroSign(text2);
    if ((positive + negative + zero) > 1) {
        return false;
    }

    // 符号先頭チェック
    if (positive != 0) {
        if (!startsWithPositiveSign(text2)) {
            return false;
        }
    }
    if (negative != 0) {
        if (!startsWithNegativeSign(text2)) {
            return false;
        }
    }
    if (zero != 0) {
        if (!startsWithZeroSign(text2)) {
            return false;
        }
    }

    // 正規化
    text2 = alternate(text2);
    text2 = normalizePositiveSing(text2);

    // Nan
    if (isNan(text2)) {
        return true;
    }

    // Infinity
    text2 = deleteSignPartNumberText(text2); // 符号のみ削除
    if (isInfinity(text2)) {
        return true;
    }

    // 末尾チェック
    auto found = std::find_if_not(text2.begin(), text2.end(), [](std::string::value_type c) { return StringEx::containts("-.0123456789", std::string(1, c)); });
    if (text2.end() != found) {
        return false; // -0-9.以外はNG
    }

    // 数値変換
    try {
        double value = StringEx::toNumber(text2);
        return true;
    }
    catch (...) {
        return false;
    }
}

bool NumberTextNormalizer::isPositiveNumberText(std::string_view text) const
{
    std::string text2 = StringEx::trimAll(text);

    // 検証
    validateNumberText(text2);

    // Nanは常にfalse
    if (isNan(text2)) {
        return false;
    }

    // Positive判定
    if (startsWithPositiveSign(text2)) {
        return true;
    }
    if (startsWithZeroSign(text2) && isZeroNumberText(text2)) { // Positive扱い
        return true;
    }
    if (startsWithNegativeSign(text2)) {
        return false;
    }
    return true; // 符号記号なし=Positive
}

bool NumberTextNormalizer::isNegativeNumberText(std::string_view text) const
{
    std::string text2 = StringEx::trimAll(text);

    // 検証
    validateNumberText(text2);

    // Nanは常にfalse
    if (isNan(text2)) {
        return false;
    }

    // Negative判定
    if (startsWithNegativeSign(text2)) {
        return true;
    }
    return false;
}

bool NumberTextNormalizer::isZeroNumberText(std::string_view text) const
{
    std::string text2 = StringEx::trimAll(text);

    // 検証
    validateNumberText(text2);

    // 正規化
    text2 = alternate(text2);
    text2 = normalizePositiveSing(text2);

    // 数値変換
    try {
        double value = StringEx::toNumber(text2);
        if (value == 0.0) {
            return true;
        }
        return false;
    }
    catch (...) {
        return false;
    }
}

bool NumberTextNormalizer::isNegativeZeroNumberText(std::string_view text) const
{
    if (!isNegativeNumberText(text)) {
        return false;
    }
    if (!isZeroNumberText(text)) {
        return false;
    }
    return true;
}

bool NumberTextNormalizer::isInfinityNumberText(std::string_view text) const
{
    std::string text2 = StringEx::trimAll(text);

    // 検証
    validateNumberText(text2);

    // Infinity判定
    text2 = deleteSignPartNumberText(text2); // 符号のみ削除
    if (isInfinity(text2)) {
        return true;
    }
    return false;
}

bool NumberTextNormalizer::isNanNumberText(std::string_view text) const
{
    std::string text2 = StringEx::trimAll(text);

    // 検証
    validateNumberText(text2);

    // Nan判定
    if (isNan(text2)) {
        return true;
    }
    return false;
}

std::string NumberTextNormalizer::normalizeNumberText(std::string_view text) const
{
    std::string text2 = StringEx::trimAll(text);

    // 正規化
    text2 = alternate(text2);
    text2 = normalizePositiveSing(text2);

    if (isFixupFixedPoint() && !containtsNan(text2) && !containtsInfinity(text2)) {
        // X -> X.
        if (!StringEx::containts(text2, getDefaultPointNumberText())) {
            text2 = text2 + getDefaultPointNumberText();
        }

        // .X -> 0.X
        if (text2.starts_with(getDefaultPointNumberText())) {
            text2 = getDefaultZeroNumberText() + text2;
        }

        // X. -> X.0
        if (text2.ends_with(getDefaultPointNumberText())) {
            text2 = text2 + getDefaultZeroNumberText();
        }
    }

    // -0 -> 0
    if (isNegativeZeroNumberText(text2)) {
        text2 = deleteSignPartNumberText(text2);
    }

    // 検証
    validateNumberText(text2);
    return text2;
}

std::string NumberTextNormalizer::deleteSignPartNumberText(std::string_view text) const
{
    std::string text2 = deletePositiveSign(text);
    text2 = deleteNegativeSign(text2);
    text2 = deleteZeroSign(text2);
    return text2;
}

std::string NumberTextNormalizer::getSignPartNumberText(std::string_view text) const
{
    std::string text2 = StringEx::trimAll(text);

    // 正規化
    text2 = alternate(text2);
    text2 = normalizePositiveSing(text2);

    // 検証
    validateNumberText(text2);

    // 符号取り出し
    std::string sign = pickupPositiveSign(text2);
    if (!sign.empty()) {
        return sign;
    }
    sign = pickupNegativeSign(text2);
    if (!sign.empty()) {
        return sign;
    }
    sign = pickupZeroSign(text2);
    return sign;
}

std::string NumberTextNormalizer::getIntegerPartNumberText(std::string_view text) const
{
    std::string text2 = StringEx::trimAll(text);

    // 正規化
    text2 = alternate(text2);
    text2 = normalizePositiveSing(text2);

    // 検証
    validateNumberText(text2);

    // Nan
    if (isNan(text2)) {
        return "";
    }

    // 符号符号削除
    text2 = deleteSignPartNumberText(text2);

    // Infinty
    if (isInfinity(text2)) {
        return "";
    }

    // 分割
    auto splited = StringEx::split(text2, getDefaultPointNumberText());
    return splited.front();
}

std::string NumberTextNormalizer::getDecimalPartNumberText(std::string_view text) const
{
    std::string text2 = StringEx::trimAll(text);

    // 正規化
    text2 = alternate(text2);
    text2 = normalizePositiveSing(text2);

    // 検証
    validateNumberText(text2);

    // Nan
    if (isNan(text2)) {
        return "";
    }

    // 符号符号削除
    text2 = deleteSignPartNumberText(text2);

    // Infinty
    if (isInfinity(text2)) {
        return "";
    }

    // 分割
    auto splited = StringEx::split(text2, getDefaultPointNumberText());
    if (1 == splited.size()) {
        return "";
    }
    return splited.back();
}

std::size_t NumberTextNormalizer::countPositiveSign(std::string_view text) const
{
    std::size_t count = StringEx::count(text, m_positiveSign) + StringEx::count(text, getDefaultPositiveSignNumberText());
    return count;
}

bool NumberTextNormalizer::containtsPositiveSign(std::string_view text) const
{
    if (!m_positiveSign.empty() && StringEx::containts(text, m_positiveSign)) {
        return true;
    }
    if (StringEx::containts(text, getDefaultPositiveSignNumberText())) {
        return true;
    }
    return false;
}

bool NumberTextNormalizer::startsWithPositiveSign(std::string_view text) const
{
    if (!m_positiveSign.empty() && text.starts_with(m_positiveSign)) {
        return true;
    }
    if (text.starts_with(getDefaultPositiveSignNumberText())) {
        return true;
    }
    return false;
}

std::string NumberTextNormalizer::deletePositiveSign(std::string_view text) const 
{
    std::string text2 = std::string{ text };
    text2 = StringEx::replace(text2, m_positiveSign, "");
    text2 = StringEx::replace(text2, getDefaultPositiveSignNumberText(), "");
    return text2;
}

std::string NumberTextNormalizer::pickupPositiveSign(std::string_view text) const
{
    if (!m_positiveSign.empty() && StringEx::containts(text, m_positiveSign)) {
        return m_positiveSign;
    }
    if (StringEx::containts(text, getDefaultPositiveSignNumberText())) {
        return getDefaultPositiveSignNumberText();
    }
    return "";
}

std::size_t NumberTextNormalizer::countNegativeSign(std::string_view text) const
{
    std::size_t count = StringEx::count(text, m_negativeSign) + StringEx::count(text, getDefaultNegativeSignNumberText());
    return count;
}

bool NumberTextNormalizer::containtsNegativeSign(std::string_view text) const
{
    if (!m_negativeSign.empty() && StringEx::containts(text, m_negativeSign)) {
        return true;
    }
    if (StringEx::containts(text, getDefaultNegativeSignNumberText())) {
        return true;
    }
    return false;
}

bool NumberTextNormalizer::startsWithNegativeSign(std::string_view text) const
{
    if (!m_negativeSign.empty() && text.starts_with(m_negativeSign)) {
        return true;
    }
    if (text.starts_with(getDefaultNegativeSignNumberText())) {
        return true;
    }
    return false;
}

std::string NumberTextNormalizer::deleteNegativeSign(std::string_view text) const {
    std::string text2 = std::string{ text };
    text2 = StringEx::replace(text2, m_negativeSign, "");
    text2 = StringEx::replace(text2, getDefaultNegativeSignNumberText(), "");
    return text2;
}

std::string NumberTextNormalizer::pickupNegativeSign(std::string_view text) const
{
    if (!m_negativeSign.empty() && StringEx::containts(text, m_negativeSign)) {
        return m_negativeSign;
    }
    if (StringEx::containts(text, getDefaultNegativeSignNumberText())) {
        return getDefaultNegativeSignNumberText();
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
    std::size_t count = StringEx::count(text, m_point) + StringEx::count(text, getDefaultPointNumberText());
    return count;
}

bool NumberTextNormalizer::containtsPoint(std::string_view text) const
{
    if (!m_point.empty() && StringEx::containts(text, m_point)) {
        return true;
    }
    if (StringEx::containts(text, getDefaultPointNumberText())) {
        return true;
    }
    return false;
}

bool NumberTextNormalizer::containtsInfinity(std::string_view text) const
{
    if (!m_infinity.empty() && StringEx::containts(text, m_infinity)) {
        return true;
    }
    if (StringEx::containts(text, getDefaultInfinityNumberText())) {
        return true;
    }
    return false;
}

bool NumberTextNormalizer::isInfinity(std::string_view text) const
{
    if (!m_infinity.empty() && m_infinity == text) {
        return true;
    }
    if (getDefaultInfinityNumberText() == text) {
        return true;
    }
    return false;
}

bool NumberTextNormalizer::containtsNan(std::string_view text) const
{
    if (!m_nan.empty() && StringEx::containts(text, m_nan)) {
        return true;
    }
    if (StringEx::containts(text, getDefaultNanNumberText())) {
        return true;
    }
    return false;
}

bool NumberTextNormalizer::isNan(std::string_view text) const
{
    if (!m_nan.empty() && m_nan == text) {
        return true;
    }
    if (getDefaultNanNumberText() == text) {
        return true;
    }
    return false;
}

std::string NumberTextNormalizer::alternate(std::string_view text) const
{
    std::string text2 = std::string{ text };
    text2 = StringEx::replace(text2, m_positiveSign, getDefaultPositiveSignNumberText());
    text2 = StringEx::replace(text2, m_negativeSign, getDefaultNegativeSignNumberText());
    text2 = StringEx::replace(text2, m_zeroSign, "");
    text2 = StringEx::replace(text2, m_point, getDefaultPointNumberText());
    text2 = StringEx::replace(text2, m_infinity, getDefaultInfinityNumberText());
    text2 = StringEx::replace(text2, m_nan, getDefaultNanNumberText());
    return text2;
}

std::string NumberTextNormalizer::normalizePositiveSing(std::string_view text) const
{
    std::string text2 = std::string{ text };
    if (!m_keepPositiveSign) {
        text2 = deletePositiveSign(text2);
    }
    return text2;
}

