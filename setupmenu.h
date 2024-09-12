#ifndef SETUPMENU_H
#define SETUPMENU_H

#include <QWidget>

namespace Ui {
class SetupMenu;
}

class SetupMenu : public QWidget
{
    Q_OBJECT

public:
    explicit SetupMenu(QWidget *parent = nullptr);
    ~SetupMenu();

private slots:
    void on_pushButton_clicked();

private:
    Ui::SetupMenu *ui;
};

#endif // SETUPMENU_H
