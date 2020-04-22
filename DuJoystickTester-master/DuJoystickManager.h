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
};

enum JoyHatDirection
{
    CENTERED = 0,
    LEFT = -1,
    RIGHT = 1,
    DOWN = 1,
    UP = -1
};

enum JoysitckAxis
{
    AXIS_HORIZONTAL,
    AXIS_VERTICAL,
    NOT_AXIS
};

class DuJoystickManager : public QThread
{
    Q_OBJECT
public:
    DuJoystickManager(QObject *parent = nullptr);
signals:
    void SDL_joyButtonDown(int);
    void getConfiguration(int, int, int, int);
    void sendX(int);
    void sendY(int);
protected:
    void run() override;

};



#endif // DUJOYSTICKMANAGER_H
