#pragma once

#include "type.h"

value make$dict();
value __getitem__$dict$(value self, value k);
value __setitem__$dict$$(value self, value k, value v);
value __contains__$dict$(value self, value k);
value __delitem__$dict$(value self, value k);
value __bool__$dict(value self);
value __len__$dict(value self);
value __eq__$dict$dict(value x, value y);
value __ne__$dict$dict(value x, value y);
