#pragma once

#include "type.h"


value make$set();
value add$set$(value self, value v);
value remove$set$(value self, value v);
value __contains__$set$(value self, value v);
value __bool__$set(value self);
value __len__$set(value self);
value __eq__$set$set(value x, value y);
value __ne__$set$set(value x, value y);
value __lt__$set$set(value x, value y);
value __le__$set$set(value x, value y);
value __ge__$set$set(value x, value y);
value __gt__$set$set(value x, value y);
