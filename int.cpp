#include "int.h"
#include "float.h"
#include "bool.h"
#include "assert.h"

namespace int_ {

value make(long v) {
    value ret;
    ret.type = value::INT;
    ret.intval = v;
    return ret;
}

value __add__(value x, value y) {
    assert(x.type == value::INT && y.type == value::INT);
    return make(x.intval + y.intval);
}

value __sub__(value x, value y) {
    assert(x.type == value::INT && y.type == value::INT);
    return make(x.intval - y.intval);
}

value __mul__(value x, value y) {
    assert(x.type == value::INT && y.type == value::INT);
    return make(x.intval * y.intval);
}

value __truediv__(value x, value y) {
    assert(x.type == value::INT && y.type == value::INT);
    return float_::make((double) x.intval / (double) y.intval);
}

value __mod__(value x, value y) {
    assert(x.type == value::INT && y.type == value::INT);
    return make(x.intval % y.intval);
}

value __float__(value self) {
    assert(self.type == value::INT);
    return float_::make(self.intval);
}

value __eq__(value x, value y) {
    assert(x.type == value::INT && y.type == value::INT);
    return bool_::make(x.intval == y.intval);
}

value __ne__(value x, value y) {
    assert(x.type == value::INT && y.type == value::INT);
    return bool_::make(x.intval != y.intval);
}

value __lt__(value x, value y) {
    assert(x.type == value::INT && y.type == value::INT);
    return bool_::make(x.intval < y.intval);
}

value __le__(value x, value y) {
    assert(x.type == value::INT && y.type == value::INT);
    return bool_::make(x.intval <= y.intval);
}

value __ge__(value x, value y) {
    assert(x.type == value::INT && y.type == value::INT);
    return bool_::make(x.intval >= y.intval);
}

value __gt__(value x, value y) {
    assert(x.type == value::INT && y.type == value::INT);
    return bool_::make(x.intval > y.intval);
}

value __bool__(value self) {
    assert(self.type == value::INT);
    return bool_::make(self.intval != 0);
}

value __and__(value x, value y) {
    assert(x.type == value::INT && y.type == value::INT);
    return make(x.intval & y.intval);
}

value __or__(value x, value y) {
    assert(x.type == value::INT && y.type == value::INT);
    return make(x.intval | y.intval);
}

value __xor__(value x, value y) {
    assert(x.type == value::INT && y.type == value::INT);
    return make(x.intval ^ y.intval);
}

value __invert__(value self) {
    assert(self.type == value::INT);
    return make(~self.intval);
}

value __lshift__(value x, value y) {
    assert(x.type == value::INT && y.type == value::INT);
    return make(x.intval << y.intval);
}

value __rshift__(value x, value y) {
    assert(x.type == value::INT && y.type == value::INT);
    return make(x.intval >> y.intval);
}

}