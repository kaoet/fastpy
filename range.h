#pragma once

#include "type.h"
#include "int.h"

value __init__$range$int_(value stop);
value __init__$range$int_$int_$int_(value start, value stop, value step = make$int_(1));
value __iter__$range(value self);
