#include "item_manager.hpp"
#include "crossings.hpp"
#include <QTimer>
#include <iostream>

ItemManager::ItemManager(QObject* parent, QGraphicsScene* scene)
  : QObject(parent)
  , scene_(scene)
  , counter_(0)
{
    // add seed for random num generator
    qsrand(QTime(0, 0, 0).secsTo(QTime::currentTime()));
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
    for (int i = 0; i < 5; i++) {
        auto car = new Car();
        int w = car->getWidth(), l = car->getLength();

        QPoint pos = init_pos_[qrand() % 12];
        if (pos.x() == 300) {
            pos += QPoint(-l / 2, -w / 2);
            car->setTransform(QTransform().rotate(90));
            car->setDirection(QPoint(-1, 0));
        }
        if (pos.x() == -300) {
            pos += QPoint(l / 2, w / 2);
            car->setTransform(QTransform().rotate(-90));
            car->setDirection(QPoint(1, 0));
        }
        if (pos.y() == 300) {
            pos += QPoint(w / 2, -l / 2);
            car->setDirection(QPoint(0, -1));
        }
        if (pos.y() == -300) {
            pos += QPoint(-w / 2, l / 2);
            car->setDirection(QPoint(0, 1));
        }
        car->setPos(pos);
        if (!scene_->collidingItems(car).isEmpty()) {
            delete car;
            continue;
        }
        cars_.push_back(car);
        scene_->addItem(car);
    }
    // timer for moving car
    auto c_timer = new QTimer(this);
    connect(c_timer, &QTimer::timeout, [=]() {
        for (auto iter : cars_) {
            QPointF head_pos = iter->pos();
            if (iter->getDirection().x() == 0)
                head_pos += QPointF(0, iter->getLength() / 2 * iter->getDirection().y());
            else
                head_pos += QPointF(iter->getWidth() / 2 * iter->getDirection().x(), 0);

            if (!signals_->canPass(head_pos, iter->getDirection()))
                continue;
            iter->setPos(iter->pos() + iter->getDirection());
            if (!scene_->collidingItems(iter).isEmpty())
                iter->setPos(iter->pos() - iter->getDirection());
        }
    });
    c_timer->start(1000 / 20.0);
}
