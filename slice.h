#pragma once

#include "type.h"
#include "int.h"

namespace slice {
    
value __init__(value stop);
value __init__(value start, value stop, value step=int_::make(1));

}