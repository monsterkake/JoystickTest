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

//enum JoyHatDirection
//{
//    SDL_HAT_CENTERED,

//    SDL_HAT_LEFT,
//    SDL_HAT_RIGHT,
//    SDL_HAT_DOWN,
//    SDL_HAT_UP,

//    SDL_HAT_LEFTUP,
//    SDL_HAT_LEFTDOWN,
//    SDL_HAT_RIGHTDOWN,
//    SDL_HAT_RIGHTUP,
//};

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
    int X = 0;
    int Y = 0;
    DuJoystickManager(QObject *parent = nullptr);
signals:
    void SDL_joyButtonDown(int);
    void SDL_joyAxisMotion(int,int);
    void getConfiguration(int, int, int, int);
protected:
    void run() override;

};

class TreadForLoop : public QThread
{
    Q_OBJECT
public:
    DuJoystickManager* ptr ;
    TreadForLoop(QObject *parent = nullptr);
signals:
    void sendData(int,int);
protected:
    void run() override;

};

#endif // DUJOYSTICKMANAGER_H
