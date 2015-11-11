#pragma once

#include "type.h"
#include "int.h"

value range$int_(value stop);
value range$int_$int_(value start, value stop);
value range$int_$int_$int_(value start, value stop, value step);
value __iter__$range(value self);
