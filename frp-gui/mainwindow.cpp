#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    cl = new ClickableLabel(this);

    cl->setGeometry(QRect(202, 142, 32, 32));
    cl->setPixmap(QPixmap(QString::fromUtf8(":/ui/resources/config.png")));
    cl->setScaledContents(true);
    cl->show();


    conf = new config();

    QObject::connect(cl, &ClickableLabel::clicked, this, &MainWindow::toggingWindow);
    QObject::connect(ui->startButton, &QPushButton::clicked, this, &MainWindow::startFrp);
};

void MainWindow::closeEvent(QCloseEvent *event)
{
    QMessageBox::StandardButton reply = QMessageBox::question(this, "确认", "您确定要关闭窗口吗？", QMessageBox::Yes|QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        // 执行一些清理操作
        // 清理管道程序
        if(self::global::isProcessStart){
            // 根据操作系统选择相应的命令和参数
            QString command;
            QStringList arguments;
            command = "taskkill";
            arguments << "/F" << "/PID" << QString::number(self::global::processPID);

            QProcess process;
            process.start(command, arguments);
            process.waitForFinished();
        }

        delete cl;
        delete conf;
        event->accept();
    } else {
        event->ignore();
    }
}

void MainWindow::startFrp(){
    ui->startButton->setEnabled(false);

    if(togglingStartButtonText){
        // 关闭
        self::global::isProcessStart = false;
        QString command;
        QStringList arguments;
        command = "taskkill";
        arguments << "/F" << "/PID" << QString::number(self::global::processPID);

        QProcess process;
        process.start(command, arguments);
        process.waitForFinished();
        ui->startButton->setText("启动frp");
    }else{
        // 启动
        // 创建自定义线程对象
        std::thread thread([](){
            QProcess process;
            process.start(self::global::frpPath[0]+self::global::frpPath[2] + " -c " + self::global::frpPath[0] + self::global::frpPath[1]);  // 启动ls命令，并使用“-l”参数
            self::global::isProcessStart = true;
            self::global::processPID = process.processId();  // 获取进程的PID

            process.waitForStarted();  // 等待进程启动

            process.waitForFinished(); // 等待进程完成

            // QString output = process.readAllStandardOutput();  // 读取标准输出
            // qDebug() << output;
        });

        thread.detach();
        ui->startButton->setText("关闭frp");
    }


    this->togglingStartButtonText = !this->togglingStartButtonText;
    ui->startButton->setEnabled(true);
};

MainWindow::~MainWindow()
{
    delete cl;
    delete conf;
    delete ui;
};
