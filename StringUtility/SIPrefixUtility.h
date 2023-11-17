#pragma

#include <ratio>
#include <chrono>
#include <map>
#include <functional>
#include <string>
#include <vector>
#include <algorithm>

#include "SIPrefixType.h"

class SIPrefixUtility {
public:
    using Base = std::chrono::duration<long double>;

    using Atto = std::chrono::duration<long double, std::ratio_multiply<Base::period, std::atto>>;
    using Femto = std::chrono::duration<long double, std::ratio_multiply<Base::period, std::femto>>;
    using Pico = std::chrono::duration<long double, std::ratio_multiply<Base::period, std::pico>>;
    using Nano = std::chrono::duration<long double, std::ratio_multiply<Base::period, std::nano>>;
    using Micro = std::chrono::duration<long double, std::ratio_multiply<Base::period, std::micro>>;
    using Milli = std::chrono::duration<long double, std::ratio_multiply<Base::period, std::milli>>;
    using Centi = std::chrono::duration<long double, std::ratio_multiply<Base::period, std::centi>>;
    using Deci = std::chrono::duration<long double, std::ratio_multiply<Base::period, std::deci>>;

    using Deca = std::chrono::duration<long double, std::ratio_multiply<Base::period, std::deca>>;
    using Hecto = std::chrono::duration<long double, std::ratio_multiply<Base::period, std::hecto>>;
    using Kilo = std::chrono::duration<long double, std::ratio_multiply<Base::period, std::kilo>>;
    using Mega = std::chrono::duration<long double, std::ratio_multiply<Base::period, std::mega>>;
    using Giga = std::chrono::duration<long double, std::ratio_multiply<Base::period, std::giga>>;
    using Tera = std::chrono::duration<long double, std::ratio_multiply<Base::period, std::tera>>;
    using Peta = std::chrono::duration<long double, std::ratio_multiply<Base::period, std::peta>>;
    using Exa = std::chrono::duration<long double, std::ratio_multiply<Base::period, std::exa>>;

    static std::vector<SIPrefix> getAscendingSIPrefixes() {
        std::vector prefixes = {
            SIPrefix::Atto,
            SIPrefix::Femto,
            SIPrefix::Pico,
            SIPrefix::Nano,
            SIPrefix::Micro,
            SIPrefix::Milli,
            SIPrefix::Centi,
            SIPrefix::Deci,
            SIPrefix::Base,
            SIPrefix::Deca,
            SIPrefix::Hecto,
            SIPrefix::Kilo,
            SIPrefix::Mega,
            SIPrefix::Giga,
            SIPrefix::Tera,
            SIPrefix::Peta,
            SIPrefix::Exa,
        };
        return prefixes;
    }

    static std::vector<SIPrefix> getDescendingSIPrefixes() {
        auto prefixes = getAscendingSIPrefixes();
        std::reverse(prefixes.begin(), prefixes.end());
        return prefixes;
    }

    template <typename Type = long double>
    static Type getValue(SIPrefix prefix) {
        return static_cast<Type>(infos.at(prefix).value());
    }

    static std::string getName(SIPrefix prefix) {
        return infos.at(prefix).name;
    }

    static std::string getText(SIPrefix prefix) {
        return infos.at(prefix).text;
    }

    // to
    template <typename Type>
    static Type to(Type value, SIPrefix to) {
        return static_cast<Type>(infos.at(to).to(value));
    }

    template <typename Result, typename Type>
    static Type to(Type value, SIPrefix to) {
        return static_cast<Result>(infos.at(to).to(value));
    }

    template <typename Type>
    static Type to(Type value, SIPrefix from, SIPrefix to) {
        return static_cast<Type>(infos.at(to).to(infos.at(from).to(value)));
    }

    template <typename Result, typename Type>
    static Type to(Type value, SIPrefix from, SIPrefix to) {
        return static_cast<Result>(infos.at(to).to(infos.at(from).to(value)));
    }

    // readable
    template <typename Type>
    static SIPrefix readbable(Type value) {
        for (auto prefix : getDescendingSIPrefixes()) {
            if (infos.at(prefix).greaterEqualThan(static_cast<long double>(value))) {
                return prefix;
            }
        }
        return SIPrefix::Base;
    }


private:
    struct SIPrefixInfo {
        std::function<long double()> value;
        std::string name;
        std::string text;
        std::function<long double(long double)> to;
        std::function<bool(long double)> greaterEqualThan;
    };

    static inline std::map<SIPrefix, SIPrefixInfo> infos = {
        {SIPrefix::Atto, SIPrefixInfo{
            []() { return std::chrono::duration_cast<Base>(Atto{1}).count(); },
            "Atto", std::string{"a"},
            [](long double value) { return std::chrono::duration_cast<Atto>(Base{value}).count(); },
            [](long double value) { return Base{value} >= Atto{1}; }
        }},
        {SIPrefix::Femto, SIPrefixInfo{
            []() { return std::chrono::duration_cast<Base>(Femto{1}).count(); },
            "Femto", std::string{"f"},
            [](long double value) { return std::chrono::duration_cast<Femto>(Base{value}).count(); },
            [](long double value) { return Base{value} >= Femto{1}; }
        }},
        {SIPrefix::Pico, SIPrefixInfo{
            []() { return std::chrono::duration_cast<Base>(Pico{1}).count(); },
            "Pico", std::string{"p"},
            [](long double value) { return std::chrono::duration_cast<Pico>(Base{value}).count(); },
            [](long double value) { return Base{value} >= Pico{1}; }
        }},
        {SIPrefix::Nano, SIPrefixInfo{
            []() { return std::chrono::duration_cast<Base>(Nano{1}).count(); },
            "Nano", std::string{"n"},
            [](long double value) { return std::chrono::duration_cast<Nano>(Base{value}).count(); },
            [](long double value) { return Base{value} >= Nano{1}; }
        }},
        {SIPrefix::Micro, SIPrefixInfo{
            []() { return std::chrono::duration_cast<Base>(Micro{1}).count(); },
            "Micro", std::string{"u"},
            [](long double value) { return std::chrono::duration_cast<Micro>(Base{value}).count(); },
            [](long double value) { return Base{value} >= Micro{1}; }
        }},
        {SIPrefix::Milli, SIPrefixInfo{
            []() { return std::chrono::duration_cast<Base>(Milli{1}).count(); },
            "Milli", std::string{"m"},
            [](long double value) { return std::chrono::duration_cast<Milli>(Base{value}).count(); },
            [](long double value) { return Base{value} >= Milli{1}; }
        }},
        {SIPrefix::Centi, SIPrefixInfo{
            []() { return std::chrono::duration_cast<Base>(Centi{1}).count(); },
            "Centi", std::string{"c"},
            [](long double value) { return std::chrono::duration_cast<Centi>(Base{value}).count(); },
            [](long double value) { return Base{value} >= Centi{1}; }
        }},
        {SIPrefix::Deci, SIPrefixInfo{
            []() { return std::chrono::duration_cast<Base>(Deci{1}).count(); },
            "Deci", std::string{"d"},
            [](long double value) { return std::chrono::duration_cast<Deci>(Base{value}).count(); },
            [](long double value) { return Base{value} >= Deci{1}; }
        }},
        {SIPrefix::Base, SIPrefixInfo{
            []() { return std::chrono::duration_cast<Base>(Base{1}).count(); },
            "Base", std::string{""},
            [](long double value) { return value; },
            [](long double value) { return Base{value} >= Base{1}; }
        }},
        {SIPrefix::Deca, SIPrefixInfo{
            []() { return std::chrono::duration_cast<Base>(Deca{1}).count(); },
            "Deca", std::string{"da"},
            [](long double value) { return std::chrono::duration_cast<Deca>(Base{value}).count(); },
            [](long double value) { return Base{value} >= Deca{1}; }
        }},
        {SIPrefix::Hecto, SIPrefixInfo{
            []() { return std::chrono::duration_cast<Base>(Hecto{1}).count(); },
            "Hecto", std::string{"h"},
            [](long double value) { return std::chrono::duration_cast<Hecto>(Base{value}).count(); },
            [](long double value) { return Base{value} >= Hecto{1}; }
        }},
        {SIPrefix::Kilo, SIPrefixInfo{
            []() { return std::chrono::duration_cast<Base>(Kilo{1}).count(); },
            "Kilo", std::string{"k"},
            [](long double value) { return std::chrono::duration_cast<Kilo>(Base{value}).count(); },
            [](long double value) { return Base{value} >= Kilo{1}; }
        }},
        {SIPrefix::Mega, SIPrefixInfo{
            []() { return std::chrono::duration_cast<Base>(Mega{1}).count(); },
            "Mega", std::string{"M"},
            [](long double value) { return std::chrono::duration_cast<Mega>(Base{value}).count(); },
            [](long double value) { return Base{value} >= Mega{1}; }
        }},
        {SIPrefix::Giga, SIPrefixInfo{
            []() { return std::chrono::duration_cast<Base>(Giga{1}).count(); },
            "Giga", std::string{"G"},
            [](long double value) { return std::chrono::duration_cast<Giga>(Base{value}).count(); },
            [](long double value) { return Base{value} >= Giga{1}; }
        }},
        {SIPrefix::Tera, SIPrefixInfo{
            []() { return std::chrono::duration_cast<Base>(Tera{1}).count(); },
            "Tera", std::string{"T"},
            [](long double value) { return std::chrono::duration_cast<Tera>(Base{value}).count(); },
            [](long double value) { return Base{value} >= Tera{1}; }
        }},
        {SIPrefix::Peta, SIPrefixInfo{
            []() { return std::chrono::duration_cast<Base>(Peta{1}).count(); },
            "Peta", std::string{"P"},
            [](long double value) { return std::chrono::duration_cast<Peta>(Base{value}).count(); },
            [](long double value) { return Base{value} >= Peta{1}; }
        }},
        {SIPrefix::Exa, SIPrefixInfo{
            []() { return std::chrono::duration_cast<Base>(Exa{1}).count(); },
            "Exa", std::string{"E"},
            [](long double value) { return std::chrono::duration_cast<Exa>(Base{value}).count(); },
            [](long double value) { return Base{value} >= Exa{1}; }
        }},
    };
};
