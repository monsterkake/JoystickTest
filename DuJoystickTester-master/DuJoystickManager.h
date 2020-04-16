#ifndef DUJOYSTICKMANAGER_H
#define DUJOYSTICKMANAGER_H

#include <QThread>

enum JoystickButton
{
    BUTTON1,
    BUTTON2,
    BUTTON3,
    BUTTON4,
    BUTTON5,
    BUTTON6,
    BUTTON7,
    BUTTON8,
    BUTTON9,
    BUTTON10,
    BUTTON11,
    BUTTON12,
    BUTTON13,
    BUTTON14,
    UP,
    DOWN,
    LEFT,
    RIGHT
};

enum JoysitckAxis
{
    AXIS_HORIZONTAL,
    AXIS_VERTICAL,
    AXIS_HV,
    NOT_AXIS
};

class DuJoystickManager : public QThread
{
    Q_OBJECT
public:
    DuJoystickManager(QObject *parent = nullptr);
signals:
    void SDL_joyButtonDown(int, int, int);
protected:
    void run() override;

};

#endif // DUJOYSTICKMANAGER_H
