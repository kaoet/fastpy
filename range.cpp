#include "range.h"
#include "assert.h"
#include "range_iterator.h"

value range$int_(value stop) {
    return range$int_$int_$int_(make$int_(0), stop, make$int_(1));
}

value range$int_$int_(value start, value stop) {
  return range$int_$int_$int_(start, stop, make$int_(1));
}

value range$int_$int_$int_(value start, value stop, value step) {
  assert(start.type == value::INT && stop.type == value::INT && step.type == value::INT);
  
  if (step.intval == 0)
      throw std::runtime_error("range step must not be zero");
  value ret;
  ret.type = value::RANGE;
  ret.rangeval = new range_t{start.intval, stop.intval, step.intval};
  return ret;
}

value __iter__$range(value self) {
  assert(self.type == value::RANGE);
  return make$range_iterator(self.rangeval);
}
