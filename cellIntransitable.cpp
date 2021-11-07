#include <string>
#include <iostream>

#include "cellIntransitable.h"
#include "constants.h"
#include "colors.h"

using namespace std;


CellIntransitable::CellIntransitable() : Cell(){
}

CellIntransitable::~CellIntransitable(){
}


void CellIntransitable::showCell(){

    cout << BGND_BLUE_19 << '|' << ' ' << '|' << END_COLOR;

}

void CellIntransitable::showCellInfo(){

    cout << "Este casillero es un lago" << endl;

}



CellIntransitable::CellIntransitable(int x, int y, string identif) : Cell(x, y, identif){

}

