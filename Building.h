#ifndef _BUILDING_H_INCLUDED_
#define _BUILDING_H_INCLUDED_

using namespace std;

class Building{
protected:
    string buildingName;
    int stoneRequired;
    int woodRequired;
    int metalRequired;
    int buildingsAllowed;
    int buildingsMade;
    string identifier;
    string generatedMaterial;
    int generatedMaterialAmount;
    //

public:
    Building();
    Building(const Building &);
    ~Building();

    friend ostream & operator<< (ostream &outputStream, const Building & Building);
    bool operator==(const Building &);

    string getBuildingName()const;
    int getStoneRequired()const;
    int getWoodRequired()const;
    int getMetalRequired()const;
    int getBuildingsAllowed()const;
    int getBuildingsMade()const;
    string getIdentifier()const;
    string getGeneratedMaterial()const;
    int getGeneratedMaterialAmount()const;

    void setBuildingName(string);
    void setStoneRequired(int);
    void setWoodRequired(int);
    void setMetalRequired(int);
    void setBuildingsAllowed(int); 
    void setBuildingsMade(int);
    void setIdentifier(string);
    void setGeneratedMaterial(string);
    void setGeneratedMaterialAmount(int);

    /*
    virtual string obtenerTipoEdificio() = 0;
    En la escuela: return "Escuela"
    */
};

//escuela como atributo no tiene nada. en privado un str material q brinda. y cantidad q brinda.
/*
Building * my_escuela;
my_escuela = new Escuela();
Escuela.obtenerTipoEdificio();
*/






#endif
