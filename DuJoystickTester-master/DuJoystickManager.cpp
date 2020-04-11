#include "DuJoystickManager.h"
#include <SDL2/SDL.h>
#include <QDebug>

DuJoystickManager::DuJoystickManager(QObject *parent)
    : QThread(parent)
{
    SDL_JoystickOpen(0);
}

void DuJoystickManager::run()
{
    while (true) {
        SDL_Event event;
        if (SDL_PollEvent(&event)) {
            if (event.type == SDL_JOYBUTTONDOWN) {
               emit SDL_joyButtonDown(event.jbutton.button);
            } else if (event.type == SDL_JOYAXISMOTION) {
                switch (event.jaxis.axis) {
                case AXIS_HORIZONTAL:
                    if (event.jaxis.value < -32768/2) {
                        emit SDL_joyButtonDown(LEFT);
                    }
                    if (event.jaxis.value > 32767/2){
                        emit SDL_joyButtonDown(RIGHT);
                    }
                    break;
                case AXIS_VERTICAL:
                    if (event.jaxis.value < -32768/2) {
                        emit SDL_joyButtonDown(UP);
                    }
                    if (event.jaxis.value > 32767/2) {
                        emit SDL_joyButtonDown(DOWN);
                    }
                    break;
                }
            }
        }
    }
}
