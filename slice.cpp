#include "slice.h"
#include "assert.h"

value __init__$slice$int_(value stop) {
  return __init__$slice$int_$int_$int_(make$int_(0), stop, make$int_(1));
}

value __init__$slice$int_$int_$int_(value start, value stop, value step) {
  assert(start.type == value::INT && stop.type == value::INT &&
         step.type == value::INT);

  if (step.intval == 0)
      throw std::runtime_error("slice step must not be zero");
  value ret;
  ret.type = value::SLICE;
  ret.sliceval = new slice_t{start.intval, stop.intval, step.intval};
  return ret;
}
