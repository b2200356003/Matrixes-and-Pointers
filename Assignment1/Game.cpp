#include <iostream>
#include "Game.h"

using namespace std;

int **Game::createB(int **Bmatrix, int **mapmatrix, int keyrow,int keycol, int TLrow, int TLcol) {
    Bmatrix = new int * [keyrow];
    for (int i = 0; i < keycol; ++i) {
        Bmatrix[i] = new int[keycol];
    }

    int a = -1 ;
    int b = 0 ;
    for (int i = TLrow; i <TLrow+keyrow ; i++) {
        a++;
        b=0;
        for (int j = TLcol; j <TLcol+keycol ; j++) {
            Bmatrix[a][b]=mapmatrix[i][j];
            b++;
        }
    }


    return Bmatrix;
}



void Game::Search(string file,int **Bmatrix, int **keymatrix,int**mapmatrix ,int keyrow,int keycol,int maprow,int mapcol,int&D,int &TLrow, int &TLcol) {
    ofstream myfile ;

    myfile.open(file,ios::app);

    myfile << TLrow+(keyrow/2) << ",";
    myfile << TLcol+(keycol/2) << ";";

    D=0;
    for (int i = 0; i < keyrow; i++) {
        for (int j = 0; j < keyrow; j++) {
            D+=Bmatrix[i][j]*keymatrix[i][j];
        }
    }

    // if D is negative add 5 until D be positive
    while (D<0){
        D+=5;
    }

    myfile << D << endl;

    D%=5;


    // Search with recursion like you want


    if (D==1){
        if (TLrow==0){
            TLrow+=keyrow;
            Search(file,createB(Bmatrix,mapmatrix,keyrow,keycol,TLrow,TLcol),keymatrix,mapmatrix,keyrow,keycol,maprow,mapcol,D,TLrow,TLcol);}
        else{
            TLrow-=keyrow;
            Search(file,createB(Bmatrix,mapmatrix,keyrow,keycol,TLrow,TLcol),keymatrix,mapmatrix,keyrow,keycol,maprow,mapcol,D,TLrow,TLcol);}
    }
    else if (D==2){
        if (TLrow+keyrow==maprow){
            TLrow-=keyrow;
            Search(file,createB(Bmatrix,mapmatrix,keyrow,keycol,TLrow,TLcol),keymatrix,mapmatrix,keyrow,keycol,maprow,mapcol,D,TLrow,TLcol);}
        else{
            TLrow+=keyrow;
            Search(file,createB(Bmatrix,mapmatrix,keyrow,keycol,TLrow,TLcol),keymatrix,mapmatrix,keyrow,keycol,maprow,mapcol,D,TLrow,TLcol);}
    }
    else if (D==3){
        if (TLcol+keycol==mapcol){
            TLcol-=keycol;
            Search(file,createB(Bmatrix,mapmatrix,keyrow,keycol,TLrow,TLcol),keymatrix,mapmatrix,keyrow,keycol,maprow,mapcol,D,TLrow,TLcol);}
        else{
            TLcol+=keycol;
            Search(file,createB(Bmatrix,mapmatrix,keyrow,keycol,TLrow,TLcol),keymatrix,mapmatrix,keyrow,keycol,maprow,mapcol,D,TLrow,TLcol);}

    }
    else if (D==4){
        if (TLcol==0){
            TLcol+=keycol;
            Search(file,createB(Bmatrix,mapmatrix,keyrow,keycol,TLrow,TLcol),keymatrix,mapmatrix,keyrow,keycol,maprow,mapcol,D,TLrow,TLcol);}
        else{
            TLcol-=keycol;
            Search(file,createB(Bmatrix,mapmatrix,keyrow,keycol,TLrow,TLcol),keymatrix,mapmatrix,keyrow,keycol,maprow,mapcol,D,TLrow,TLcol);}

    }

    myfile.close();
}