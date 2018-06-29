#ifndef PHONEWIDGET_H
#define PHONEWIDGET_H

#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QDebug>
#include <QSizePolicy>
#include <QPushButton>
#include <mainwindow.h>

class PhoneWidget : public QWidget{
    Q_OBJECT
private:
        QPushButton *phonePriceButton;
        int id;
        QString *name;
        QString *price;
        QString *pathToImage;
        QString *weight;
        QString *size;
        QString *material;
        QString *colors;
        QString *batteryCapacity;
        QString *screen;
        QString *camera;
        QString *soc;
        QString *androidVersion;
        QString *miuiVersion;

        void openSecondWindow();

public:
    explicit PhoneWidget(QWidget *parent = nullptr);

    //construct class from string of csv file
        explicit PhoneWidget(QList<QByteArray> phoneData,QWidget *parent = nullptr);
    int getId();
    QPushButton* getPhonePriceButton();


    QString *getName() const;

    QString *getPrice() const;

    QString *getPathToImage() const;

    QString *getWeight() const;

    QString *getSize() const;

    QString *getMaterial() const;

    QString *getColors() const;

    QString *getBatteryCapacity() const;

    QString *getScreen() const;

    QString *getCamera() const;

    QString *getSoc() const;

    QString *getAndroidVersion() const;

    QString *getMiuiVersion() const;

signals:

public slots:
};

#endif // PHONEWIDGET_H
