#include "obsreal.h"
#include <iostream>
using namespace std;
void CurCondsDisplay::update(const sub_t &wet)
{
    tem = wet.getTemperature();
    hum = wet.getHumidity();
    preSS = wet.getPressure();

    DisplayStuff();
}

void CurCondsDisplay::DisplayStuff()
{
    cout << "Just checkin': "
         << "\nTemperature - " << tem
         << "\nHumidity - " << hum
         << "\nPressure - " << preSS
         <<"\n";
}

void StatDisplay::update(const sub_t &wet)
{
    upd_i++;
    avtem +=wet.getTemperature(), avhum += wet.getHumidity(), avpreSS += wet.getPressure();
    avtem /= float(upd_i), avhum /= float(upd_i), avpreSS /= float(upd_i);
    mintem = min(mintem, wet.getTemperature()), minhum = min(minhum, wet.getHumidity()), minpreSS = min(minpreSS, wet.getPressure());
    maxtem = max(maxtem, wet.getTemperature()), maxhum = max(maxhum, wet.getHumidity()),  maxpreSS = max(maxpreSS, wet.getPressure());

    DisplayStuff();
}

void StatDisplay::DisplayStuff()
{
    cout << "Temperature : avg - " << avtem << " max - " << maxtem << " min - " << mintem
         <<"\nHumidity : avg - " << avhum << " max - " << maxhum << " min - " << mintem
        <<"\nPressure : avg - " << avpreSS << " max - " << maxpreSS << " min - " << minpreSS << "\n";
}

void ForecastDisplay::DisplayStuff() { cout << "We're all gon to die so whenever\n";}
