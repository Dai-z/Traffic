#include "car.hpp"
#include <QPainter>

Car::Car(QGraphicsItem* parent)
  : QGraphicsItem(parent)
  , dire_decided_(false)
  , w_(8)
  , h_(8)
{
    this->setFlag(QGraphicsItem::ItemIsMovable, true);
}

Car::~Car()
{
}

QRectF
Car::boundingRect() const
{
    return QRectF(-w_ / 2, -h_ / 2, w_, h_);
}

void
Car::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
    QBrush brush(Qt::cyan);
    painter->setBrush(brush);
    painter->setPen(QPen(Qt::black, 1));
    painter->drawRect(-w_ / 2, -h_ / 2, w_, h_);
}