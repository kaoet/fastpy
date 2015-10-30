#include "set.h"
#include "bool.h"
#include "int.h"
#include "assert.h"
#include "none.h"
  
value make$set() {
    value ret;
    ret.type = value::SET;
    ret.setval = new set_t();
    return ret;
}

value add$set$(value self, value v) {
    assert(self.type == value::SET);
    self.setval->insert(v);
    return make$set();
}

value remove$set$(value self, value v) {
    assert(self.type == value::SET);
    auto it = self.setval->find(v);
    if (it == self.setval->end())
        throw std::runtime_error("key error");
    self.setval->erase(it);
    return make$set();
}

value __contains__$set$(value self, value v) {
    assert(self.type == value::SET);
    return make$int_(self.setval->find(v) != self.setval->end());
}

value __bool__$set(value self) {
    assert(self.type == value::SET);
    return make$int_(!self.setval->empty());
}

value __len__$set(value self) {
    assert(self.type == value::SET);
    return make$int_(self.setval->size());
}

value __eq__$set$set(value x, value y) {
    assert(x.type == value::SET && y.type == value::SET);
    return make$int_(*x.setval == *y.setval);
}

value __ne__$set$set(value x, value y) {
    assert(x.type == value::SET && y.type == value::SET);
    return make$int_(*x.setval != *y.setval);
}

value __lt__$set$set(value x, value y) {
    assert(x.type == value::SET && y.type == value::SET);
    
    if (x.setval->size() >= y.setval->size())
        return make$int_(false);
    
    for (value v : *x.setval) {
        if (y.setval->find(v) == y.setval->end())
            return make$int_(false);
    }
    return make$int_(true);
}

value __le__$set$set(value x, value y) {
    assert(x.type == value::SET && y.type == value::SET);
    
    if (x.setval->size() > y.setval->size())
        return make$int_(false);
    
    for (value v : *x.setval) {
        if (y.setval->find(v) == y.setval->end())
            return make$int_(false);
    }
    return make$int_(true);
}

value __ge__$set$set(value x, value y) {
    return __le__$set$set(y, x);
}

value __gt__$set$set(value x, value y) {
    return __lt__$set$set(y, x);
}
