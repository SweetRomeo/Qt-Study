#ifndef TESTSTRINGUTIL_H
#define TESTSTRINGUTIL_H

#include <QObject>
#include <QtTest>

class TestStringUtil : public QObject
{
    Q_OBJECT
public:
    explicit TestStringUtil(QObject *parent = nullptr);
private slots:
    void shouldReturnReverseWhenThereisValidText();
    void shouldReturnTrueWhenTextisPalindrome();
    void shouldReturnFalseWhenTextisNotPalindrome();
signals:
};

#endif // TESTSTRINGUTIL_H
