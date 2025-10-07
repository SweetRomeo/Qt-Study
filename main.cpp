#include <QCoreApplication>
#include <QTextStream>
#include <QDebug>
#include <iostream>
#include <string>
#include "numberutil.h"
#include "station.h"
#include "radio.h"

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

void radioStationTest()
{

    Radio boombox;
    Station* channels[3];

    channels[0] = new Station(&boombox, 94, "Music");
    channels[1] = new Station(&boombox, 87, "Magazine");
    channels[2] = new Station(&boombox, 104, "News");

    //boombox.connect(&boombox, &Radio::quit, &a, &QCoreApplication::quit);
    bool running = true;
    QTextStream qtin(stdin);

    while (running)
    {
        qInfo() << "Enter on, off, test or quit";
        std::string line;
        std::cin >> line;
        std::cout << line;
        if (line == "ON")
        {
            qInfo() << "Turning the radio on";
            for (int i = 0; i < 3; ++i)
            {
                Station* channel = channels[i];
                boombox.connect(channel, &Station::send, &boombox, &Radio::listen);
            }
            qInfo() << "Radio is on";
        }

        if (line == "OFF")
        {
            qInfo() << "Turning the radio off";
            for (int i = 0; i < 3; ++i)
            {
                Station* channel = channels[i];
                boombox.disconnect(channel, &Station::send, &boombox, &Radio::listen);
            }
            qInfo() << "Radio is off";
        }

        if (line == "TEST")
        {
            qInfo() << "Testing";
            for (int i = 0; i < 3; ++i)
            {
                Station* channel = channels[i];
                channel->broadcast("Broadcasting live!");
            }
            qInfo() << "Test complete";
        }

        if (line == "QUIT")
        {
            qInfo() << "Quitting";
            running = false;
        }
    }
}

int main(int argc, char *argv[])
{
    using namespace std;
    QCoreApplication a(argc, argv);

    qDebug() << "=== INPUT TEST ===";
    qDebug() << "Testing QTextStream...";

    QTextStream in(stdin);
    QString line = in.readLine();
    qDebug() << "QTextStream result:" << line;

    qDebug() << "Testing std::cin...";
    std::string stdline;
    std::getline(std::cin, stdline);
    qDebug() << "std::cin result:" << QString::fromStdString(stdline);

    radioStationTest();
    return a.exec();
}
