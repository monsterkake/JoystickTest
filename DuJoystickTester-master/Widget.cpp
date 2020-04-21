#include "Widget.h"
#include "ui_Widget.h"
#include "DuJoystickManager.h"
#include <QMessageBox>
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
    connect(mJoyManager, &DuJoystickManager::SDL_joyAxisMotion, this,
            &Widget::manageJoystickAxis);
    connect(mJoyManager, &DuJoystickManager::getConfiguration, this,
            &Widget::displayConfiguration);

    treadForLoop = new TreadForLoop(this);
    treadForLoop->ptr = mJoyManager;
    treadForLoop->start();
    connect(treadForLoop, &TreadForLoop::sendData, this,
            &Widget::moveEntity);
}

Widget::~Widget()
{
    mJoyManager->terminate();
    treadForLoop->terminate();
    delete ui;
}

void Widget::manageJoystickButton(int button)
{
    ui->textEdit->append("buttonDown: " + QString::number(button));
}

void Widget::manageJoystickAxis(int axisValue, int axis)
{
//    ui->label->setText("value = " + QString::number(axisValue));
//    ui->label_2->setText("axis = " + QString::number(axis));
//    if(axis == AXIS_VERTICAL){
//        ui->pushButton->move(ui->pushButton->pos().x(), ui->pushButton->pos().y() + 4*axisValue/MAX_AXIS_VALUE);
//    }
//    if(axis == AXIS_HORIZONTAL){
//        ui->pushButton->move(ui->pushButton->pos().x() + 4*axisValue/MAX_AXIS_VALUE, ui->pushButton->pos().y());
//    }
}

void Widget::moveEntity(int X, int Y)
{
    ui->pushButton->move(ui->pushButton->pos().x() + X, ui->pushButton->pos().y() + Y);
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
