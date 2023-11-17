#include "StringEx.h"

#include <limits>
#include <string>
#include <stdexcept>

bool StringEx::containts(std::string_view text, std::string_view find)
{
    if (std::string::npos == text.find(find)) {
        return false;
    }
    return true;
}

std::string StringEx::replace(std::string_view text, std::string_view from, std::string_view to)
{
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

bool StringEx::isInfinityNumberText(std::string_view text, const NumberTextAlternate& alternate)
{
    if (text.empty()) {
        return false;
    }
    std::string text2 = trimAll(text);
    text2 = deleteSignPartNumberText(text2, alternate);
    if (alternate.isInfinity(text2)) {
        return true;
    }
    if (getDefaultInfinityNumberText() == text2) {
        return true;
    }
    return false;
}

bool StringEx::isNanNumberText(std::string_view text, const NumberTextAlternate& alternate)
{
    if (text.empty()) {
        return false;
    }
    std::string text2 = trimAll(text);
    if (alternate.isNan(text2)) {
        return true;
    }
    if (getDefaultNanNumberText() == text2) {
        return true;
    }
    return false;
}

bool StringEx::validateSingPart(std::string_view text, const NumberTextAlternate& alternate)
{
    if (text.empty()) {
        return true;
    }

    std::string text2 = trimAll(text);

    // 重複チェック
    // 符号先頭チェック


    bool exists = false;

    return true;
}

bool StringEx::isPositiveNumberText(std::string_view text, const NumberTextAlternate& alternate)
{
    std::string text2 = trimAll(text);
    if (!validateSingPart(text2, alternate)) {
        throw std::runtime_error("invalid sign part.");
    }
    if (alternate.startsWithPositiveSign(text2)) {
        return true;
    }
    if (text.starts_with(getDefaultPositiveSignNumberText())) {
        return true;
    }
    if (alternate.startsWithZeroSign(text2)) { // Positive扱い
        return true;
    }
    if (alternate.startsWithNegativeSign(text2)) {
        return false;
    }
    if (text.starts_with(getDefaultNegativeSignNumberText())) {
        return false;
    }
    return true; // 符号記号なし=Positive
}

bool StringEx::isNegativeNumberText(std::string_view text, const NumberTextAlternate& alternate)
{
    std::string text2 = trimAll(text);
    if (!validateSingPart(text2, alternate)) {
        throw std::runtime_error("invalid sign part.");
    }
    if (alternate.startsWithNegativeSign(text2)) {
        return true;
    }
    if (text.starts_with(getDefaultNegativeSignNumberText())) {
        return true;
    }
    return false;
}

std::string StringEx::deleteSignPartNumberText(std::string_view text, const NumberTextAlternate& alternate)
{
    if (text.empty()) {
        return std::string{text};
    }
    std::string text2 = alternate.deletePositiveSign(text);
    text2 = replace(text2, getDefaultPositiveSignNumberText(), "");
    text2 = alternate.deleteNegativeSign(text2);
    text2 = replace(text2, getDefaultNegativeSignNumberText(), "");
    text2 = alternate.deleteZeroSign(text2);
    return text2;
}

