#include "car.hpp"
#include "signals.hpp"
#include <QGraphicsScene>
#include <QObject>
#include <QtCore>

class ItemManager : public QObject
{
    Q_OBJECT
  public:
    /**
     * @brief ItemManager constructor
     *
     * @param parent - parent of item manager
     * @param scene - scene for traffic map
     */
    ItemManager(QObject* parent, QGraphicsScene* scene);
    ~ItemManager();
    void init();

  private:
    QGraphicsScene* scene_;

    Signals* signals_;
    // for changing signals' color
    int counter_;

    QVector<Car*> cars_;
    // initial position of cars
    QVector<QPoint> init_pos_;
};
