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

bool StringUtil::CodelandUsernameValidation(std::string str) {
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

bool StringUtil::BracketMatcher(std::string str)
{
    int count = 0;
    for (char ch : str)
    {
        if (ch == '(')
        {
            count++;
        }
        else if (ch == ')')
        {
            count--;
        }
        if (count < 0)
        {
            return false;
        }
    }

    return count == 0;
}

std::string LongestWord(std::string text) {
    std::string temp;
    std::string result;
    int len = 0;
    for (char ch : text)
    {
        if (!isspace(ch))
        {
            if (isalnum(ch))
            {
                temp += ch;
            }
        }
        else
        {
            if (temp.length() > len)
            {
                len = temp.length();
                result = temp;
            }
            temp = "";
        }
    }
    if (temp.length() > len)
    {
        result = temp;
    }

    return result;
}
