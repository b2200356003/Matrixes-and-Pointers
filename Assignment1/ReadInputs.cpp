#include <string>
#include <sstream>
#include "ReadInputs.h"
#include <iostream>
using namespace std;

void ReadInputs::FindRC(string file,int &keyrow, int &keycol, int &maprow, int&mapcol) {
    ifstream inFile(file);
    string line ;
    string temp ;
    while (getline(inFile, line)) {
        if (line != " ") {
            if (file.substr(0,1) == "k") {
                keyrow += 1;
            }
            if (file.substr(0,1) == "m") {
                maprow += 1;
            }
        }
        line = line + " ";
        for (int i = 0; i < line.length(); i++) {
            if (string(1, line[i]) == " ") {
                 if (file.substr(0,1) == "k") {
                    keycol += 1;
                }
                if (file.substr(0,1) == "m") {
                    mapcol += 1;
                }
            }
        }
    }
    if (file.substr(0,1) == "k") {
        keycol=keycol/keyrow;
    }
    if (file.substr(0,1) == "m") {
        mapcol=mapcol/maprow;
    }

    inFile.close();

}

int **ReadInputs::CreateMatrixes(string file, int **matrix, int keyrow, int keycol, int maprow, int mapcol) {
    if (file.substr(0,1) == "k"){
        matrix = new int *[keyrow];
        for (int i = 0; i < keyrow; ++i) {
            matrix[i] = new int[keycol];
        }
    }

    if (file.substr(0,1) == "m"){
        matrix = new int *[maprow];
        for (int i = 0; i < maprow; ++i) {
            matrix[i] = new int[mapcol];
        }
    }


    return matrix;
}

int **ReadInputs::FillMatrixes(string file,int ** matrix,int row,int col) {
    ifstream fillstr;
    fillstr.open(file);
    string line;
    for (int i = 0; i < row; i++) {
        getline (fillstr, line);
        stringstream sstream2;
        sstream2 << line;
        int temp;
        for (int j = 0; j < col; j++) {
            sstream2 >> temp;
            matrix[i][j] = temp;
        }
    }
    fillstr.close();
    return matrix;
}

void ReadInputs::ClearOutput(string file) {
    // to exactly true outputs for multiple tries.
    int length;
    ifstream filestr;

    filestr.open(file, ios::binary);
    filestr.seekg(0, ios::end);
    length = filestr.tellg();
    filestr.close();

    if ( length != 0 ){
        ofstream ofs;
        ofs.open(file, std::ofstream::out | std::ofstream::trunc);
        ofs.close();
    }
}

