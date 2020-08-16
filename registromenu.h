#ifndef REGISTROMENU_H
#define REGISTROMENU_H

#include <QWidget>

namespace Ui {
class RegistroMenu;
}

class RegistroMenu : public QWidget
{
    Q_OBJECT

public:
    explicit RegistroMenu(QWidget *parent = nullptr);
    ~RegistroMenu();

private:
    Ui::RegistroMenu *ui;
};

#endif // REGISTROMENU_H
