#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include "utilities.h"
#include "map.h"
#include "cellBuildable.h"
#include "cellPassable.h"
#include "cellIntransitable.h"


void loadMaterials(List <Materials>* materialsChain) {
    fstream file;
    string str;
    Materials Material;
    string parsedLine[materialsParseValue];

    file.open("materiales.txt", ios::in);

    if (file.is_open()) {
        while (getline(file, str)) {
            loadParsedLine(parsedLine, str, materialsParseValue);
            Material.setMaterial(parsedLine[0]);
            Material.setAmount(stoi(parsedLine[1]));

            loadIdentifier(&Material); 

            Node<Materials> materialNode(Material);
            (*materialsChain).addNodeEnd(materialNode);
                
        }
        file.close();
    }
    else
        cerr << ERR_CANT_OPEN_FILE << endl;
}

void loadParsedLine(string parsedLine[], string str, const int parseValue) {
    string aux;
    int i = 0;

    stringstream ssin(str);
    while (ssin.good() && i < parseValue) {
        ssin >> parsedLine[i];
        i++;
    }
}


void loadIdentifier(Materials * Material){
    if(Material->getMaterial() == WORD_STONE){
        Material->setIdentifier(STONE_IDENTIFIER);
    }
    else if(Material->getMaterial() == WORD_WOOD){
        Material->setIdentifier(WOOD_IDENTIFIER);
    }
    else if(Material->getMaterial() == WORD_METAL){
        Material->setIdentifier(METAL_IDENTIFIER);
    }
    else{
        Material->setIdentifier(NO_IDENTIFIER);
    }
}


void loadMap(Map &andyMap){
    fstream file;
    string str;
    int rows;
    int columns;

    file.open("mapa.txt", ios::in);

    if (file.is_open()) {
        file >> rows;
        file >> columns;
        andyMap.askCellMatrixMemory(rows,columns);

        for(int i = 0; i < rows; i++){
            for(int j = 0; j < columns; j++){
                file >> str;
                andyMap.addElement(i, j, str);
            }
        }
        file.close();
    }
    else
        cerr << ERR_CANT_OPEN_FILE << endl;

    andyMap.printMap();
    andyMap.getElement(3,0)->showCell();
    andyMap.getElement(0,2)->showCell();
    andyMap.getElement(0,0)->showCell();
}

