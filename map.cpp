#include <string>
#include <iostream>

#include "map.h"
#include "cellBuildable.h"
#include "cellPassable.h"
#include "cellIntransitable.h"
#include "constants.h"


using namespace std;


Map::Map(){
    rows = 0;
    columns = 0;
    cellPtrMatrix = nullptr;
}

Map::~Map(){

    if(cellPtrMatrix == nullptr)
        return;

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            delete cellPtrMatrix[i][j];
        }
        delete [] cellPtrMatrix[i];
    }    

    delete [] cellPtrMatrix;
}

void Map::askCellMatrixMemory(int rows, int columns){
    cellPtrMatrix = new CellPtr*[rows]; 

    for(int i = 0; i < rows; i++)
        (cellPtrMatrix)[i] = new CellPtr[columns];

    this->rows = rows;
    this->columns = columns;

}


Map::CellPtr Map::getElement(int x, int y){

    if(x >= rows || y >= columns || x < 0 || y < 0)
        return nullptr;

    return cellPtrMatrix[x][y];

}


void Map::addElement(int x, int y, string data){

    if(x >= rows || y >= columns || x < 0 || y < 0)
        return;

    if(data == FIELD_IDENTIFIER){
        cellPtrMatrix[x][y] = new CellBuildable(x, y, data);
    }
    else if(data == LAKE_IDENTIFIER){
        cellPtrMatrix[x][y] = new CellIntransitable(x, y, data);
    }
    else if(data == ROAD_IDENTIFIER){
        cellPtrMatrix[x][y] = new CellPassable(x, y, data);
    }

}

void Map::buildBuilding(int x, int y, string data){

    if(x >= rows || y >= columns || x < 0 || y < 0)
        return;

    (cellPtrMatrix[x][y])->setBuildingIdentifier(data);
 


/*
    if(data == FIELD_IDENTIFIER){
        cellPtrMatrix[x][y] = new CellBuildable(x, y, data);
    }
    else if(data == LAKE_IDENTIFIER){
        cellPtrMatrix[x][y] = new CellIntransitable(x, y, data);
    }
    else if(data == ROAD_IDENTIFIER){
        cellPtrMatrix[x][y] = new CellPassable(x, y, data);
    }
*/
}




void Map::printMap(){

    cout << cellPtrMatrix[0][2]->getBuilding().getIdentifier() << endl;
    cout << cellPtrMatrix[0][3]->getBuilding().getIdentifier() << endl;
    cout << cellPtrMatrix[0][4]->getBuilding().getIdentifier() << endl;

/*
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            cout << cellPtrMatrix[i][j]->getCellIdentifier() << " ";
        }
        cout << endl;
    }
*/
}



/*
Cell *** Map::getCellMatrix(){
    return &cellPtrMatrix;
}*/