#include "stringutil.h"

StringUtil::StringUtil(QObject *parent)
    : QObject{parent}
{}

bool StringUtil::isVowel(char ch)
{
    return ch == 'a' || ch == 'A' || ch == 'e' ||
           ch == 'E' || ch == 'i' || ch == 'I' ||
           ch == 'o' || ch == 'O' || ch == 'u' ||
           ch == 'U';
}

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

bool StringUtil::isPalindrome(std::string str)
{
    str.erase(std::remove_if(str.begin(), str.end(), [](unsigned char x) { return std::isspace(x); }), str.end());
    return std::string(str.rbegin(), str.rend()) == str;
}

bool StringUtil::isPalindrome(char* text)
{
    int len = length(text);
    for (int i = 0; i < len; ++i)
    {
        if (*(text + len - 1 - i) != *(text + i))
        {
            return false;
        }
    }
    return true;
}

bool StringUtil::isPangram(std::string text)
{
    std::string alphabeth = "abcdefghijklmnqrstpuoxwyz";

    for (char ch : alphabeth)
    {
        if (auto search = text.find(ch); search == std::string::npos)
        {
            return false;
        }
    }
    return true;
}

std::string StringUtil::LetterCapitalize(std::string text)
{
    bool isSpaceFound = true;
    for (int i = 0; i < text.length(); ++i)
    {
        if (!isspace(text[i]) && isSpaceFound)
        {
            if (islower(text[i]))
            {
                text[i] = std::toupper(text[i]);
            }
            isSpaceFound = false;
        }
        else if (isspace(text[i]))
        {
            isSpaceFound = true;
        }
    }
    return text;
}

bool hasRepeatingLetters(std::string str)
{
    std::unordered_map<char, int> letters;
    for (char c : str)
    {
        letters[c]++;
    }
    for (std::pair<char, int> letter : letters)
    {
        if (letter.second > 1)
        {
            return true;
        }
    }
    return false;
}

std::string LetterCount(std::string str) {
    std::string temp;
    for (char c : str)
    {
        if (!isspace(c))
        {
            temp += c;
        }
        else
        {
            if (hasRepeatingLetters(temp))
            {
                return temp;
            }
            temp = "";
        }
    }
    if (hasRepeatingLetters(temp))
    {
        return temp;
    }
    return "-1";
}

std::string StringUtil::countVowels(std::string text)
{
    int count = 0;
    for (char c : text)
    {
        if (isVowel(c))
        {
            count++;
        }
    }
    return std::to_string(count);
}
