#include "Attribute.h"
#include <string>
using namespace std;

Attribute::Attribute(string attributeID, string unit, string description){
    this->attributeID = attributeID;
    this->unit = unit;
    this->description = description;
}
Attribute::Attribute(){
    attributeID = "";
    unit = "";
    description = "";
}