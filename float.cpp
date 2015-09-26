#include <cassert>
#include "float.h"
#include "bool.h"

namespace float_ {

value make(double v) {
    value ret;
    ret.type = value::FLOAT;
    ret.floatval = v;
    return ret;
}

value __add__(value x, value y) {
    assert(x.type == value::FLOAT && y.type == value::FLOAT);
    return make(x.floatval + y.floatval);
}

value __sub__(value x, value y) {
    assert(x.type == value::FLOAT && y.type == value::FLOAT);
    return make(x.floatval - y.floatval);
}

value __mul__(value x, value y) {
    assert(x.type == value::FLOAT && y.type == value::FLOAT);
    return make(x.floatval * y.floatval);
}

value __truediv__(value x, value y) {
    assert(x.type == value::FLOAT && y.type == value::FLOAT);
    return make(x.floatval / y.floatval);
}

value __mod__(value x, value y) {
    assert(x.type == value::FLOAT && y.type == value::FLOAT);
    return make(fmod(x.floatval, y.floatval));
}

value __eq__(value x, value y) {
    assert(x.type == value::FLOAT && y.type == value::FLOAT);
    return bool_::make(x.floatval == y.floatval);
}

value __ne__(value x, value y) {
    assert(x.type == value::FLOAT && y.type == value::FLOAT);
    return bool_::make(x.floatval != y.floatval);
}

value __lt__(value x, value y) {
    assert(x.type == value::FLOAT && y.type == value::FLOAT);
    return bool_::make(x.floatval < y.floatval);
}

value __le__(value x, value y) {
    assert(x.type == value::FLOAT && y.type == value::FLOAT);
    return bool_::make(x.floatval <= y.floatval);
}

value __ge__(value x, value y) {
    assert(x.type == value::FLOAT && y.type == value::FLOAT);
    return bool_::make(x.floatval >= y.floatval);
}

value __gt__(value x, value y) {
    assert(x.type == value::FLOAT && y.type == value::FLOAT);
    return bool_::make(x.floatval > y.floatval);
}

value __bool__(value self) {
    assert(self.type == value::FLOAT);
    return bool_::make(self.floatval != 0.0);
}

}