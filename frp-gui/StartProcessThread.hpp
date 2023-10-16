#ifndef STARTPROCESSTHREAD_HPP
#define STARTPROCESSTHREAD_HPP

#include <QThread>
#include <QProcess>
#include <QDebug>
#include "global.hpp"

namespace self{
    // 继承自QThread的自定义线程类
    class StartProcessThread : public QThread
    {
    public:
        void run() override
        {
            QProcess process;
            process.start(self::global::frpPath[0]+self::global::frpPath[2] + " -c " + self::global::frpPath[0] + self::global::frpPath[1]);  // 启动ls命令，并使用“-l”参数
            self::global::isProcessStart = true;
            self::global::processPID = process.processId();  // 获取进程的PID

            process.waitForStarted();  // 等待进程启动

            process.waitForFinished(); // 等待进程完成

            QString output = process.readAllStandardOutput();  // 读取标准输出
            qDebug() << output;
        }
    };
}

#endif // STARTPROCESSTHREAD_HPP
