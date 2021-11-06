#ifndef _CELL_BUILDABLE_H_INCLUDED_
#define _CELL_BUILDABLE_H_INCLUDED_

#include "cell.h"
#include "Building.h"

using namespace std;

class CellBuildable: public Cell{
private:
    Building * building;

public:

    CellBuildable();
    CellBuildable(int, int, string);
    ~CellBuildable();

    void showCell();

};

#endif