#ifndef _CONSTANTS_H_INCLUDED_
#define _CONSTANTS_H_INCLUDED_


static const string WORD_STONE = "piedra";
static const string WORD_WOOD = "madera";
static const string WORD_METAL = "metal";
static const string WORD_SCHOOL = "escuela";
static const string WORD_FACTORY = "fabrica";
static const string WORD_MINE = "mina";
static const string WORD_SAWMILL = "aserradero";
static const string WORD_POWER_PLANT = "planta electrica";
static const string WORD_OBELISK = "obelisco";



static const string STONE_IDENTIFIER = "S";
static const string WOOD_IDENTIFIER = "W";
static const string METAL_IDENTIFIER = "I";
static const string MINE_IDENTIFIER = "M";
static const string SAWMILL_IDENTIFIER = "A";
static const string FACTORY_IDENTIFIER = "F";
static const string SCHOOL_IDENTIFIER = "E";
static const string OBELISK_IDENTIFIER = "O";
static const string POWER_PLANT_IDENTIFIER = "P";
static const string FIELD_IDENTIFIER = "T";
static const string ROAD_IDENTIFIER = "C";
static const string LAKE_IDENTIFIER = "L";
static const string NO_IDENTIFIER = "Identificador no definido";

static const int MATERIAL_PRODUCED_MINE = 15;
static const int MATERIAL_PRODUCED_SAWMILL = 25;
static const int MATERIAL_PRODUCED_FACTORY = 40;


static const string ERR_CANT_OPEN_FILE = "No se pudo abrir el archivo.";
static const string ERR_INCORRECT_FILE = "El archivo esta mal formado.";
static const string ERR_WRONG_INPUT = "La opcion ingresada es incorrecta.";
static const string ERR_BUILDING_NOT_FOUND = "No existe el edificio que ha ingresado.";
static const string ERR_NOT_ENOUGH_MATERIALS = "No hay suficientes materiales para construir el edificio.";
static const string ERR_NOT_ENOUGH_STONE = "No hay suficiente piedra para construir el edificio.";
static const string ERR_NOT_ENOUGH_WOOD = "No hay suficiente madera para construir el edificio.";
static const string ERR_NOT_ENOUGH_METAL = "No hay suficiente metal para construir el edificio.";
static const string ERR_NO_REMAINING_BUILDINGS_TO_BUILD = "No quedan edificios disponibles por construir.";
static const string ERR_NO_REMAINING_BUILDINGS_TO_DEMOLISH = "No quedan edificios disponibles para demoler.";
static const string ERR_INVALID_COORDINATES = "Las coordenadas no son validas";

static const string CONFIRMATION_TO_BUILD = "¿Esta seguro que desea construir el edificio?";
static const string ENTER_BUILDING_TO_BUILD = "Ingrese el nombre del edificio que desea construir: ";
static const string ENTER_BUILDING_TO_DEMOLISH = "Ingrese el edificio que desea demoler: ";
static const string ENTER_OPTION = "Ingrese el numero correspondiente a la accion que desea realizar";
static const string BUILD_BUILDING_SUCCESS = "Se construyo satisfactoriamente una unidad del edificio: ";
static const string DEMOLISH_BUILDING_SUCCESS = "Se destruyo satisfactoriamente una unidad del edificio: ";

static const string INSERT_ROW = "Ingrese la fila del casillero que desea consultar: ";
static const string INSERT_COLUMN = "Ingrese la columna del casillero que desea consultar: ";

static const string DATA_SAVED = "Todos los cambios han sido guardados";

static const string TAB = "    "; // 4 espacios.

#endif