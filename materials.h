#ifndef _MATERIALS_H_INCLUDED_
#define _MATERIALS_H_INCLUDED_

using namespace std;

class Materials {

    string material;
    string identifier;
    int amount;

public:
    Materials();
    Materials(string, int);
    Materials(const Materials&);
    ~Materials();

    friend ostream& operator<< (ostream& outputStream, const Materials& Material);
    bool operator==(const Materials&);

    string getMaterial()const;
    string getIdentifier()const;
    int getAmount()const;

    void setMaterial(string);
    void setIdentifier(string);
    void setAmount(int);
};

#endif
