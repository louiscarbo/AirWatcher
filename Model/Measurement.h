#ifndef MEASUREMENT_H
#define MEASUREMENT_H

#include <ctime>
#include <string>
#include "Attribute.h"
using namespace std;


class Measurement {
    public:
        Measurement(time_t time, float valeur, string capteurID, Attribute attribut);
        float getValue();
        Attribute getAttribute();
        time_t getTimeStamp();
        
    protected:
        time_t timestamp;
        float value;
        string sensorID;
        Attribute attribute;

};

#endif // MEASUREMENT_H