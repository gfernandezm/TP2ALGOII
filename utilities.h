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

using namespace std;

static const int materialsParseValue = 2;

// PRE: La lista recibida debe estar creada, aunque est� vac�a (de hecho lo est�)
// y el archivo "materiales.txt" debe estar bien formado.
// POST: Si se puede abrir el archivo, se leen los elementos del archivo, se los procesa y se los carga en los atributos correspondientes
// de la clase Materiales, para luego a�adir al final de la lista recibida un Nodo que contiene la instancia de esta clase.
// Caso contrario, se indica que no se pudo abrir el archivo y finaliza la funci�n.
void loadMaterials(List <Materials>* materialsChain);

// PRE: -
// POST: Obtiene cada una de las palabras de "str" y las carga en orden de aparici�n en el arreglo de cadenas "parsed_line[]" 
void loadParsedLine(string parsedLine[], string str, const int parseValue);



void loadIdentifier(Materials * Material);

void loadMap(Map &andyMap);


#endif