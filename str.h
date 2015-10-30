#pragma once

#include "type.h"

value make$str(const char *v="");
value __getitem__$str$(value self, value k);
value __getitem__$str$int_(value self, value k);
value __getitem__$str$slice(value self, value k);
value __len__$str(value self);
value __add__$str$str(value x, value y);
value __mul__$str$int_(value self, value n);
value __eq__$str$str(value x, value y);
value __ne__$str$str(value x, value y);
value __lt__$str$str(value x, value y);
value __le__$str$str(value x, value y);
value __ge__$str$str(value x, value y);
value __gt__$str$str(value x, value y);
value __contains__$str$str(value self, value sub);
value __bool__$str(value self);
