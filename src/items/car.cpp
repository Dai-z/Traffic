#include "car.hpp"
#include <QPainter>
#include <iostream>

Car::Car(QGraphicsItem* parent)
  : QGraphicsItem(parent)
  , dire_decided_(false)
  , w_(8)
  , l_(10)
{
    this->setFlag(QGraphicsItem::ItemIsMovable, true);
    speed_ = qrand() % 21;
    speed_ /= 10;
    speed_ += 1;
    std::cout << "speed: " << speed_ << std::endl;
}

Car::~Car()
{
}

QRectF
Car::boundingRect() const
{
    return QRectF(-w_ / 2, -l_ / 2, w_, l_);
}

void
Car::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
    QBrush brush(Qt::cyan);
    painter->setBrush(brush);
    int line_w = 1;
    painter->setPen(QPen(Qt::black, line_w));
    // the width of pen
    painter->drawRect(-w_ / 2 + line_w, -l_ / 2 + line_w, w_ - 2 * line_w, l_ - 2 * line_w);
}