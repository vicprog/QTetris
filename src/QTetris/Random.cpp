#include "Random.h"

#include <QtGlobal>

int CRandom::generate()
{
  return qrand() % 6;
}
