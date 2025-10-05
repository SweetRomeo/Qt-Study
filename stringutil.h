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
    static bool isPalindrome(std::string str);
    static bool isPalindrome(char*);
private:
    static int length(char*);
signals:
};

#endif // STRINGUTIL_H
