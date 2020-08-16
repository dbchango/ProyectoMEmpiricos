#ifndef MENU_H
#define MENU_H
#include <QObject>


class Menu
{
private:
    int idMenu;
    QString nombreMenu;
public:
    Menu();
    Menu(int, QString);
};

#endif // MENU_H
