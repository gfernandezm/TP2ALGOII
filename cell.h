#ifndef _CELL_H_INCLUDED_
#define _CELL_H_INCLUDED_

using namespace std;

class Cell{
protected:
    int coordinateX; 
    int coordinateY; 
    string cellIdentifier;
    
public:
    Cell();
    Cell(int x, int y, string identif);
    virtual ~Cell() = 0;
    

    void setCellIdentifier(string);
    void setCoordinates(int x, int y);

    string getCellIdentifier()const;
    int getCoordinateX()const;
    int getCoordinateY()const;


    virtual void showCell() = 0;

    //friend ostream & operator<< (ostream &os, const Cell & b);
    //virtual void show();
};



#endif