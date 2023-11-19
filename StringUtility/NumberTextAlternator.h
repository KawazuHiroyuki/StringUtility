#pragma once

#include <string_view>
#include <string>
#include <cstddef>
#include <vector>
#include <optional>

class NumberTextAlternaor {
    std::string m_positiveSign;
    std::string m_negativeSign;
    std::string m_zeroSign;
    std::string m_point;
    std::string m_infinity;
    std::string m_nan;

public:
    NumberTextAlternaor& setPositiveSign(std::string_view alternate) {
        m_positiveSign = std::string{ alternate };
        return *this;
    }
    NumberTextAlternaor& setNegativeSign(std::string_view alternate) {
        m_negativeSign = std::string{ alternate };
        return *this;
    }
    NumberTextAlternaor& setZeroSign(std::string_view alternate) {
        m_zeroSign = std::string{ alternate };
        return *this;
    }
    NumberTextAlternaor& setPoint(std::string_view alternate) {
        m_point = std::string{ alternate };
        return *this;
    }
    NumberTextAlternaor& setInfinity(std::string_view alternate) {
        m_infinity = std::string{ alternate };
        return *this;
    }
    NumberTextAlternaor& setNan(std::string_view alternate) {
        m_nan = std::string{alternate};
        return *this;
    }

    std::size_t countPositiveSign(std::string_view text) const;
    bool containtsPositiveSign(std::string_view text) const;
    bool startsWithPositiveSign(std::string_view text) const;
    std::string deletePositiveSign(std::string_view text) const;

    std::size_t countNegativeSign(std::string_view text) const;
    bool containtsNegativeSign(std::string_view text) const;
    bool startsWithNegativeSign(std::string_view text) const;
    std::string deleteNegativeSign(std::string_view text) const;

    std::size_t countZeroSign(std::string_view text) const;
    bool containtsZeroSign(std::string_view text) const;
    bool startsWithZeroSign(std::string_view text) const;
    std::string deleteZeroSign(std::string_view text) const;

    std::size_t countPoint(std::string_view text) const;
    bool containtsPoint(std::string_view text) const;

    bool containtsInfinity(std::string_view text) const;
    bool isInfinity(std::string_view text) const;

    bool containtsNan(std::string_view text) const;
    bool isNan(std::string_view text) const;

    std::string replace(std::string_view text) const;
    std::string normalize(std::string_view text) const;
};
