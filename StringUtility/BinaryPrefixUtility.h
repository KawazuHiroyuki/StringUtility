#pragma

#include <ratio>
#include <chrono>
#include <string>

#include "BinaryPrefixType.h"

class BinaryPrefixUtility {
public:
    using Base = std::chrono::duration<long double>;

    using Kibi = std::chrono::duration<long double, std::ratio_multiply<Base::period, std::ratio<1024, 1>>>;
    using Mebi = std::chrono::duration<long double, std::ratio_multiply<Kibi::period, std::ratio<1024, 1>>>;
    using Gibi = std::chrono::duration<long double, std::ratio_multiply<Mebi::period, std::ratio<1024, 1>>>;
    using Tebi = std::chrono::duration<long double, std::ratio_multiply<Gibi::period, std::ratio<1024, 1>>>;
    using Pebi = std::chrono::duration<long double, std::ratio_multiply<Tebi::period, std::ratio<1024, 1>>>;
    using Exbi = std::chrono::duration<long double, std::ratio_multiply<Pebi::period, std::ratio<1024, 1>>>;

    template <typename Type = long double>
    static Type getValue(BinaryPrefix prefix) {
        return static_cast<Type>(infos.at(prefix).value());
    }

    static std::string getName(BinaryPrefix prefix) {
        return infos.at(prefix).name;
    }

    static std::string getText(BinaryPrefix prefix) {
        return infos.at(prefix).text;
    }

    static std::string getSIPrefixLikeText(BinaryPrefix prefix) {
        return infos.at(prefix).siPrefixLikeText;
    }

    // to
    template <typename Type>
    static Type to(Type value, BinaryPrefix to) {
        return static_cast<Type>(infos.at(to).to(value));
    }

    template <typename Result, typename Type>
    static Type to(Type value, BinaryPrefix to) {
        return static_cast<Result>(infos.at(to).to(value));
    }

    // readable

private:
    struct BinaryPrefixInfo {
        std::function<long double()> value;
        std::string name;
        std::string text;
        std::string siPrefixLikeText;
        std::function<long double(long double)> to;
        std::function<bool(long double)> greaterEqualThan;
    };

    static inline std::map<BinaryPrefix, BinaryPrefixInfo> infos = {
        {BinaryPrefix::Base, BinaryPrefixInfo{
            []() { return std::chrono::duration_cast<Base>(Base{1}).count(); },
            "Base", "", "",
            [](long double value) { return value; },
            [](long double value) { return Base{value} >= Base{1}; }
        }},
        {BinaryPrefix::Kibi, BinaryPrefixInfo{
            []() { return std::chrono::duration_cast<Base>(Kibi{1}).count(); },
            "Kibi", "Ki", "k",
            [](long double value) { return std::chrono::duration_cast<Kibi>(Base{value}).count(); },
            [](long double value) { return Base{value} >= Kibi{1}; }
        }},
        {BinaryPrefix::Mebi, BinaryPrefixInfo{
            []() { return std::chrono::duration_cast<Base>(Mebi{1}).count(); },
            "Mebi", "Mi", "M",
            [](long double value) { return std::chrono::duration_cast<Mebi>(Base{value}).count(); },
            [](long double value) { return Base{value} >= Mebi{1}; }
        }},
        {BinaryPrefix::Gibi, BinaryPrefixInfo{
            []() { return std::chrono::duration_cast<Base>(Gibi{1}).count(); },
            "Gibi", "Gi", "G",
            [](long double value) { return std::chrono::duration_cast<Gibi>(Base{value}).count(); },
            [](long double value) { return Base{value} >= Gibi{1}; }
        }},
        {BinaryPrefix::Tebi, BinaryPrefixInfo{
            []() { return std::chrono::duration_cast<Base>(Tebi{1}).count(); },
            "Tebi", "Ti", "T",
            [](long double value) { return std::chrono::duration_cast<Tebi>(Base{value}).count(); },
            [](long double value) { return Base{value} >= Tebi{1}; }
        }},
        {BinaryPrefix::Pebi, BinaryPrefixInfo{
            []() { return std::chrono::duration_cast<Base>(Pebi{1}).count(); },
            "Pebi", "Pi", "P",
            [](long double value) { return std::chrono::duration_cast<Pebi>(Base{value}).count(); },
            [](long double value) { return Base{value} >= Pebi{1}; }
        }},
        {BinaryPrefix::Exbi, BinaryPrefixInfo{
            []() { return std::chrono::duration_cast<Base>(Exbi{1}).count(); },
            "Exbi", "Ei", "E",
            [](long double value) { return std::chrono::duration_cast<Exbi>(Base{value}).count(); },
            [](long double value) { return Base{value} >= Exbi{1}; }
        }},
    };
};
