#pragma once

#include "type.h"
#include "int.h"
   
value slice$int_(value stop);
value slice$int_$int_(value start, value stop);
value slice$int_$int_$int_(value start, value stop, value step);
