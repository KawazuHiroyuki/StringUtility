#pragma once

#include <string>
#include <cctype>
#include <list>
#include "AsciiCharacter.h"
#include "AsciiCharacterType.h"

namespace string_utility
{
template <typename Type>
bool isAscii(Type character)
{
    bool ascii = (0 != isascii(character));
    return ascii;
}

bool isAsciiControl(AsciiCharacter character)
{
    bool control = (0 != std::iscntrl(static_cast<int>(character)));
    return control;
}

bool isAsciiPrintable(AsciiCharacter character)
{
    bool printable = (0 != std::isprint(static_cast<int>(character)));
    return printable;
}

bool isAsciiWhiteSpace(AsciiCharacter character)
{
    bool space = (0 != std::isspace(static_cast<int>(character)));
    return space;
}

bool isAsciiBlank(AsciiCharacter character)
{
    bool blank = (0 != std::isblank(static_cast<int>(character)));
    return blank;
}

bool isAsciiGraphical(AsciiCharacter character)
{
    bool graphical = (0 != std::isgraph(static_cast<int>(character)));
    return graphical;
}

bool isAsciiAlphanumeric(AsciiCharacter character)
{
    bool alphanumeric = (0 != std::isalnum(static_cast<int>(character)));
    return alphanumeric;
}

bool isAsciiAlphabetic(AsciiCharacter character)
{
    bool alphabetic = (0 != std::isalpha(static_cast<int>(character)));
    return alphabetic;
}

bool isAsciiUpperCase(AsciiCharacter character)
{
    bool upperCase = (0 != std::isupper(static_cast<int>(character)));
    return upperCase;
}

bool isAsciiLowerCase(AsciiCharacter character)
{
    bool lowerCase = (0 != std::islower(static_cast<int>(character)));
    return lowerCase;
}

bool isAsciiNumeric(AsciiCharacter character)
{
    bool numeric = (0 != std::isalnum(static_cast<int>(character)));
    return numeric;
}

bool isAsciiDigit(AsciiCharacter character)
{
    bool digit = (0 != std::isdigit(static_cast<int>(character)));
    return digit;
}

bool isAsciiDecimal(AsciiCharacter character)
{
    bool decimal = isAsciiDigit(character);
    return decimal;
}

bool isAsciiHexadecimal(AsciiCharacter character)
{
    bool hexadecimal = (0 != std::isxdigit(static_cast<int>(character)));
    return hexadecimal;
}

std::string filter()
{

}

std::string replace(const std::string target, const std::string replacer)
{

}

}
