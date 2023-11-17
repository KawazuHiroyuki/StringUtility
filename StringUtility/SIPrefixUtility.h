#pragma

#include <ratio>
#include <chrono>
#include <map>
#include <functional>
#include <string>

#include "SIPrefixType.h"

class SIPrefixUtility {
public:
    using Base = std::chrono::duration<double>;

    using Atto = std::chrono::duration<double, std::ratio_multiply<Base::period, std::atto>>;
    using Femto = std::chrono::duration<double, std::ratio_multiply<Base::period, std::femto>>;
    using Pico = std::chrono::duration<double, std::ratio_multiply<Base::period, std::pico>>;
    using Nano = std::chrono::duration<double, std::ratio_multiply<Base::period, std::nano>>;
    using Micro = std::chrono::duration<double, std::ratio_multiply<Base::period, std::micro>>;
    using Milli = std::chrono::duration<double, std::ratio_multiply<Base::period, std::milli>>;
    using Centi = std::chrono::duration<double, std::ratio_multiply<Base::period, std::centi>>;
    using Deci = std::chrono::duration<double, std::ratio_multiply<Base::period, std::deci>>;

    using Deca = std::chrono::duration<double, std::ratio_multiply<Base::period, std::deca>>;
    using Hecto = std::chrono::duration<double, std::ratio_multiply<Base::period, std::hecto>>;
    using Kilo = std::chrono::duration<double, std::ratio_multiply<Base::period, std::kilo>>;
    using Mega = std::chrono::duration<double, std::ratio_multiply<Base::period, std::mega>>;
    using Giga = std::chrono::duration<double, std::ratio_multiply<Base::period, std::giga>>;
    using Tera = std::chrono::duration<double, std::ratio_multiply<Base::period, std::tera>>;
    using Peta = std::chrono::duration<double, std::ratio_multiply<Base::period, std::peta>>;
    using Exa = std::chrono::duration<double, std::ratio_multiply<Base::period, std::exa>>;

    template <typename Type = double>
    static Type getValue(SIPrefix prefix) {
        return static_cast<Type>(infos.at(prefix).value());
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

private:
    struct SIPrefixInfo {
        std::function<double()> value;
        std::string text;
        std::function<double(double)> to;
    };

    static inline std::map<SIPrefix, SIPrefixInfo> infos = {
        {SIPrefix::Atto, SIPrefixInfo{
            []() { return std::chrono::duration_cast<Base>(Atto{1}).count(); },
            std::string{"a"},
            [](double value) { return std::chrono::duration_cast<Atto>(Base{value}).count(); }}
        },
        {SIPrefix::Femto, SIPrefixInfo{
            []() { return std::chrono::duration_cast<Base>(Femto{1}).count(); },
            std::string{"f"},
            [](double value) { return std::chrono::duration_cast<Femto>(Base{value}).count(); }}
        },
        {SIPrefix::Pico, SIPrefixInfo{
            []() { return std::chrono::duration_cast<Base>(Pico{1}).count(); },
            std::string{"p"},
            [](double value) { return std::chrono::duration_cast<Pico>(Base{value}).count(); }}
        },
        {SIPrefix::Nano, SIPrefixInfo{
            []() { return std::chrono::duration_cast<Base>(Nano{1}).count(); },
            std::string{"n"},
            [](double value) { return std::chrono::duration_cast<Nano>(Base{value}).count(); }}
        },
        {SIPrefix::Micro, SIPrefixInfo{
            []() { return std::chrono::duration_cast<Base>(Micro{1}).count(); },
            std::string{"u"},
            [](double value) { return std::chrono::duration_cast<Micro>(Base{value}).count(); }}
        },
        {SIPrefix::Milli, SIPrefixInfo{
            []() { return std::chrono::duration_cast<Base>(Milli{1}).count(); },
            std::string{"m"},
            [](double value) { return std::chrono::duration_cast<Milli>(Base{value}).count(); }}
        },
        {SIPrefix::Centi, SIPrefixInfo{
            []() { return std::chrono::duration_cast<Base>(Centi{1}).count(); },
            std::string{"c"},
            [](double value) { return std::chrono::duration_cast<Centi>(Base{value}).count(); }}
        },
        {SIPrefix::Deci, SIPrefixInfo{
            []() { return std::chrono::duration_cast<Base>(Deci{1}).count(); },
            std::string{"d"},
            [](double value) { return std::chrono::duration_cast<Deci>(Base{value}).count(); }}
        },
        {SIPrefix::Base, SIPrefixInfo{
            []() { return std::chrono::duration_cast<Base>(Base{1}).count(); },
            std::string{""},
            [](double value) { return value; }}
        },
        {SIPrefix::Deca, SIPrefixInfo{
            []() { return std::chrono::duration_cast<Base>(Deca{1}).count(); },
            std::string{"da"},
            [](double value) { return std::chrono::duration_cast<Deca>(Base{value}).count(); }}
        },
        {SIPrefix::Hecto, SIPrefixInfo{
            []() { return std::chrono::duration_cast<Base>(Hecto{1}).count(); },
            std::string{"h"},
            [](double value) { return std::chrono::duration_cast<Hecto>(Base{value}).count(); }}
        },
        {SIPrefix::Kilo, SIPrefixInfo{
            []() { return std::chrono::duration_cast<Base>(Kilo{1}).count(); },
            std::string{"k"},
            [](double value) { return std::chrono::duration_cast<Kilo>(Base{value}).count(); }}
        },
        {SIPrefix::Mega, SIPrefixInfo{
            []() { return std::chrono::duration_cast<Base>(Mega{1}).count(); },
            std::string{"M"},
            [](double value) { return std::chrono::duration_cast<Mega>(Base{value}).count(); }}
        },
        {SIPrefix::Giga, SIPrefixInfo{
            []() { return std::chrono::duration_cast<Base>(Giga{1}).count(); },
            std::string{"G"},
            [](double value) { return std::chrono::duration_cast<Giga>(Base{value}).count(); }}
        },
        {SIPrefix::Tera, SIPrefixInfo{
            []() { return std::chrono::duration_cast<Base>(Tera{1}).count(); },
            std::string{"T"},
            [](double value) { return std::chrono::duration_cast<Tera>(Base{value}).count(); }}
        },
        {SIPrefix::Peta, SIPrefixInfo{
            []() { return std::chrono::duration_cast<Base>(Peta{1}).count(); },
            std::string{"P"},
            [](double value) { return std::chrono::duration_cast<Peta>(Base{value}).count(); }}
        },
        {SIPrefix::Exa, SIPrefixInfo{
            []() { return std::chrono::duration_cast<Base>(Exa{1}).count(); },
            std::string{"E"},
            [](double value) { return std::chrono::duration_cast<Exa>(Base{value}).count(); }}
        },
    };
};
