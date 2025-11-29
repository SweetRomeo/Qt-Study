#include "teststringutil.h"
#include "stringutil.h"

TestStringUtil::TestStringUtil(QObject *parent)
    : QObject{parent}
{}

void TestStringUtil::shouldReturnReverseWhenThereisValidText()
{
    std::string testText1 = "kaya";
    std::string testText2 = "Ali papila";

    QCOMPARE(StringUtil::reverseString(testText1), "ayak");
    QCOMPARE(StringUtil::reverseString(testText2), "alipap ilA");

    QCOMPARE(StringUtil::reverseString(testText1.c_str()), "ayak");
    QCOMPARE(StringUtil::reverseString(testText2.c_str()), "alipap ilA");
}

void TestStringUtil::shouldReturnTrueWhenTextisPalindrome()
{
    std::string testText1 = "alipapila";
    std::string testText2 = "ey edip adanada pide ye";

    QCOMPARE(StringUtil::isPalindrome(testText1), true);
    QCOMPARE(StringUtil::isPalindrome(testText2), true);

    QCOMPARE(StringUtil::isPalindrome(testText1.c_str()), true);
    QCOMPARE(StringUtil::isPalindrome(testText2.c_str()), true);
}

void TestStringUtil::shouldReturnFalseWhenTextisNotPalindrome()
{
    std::string testText1 = "Ali papila";
    std::string testText2 = "At sahibi gibi hasta";

    QCOMPARE(StringUtil::isPalindrome(testText1), false);
    QCOMPARE(StringUtil::isPalindrome(testText2), false);

    QCOMPARE(StringUtil::isPalindrome(testText1.c_str()), false);
    QCOMPARE(StringUtil::isPalindrome(testText2.c_str()), false);
}


QTEST_APPLESS_MAIN(TestStringUtil)
