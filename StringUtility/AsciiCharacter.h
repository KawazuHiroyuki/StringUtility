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

Qt Text Codec

Codec: データのエンコード(符号化)とでコード(復号)を双方向にできるソフトウェアまたはアルゴリズム

QTextCodecで対応しているエンコード
 * Big5
 * Big5-HKSCS
 * CP949
 * EUC-JP
 * EUC-KR
 * GB18030
 * HP-ROMAN8
 * IBM 850
 * IBM 866
 * IBM 874
 * ISO 2022-JP
 * ISO 8859-1 to 10
 * ISO 8859-13 to 16
 * Iscii-Bng, Dev, Gjr, Knd, Mlm, Ori, Pnj, Tlg, and Tml
 * KOI8-R
 * KOI8-U
 * Macintosh
 * Shift-JIS
 * TIS-620
 * TSCII
 * UTF-8
 * UTF-16
 * UTF-16BE
 * UTF-16LE
 * UTF-32
 * UTF-32BE
 * UTF-32LE
 * Windows-1250 to 1258




*/

/*

IANA Character Sets (文字セット)
https://www.iana.org/assignments/character-sets/character-sets.xhtml


優先MIME名             名前
Preferred              Name
MIME Name
US-ASCII                US-ASCII
ISO-8859-1              ISO_8859-1:1987
ISO-8859-2              ISO_8859-2:1987
ISO-8859-3              ISO_8859-3:1988
ISO-8859-4              ISO_8859-4:1988
ISO-8859-5              ISO_8859-5:1988
ISO-8859-6              ISO_8859-6:1987
ISO-8859-7              ISO_8859-7:1987
ISO-8859-8              ISO_8859-8:1988
ISO-8859-9              ISO_8859-9:1989
ISO-8859-10             ISO_8859-10
                        ISO_6937-2-add
                        JIS_X0201
                        JIS_Encoding
Shift_JIS               Shift_JIS
EUC-JP                  Extended_UNIX_Code_Packed_Format_for_Japanese
                        Extended_UNIX_Code_Fixed_Width_for_Japanese
                        BS_14730
                        SEN_850200_C
                        IT
                        ES
                        DIN_66003
                        NS_4551-1
                        NF_Z_62-010
                        ISO-10646-UFT-1
                        ISO_646.basic:1983
                        INVARIANT
                        ISO_646.irv:1983
                        NATS-SEFI
                        NATS-SEFI-ADD
                        NATS-DANO
                        NATS-DANO-ADD
                        SEN_180200_B
                        KS_C_5601-1987
ISO-2022-KR             ISO-2022-KR
EUC-KR                  EUC-KR
ISO-2022-JP             ISO-2022-JP
ISO-2022-JP-2           ISO-2022-JP-2
                        JIS_C6220-1969-jp
                        JIS_C6220-1969-ro
                        PT
                        greek7-old
                        latin-greek
                        NF_Z_62-010_(1973)
                        Latin-greek-1
                        ISO-5427
                        JIS_C6226-1978
                        BS_viewdata
                        INIS
                        INIS-8
                        INIS-cyrillic
                        ISO_5127:1981
                        ISO_5428:1980
                        GB_1988-80
                        GB_2312-80
                        NS_4551-2
                        videotex-suppl
                        PT2
                        ES2
                        MSZ_7795.3
                        JIS_C6226-1983
                        greek7
                        ASMO_449
                        iso-ir-90
                        JIS_C6229-1984-a
                        JIS_C6229-1984-b
                        JIS_C6229-1984-b-add
                        JIS_C6229-1984-hand
                        JIS_C6229-1984-hand-add
                        JIS_C6229-1984-kana
                        ISO-2033-1983
                        ANSI_X3.110-1983
                        T.61-7bit
                        T.61-8bit
                        ECMA-cyrillic
                        CSA_Z243.4.1985-1
                        SCA_Z243.4-1985-2
                        CSA_Z243.4-1985-gr
ISO-8859-6-E            ISO_8859-6-E
ISO-8859-6-I            ISO_8859-6-I
                        T.101-G2
ISO-8859-8-E            ISO-8859-8-E
ISO-8859-8-I            ISO-8859-8-I
                        CSN_369103
                        JUS_I.B1.002
                        IEC-P27-1
                        JUS_I.B1.003-serb
                        JUS_I.B1.003-mac
                        greek-ccitt
                        NC_NC00-10:81
                        ISO_6937-2-25
                        GOST_19768-74
                        ISO_8859-supp
                        ISO_10367-box
                        latin-lap
                        JIS_X0212-1990
                        DS_2089
                        us-dk
                        dk-us
                        KSC5636
                        UNICODE-1-1-UTF-7
                        ISO-2022-CN
                        ISO-2022-CN-EXT
                        UTF-8
                        ISO-8859-13
                        ISO-8859-14
                        ISO-8859-15
                        ISO-8859-16
                        GBK
                        GB18030
                        OSD_EBCDIC_DF04_15
                        OSD_EBCDIC_DF03_IRV
                        OSD_EBCDIC_DF04_1
                        ISO-11548-1
                        KZ-1048
                        ISO-10646-UCS-2
                        ISO-10646-UCS-4
                        ISO-10646-UCS-Basic
                        ISO-10646-Unicode-Latin1
                        ISO-10646-j-1
                        ISO-Unicode-IBM-1261
                        ISO-Unicode-IBM-1268
                        ISO-Unicode-IBM-1276
                        ISO-Unicode-IBM-1264
                        ISO-Unicode-IBM-1265
                        UNICODE-1-1
                        SCSU
                        UTF-7
                        UTF-16BE
                        UTF-16LE
                        UTF-16
                        CESU-8
                        UTF-32
                        UTF-32BE
                        UTF-32LE
                        BOCU-1
                        UTF-7-JMAP
                        ISO-8859-1-Windows-3.0-Latin-1
                        ISO-8859-1-Windows-3.1-Latin-1
                        ISO-8859-2-Windows-Latin-2
                        ISO-8859-9-Windows-Latin-5
                        hp-roman8
                        Adobe-Standard-Encoding
                        Ventura-US
                        Venture-Insternational
                        DEC-MCS
                        IBM850
                        PC8-Danish-Norwegian
                        IBM862
                        PC8-Turkish
                        IBM-Symbols
                        IBM-Thai
                        HP-Legal
                        HP-Pi-font
                        HP-Math8
                        Adobe-Symbol-Encoding
                        HP-DeskTop
                        Venture-Math
                        Microsoft-Publishing
                        Windows-31J
GB2312                  GB2312
Big5                    Big5
                        macintosh
                        IBM037
                        IBM038
                        IBM273
                        IBM274
                        IBM275
                        IBM277
                        IBM278
                        IBM280
                        IBM281
                        IBM285
                        IBM290
                        IBM297
                        IBM420
                        IBM423
                        IBM424
                        IBM437
                        IBM500
                        IBM851
                        IBM852
                        IBM855
                        IBM857
                        IBM860
                        IBM861
                        IBM863
                        IBM864
                        IBM865
                        IBM868
                        IBM870
                        IBM871
                        IBM880
                        IBM891
                        IBM903
                        IBM904
                        IBM905
                        IBM918
                        IBM1026
                        EBCDIC-AT-DE
                        EBCDIC-AT-DE-A
                        EBCDIC-CA-FR
                        EBCDIC-DK-NO
                        EBCDIC-DK-NOA
                        EBCDIC-FI-SE
                        EBCDIC-FI-SE-A
                        EBCDIC-FR
                        EBCDIC-IR
                        EBCDIC-PT
                        EBCDIC-ES
                        EBCDIC-ES-A
                        EBCDIC-ES-S
                        EBCDIC-UK
                        EBCDIC-US
                        UNKNOWN-8BIT
                        MNEMONIC
                        MNEM
                        VISCII
                        VIQR
KOI8-R                  KOI8-R
                        HZ-GB-2312
                        IBM866
                        IBM775
                        KOI8-U
                        IBM00858
                        IBM00924
                        IBM01140
                        IBM01141
                        IBM01142
                        IBM01143
                        IBM01144
                        IBM01145
                        IBM01146
                        IBM01147
                        IBM01148
                        IBM01149
                        Bit5-HKSCS
                        IBM1047
                        PTCP154
                        Amiga-1251
                        KOI7-switched
                        BRF
                        TSCII
                        CP51932
                        windows-874
                        windows-1250
                        windows-1251
                        windows-1252
                        windows-1253
                        windows-1254
                        windows-1255
                        windows-1256
                        windows-1257
                        windows-1258
                        TIS-620
                        CP50220



*/





