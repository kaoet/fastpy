#include "range.h"
#include "assert.h"
#include "range_iterator.h"

namespace range {

value make(long start, long stop, long step) {
  value ret;
  ret.type = value::RANGE;
  ret.rangeval = new range_t{start, stop, step};
  return ret;
}

value __iter__(value self) {
  assert(self.type == value::RANGE);
  return range_iterator::make(self.rangeval);
}
}