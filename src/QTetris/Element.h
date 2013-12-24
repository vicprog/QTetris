#pragma once

#include <QPoint>

class CElement
{
public:
  CElement(QPoint = QPoint());
  QPoint& pos();

private:
  QPoint m_pos;
};
