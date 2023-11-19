#pragma

#include <string>
#include <string_view>
#include <cstddef>
#include <vector>
#include "NumberTextNormalizer.h"

class StringEx {
public:
    static std::size_t count(std::string_view text, std::string_view find);
    static bool containts(std::string_view text, std::string_view find);
    static std::vector<std::string> split(std::string_view text, std::string_view separator);
    static std::string replace(std::string_view text, std::string_view from, std::string_view to);
    static std::string trimAll(std::string_view text);

    static std::string getDefaultPositiveSignNumberText();
    static std::string getDefaultNegativeSignNumberText();
    static std::string getDefaultPointNumberText();
    static std::string getDefaultZeroNumberText();
    static std::string getDefaultInfinityNumberText();
    static std::string getDefaultNanNumberText();

    static void validateNumberText(std::string_view text, const NumberTextNormalizer& normalizer = NumberTextNormalizer{});

    static bool isValidNumberText(std::string_view text, const NumberTextNormalizer& normalizer = NumberTextNormalizer{});
    static bool isPositiveNumberText(std::string_view text, const NumberTextNormalizer& normalizer = NumberTextNormalizer{});
    static bool isNegativeNumberText(std::string_view text, const NumberTextNormalizer& normalizer = NumberTextNormalizer{});
    static bool isZeroNumberText(std::string_view text, const NumberTextNormalizer& normalizer = NumberTextNormalizer{});
    //static bool isNegativeZeroNumberText(std::string_view text, const NumberTextNormalizer& normalizer = NumberTextNormalizer{});
    static bool isInfinityNumberText(std::string_view text, const NumberTextNormalizer& normalizer = NumberTextNormalizer{});
    static bool isNanNumberText(std::string_view text, const NumberTextNormalizer& normalizer = NumberTextNormalizer{});

    static std::string normalizeNumberText(std::string_view text, const NumberTextNormalizer& normalizer = NumberTextNormalizer{});

    static std::string deleteSignPartNumberText(std::string_view text, const NumberTextNormalizer& normalizer = NumberTextNormalizer{});

    static std::vector<std::string> splitPartNumberText(std::string_view text, const NumberTextNormalizer& normalizer = NumberTextNormalizer{});
    static std::string getSignPartNumberText(std::string_view text, const NumberTextNormalizer& normalizer = NumberTextNormalizer{});
    static std::string getIntegerPartNumberText(std::string_view text, const NumberTextNormalizer& normalizer = NumberTextNormalizer{});
    static std::string getDecimalPartNumberText(std::string_view text, const NumberTextNormalizer& normalizer = NumberTextNormalizer{});

    // no impl
    static double toNumber(std::string_view text);
};
