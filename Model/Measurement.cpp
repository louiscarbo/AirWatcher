#include <ctime>
#include <string>
#include "Measurement.h"
#include "Attribute.h"
using namespace std;

Measurement::Measurement(Date time, float valeur, string capteurID, Attribute attribut){
    timestamp = time;
    attribute = attribut;
    sensorID = capteurID;
    value = valeur;
}

float Measurement::getValue(){
    return value;
}

Attribute Measurement::getAttribute(){
    return attribute;
}
Date Measurement::getTimeStamp(){
    return timestamp;
}