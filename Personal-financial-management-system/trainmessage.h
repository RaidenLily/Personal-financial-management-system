#ifndef TRAINMESSAGE_H
#define TRAINMESSAGE_H

#include <QMainWindow>
#include <string>
#include <QString>
#include <cardmessage.h>
#include <QMessageBox>

/*
 * 历史交易界面
 */

using namespace std;

namespace Ui {
class TrainMessage;
}

class TrainMessage : public QMainWindow
{
    Q_OBJECT

public:
    explicit TrainMessage(QWidget *parent = nullptr);
    ~TrainMessage();

private slots:
    void on_pushButton_5_clicked();

    void getId(pair <string,CardMessage>);

    void on_previous_clicked();

    void on_next_clicked();

    void on_last_clicked();

    void on_firstButton_clicked();

private:
    Ui::TrainMessage *ui;
    vector<Histroy> a;
    vector<Histroy>::iterator it;
    void setText();
};

#endif // TRAINMESSAGE_H
