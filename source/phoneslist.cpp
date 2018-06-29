#include "phoneslist.h"
#include <QFile>
#include <QDebug>


bool PhonesList::compareByPrice(const QList<QByteArray> &a, const QList<QByteArray> &b)
{
    return ((QByteArray)(a[BY_PRICE])).toInt()<((QByteArray)(b[BY_PRICE])).toInt();
}

bool PhonesList::compareByWeight(const QList<QByteArray> &a, const QList<QByteArray> &b)
{
    return ((QByteArray)(a[BY_WEIGHT])).toInt()<((QByteArray)(b[BY_WEIGHT])).toInt();
}

bool PhonesList::compareByBattery(const QList<QByteArray> &a, const QList<QByteArray> &b)
{
    return ((QByteArray)(a[BY_BATTERY])).toInt()<((QByteArray)(b[BY_BATTERY])).toInt();
}

bool PhonesList::compareByCamera(const QList<QByteArray> &a, const QList<QByteArray> &b)
{
    return ((QByteArray)(a[BY_CAMERA])).toInt()<((QByteArray)(b[BY_CAMERA])).toInt();
}

bool PhonesList::compareByRam(const QList<QByteArray> &a, const QList<QByteArray> &b)
{
    return ((QByteArray)(a[BY_RAM])).toInt()<((QByteArray)(b[BY_RAM])).toInt();
}

bool PhonesList::compareByFlash(const QList<QByteArray> &a, const QList<QByteArray> &b)
{
    return ((QByteArray)(a[BY_FLASH])).toInt()<((QByteArray)(b[BY_FLASH])).toInt();
}

PhonesList::PhonesList()
{

}

PhonesList::PhonesList(QString pathToCsv)
{
    //parsing
    QFile file(pathToCsv);
    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << file.errorString();
    }
    while (!file.atEnd()) {
        QList<QByteArray> phone;
        QByteArray line = file.readLine();
        phone = line.split(',');
        this->append(phone);
    }
    //clearing header of the table
    this->removeFirst();
}

void PhonesList::sort(int byField)
{
    switch (byField) {
    case BY_PRICE:
        std::sort(this->begin(),this->end(),compareByPrice);
        break;
    case BY_BATTERY:
        std::sort(this->begin(),this->end(),compareByBattery);
        break;
    case BY_CAMERA:
        std::sort(this->begin(),this->end(),compareByCamera);
        break;
    case BY_FLASH:
        std::sort(this->begin(),this->end(),compareByFlash);
        break;
    case BY_RAM:
        std::sort(this->begin(),this->end(),compareByRam);
        break;
    case BY_WEIGHT:
        std::sort(this->begin(),this->end(),compareByWeight);
        break;
    default:
        std::sort(this->begin(),this->end(),compareByPrice);
        break;
    }
}

PhonesList PhonesList::applyFilters(int maxPrice,int minCamera, int minBattery){
    PhonesList result = *this;

    //filtering
    QMutableListIterator<QList<QByteArray>> i(result);
    while (i.hasNext()) {
        QList<QByteArray> phone = i.next();
        //price
        if (((QByteArray)phone[BY_PRICE]).toInt() > maxPrice){
            qDebug()<<"phone costs: "<<((QByteArray)phone[BY_PRICE]).toInt();
            i.remove();
        }
        //camera
        if (((QByteArray)phone[BY_CAMERA]).toInt()<minCamera){
            i.remove();
        }
        //battery
        if (((QByteArray)phone[BY_BATTERY]).toInt()<minBattery){
            i.remove();
        }
    }
    return result;
}

