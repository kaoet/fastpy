#include "set.h"
#include "bool.h"
#include "int.h"
#include "assert.h"
#include "none.h"
#include "set_iterator.h"

namespace set {
    
value make() {
    value ret;
    ret.type = value::SET;
    ret.setval = new set_t();
    return ret;
}

value add(value self, value v) {
    assert(self.type == value::SET);
    self.setval->insert(v);
    return none::make();
}

value remove(value self, value v) {
    assert(self.type == value::SET);
    auto it = self.setval->find(v);
    if (it == self.setval->end())
        throw std::runtime_error("key error");
    self.setval->erase(it);
    return none::make();
}

value __contains__(value self, value v) {
    assert(self.type == value::SET);
    return bool_::make(self.setval->find(v) != self.setval->end());
}

value __bool__(value self) {
    assert(self.type == value::SET);
    return bool_::make(!self.setval->empty());
}

value __len__(value self) {
    assert(self.type == value::SET);
    return int_::make(self.setval->size());
}

value __eq__(value x, value y) {
    assert(x.type == value::SET && y.type == value::SET);
    return bool_::make(*x.setval == *y.setval);
}

value __ne__(value x, value y) {
    assert(x.type == value::SET && y.type == value::SET);
    return bool_::make(*x.setval != *y.setval);
}

value __lt__(value x, value y) {
    assert(x.type == value::SET && y.type == value::SET);
    
    if (x.setval->size() >= y.setval->size())
        return bool_::make(false);
    
    for (value v : *x.setval) {
        if (y.setval->find(v) == y.setval->end())
            return bool_::make(false);
    }
    return bool_::make(true);
}

value __le__(value x, value y) {
    assert(x.type == value::SET && y.type == value::SET);
    
    if (x.setval->size() > y.setval->size())
        return bool_::make(false);
    
    for (value v : *x.setval) {
        if (y.setval->find(v) == y.setval->end())
            return bool_::make(false);
    }
    return bool_::make(true);
}

value __ge__(value x, value y) {
    return set::__le__(y, x);
}

value __gt__(value x, value y) {
    return set::__lt__(y, x);
}

value __iter__(value self) {
    assert(self.type == value::SET);
    return set_iterator::make(self.setval);
}

}