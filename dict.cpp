#include "dict.h"
#include "bool.h"
#include "int.h"
#include "assert.h"
#include "none.h"
#include "dict_iterator.h"
    
value make$dict() {
    value ret;
    ret.type = value::DICT;
    ret.dictval = new dict_t();
    return ret;
}

value __getitem__$dict$(value self, value k) {
    assert(self.type == value::DICT);
    auto it = self.dictval->find(k);
    if (it == self.dictval->end()) {
        throw std::runtime_error("key error");
    }
    return it->second;
}

value __setitem__$dict$$(value self, value k, value v) {
    assert(self.type == value::DICT);
    (*self.dictval)[k] = v;
    return make$none();
}

value __contains__$dict$(value self, value k) {
    assert(self.type == value::DICT);
    return make$bool_(self.dictval->find(k) != self.dictval->end());
}

value __delitem__$dict$(value self, value k) {
    assert(self.type == value::DICT);
    self.dictval->erase(k);
    return make$none();
}

value __bool__$dict(value self) {
    assert(self.type == value::DICT);
    return make$bool_(!self.dictval->empty());
}

value __len__$dict(value self) {
    assert(self.type == value::DICT);
    return make$int_(self.dictval->size());
}

value __eq__$dict$dict(value x, value y) {
    assert(x.type == value::DICT && y.type == value::DICT);
    return make$bool_(*x.dictval == *y.dictval);
}

value __ne__$dict$dict(value x, value y) {
    assert(x.type == value::DICT && y.type == value::DICT);
    return make$bool_(*x.dictval != *y.dictval);
}

value __iter__$dict(value self) {
    assert(self.type == value::DICT);
    return make$dict_iterator(self.dictval);
}
