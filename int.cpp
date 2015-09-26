#include <cassert>
#include "int.h"
#include "float.h"
#include "bool.h"

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

value __bool__(value self) {
    assert(self.type == value::INT);
    return bool_::make(self.intval != 0);
}

}