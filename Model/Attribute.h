#ifndef ATTRIBUTE_H
#define ATTRIBUTE_H

#include <string>
using namespace std;

class Attribute {
    public:
        Attribute(string attributeID, string unit, string description);
        Attribute();
        
    protected:
        string attributeID;
        string unit;
        string description;

};

#endif // ATTRIBUTE_H