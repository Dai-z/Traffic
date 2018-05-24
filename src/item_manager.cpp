#include "item_manager.hpp"
#include "crossings.hpp"
#include <QTimer>
#include <iostream>

ItemManager::ItemManager(QObject* parent, QGraphicsScene* scene)
  : QObject(parent)
  , scene_(scene)
  , counter_(0)
{
}

ItemManager::~ItemManager()
{
}

void
ItemManager::init()
{
    scene_->addItem(new Crossings());
    signals_ = new Signals();
    scene_->addItem(signals_);

    auto s_timer = new QTimer(this);
    connect(s_timer, &QTimer::timeout, [=]() {
        counter_++;
        if (counter_ == signals_->getTime(0)) {
            counter_ = 0;
            signals_->changeColor(false);
        } else if (counter_ == signals_->getTime(1))
            signals_->changeColor(true);
    });
    s_timer->start(1000);
}
