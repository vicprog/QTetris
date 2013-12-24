#pragma once

#include "ITetris.h"

struct MockTetris: public ITetris
{
  MOCK_METHOD1(testPos, bool(const QPoint&));
};
