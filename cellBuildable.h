#ifndef _CELL_BUILDABLE_H_INCLUDED_
#define _CELL_BUILDABLE_H_INCLUDED_

#include "cell.h"
#include "building.h"

using namespace std;

class CellBuildable: public Cell{
private:
    Building * ptrBuilding;
    bool isBuilt;

public:

    CellBuildable();
    CellBuildable(string building);
    CellBuildable(int, int, string);
    ~CellBuildable();

    void showCell();

    //void setBuildingIdentifier(string);
    void build(string building);
    


};

#endif