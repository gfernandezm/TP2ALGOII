#include <iostream>

#include "menu.h"
#include "list.h"
#include "node.h"
#include "materials.h" 
#include "utilities.h"
#include "constants.h"
#include "colors.h"
#include "map.h"
#include "cell.h"
#include "buildingInfo.h"
#include "building.h"

using namespace std;


int main(){
    opcion_menu_t option = UNDEFINE;
    List<BuildingInfo> buildingsInfoChain;
    List<Materials> materialsChain;
    Map andyMap;

    system (CLR_SCREEN);
    loadBuildingsData(buildingsInfoChain);
    loadMaterials(materialsChain);
    loadMap(andyMap);

    //buildingsInfoChain.print();

    while (option != LEAVE) {
        option = UNDEFINE;
        handleMenu(option);
        processOption(option, materialsChain, buildingsInfoChain, andyMap);
    }


    return 0;
}
