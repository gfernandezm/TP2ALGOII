#include <string>
#include <iostream>

#include "materials.h"

using namespace std;

// Constructores

Materials::Materials() {
    material.clear();
    identifier.clear();
    amount = 0;
}

Materials::Materials(const Materials& Material) {
    material = Material.material;
    identifier = Material.identifier;
    amount = Material.amount;
}

// Destructor

Materials::~Materials() {
}


// Sobrecarga de operadores

ostream& operator<< (ostream& outputStream, const Materials& Material) {
    outputStream << Material.material << endl;
    outputStream << Material.identifier << endl;
    outputStream << Material.amount << endl;

    return outputStream;
}

bool Materials::operator==(const Materials& Material) {
    return  (material == Material.material && identifier == Material.identifier && amount == Material.amount);
}

// Getters

string Materials::getMaterial()const {
    return material;
}

string Materials::getIdentifier()const {
    return identifier;
}

int Materials::getAmount()const {
    return amount;
}

// Setters

void Materials::setMaterial(string mat) {
    material = mat;
}

void Materials::setIdentifier(string identif) {
    identifier = identif;
}

void Materials::setAmount(int amountt) {
    amount = amountt;
}