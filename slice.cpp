#include "slice.h"
#include "assert.h"

namespace slice {
value __init__(value stop) {
  return __init__(int_::make(0), stop, int_::make(1));
}

value __init__(value start, value stop, value step) {
  assert(start.type == value::INT && stop.type == value::INT &&
         step.type == value::INT);

  if (step.intval == 0)
      throw std::runtime_error("slice step must not be zero");
  value ret;
  ret.type = value::SLICE;
  ret.sliceval = new slice_t{start.intval, stop.intval, step.intval};
  return ret;
}
}