#pragma once

#include <string_view>
#include <string>
#include <vector>

class NumberTextAlternate {
    std::string m_positiveSign;
    std::string m_negativeSign;
    std::string m_zeroSign;
    std::string m_point;
    std::string m_infinity;
    std::string m_nan;

public:
    NumberTextAlternate& setPositiveSign(std::string_view alternate) {
        m_positiveSign = std::string{ alternate };
        return *this;
    }
    NumberTextAlternate& setNegativeSign(std::string_view alternate) {
        m_negativeSign = std::string{ alternate };
        return *this;
    }
    NumberTextAlternate& setZeroSign(std::string_view alternate) {
        m_zeroSign = std::string{ alternate };
        return *this;
    }
    NumberTextAlternate& setPoint(std::string_view alternate) {
        m_point = std::string{ alternate };
        return *this;
    }
    NumberTextAlternate& setInfinity(std::string_view alternate) {
        m_infinity = std::string{ alternate };
        return *this;
    }
    NumberTextAlternate& setNan(std::string_view alternate) {
        m_nan = std::string{alternate};
        return *this;
    }

    bool containtsPositiveSign(std::string_view text) const;
    bool startsWithPositiveSign(std::string_view text) const;
    std::string deletePositiveSign(std::string_view text) const;

    bool containtsNegativeSign(std::string_view text) const;
    bool startsWithNegativeSign(std::string_view text) const;
    std::string deleteNegativeSign(std::string_view text) const;

    bool containtsZeroSign(std::string_view text) const;
    bool startsWithZeroSign(std::string_view text) const;
    std::string deleteZeroSign(std::string_view text) const;

    bool containtsPoint(std::string_view text) const;

    bool containtsInfinity(std::string_view text) const;
    bool isInfinity(std::string_view text) const;

    bool containtsNan(std::string_view text) const;
    bool isNan(std::string_view text) const;

    // replace
};
