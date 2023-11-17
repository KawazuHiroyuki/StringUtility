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
    void addInfinity(std::string_view infinity);
    // containts
    // is
    // replace
};
