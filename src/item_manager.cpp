#include "item_manager.hpp"
#include "crossings.hpp"
#include <QTimer>
#include <iostream>

ItemManager::ItemManager(QObject* parent, QGraphicsScene* scene)
  : QObject(parent)
  , scene_(scene)
  , counter_(0)
{
    init_pos_.push_back(QPoint(-200, -300));
    init_pos_.push_back(QPoint(0, -300));
    init_pos_.push_back(QPoint(200, -300));
    init_pos_.push_back(QPoint(-200, 300));
    init_pos_.push_back(QPoint(0, -300));
    init_pos_.push_back(QPoint(200, -300));
    init_pos_.push_back(QPoint(-300, -200));
    init_pos_.push_back(QPoint(-300, 0));
    init_pos_.push_back(QPoint(-300, 200));
    init_pos_.push_back(QPoint(300, -200));
    init_pos_.push_back(QPoint(300, 0));
    init_pos_.push_back(QPoint(300, 200));
}

ItemManager::~ItemManager()
{
}

void
ItemManager::init()
{
    // add seed for random num generator
    qsrand(QTime(0, 0, 0).secsTo(QTime::currentTime()));
    // add map
    scene_->addItem(new Crossings());
    // add signals
    signals_ = new Signals();
    scene_->addItem(signals_);

    // timer to change signal lights' color
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
    // add cars
    auto car = new Car();
    cars_.push_back(car);
    int w = car->getWidth(), l = car->getLength();

    QPoint pos = init_pos_[qrand() % 12];
    if (pos.x() == 300) {
        pos += QPoint(-l / 2, -w / 2);
        car->setTransform(QTransform().rotate(90));
    }
    if (pos.x() == -300) {
        pos += QPoint(l / 2, w / 2);
        car->setTransform(QTransform().rotate(-90));
    }
    if (pos.y() == 300)
        pos += QPoint(w / 2, -l / 2);
    if (pos.y() == -300)
        pos += QPoint(-w / 2, l / 2);
    car->setPos(pos);
    scene_->addItem(car);
}
