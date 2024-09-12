#include "Game.h"
#include <QPainter>
#include <QRandomGenerator>
#include <QTime>
#include <QMessageBox>
#include <Qdebug>



// размер онкна и инициализация
Game::Game() {

    this->resize(SIZE_plate * SIZE_field, SIZE_plate * SIZE_field);
    initGame();
}


// Событие по времени (каждую задержку)

void Game::timerEvent(QTimerEvent *e)
{
    Q_UNUSED(e);
    if(m_inGame){
        Check_apple();
        Move();
        Check_field();

        this->repaint();
    }
    else {
        this->close();
    }
}



// Событие нажатие кнопок

void Game::keyPressEvent(QKeyEvent *event)
{
    int key = event->key();
    if(key == Qt::Key_Left  && m_dir!=Directions::Right)    {    m_dir = Left;};
    if(key == Qt::Key_Right && m_dir!=Directions::Left)     {    m_dir = Right;};
    if(key == Qt::Key_Up    && m_dir!=Directions::Down)     {    m_dir = Up;};
    if(key == Qt::Key_Down  && m_dir!=Directions::Up)       {    m_dir = Down;};


    if(key == Qt::Key_Escape)                               {m_inGame = false;;}
}


// событие перерисовка
void Game::paintEvent(QPaintEvent *)
{
    doDrawing();
}


// событие движение змеи и проверка на самопересечение

void Game::Move()
{

    for(int i = m_Snake_body.size()-1;i>0;--i){

        m_Snake_body[i] = m_Snake_body[i-1];
    };


    switch(m_dir) {
    case Left: {
        m_Snake_body[0].rx() -=1;break; }

    case Right: {
        m_Snake_body[0].rx() +=1;break;}

    case Up: {
        m_Snake_body[0].ry() -=1;break;}

    case Down: {
        m_Snake_body[0].ry() +=1;break;}
    }



    for(int i=1; i <m_Snake_body.size();i++)    {
        if( m_Snake_body[i]==m_Snake_body[0]) {
            m_inGame = false;
        };
    };
}





// проверка на выход за пределы поля
void Game::Check_field()
{

    if(m_Snake_body[0].x() >= SIZE_plate)   {m_inGame = false;};
    if(m_Snake_body[0].y() >= SIZE_plate)   {m_inGame = false;};
    if(m_Snake_body[0].x() < 0)             {m_inGame = false;};
    if(m_Snake_body[0].y() < 0)             {m_inGame = false;};

    if(!m_inGame)   {killTimer(m_TimerId);}

}
// событие на завершение игры
void Game::gameOver()
{
    QMessageBox msgb;
    msgb.setText("Game Over");
    msgb.exec();
    this->close();

}


// проверка на яблоко

void Game::Check_apple()
{
    if(m_Apple == m_Snake_body[0]){

        m_Snake_body.push_back(QPoint(0,0));
        Local_Apple();
    };
}


void Game::doDrawing()
{
    QPainter qp(this);

    if(m_inGame){

        qp.setBrush(Qt::red);
        qp.drawEllipse(m_Apple.x()*SIZE_field, m_Apple.y()*SIZE_field, SIZE_plate, SIZE_plate);

        for (const QPoint& p: m_Snake_body){

            qp.setBrush(Qt::green);
            qp.drawEllipse(p.x()*SIZE_field, p.y()*SIZE_field, SIZE_plate, SIZE_plate);
        }

        qp.setBrush(Qt::black);
        qp.drawEllipse(m_Snake_body[0].x()*SIZE_field, m_Snake_body[0].y()*SIZE_field, SIZE_plate, SIZE_plate);

    }
    else{
        gameOver();
    }

};

void Game::Local_Apple(){

    QTime time = QTime::currentTime();
    srand((uint) time.msec());
    while(m_Snake_body.contains(m_Apple)) {
        m_Apple.rx() = rand() % SIZE_field;
        m_Apple.ry() = rand() % SIZE_field;
    };
};


void Game::initGame(){


    m_inGame = true;

    m_Snake_body.resize(3);

    for (int i=0; i<m_Snake_body.size();i++){

        m_Snake_body[i].ry() = 0;
        m_Snake_body[i].rx() = m_Snake_body.size()-i;

        m_dir = Right;
    }


    Local_Apple();
    m_TimerId = startTimer(DELAY);

};




