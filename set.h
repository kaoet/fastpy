#pragma once

#include "type.h"

namespace set {
    
value make();
void add(value self, value v);
void remove(value self, value v);
value __contains__(value self, value v);
value __bool__(value self);
value __eq__(value x, value y);
value __ne__(value x, value y);

}