#pragma once

#include <QWidget>
#include <QPoint>
#include <QVector>
#include <QKeyEvent>
#include <QPaintEvent>

#include <QWidget>

class Game : public QWidget
{
    Q_OBJECT

public:
    Game();

protected:
    void timerEvent(QTimerEvent *) override;
    void keyPressEvent(QKeyEvent *) override;
    void paintEvent(QPaintEvent *) override;

private :

    //  field
    static const int SIZE_plate = 20;
    static const int SIZE_field = 20;

    int DELAY = 150;
    int m_TimerId;


    // in game flag
    bool m_inGame;


    // SnakeBody
    QVector<QPoint> m_Snake_body;

    // Apple
    QPoint m_Apple;


    // Direction
    enum Directions {
        Left, Right, Up, Down
    };

    // Direction status
    Directions m_dir;

    void initGame();

    void doDrawing();

    void Local_Apple();

    void Move();

    void Check_field();

    void gameOver();

    void Check_apple();
};

