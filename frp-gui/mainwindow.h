#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <thread>
#include <QMainWindow>
#include <QLabel>
#include <QPushButton>
#include <QDebug>
#include <QSharedPointer>
#include <QPixmap>
#include <QProcess>
#include <QMessageBox>
#include "global.hpp"
#include "config.h"
#include "self_label.hpp"
#include "StartProcessThread.hpp"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void closeEvent(QCloseEvent *event);

private:
    ClickableLabel* cl;
    config* conf;
    // false是关闭,true是启动
    bool togglingStartButtonText {false};

private slots:
    void toggingWindow(void){
        conf->show();
    };
    void startFrp(void);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
