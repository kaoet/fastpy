#pragma once

#include "type.h"

namespace none {
    
value make();
value __bool__(value self);
value __eq__(value x, value y);
value __ne__(value x, value y);

}