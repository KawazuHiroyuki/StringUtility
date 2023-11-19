#include "NumberTextNormalizer.h"

#include <algorithm>
#include <stdexcept>
#include "StringEx.h"

std::string NumberTextNormalizer::toDefaultText(std::string_view text) const
{
    std::string text2 = std::string{ text };
    text2 = StringEx::replace(text2, m_positiveSign, getDefaultPositiveSignText());
    text2 = StringEx::replace(text2, m_negativeSign, getDefaultNegativeSignText());
    text2 = StringEx::replace(text2, m_zeroSign, "");
    text2 = StringEx::replace(text2, m_point, getDefaultPointText());
    text2 = StringEx::replace(text2, m_infinity, getDefaultInfinityText());
    text2 = StringEx::replace(text2, m_nan, getDefaultNanText());
    return text2;
}

std::string NumberTextNormalizer::toAlternateText(std::string_view text) const
{
    std::string text2 = std::string{ text };
    text2 = StringEx::replace(text2, getDefaultPositiveSignText(), m_positiveSign);
    text2 = StringEx::replace(text2, getDefaultNegativeSignText(), m_negativeSign);
    //text2 = StringEx::replace(text2, m_zeroSign, "");
    text2 = StringEx::replace(text2, getDefaultPointText(), m_point);
    text2 = StringEx::replace(text2, getDefaultInfinityText(), m_infinity);
    text2 = StringEx::replace(text2, getDefaultNanText(), m_nan);
    return text2;
}

std::string NumberTextNormalizer::deleteSignPartNumberText(std::string_view text) const
{
    std::string text2 = deletePositiveSign(text);
    text2 = deleteNegativeSign(text2);
    text2 = deleteZeroSign(text2);
    return text2;
}

void NumberTextNormalizer::validateNumberText(std::string_view text) const
{
    if (!isValidNumberText(text)) {
        throw std::runtime_error("invalid number text.");
    }
}

bool NumberTextNormalizer::isValidNumberText(std::string_view text) const
{
    std::string text2 = StringEx::trimAll(text);

    // �����d���`�F�b�N
    int positive = countPositiveSign(text2);
    int negative = countNegativeSign(text2);
    int zero = countZeroSign(text2);
    if ((positive + negative + zero) > 1) {
        return false;
    }

    // �����擪�`�F�b�N
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

    // ���K��
    text2 = toDefaultText(text2);
    text2 = normalizePositiveSign(text2, false);

    // Nan
    if (isNan(text2)) {
        return true;
    }

    // Infinity
    text2 = deleteSignPartNumberText(text2); // �����̂ݍ폜
    if (isInfinity(text2)) {
        return true;
    }

    // �擪�`�F�b�N - charconv�̎d�l�ɍ��킹�āA�擪�̋���/�֎~�͉��L�Ƃ���B
    if (!isValidPrefixNumberText(text2)) {
        return false;
    }

    // �L�����l�e�L�X�g�`�F�b�N
    if (!isValidFiniteNumberText(text2)) {
        return false;
    }

    // ���l�ϊ�
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

    // ����
    validateNumberText(text2);

    // Nan�͏��false
    if (isNan(text2)) {
        return false;
    }

    // Positive����
    if (startsWithPositiveSign(text2)) {
        return true;
    }
    if (startsWithZeroSign(text2) && isZeroNumberText(text2)) { // Positive����
        return true;
    }
    if (startsWithNegativeSign(text2)) {
        return false;
    }
    return true; // �����L���Ȃ�=Positive
}

bool NumberTextNormalizer::isNegativeNumberText(std::string_view text) const
{
    std::string text2 = StringEx::trimAll(text);

    // ����
    validateNumberText(text2);

    // Nan�͏��false
    if (isNan(text2)) {
        return false;
    }

    // Negative����
    if (startsWithNegativeSign(text2)) {
        return true;
    }
    return false;
}

bool NumberTextNormalizer::isZeroNumberText(std::string_view text) const
{
    std::string text2 = StringEx::trimAll(text);

    // ����
    validateNumberText(text2);

    // ���K��
    text2 = toDefaultText(text2);
    text2 = normalizePositiveSign(text2, false); // �[���m�F���͐������s�v

    // ���l�ϊ�
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

bool NumberTextNormalizer::isInfinityNumberText(std::string_view text) const
{
    std::string text2 = StringEx::trimAll(text);

    // ����
    validateNumberText(text2);

    // Infinity����
    text2 = deleteSignPartNumberText(text2); // �����̂ݍ폜
    if (isInfinity(text2)) {
        return true;
    }
    return false;
}

bool NumberTextNormalizer::isNanNumberText(std::string_view text) const
{
    std::string text2 = StringEx::trimAll(text);

    // ����
    validateNumberText(text2);

    // Nan����
    if (isNan(text2)) {
        return true;
    }
    return false;
}

std::string NumberTextNormalizer::normalizeNumberText(std::string_view text) const
{
    std::string text2 = StringEx::trimAll(text);

    // ���K��
    text2 = toDefaultText(text2);
    text2 = normalizePositiveSign(text2, isKeepPositiveSign());
    text2 = normalizeFixedPoint(text2);
    text2 = normalizeZeroBase(text2);
    text2 = normalizeNegativeZero(text2);

    // ����
    validateNumberText(text2);
    return text2;
}

std::vector<std::string> NumberTextNormalizer::splitPartNumberText(std::string_view text) const
{
    std::string text2 = StringEx::trimAll(text);

    // ���K��
    text2 = toDefaultText(text2);
    text2 = normalizePositiveSign(text2, isKeepPositiveSign());
    text2 = normalizeFixedPoint(text2);
    text2 = normalizeZeroBase(text2);

    // ����
    validateNumberText(text2);

    // Nan
    if (isNan(text2)) {
        return std::vector<std::string>({"", getDefaultNanText(), ""});
    }

    // �����폜
    std::string sign = getSignPartNumberText(text2);
    text2 = deleteSignPartNumberText(text2);

    // Infinty
    if (isInfinity(text2)) {
        return std::vector<std::string>({sign, getDefaultInfinityText(), "" });
    }

    // ����
    auto splited = StringEx::split(text2, getDefaultPointText());
    splited.insert(splited.begin(), sign);
    if (3 != splited.size()) {
        splited.emplace_back("");
    }
    return splited;
}

std::string NumberTextNormalizer::getSignPartNumberText(std::string_view text) const
{
    std::string text2 = StringEx::trimAll(text);

    // ���K��
    text2 = toDefaultText(text2);
    text2 = normalizePositiveSign(text2, true); // �������擾�ł���K�v������̂ŁA�������͍폜���Ȃ�
    text2 = normalizeFixedPoint(text2);
    text2 = normalizeZeroBase(text2);

    // ����
    validateNumberText(text2);

    // �������o��
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

    // ���K��
    text2 = toDefaultText(text2);
    text2 = normalizePositiveSign(text2, false); // ��ɕ������̍폜�����̂ŁA�������폜�Œ�
    text2 = normalizeFixedPoint(text2);
    text2 = normalizeZeroBase(text2);

    // ����
    validateNumberText(text2);

    // Nan
    if (isNan(text2)) {
        return "";
    }

    // �����폜
    text2 = deleteSignPartNumberText(text2);

    // Infinty
    if (isInfinity(text2)) {
        return "";
    }

    // ����
    auto splited = StringEx::split(text2, getDefaultPointText());
    return splited.front();
}

std::string NumberTextNormalizer::getDecimalPartNumberText(std::string_view text) const
{
    std::string text2 = StringEx::trimAll(text);

    // ���K��
    text2 = toDefaultText(text2);
    text2 = normalizePositiveSign(text2, false); // ��ɕ������̍폜�����̂ŁA�������폜�Œ�
    text2 = normalizeFixedPoint(text2);
    text2 = normalizeZeroBase(text2);

    // ����
    validateNumberText(text2);

    // Nan
    if (isNan(text2)) {
        return "";
    }

    // �����폜
    text2 = deleteSignPartNumberText(text2);

    // Infinty
    if (isInfinity(text2)) {
        return "";
    }

    // ����
    auto splited = StringEx::split(text2, getDefaultPointText());
    if (1 == splited.size()) {
        return "";
    }
    return splited.back();
}

bool NumberTextNormalizer::isValidPrefixNumberText(std::string_view text) const
{
    // OK: charconv�̎d�l�ɍ��킹�āA�擪�̋��͉��L�Ƃ���B
    // X
    // .X
    // -X

    // NG: charconv�̎d�l�ɍ��킹�āA�擪�̋֎~�͉��L�Ƃ���B
    if ((1 == text.size()) && text.starts_with(getDefaultPointText())) { // NG .
        return false;
    }
    if ((2 == text.size()) && text.starts_with(getDefaultNegativeSignText() + getDefaultPointText())) { // NG -.
        return false;
    }
    return true;
}

bool NumberTextNormalizer::isValidFiniteNumberText(std::string_view text) const
{
    auto found = std::find_if_not(text.begin(), text.end(), [](std::string::value_type c) {
        return StringEx::containts(getDefaultFiniteNumberChars(), std::string(1, c)); });
    if (text.end() != found) {
        return false; // -0-9.�ȊO��NG
    }
    return true;
}

bool NumberTextNormalizer::isNegativeZeroNumberText(std::string_view text) const
{
    bool zero = isZeroNumberText(text);

    // -0 �� 0
    // -0. �� 0.
    if (zero && text.starts_with(getDefaultNegativeSignText() + getDefaultZeroText())) {
        return true;
    }
    // -.0
    if (zero && text.starts_with(getDefaultNegativeSignText() + getDefaultPointText())) {
        return true;
    }
    return false;
}

bool NumberTextNormalizer::isInfinity(std::string_view text) const
{
    if (!m_infinity.empty() && m_infinity == text) {
        return true;
    }
    if (getDefaultInfinityText() == text) {
        return true;
    }
    return false;
}

bool NumberTextNormalizer::isNan(std::string_view text) const
{
    if (!m_nan.empty() && m_nan == text) {
        return true;
    }
    if (getDefaultNanText() == text) {
        return true;
    }
    return false;
}

std::size_t NumberTextNormalizer::countPositiveSign(std::string_view text) const
{
    std::size_t count = StringEx::count(text, m_positiveSign) + StringEx::count(text, getDefaultPositiveSignText());
    return count;
}

std::size_t NumberTextNormalizer::countNegativeSign(std::string_view text) const
{
    std::size_t count = StringEx::count(text, m_negativeSign) + StringEx::count(text, getDefaultNegativeSignText());
    return count;
}

std::size_t NumberTextNormalizer::countZeroSign(std::string_view text) const
{
    std::size_t count = StringEx::count(text, m_zeroSign);
    return count;
}

bool NumberTextNormalizer::containtsInfinity(std::string_view text) const
{
    if (!m_infinity.empty() && StringEx::containts(text, m_infinity)) {
        return true;
    }
    if (StringEx::containts(text, getDefaultInfinityText())) {
        return true;
    }
    return false;
}

bool NumberTextNormalizer::containtsNan(std::string_view text) const
{
    if (!m_nan.empty() && StringEx::containts(text, m_nan)) {
        return true;
    }
    if (StringEx::containts(text, getDefaultNanText())) {
        return true;
    }
    return false;
}

bool NumberTextNormalizer::startsWithPositiveSign(std::string_view text) const
{
    if (!m_positiveSign.empty() && text.starts_with(m_positiveSign)) {
        return true;
    }
    if (text.starts_with(getDefaultPositiveSignText())) {
        return true;
    }
    return false;
}

bool NumberTextNormalizer::startsWithNegativeSign(std::string_view text) const
{
    if (!m_negativeSign.empty() && text.starts_with(m_negativeSign)) {
        return true;
    }
    if (text.starts_with(getDefaultNegativeSignText())) {
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

std::string NumberTextNormalizer::deletePositiveSign(std::string_view text) const 
{
    std::string text2 = std::string{ text };
    text2 = StringEx::replace(text2, m_positiveSign, "");
    text2 = StringEx::replace(text2, getDefaultPositiveSignText(), "");
    return text2;
}

std::string NumberTextNormalizer::deleteNegativeSign(std::string_view text) const {
    std::string text2 = std::string{ text };
    text2 = StringEx::replace(text2, m_negativeSign, "");
    text2 = StringEx::replace(text2, getDefaultNegativeSignText(), "");
    return text2;
}

std::string NumberTextNormalizer::deleteZeroSign(std::string_view text) const {
    std::string text2 = std::string{ text };
    text2 = StringEx::replace(text2, m_zeroSign, "");
    return text2;
}

std::string NumberTextNormalizer::pickupPositiveSign(std::string_view text) const
{
    if (!m_positiveSign.empty() && StringEx::containts(text, m_positiveSign)) {
        return m_positiveSign;
    }
    if (StringEx::containts(text, getDefaultPositiveSignText())) {
        return getDefaultPositiveSignText();
    }
    return "";
}

std::string NumberTextNormalizer::pickupNegativeSign(std::string_view text) const
{
    if (!m_negativeSign.empty() && StringEx::containts(text, m_negativeSign)) {
        return m_negativeSign;
    }
    if (StringEx::containts(text, getDefaultNegativeSignText())) {
        return getDefaultNegativeSignText();
    }
    return "";
}

std::string NumberTextNormalizer::pickupZeroSign(std::string_view text) const
{
    if (!m_zeroSign.empty() && StringEx::containts(text, m_zeroSign)) {
        return m_zeroSign;
    }
    return "";
}

std::string NumberTextNormalizer::normalizePositiveSign(std::string_view text, bool keepPositiveSign) const
{
    std::string text2 = std::string{ text };
    if (!keepPositiveSign) {
        text2 = deletePositiveSign(text2);
    }
    return text2;
}

std::string NumberTextNormalizer::normalizeNegativeZero(std::string_view text) const
{
    std::string text2 = StringEx::trimAll(text);
    if (isNegativeZeroNumberText(text2)) {
        text2 = deleteSignPartNumberText(text2);
    }
    return text2;
}

std::string NumberTextNormalizer::normalizeFixedPoint(std::string_view text) const
{
    std::string text2 = std::string(text);
    if (containtsNan(text2) || containtsInfinity(text2)) {
        return text2;
    }

    if (isFixupFixedPoint()) {
        // X -> X.
        if (!StringEx::containts(text2, getDefaultPointText())) {
            text2 = text2 + getDefaultPointText();
        }
    }
    return text2;
}

std::string NumberTextNormalizer::normalizeZeroBase(std::string_view text) const
{
    std::string text2 = std::string(text);
    if (containtsNan(text2) || containtsInfinity(text2)) {
        return text2;
    }

    // not fixup .
    // not fixup -.
    if (!isValidPrefixNumberText(text2)) {
        return text2;
    }

    // .X -> 0.X
    if (text2.starts_with(getDefaultPointText())) {
        text2 = getDefaultZeroText() + text2;
    }

    // X. -> X.0
    if (text2.ends_with(getDefaultPointText())) {
        text2 = text2 + getDefaultZeroText();
    }

    // -.X -> -0.X
    if (text2.starts_with(getDefaultNegativeSignText() + getDefaultPointText())) {
        std::string zero = getDefaultZeroText();
        text2.insert(std::next(text2.begin(), 1), zero.begin(), zero.end());
    }
    return text2;
}
