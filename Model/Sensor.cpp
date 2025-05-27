#include <string>
#include <ctime>
#include <chrono>
#include <set>
#include <vector>
#include "Sensor.h"
using Timestamp = std::chrono::time_point<std::chrono::system_clock>;
#include "../Model/Coordinates.h"
#include "../Model/Measurement.h"
#include <map>
using namespace std;


 
Coordinates * Sensor::getCoordinates() const{
    return coordinates;
}

int Sensor::calculateMeanAtmoIndex(Timestamp timeStamp =  std::chrono::system_clock::now()){ //à vérifier
    int atmo_final = 0;
    auto it = measurements.begin();
    map<int,int> dictMaxValAtmo;
    for(int i=0;i<measurements.size();i+=4){
        advance(it, i);
        if (it->getTimeStamp()==timeStamp){
            for(int j=0;j<4;++j){
                advance(it, i+j);
                dictMaxValAtmo = dictUnitAtmoMaxValue[it->getAttribute().getUnit()];
                for(int atmo=1;atmo<=10;++atmo){
                    if(dictMaxValAtmo[atmo]>= ((int)it->getValue()) && atmo>1){
                        atmo_final=max(atmo_final,atmo);
                        break;
                    }
                }
            }
            
        }
    }
    return atmo_final;
}


bool Sensor::hasMeasurementAtTime(Timestamp timeStamp) const{
    bool res = false;
    auto it = measurements.begin();
    for(int i=0;i<measurements.size();i+=4){
        advance(it, i);
        if (it->getTimeStamp()==timeStamp){
            res = true;
            break;                
        }

    }
    return res;
}

string Sensor::getSensorID() const
{
    #ifdef MAP
        cout << "Appel à getSensorID" << endl;
    #endif
    return sensorID;
}

vector<Timestamp> Sensor::getMeasurementTimestamps() const { //!!!!!!!!!!!!!!!!!!!!! set et non list
    set <Timestamp> liste_timestamps;
    auto it = measurements.begin();
    for(int i=0;i<measurements.size();++i){
        advance(it, i);
        liste_timestamps.insert(it->getTimeStamp());
    }

    vector<Timestamp> liste_finale(liste_timestamps.begin(), liste_timestamps.end());
    return liste_finale;
}


Sensor::Sensor(){
    initDictUnit(); 
}
//boolean addMeasurement(Measurement measurement)??
Sensor::Sensor(string sensor_ID, float latitudeInit, float longitudeInit, PrivateIndividual * privateIndiv) {
    sensorID = sensor_ID;
    coordinates = new Coordinates(latitudeInit, longitudeInit);
    privateIndividual = privateIndiv;
    measurements = list<Measurement>();
    initDictUnit();
}
Sensor::~Sensor(){
    #ifdef MAP
        cout << "Appel au destructeur de <Sensor>" << endl;
    #endif
    delete coordinates;
}



void Sensor::initDictUnit(){
    //O3
    dictUnitAtmoMaxValue["O3"][1]=29;
    dictUnitAtmoMaxValue["O3"][2]=54;
    dictUnitAtmoMaxValue["O3"][3]=79;
    dictUnitAtmoMaxValue["O3"][4]=104;
    dictUnitAtmoMaxValue["O3"][5]=129;
    dictUnitAtmoMaxValue["O3"][6]=149;
    dictUnitAtmoMaxValue["O3"][7]=179;
    dictUnitAtmoMaxValue["O3"][8]=209;
    dictUnitAtmoMaxValue["O3"][9]=239;
    dictUnitAtmoMaxValue["O3"][10]=INT_MAX;


    //SO2
    dictUnitAtmoMaxValue["SO2"][1]=39;
    dictUnitAtmoMaxValue["SO2"][2]=79;
    dictUnitAtmoMaxValue["SO2"][3]=119;
    dictUnitAtmoMaxValue["SO2"][4]=159;
    dictUnitAtmoMaxValue["SO2"][5]=199;
    dictUnitAtmoMaxValue["SO2"][6]=249;
    dictUnitAtmoMaxValue["SO2"][7]=299;
    dictUnitAtmoMaxValue["SO2"][8]=399;
    dictUnitAtmoMaxValue["SO2"][9]=499;
    dictUnitAtmoMaxValue["SO2"][10]=INT_MAX;


    //NO2
    dictUnitAtmoMaxValue["NO2"][1]=29;
    dictUnitAtmoMaxValue["NO2"][2]=54;
    dictUnitAtmoMaxValue["NO2"][3]=84;
    dictUnitAtmoMaxValue["NO2"][4]=109;
    dictUnitAtmoMaxValue["NO2"][5]=134;
    dictUnitAtmoMaxValue["NO2"][6]=164;
    dictUnitAtmoMaxValue["NO2"][7]=199;
    dictUnitAtmoMaxValue["NO2"][8]=274;
    dictUnitAtmoMaxValue["NO2"][9]=399;
    dictUnitAtmoMaxValue["NO2"][10]=INT_MAX;


    //PM10
    dictUnitAtmoMaxValue["PM10"][1]=6;
    dictUnitAtmoMaxValue["PM10"][2]=13;
    dictUnitAtmoMaxValue["PM10"][3]=20;
    dictUnitAtmoMaxValue["PM10"][4]=27;
    dictUnitAtmoMaxValue["PM10"][5]=34;
    dictUnitAtmoMaxValue["PM10"][6]=41;
    dictUnitAtmoMaxValue["PM10"][7]=49;
    dictUnitAtmoMaxValue["PM10"][8]=64;
    dictUnitAtmoMaxValue["PM10"][9]=79;
    dictUnitAtmoMaxValue["PM10"][10]=INT_MAX;


}








