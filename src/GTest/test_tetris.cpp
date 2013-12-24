#include "Stdafx.h"

#include <Tetris.h>

TEST(TetrisTest, shouldCreate)
{
  CTetris tetris;
}

TEST(TetrisTest, shouldAddFigure)
{
  // Given
  CFigurePtr spFigure(new CFigure);
  CTetris tetris;

  // When
  tetris.addFigure(spFigure);
}
