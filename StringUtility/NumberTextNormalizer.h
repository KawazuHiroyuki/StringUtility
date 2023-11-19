#pragma once

#include <string_view>
#include <string>
#include <cstddef>
#include <vector>
#include <optional>
#include <limits>

class NumberTextNormalizer {
    bool m_keepPositiveSign = false;
    bool m_fixupFixedPoint = false;
    std::string m_positiveSign;
    std::string m_negativeSign;
    std::string m_zeroSign;
    std::string m_point;
    std::string m_infinity;
    std::string m_nan;

public:
    NumberTextNormalizer& setKeepPositiveSign(bool keep = true) {
        m_keepPositiveSign = keep;
        return *this;
    }
    bool isKeepPositiveSign() const {
        return m_keepPositiveSign;
    }

    NumberTextNormalizer& setFixupFixedPoint(bool fixup = true) {
        m_fixupFixedPoint = fixup;
        return *this;
    }
    bool isFixupFixedPoint() const {
        return m_fixupFixedPoint;
    }

    NumberTextNormalizer& setAlternatePositiveSignText(std::string_view alternate) {
        m_positiveSign = std::string{ alternate };
        return *this;
    }
    NumberTextNormalizer& setAlternateNegativeSignText(std::string_view alternate) {
        m_negativeSign = std::string{ alternate };
        return *this;
    }
    NumberTextNormalizer& setAlternateZeroSignText(std::string_view alternate) {
        m_zeroSign = std::string{ alternate };
        return *this;
    }
    NumberTextNormalizer& setAlternatePointText(std::string_view alternate) {
        m_point = std::string{ alternate };
        return *this;
    }
    NumberTextNormalizer& setAlternateInfinityText(std::string_view alternate) {
        m_infinity = std::string{ alternate };
        return *this;
    }
    NumberTextNormalizer& setAlternateNanText(std::string_view alternate) {
        m_nan = std::string{alternate};
        return *this;
    }

    static std::string getDefaultPositiveSignText()
    {
        return "+";
    }

    static std::string getDefaultNegativeSignText()
    {
        return "-";
    }

    static std::string getDefaultPointText()
    {
        return ".";
    }

    static std::string getDefaultZeroText()
    {
        return "0";
    }

    static std::string getDefaultInfinityText()
    {
        static constexpr double value = std::numeric_limits<double>::infinity();
        std::string text = std::to_string(value);
        return text;
    }

    static std::string getDefaultNanText()
    {
        static constexpr double value = std::numeric_limits<double>::quiet_NaN();
        std::string text = std::to_string(value);
        return text;
    }

    void validateNumberText(std::string_view text) const;
    bool isNumberText(std::string_view text) const;
    bool isPositiveNumberText(std::string_view text) const;
    bool isNegativeNumberText(std::string_view text) const;
    bool isZeroNumberText(std::string_view text) const;
    bool isNegativeZeroNumberText(std::string_view text) const;
    bool isInfinityNumberText(std::string_view text) const;
    bool isNanNumberText(std::string_view text) const;

    std::string normalizeNumberText(std::string_view text) const;

    std::string deleteSignPartNumberText(std::string_view text) const;

    std::string getSignPartNumberText(std::string_view text) const;
    std::string getIntegerPartNumberText(std::string_view text) const;
    std::string getDecimalPartNumberText(std::string_view text) const;

private:
    std::size_t countPositiveSign(std::string_view text) const;
    bool containtsPositiveSign(std::string_view text) const;
    bool startsWithPositiveSign(std::string_view text) const;
    std::string deletePositiveSign(std::string_view text) const;
    std::string pickupPositiveSign(std::string_view text) const;

    std::size_t countNegativeSign(std::string_view text) const;
    bool containtsNegativeSign(std::string_view text) const;
    bool startsWithNegativeSign(std::string_view text) const;
    std::string deleteNegativeSign(std::string_view text) const;
    std::string pickupNegativeSign(std::string_view text) const;

    std::size_t countZeroSign(std::string_view text) const;
    bool containtsZeroSign(std::string_view text) const;
    bool startsWithZeroSign(std::string_view text) const;
    std::string deleteZeroSign(std::string_view text) const;
    std::string pickupZeroSign(std::string_view text) const;

    std::size_t countPoint(std::string_view text) const;
    bool containtsPoint(std::string_view text) const;

    bool containtsInfinity(std::string_view text) const;
    bool isInfinity(std::string_view text) const;

    bool containtsNan(std::string_view text) const;
    bool isNan(std::string_view text) const;

    std::string alternate(std::string_view text) const;
    std::string normalizePositiveSign(std::string_view text) const;
    std::string normalizeNegativeZero(std::string_view text) const;
    std::string normalizeFixedPoint(std::string_view text) const;
};
