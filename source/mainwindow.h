#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QStringList>
#include <QDebug>
#include <QPushButton>
#include <phonewidget.h>
#include <phoneslist.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private:
    Ui::MainWindow *ui;

    //contains original loaded set of phones
    PhonesList originalPhonesList;

    //contains filtered and sorted list
    PhonesList actualPhonesList;

    void reloadMainWidgets();

public slots:
    void sortComboBoxStateChanged();
    void priceButtonClicked();
    void screen2BackButtonClicked();
    void applyFiltersButtonClicked();
    void resetFiltersButtonClicked();
};

#endif // MAINWINDOW_H
