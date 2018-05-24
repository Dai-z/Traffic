#include "render.hpp"
#include <QGraphicsItem>

Render::Render(QObject* parent)
  : QGraphicsScene(parent)
{
    this->setBackgroundBrush(QColor(110, 110, 110));

    int w = 600;
    int h = 600;
    this->setSceneRect(-w / 2, -h / 2, w, h);
}

Render::~Render()
{
}