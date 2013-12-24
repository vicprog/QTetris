#pragma once

#include "Interface.h"

Interface ITetris;
class CFigure;

class CFigureMove
{
public:
  CFigureMove(ITetris*);

  bool left(CFigure*);
  bool right(CFigure*);
  bool down(CFigure*);
  bool up();

private:
  ITetris* m_pTetris;
};
