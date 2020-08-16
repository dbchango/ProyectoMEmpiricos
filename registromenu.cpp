#include "registromenu.h"
#include "ui_registromenu.h"

RegistroMenu::RegistroMenu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RegistroMenu)
{
    ui->setupUi(this);
}

RegistroMenu::~RegistroMenu()
{
    delete ui;
}
