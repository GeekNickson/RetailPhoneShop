#ifndef PHONESLIST_H
#define PHONESLIST_H

#include <QObject>
#include <phone.h>

static const int BY_PRICE = 2;
static const int BY_WEIGHT = 4;
static const int BY_BATTERY = 8;
static const int BY_CAMERA = 10;
static const int BY_RAM = 13;
static const int BY_FLASH = 14;

class PhonesList : public QList<QList<QByteArray>>
{
    static bool compareByPrice(const QList<QByteArray> &a, const QList<QByteArray> &b);
    static bool compareByWeight(const QList<QByteArray> &a, const QList<QByteArray> &b);
    static bool compareByBattery(const QList<QByteArray> &a, const QList<QByteArray> &b);
    static bool compareByCamera(const QList<QByteArray> &a, const QList<QByteArray> &b);
    static bool compareByRam(const QList<QByteArray> &a, const QList<QByteArray> &b);
    static bool compareByFlash(const QList<QByteArray> &a, const QList<QByteArray> &b);
public:
    PhonesList();

    //init with csv path
    PhonesList(QString pathToCsv);

    PhonesList applyFilters(int maxPrice,int minCamera, int minBattery);

public slots:
    void sort(int byField);
};

#endif // PHONESLIST_H
