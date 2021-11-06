#include <string>
#include <iostream>

#include "cellBuildable.h"

using namespace std;


CellBuildable::CellBuildable() : Cell(){
    building = nullptr;
}

CellBuildable::~CellBuildable(){
}


void CellBuildable::showCell(){

    if(building){
        cout << "soy un casillero construible y hay algo construido" << endl;
    } else{
        cout << "soy un casillero construible y toy vacio uwu" << endl;
    }

}


CellBuildable::CellBuildable(int x, int y, string identif) : Cell(x, y, identif){
    building = nullptr;
}

