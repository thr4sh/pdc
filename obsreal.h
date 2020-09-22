#ifndef TTT_H
#define TTT_H
#include "subject.h"
#include <numeric>
#include <random>
class CurCondsDisplay : public Observer<WeatherData>, public Display
{
private:
    float tem = 0, hum =0 , preSS = 0;
    shared_ptr<WeatherData> wd;
public:
    CurCondsDisplay() = default;
    CurCondsDisplay(const CurCondsDisplay&) = default;
    CurCondsDisplay(shared_ptr<WeatherData> c) :  wd(c)  {}
    void update(const sub_t &);
    void DisplayStuff();
};

class StatDisplay : public Observer<WeatherData>, public Display
{
private:
    int upd_i = 0;
    float avtem = 0, avhum = 0, avpreSS = 0;
    float mintem = numeric_limits<float>::max(), minhum = numeric_limits<float>::max(), minpreSS = numeric_limits<float>::max();
    float maxtem = numeric_limits<float>::lowest(), maxhum = numeric_limits<float>::lowest(), maxpreSS = numeric_limits<float>::lowest();
public:
    void update(const sub_t &);
    void DisplayStuff();
};

class ForecastDisplay : public Observer<WeatherData>, public Display
{
public:
    void update(const sub_t &) {};
    void DisplayStuff();
};

#endif // TTT_H
