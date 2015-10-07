#pragma once

#include "type.h"

namespace range {

value make(long start, long stop, long step);
value __iter__(value self);

}