#ifndef PHONEGROUPBOX_H
#define PHONEGROUPBOX_H

#include <QGroupBox>

namespace Ui {
class GroupBox;
}

class GroupBox : public QGroupBox
{
    Q_OBJECT

public:
    explicit GroupBox(QWidget *parent = 0);
    ~GroupBox();

private:
    Ui::GroupBox *ui;
};

#endif // PHONEGROUPBOX_H
