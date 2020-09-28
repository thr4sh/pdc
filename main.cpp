#include <QApplication>

#include "decoyduck.h"

#include "character.h"

#include "subject.h"
#include "obsreal.h"

//STD INCLUDES
#include <memory>
#include <utility>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    unique_ptr<Duck> t(new DecoyDuck());

    t->display();
    t->fly();
    t->quack();

    unique_ptr<Character> p((new Knight()));

    p->setWeapon(make_unique<KnifeBehaviour>());

    p->fight();

    shared_ptr<WeatherData> wd(new WeatherData());
    //shared_ptr<CurCondsDisplay> ccd(new CurCondsDisplay(wd));
    shared_ptr<StatDisplay> st(new StatDisplay());

    wd->registerObserver(st);
    //wd->registerObserver(ccd);

    wd->setMeasures(882.f, 100.f, 1337.f);

    //wd->removeObserver(ccd);
    wd->removeObserver(st);
    return a.exec();
}
