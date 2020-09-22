#ifndef SUBJECT_H
#define SUBJECT_H
#include <list>
#include <memory>
#include <type_traits>
#include "observer.h"
using namespace std;
template<typename C>
class Subject
{
public:
    //Subject() = default;
    virtual ~Subject(){}



    void registerObserver(shared_ptr<Observer<C>> o)
    {
        ob_ls.push_back(o);
        o->meme = --(ob_ls.end());
    }

    bool removeObserver(shared_ptr<Observer<C>> o)
    {
        ob_ls.erase(o->meme); return true;
    }

    void notifyObservers()
    {
        for(auto &i : ob_ls)
            i->update(reinterpret_cast<C&>(*this));//Its safe to do cuz we`re guranted to be the base of C
    }


protected:
    list<shared_ptr<Observer<C>> > ob_ls;
};

class WeatherData : public Subject<WeatherData>
{
    static_assert ( is_default_constructible<Subject<WeatherData>>::value );
public:
    WeatherData() = default;
    void setMeasures(float f0, float f1, float f2)
    {
        tem = f0; hum = f1; press = f2;
        notifyObservers();
    }

    auto getTemperature() const {return tem;}
    auto getHumidity() const {return tem;}
    auto getPressure() const {return tem;}


private:
    float tem, hum, press;//preSS
};

#endif // SUBJECT_H
