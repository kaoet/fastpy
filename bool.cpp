#include "bool.h"
#include "int.h"
#include "float.h"
#include "assert.h"

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
