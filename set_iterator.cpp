#include "set_iterator.h"
#include "assert.h"
#include "none.h"
#include "int.h"
  
value make$set_iterator(set_t *set) {
    value ret;
    ret.type = value::SET_ITERATOR;
    ret.set_iteratorval = new set_iterator_t{set->cbegin(), set->cend()};
    return ret;
}

value __next__$set_iterator(value self) {
    assert(self.type == value::SET_ITERATOR);
    auto iter = self.set_iteratorval;
    if (iter->cur != iter->end) {
        return *iter->cur++;
    } else {
        return make$none();
    }
}
