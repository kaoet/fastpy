#pragma once

#include "type.h"

namespace str {
    
value make(const char *v="");
value __getitem__(value self, value k);
value __len__(value self);
value __add__(value x, value y);
value __mul__(value self, value n);
value __eq__(value x, value y);
value __ne__(value x, value y);
value __lt__(value x, value y);
value __le__(value x, value y);
value __ge__(value x, value y);
value __gt__(value x, value y);
value __contains__(value self, value sub);
value __bool__(value self);

}