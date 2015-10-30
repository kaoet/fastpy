#include "float.h"
#include "bool.h"
#include "assert.h"

value make$float_(double v) {
    value ret;
    ret.type = value::FLOAT;
    ret.floatval = v;
    return ret;
}

value __add__$float_$float_(value x, value y) {
    assert(x.type == value::FLOAT && y.type == value::FLOAT);
    return make$float_(x.floatval + y.floatval);
}

value __sub__$float_$float_(value x, value y) {
    assert(x.type == value::FLOAT && y.type == value::FLOAT);
    return make$float_(x.floatval - y.floatval);
}

value __mul__$float_$float_(value x, value y) {
    assert(x.type == value::FLOAT && y.type == value::FLOAT);
    return make$float_(x.floatval * y.floatval);
}

value __truediv__$float_$float_(value x, value y) {
    assert(x.type == value::FLOAT && y.type == value::FLOAT);
    return make$float_(x.floatval / y.floatval);
}

value __mod__$float_$float_(value x, value y) {
    assert(x.type == value::FLOAT && y.type == value::FLOAT);
    return make$float_(fmod(x.floatval, y.floatval));
}

value __eq__$float_$float_(value x, value y) {
    assert(x.type == value::FLOAT && y.type == value::FLOAT);
    return make$bool_(x.floatval == y.floatval);
}

value __ne__$float_$float_(value x, value y) {
    assert(x.type == value::FLOAT && y.type == value::FLOAT);
    return make$bool_(x.floatval != y.floatval);
}

value __lt__$float_$float_(value x, value y) {
    assert(x.type == value::FLOAT && y.type == value::FLOAT);
    return make$bool_(x.floatval < y.floatval);
}

value __le__$float_$float_(value x, value y) {
    assert(x.type == value::FLOAT && y.type == value::FLOAT);
    return make$bool_(x.floatval <= y.floatval);
}

value __ge__$float_$float_(value x, value y) {
    assert(x.type == value::FLOAT && y.type == value::FLOAT);
    return make$bool_(x.floatval >= y.floatval);
}

value __gt__$float_$float_(value x, value y) {
    assert(x.type == value::FLOAT && y.type == value::FLOAT);
    return make$bool_(x.floatval > y.floatval);
}

value __bool__$float_(value self) {
    assert(self.type == value::FLOAT);
    return make$bool_(self.floatval != 0.0);
}
