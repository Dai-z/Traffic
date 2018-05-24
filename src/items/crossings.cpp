#include "crossings.hpp"
#include <QPainter>
#include <QWidget>

Crossings::Crossings(QGraphicsItem* parent)
  : QGraphicsItem(parent)
{
    this->setFlag(QGraphicsItem::ItemIsMovable, false);
    setVisible(true);
    centers_.push_back(QPoint(-200, -200));
    centers_.push_back(QPoint(0, -200));
    centers_.push_back(QPoint(200, -200));
    centers_.push_back(QPoint(-200, 0));
    centers_.push_back(QPoint(0, 0));
    centers_.push_back(QPoint(200, 0));
    centers_.push_back(QPoint(-200, 200));
    centers_.push_back(QPoint(0, 200));
    centers_.push_back(QPoint(200, 200));
}

Crossings::~Crossings()
{
}

QRectF
Crossings::boundingRect() const
{
    return QRectF(0, 0, 0, 0);
}

void
Crossings::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
    // a crossing is like

    //         |  |
    //  ooo |  |
    // -------   ------
    // -------   ------
    //         |  |8
    //         |  |o
    for (auto iter : centers_) {
        // set pen
        QPen pen(Qt::white, 3);
        painter->setPen(pen);
        // up-left corner
        painter->drawLine(iter + QPoint(-10, -10), iter + QPoint(-10, -100));
        painter->drawLine(iter + QPoint(-10, -10), iter + QPoint(-100, -10));
        // up-right corner
        painter->drawLine(iter + QPoint(10, -10), iter + QPoint(10, -100));
        painter->drawLine(iter + QPoint(10, -10), iter + QPoint(100, -10));
        // down-left corner
        painter->drawLine(iter + QPoint(-10, 10), iter + QPoint(-10, 100));
        painter->drawLine(iter + QPoint(-10, 10), iter + QPoint(-100, 10));
        // down-right corner
        painter->drawLine(iter + QPoint(10, 10), iter + QPoint(10, 100));
        painter->drawLine(iter + QPoint(10, 10), iter + QPoint(100, 10));
    }
}
