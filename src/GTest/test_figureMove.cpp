#include "Stdafx.h"

#include <FigureMove.h>
#include <Figure.h>

#include "mock_tetris.h"

class FigureMoveFixture: public Test
{
public:
  FigureMoveFixture()
    : elem0(QPoint(1, 0))
    , elem1(QPoint(2, 0))
    , elem2(QPoint(1, 1))
    , elem3(QPoint(2, 1))
  {}

  QPoint left(CElement& element)
  {
    QPoint pos(element.pos());
    --pos.rx();
    return pos;
  }

  QPoint right(CElement& element)
  {
    QPoint pos(element.pos());
    ++pos.rx();
    return pos;
  }

  QPoint down(CElement& element)
  {
    QPoint pos(element.pos());
    ++pos.ry();
    return pos;
  }

  void SetUp()
  {
    spFigure.reset(new CFigure);
    spFigure->elem.push_back(elem0);
    spFigure->elem.push_back(elem1);
    spFigure->elem.push_back(elem2);
    spFigure->elem.push_back(elem3);

  }

protected:

  StrictMock<MockTetris> strictTetris;
  NiceMock<MockTetris> niceTetris;

  Sequence s;
  CFigurePtr spFigure;
  CElement elem0;
  CElement elem1;
  CElement elem2;
  CElement elem3;
};

TEST_F(FigureMoveFixture, shouldCreate)
{
  CFigureMove figureMove(nullptr);
}

TEST_F(FigureMoveFixture, shouldTestPosWhenMoveLeft)
{
  // Given
  CFigureMove figureMove(&strictTetris);

  // Expected
  EXPECT_CALL(strictTetris, testPos(left(elem0))).InSequence(s).WillOnce(Return(true));
  EXPECT_CALL(strictTetris, testPos(left(elem1))).InSequence(s).WillOnce(Return(true));
  EXPECT_CALL(strictTetris, testPos(left(elem2))).InSequence(s).WillOnce(Return(true));
  EXPECT_CALL(strictTetris, testPos(left(elem3))).InSequence(s).WillOnce(Return(true));

  // When
  figureMove.left(spFigure.data());
}

TEST_F(FigureMoveFixture, shouldMoveLeftFigureWhenMoveLeft)
{
  // Given
  ON_CALL(niceTetris, testPos(_)).WillByDefault(Return(true));

  CFigureMove figureMove(&niceTetris);

  // When
  bool ret = figureMove.left(spFigure.data());

  // Then
  ASSERT_TRUE(ret);
  ASSERT_EQ(left(elem0), spFigure->elem[0].pos());
  ASSERT_EQ(left(elem1), spFigure->elem[1].pos());
  ASSERT_EQ(left(elem2), spFigure->elem[2].pos());
  ASSERT_EQ(left(elem3), spFigure->elem[3].pos());
}

TEST_F(FigureMoveFixture, shouldNotMoveLeftFigureWhenMoveLeft)
{
  // Given
  ON_CALL(niceTetris, testPos(_)).WillByDefault(Return(false));

  CFigureMove figureMove(&niceTetris);

  // When
  bool ret = figureMove.left(spFigure.data());

  // Then
  ASSERT_FALSE(ret);
  ASSERT_EQ(elem0.pos(), spFigure->elem[0].pos());
  ASSERT_EQ(elem1.pos(), spFigure->elem[1].pos());
  ASSERT_EQ(elem2.pos(), spFigure->elem[2].pos());
  ASSERT_EQ(elem3.pos(), spFigure->elem[3].pos());
}

TEST_F(FigureMoveFixture, shouldTestPosWhenMoveRight)
{
  // Given
  CFigureMove figureMove(&strictTetris);

  // Expected
  EXPECT_CALL(strictTetris, testPos(right(elem0))).InSequence(s).WillOnce(Return(true));
  EXPECT_CALL(strictTetris, testPos(right(elem1))).InSequence(s).WillOnce(Return(true));
  EXPECT_CALL(strictTetris, testPos(right(elem2))).InSequence(s).WillOnce(Return(true));
  EXPECT_CALL(strictTetris, testPos(right(elem3))).InSequence(s).WillOnce(Return(true));

  // When
  figureMove.right(spFigure.data());
}

TEST_F(FigureMoveFixture, shouldMoveRightFigureWhenMoveRight)
{
  // Given
  ON_CALL(niceTetris, testPos(_)).WillByDefault(Return(true));

  CFigureMove figureMove(&niceTetris);

  // When
  bool ret = figureMove.right(spFigure.data());

  // Then
  ASSERT_TRUE(ret);
  ASSERT_EQ(right(elem0), spFigure->elem[0].pos());
  ASSERT_EQ(right(elem1), spFigure->elem[1].pos());
  ASSERT_EQ(right(elem2), spFigure->elem[2].pos());
  ASSERT_EQ(right(elem3), spFigure->elem[3].pos());
}

TEST_F(FigureMoveFixture, shouldNotMoveRightFigureWhenMoveRight)
{
  // Given
  ON_CALL(niceTetris, testPos(_)).WillByDefault(Return(false));

  CFigureMove figureMove(&niceTetris);

  // When
  bool ret = figureMove.right(spFigure.data());

  // Then
  ASSERT_FALSE(ret);
  ASSERT_EQ(elem0.pos(), spFigure->elem[0].pos());
  ASSERT_EQ(elem1.pos(), spFigure->elem[1].pos());
  ASSERT_EQ(elem2.pos(), spFigure->elem[2].pos());
  ASSERT_EQ(elem3.pos(), spFigure->elem[3].pos());
}

TEST_F(FigureMoveFixture, shouldTestPosWhenMoveDown)
{
  // Given
  CFigureMove figureMove(&strictTetris);

  // Expected
  EXPECT_CALL(strictTetris, testPos(down(elem0))).InSequence(s).WillOnce(Return(true));
  EXPECT_CALL(strictTetris, testPos(down(elem1))).InSequence(s).WillOnce(Return(true));
  EXPECT_CALL(strictTetris, testPos(down(elem2))).InSequence(s).WillOnce(Return(true));
  EXPECT_CALL(strictTetris, testPos(down(elem3))).InSequence(s).WillOnce(Return(true));

  // When
  figureMove.down(spFigure.data());
}

