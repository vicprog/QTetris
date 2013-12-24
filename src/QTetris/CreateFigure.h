#pragma once

#include "Interface.h"
#include "Figure.h"

Interface IRandom;

class CCreateFigure
{
public:
  CCreateFigure(IRandom*, quint8 size);

  CFigurePtr create();

private:
  IRandom* m_pRandom;
  quint8 m_size;
};
