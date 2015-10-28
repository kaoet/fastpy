#include "list_iterator.h"
#include "assert.h"
#include "none.h"
#include "int.h"

namespace list_iterator {
    
value make(list_t *lst) {
    value ret;
    ret.type = value::LIST_ITERATOR;
    ret.list_iteratorval = new list_iterator_t{lst, 0};
    return ret;
}

value __next__(value self) {
    assert(self.type == value::LIST_ITERATOR);
    auto iter = self.list_iteratorval;
    if (iter->index < iter->list->size()) {
        return (*iter->list)[iter->index++];
    } else {
        return none::make();
    }
}

}