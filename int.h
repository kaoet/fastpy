#pragma once

#include "type.h"

namespace int_ {

value make(long v=0);

value __add__(value x, value y);
value __sub__(value x, value y);
value __mul__(value x, value y);
value __truediv__(value x, value y);
value __mod__(value x, value y);
value __float__(value self);
value __eq__(value x, value y);
value __ne__(value x, value y);
value __bool__(value self);
}