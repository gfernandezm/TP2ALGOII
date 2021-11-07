#ifndef _CELL_INTRANSITABLE_H_INCLUDED_
#define _CELL_INTRANSITABLE_H_INCLUDED_

#include "cell.h"

using namespace std;

class CellIntransitable: public Cell{

public:

    CellIntransitable();
    CellIntransitable(int, int, string);
    ~CellIntransitable();

    void showCell();
    void showCellInfo();


};

#endif