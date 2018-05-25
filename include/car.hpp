#pragma once
#include <QGraphicsItem>

class Car : public QGraphicsItem
{
  public:
    Car(QGraphicsItem* parent = 0);
    ~Car();

    QRectF boundingRect() const;

    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget);
    inline int getWidth()
    {
        return w_;
    }
    inline int getLength()
    {
        return l_;
    }
    inline QPoint getDirection()
    {
        return direction_;
    }
    inline void setDirection(QPoint d)
    {
        direction_ = d;
    }
    float getSpeed();

  private:
    // width and length of car in graphics
    int w_, l_;
    // if the car has decided the direction to go at crossing
    bool dire_decided_;
    // speed of car(1.0-3.0)
    float speed_;
    //  counter for changing speed after some time
    int counter_;
    // unit vector
    QPoint direction_;
};