#include "Test.h"

#include <iostream>

#include "SIPrefixUtility.h"
#include "BinaryPrefixUtility.h"

void Test003() {
    std::cout << SIPrefixUtility::getValue(SIPrefix::Atto) << std::endl;
    std::cout << SIPrefixUtility::getValue(SIPrefix::Femto) << std::endl;
    std::cout << SIPrefixUtility::getValue(SIPrefix::Pico) << std::endl;
    std::cout << SIPrefixUtility::getValue(SIPrefix::Nano) << std::endl;
    std::cout << SIPrefixUtility::getValue(SIPrefix::Micro) << std::endl;
    std::cout << SIPrefixUtility::getValue(SIPrefix::Milli) << std::endl;
    std::cout << SIPrefixUtility::getValue(SIPrefix::Centi) << std::endl;
    std::cout << SIPrefixUtility::getValue(SIPrefix::Deci) << std::endl;
    std::cout << SIPrefixUtility::getValue(SIPrefix::Base) << std::endl;
    std::cout << SIPrefixUtility::getValue(SIPrefix::Deca) << std::endl;
    std::cout << SIPrefixUtility::getValue(SIPrefix::Hecto) << std::endl;
    std::cout << SIPrefixUtility::getValue(SIPrefix::Kilo) << std::endl;
    std::cout << SIPrefixUtility::getValue(SIPrefix::Mega) << std::endl;
    std::cout << SIPrefixUtility::getValue(SIPrefix::Giga) << std::endl;
    std::cout << SIPrefixUtility::getValue(SIPrefix::Tera) << std::endl;
    std::cout << SIPrefixUtility::getValue(SIPrefix::Peta) << std::endl;
    std::cout << SIPrefixUtility::getValue(SIPrefix::Exa) << std::endl;

    std::cout << SIPrefixUtility::getText(SIPrefix::Atto) << std::endl;
    std::cout << SIPrefixUtility::getText(SIPrefix::Femto) << std::endl;
    std::cout << SIPrefixUtility::getText(SIPrefix::Pico) << std::endl;
    std::cout << SIPrefixUtility::getText(SIPrefix::Nano) << std::endl;
    std::cout << SIPrefixUtility::getText(SIPrefix::Micro) << std::endl;
    std::cout << SIPrefixUtility::getText(SIPrefix::Milli) << std::endl;
    std::cout << SIPrefixUtility::getText(SIPrefix::Centi) << std::endl;
    std::cout << SIPrefixUtility::getText(SIPrefix::Deci) << std::endl;
    std::cout << SIPrefixUtility::getText(SIPrefix::Base) << std::endl;
    std::cout << SIPrefixUtility::getText(SIPrefix::Deca) << std::endl;
    std::cout << SIPrefixUtility::getText(SIPrefix::Hecto) << std::endl;
    std::cout << SIPrefixUtility::getText(SIPrefix::Kilo) << std::endl;
    std::cout << SIPrefixUtility::getText(SIPrefix::Mega) << std::endl;
    std::cout << SIPrefixUtility::getText(SIPrefix::Giga) << std::endl;
    std::cout << SIPrefixUtility::getText(SIPrefix::Tera) << std::endl;
    std::cout << SIPrefixUtility::getText(SIPrefix::Peta) << std::endl;
    std::cout << SIPrefixUtility::getText(SIPrefix::Exa) << std::endl;

    std::cout << SIPrefixUtility::to(42.0, SIPrefix::Atto) << std::endl;
    std::cout << SIPrefixUtility::to(42.0, SIPrefix::Femto) << std::endl;
    std::cout << SIPrefixUtility::to(42.0, SIPrefix::Pico) << std::endl;
    std::cout << SIPrefixUtility::to(42.0, SIPrefix::Nano) << std::endl;
    std::cout << SIPrefixUtility::to(42.0, SIPrefix::Micro) << std::endl;
    std::cout << SIPrefixUtility::to(42.0, SIPrefix::Milli) << std::endl;
    std::cout << SIPrefixUtility::to(42.0, SIPrefix::Centi) << std::endl;
    std::cout << SIPrefixUtility::to(42.0, SIPrefix::Deci) << std::endl;
    std::cout << SIPrefixUtility::to(42.0, SIPrefix::Base) << std::endl;
    std::cout << SIPrefixUtility::to(42.0, SIPrefix::Deca) << std::endl;
    std::cout << SIPrefixUtility::to(42.0, SIPrefix::Hecto) << std::endl;
    std::cout << SIPrefixUtility::to(42.0, SIPrefix::Kilo) << std::endl;
    std::cout << SIPrefixUtility::to(42.0, SIPrefix::Mega) << std::endl;
    std::cout << SIPrefixUtility::to(42.0, SIPrefix::Giga) << std::endl;
    std::cout << SIPrefixUtility::to(42.0, SIPrefix::Tera) << std::endl;
    std::cout << SIPrefixUtility::to(42.0, SIPrefix::Peta) << std::endl;
    std::cout << SIPrefixUtility::to(42.0, SIPrefix::Exa) << std::endl;

    std::cout << BinaryPrefixUtility::getValue(BinaryPrefix::Base) << std::endl;
    std::cout << BinaryPrefixUtility::getValue(BinaryPrefix::Kibi) << std::endl;
    std::cout << BinaryPrefixUtility::getValue(BinaryPrefix::Mebi) << std::endl;
    std::cout << BinaryPrefixUtility::getValue(BinaryPrefix::Gibi) << std::endl;
    std::cout << BinaryPrefixUtility::getValue(BinaryPrefix::Tebi) << std::endl;
    std::cout << BinaryPrefixUtility::getValue(BinaryPrefix::Pebi) << std::endl;
    std::cout << BinaryPrefixUtility::getValue(BinaryPrefix::Exbi) << std::endl;

    std::cout << BinaryPrefixUtility::getText(BinaryPrefix::Base) << std::endl;
    std::cout << BinaryPrefixUtility::getText(BinaryPrefix::Kibi) << std::endl;
    std::cout << BinaryPrefixUtility::getText(BinaryPrefix::Mebi) << std::endl;
    std::cout << BinaryPrefixUtility::getText(BinaryPrefix::Gibi) << std::endl;
    std::cout << BinaryPrefixUtility::getText(BinaryPrefix::Tebi) << std::endl;
    std::cout << BinaryPrefixUtility::getText(BinaryPrefix::Pebi) << std::endl;
    std::cout << BinaryPrefixUtility::getText(BinaryPrefix::Exbi) << std::endl;

    std::cout << BinaryPrefixUtility::getSIPrefixLikeText(BinaryPrefix::Base) << std::endl;
    std::cout << BinaryPrefixUtility::getSIPrefixLikeText(BinaryPrefix::Kibi) << std::endl;
    std::cout << BinaryPrefixUtility::getSIPrefixLikeText(BinaryPrefix::Mebi) << std::endl;
    std::cout << BinaryPrefixUtility::getSIPrefixLikeText(BinaryPrefix::Gibi) << std::endl;
    std::cout << BinaryPrefixUtility::getSIPrefixLikeText(BinaryPrefix::Tebi) << std::endl;
    std::cout << BinaryPrefixUtility::getSIPrefixLikeText(BinaryPrefix::Pebi) << std::endl;
    std::cout << BinaryPrefixUtility::getSIPrefixLikeText(BinaryPrefix::Exbi) << std::endl;

    std::cout << BinaryPrefixUtility::to(2048.5, BinaryPrefix::Base) << std::endl;
    std::cout << BinaryPrefixUtility::to(2048.5, BinaryPrefix::Kibi) << std::endl;
    std::cout << BinaryPrefixUtility::to(2048.5, BinaryPrefix::Mebi) << std::endl;
    std::cout << BinaryPrefixUtility::to(2048.5, BinaryPrefix::Gibi) << std::endl;
    std::cout << BinaryPrefixUtility::to(2048.5, BinaryPrefix::Tebi) << std::endl;
    std::cout << BinaryPrefixUtility::to(2048.5, BinaryPrefix::Pebi) << std::endl;
    std::cout << BinaryPrefixUtility::to(2048.5, BinaryPrefix::Exbi) << std::endl;
}
