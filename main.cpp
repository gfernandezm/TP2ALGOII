#include <iostream>

#include "menu.h"
#include "list.h"
#include "node.h"
#include "materials.h" //Tiene que estar en mayúscula
#include "utilities.h"
#include "constants.h"
#include "colors.h"
#include "map.h"
#include "cell.h"


using namespace std;


int main(){
    opcion_menu_t opcion = UNDEFINE;
    //List<Building *> buildingsChain;
    List<Materials> materialsChain;
    Map andyMap;

    //load_buildings_data(&buildingsChain);
    loadMaterials(&materialsChain);
    system (CLR_SCREEN);
    loadMap(andyMap);

    while (opcion != LEAVE) {
        opcion = UNDEFINE;
        handleMenu(opcion);
        processOption(opcion, &materialsChain);
    }


    //handleMenu(/*&buildingsChain,*/ &materialsChain);

    return 0;
}
