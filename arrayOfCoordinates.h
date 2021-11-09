#ifndef _ARRAY_OF_COORDINATES_H_INCLUDED_
#define _ARRAY_OF_COORDINATES_H_INCLUDED_

using namespace std;
#include "constants.h"

struct CoordinatesOfBuilding{
	int row;
	int column;
} ;


class ArrayOfCoordinates{
private:
    int size;
	int allocSize;
    CoordinatesOfBuilding * arrayOfCoordinates; 

public:
    ArrayOfCoordinates();
    ~ArrayOfCoordinates();

    void pushBack(int row, int column);
    void print();
    void deletee(int row, int column);

    CoordinatesOfBuilding operator[](size_t index);

};



#endif
