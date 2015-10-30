#include "dict_iterator.h"
#include "assert.h"
#include "none.h"
#include "int.h"
   
value make$dict_iterator(dict_t *dict) {
    value ret;
    ret.type = value::DICT_ITERATOR;
    ret.dict_iteratorval = new dict_iterator_t{dict->cbegin(), dict->cend()};
    return ret;
}

value __next__$dict_iterator(value self) {
    assert(self.type == value::DICT_ITERATOR);
    auto iter = self.dict_iteratorval;
    if (iter->cur != iter->end) {
        return (iter->cur++)->first;
    } else {
        return make$none();
    }
}
