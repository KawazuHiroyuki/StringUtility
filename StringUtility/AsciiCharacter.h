#pragma once

enum class AsciiCharacter : char {
    Null = 0x00, //<! 空文字
    StartOfHeading, //<! SOH: ヘッダ開始
    StartOfText, //<! STX: テキスト開始
    EndOfText, //<! EOF: テキスト終了
    EndOfTransimission, //<! EOT: 伝送終了
    Enquiry, //<! ENQ: 問い合わせ
    Acknowlegement, //<! ACK: 肯定応答
    Bell, //<! BEL: ベル
    BackSpace, //<! BS: 一文字後退
    HorizontalTabulation, //<! HT: 水平タブ
    LineFeed, //<! LF: 改行 (NL: NewLine)
    VerticalTabulation, //<! VT: 垂直タブ
    FormFeed, //<! FF : 改ページ (NP: NewPage)
    CarriageReturn, //<! CR: 行頭復帰
    ShiftOut, //<! SO: シフトアウト(多バイト文字終了)
    ShiftIn, //<! SI: シフトイン(多バイト文字開始)
    DataLinkEscape, //<! DLE: データリンク拡張(バイナリ通信開始)
    DeviceControl1, //<! DC1: 装置制御1
    DeviceControl2, //<! DC2: 装置制御2
    DeviceControl3, //<! DC3: 装置制御3
    DeviceControl4, //<! DC4: 装置制御4
    NegativeAcknowledment, //<! NAK: 否定応答
    SynchronousIdole, //<! SYN: 同期
    EndOfTransmissionBlock, //<! ETB: 伝送ブロック終了
    Cancel, //<! CAN: 取消
    EndOfMedium, //<! EM: 記憶媒体終端
    EndOfFile, //<! EOF : ファイル終端 (SUB: Substitude: 文字置換)
    Escape, //<! ESC: エスケープ(特殊文字開始)
    FileSeparator, //<! FS: ファイル区切り
    GroupSeparator, //<! GS: グループ区切り
    RecordSeparator, //<! RS: レコード区切り
    UnitSeparator, //<! US: ユニット区切り
    Space, //<! SPC: 空白文字
    ExclamationMark, //<! !: 感嘆符
    DoubleQuote, //<! ": 二重引用符
    NumberSign, //<! #: 番号記号 (HashMark: ハッシュ)
    DollarSign, //<! $; ドル記号
    PercentSign, //<! %: パーセント記号
    Ampersand, //<! &: アンパーサンド (論理積記号)
    SingleQuote, //<! ': 一重引用符 (アポストロフィ)
    OpenParenthesis, //<! (: 開き丸括弧 (LeftParen/OpenParen/LeftParenthesis)
    CloseParenthesis, //<! ): 閉じ丸括弧 (RightParen/CloseParen/RightParenthesis)
    Asterisk, //<! *: アスタリスク (乗算記号)
    Plus, //<! +: プラス (加算記号)
    Comma, //<! ,: コンマ (カンマ / セディユ)
    Hyphen, //<! -: ハイフン (ダッシュ/マイナス/減算記号)
    Period, //<! .: 終止符 (Dot / Point)
    Slash, //<! /: 斜線 (商算記号)
    Zero, //<! 0: 数字0
    One, //<! 1: 数字1
    Two, //<! 2: 数字2
    Three, //<! 3: 数字3
    Four, //<! 4: 数字4
    Five, //<! 5: 数字5
    Six, //<! 6: 数字6
    Seven, //<! 7: 数字7
    Eight, //<! 8: 数字8
    Nine, //<! 9: 数字9
    Colon, //<! :: コロン
    Semicolon, //<! ;: セミコロン
    OpenAngleBracket, //<! <: 開き山括弧 (LessThen: より小 / 未満 / 不等号記号)
    Equals, //<! =: 等しい (等号符号)
    CloseAngleBracket, //<! >: 閉じ山括弧 (GreaterThen: より大 / 不等号記号)
    QuestionMark, //<! ?: 疑問符
    AtSymbol, //<! @: アットマーク
    UpperCaseA, //<! A: 英字大文字A
    UpperCaseB, //<! B: 英字大文字B
    UpperCaseC, //<! C: 英字大文字C
    UpperCaseD, //<! D: 英字大文字D
    UpperCaseE, //<! E: 英字大文字E
    UpperCaseF, //<! F: 英字大文字F
    UpperCaseG, //<! G: 英字大文字G
    UpperCaseH, //<! H: 英字大文字H
    UpperCaseI, //<! I: 英字大文字I
    UpperCaseJ, //<! J: 英字大文字J
    UpperCaseK, //<! K: 英字大文字K
    UpperCaseL, //<! L: 英字大文字L
    UpperCaseM, //<! M: 英字大文字M
    UpperCaseN, //<! N: 英字大文字N
    UpperCaseO, //<! O: 英字大文字O
    UpperCaseP, //<! P: 英字大文字P
    UpperCaseQ, //<! Q: 英字大文字Q
    UpperCaseR, //<! R: 英字大文字R
    UpperCaseS, //<! S: 英字大文字S
    UpperCaseT, //<! T: 英字大文字T
    UpperCaseU, //<! U: 英字大文字U
    UpperCaseV, //<! V: 英字大文字V
    UpperCaseW, //<! W: 英字大文字W
    UpperCaseX, //<! X: 英字大文字X
    UpperCaseY, //<! Y: 英字大文字Y
    UpperCaseZ, //<! Z: 英字大文字Z
    OpenSquareBracked, //<! [: 開き角括弧 (LeftBracket/OpenBracket)
    Backslash, //<! \: バックスラッシュ (円記号)
    CloseSquareBracked, //<! ]: 閉じ角括弧 (RightBracket/RightBracket)
    Caret, //<! ^: キャレット (ハット / Circumflex: サーカムフレックス / アクサンシルコンフレックス / キャロット)
    Underscore, //<! :_ 下線
    GraveAccent, //<! `: 抑音 (アクサングラーブ / ReverseSingleQuote: 逆一重引用符 / GraveMark: グレイヴマーク)
    LowerCaseA, //<! a: 英語小文字a
    LowerCaseB, //<! b: 英語小文字b
    LowerCaseC, //<! c: 英語小文字c
    LowerCaseD, //<! d: 英語小文字d
    LowerCaseE, //<! e: 英語小文字e
    LowerCaseF, //<! f: 英語小文字f
    LowerCaseG, //<! g: 英語小文字g
    LowerCaseH, //<! h: 英語小文字h
    LowerCaseI, //<! i; 英語小文字i
    LowerCaseJ, //<! j: 英語小文字j
    LowerCaseK, //<! k: 英語小文字k
    LowerCaseL, //<! l: 英語小文字l
    LowerCaseM, //<! m: 英語小文字m
    LowerCaseN, //<! n: 英語小文字n
    LowerCaseO, //<! o: 英語小文字o
    LowerCaseP, //<! p: 英語小文字p
    LowerCaseQ, //<! q: 英語小文字q
    LowerCaseR, //<! r: 英語小文字r
    LowerCaseS, //<! s: 英語小文字s
    LowerCaseT, //<! t: 英語小文字t
    LowerCaseU, //<! u: 英語小文字u
    LowerCaseV, //<! v: 英語小文字v
    LowerCaseW, //<! w: 英語小文字w
    LowerCaseX, //<! x: 英語小文字x
    LowerCaseY, //<! y: 英語小文字y
    LowerCaseZ, //<! z: 英語小文字z
    OepenCurlyBracket, //<! {: 開き波括弧 (LeftCurlyBrace/OpenCurlyBrace)
    VerticalBar, //<! |: 垂直線 (縦線/論理和記号)
    CloseCurlyBracket, //<! }: 閉じ波括弧 (RightCurlyBrace/RightCurlyBrace)
    Tilde, //<! ~: チルダ (波線/波形記号/近似)
    Delete = 0x7F, //<! DEL: 一文字削除
};

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

bool isAscii(signed char character)
{

}

bool isAscii(unsigned char character)
{

}

bool isAscii(char character)
{

}

bool isControl(AsciiCharacter character)
{
    if (AsciiCharacter::Null <= character && AsciiCharacter::UnitSeparator >= character) {
        return true;
    }
    if (AsciiCharacter::Delete == character) {
        return true;
    }
    return false;
}

bool isPrintable(AsciiCharacter character)
{
    if (AsciiCharacter::Null <= character && AsciiCharacter::UnitSeparator >= character) {
        return true;
    }
}

bool isWhiteSpace(AsciiCharacter character)
{

}

bool isBlank(AsciiCharacter character)
{

}

bool isGraphical(AsciiCharacter character)
{

}

bool isAlphanumeric(AsciiCharacter character)
{

}

bool isAlphabetic(AsciiCharacter character)
{

}

bool isUpperCase(AsciiCharacter character)
{

}

bool isLowerCase(AsciiCharacter character)
{

}

bool isNumeric(AsciiCharacter character)
{

}

bool isDigit(AsciiCharacter character)
{

}

bool isDecimal(AsciiCharacter character)
{

}

bool isHexadecimal(AsciiCharacter character)
{

}


/*

QTextCodec




*/





