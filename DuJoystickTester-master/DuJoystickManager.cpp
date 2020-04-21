#include "DuJoystickManager.h"
#include <SDL2/SDL.h>
#include <QDebug>

#define MAX_AXIS_VALUE 32768

DuJoystickManager::DuJoystickManager(QObject *parent)
    : QThread(parent)
{

}

void DuJoystickManager::run()
{ 
    bool update;
    SDL_Event event;
    SDL_Joystick *joystick;
    joystick = SDL_JoystickOpen(0);
    SDL_Init(SDL_INIT_JOYSTICK);
    SDL_JoystickEventState(SDL_ENABLE);
    emit getConfiguration(SDL_JoystickNumAxes(joystick),
                          SDL_JoystickNumButtons(joystick),
                          SDL_JoystickNumBalls(joystick),
                          SDL_JoystickNumHats(joystick));

    while (SDL_WaitEvent(&event)) {
        {
            if (event.type == SDL_JOYBUTTONDOWN) {
                emit SDL_joyButtonDown(event.jbutton.button);
            }
            else
                if (event.type == SDL_JOYAXISMOTION) {
                    //emit SDL_joyAxisMotion(event.jaxis.value, event.jaxis.axis);
                    if(event.jaxis.axis == AXIS_HORIZONTAL)
                    {
                        if(event.jaxis.value > MAX_AXIS_VALUE/2) this->X = 1;
                        if(event.jaxis.value < -MAX_AXIS_VALUE/2) this->X = -1;
                        if(event.jaxis.value < MAX_AXIS_VALUE/2 && event.jaxis.value > -MAX_AXIS_VALUE/2) this->X = 0;
                    }
                    if(event.jaxis.axis == AXIS_VERTICAL)
                    {
                        if(event.jaxis.value > MAX_AXIS_VALUE/2) this->Y = 1;
                        if(event.jaxis.value < -MAX_AXIS_VALUE/2) this->Y = -1;
                        if(event.jaxis.value < MAX_AXIS_VALUE/2 && event.jaxis.value > -MAX_AXIS_VALUE/2) this->Y = 0;
                    }
                }
        }
        msleep(10);
    }
}

TreadForLoop::TreadForLoop(QObject *parent)
    : QThread(parent)
{

}

void TreadForLoop::run()
{
    while(true)
    {
        emit sendData(ptr->X,ptr->Y);
        msleep(10);
    }
}
