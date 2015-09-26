#include <stdexcept>
#include <cassert>
#include "list.h"
#include "int.h"
#include "bool.h"
#include "func.h"

namespace list {

value make() {
    value ret;
    ret.type = value::LIST;
    ret.listval = new list_t();
    return ret;
}

void append(value self, value v) {
    assert(self.type == value::LIST);
    self.listval->push_back(v);
}

value pop(value self) {
    assert(self.type == value::LIST);
    value ret = self.listval->back();
    self.listval->pop_back();
    return ret;
}

value __getitem__(value self, value k) {
    assert(self.type == value::LIST && k.type == value::INT);
    return self.listval->at(k.intval);
}

void __setitem__(value self, value k, value v) {
    assert(self.type == value::LIST && k.type == value::INT);
    self.listval->at(k.intval) = v;
}

value __add__(value x, value y) {
    assert(x.type == value::LIST && y.type == value::LIST);
    
    list_t *merged = new list_t();
    merged->reserve(x.listval->size() + y.listval->size());
    merged->insert(merged->end(), x.listval->begin(), x.listval->end());
    merged->insert(merged->end(), y.listval->begin(), y.listval->end());
    
    value ret;
    ret.type = value::LIST;
    ret.listval = merged;
    return ret;
}

value __mul__(value self, value n) {
    assert(self.type == value::LIST && n.type == value::INT);
    
    list_t *duped = new list_t();
    if (n.intval > 0) {
        duped->reserve(self.listval->size() * n.intval);
        for (long i = 0; i < n.intval; i++)
            duped->insert(duped->end(), self.listval->begin(), self.listval->end());
    }
    
    value ret;
    ret.type = value::LIST;
    ret.listval = duped;
    return ret;
}

value __len__(value self) {
    assert(self.type == value::LIST);
    return int_::make(self.listval->size());
}

value __eq__(value x, value y) {
    assert(x.type == value::LIST && y.type == value::LIST);
    return bool_::make(*x.listval == *y.listval);
}

value __ne__(value x, value y) {
    assert(x.type == value::LIST && y.type == value::LIST);
    return bool_::make(*x.listval != *y.listval);
}

value __contains__(value self, value v) {
    assert(self.type == value::LIST);
    
    for (size_t i = 0; i < self.listval->size(); i++)
        if ((*self.listval)[i] == v)
            return bool_::make(true);
    return bool_::make(false);
}

void __delitem__(value self, value k) {
    assert(self.type == value::LIST && k.type == value::INT);
    self.listval->erase(self.listval->begin() + k.intval);
}

value __bool__(value self) {
    assert(self.type == value::LIST);
    return bool_::make(!self.listval->empty());
}

}