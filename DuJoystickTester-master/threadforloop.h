#ifndef THREADFORLOOP_H
#define THREADFORLOOP_H

#include <QThread>

class DuJoystickManager;

class TreadForLoop : public QThread
{
    Q_OBJECT
public:
    TreadForLoop(QObject *parent = nullptr , DuJoystickManager* pointer = nullptr);
signals:
    void sendData(int,int);
protected:
    void run() override;
private:
    int dX = 0;
    int dY = 0;

    void setX(int);
    void setY(int);
};

#endif // THREADFORLOOP_H
