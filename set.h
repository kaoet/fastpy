#pragma once

#include "type.h"

namespace set {
    
value make();
value add(value self, value v);
value remove(value self, value v);
value __contains__(value self, value v);
value __bool__(value self);
value __len__(value self);
value __eq__(value x, value y);
value __ne__(value x, value y);
value __lt__(value x, value y);
value __le__(value x, value y);
value __ge__(value x, value y);
value __gt__(value x, value y);

}