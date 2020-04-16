#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui
{
class Widget;
}

class DuJoystickManager;

class Widget : public QWidget
{
    Q_OBJECT
public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();
private slots:
    void on_pushButton_clicked();

private:
    Ui::Widget *ui;
    DuJoystickManager *mJoyManager;

    void manageJoystick(int speed,int axis,int button);
};

#endif // WIDGET_H
