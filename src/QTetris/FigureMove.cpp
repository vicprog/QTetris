#include "FigureMove.h"

#include "ITetris.h"
#include "Figure.h"

CFigureMove::CFigureMove(ITetris* pTetris)
  : m_pTetris(pTetris)
{
}

bool CFigureMove::left(CFigure* pFigure)
{
  for (auto it = pFigure->elem.begin(); it != pFigure->elem.end(); ++it)
  {
    QPoint pos(it->pos());
    --pos.rx();
    if (!m_pTetris->testPos(pos))
      return false;
  }
  for (auto it = pFigure->elem.begin(); it != pFigure->elem.end(); ++it)
    --it->pos().rx();
  return true;
}

bool CFigureMove::right(CFigure* pFigure)
{
  for (auto it = pFigure->elem.begin(); it != pFigure->elem.end(); ++it)
  {
    QPoint pos(it->pos());
    ++pos.rx();
    if (!m_pTetris->testPos(pos))
      return false;
  }
  for (auto it = pFigure->elem.begin(); it != pFigure->elem.end(); ++it)
    ++it->pos().rx();
  return true;
}

bool CFigureMove::down(CFigure* pFigure)
{
  for (auto it = pFigure->elem.begin(); it != pFigure->elem.end(); ++it)
  {
    QPoint pos(it->pos());
    ++pos.ry();
    if (!m_pTetris->testPos(pos))
      return false;
  }
  for (auto it = pFigure->elem.begin(); it != pFigure->elem.end(); ++it)
    ++it->pos().ry();
  return true;
}
