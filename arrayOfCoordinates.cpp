#include <string>
#include <iostream>

#include "arrayOfCoordinates.h"

using namespace std;

ArrayOfCoordinates::ArrayOfCoordinates(){
    arrayOfCoordinates = new CoordinatesOfBuilding[INIT_SIZE];
    size = 0;
    allocSize = INIT_SIZE;
}

ArrayOfCoordinates::~ArrayOfCoordinates(){
    delete[] arrayOfCoordinates;
}

void ArrayOfCoordinates::pushBack(int row, int column){

    if(size >= allocSize){
        CoordinatesOfBuilding * aux;
        aux = new CoordinatesOfBuilding[allocSize * 4];

        for (int i = 0; i < size; i++){
            aux[i] = arrayOfCoordinates[i];
            aux[i].row = arrayOfCoordinates[i].row;
            aux[i].column = arrayOfCoordinates[i].column;

            delete[] arrayOfCoordinates;
	        arrayOfCoordinates = aux;
	        allocSize *= 4; //Aumento la capacidad del arreglo x4
        }
    }

    arrayOfCoordinates[size].row = row;
    arrayOfCoordinates[size].column = column;
    size++;
}


void ArrayOfCoordinates::print(){

    for(int i = 0; i < size; i++){
        cout << "(" << arrayOfCoordinates[i].row << ","
        << " " << arrayOfCoordinates[i].column << ")" << " ";
    }
}

//PRE: INGRESA UN INDEX MENOR AL SIZE DEL ARREGLO 
CoordinatesOfBuilding ArrayOfCoordinates::operator[](size_t index){

    return arrayOfCoordinates[index];
}
