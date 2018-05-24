#pragma once
#include <QGraphicsItem>
#include <QtCore>

class Crossings : public QGraphicsItem
{
  public:
    Crossings(QGraphicsItem* parent = 0);
    ~Crossings();

    QRectF boundingRect() const;
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget);

  private:
    QVector<QPoint> centers_;
};