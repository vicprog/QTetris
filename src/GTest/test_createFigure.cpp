#include "Stdafx.h"

#include <CreateFigure.h>

#include "mock_random.h"

class CreateFigureFixture: public Test
{
public:
  void SetUp()
  {
    size = 20;
  }

protected:
  NiceMock<MockRandom> niceRandom;

  StrictMock<MockRandom> strictRandom;

  quint8 size;
};

TEST_F(CreateFigureFixture, shouldCreate)
{
  CCreateFigure createFigure(nullptr, size);
}

TEST_F(CreateFigureFixture, shouldGetGeneratedNumberWhenCreateFigure)
{
  // Given
  CCreateFigure createFigure(&strictRandom, size);

  // Expected
  EXPECT_CALL(strictRandom, generate()).WillOnce(Return(1));

  // When
  createFigure.create();
}

TEST_F(CreateFigureFixture, shouldCreateFigure1WhenCreate)
{
  // Given
  ON_CALL(niceRandom, generate()).WillByDefault(Return(0));
  CCreateFigure createFigure(&niceRandom, size);

  // When
  CFigurePtr spFigure = createFigure.create();

  // Then
  ASSERT_EQ(4, spFigure->elem.size());
  EXPECT_EQ(QPoint(size/2 - 1, 0), spFigure->elem[0].pos());
  EXPECT_EQ(QPoint(size/2, 0), spFigure->elem[1].pos());
  EXPECT_EQ(QPoint(size/2 -1, 1), spFigure->elem[2].pos());
  EXPECT_EQ(QPoint(size/2, 1), spFigure->elem[3].pos());
}

TEST_F(CreateFigureFixture, shouldCreateFigure2WhenCreate)
{
  // Given
  ON_CALL(niceRandom, generate()).WillByDefault(Return(1));
  CCreateFigure createFigure(&niceRandom, size);

  // When
  CFigurePtr spFigure = createFigure.create();

  // Then
  ASSERT_EQ(4, spFigure->elem.size());
  EXPECT_EQ(QPoint(size/2 - 1, 0), spFigure->elem[0].pos());
  EXPECT_EQ(QPoint(size/2, 0), spFigure->elem[1].pos());
  EXPECT_EQ(QPoint(size/2, 1), spFigure->elem[2].pos());
  EXPECT_EQ(QPoint(size/2 + 1, 1), spFigure->elem[3].pos());
}

TEST_F(CreateFigureFixture, shouldCreateFigure3WhenCreate)
{
  // Given
  ON_CALL(niceRandom, generate()).WillByDefault(Return(2));
  CCreateFigure createFigure(&niceRandom, size);

  // When
  CFigurePtr spFigure = createFigure.create();

  // Then
  ASSERT_EQ(4, spFigure->elem.size());
  EXPECT_EQ(QPoint(size/2, 0), spFigure->elem[0].pos());
  EXPECT_EQ(QPoint(size/2 + 1, 0), spFigure->elem[1].pos());
  EXPECT_EQ(QPoint(size/2 - 1, 1), spFigure->elem[2].pos());
  EXPECT_EQ(QPoint(size/2, 1), spFigure->elem[3].pos());
}

TEST_F(CreateFigureFixture, shouldCreateFigure4WhenCreate)
{
  // Given
  ON_CALL(niceRandom, generate()).WillByDefault(Return(3));
  CCreateFigure createFigure(&niceRandom, size);

  // When
  CFigurePtr spFigure = createFigure.create();

  // Then
  ASSERT_EQ(4, spFigure->elem.size());
  EXPECT_EQ(QPoint(size/2 - 1, 0), spFigure->elem[0].pos());
  EXPECT_EQ(QPoint(size/2, 0), spFigure->elem[1].pos());
  EXPECT_EQ(QPoint(size/2, 1), spFigure->elem[2].pos());
  EXPECT_EQ(QPoint(size/2, 2), spFigure->elem[3].pos());
}

TEST_F(CreateFigureFixture, shouldCreateFigure5WhenCreate)
{
  // Given
  ON_CALL(niceRandom, generate()).WillByDefault(Return(4));
  CCreateFigure createFigure(&niceRandom, size);

  // When
  CFigurePtr spFigure = createFigure.create();

  // Then
  ASSERT_EQ(4, spFigure->elem.size());
  EXPECT_EQ(QPoint(size/2 - 1, 0), spFigure->elem[0].pos());
  EXPECT_EQ(QPoint(size/2, 0), spFigure->elem[1].pos());
  EXPECT_EQ(QPoint(size/2 - 1, 1), spFigure->elem[2].pos());
  EXPECT_EQ(QPoint(size/2 - 1, 2), spFigure->elem[3].pos());
}

TEST_F(CreateFigureFixture, shouldCreateFigure6WhenCreate)
{
  // Given
  ON_CALL(niceRandom, generate()).WillByDefault(Return(5));
  CCreateFigure createFigure(&niceRandom, size);

  // When
  CFigurePtr spFigure = createFigure.create();

  // Then
  ASSERT_EQ(4, spFigure->elem.size());
  EXPECT_EQ(QPoint(size/2 - 1, 0), spFigure->elem[0].pos());
  EXPECT_EQ(QPoint(size/2 - 1, 1), spFigure->elem[1].pos());
  EXPECT_EQ(QPoint(size/2 - 1, 2), spFigure->elem[2].pos());
  EXPECT_EQ(QPoint(size/2 - 1, 3), spFigure->elem[3].pos());
}
