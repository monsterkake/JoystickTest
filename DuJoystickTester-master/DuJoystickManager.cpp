#include "DuJoystickManager.h"
#include <SDL2/SDL.h>
#include <QDebug>

#define MAX_AXIS_VALUE 32768

DuJoystickManager::DuJoystickManager(QObject *parent)
    : QThread(parent)
{
    SDL_JoystickOpen(0);
}

void DuJoystickManager::run()
{
    SDL_Event event;
    while (true) {
        SDL_PollEvent(&event);
        if (event.type == SDL_JOYBUTTONDOWN) {
            emit SDL_joyButtonDown(0, NOT_AXIS ,event.jbutton.button);
        }
        else
            if (event.type == SDL_JOYAXISMOTION) {
                {
                    if(event.jaxis.axis == AXIS_VERTICAL)
                        emit SDL_joyButtonDown(event.jaxis.value, AXIS_VERTICAL, 0);
                    if(event.jaxis.axis == AXIS_HORIZONTAL)
                        emit SDL_joyButtonDown(event.jaxis.value, AXIS_HORIZONTAL, 0);
                }
            }
        msleep(10);
    }
}
