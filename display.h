#ifndef DISPLAY_H
#define DISPLAY_H


//QT trash
#include <QWidget>
#include <QLCDNumber>
#include <QLabel>

class Display
{
public:
    Display();
    void virtual DisplayStuff() = 0;
};

#endif // DISPLAY_H
