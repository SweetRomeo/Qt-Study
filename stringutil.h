#ifndef STRINGUTIL_H
#define STRINGUTIL_H

#include <QObject>
#include <string>
#include <cctype>

class StringUtil : public QObject
{
    Q_OBJECT
public:
    explicit StringUtil(QObject *parent = nullptr);
    static std::string reverseString(std::string);
    static char* reverseString(char*);
    static bool CodelandUsernameValidation(std::string);
    static bool BracketMatcher(std::string);
    static bool isPalindrome(std::string);
    static bool isPalindrome(char*);
    static bool isPangram(std::string);
    static bool hasRepeatingLetters(std::string);
    static std::string LetterCount(std::string);
    static std::string LetterCapitalize(std::string);
    static std::string countVowels(std::string);
    static int countVowels(const char*);
    static int countWords(std::string);
    static int countWords(const char*);
    static std::string ABCheck(std::string);
    static std::string AlphabethSoup(std::string);
    static std::string CamelCase(std::string);
    static std::string ASCIIConversion(std::string);
    static std::string PalindromeCreator(std::string);
private:
    static int length(char*);
    static bool isVowel(char);
signals:
};

#endif // STRINGUTIL_H
