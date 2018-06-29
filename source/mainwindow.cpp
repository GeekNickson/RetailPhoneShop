#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //initial setup of window
    originalPhonesList = *(new PhonesList("C:/res/Phones_base.csv"));
    actualPhonesList = originalPhonesList;
    ui->scrollAreaWidgetContents->setLayout(new QVBoxLayout(ui->scrollArea));

    //adding values to combobox
    ui->sortTypeComboBox->addItem("by price");
    ui->sortTypeComboBox->addItem("by camera");
    ui->sortTypeComboBox->addItem("by battery");

    connect(ui->sortTypeComboBox,SIGNAL(currentIndexChanged(QString)),this,SLOT(sortComboBoxStateChanged()));
    connect(ui->screen2BackButton,SIGNAL(clicked(bool)),this,SLOT(screen2BackButtonClicked()));
    connect(ui->applyFiltersButton,SIGNAL(clicked(bool)),this,SLOT(applyFiltersButtonClicked()));
    connect(ui->resetFiltersButton,SIGNAL(clicked(bool)),this,SLOT(resetFiltersButtonClicked()));

    //this causes sort by price by default
    sortComboBoxStateChanged();

    //Dynamicaly creating widgets
    reloadMainWidgets();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::priceButtonClicked()
{

    QPushButton* buttonSender = (QPushButton*)sender();
    PhoneWidget* senderParent = (PhoneWidget*)buttonSender->parent();
    qDebug()<<"price button: ";
    //fill second screen with this info
    //image
    QPixmap pic(*senderParent->getPathToImage());
    ui->secondScreenImage->setPixmap(pic.scaledToHeight(366));
    ui->secondScreenPhoneName->setText(*senderParent->getName());
    ui->specsLabel1->setText("weight: "+*senderParent->getWeight()+" grams");
    ui->specsLabel2->setText("size: "+*senderParent->getSize()+" mm");
    ui->specsLabel3->setText("camera: "+*senderParent->getCamera()+" Megapixels");
    ui->specsLabel4->setText("screen resolution: "+*senderParent->getScreen());
    ui->specsLabel5->setText("processor: "+*senderParent->getSoc());
    ui->specsLabel6->setText("battery capacity: "+*senderParent->getBatteryCapacity()+" mAh");
    ui->specsLabel7->setText("colors: "+*senderParent->getColors());
    ui->specsLabel8->setText("material: "+*senderParent->getMaterial());

    ui->secondScreenBuyButton->setText("Buy this for "+*senderParent->getPrice()+"$");

    //ui->

    ui->firstScreen->setCurrentIndex(1);
    ui->firstScreen->show();
}

void MainWindow::screen2BackButtonClicked()
{
    ui->firstScreen->setCurrentIndex(0);
}

void MainWindow::applyFiltersButtonClicked()
{
    int maxPrice = ui->sortingPriceSpinBox->value();
    int minCamera = ui->sortingCameraSpinBox->value();
    int minBattery = ui->sortingBatterySpinBox->value();
    actualPhonesList = originalPhonesList.applyFilters(maxPrice,minCamera,minBattery);

    sortComboBoxStateChanged();
    reloadMainWidgets();
}

void MainWindow::resetFiltersButtonClicked()
{
    //reseting filters
    actualPhonesList = originalPhonesList;

    sortComboBoxStateChanged();
    reloadMainWidgets();
}

void MainWindow::reloadMainWidgets()
{
    //if there's widgets already, clear it
    QLayoutItem *child; //replace with widget
    while ((child = ui->scrollAreaWidgetContents->layout()->takeAt(0)) != 0) {
        delete child->widget();
    }

    ui->scrollAreaWidgetContents->show();
    foreach (QList<QByteArray> phone, actualPhonesList) {
        PhoneWidget *phoneMainWidget = new PhoneWidget(phone,this);
        QPushButton *pb = phoneMainWidget->getPhonePriceButton();
        connect(pb,SIGNAL(clicked(bool)),this,SLOT(priceButtonClicked()));
        phoneMainWidget->setFixedHeight(200);
        ui->scrollAreaWidgetContents->layout()->addWidget(phoneMainWidget);
    }
}

void MainWindow::sortComboBoxStateChanged()
{
    QComboBox *senderComboBox = ui->sortTypeComboBox;
    QString text= senderComboBox->currentText();
    if(text=="by price"){
        actualPhonesList.sort(BY_PRICE);
    }
    if(text=="by camera"){
        actualPhonesList.sort(BY_CAMERA);
    }
    if(text=="by battery"){
        actualPhonesList.sort(BY_BATTERY);
    }
    reloadMainWidgets();
}


