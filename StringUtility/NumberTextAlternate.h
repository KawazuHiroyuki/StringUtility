#pragma once

#include <string_view>
#include <string>
#include <vector>

class NumberTextAlternate {
    std::vector<std::string> m_positiveSigns;
    std::vector<std::string> m_negativeSigns;
    std::vector<std::string> m_zeroSigns;
    std::vector<std::string> m_points;
    std::vector<std::string> m_infinities;
    std::vector<std::string> m_nans;

public:
    NumberTextAlternate& addPositiveSign(std::string_view alternate) {
        m_positiveSigns.emplace_back(alternate);
        return *this;
    }
    NumberTextAlternate& addNegativeSign(std::string_view alternate) {
        m_negativeSigns.emplace_back(alternate);
        return *this;
    }
    NumberTextAlternate& addZeroSign(std::string_view alternate) {
        m_zeroSigns.emplace_back(alternate);
        return *this;
    }
    NumberTextAlternate& addPoint(std::string_view alternate) {
        m_points.emplace_back(alternate);
        return *this;
    }
    NumberTextAlternate& addInfinity(std::string_view alternate) {
        m_infinities.emplace_back(alternate);
        return *this;
    }
    NumberTextAlternate& addNan(std::string_view alternate) {
        m_nans.emplace_back(alternate);
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
