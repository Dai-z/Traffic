#include "mainwindow.hpp"
#include "item_manager.hpp"
#include "render.hpp"
#include <QDockWidget>
#include <QGraphicsView>
#include <QTimer>

MainWindow::MainWindow(QWidget* parent)
  : QMainWindow(parent)
{
    QDockWidget* control_panel = new QDockWidget("control");
    this->addDockWidget(Qt::LeftDockWidgetArea, control_panel);

    auto render = new Render(this);
    auto item_manager = new ItemManager(this, render);
    item_manager->init();

    auto view = new QGraphicsView(this);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setScene(render);

    setCentralWidget(view);

    // Time for updating view
    auto timer = new QTimer(this);
    connect(timer, &QTimer::timeout, [=]() {
        view->update();
        view->scene()->update();
    });
    timer->start(1000 / 20.0);
}

MainWindow::~MainWindow()
{
}
