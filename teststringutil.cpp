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

QTEST_APPLESS_MAIN(TestStringUtil)
