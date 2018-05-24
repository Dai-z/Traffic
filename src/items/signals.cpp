#include "signals.hpp"
#include <QPainter>
#include <QTimer>
#include <iostream>
#include <math.h>

Signals::Signals(QGraphicsItem* parent)
  : QGraphicsItem(parent)
{
    for (int i = 0; i < 9; i++) {
        color_.push_back(Qt::red);
        color_.push_back(Qt::green);
    }
    time_[0] = 6;
    time_[1] = 5;
    time_[2] = 1;
    centers_.push_back(QPoint(-200, -200));
    centers_.push_back(QPoint(0, -200));
    centers_.push_back(QPoint(200, -200));
    centers_.push_back(QPoint(-200, 0));
    centers_.push_back(QPoint(0, 0));
    centers_.push_back(QPoint(200, 0));
    centers_.push_back(QPoint(-200, 200));
    centers_.push_back(QPoint(0, 200));
    centers_.push_back(QPoint(200, 200));

    this->setFlag(QGraphicsItem::ItemIsMovable, false);
    this->setVisible(true);
}

Signals::~Signals()
{
}

QRectF
Signals::boundingRect() const
{
    return QRectF(0, 0, 0, 0);
}

void
Signals::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
    for (int i = 0; i < 9; i++) {
        QPoint c = centers_[i];
        // draw black shell of light
        QBrush brush(Qt::black);
        painter->setBrush(brush);
        painter->drawRect(c.x() - 45, c.y() - 25, 30, 10);
        painter->drawRect(c.x() + 15, c.y() + 15, 10, 30);
        // draw arrows to resent the direction of signal lights
        painter->setPen(QPen(Qt::white, 1));
        painter->drawLine(c.x() - 40, c.y() - 23, c.x() - 40, c.y() - 17);
        painter->drawLine(c.x() - 40, c.y() - 23, c.x() - 43, c.y() - 20);
        painter->drawLine(c.x() - 40, c.y() - 23, c.x() - 37, c.y() - 20);
        painter->drawLine(c.x() - 30, c.y() - 23, c.x() - 30, c.y() - 17);
        painter->drawLine(c.x() - 30, c.y() - 17, c.x() - 33, c.y() - 20);
        painter->drawLine(c.x() - 30, c.y() - 17, c.x() - 27, c.y() - 20);
        painter->drawLine(c.x() + 17, c.y() + 30, c.x() + 23, c.y() + 30);
        painter->drawLine(c.x() + 17, c.y() + 30, c.x() + 20, c.y() + 27);
        painter->drawLine(c.x() + 17, c.y() + 30, c.x() + 20, c.y() + 33);
        painter->drawLine(c.x() + 17, c.y() + 40, c.x() + 23, c.y() + 40);
        painter->drawLine(c.x() + 23, c.y() + 40, c.x() + 20, c.y() + 37);
        painter->drawLine(c.x() + 23, c.y() + 40, c.x() + 20, c.y() + 43);
        painter->setPen(QPen());
        // draw light
        brush.setColor(color_[i << 1]);
        painter->setBrush(brush);
        painter->drawEllipse(c.x() - 25, c.y() - 25, 10, 10);
        brush.setColor(color_[(i << 1) + 1]);
        painter->setBrush(brush);
        painter->drawEllipse(c.x() + 15, c.y() + 15, 10, 10);
    }
}

QColor
Signals::getColor(const QPoint pos)
{
    int id = 0;
    if (abs(pos.y() + 300) < 20)
        id += 0;
    else if (abs(pos.y()) < 20)
        id += 3;
    else if (abs(pos.y() + 300) < 20)
        id += 6;

    if (abs(pos.x()) < 20)
        id += 1;
    else if (abs(pos.x() + 300) < 20)
        id += 2;
    if (abs(pos.x() - centers_[id].x()) > 10)
        return color_[id * 2 + 1];
    else
        return color_[id * 2];
}

void
Signals::changeColor(bool toYellow)
{
    for (int i = 0; i < 9; i++) {
        if (!toYellow) {
            if (color_[i * 2] == Qt::yellow) {
                color_[i * 2] = Qt::red;
                color_[i * 2 + 1] = Qt::green;
            } else if (color_[i * 2 + 1] == Qt::yellow) {
                color_[i * 2] = Qt::green;
                color_[i * 2 + 1] = Qt::red;
            }
        } else if (color_[i * 2] == Qt::green) {
            color_[i * 2] = Qt::yellow;
        } else {
            color_[i * 2 + 1] = Qt::yellow;
        }
    }
}
