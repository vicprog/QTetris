#pragma once

#include <QPoint>

#include "Interface.h"

Interface ITetris
{
  virtual bool testPos(const QPoint&) = 0;
};
