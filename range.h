#pragma once

#include "type.h"

namespace range {

value make(long stop);
value make(long start, long stop, long step = 1);
value __iter__(value self);

}