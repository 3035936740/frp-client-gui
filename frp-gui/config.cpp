#include "config.h"
#include "ui_config.h"

config::config(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::config){
    ui->setupUi(this);

    QHash<QString, QString> iniKeyDict {
        {"common/server_addr", nullptr},
        {"common/server_port", nullptr},
        {"main/local_ip", nullptr},
        {"main/local_port", nullptr},
        {"main/remote_port", nullptr},
        {"main/type", nullptr}
    };

    foreach (QString key, setting.allKeys()){

        if(iniKeyDict.contains(key)){
            iniKeyDict.insert(key, setting.value(key).toString());
        }
    };

    ui->localIP->setText(iniKeyDict.value("main/local_ip"));
    ui->serverAddress->setText(iniKeyDict.value("common/server_addr"));
    ui->networkProtocol->setEditText(iniKeyDict.value("main/type"));
    ui->localPort->setValue(iniKeyDict.value("main/local_port").toInt());
    ui->remotePort->setValue(iniKeyDict.value("main/remote_port").toInt());
    ui->serverPort->setValue(iniKeyDict.value("common/server_port").toInt());

    QObject::connect(ui->saveButton, &QPushButton::clicked, this, &config::saveIniFile);
}

void config::saveIniFile(void){
    QString formattedIni(
                iniArgs.arg(ui->serverAddress->text()).arg(ui->serverPort->value())
                .arg(ui->networkProtocol->currentText()).arg(ui->localIP->text())
                .arg(ui->localPort->value()).arg(ui->remotePort->value())
                );

    QFile file(self::global::frpPath[0] + self::global::frpPath[1]);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream stream(&file);
        stream << formattedIni;
        file.close();
        QMessageBox::information(nullptr, "成功", "配置修改成功");
    } else {
        QMessageBox::information(nullptr, "失败", "配置修改失败");
    }
};

config::~config()
{
    delete ui;
}
