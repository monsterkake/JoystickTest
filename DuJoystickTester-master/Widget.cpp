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
            &Widget::manageJoystick);
}

Widget::~Widget()
{
    mJoyManager->terminate();
    delete ui;
}

void Widget::manageJoystick(int speed, int axis, int button)
{
    if(axis == AXIS_VERTICAL){
            ui->pushButton->move(ui->pushButton->pos().x(), ui->pushButton->pos().y() + 8*speed/MAX_AXIS_VALUE);
            ui->label->setText(QString::number(speed));
    }
    if(axis == AXIS_HORIZONTAL){
            ui->pushButton->move(ui->pushButton->pos().x() +8*speed/MAX_AXIS_VALUE, ui->pushButton->pos().y());
            ui->label->setText(QString::number(speed));
    }

    //if(axis == NOT_AXIS)
    if(false)
    switch(button){
    case BUTTON1: {
        QMessageBox::information(this, "OK"," Button1 ");
        break;
    }
    case BUTTON2:{
        QMessageBox::information(this, "OK"," Button2 ");
        break;
    }
    case BUTTON3:{
        QMessageBox::information(this, "OK"," Button3 ");
        break;
    }
    case BUTTON4:{
        QMessageBox::information(this, "OK"," Button4 ");
        break;
    }
    case BUTTON5:{
        QMessageBox::information(this, "OK"," Button5 ");
        break;
    }
    case BUTTON6:{
        QMessageBox::information(this, "OK"," Button6 ");
        break;
    }
    case BUTTON7:{
        QMessageBox::information(this, "OK"," Button7 ");
        break;
    }
    case BUTTON8:{
        QMessageBox::information(this, "OK"," Button8 ");
        break;
    }
    case BUTTON9:{
        QMessageBox::information(this, "OK"," Button9 ");
        break;
    }
    case BUTTON10:{
        QMessageBox::information(this, "OK"," Button10 ");
        break;
    }
    case BUTTON11:{
        QMessageBox::information(this, "OK"," Button11 ");
        break;
    }
    case BUTTON12:{
        QMessageBox::information(this, "OK"," Button12 ");
        break;
    }
    case BUTTON13:{
        QMessageBox::information(this, "OK"," Button13 ");
        break;
    }
    case BUTTON14:{
        QMessageBox::information(this, "OK"," Button14 ");
        break;
    }
    }
}

void Widget::on_pushButton_clicked()
{
    QMessageBox::information(this, "OK"," click ");
}
