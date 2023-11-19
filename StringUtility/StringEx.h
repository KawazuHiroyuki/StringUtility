#pragma

#include <string>
#include <string_view>

#include "NumberTextAlternate.h"

class StringEx {
public:
    static bool containts(std::string_view text, std::string_view find);
    static std::string replace(std::string_view text, std::string_view from, std::string_view to);
    static std::string trimAll(std::string_view text);

    static std::string getDefaultPositiveSignNumberText();
    static std::string getDefaultNegativeSignNumberText();
    static std::string getDefaultPointNumberText();
    static std::string getDefaultZeroNumberText();
    static std::string getDefaultInfinityNumberText();
    static std::string getDefaultNanNumberText();

    static bool validateSingPart(std::string_view text, const NumberTextAlternaor& alternate);

    static bool isPositiveNumberText(std::string_view text, const NumberTextAlternaor& alternate);
    static bool isNegativeNumberText(std::string_view text, const NumberTextAlternaor& alternate);
    static bool isZeroNumberText(std::string_view text, const NumberTextAlternaor& alternate);
    static bool isInfinityNumberText(std::string_view text, const NumberTextAlternaor& alternate);
    static bool isNanNumberText(std::string_view text, const NumberTextAlternaor& alternate);
    static bool isNumberText(std::string_view text, const NumberTextAlternaor& alternate);

    static std::string normalizeNumberText(std::string_view text, const NumberTextAlternaor& alternate);

    static std::string deleteSignPartNumberText(std::string_view text, const NumberTextAlternaor& alternate);

    static std::string getSignPartNumberText();
    static std::string getIntegerPartNumberText();
    static std::string getDecimalPartNumberText();
};
