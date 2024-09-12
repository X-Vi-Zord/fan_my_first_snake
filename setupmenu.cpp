#include "setupmenu.h"
#include "ui_setupmenu.h"

SetupMenu::SetupMenu(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::SetupMenu)
{
    ui->setupUi(this);
}

SetupMenu::~SetupMenu()
{
    delete ui;
}

void SetupMenu::on_pushButton_clicked()
{
    this->close();
}

