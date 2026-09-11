//Daniel Aviles Gerena
//NUM ESTUDIANTE: 801-24-5453

#include "Date.h"
#include <stdexcept>
#include <iostream>

using namespace std;

//Constructor con la Fecha 1903-01-01 (January 1, 1903)
Date::Date() {
    year = 1903;
    month = 1;
    day = 1;
    alternate = "";
}
// Este constructor recibe el año, mes y día
Date::Date(int aYear, int aMonth, int aDay)
    {
        //Esta funcion verifica si la fecha es valida
        if (valid(aYear, aMonth, aDay))
        {
            year = aYear;
            month = aMonth;
            day = aDay;
            alternate = "";
        }
        else {
            throw invalid_argument("Fecha invalida"); //Si no tira un invalid argument
        }

    }
//Este constructor ahora recibe altDay que es un dia alterno
Date::Date(int aYear, int aMonth, int aDay, string altDay)

    {
        
        if (valid(aYear, aMonth, aDay))
        {
            year = aYear;
            month = aMonth;
            day = aDay;
            alternate = altDay;
        }
        else {
            throw invalid_argument("Fecha invalida"); 
        }
        
    }

//La funcion valid verifica si la fecha es valida
bool Date::valid(int aYear, int aMonth, int aDay)
    {
        
        if (aYear < 1903)
        {
            return false;
        }


        if (aMonth < 1 || aMonth > 12)
        {
            return false;
        }
        //Un arreglo de la cantidad de dias en cada mes(no incluyendo anos biseito)
        int dias[] = {
            31, 28, 31, 30, 31, 30,
            31, 31, 30, 31, 30, 31};

        if ((aYear % 400 == 0) || (aYear % 4 == 0 && aYear % 100 != 0)) //Verifica si el ano es biseito
        {
            dias[1] = 29;
        }

        return aDay >= 1 && aDay <= dias[aMonth - 1]; //Esto verifica si el dia es valido

        }

//Esta funcion compara dos fechas para ver si son iguales
//No tienen que tener el mismo altDay
bool Date::same(Date D) {
        if(D.day == day && D.year == year && D.month == month)
        {
            return true;
        }
        else {
            return false;
        }
    }

//Busca para el dia de la semana usando un algoritmo
int Date::dayofweek(int y, int m, int d)
/* 1 <= m <= 12, y > 1752 (in the U.K.), or 1582 (in Spain) */
    {
        static int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
        if ( m < 3 )
        {
            y -= 1;
        }
        return (y + y/4 - y/100 + y/400 + t[m-1] + d) % 7;
    }

string Date::getDaysoftheweek(){
        
        //Se cree un arreglo de todos los dias en la semana
        string arr[7] = {"domingo" , "lunes" , "martes","miércoles", "jueves" , "viernes", "sábado"};
    
        //Un for loop para iterar sobre el arreglo
        for(int i = 0; i < 7; i++)
        {
            if(i == dayofweek(year, month, day)) //Cuando ponemos una fecha en dayofweek comparamos lo que devuelve con el i que esta iterando
                {
                if(alternate != arr[i]) //Verifica si la fecha tiene un dia alternativo
                {
                    return arr[i] + "pero se reunen las clases de los" + alternate;
                }
                else {
                    return arr[i];
                }
            }
    }

    }
