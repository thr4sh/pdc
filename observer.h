#ifndef OBSERVER_H
#define OBSERVER_H
#include <memory>
#include <list>
#include "display.h"
template<typename C>
class Subject;
template<typename C>
class Observer
{
private:
    typename std::list<std::shared_ptr<Observer>>::iterator meme;
public:
    using sub_t = C;
    friend Subject<C>;
    virtual ~Observer(){}
    void virtual update(const sub_t &)= 0;
};


#endif // OBSERVER_H
