#ifndef SELF_LABEL_HPP
#define SELF_LABEL_HPP

#include <QLabel>
#include <QMouseEvent>

class ClickableLabel : public QLabel
{
    Q_OBJECT

public:
    explicit ClickableLabel(QWidget *parent = nullptr)
        : QLabel(parent)
    {
        setMouseTracking(true);
    }

signals:
    void clicked();

protected:
    void mousePressEvent(QMouseEvent *event) override
    {
        if (event->button() == Qt::LeftButton)
        {
            emit clicked();
        }
    }
};

#endif // SELF_LABEL_HPP
