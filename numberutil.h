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
    int sumDigits(int val);
    int countDigits(int val);
    int reverse(int val);
    bool isArmstrong(int val);
    bool isPrime(const int val);
signals:
};

#endif // NUMBERUTIL_H
