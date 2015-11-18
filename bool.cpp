#include "bool.h"
#include "int.h"
#include "float.h"
#include "assert.h"
#include "str.h"
#include "list.h"

value make$bool_(bool v) {
  value ret;
  ret.type = value::BOOL;
  ret.boolval = v;
  return ret;
}

value __eq__$bool_$bool_(value x, value y) {
  assert(x.type == value::BOOL && y.type == value::BOOL);
  return make$bool_(x.boolval == y.boolval);
}

value __ne__$bool_$bool_(value x, value y) {
  assert(x.type == value::BOOL && y.type == value::BOOL);
  return make$bool_(x.boolval != y.boolval);
}

value __lt__$bool_$bool_(value x, value y) {
  assert(x.type == value::BOOL && y.type == value::BOOL);
  return make$bool_(x.boolval < y.boolval);
}

value __le__$bool_$bool_(value x, value y) {
  assert(x.type == value::BOOL && y.type == value::BOOL);
  return make$bool_(x.boolval <= y.boolval);
}

value __ge__$bool_$bool_(value x, value y) {
  assert(x.type == value::BOOL && y.type == value::BOOL);
  return make$bool_(x.boolval >= y.boolval);
}

value __gt__$bool_$bool_(value x, value y) {
  assert(x.type == value::BOOL && y.type == value::BOOL);
  return make$bool_(x.boolval > y.boolval);
}

value __add__$bool_$bool_(value x, value y) {
  assert(x.type == value::BOOL && y.type == value::BOOL);
  return __add__$int_$int_(__int__$bool_(x), __int__$bool_(y));
}


value __truediv__$bool_$bool_(value x, value y) {
  assert(x.type == value::BOOL && y.type == value::BOOL);
  return __truediv__$int_$int_(__int__$bool_(x), __int__$bool_(y));
}


value __sub__$bool_$bool_(value x, value y) {
  assert(x.type == value::BOOL && y.type == value::BOOL);
  return __sub__$int_$int_(__int__$bool_(x), __int__$bool_(y));
}


value __mul__$bool_$bool_(value x, value y) {
  assert(x.type == value::BOOL && y.type == value::BOOL);
  return __mul__$int_$int_(__int__$bool_(x), __int__$bool_(y));
}

value __mod__$bool_$bool_(value x, value y) {
  assert(x.type == value::BOOL && y.type == value::BOOL);
  return __mod__$int_$int_(__int__$bool_(x), __int__$bool_(y));
}
value __lshift__$bool_$bool_(value x, value y) {
  assert(x.type == value::BOOL && y.type == value::BOOL);
  return __lshift__$int_$int_(__int__$bool_(x), __int__$bool_(y));
}
value __rshift__$bool_$bool_(value x, value y) {
  assert(x.type == value::BOOL && y.type == value::BOOL);
  return __rshift__$int_$int_(__int__$bool_(x), __int__$bool_(y));
}

value __invert__$bool_(value x) {
  assert(x.type == value::BOOL);
  return __invert__$int_(__int__$bool_(x));
}

value __bool__$bool_(value self) {
  assert(self.type == value::BOOL);
  return self;
}

value __int__$bool_(value self) {
  assert(self.type == value::BOOL);
  return make$int_(self.boolval? 1: 0);
}

value __float__$bool_(value self) {
  assert(self.type == value::BOOL);
  return make$float_(self.boolval? 1.0: 0.0);
}

value __and__$bool_$bool_(value x, value y) {
    assert(x.type == value::BOOL && y.type == value::BOOL);
    return make$bool_(x.boolval & y.boolval);
}

value __or__$bool_$bool_(value x, value y) {
    assert(x.type == value::BOOL && y.type == value::BOOL);
    return make$bool_(x.boolval | y.boolval);
}

value __xor__$bool_$bool_(value x, value y) {
    assert(x.type == value::BOOL && y.type == value::BOOL);
    return make$bool_(x.boolval ^ y.boolval);
}
