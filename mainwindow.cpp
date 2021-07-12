#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <vector>
using std::vector;

#define MAZESIZE 500

#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //generateMaze();
    this -> map = new MazeMap();
    vector<vector<int> > vec = this -> map -> getMap();
    this -> mazeHeight = this -> map -> getHeight();
    this -> mazeWidth = this -> map -> getWidth();
    this -> girdSize = MAZESIZE / this -> mazeHeight;

    //qDebug() << girdSize;
//    for (vector<int> i : vec)
//    {
//        for (int j : i)
//            printf("%d ", j);
//        printf("\n");
//    }
    //之后自动调paintEvent
}

void MainWindow::paintGird(int y, int x, QBrush color)
{
    QPainter painter(this);
    painter.setBrush(color);
    painter.drawRect(QRect(20 + this -> girdSize * x, 20 + this -> girdSize * y, girdSize, girdSize));
}

void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QBrush wall(Qt::blue);
    QBrush road(Qt::white);
    QBrush start(Qt::green);
    QBrush end(Qt::red);

    //绘制地图边界 左上角坐标 宽度 高度 (其实这里不画也行)
    painter.drawRect(QRect(20, 20, MAZESIZE, MAZESIZE));

    //根据每个方格信息进行绘制
    vector<vector<int> > vec = this -> map -> getMap();
    for (int i = 0; i < vec.size(); i++)
        for (int j = 0; j < vec[i].size(); j++)
            switch (vec[i][j])
            {
                case 0: paintGird(i, j, road); break;
                case 1: paintGird(i, j, wall); break;
                case 2: paintGird(i, j, start); break;
                case 3: paintGird(i, j, end); break;
                default: break;
            }
}

MainWindow::~MainWindow()
{
    delete ui;
}
