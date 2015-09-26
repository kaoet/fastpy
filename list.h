#pragma once

#include "type.h"

namespace list {

value make(size_t size=0);

void append(value self, value v);
value pop(value self);
value __getitem__(value self, value k);
void __setitem__(value self, value k, value v);
value __add__(value x, value y);
value __mul__(value self, value n);
value __len__(value self);
value __eq__(value x, value y);
value __ne__(value x, value y);
value __contains__(value self, value v);
void __delitem__(value self, value k);
value __bool__(value self);

}