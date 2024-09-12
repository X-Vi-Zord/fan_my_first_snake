#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Game.h"
/*#include "setupmenu.h"*/

mainWindow::mainWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::mainWindow)
{
    ui->setupUi(this);
}

mainWindow::~mainWindow()
{
    delete ui;
}

void mainWindow::on_pushButton_clicked()
{
    Game *Snake = new Game();
    Snake->show();
}


/*void mainWindow::on_pushButton_2_clicked()
{
    SetupMenu *Setup = new SetupMenu();
    Setup->show();

}*/

void mainWindow::on_pushButton_3_clicked()
{
    this->close();
}

