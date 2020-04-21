#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <SDL2/SDL.h>

namespace Ui
{
class Widget;
}

class DuJoystickManager;
class TreadForLoop;

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
    TreadForLoop *treadForLoop;

    void manageJoystickButton(int button);
    void manageJoystickAxis(int axisValue,int axis);
    void displayConfiguration(int, int, int, int);
    void moveEntity(int,int);
};

#endif // WIDGET_H
