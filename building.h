#ifndef _BUILDING_H_INCLUDED_
#define _BUILDING_H_INCLUDED_


using namespace std;

class Building{
protected:
    string identifier; 
    string generatedMaterial; 
    int generatedMaterialAmount; 

public:
    Building();
    Building(const Building &);
    ~Building();

    friend ostream & operator<< (ostream &outputStream, const Building & Building);
    bool operator==(const Building &);

    string getIdentifier()const;
    string getGeneratedMaterial()const;
    int getGeneratedMaterialAmount()const;

    void setIdentifier(string);
    void setGeneratedMaterial(string);
    void setGeneratedMaterialAmount(int);

};

#endif






