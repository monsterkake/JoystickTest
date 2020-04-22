#include "Widget.h"
#include "ui_Widget.h"
#include "DuJoystickManager.h"
#include "ThreadForLoop.h"
#include <QThread>

#define MAX_AXIS_VALUE 32768

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    mJoyManager = new DuJoystickManager(this);
    mJoyManager->start();
    connect(mJoyManager, &DuJoystickManager::SDL_joyButtonDown, this,
            &Widget::manageJoystickButton);
    connect(mJoyManager, &DuJoystickManager::getConfiguration, this,
            &Widget::displayConfiguration);

    treadForLoop = new TreadForLoop(this, mJoyManager);
    treadForLoop->start();

    connect(treadForLoop, &TreadForLoop::sendData, this,
            &Widget::moveEntity);
}

Widget::~Widget()
{
    mJoyManager->terminate();
    treadForLoop->terminate();
    delete mJoyManager;
    delete treadForLoop;
    delete ui;
}

void Widget::manageJoystickButton(int button)
{
    ui->textEdit->append("buttonDown: " + QString::number(button));
}

void Widget::moveEntity(int dX, int dY)
{
    ui->label->setText("AxisMovement: dX:" + QString::number(dX));
    ui->label_2->setText("AxisMovement: dY:" + QString::number(dY));
    ui->pushButton->move(ui->pushButton->pos().x() + dX, ui->pushButton->pos().y() + dY);
    ui->pushButton->setText("X:" + QString::number(ui->pushButton->pos().x()) + "\nY:" + QString::number(ui->pushButton->pos().y()) );
}

void Widget::displayConfiguration(int axes, int buttons, int balls, int hats)
{
    ui->textEdit->append("Joystick has " + QString::number(axes) + " axes." );
    ui->textEdit->append("Joystick has " + QString::number(buttons) + " buttons." );
    ui->textEdit->append("Joystick has " + QString::number(balls) + " balls." );
    ui->textEdit->append("Joystick has " + QString::number(hats) + " hats." );
}

void Widget::on_pushButton_clicked()
{

}
