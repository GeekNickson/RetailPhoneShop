#ifndef THIRDWINDOW_H
#define THIRDWINDOW_H

#include <QMainWindow>

namespace Ui {
class thirdWindow;
}

class thirdWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit thirdWindow(QWidget *parent = 0);
    ~thirdWindow();

private:
    Ui::thirdWindow *ui;
};

#endif // THIRDWINDOW_H
