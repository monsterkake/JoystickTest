#include "Widget.h"
#include "ui_Widget.h"
#include "DuJoystickManager.h"
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    mJoyManager = new DuJoystickManager(this);

    for (int i = 0; i < 5; ++i) {
        ui->listWidget->addItem(QString::number(i));
    }
    ui->listWidget->setCurrentRow(0);
    mJoyManager->start();

    connect(mJoyManager, &DuJoystickManager::SDL_joyButtonDown, this,
            &Widget::manageJoystick);
}

Widget::~Widget()
{
    delete ui;
}
//ui->listWidget->currentItem()->text()
void Widget::manageJoystick(int button)
{
    int currentRow = ui->listWidget->currentRow();
    const int rowCount = ui->listWidget->count();

    switch (button) {
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
    case UP: {
//        if (currentRow == 0) {
//            break;
//        }
//        else
//        {
//            currentRow--;
//        }
//        ui->listWidget->setCurrentRow(currentRow);
//        break;
        QMessageBox::information(this, "OK"," up ");

        break;
    }
    case DOWN: {
//        if (currentRow == rowCount - 1)
//        {
//            break;
//        }
//        else
//        {
//            currentRow++;
//        }
//        ui->listWidget->setCurrentRow(currentRow);
//        break;
        QMessageBox::information(this, "OK"," down ");

        break;

    }
    case LEFT:{
        QMessageBox::information(this, "OK"," left ");

        break;
    }
    case RIGHT:{
        QMessageBox::information(this, "OK"," right ");

        break;
    }
    }
}
