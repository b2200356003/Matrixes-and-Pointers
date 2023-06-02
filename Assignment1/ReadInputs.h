#pragma once
using namespace std;
#include <fstream>


class ReadInputs {
public:
    // even though we take row and column numbers of key and mapmatrix I check it manuelly for better output
    static void FindRC(string file,int &keyrow, int &keycol, int &maprow, int&mapcol);
    // creating empty map and keymatrix with true row and column numbers
    static int** CreateMatrixes(string file,int ** matrix,int keyrow,int keycol,int maprow,int mapcol);
    // filling the matrixes with input values
    static int** FillMatrixes(string file,int ** matrix,int row,int col);

    static void ClearOutput(string file);
};


