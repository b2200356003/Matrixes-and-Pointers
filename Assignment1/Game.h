#pragma once
#include <iostream>
#include <fstream>
using namespace std;
class Game {
public:
    // creating B matrix
    static int** createB(int **Bmatrix, int **mapmatrix, int keyrow,int keycol, int TLrow, int TLcol);

    // The search function for playing game
    static void Search(string file ,int **Bmatrix, int **keymatrix,int**mapmatrix ,int keyrow,int keycol,int maprow,int mapcol,int&D,int &TLrow, int &TLcol);
};


