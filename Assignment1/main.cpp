using namespace std;
#include "ReadInputs.h"
#include "Game.h"

int main(int argc, char *argv[]) {
    int** Bmatrix;
    int ** keymatrix;
    int ** mapmatrix;
    int D;
    int TLrow=0;
    int TLcol=0;
    int keyrow =0;
    int keycol = 0;
    int maprow = 0;
    int mapcol = 0;

    ReadInputs::ClearOutput(argv[5]);
    ReadInputs::FindRC(argv[4],keyrow,keycol,maprow,mapcol);
    ReadInputs::FindRC(argv[3],keyrow,keycol,maprow,mapcol);
    keymatrix=ReadInputs::CreateMatrixes(argv[4],keymatrix,keyrow,keycol,maprow,mapcol);
    mapmatrix=ReadInputs::CreateMatrixes(argv[3],mapmatrix,keyrow,keycol,maprow,mapcol);

    keymatrix=ReadInputs::FillMatrixes(argv[4],keymatrix,keyrow,keycol);
    mapmatrix=ReadInputs::FillMatrixes(argv[3],mapmatrix,maprow,mapcol);

    Bmatrix=Game::createB(Bmatrix,mapmatrix,keyrow,keycol,TLrow,TLcol);

    Game::Search(argv[5],Bmatrix,keymatrix,mapmatrix,keyrow,keycol,maprow,mapcol,D,TLrow,TLcol);

    return 0;
}