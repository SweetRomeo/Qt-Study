#include "stringutil.h"

StringUtil::StringUtil(QObject *parent)
    : QObject{parent}
{}

int StringUtil::length(char* text)
{
    int len = 0;
    while (*text++ != '\0')
    {
        len++;
    }
    return len;
}

std::string StringUtil::reverseString(std::string text)
{
    return std::string(text.rbegin(), text.rend());
}

char* StringUtil::reverseString(char* text)
{
    int len = length(text);
    for (int i = 0; i < len / 2; ++i)
    {
        char temp = *(text + i);
        *(text + i) = *(text + len - i - 1);
        *(text + len - i - 1) = temp;
    }
    return text;
}

bool CodelandUsernameValidation(std::string str) {
    auto len = str.length();
    if (len > 25 || len < 4 || !isalpha(str[0]) || str[len - 1] == '_' )
    {
        return false;
    }
    for (char ch : str)
    {
        if (!isalnum(ch) && ch != '_')
        {
            return false;
        }
    }
    return true;
}
