#ifndef NUMBERUTIL_H
#define NUMBERUTIL_H

#include <QObject>
#include <QtSql/QSqlDriverCreator>
#include <cmath>

class NumberUtil : public QObject
{
    Q_OBJECT
public:
    explicit NumberUtil(QObject *parent = nullptr);
    static int power(int a, int b);
    static int factorial(int val);
    static unsigned long long factorial(long long val);
    static int sumDigits(int val);
    static int countDigits(int val);
    static int reverse(int val);
    static bool isArmstrong(int val);
    static bool isPrime(const int val);
signals:
};

#endif // NUMBERUTIL_H
