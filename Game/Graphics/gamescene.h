#ifndef GAMESCENE_H
#define GAMESCENE_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QDebug>

#include <map>
#include <memory>

#include "core/gameobject.h"

namespace Student {

const std::pair<int, int> SCENE_WIDTH_LIMITS = {1, 100};
const std::pair<int, int> SCENE_HEIGHT_LIMITS = {1, 100};
const std::pair<int, int> SCENE_SCALE_LIMITS = {1, 500};

class GameScene : public QGraphicsScene
{
    Q_OBJECT

public:
    GameScene(QWidget* parent = nullptr,

              int width = 30,
              int height = 15,
              int scale = 50);

    ~GameScene() = default;

    void setSize(int width, int height);

    void setScale(int scale);

    void resize();

    int getScale() const;

    std::pair<int,int> getSize() const;

    void drawItem( std::shared_ptr<Course::GameObject> obj);

    void removeItem( std::shared_ptr<Course::GameObject> obj);

    void updateItem( std::shared_ptr<Course::GameObject> obj);

    virtual bool event(QEvent* event) override;

private:

    QGraphicsItem* m_mapBoundRect;
    int m_width;
    int m_height;
    int m_scale;
};

} // Namespace

#endif // GAMESCENE_H
