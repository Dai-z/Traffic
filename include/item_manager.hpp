#include "signals.hpp"
#include <QGraphicsScene>
#include <QObject>

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
    int counter_;
};
