#include <cassert>
#include "str.h"
#include "int.h"
#include "bool.h"

namespace str {
    
value make(const char *v) {
    value ret;
    ret.type = value::STR;
    ret.strval = new str_t(v);
    return ret;
}

value __getitem__(value self, value k) {
    assert(self.type == value::STR && k.type == value::INT);
    value ret;
    ret.type = value::STR;
    ret.strval = new str_t(1, self.strval->at(k.intval));
    return ret;
}

value __len__(value self) {
    assert(self.type == value::STR);
    return int_::make(self.strval->size());
}

value __add__(value x, value y) {
    assert(x.type == value::STR && y.type == value::STR);
    
    str_t *merged = new str_t();
    merged->reserve(x.strval->size() + y.strval->size());
    merged->insert(merged->end(), x.strval->begin(), x.strval->end());
    merged->insert(merged->end(), y.strval->begin(), y.strval->end());
    
    value ret;
    ret.type = value::STR;
    ret.strval = merged;
    return ret; 
}

value __mul__(value self, value n) {
    assert(self.type == value::STR && n.type == value::INT);
    
    str_t *duped = new str_t();
    if (n.intval > 0) {
        duped->reserve(self.strval->size() * n.intval);
        for (long i = 0; i < n.intval; i++)
            duped->insert(duped->end(), self.strval->begin(), self.strval->end());
    }
    
    value ret;
    ret.type = value::STR;
    ret.strval = duped;
    return ret; 
}

value __eq__(value x, value y) {
    assert(x.type == value::STR && y.type == value::STR);
    return bool_::make(*x.strval == *y.strval);
}

value __ne__(value x, value y) {
    assert(x.type == value::STR && y.type == value::STR);
    return bool_::make(*x.strval != *y.strval);
}

value __lt__(value x, value y) {
    assert(x.type == value::STR && y.type == value::STR);
    return bool_::make(*x.strval < *y.strval);
}

value __le__(value x, value y) {
    assert(x.type == value::STR && y.type == value::STR);
    return bool_::make(*x.strval <= *y.strval);
}

value __ge__(value x, value y) {
    assert(x.type == value::STR && y.type == value::STR);
    return bool_::make(*x.strval >= *y.strval);
}

value __gt__(value x, value y) {
    assert(x.type == value::STR && y.type == value::STR);
    return bool_::make(*x.strval > *y.strval);
}

value __contains__(value self, value sub) {
    assert(self.type == value::STR && sub.type == value::STR);
    return bool_::make(self.strval->find(*sub.strval) != std::string::npos);
}

value __bool__(value self) {
    assert(self.type == value::STR);
    return bool_::make(!self.strval->empty());
}

}