#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>

#include "menu.h"


using namespace std;

void handleMenu(opcion_menu_t& option) {
    int selectedOption = 0;
    string aux;

    displayMenu();
    getline(cin, aux);

    if (isANumber(aux) == true)
        selectedOption = stoi(aux);
 
    if (selectedOption >= 1 && selectedOption <= 10)
        option = (opcion_menu_t)selectedOption;
  
}

void processOption(opcion_menu_t& selectedOption, List<Materials> & materialsChain, List<BuildingInfo> & buildingsInfoChain, Map & andyMap){

    switch(selectedOption){
        case BUILD_BUILDING_BY_NAME:
            buildBuildingByName(materialsChain, buildingsInfoChain, andyMap);
            break;

        case LIST_CONSTRUCTUCTED_BUILDINGS:
            cout << "opcion 2" << endl;
            break;

        case LIST_ALL_BUILDINGS:
            cout << "opcion 3" << endl;
            break;

        case DEMOLISH_BUILDING_BY_COORDINATES:
            cout << "opcion 4" << endl;
            break;

        case SHOW_MAP:
            andyMap.printMap();
            break;

        case ASK_COORDINATES:
            showCellByCoordinates(andyMap);
            break;

        case SHOW_INVENTARY:
            listConstructionMaterials(&materialsChain);
            break;
            
        case COLECT_RESOURCES:
            cout << "opcion 8" << endl;
            break;
        
        case RESOURCES_STORM:
            cout << "opcion 9" << endl;
            break;

        case SAVE_AND_LEAVE:
            cout << "opcion 10" << endl;
            selectedOption = LEAVE;
            break;

        default:
            cout << ERR_WRONG_INPUT << endl;
            break;
    }
}

void buildBuildingByName(List<Materials> &materialsChain, List<BuildingInfo> &buildingsInfoChain, Map &andyMap){
    string building;
    Node<BuildingInfo> * ptrBuildInfoNode = nullptr;
    int row, column;

    cout << ENTER_BUILDING_TO_BUILD << endl;
    getline(cin, building);
    
    if(searchBuildingByName(buildingsInfoChain, &ptrBuildInfoNode, building) == true){
        if(checkBuildingRequirements(ptrBuildInfoNode, materialsChain) == true){
            askCoordinates(row,column);
            if(andyMap.validateCoordinates(row, column) == true){
                if((ptrBuildInfoNode->getData()).getBuildingsAllowed() - (ptrBuildInfoNode->getData()).getBuildingsMade() > 0){

                    if(ConfirmationToBuild() == CONFIRMATION_BUILD_YES){
                        if(andyMap.buildBuilding(row, column, building) == true){
                            ptrBuildInfoNode->getData().setBuildingsMade(ptrBuildInfoNode->getData().getBuildingsMade() + 1);
                            updateMaterialsAmount(ptrBuildInfoNode, materialsChain);
                            cout << BUILD_BUILDING_SUCCESS << building << endl;
                        }
                    }
                }
                else
                    cerr << ERR_NO_REMAINING_BUILDINGS_TO_BUILD << endl;
            } else
                cerr << ERR_INVALID_COORDINATES << endl;
        }
    } else
        cerr << ERR_BUILDING_NOT_FOUND << endl;
}






void showCellByCoordinates(Map & andyMap){
    int row, column;

    askCoordinates(row, column);

    if(andyMap.validateCoordinates(row,column) == false){
        cerr << ERR_INVALID_COORDINATES << endl;
        return;
    }

    andyMap.printCellInfo(row, column);
}





void listConstructionMaterials(List <Materials> * materialsChain){
    Node<Materials> * aux = (*materialsChain).getFirst();
    string material;

    printTitleListOfMaterials();
    printHeaderListOfMaterials();

	if(!(*materialsChain).isEmpty()){
		while(aux != 0){
            material = (aux->getData()).getMaterial();
            printListOfMaterials(aux);
			aux = aux->getNext();
		}
		cout << endl;
	}
}





void displayMenu(){

    cout << TAB << BGND_DARK_AQUA_24 << TAB << TAB << TAB << TAB << " MENU" << TAB << TAB << TAB << TAB << TAB << TAB << END_COLOR << endl;
    cout << TAB << BGND_DARK_AQUA_24 << "_____________________________________________" << END_COLOR << endl;
    cout << TAB << BGND_DARK_AQUA_24 << "|  1. Constuir edificio por nombre.         |" << END_COLOR << endl;
    cout << TAB << BGND_DARK_AQUA_24 << "|  2. Listar los edificios construidos      |" << END_COLOR << endl;
    cout << TAB << BGND_DARK_AQUA_24 << "|  3. Listar todos los edificios            |" << END_COLOR << endl;
    cout << TAB << BGND_DARK_AQUA_24 << "|  4. Demoler un edificio por coordenada.   |" << END_COLOR << endl;
    cout << TAB << BGND_DARK_AQUA_24 << "|  5. Mostrar mapa.                         |" << END_COLOR << endl;
    cout << TAB << BGND_DARK_AQUA_24 << "|  6. Consultar coordenada.                 |" << END_COLOR << endl;
    cout << TAB << BGND_DARK_AQUA_24 << "|  7. Mostrar inventario.                   |" << END_COLOR << endl;
    cout << TAB << BGND_DARK_AQUA_24 << "|  8. Recolectar recursos producidos.       |" << END_COLOR << endl;
    cout << TAB << BGND_DARK_AQUA_24 << "|  9. Lluvia de recursos.                   |" << END_COLOR << endl;
    cout << TAB << BGND_DARK_AQUA_24 << "| 10. Guardar y salir.                      |" << END_COLOR << endl;
    cout << TAB << BGND_DARK_AQUA_24 << "|___________________________________________|" << END_COLOR << endl;

    cout << TXT_ORANGE_166 << ENTER_OPTION << END_COLOR << endl;

}

void printTitleListOfMaterials(){
    cout << TAB << BGND_DARK_AQUA_24 << "_________________________________________" << END_COLOR << endl;
    cout << TAB << BGND_DARK_AQUA_24 << "| Listado de materiales de construccion |" << END_COLOR << endl;
    cout << TAB << BGND_DARK_AQUA_24 << "|_______________________________________|" << END_COLOR << endl;
}

void printHeaderListOfMaterials(){
    int width = 15;
    cout << left << TAB << setw(width)  << "Material" << setw(1) << "|" << setw(width) << "Cantidad" << endl;
}


void printListOfMaterials(Node<Materials> * aux){
    int width = 15;
    cout << left << TAB << setw(width) << (aux->getData()).getMaterial() << setw(1) << "|" 
    << setw(width) << (aux->getData()).getAmount() << endl;
}

void printConfirmationToBuild(){
    cout << TXT_ORANGE_166 << CONFIRMATION_TO_BUILD << END_COLOR << endl;
    cout << TXT_ORANGE_166 << ENTER_OPTION << END_COLOR << endl;
    cout << TXT_ORANGE_166 << "1. Si" << END_COLOR << endl;
    cout << TXT_ORANGE_166 << "2. No" << END_COLOR << endl;
}