#pragma once

#include "type.h"

value make$int_(long v=0);

value __add__$int_$int_(value x, value y);
value __sub__$int_$int_(value x, value y);
value __mul__$int_$int_(value x, value y);
value __mod__$int_$int_(value x, value y);
value __float__$int_(value self);
value __eq__$int_$int_(value x, value y);
value __ne__$int_$int_(value x, value y);
value __lt__$int_$int_(value x, value y);
value __le__$int_$int_(value x, value y);
value __ge__$int_$int_(value x, value y);
value __gt__$int_$int_(value x, value y);
value __bool__$int_(value self);
value __and__$int_$int_(value x, value y);
value __or__$int_$int_(value x, value y);
value __xor__$int_$int_(value x, value y);
value __invert__$int_(value self);
value __lshift__$int_$int_(value x, value y);
value __rshift__$int_$int_(value x, value y);
