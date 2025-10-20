#include "owner.h"

Owner::Owner(QObject *parent) : QObject(parent) {}

void Owner::giveSnacks()
{
    qInfo() << "The snacks are ready";
    emit treats();
}
