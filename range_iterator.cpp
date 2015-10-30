#include "range_iterator.h"
#include "assert.h"
#include "none.h"
#include "int.h"
    
value make$range_iterator(range_t *rng) {
    value ret;
    ret.type = value::RANGE_ITERATOR;
    ret.range_iteratorval = new range_iterator_t(*rng);
    return ret;
}

value __next__$range_iterator(value self) {
    assert(self.type == value::RANGE_ITERATOR);
    auto iter = self.range_iteratorval;
    if (iter->step >= 0 && iter->start < iter->stop || iter->step < 0 && iter->start > iter->stop) {
        value ret = make$int_(iter->start);
        iter->start += iter->step;
        return ret;
    } else {
        return make$none();
    }
}
