#ifndef _CELL_PASSABLE_H_INCLUDED_
#define _CELL_PASSABLE_H_INCLUDED_

#include "cell.h"
#include "materials.h"

using namespace std;

class CellPassable: public Cell{
private:
    Materials material;

public:

    CellPassable();
    CellPassable(int, int, string);
    ~CellPassable();

    void showCell();

};

#endif