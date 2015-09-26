#pragma once

#include "type.h"

namespace bool_ {
    
value make(bool v=false);

value __eq__(value x, value y);
value __ne__(value x, value y);
value __bool__(value self);
value __int__(value self);
value __float__(value self);

}