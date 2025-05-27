#include "../Model/Coordinates.h"
#include <cmath>
#include <stdio.h>  
using namespace std;


float distance(Coordinates c1, Coordinates c2){
    return sqrt(pow(c1.getLatitude()-c2.getLatitude(),2)+pow(c1.getLongitude()-c2.getLongitude(),2));
}

int main(){
    Coordinates c1(56,42.3);
    Coordinates c2(56,43.3);
    printf("%f",distance(c1,c2));
    return 0;

}