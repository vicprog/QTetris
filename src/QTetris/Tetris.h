#pragma once

#include "ITetris.h"
#include "ITimer.h"
#include "IController.h"

#include "Figure.h"

class CTetris: public ITetris, public ITimer, public IController
{
public:
    CTetris();

    bool testPos(const QPoint&);

    void addFigure(CFigurePtr);
private:

};
