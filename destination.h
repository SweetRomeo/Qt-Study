#ifndef DESTINATION_H
#define DESTINATION_H

#include <QObject>
#include <QDebug>
#include <QString>

class Destination : public QObject
{
    Q_OBJECT
public:
    explicit Destination(QObject *parent = nullptr);

signals:
    void arrived();

public slots:
    void MySignal(QString message);
};

#endif // DESTINATION_H
