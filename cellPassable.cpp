#include <string>
#include <iostream>

#include "cellPassable.h"
#include "constants.h"
#include "colors.h"

using namespace std;


CellPassable::CellPassable() : Cell(){
}

CellPassable::~CellPassable(){
}


void CellPassable::showCell(){


    cout << BGND_LIGHT_GRAY_246 << '|' << ' ' << '|' << END_COLOR;

/*
    if(material.getIdentifier() == STONE_IDENTIFIER){
        cout << "soy un casillero transitable y tengo piedra" << endl;
    } else if(material.getIdentifier() == WOOD_IDENTIFIER){
        cout << "soy un casillero transitable y tengo madera" << endl;
    } else if(material.getIdentifier() == METAL_IDENTIFIER){
        cout << "soy un casillero transitable y tengo metal" << endl;
    } else 
        cout << "soy un camino y estoy vacío jeje" << endl;
*/

}

void CellPassable::showCellInfo(){

    cout << "Este casillero es un camino" << endl;

}


CellPassable::CellPassable(int x, int y, string identif) : Cell(x, y, identif){

}

