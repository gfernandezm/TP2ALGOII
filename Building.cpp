#include <string>
#include <iostream>

#include "building.h"

using namespace std;

// Constructores

Building::Building(){
    buildingName.clear();
    stoneRequired = 0;
    woodRequired = 0;
    metalRequired = 0;
    buildingsAllowed = 0;
    buildingsMade = 0;
    identifier.clear();
    generatedMaterial.clear();
    generatedMaterialAmount = 0;
}

Building::Building(const Building & Building){
    buildingName = Building.buildingName;
    stoneRequired = Building.stoneRequired;
    woodRequired = Building.woodRequired;
    metalRequired = Building.metalRequired;
    buildingsAllowed = Building.buildingsAllowed;
    buildingsMade = Building.buildingsMade;
    identifier = Building.identifier;
    generatedMaterial = Building.generatedMaterial;
    generatedMaterialAmount = Building.generatedMaterialAmount;
}

// Destructor

Building::~Building(){
}


// Sobrecarga de operadores

ostream & operator<< (ostream &outputStream, const Building & Building){
 	outputStream << Building.buildingName << endl;
    outputStream << Building.stoneRequired << endl;
    outputStream << Building.woodRequired << endl;
    outputStream << Building.metalRequired << endl;
    outputStream << Building.buildingsAllowed << endl;
    outputStream << Building.buildingsMade << endl;
    outputStream << Building.identifier << endl;
    outputStream << Building.generatedMaterial << endl;
    outputStream << Building.generatedMaterialAmount << endl;

	return outputStream;
}


bool Building::operator==(const Building & Building){
    return  ( buildingName == Building.buildingName
            && stoneRequired == Building.stoneRequired
            && woodRequired == Building.woodRequired 
            && metalRequired == Building.metalRequired
            && buildingsAllowed == Building.buildingsAllowed 
            && buildingsMade == Building.buildingsMade
            && identifier == Building.identifier
            && generatedMaterial == Building.generatedMaterial
            && generatedMaterialAmount == Building.generatedMaterialAmount);
}

// Getters

string Building::getBuildingName()const{
    return buildingName;
}

int Building::getStoneRequired()const{
    return stoneRequired;
}

int Building::getWoodRequired()const{
    return woodRequired;
}

int Building::getMetalRequired()const{
    return metalRequired;
}

int Building::getBuildingsAllowed()const{
    return buildingsAllowed;
}

int Building::getBuildingsMade()const{
    return buildingsMade;
}

string Building::getIdentifier()const{
    return identifier;
}

string Building::getGeneratedMaterial()const{
    return generatedMaterial;
}

int Building::getGeneratedMaterialAmount()const{
    return generatedMaterialAmount;
}

// Setters

void Building::setBuildingName(string builName){
    buildingName = builName;
}

void Building::setStoneRequired(int stoneReq){
    stoneRequired = stoneReq;
}

void Building::setWoodRequired(int woodReq){
    woodRequired = woodReq;
}

void Building::setMetalRequired(int metalReq){
    metalRequired = metalReq;
}

void Building::setBuildingsAllowed(int builAllowed){
    buildingsAllowed = builAllowed;
}

void Building::setBuildingsMade(int builMade){
    buildingsMade = builMade;
}

void Building::setIdentifier(string identif){
    identifier = identif;
}

void Building::setGeneratedMaterial(string generatedMat){
    generatedMaterial = generatedMat;
}

void Building::setGeneratedMaterialAmount(int generatedMatAmount){
    generatedMaterialAmount = generatedMatAmount;
}