#pragma once

#include "type.h"

namespace list {

value make();

value append(value self, value v);
value pop(value self);
value __getitem__(value self, value k);
value __setitem__(value self, value k, value v);
value __add__(value x, value y);
value __mul__(value self, value n);
value __len__(value self);
value __eq__(value x, value y);
value __ne__(value x, value y);
value __lt__(value x, value y);
value __le__(value x, value y);
value __ge__(value x, value y);
value __gt__(value x, value y);
value __contains__(value self, value v);
value __delitem__(value self, value k);
value __bool__(value self);

}