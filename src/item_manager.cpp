#include "item_manager.hpp"
#include "crossings.hpp"

ItemManager::ItemManager(QObject* parent, QGraphicsScene* scene)
  : QObject(parent)
  , scene_(scene)
{
}

ItemManager::~ItemManager()
{
}

void
ItemManager::init()
{
    scene_->addItem(new Crossings());
}
