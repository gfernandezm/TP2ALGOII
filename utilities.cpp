#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include "utilities.h"
#include "map.h"
#include "cellBuildable.h"
#include "cellPassable.h"
#include "cellIntransitable.h"
#include "buildingInfo.h"
#include "list.h"
#include "node.h"


void loadBuildingsData(List <BuildingInfo> & buildingsInfoChain){
    fstream file;
    string aux;
    string buildingName;
    int stoneRequired;
    int woodRequired;
    int metalRequired;
    int buildingsAllowed;   

    file.open("edificios.txt", ios::in); 

    if(file.is_open()){

        while(file >> buildingName){
            
            file >> aux;
            if (isANumber(aux) == true) {
                stoneRequired = stoi(aux);
            } else {
                buildingName = buildingName + " " + aux;
                file >> stoneRequired;
            }

            file >> woodRequired;
            file >> metalRequired;
            file >> buildingsAllowed;

            BuildingInfo building(buildingName, stoneRequired, woodRequired, metalRequired,
                                  buildingsAllowed);

            Node<BuildingInfo> buildingNode(building);
            buildingsInfoChain.addNodeEnd(buildingNode);
        }

 		file.close();
    }
	else
		cerr << ERR_CANT_OPEN_FILE << endl;     
}



void loadMaterials(List <Materials> & materialsChain) {
    fstream file;
    string materialName;
    int amount;

    file.open("materiales.txt", ios::in);

    if (file.is_open()) {

        while(file >> materialName){
            file >> amount;

            Materials material(materialName, amount);
            Node<Materials> materialNode(material);
            materialsChain.addNodeEnd(materialNode);
        }
        file.close();
    }
    else
        cerr << ERR_CANT_OPEN_FILE << endl;
}


void loadMap(Map &andyMap, List <BuildingInfo> & buildingInfoChain){
    createMap(andyMap);
    loadMapFromFile(andyMap, buildingInfoChain);
}


void createMap(Map & andyMap){
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
    else{
        cerr << ERR_CANT_OPEN_FILE << endl;
    }
}

void loadMapFromFile(Map & andyMap,List <BuildingInfo> & buildingInfoChain){
    fstream file;
    string str;
    string coordinates;
    int rows;
    int columns;

    file.open("ubicaciones.txt", ios::in);

    if (file.is_open()) {
 
        while(file >> str){
            file >> coordinates;
            if (coordinates[0] == '(') {
                rows = coordinates[1] - '0';
                columns = coordinates[3] - '0';
            } else {
                str = str + " " + coordinates;
                file >> coordinates;
                rows = coordinates[1] - '0';
                columns = coordinates[3] - '0';
            }   
            
            andyMap.buildBuilding(rows, columns, str);

            loadBuildingsMadeFromFile(str, buildingInfoChain);

        }

        file.close();
    }
    else
        cerr << ERR_CANT_OPEN_FILE << endl;
   
}

void loadBuildingsMadeFromFile(string str, List <BuildingInfo> & buildingInfoChain){

    bool flag = false;
    Node<BuildingInfo> * aux = buildingInfoChain.getFirst();

    while(aux != nullptr && flag == false){

        if(aux->getData().getBuildingName() == str){
            aux->getData().setBuildingsMade(aux->getData().getBuildingsMade()+1);
            flag = true;
        }
        aux = aux->getNext();
    }

    flag = false;
    aux = buildingInfoChain.getFirst();

}
