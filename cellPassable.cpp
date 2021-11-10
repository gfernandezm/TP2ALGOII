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


void CellPassable::addMaterial(string material1){
    material.setMaterial(material1);
    material.setAmount(1);
    material.setIdentifier(STONE_IDENTIFIER);
}

Materials& CellPassable::getMaterial(){
    return material;
}


void CellPassable::showCell(){
    
    if(!material.getIdentifier().empty())
        cout << BGND_LIGHT_GRAY_246 << '|' << material.getIdentifier() << '|' << END_COLOR;
    
    else 
        cout << BGND_LIGHT_GRAY_246 << '|' << " " << '|' << END_COLOR;

}

void CellPassable::showCellInfo(){

    if(material.getIdentifier() == WOOD_IDENTIFIER){
        cout << PASSABLE_CELL_WITH_WOOD << endl;
    } else if(material.getIdentifier() == METAL_IDENTIFIER){
        cout << PASSABLE_CELL_WITH_METAL << endl;
    } else if(material.getIdentifier() == STONE_IDENTIFIER){
        cout << PASSABLE_CELL_WITH_STONE << endl;
    }
    else
        cout << PASSABLE_CELL_EMPTY << endl;

}


CellPassable::CellPassable(int x, int y, string identif) : Cell(x, y, identif){

}

