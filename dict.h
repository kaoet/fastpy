#pragma once

#include "type.h"

namespace dict {
    
value make();
value __getitem__(value self, value k);
void __setitem__(value self, value k, value v);
value __contains__(value self, value k);
void __delitem__(value self, value k);
value __bool__(value self);
value __eq__(value x, value y);
value __ne__(value x, value y);

}