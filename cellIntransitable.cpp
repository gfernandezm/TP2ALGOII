#include <string>
#include <iostream>

#include "cellIntransitable.h"
#include "constants.h"

using namespace std;


CellIntransitable::CellIntransitable() : Cell(){
}

CellIntransitable::~CellIntransitable(){
}


void CellIntransitable::showCell(){

    cout << "soy un lago bro" << endl;

}


CellIntransitable::CellIntransitable(int x, int y, string identif) : Cell(x, y, identif){

}

