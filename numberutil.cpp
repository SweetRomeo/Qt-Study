#include "numberutil.h"

NumberUtil::NumberUtil(QObject *parent)
    : QObject{parent}
{}

int NumberUtil::power(int a, int b)
{
    int result = 1;
    for (int i = 1; i <= b; ++i)
    {
        result *= a;
    }
    return result;
}

int NumberUtil::factorial(int val)
{
    int result = 1;
    for (int i = 2; i <= val; ++i)
    {
        result *= i;
    }
    return result;
}

unsigned long long NumberUtil::factorial(long long val)
{
    unsigned long long result = 1;

    for (int i = 2; i <= val; ++i)
    {
        result *= i;
    }
    return result;
}

int NumberUtil::sumDigits(int val)
{
    int sum = 0;
    while (val)
    {
        sum += val % 10;
        val /= 10;
    }
    return abs(sum);
}

int NumberUtil::countDigits(int val)
{
    int count = 0;
    do
    {
        count++;
        val /= 10;
    } while (val);
    return count;
}

bool NumberUtil::isArmstrong(int val)
{
    int temp = val;
    int sum = 0;
    int count = countDigits(val);
    while (val)
    {
        sum += pow(val % 10, count);
        val /= 10;
    }
    return temp == sum;
}

bool NumberUtil::isPrime(const int val)
{
    if (val <= 1)
        return false;
    if (val % 2 == 0)
        return val == 2;
    if (val % 3 == 0)
        return val == 3;
    if (val % 5 == 0)
        return val == 5;
    if (val % 7 == 0)
        return val == 7;
    for (int i = 11; i * i < val; i += 2)
    {
        if (val % i == 0)
            return false;
    }
    return true;
}

int NumberUtil::reverse(int val)
{
    int rev = 0;

    while (val)
    {
        rev *= 10;
        rev += val % 10;
        val /= 10;
    }
    return rev;
}
