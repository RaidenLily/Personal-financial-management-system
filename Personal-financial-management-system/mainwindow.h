 #ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <string>
#include <cardmessage.h>
#include <usermessage.h>
#include <map>
#include <QMessageBox>
#include <trainmessage.h>
#include <QValidator>
#include <QDateTime>

/*
 * 主体窗口
 */

using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_addButton_clicked();

    void on_quitButton_clicked();

    void on_searchButton_clicked();

    void getUser(UserMessage *);

    void on_confirmButton_clicked();

    void on_resetButton_clicked();

    void on_modifyButton_clicked();

    void on_manageButton_clicked();

private:
    Ui::MainWindow *ui;
    UserMessage *uesr;
    map<string , CardMessage> MAP;
    void enterTrainModel();
    map<string , CardMessage>::iterator l_it;

signals:
    void  sendData(pair <string,CardMessage>);
};

#endif // MAINWINDOW_H
