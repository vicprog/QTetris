#pragma once

#include <IRandom.h>

struct MockRandom: public IRandom
{
  MOCK_METHOD0(generate, int());
};
