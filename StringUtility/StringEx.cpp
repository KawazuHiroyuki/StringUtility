#include "StringEx.h"

#include <algorithm>
#include <limits>
#include <string>
#include <stdexcept>
#include <charconv>

std::size_t StringEx::count(std::string_view text, std::string_view find)
{
    std::size_t count = 0;
    if (find.empty()) {
        return count;
    }
    auto first = std::begin(text);
    while (true)
    {
        auto found = std::search(first, text.end(), find.begin(), find.end());
        if (text.end() == found) {
            break;
        }

        count++;
        first = std::next(found, find.size());
        if (text.end() == first) {
            break;
        }
    }
    return count;
}

bool StringEx::containts(std::string_view text, std::string_view find)
{
    if (find.empty()) {
        return false;
    }
    if (std::string::npos == text.find(find)) {
        return false;
    }
    return true;
}

std::string StringEx::replace(std::string_view text, std::string_view from, std::string_view to)
{
    if (from.empty()) {
        return std::string{text};
    }
    std::string text2 = std::string{text};
    while (true) {
        auto found = text2.find(from);
        if (found == std::string::npos) {
            break;
        }
        text2.replace(found, from.size(), to);
    }
    return text2;
}

std::string StringEx::trimAll(std::string_view text)
{
    return replace(text, " ", "");
}

std::string StringEx::getDefaultPositiveSignNumberText()
{
    return "+";
}

std::string StringEx::getDefaultNegativeSignNumberText()
{
    return "-";
}

std::string StringEx::getDefaultPointNumberText()
{
    return ".";
}

std::string StringEx::getDefaultZeroNumberText()
{
    return "0";
}

std::string StringEx::getDefaultInfinityNumberText()
{
    static constexpr double value = std::numeric_limits<double>::infinity();
    std::string text = std::to_string(value);
    return text;
}

std::string StringEx::getDefaultNanNumberText()
{
    static constexpr double value = std::numeric_limits<double>::quiet_NaN();
    std::string text = std::to_string(value);
    return text;
}

bool StringEx::validateSingPartNumberText(std::string_view text, const NumberTextAlternaor& alternate)
{
    std::string text2 = trimAll(text);

    // 重複チェック
    int positive = alternate.countPositiveSign(text2);
    int negative = alternate.countNegativeSign(text2);
    int zero = alternate.countZeroSign(text2);
    if ((positive + negative + zero) > 1) {
        return false;
    }

    // 符号先頭チェック
    if (positive != 0) {
        if (!alternate.startsWithPositiveSign(text2)) {
            return false;
        }
    }
    if (negative != 0) {
        if (!alternate.startsWithNegativeSign(text2)) {
            return false;
        }
    }
    if (zero != 0) {
        if (!alternate.startsWithZeroSign(text2)) {
            return false;
        }
        if (alternate.startsWithZeroSign(text2) && !isZeroNumberText(text2, alternate)) {
            return false;
        }
    }
    return true;
}

bool StringEx::validateNumberPartNumberText(std::string_view text, const NumberTextAlternaor& alternate)
{
    // TODO NG 10AA

    std::string text2 = trimAll(text);
    text2 = alternate.normalize(text2);

    const char* str = text2.c_str();
    double value{};

    if (auto [ptr, ec] = std::from_chars(str, str + text2.size(), value); ec != std::errc{}) {
        return false;
    }

    return true;
}

bool StringEx::isPositiveNumberText(std::string_view text, const NumberTextAlternaor& alternate)
{
    std::string text2 = trimAll(text);
    if (alternate.isNan(text2)) {
        return false;
    }

    if (!validateSingPartNumberText(text2, alternate)) {
        throw std::runtime_error("invalid sign part.");
    }
    if (!validateNumberPartNumberText(text2, alternate)) {
        throw std::runtime_error("invalid number part.");
    }

    if (alternate.startsWithPositiveSign(text2)) {
        return true;
    }
    if (alternate.startsWithZeroSign(text2) && isZeroNumberText(text2, alternate)) { // Positive扱い
        return true;
    }
    if (alternate.startsWithNegativeSign(text2)) {
        return false;
    }
    return true; // 符号記号なし=Positive
}

bool StringEx::isNegativeNumberText(std::string_view text, const NumberTextAlternaor& alternate)
{
    std::string text2 = trimAll(text);
    if (alternate.isNan(text2)) {
        return false;
    }

    if (!validateSingPartNumberText(text2, alternate)) {
        throw std::runtime_error("invalid sign part.");
    }
    if (!validateNumberPartNumberText(text2, alternate)) {
        throw std::runtime_error("invalid number part.");
    }

    if (alternate.startsWithNegativeSign(text2)) {
        return true;
    }
    return false;
}

bool StringEx::isZeroNumberText(std::string_view text, const NumberTextAlternaor& alternate)
{
    std::string text2 = trimAll(text);
    text2 = alternate.normalize(text2);

    const char* str = text2.c_str();
    double value{};

    if (auto [ptr, ec] = std::from_chars(str, str + text2.size(), value); ec != std::errc{}) {
        return false;
    }

    if (value != 0.0) {
        return false;
    }

    return true;
}

bool StringEx::isInfinityNumberText(std::string_view text, const NumberTextAlternaor& alternate)
{
    // 検証
    if (!validateSingPartNumberText(text, alternate)) {
        return false;
    }
    if (!validateNumberPartNumberText(text, alternate)) {
        return false;
    }

    // Infinity判定
    std::string text2 = trimAll(text);
    text2 = deleteSignPartNumberText(text2, alternate); // 符号のみ削除
    if (alternate.isInfinity(text2)) {
        return true;
    }
    return false;
}

bool StringEx::isNanNumberText(std::string_view text, const NumberTextAlternaor& alternate)
{
    // 検証
    if (!validateSingPartNumberText(text, alternate)) {
        return false;
    }
    if (!validateNumberPartNumberText(text, alternate)) {
        return false;
    }

    // Nan判定
    std::string text2 = trimAll(text);
    if (alternate.isNan(text2)) {
        return true;
    }
    return false;
}

std::string StringEx::deleteSignPartNumberText(std::string_view text, const NumberTextAlternaor& alternate)
{
    std::string text2 = alternate.deletePositiveSign(text);
    text2 = alternate.deleteNegativeSign(text2);
    text2 = alternate.deleteZeroSign(text2);
    return text2;
}
