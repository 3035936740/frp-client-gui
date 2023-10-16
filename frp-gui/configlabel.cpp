#include "configlabel.h"

MyLabel::MyLabel(QWidget *parent):QLabel(parent)
{

}

void MyLabel::enterEvent(QEvent *event)
{
    setStyleSheet("border:6px solid;"
                  "border-color:rgb(255,0,0);"
                  "background-color: rgb(0, 0, 255);");
}

void MyLabel::leaveEvent(QEvent *event)
{
    setStyleSheet("border:0px");
    setText(" ");
    setAlignment(Qt::AlignCenter);
}

void MyLabel::mousePressEvent(QMouseEvent *event)
{
    setStyleSheet("border:2px solid;"
                  "background-color: rgb(255, 0, 0);");
    QFont font ( "Microsoft YaHei", 30, 75);
    setFont(font);
    setText("被点击了");
    setAlignment(Qt::AlignCenter);

}
