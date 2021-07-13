
#ifndef GENERATOR_H
#define GENERATOR_H
#include <vector>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include "mazemap.h"
#define down 1
#define right 2
#define left 3
#define up 4
#define WALL -1
#define NOTHING 2
using namespace std;
struct block{
    int row,column,direction;
    block(int _row,int _column,int _direction){
        row = _row;
        column = _column;
        direction = _direction;
    }
};
class generator
{
public:
    generator(int row0, int column0);
    void init();
    void findBlock();
    void genMaze();
private:
    vector<block> myblock;
    int M[200][200];
    int startX,startY;
    int row1,column1;
    int x=1,y=1;
    vector<vector<int> > maze;
    MazeMap qwq;
};
#endif // GENERATOR_H
