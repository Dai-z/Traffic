#pragma once
#include <QGraphicsScene>

class Render : public QGraphicsScene
{
    Q_OBJECT
  public:
    Render(QObject* parent = 0);
    ~Render();
};