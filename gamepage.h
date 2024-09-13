#ifndef GAMEPAGE_H
#define GAMEPAGE_H
#include <QWidget>
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QStackedWidget>
#include <vector>
#include "pacman.h"
#include "ghost.h"
#include "collectable.h"
#define MAP_WIDTH 30
#define MAP_HEIGHT 20
#define NO_OF_GHOSTS 4

using std::vector;

QT_BEGIN_NAMESPACE
namespace Ui { class GamePage; }
QT_END_NAMESPACE

class GamePage : public QWidget
{
    Q_OBJECT
private:
    QStackedWidget* layout_ref;
    Ui::GamePage *ui;
    QGraphicsScene *scene;
    QTimer * player_timer;

    uint score;
    int current_level;
    int mapGrid[MAP_HEIGHT][MAP_WIDTH];
    Pacman *pacman;
    Ghost *ghosts[NO_OF_GHOSTS];

    std::vector<Collectable*> collectables;

    void drawMapGrid();
    void loadLevel(int lvl_number);
    void initializeGrid(const QJsonArray &jsonArr);
private slots:
    void collectCollectables();
    void updateScore();
protected:
    void keyPressEvent(QKeyEvent *event) override;
public:
    GamePage(QWidget *parent = nullptr, QStackedWidget* ref = nullptr);
    ~GamePage();
};

#endif // GAMEPAGE_H
