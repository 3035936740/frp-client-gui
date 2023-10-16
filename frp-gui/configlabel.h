#ifndef CONFIGLABEL_H
#define CONFIGLABEL_H

#include <QObject>
#include <QDebug>
#include <QLabel>

class MyLabel:public QLabel
{
    Q_OBJECT
public:
    MyLabel(QWidget *parent = 0);
    void enterEvent(QEvent *event);
    void leaveEvent(QEvent *event);
    void mousePressEvent(QMouseEvent *event);
};

#endif // CONFIGLABEL_H
