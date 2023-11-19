#pragma

#include <string>
#include <string_view>
#include <cstddef>
#include <vector>
#include "NumberTextAlternator.h"

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

    static bool validateNumberText(std::string_view text, const NumberTextAlternaor& alternate = NumberTextAlternaor{});

    static bool isPositiveNumberText(std::string_view text, const NumberTextAlternaor& alternate = NumberTextAlternaor{});
    static bool isNegativeNumberText(std::string_view text, const NumberTextAlternaor& alternate = NumberTextAlternaor{});
    static bool isZeroNumberText(std::string_view text, const NumberTextAlternaor& alternate = NumberTextAlternaor{});
    static bool isNegativeZeroNumberText(std::string_view text, const NumberTextAlternaor& alternate = NumberTextAlternaor{});
    static bool isInfinityNumberText(std::string_view text, const NumberTextAlternaor& alternate = NumberTextAlternaor{});
    static bool isNanNumberText(std::string_view text, const NumberTextAlternaor& alternate = NumberTextAlternaor{});
    static bool isNumberText(std::string_view text, const NumberTextAlternaor& alternate = NumberTextAlternaor{});

    static std::string normalizeNumberText(std::string_view text, bool fixedPoint, const NumberTextAlternaor& alternate = NumberTextAlternaor{});

    static std::string deleteSignPartNumberText(std::string_view text, const NumberTextAlternaor& alternate = NumberTextAlternaor{});

    static std::string getSignPartNumberText(std::string_view text, const NumberTextAlternaor& alternate = NumberTextAlternaor{});
    static std::string getIntegerPartNumberText(std::string_view text, const NumberTextAlternaor& alternate = NumberTextAlternaor{});
    static std::string getDecimalPartNumberText(std::string_view text, const NumberTextAlternaor& alternate = NumberTextAlternaor{});
};
