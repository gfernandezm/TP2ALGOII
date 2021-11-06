#ifndef _MENU_H_INCLUDED_
#define _MENU_H_INCLUDED_


#ifdef __linux__
#define CLR_SCREEN "clear"
#endif // __linux__

#ifdef __MINGW32__
#define CLR_SCREEN "CLS"
#endif // __MINGW32__


#include "list.h"
#include "colors.h"
#include "constants.h"
#include "materials.h"
#include "building.h"
#include "buildingInfo.h"
#include "map.h"

using namespace std;

typedef enum {

	UNDEFINE = 0,
	BUILD_BUILDING_BY_NAME = 1,
	LIST_CONSTRUCTUCTED_BUILDINGS = 2,
	LIST_ALL_BUILDINGS = 3,
	DEMOLISH_BUILDING_BY_COORDINATES = 4,
	SHOW_MAP = 5,
	ASK_COORDINATES = 6,
	SHOW_INVENTARY = 7,
	COLECT_RESOURCES = 8,
	RESOURCES_STORM = 9,
	SAVE_AND_LEAVE = 10,
	LEAVE = 11

} opcion_menu_t;


// PRE: Las listas recibidas deben estar creadas, aunque estén vacías.
// POST: Se llaman a las funciones contempladas en las opciones del 1 al 6 si el usuario ingresa esas opciones.
// Caso contrario, se indica que la opción ingresada es incorrecta y se finaliza la función.
void handleMenu(/*List <Building> * buildings_chain, List <Materials>* materialsChain, */opcion_menu_t& option);

// PRE: -
// POST: Se imprime el menú del programa.
void displayMenu();

//bool validateOption(int selectedOption);

void processOption(opcion_menu_t& selectedOption, List<Materials> & materialsChain, List<BuildingInfo> & buildingsInfoChain, Map & andyMap);



// PRE: La lista recibida debe estar creada, aunque esté vacía.
// POST: Imprime por consola UNICAMENTE los materiales de construccion con sus respectivas cantidades.
void listConstructionMaterials(List <Materials> * materialsChain);


// PRE: -
// POST: Se imprime el título "Listado de materiales de construcción".
void printTitleListOfMaterials();


// PRE: -
// POST: Se imprimen los encabezados "Material" y "Cantidad".
void printHeaderListOfMaterials();


// PRE: El nodo recibido debe estar creado, aunque esté vacío.
// POST: Se imprime el material de construcción con su respectiva cantidad.
void printListOfMaterials(Node<Materials> * aux);

bool isANumber(string cadena);

#endif