#include "obsreal.h"
#include <iostream>
using namespace std;

CurCondsDisplay::CurCondsDisplay(shared_ptr<WeatherData> c)
{
    wd = c;
    this->setGeometry(100, 100, 200, 200);
    this->setWindowTitle("Текущие значения");

    temp = new QLabel(this);
    temp->setText("Температура:");
    temp->setGeometry(10,10, 90, 30);
    temp->setParent(this);
    tempLCD = new QLCDNumber(this);
    tempLCD->setGeometry(100, 10, 40, 30);
    tempLCD->setPalette(Qt::green);
    tempLCD->setParent(this);

    humd = new QLabel(this);
    humd->setText("Влажность:");
    humd->setGeometry(10,60, 190, 30);
    humd->setParent(this);
    humLCD = new QLCDNumber(this);
    humLCD->setGeometry(100, 60, 40, 30);
    humLCD->setPalette(Qt::green);
    humLCD->setParent(this);

    press = new QLabel(this);
    press->setText("Давление:");
    press->setGeometry(10,110, 190, 30);
    press->setParent(this);
    pressLCD = new QLCDNumber(this);
    pressLCD->setGeometry(100, 110, 40, 30);
    pressLCD->setPalette(Qt::green);
    pressLCD->setParent(this);
}
void CurCondsDisplay::update(const sub_t &wet)
{
    tem = wet.getTemperature();
    hum = wet.getHumidity();
    preSS = wet.getPressure();

    this->show();
    DisplayStuff();
}

void CurCondsDisplay::DisplayStuff()
{
    cout << "Just checkin': "
         << "\nTemperature - " << tem
         << "\nHumidity - " << hum
         << "\nPressure - " << preSS
         <<"\n";


    tempLCD->display(QString::number(tem));
    humLCD->display(QString::number(hum));
    pressLCD->display(QString::number(preSS));
}


StatDisplay::StatDisplay()
{
    this->setGeometry(100, 100, 400, 400);
    this->setWindowTitle("Статистика значений");


    qavtemp = new QLabel(this);
    qavtemp->setText("Ср. Температура:");
    qavtemp->setGeometry(10,10, 100, 30);
    qavtemp->setParent(this);
    qavtempLCD = new QLCDNumber(this);
    qavtempLCD->setGeometry(110, 10, 40, 30);
    qavtempLCD->setPalette(Qt::green);
    qavtempLCD->setParent(this);

    qmintemp = new QLabel(this);
    qmintemp->setText("Мин. Температура:");
    qmintemp->setGeometry(10,50, 100, 30);
    qmintemp->setParent(this);
    qmintempLCD = new QLCDNumber(this);
    qmintempLCD->setGeometry(110, 50, 40, 30);
    qmintempLCD->setPalette(Qt::green);
    qmintempLCD->setParent(this);

    qmaxtemp = new QLabel(this);
    qmaxtemp->setText("Макс. Температура:");
    qmaxtemp->setGeometry(10,90, 100, 30);
    qmaxtemp->setParent(this);
    qmaxtempLCD = new QLCDNumber(this);
    qmaxtempLCD->setGeometry(110, 90, 40, 30);
    qmaxtempLCD->setPalette(Qt::green);
    qmaxtempLCD->setParent(this);


    qavhumd = new QLabel(this);
    qavhumd->setText("Ср. Влажность:");
    qavhumd->setGeometry(10,130, 190, 30);
    qavhumd->setParent(this);
    qavhumdLCD = new QLCDNumber(this);
    qavhumdLCD->setGeometry(110, 130, 40, 30);
    qavhumdLCD->setPalette(Qt::green);
    qavhumdLCD->setParent(this);

    qminhumd = new QLabel(this);
    qminhumd->setText("Мин. Влажность:");
    qminhumd->setGeometry(10,170, 100, 30);
    qminhumd->setParent(this);
    qminhumdLCD = new QLCDNumber(this);
    qminhumdLCD->setGeometry(110, 170, 40, 30);
    qminhumdLCD->setPalette(Qt::green);
    qminhumdLCD->setParent(this);

    qmaxhumd = new QLabel(this);
    qmaxhumd->setText("Макс. Влажность:");
    qmaxhumd->setGeometry(10,210, 100, 30);
    qmaxhumd->setParent(this);
    qmaxhumdLCD = new QLCDNumber(this);
    qmaxhumdLCD->setGeometry(110, 210, 40, 30);
    qmaxhumdLCD->setPalette(Qt::green);
    qmaxhumdLCD->setParent(this);


    qavpress = new QLabel(this);
    qavpress->setText("Ср. Давление:");
    qavpress->setGeometry(10,250, 190, 30);
    qavpress->setParent(this);
    qavpressLCD = new QLCDNumber(this);
    qavpressLCD->setGeometry(110, 250, 40, 30);
    qavpressLCD->setPalette(Qt::green);
    qavpressLCD->setParent(this);

    qminpress= new QLabel(this);
    qminpress->setText("Мин. Давление:");
    qminpress->setGeometry(10,290, 100, 30);
    qminpress->setParent(this);
    qminpressLCD = new QLCDNumber(this);
    qminpressLCD->setGeometry(110, 290, 40, 30);
    qminpressLCD->setPalette(Qt::green);
    qminpressLCD->setParent(this);

    qmaxpress = new QLabel(this);
    qmaxpress->setText("Макс. Давление:");
    qmaxpress->setGeometry(10,330, 100, 30);
    qmaxpress->setParent(this);
    qmaxpressLCD = new QLCDNumber(this);
    qmaxpressLCD->setGeometry(110, 330, 40, 30);
    qmaxpressLCD->setPalette(Qt::green);
    qmaxpressLCD->setParent(this);

    this->show();
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

    qavtempLCD->display(QString::number(avtem));
    qmintempLCD->display(QString::number(mintem));
    qmaxtempLCD->display(QString::number(maxtem));
    qavhumdLCD->display(QString::number(avhum));
    qminhumdLCD->display(QString::number(minhum));
    qmaxhumdLCD->display(QString::number(maxhum));
    qavpressLCD->display(QString::number(avpreSS));
    qminpressLCD->display(QString::number(minpreSS));
    qmaxpressLCD->display(QString::number(maxpreSS));
}

void ForecastDisplay::DisplayStuff() { cout << "We're all gon to die so whenever\n";}
