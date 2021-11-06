#include <string>
#include <iostream>

#include "cellBuildable.h"
#include "school.h"
#include "mine.h"
#include "sawmill.h"
#include "factory.h"
#include "power_plant.h"
#include "obelisk.h"
#include "constants.h"

using namespace std;


CellBuildable::CellBuildable() : Cell(){
    ptrBuilding = nullptr;
    isBuilt = false;
}


void CellBuildable::build(string building){
    
    if(building == WORD_SCHOOL)
        ptrBuilding = new School();
    else if (building == WORD_OBELISK)    
        ptrBuilding = new Obelisk();
    else if (building == WORD_FACTORY)
        ptrBuilding = new Factory();    
    else if (building == WORD_SAWMILL)
        ptrBuilding = new Sawmill();
    else if (building == WORD_MINE)
        ptrBuilding = new Mine();
    else if (building == WORD_POWER_PLANT)
        ptrBuilding = new PowerPlant();
    
    isBuilt = true;
}


CellBuildable::~CellBuildable(){
    if(ptrBuilding)
        delete ptrBuilding;
}


void CellBuildable::showCell(){

    if(ptrBuilding){
        cout << "soy un casillero construible y tengo construido un edificio con el siguiente identificador: " 
        <<  (*ptrBuilding).getIdentifier() << endl;
    } else{
        cout << "soy un casillero construible y toy vacio uwu" << endl;
    }

}


CellBuildable::CellBuildable(int x, int y, string identif) : Cell(x, y, identif){
    ptrBuilding = nullptr;
    isBuilt = false;
}

/*
void CellBuildable::setBuildingIdentifier(string identif){
    ptrBuilding = new Building;
    (*ptrBuilding).setIdentifier(identif);
    isBuilt = true;
}
*/


