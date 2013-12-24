#include "Element.h"

CElement::CElement(QPoint pos)
  : m_pos(pos)
{
}

QPoint& CElement::pos()
{
  return m_pos;
}
