#include "thirdwindow.h"
#include "ui_thirdwindow.h"

thirdWindow::thirdWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::thirdWindow)
{
    ui->setupUi(this);
}

thirdWindow::~thirdWindow()
{
    delete ui;
}
