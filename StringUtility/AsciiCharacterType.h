#pragma once

namespace string_utility
{
enum class AsciiCharacterType {
    Control = 0, //!< 制御文字
    Printable, //!< 印刷可能文字
    WhiteSpace, //!< 空白類文字
    Blank, //!< ブランク文字
    Graphical, //!< グラフィック表現
    Alphabetic, //!< 英字
    UpperCase, //!< 英字小文字
    LowerCase, //!< 英字大文字
    Numeric, //!< 数字
    Decimal, //!< 10進数字
    Hexadecimal, //!< 16進数字
    Bracket, //!< 括弧
    Quote, //!< 引用符
};
}