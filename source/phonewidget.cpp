#include "phonewidget.h"

QString *PhoneWidget::getName() const
{
    return name;
}

QString *PhoneWidget::getPrice() const
{
    return price;
}

QString *PhoneWidget::getPathToImage() const
{
    return pathToImage;
}

QString *PhoneWidget::getWeight() const
{
    return weight;
}

QString *PhoneWidget::getSize() const
{
    return size;
}

QString *PhoneWidget::getMaterial() const
{
    return material;
}

QString *PhoneWidget::getColors() const
{
    return colors;
}

QString *PhoneWidget::getBatteryCapacity() const
{
    return batteryCapacity;
}

QString *PhoneWidget::getScreen() const
{
    return screen;
}

QString *PhoneWidget::getCamera() const
{
    return camera;
}

QString *PhoneWidget::getSoc() const
{
    return soc;
}

QString *PhoneWidget::getAndroidVersion() const
{
    return androidVersion;
}

QString *PhoneWidget::getMiuiVersion() const
{
    return miuiVersion;
}

PhoneWidget::PhoneWidget(QWidget *parent) : QWidget(parent)
{

}

PhoneWidget::PhoneWidget(QList<QByteArray> phoneData, QWidget *parent)
{
/*      |-------------|--------------------------------------|
 *      |             |  NameOfPhone                         |
 *      |             |     *color                           |
 *      |   Image of  |     *screen                          |
 *      |    Phone    |     *battery                ######## |
 *      |             |     *camera                 # more # |
 *      |             |                             ######## |
 *      |-------------|--------------------------------------|
 */
    //"parse" the string
    //qDebug()<<"len: "<<phoneData.length();
    int index = 0;
    this->id = phoneData[index++].toInt();
    name = new QString(phoneData[index++]);
    price = new QString(phoneData[index++]);
    pathToImage = new QString(phoneData[index++]);
    weight = new QString(phoneData[index++]);
    size = new QString(phoneData[index++]);
    material = new QString(phoneData[index++]);
    colors = new QString(phoneData[index++]);
    batteryCapacity = new QString(phoneData[index++]);
    screen = new QString(phoneData[index++]);
    camera = new QString(phoneData[index++]);
    soc = new QString(phoneData[index++]);
    androidVersion = new QString(phoneData[index++]);
    miuiVersion = new QString(phoneData[index++]);

    //  Fonts
    QFont *nameFont = new QFont("Trebuchet MS",25);
    nameFont->setBold(true);
    QFont *specsFont = new QFont("Trebuchet MS",16);

    //  I) setting the appropriate layout
    this->setLayout(new QHBoxLayout(this));

    //  II) filling layout with elements

    //      1) creating label to store image
    //          a) label itself
    QLabel *phoneImage = new QLabel(this);
    //          b) QPixmap representing pixels of image,
    //            it creates from path
    QPixmap pic(*pathToImage);
    //          c) setting pixmap to our label
    phoneImage->setPixmap(pic.scaledToHeight(180));
    //          d) resizing

    //          e) adding label to main layout of widget
    this->layout()->addWidget(phoneImage);

    //price. we will open next screen by pushing this button
    phonePriceButton= new QPushButton((*price)+"$",this);
    phonePriceButton->setFixedWidth(55);
    phonePriceButton->setFixedHeight(30);
    phonePriceButton->setFont(*specsFont);
    //phonePrice->setStyleSheet("border: 1px solid black");
    //connect(phonePriceButton,SIGNAL(clicked(bool)),parent,SLOT());
    this->layout()->addWidget(phonePriceButton);

    //      2) creating anoter layout to store specs and name of phone
    //          a) Widget in which layout is stored
    QWidget *phoneSpecsWidget = new QWidget(this);
    //          b) setting the appropriate layout for widget
    phoneSpecsWidget->setLayout(new QVBoxLayout(phoneSpecsWidget));

    //      3) filling phoneSpecsWidget

    //      *0) label for name of phone
    QLabel *phoneNameLabel = new QLabel(*name);
    phoneNameLabel->setFont(*nameFont);
    //          a)store it in phoneSpecsWidget
    phoneSpecsWidget->layout()->addWidget(phoneNameLabel);

    //      *1) label for color of phone
    QLabel *phoneColorLabel = new QLabel("colors: "+(*colors));
    phoneColorLabel->setFont(*specsFont);
    //          a)store it in phoneSpecsWidget
    phoneSpecsWidget->layout()->addWidget(phoneColorLabel);

    //      *2) label for screen of phone
    QLabel *phoneScreenLabel = new QLabel("screen: "+(*screen));
    phoneScreenLabel->setFont(*specsFont);
    //          a)store it in phoneSpecsWidget
    phoneSpecsWidget->layout()->addWidget(phoneScreenLabel);

    //      *3) label for battery of phone
    QLabel *phoneBatteryLabel = new QLabel("battery: "+(*batteryCapacity)+" mAh");
    phoneBatteryLabel->setFont(*specsFont);
    //          a)store it in phoneSpecsWidget
    phoneSpecsWidget->layout()->addWidget(phoneBatteryLabel);

    //      *4) label for camera of phone
    QLabel *phoneCameraLabel = new QLabel("camera: "+(*camera)+" MP");
    phoneCameraLabel->setFont(*specsFont);
    //          a)store it in phoneSpecsWidget
    phoneSpecsWidget->layout()->addWidget(phoneCameraLabel);

    //      4) adding phoneSpecsWidget to main layout of widget
    this->layout()->addWidget(phoneSpecsWidget);

    //css style for border
    //this->setStyleSheet(".PhoneWidget{border: 1px solid black;}");
}

int PhoneWidget::getId()
{
    return id;
}

QPushButton* PhoneWidget::getPhonePriceButton()
{
    return phonePriceButton;
}


