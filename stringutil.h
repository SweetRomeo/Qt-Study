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
    int length(char*);
    std::string reverseString(std::string);
    char* reverseString(char*);
    bool CodelandUsernameValidation(std::string);
signals:
};

#endif // STRINGUTIL_H
