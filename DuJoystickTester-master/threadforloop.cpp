#include "ThreadForLoop.h"
#include "DuJoystickManager.h"

TreadForLoop::TreadForLoop(QObject *parent, DuJoystickManager* ptr)
    : QThread(parent)
{
    connect(ptr, &DuJoystickManager::sendX, this,
            &TreadForLoop::setX);
    connect(ptr, &DuJoystickManager::sendY, this,
            &TreadForLoop::setY);
}

void TreadForLoop::setX(int X)
{
    this->dX = X;
}

void TreadForLoop::setY(int Y)
{
    this->dY = Y;
}

void TreadForLoop::run()
{
    while(true)
    {
        emit sendData(this->dX,this->dY);
        msleep(10);
    }
}
