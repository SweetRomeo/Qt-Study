#include <QCoreApplication>
#include <QDebug>

template<class Con>
void print(Con con)
{
    for (auto iter = con.begin(); iter != con.end(); ++iter)
    {
        qInfo() << *iter << " ";
    }
    qInfo() << "\n";
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qInfo() << "Info" << '\n';
    qDebug() << "Debug Message" << '\n';
    qWarning() << "Warning Message" << '\n';
    qFatal() << "Fatal Error" << '\n';


    return a.exec();
}
