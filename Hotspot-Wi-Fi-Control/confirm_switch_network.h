#ifndef CONFIRM_SWITCH_NETWORK_H
#define CONFIRM_SWITCH_NETWORK_H

#include <QDialog>

namespace Ui {
class confirm_switch_network;
}

class confirm_switch_network : public QDialog
{
    Q_OBJECT

public:
    explicit confirm_switch_network(QWidget *parent = 0, int current_value = 0);
    ~confirm_switch_network();

private:
    Ui::confirm_switch_network *ui;
};

#endif // CONFIRM_SWITCH_NETWORK_H
