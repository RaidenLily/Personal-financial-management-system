#ifndef BANKCARD_H
#define BANKCARD_H

#include <QMainWindow>

namespace Ui {
class BankCard;
}

class BankCard : public QMainWindow
{
    Q_OBJECT

public:
    explicit BankCard(QWidget *parent = nullptr);
    ~BankCard();

private:
    Ui::BankCard *ui;
};

#endif // BANKCARD_H
