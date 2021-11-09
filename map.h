#ifndef _MAP_H_INCLUDED_
#define _MAP_H_INCLUDED_

#include "cell.h"

using namespace std;


class Map{

typedef Cell* CellPtr;

private:
    int rows;
    int columns;
    CellPtr ** cellPtrMatrix;

public:
    Map();
    ~Map();

    void askCellMatrixMemory(int rows, int columns);

    CellPtr getElement(int x, int y);
    void addElement(int x, int y, string);
    bool buildBuilding(int x, int y, string data);
    bool demolishBuilding(int x, int y, string & demolishedBuilding);///
    void printMap();
    void printCellInfo(int row, int column);
    bool validateCoordinates(int row, int column);

    //Cell *** getCellMatrix();

};




#endif
