#include "CreateFigure.h"

#include "IRandom.h"

static bool figures[][4] = {
  // figure 1
  0, 1, 1, 0,
  0, 1, 1, 0,
  0, 0, 0, 0,
  0, 0, 0, 0,

  // figure 2
  0, 1, 1, 0,
  0, 0, 1, 1,
  0, 0, 0, 0,
  0, 0, 0, 0,

  // figure 3
  0, 0, 1, 1,
  0, 1, 1, 0,
  0, 0, 0, 0,
  0, 0, 0, 0,

  // figure 4
  0, 1, 1, 0,
  0, 0, 1, 0,
  0, 0, 1, 0,
  0, 0, 0, 0,

  // figure 5
  0, 1, 1, 0,
  0, 1, 0, 0,
  0, 1, 0, 0,
  0, 0, 0, 0,

  // figure 6
  0, 1, 0, 0,
  0, 1, 0, 0,
  0, 1, 0, 0,
  0, 1, 0, 0,

};
CCreateFigure::CCreateFigure(IRandom* pRandom, quint8 size)
  : m_pRandom(pRandom)
  , m_size(size)
{
}

CFigurePtr CCreateFigure::create()
{
  CFigurePtr spFigure(new CFigure());
  int figureNumber = m_pRandom->generate();
  for (int y = figureNumber * 4; y < (figureNumber +1) * 4; ++y)
    for (int x = 0; x < 4; ++x)
      if (figures[y][x])
        spFigure->elem.push_back(CElement(QPoint(m_size / 2 + x - 2, y - figureNumber * 4)));

  return spFigure;
}
