#ifndef CONFIG_H
#define CONFIG_H

#include <QWidget>
#include <QPushButton>
#include <QSettings>
#include <QDebug>
#include <QHash>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include "global.hpp"

namespace Ui {
class config;
}

class config : public QWidget
{
    Q_OBJECT

public:
    explicit config(QWidget *parent = nullptr);
    ~config();

private:QSettings setting = QSettings(self::global::frpPath[0] + self::global::frpPath[1], QSettings::IniFormat);
    const QString iniArgs = R"([common]
server_addr = %1
server_port = %2

[main]
type = %3
local_ip = %4
local_port = %5
remote_port = %6)";

private slots:
    void saveIniFile(void);

private:
    Ui::config *ui;
};

#endif // CONFIG_H
