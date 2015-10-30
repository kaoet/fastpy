#pragma once

#include "type.h"

value make$float_(double v=0.0);

value __add__$float_$float_(value x, value y);
value __sub__$float_$float_(value x, value y);
value __mul__$float_$float_(value x, value y);
value __truediv__$float_$float_(value x, value y);
value __mod__$float_$float_(value x, value y);
value __eq__$float_$float_(value x, value y);
value __ne__$float_$float_(value x, value y);
value __lt__$float_$float_(value x, value y);
value __le__$float_$float_(value x, value y);
value __ge__$float_$float_(value x, value y);
value __gt__$float_$float_(value x, value y);
value __bool__$float_(value self);
