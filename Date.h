#ifndef DATE_H
#define DATE_H

#include <string>
using namespace std; 

//throw invalid_argument("Fecha invalida");

//La clase Date contiene varios variables y funciones que pertenecen a una fecha
class Date {
private:
    //Variables:
    int year;
    int month;
    int day;
    string alternate; //Dia alternativo

public:
    //Constructores:
    Date();
    Date(int aYear, int aMonth, int aDay);
    Date(int aYear, int aMonth, int aDay, string altDay);

    //Funciones
    bool valid(int year, int month, int day);
    bool same(Date d);
    int dayofweek(int y, int m, int d);
    string getDayOfWeek();
};


#endif
