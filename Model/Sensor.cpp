#include <string>
#include <ctime>


class Sensor{
   public:
       list<Date> getMeasurementTimestamps(){


       }
       Coordinates getCoordinates(){
           return coordinates;
       }
       int calculateAtmoIndex(Date timeStamp = time()){
           int sizeMeasurementList = sizeof(measurements)/sizeof(Measurement);
           int atmo_final = 0;
           map<int,int> dictMaxValAtmo;
           for(int i=0;i<sizeMeasurementList;++i){
               if (measurement[i].getTimestamp==timeStamp){
                   for(int j=0;j<4;++j){
                       dictMaxValAtmo = dictUnitMaxValueAtmo[measurement[i+j].getAttribute().getUnit()];
                       for(int atmo=1;atmo<=10;++atmo){
                           if(dictMaxValAtmo[atmo]>= ((int)measurement[i+j].getValue()) && atmo>1){
                               atmo_final=max(atmo_final,atmo);
                               break;
                           }
                       }
                   }
               }
           }
           return atmo_final;
       }
       boolean hasMeasurementAtTime(Date timeStamp){


       }


       //boolean addMeasurement(Measurement measurement)??
       Sensor(string sensor_ID, float latitudeInit, float longitudeInit){
           sensorID = sensor_ID;
           coordinates.latitude = latitudeInit;
           coordinates.longitude = longitudeInit;
           initDictUnit();
       }
       ~Sensor(){}


   private :
       string sensorID;
       string ownerID;
       Coordinates coordinates;
       list<Measurement> measurements;
       PrivateIndividual privateIndividual;
       map<string,map<int,int>> dictUnitAtmoMaxValue;
       void initDictUnit(){
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
           dictUnitAtmoMaxValue["PM10"][3]=20
           dictUnitAtmoMaxValue["PM10"][4]=27;
           dictUnitAtmoMaxValue["PM10"][5]=34;
           dictUnitAtmoMaxValue["PM10"][6]=41;
           dictUnitAtmoMaxValue["PM10"][7]=49;
           dictUnitAtmoMaxValue["PM10"][8]=64;
           dictUnitAtmoMaxValue["PM10"][9]=79;
           dictUnitAtmoMaxValue["PM10"][10]=INT_MAX;


       }




}



