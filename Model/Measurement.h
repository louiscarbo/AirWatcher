#ifndef MEASUREMENT_H
#define MEASUREMENT_H

using namespace std;
#include <ctime>
#include <string>
#include "Attribute.h"


class Measurement {
    public:
        Measurement(Date time, float valeur, string capteurID, Attribute attribut);
        float getValue();
        Attribute getAttribute();
        Date getTimeStamp();
        
    protected:
        Date timestanp;
        float value;
        string sensorID;
        Attribute attribute;

}

#endif // MEASUREMENT_H