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
#include "arrayOfCoordinates.h"


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

           /* BuildingInfo building(buildingName, stoneRequired, woodRequired, metalRequired,
                                  buildingsAllowed);
                                
            Node<BuildingInfo> buildingNode(building);
            buildingsInfoChain.addNodeEnd(buildingNode);*/
            buildingsInfoChain.addNodeEnd(BuildingInfo(buildingName, stoneRequired, woodRequired, metalRequired,
                                  buildingsAllowed));
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
            
            if(andyMap.buildBuilding(rows, columns, str) == true)
                loadBuildingsMadeFromFile(str, buildingInfoChain, rows, columns);
                
            else{
                cout << ERR_INCORRECT_FILE << endl;
                exit(1);
            }

        }

        file.close();
    }
    else
        cerr << ERR_CANT_OPEN_FILE << endl;
   
}

void loadBuildingsMadeFromFile(string str, List <BuildingInfo> & buildingInfoChain, int row, int column){
    bool flag = false;
    Node<BuildingInfo> * aux = buildingInfoChain.getFirst();

    while(aux != nullptr && flag == false){

        if(aux->getData().getBuildingName() == str){
            aux->getData().setBuildingsMade(aux->getData().getBuildingsMade()+1);
            aux->getData().addCoordinates(row, column);
            flag = true;
        }
        aux = aux->getNext();
    }

    flag = false;
    aux = buildingInfoChain.getFirst();

}


void askCoordinates(int & row, int & column){
    string aux;
    
    cout << INSER_COORDINATES << endl;
    cout << INSERT_ROW << endl;
    
    getline(cin, aux);
    if (isANumber(aux) == true)
        row = stoi(aux);
    
    cout << INSERT_COLUMN << endl;
    getline(cin, aux);
    if (isANumber(aux) == true)
        column = stoi(aux);
}

bool isANumber(string cadena)
{
    for (unsigned int i = 0; i < cadena.length(); i++){
        if (!isdigit(cadena[i]))
            return false;
    }

    return true;
}

bool searchBuildingByName(List<BuildingInfo> & buildingsInfoChain, Node<BuildingInfo> ** outPtrBuildInfoNode, string building){
    (*outPtrBuildInfoNode) = buildingsInfoChain.getFirst();

    while((*outPtrBuildInfoNode) != nullptr){
        if(building == ((*outPtrBuildInfoNode)->getData()).getBuildingName())
            return true;
            
        (*outPtrBuildInfoNode) = (*outPtrBuildInfoNode)->getNext();
    }

    return false;
}

bool checkBuildingRequirements(Node<BuildingInfo> * ptrBuildInfoNode, List<Materials> & materialsChain){
    Node<Materials> * ptrMaterialsNode = materialsChain.getFirst();
    //esto es porque si ya chequeo los 3 materiales que me interesan, no es necesario seguir recorriendo la lista.
    bool stoneChecked = false, metalChecked = false, woodChecked = false, status = true;
    
    while(ptrMaterialsNode != nullptr && (!stoneChecked || !metalChecked || !woodChecked) && status != false){

        if((ptrMaterialsNode->getData()).getMaterial() == WORD_STONE){
            if((ptrMaterialsNode->getData()).getAmount() <= (ptrBuildInfoNode->getData()).getStoneRequired()){
                cout << TXT_DARK_RED_1 << ERR_NOT_ENOUGH_STONE << END_COLOR << endl;
                status = false;
            }
            stoneChecked = true;
        }

        if((ptrMaterialsNode->getData()).getMaterial() == WORD_METAL){
            if((ptrMaterialsNode->getData()).getAmount() <= (ptrBuildInfoNode->getData()).getMetalRequired()){
                cout << TXT_DARK_RED_1 << ERR_NOT_ENOUGH_METAL << END_COLOR << endl;
                status = false;
            }
            metalChecked = true;
        }

        if((ptrMaterialsNode->getData()).getMaterial() == WORD_WOOD){
            if((ptrMaterialsNode->getData()).getAmount() <= (ptrBuildInfoNode->getData()).getWoodRequired()){
                cout << TXT_DARK_RED_1 << ERR_NOT_ENOUGH_WOOD << END_COLOR <<endl;
                status = false;
            }
            woodChecked = true;
        }

        ptrMaterialsNode = ptrMaterialsNode->getNext();
    }
    return status;
}

void updateMaterialsAmount(Node<BuildingInfo> * ptrBuildInfoNode, List<Materials> & materialsChain){
    Node<Materials> * ptrMaterialsNode = materialsChain.getFirst();
    //esto es porque si ya chequeo los 3 materiales que me interesan, no es necesario seguir recorriendo la lista.
    bool stoneChecked = false, metalChecked = false, woodChecked = false, status = true;

    while(ptrMaterialsNode != nullptr && (!stoneChecked || !metalChecked || !woodChecked) && status != false){

        if((ptrMaterialsNode->getData()).getMaterial() == WORD_STONE){
            (ptrMaterialsNode->getData()).setAmount( (ptrMaterialsNode->getData()).getAmount() - (ptrBuildInfoNode->getData()).getStoneRequired() );        
            stoneChecked = true;
        }

        if((ptrMaterialsNode->getData()).getMaterial() == WORD_METAL){
            (ptrMaterialsNode->getData()).setAmount( (ptrMaterialsNode->getData()).getAmount() - (ptrBuildInfoNode->getData()).getStoneRequired() );
            metalChecked = true;
        }

        if((ptrMaterialsNode->getData()).getMaterial() == WORD_WOOD){
            (ptrMaterialsNode->getData()).setAmount( (ptrMaterialsNode->getData()).getAmount() - (ptrBuildInfoNode->getData()).getStoneRequired() );
            woodChecked = true;
        }

        ptrMaterialsNode = ptrMaterialsNode->getNext();
    }
}



void updateMaterialsAmountDemolish(Node<BuildingInfo> * ptrBuildInfoNode, List<Materials> & materialsChain){
    Node<Materials> * ptrMaterialsNode = materialsChain.getFirst();
    //esto es porque si ya chequeo los 3 materiales que me interesan, no es necesario seguir recorriendo la lista.
    bool stoneChecked = false, metalChecked = false, woodChecked = false, status = true;

    while(ptrMaterialsNode != nullptr && (!stoneChecked || !metalChecked || !woodChecked) && status != false){

        if((ptrMaterialsNode->getData()).getMaterial() == WORD_STONE){
            (ptrMaterialsNode->getData()).setAmount((ptrMaterialsNode->getData()).getAmount() + ((ptrBuildInfoNode->getData()).getStoneRequired())/2);        
            stoneChecked = true;
        }

        if((ptrMaterialsNode->getData()).getMaterial() == WORD_METAL){
            (ptrMaterialsNode->getData()).setAmount((ptrMaterialsNode->getData()).getAmount() + ((ptrBuildInfoNode->getData()).getStoneRequired())/2 );
            metalChecked = true;
        }

        if((ptrMaterialsNode->getData()).getMaterial() == WORD_WOOD){
            (ptrMaterialsNode->getData()).setAmount((ptrMaterialsNode->getData()).getAmount() + ((ptrBuildInfoNode->getData()).getStoneRequired())/2 );
            woodChecked = true;
        }

        ptrMaterialsNode = ptrMaterialsNode->getNext();
    }
}





int ConfirmationToBuild(){
    string aux;
    int selectedOption;

    printConfirmationToBuild();
    getline(cin, aux);
    if (isANumber(aux) == true)
        return selectedOption = stoi(aux);
    else{
        cerr << ERR_WRONG_INPUT << endl;
        return -1;
    }

}