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

int StringUtil::countVowels(const char* text)
{
    int count = 0;
    while (*text)
    {
        if (isVowel(*text++))
        {
            count++;
        }
    }
    return count;
}

int StringUtil::countWords(std::string text)
{
    int count = 1;
    for (char c : text)
    {
        if (isspace(c))
        {
            count++;
        }
    }
    return count;
}

int StringUtil::countWords(const char* text)
{
    int count = 1;
    while (*text)
    {
        if (isspace(*text++))
        {
            count++;
        }
    }
    return count;
}

std::string StringUtil::ABCheck(const std::string text)
{
    for (auto i = 0; i < text.size(); ++i)
    {
        if (text[i] == 'a' && text[i + 4] == 'b' || text[i] == 'b' && text[i + 4] == 'a')
        {
            return "true";
        }
    }
    return "false";
}

std::string StringUtil::AlphabethSoup(std::string text)
{
    std::sort(text.begin(), text.end());
    return text;
}

std::string StringUtil::CamelCase(std::string text)
{
    std::string resultText;
    bool isBegin = true;
    for (char c : text)
    {
        if (std::isalpha(c))
        {
            resultText += isBegin ? toupper(c) : tolower(c);
            isBegin = false;
        }
        else
        {
            isBegin = true;
        }
    }
    resultText[0] = text[0];
    return resultText;
}

std::string StringUtil::ASCIIConversion(std::string text)
{
    std::string resultText;
    for (auto i = 0; i < text.length(); ++i)
    {
        if (!isspace(text[i]))
        {
            int temp = text[i];
            resultText += std::to_string(temp);
        }
        else
        {
            resultText += text[i];
        }
    }
    return resultText;
}

std::string StringUtil::PalindromeCreator(std::string text) {

    if (isPalindrome(text)) {
        return "palindrome";
    }

    for (auto i = 0; i < text.length(); ++i)
    {
        std::string temp = text;
        temp.erase(temp.begin() + i);

        if (isPalindrome(temp)) {
            return std::string(1, text[i]);
        }
    }

    for (auto i = 0; i < text.length(); ++i)
    {
        for (auto j = i + 1; j < text.length(); ++j)
        {
            std::string temp = text;
            temp.erase(temp.begin() + j);
            temp.erase(temp.begin() + i);

            if (isPalindrome(temp)) {
                std::string result = "";
                result += text[i];
                result += text[j];
                return result;
            }
        }
    }

    return "not possible";
}

std::string StringUtil::RemoveBrackets(std::string text)
{
    auto count = 0;
    for (char c : text)
    {
        if (c == '(')
        {
            count++;
        }
        else if (c == ')' && count > 0)
        {
            count--;
        }
        else
        {
            count++;
        }
    }
    return std::to_string(count);
}

bool StringUtil::isAdjacent(std::string str)
{
    for (int i = 0; i < str.size() - 2; ++i)
    {
        if (isdigit(str[i]) && isdigit(str[i + 1]) && isdigit(str[i + 2]))
        {
            return true;
        }
    }
    return false;
}

bool StringUtil::hasThreeUniqueDigits(std::string str)
{
    std::string result;
    for (char ch : str)
    {
        if (isdigit(ch))
        {
            if (auto search = result.find(ch); search == std::string::npos)
            {
                result += ch;
            }
        }
    }
    return result.size() == 3;
}

bool StringUtil::ThreeNumbers(std::string str) {
    std::string temp;
    for (auto i = 0; i < str.size(); ++i)
    {
        if (!isspace(str[i]))
        {
            temp += str[i];
        }
        else
        {
            if (!hasThreeUniqueDigits(temp) || isAdjacent(temp))
            {
                return false;
            }
            temp = "";
        }
    }
    return hasThreeUniqueDigits(temp) && !isAdjacent(temp);
}

std::string StringUtil::DifferentCases(std::string)
{
    string temp;
    string result;
    bool isBegin = true;
    for (char ch : str)
    {
        if (isalpha(ch))
        {
            temp += isBegin ? toupper(ch) : tolower(ch);
            isBegin = false;
        }
        else {
            result += temp;
            temp = "";
            isBegin = true;
        }
    }
    result += temp;
    return result;
}

std::string StringUtil::SwapCase(std::string text)
{
    for (auto i = 0; i < text.size(); ++i)
    {
        if (isalpha(text[i]))
        {
            text[i] = isupper(text[i]) ? tolower(text[i]) : toupper(text[i]);
        }
    }
    return text;
}

std::string StringUtil::NumberEncoding(std::string str)
{
    std::string alphabeth = " abcdefghijklmnopqrstuvwxyz";
    std::string result;
    for (auto i = 0; i < str.size(); ++i)
    {
        if (isalpha(str[i]))
        {
            auto search = alphabeth.find(str[i]);
            result += std::to_string(search);
        }
        else {
            result += str[i];
        }
    }
    return result;
}

int StringUtil::ConsonantCount(std::string str)
{
    std::string consonantLetters = "bcdfghjklmnpqrstvwxyz";
    int consonantCount = 0;
    for (char c : str) {
        if (auto search = consonantLetters.find(tolower(c)); search != std::string::npos) {
            consonantCount++;
        }
    }
    return consonantCount;
}

std::string StringUtil::DashInsert(std::string str)
{
    std::string result;
    for (auto i = 0; i < str.size() - 1; i++)
    {
        int num1 = str[i] - '0';
        int num2 = str[i + 1] - '0';

        if (num1 % 2 == 1 && num2 % 2 == 1)
        {
            result += std::to_string(num1) + "-";
        }
        else
        {
            result += std::to_string(num1);
        }
    }
    result += str[str.size() - 1];

    return result;
}
