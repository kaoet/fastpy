#pragma once

#include "type.h"
#include "int.h"

namespace range {

value __init__(value stop);
value __init__(value start, value stop, value step = int_::make(1));
value __iter__(value self);

}