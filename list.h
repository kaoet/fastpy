#pragma once

#include "type.h"

value make$list();
value append$list$(value self, value v);
value pop$list(value self);
value __getitem__$list$(value self, value k);
value __getitem__$list$int_(value self, value k);
value __getitem__$list$slice(value self, value k);
value __setitem__$list$$(value self, value k, value v);
value __setitem__$list$int_$(value self, value k, value v);
value __setitem__$list$slice$(value self, value k, value v);
value __add__$list$list(value x, value y);
value __mul__$list$int_(value self, value n);
value __mul__$int_$list(value n, value self);
value __mul__$list$bool_(value self, value n);
value __mul__$bool_$list(value n, value self);
value __len__$list(value self);
value __eq__$list$list(value x, value y);
value __ne__$list$list(value x, value y);
value __lt__$list$list(value x, value y);
value __le__$list$list(value x, value y);
value __ge__$list$list(value x, value y);
value __gt__$list$list(value x, value y);
value __contains__$list$(value self, value v);
value __delitem__$list$int_(value self, value k);
value __delitem__$list$slice(value self, value k);
value __bool__$list(value self);
value __iter__$list(value self);

