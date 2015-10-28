#include "set_iterator.h"
#include "assert.h"
#include "none.h"
#include "int.h"

namespace set_iterator {
    
value make(set_t *set) {
    value ret;
    ret.type = value::SET_ITERATOR;
    ret.set_iteratorval = new set_iterator_t{set->cbegin(), set->cend()};
    return ret;
}

value __next__(value self) {
    assert(self.type == value::SET_ITERATOR);
    auto iter = self.set_iteratorval;
    if (iter->cur != iter->end) {
        return *iter->cur++;
    } else {
        return none::make();
    }
}

}