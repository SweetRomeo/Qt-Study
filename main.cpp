#include <QCoreApplication>
#include <QDebug>
#include <iostream>
#include "numberutil.h"
#include "source.h"
#include "destination.h"

template<class Con>
void print(Con con)
{
    for (auto iter = con.begin(); iter != con.end(); ++iter)
    {
        qInfo() << *iter << " ";
    }
    qInfo() << "\n";
}

void isPrimeTestUntil(long long maxValue)
{
    for (int i = -10; i < maxValue; ++i)
        if (NumberUtil::isPrime(i))
        {
            qInfo() << i;
        }
}

int main(int argc, char *argv[])
{
    using std::cout;
    QCoreApplication a(argc, argv);

    Source oSource;
    Destination oDestination;

    QObject::connect(&oSource, &Source::MySignal, &oDestination,&Destination::MySignal);

    //oSource.test();

    oDestination.MySignal("Hello World");

    return a.exec();
}
