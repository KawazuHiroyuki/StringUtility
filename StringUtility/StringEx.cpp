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

std::vector<std::string> StringEx::split(std::string_view text, std::string_view separator)
{
    std::vector<std::string> splited = {};
    if (text.empty()) {
        return splited;
    }
    if ((1 == text.size()) || separator.empty()) {
        splited.emplace_back(text);
        return splited;
    }

    auto first = std::begin(text);
    while (true)
    {
        auto found = std::search(first, text.end(), separator.begin(), separator.end());

        splited.emplace_back(first, found);
        if (text.end() == found) {
            break;
        }

        first = found;
        std::advance(first, separator.size());
    }

    return splited;
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
    return NumberTextNormalizer::getDefaultPositiveSignText();
}

std::string StringEx::getDefaultNegativeSignNumberText()
{
    return NumberTextNormalizer::getDefaultNegativeSignText();
}

std::string StringEx::getDefaultPointNumberText()
{
    return NumberTextNormalizer::getDefaultPointText();
}

std::string StringEx::getDefaultZeroNumberText()
{
    return NumberTextNormalizer::getDefaultZeroText();
}

std::string StringEx::getDefaultInfinityNumberText()
{
    return NumberTextNormalizer::getDefaultInfinityText();
}

std::string StringEx::getDefaultNanNumberText()
{
    return NumberTextNormalizer::getDefaultNanText();
}

void StringEx::validateNumberText(std::string_view text, const NumberTextNormalizer& normalizer)
{
    normalizer.validateNumberText(text);
}

bool StringEx::isValidNumberText(std::string_view text, const NumberTextNormalizer& normalizer)
{
    return normalizer.isValidNumberText(text);
}

bool StringEx::isPositiveNumberText(std::string_view text, const NumberTextNormalizer& normalizer)
{
    return normalizer.isPositiveNumberText(text);
}

bool StringEx::isNegativeNumberText(std::string_view text, const NumberTextNormalizer& normalizer)
{
    return normalizer.isNegativeNumberText(text);
}

bool StringEx::isZeroNumberText(std::string_view text, const NumberTextNormalizer& normalizer)
{
    return normalizer.isZeroNumberText(text);
}

bool StringEx::isNegativeZeroNumberText(std::string_view text, const NumberTextNormalizer& normalizer)
{
    return normalizer.isNegativeZeroNumberText(text);
}

bool StringEx::isInfinityNumberText(std::string_view text, const NumberTextNormalizer& normalizer)
{
    return normalizer.isInfinityNumberText(text);
}

bool StringEx::isNanNumberText(std::string_view text, const NumberTextNormalizer& normalizer)
{
    return normalizer.isNanNumberText(text);
}

std::string StringEx::normalizeNumberText(std::string_view text, const NumberTextNormalizer& normalizer)
{
    return normalizer.normalizeNumberText(text);
}

std::string StringEx::deleteSignPartNumberText(std::string_view text, const NumberTextNormalizer& normalizer)
{
    return normalizer.deleteSignPartNumberText(text);
}

std::string StringEx::getSignPartNumberText(std::string_view text, const NumberTextNormalizer& normalizer)
{
    return normalizer.getSignPartNumberText(text);
}

std::string StringEx::getIntegerPartNumberText(std::string_view text, const NumberTextNormalizer& normalizer)
{
    return normalizer.getIntegerPartNumberText(text);
}

std::string StringEx::getDecimalPartNumberText(std::string_view text, const NumberTextNormalizer& normalizer)
{
    return normalizer.getDecimalPartNumberText(text);
}


double StringEx::toNumber(std::string_view text)
{
    std::string text2 = trimAll(text);

    // êîílïœä∑
    const char* str = text2.c_str();
    double value{};
    if (auto [ptr, ec] = std::from_chars(str, str + text2.size(), value); ec != std::errc{}) {
        throw std::runtime_error("invalid number text.");
    }
    return value;
}
