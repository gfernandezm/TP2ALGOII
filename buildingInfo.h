#ifndef _BUILDING_INFO_H_INCLUDED_
#define _BUILDING_INFO_H_INCLUDED_

using namespace std;

class BuildingInfo{
private:
    string buildingName;
    int stoneRequired;
    int woodRequired;
    int metalRequired;
    int buildingsAllowed;
    int buildingsMade; 


public:
    BuildingInfo();
    BuildingInfo(string, int, int, int, int);
    BuildingInfo(const BuildingInfo &);
    ~BuildingInfo();

    friend ostream & operator<< (ostream &outputStream, const BuildingInfo & building);
    bool operator==(const BuildingInfo &);

    string getBuildingName()const;
    int getStoneRequired()const;
    int getWoodRequired()const;
    int getMetalRequired()const;
    int getBuildingsAllowed()const;
    int getBuildingsMade()const;


    void setBuildingName(string);
    void setStoneRequired(int);
    void setWoodRequired(int);
    void setMetalRequired(int);
    void setBuildingsAllowed(int); 
    void setBuildingsMade(int);


};



#endif
