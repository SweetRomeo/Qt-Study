#include "destination.h"

Destination::Destination(QObject *parent)
    : QObject{parent}
{}

void Destination::MySignal(QString message)
{
    qInfo() << message;
}
