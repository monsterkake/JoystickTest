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
    int horizontalDirection = 0, verticalDirection = 0;
    SDL_Event event;
    SDL_Joystick *joystick;
    joystick = SDL_JoystickOpen(0);
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
            if (event.type == SDL_JOYAXISMOTION) {
                if(event.jaxis.axis == AXIS_HORIZONTAL)
                {

                    if(event.jaxis.value > MAX_AXIS_VALUE/2) horizontalDirection = RIGHT;
                    if(event.jaxis.value < -MAX_AXIS_VALUE/2) horizontalDirection = LEFT;
                    if(event.jaxis.value < MAX_AXIS_VALUE/2 && event.jaxis.value > -MAX_AXIS_VALUE/2) horizontalDirection = CENTERED;
                    sendX(horizontalDirection);
                }
                if(event.jaxis.axis == AXIS_VERTICAL)
                {
                    if(event.jaxis.value > MAX_AXIS_VALUE/2) verticalDirection = DOWN;
                    if(event.jaxis.value < -MAX_AXIS_VALUE/2) verticalDirection = UP;
                    if(event.jaxis.value < MAX_AXIS_VALUE/2 && event.jaxis.value > -MAX_AXIS_VALUE/2) verticalDirection = CENTERED;
                    sendY(verticalDirection);
                }
            }
        }
        msleep(10);
    }
}


