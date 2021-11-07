#ifndef _UTILITIES_H_INCLUDED_
#define _UTILITIES_H_INCLUDED_

#include <string>
#include <fstream>
#include <iostream>

#include "materials.h"
#include "list.h"
#include "menu.h"
#include "constants.h"
#include "map.h"
#include "buildingInfo.h"

using namespace std;

// PRE: La lista recibida debe estar creada, aunque est� vac�a (de hecho lo est�)
// y el archivo "materiales.txt" debe estar bien formado.
// POST: Si se puede abrir el archivo, se leen los elementos del archivo, se los procesa y se los carga en los atributos correspondientes
// de la clase Materiales, para luego a�adir al final de la lista recibida un Nodo que contiene la instancia de esta clase.
// Caso contrario, se indica que no se pudo abrir el archivo y finaliza la funci�n.
void loadMaterials(List <Materials> & materialsChain);


// PRE: La lista recibida debe estar creada, aunque esté vacía (de hecho lo está)
// y el archivo "edificios.txt" debe estar bien formado.
// POST: Si se puede abrir el archivo, se leen los elementos del archivo, se los procesa y se los carga en los atributos correspondientes
// de la clase Building, para luego añadir al final de la lista recibida un Nodo que contiene la instancia de esta clase.
// Caso contrario, se indica que no se pudo abrir el archivo y finaliza la función.
void loadBuildingsData(List <BuildingInfo> & buildings_chain);

void loadBuildingsMadeFromFile(string str, List <BuildingInfo> & buildingInfoChain);
void loadMap(Map &andyMap, List <BuildingInfo> & buildingInfoChain);
void createMap(Map & andyMap);
void loadMapFromFile(Map & andyMap,List <BuildingInfo> & buildingInfoChain);

void askCoordinates(int & row, int & column);
bool isANumber(string cadena);

bool searchBuildingByName(List<BuildingInfo> & buildingsInfoChain, Node<BuildingInfo> ** ptrBuildInfoNode, string building);
bool checkBuildingRequirements(Node<BuildingInfo> * ptrBuildInfoNode,  List<Materials> & materialsChain);
void updateMaterialsAmount(Node<BuildingInfo> * ptrBuildInfoNode, List<Materials> & materialsChain);

int ConfirmationToBuild();



#endif