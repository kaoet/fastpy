#include "dict.h"
#include "bool.h"
#include "int.h"
#include "assert.h"

namespace dict {
    
value make() {
    value ret;
    ret.type = value::DICT;
    ret.dictval = new dict_t();
    return ret;
}

value __getitem__(value self, value k) {
    assert(self.type == value::DICT);
    auto it = self.dictval->find(k);
    if (it == self.dictval->end()) {
        throw std::runtime_error("key error");
    }
    return it->second;
}

void __setitem__(value self, value k, value v) {
    assert(self.type == value::DICT);
    (*self.dictval)[k] = v;
}

value __contains__(value self, value k) {
    assert(self.type == value::DICT);
    return bool_::make(self.dictval->find(k) != self.dictval->end());
}

void __delitem__(value self, value k) {
    assert(self.type == value::DICT);
    self.dictval->erase(k);
}

value __bool__(value self) {
    assert(self.type == value::DICT);
    return bool_::make(!self.dictval->empty());
}

value __len__(value self) {
    assert(self.type == value::DICT);
    return int_::make(self.dictval->size());
}

value __eq__(value x, value y) {
    assert(x.type == value::DICT && y.type == value::DICT);
    return bool_::make(*x.dictval == *y.dictval);
}

value __ne__(value x, value y) {
    assert(x.type == value::DICT && y.type == value::DICT);
    return bool_::make(*x.dictval != *y.dictval);
}

}