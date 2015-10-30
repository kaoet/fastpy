#pragma once

#include "type.h"
   
value make$bool_(bool v=false);

value __eq__$bool_$bool_(value x, value y);
value __ne__$bool_$bool_(value x, value y);
value __lt__$bool_$bool_(value x, value y);
value __le__$bool_$bool_(value x, value y);
value __gt__$bool_$bool_(value x, value y);
value __ge__$bool_$bool_(value x, value y);
value __bool__$bool_(value self);
value __int__$bool_(value self);
value __float__$bool_(value self);
value __and__$bool_$bool_(value x, value y);
value __or__$bool_$bool_(value x, value y);
value __xor__$bool_$bool_(value x, value y);
