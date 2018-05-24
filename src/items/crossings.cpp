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
    //         |  |
    // -------   ------
    // -------   ------
    //         |  |
    //         |  |
    for (auto iter : centers_) {
        // set pen
        QPen pen(Qt::white, 3);
        painter->setPen(pen);
        // up-left corner
        painter->drawLine(iter + QPoint(-7, -7), iter + QPoint(-7, -100));
        painter->drawLine(iter + QPoint(-7, -7), iter + QPoint(-100, -7));
        // up-right corner
        painter->drawLine(iter + QPoint(7, -7), iter + QPoint(7, -100));
        painter->drawLine(iter + QPoint(7, -7), iter + QPoint(100, -7));
        // down-left corner
        painter->drawLine(iter + QPoint(-7, 7), iter + QPoint(-7, 100));
        painter->drawLine(iter + QPoint(-7, 7), iter + QPoint(-100, 7));
        // down-right corner
        painter->drawLine(iter + QPoint(7, 7), iter + QPoint(7, 100));
        painter->drawLine(iter + QPoint(7, 7), iter + QPoint(100, 7));
    }
}
