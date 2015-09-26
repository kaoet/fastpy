#pragma once

#include "type.h"

namespace float_ {

value make(double v=0.0);

value __add__(value x, value y);
value __sub__(value x, value y);
value __mul__(value x, value y);
value __truediv__(value x, value y);
value __mod__(value x, value y);
value __eq__(value x, value y);
value __ne__(value x, value y);
value __bool__(value self);

}