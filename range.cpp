#include "range.h"
#include "assert.h"
#include "range_iterator.h"

namespace range {

value __init__(value stop) {
    return __init__(int_::make(0), stop, int_::make(1));
}

value __init__(value start, value stop, value step) {
  assert(start.type == value::INT && stop.type == value::INT && step.type == value::INT);
  
  if (step.intval == 0)
      throw std::runtime_error("range step must not be zero");
  value ret;
  ret.type = value::RANGE;
  ret.rangeval = new range_t{start.intval, stop.intval, step.intval};
  return ret;
}

value __iter__(value self) {
  assert(self.type == value::RANGE);
  return range_iterator::make(self.rangeval);
}
}