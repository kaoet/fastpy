#include "int.h"
#include "float.h"
#include "bool.h"
#include "assert.h"

value make$int_(long v) {
    value ret;
    ret.type = value::INT;
    ret.intval = v;
    return ret;
}

value __add__$int_$int_(value x, value y) {
    assert(x.type == value::INT && y.type == value::INT);
    return make$int_(x.intval + y.intval);
}

value __sub__$int_$int_(value x, value y) {
    assert(x.type == value::INT && y.type == value::INT);
    return make$int_(x.intval - y.intval);
}

value __mul__$int_$int_(value x, value y) {
    assert(x.type == value::INT && y.type == value::INT);
    return make$int_(x.intval * y.intval);
}

value __mod__$int_$int_(value x, value y) {
    assert(x.type == value::INT && y.type == value::INT);
    return make$int_(x.intval % y.intval);
}

value __float__$int_(value self) {
    assert(self.type == value::INT);
    return make$float_(self.intval);
}

value __eq__$int_$int_(value x, value y) {
    assert(x.type == value::INT && y.type == value::INT);
    return make$bool_(x.intval == y.intval);
}

value __ne__$int_$int_(value x, value y) {
    assert(x.type == value::INT && y.type == value::INT);
    return make$bool_(x.intval != y.intval);
}

value __lt__$int_$int_(value x, value y) {
    assert(x.type == value::INT && y.type == value::INT);
    return make$bool_(x.intval < y.intval);
}

value __le__$int_$int_(value x, value y) {
    assert(x.type == value::INT && y.type == value::INT);
    return make$bool_(x.intval <= y.intval);
}

value __ge__$int_$int_(value x, value y) {
    assert(x.type == value::INT && y.type == value::INT);
    return make$bool_(x.intval >= y.intval);
}

value __gt__$int_$int_(value x, value y) {
    assert(x.type == value::INT && y.type == value::INT);
    return make$bool_(x.intval > y.intval);
}

value __bool__$int_(value self) {
    assert(self.type == value::INT);
    return make$bool_(self.intval != 0);
}

value __and__$int_$int_(value x, value y) {
    assert(x.type == value::INT && y.type == value::INT);
    return make$int_(x.intval & y.intval);
}

value __or__$int_$int_(value x, value y) {
    assert(x.type == value::INT && y.type == value::INT);
    return make$int_(x.intval | y.intval);
}

value __xor__$int_$int_(value x, value y) {
    assert(x.type == value::INT && y.type == value::INT);
    return make$int_(x.intval ^ y.intval);
}

value __invert__$int_(value self) {
    assert(self.type == value::INT);
    return make$int_(~self.intval);
}

value __lshift__$int_$int_(value x, value y) {
    assert(x.type == value::INT && y.type == value::INT);
    return make$int_(x.intval << y.intval);
}

value __rshift__$int_$int_(value x, value y) {
    assert(x.type == value::INT && y.type == value::INT);
    return make$int_(x.intval >> y.intval);
}
