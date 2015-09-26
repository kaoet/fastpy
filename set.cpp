#include <cassert>
#include "set.h"
#include "bool.h"

namespace set {
    
value make() {
    value ret;
    ret.type = value::SET;
    ret.setval = new set_t();
    return ret;
}

void add(value self, value v) {
    assert(self.type == value::SET);
    self.setval->insert(v);
}

void remove(value self, value v) {
    assert(self.type == value::SET);
    auto it = self.setval->find(v);
    if (it == self.setval->end())
        throw std::runtime_error("key error");
    self.setval->erase(it);
}

value __contains__(value self, value v) {
    assert(self.type == value::SET);
    return bool_::make(self.setval->find(v) != self.setval->end());
}

value __bool__(value self) {
    assert(self.type == value::SET);
    return bool_::make(!self.setval->empty());
}

value __eq__(value x, value y) {
    assert(x.type == value::SET && y.type == value::SET);
    return bool_::make(*x.setval == *y.setval);
}

value __ne__(value x, value y) {
    assert(x.type == value::SET && y.type == value::SET);
    return bool_::make(*x.setval != *y.setval);
}

}