#if ! defined (Attribute)
#define Attribute

#include <string>
using namespace std;


class Measurement {
    public:
        Attribute(string attributeID, string unit, string description);
        
    protected:
        string attributeID;
        string unit;
        string description;

}

#endif