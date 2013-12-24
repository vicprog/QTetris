#pragma once

#include <QSharedPointer>
#include <QVector>

#include "Element.h"

class CFigure
{
public:
  CFigure();
  QVector<CElement> elem;
};

typedef QSharedPointer<CFigure> CFigurePtr;
