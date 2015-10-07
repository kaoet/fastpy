#include "bool.h"
#include "int.h"
#include "float.h"
#include "assert.h"

namespace bool_ {

value make(bool v) {
  value ret;
  ret.type = value::BOOL;
  ret.boolval = v;
  return ret;
}

value __eq__(value x, value y) {
  assert(x.type == value::BOOL && y.type == value::BOOL);
  return make(x.boolval == y.boolval);
}

value __ne__(value x, value y) {
  assert(x.type == value::BOOL && y.type == value::BOOL);
  return make(x.boolval != y.boolval);
}

value __lt__(value x, value y) {
  assert(x.type == value::BOOL && y.type == value::BOOL);
  return make(x.boolval < y.boolval);
}

value __le__(value x, value y) {
  assert(x.type == value::BOOL && y.type == value::BOOL);
  return make(x.boolval <= y.boolval);
}

value __ge__(value x, value y) {
  assert(x.type == value::BOOL && y.type == value::BOOL);
  return make(x.boolval >= y.boolval);
}

value __gt__(value x, value y) {
  assert(x.type == value::BOOL && y.type == value::BOOL);
  return make(x.boolval > y.boolval);
}

value __bool__(value self) {
  assert(self.type == value::BOOL);
  return self;
}

value __int__(value self) {
  assert(self.type == value::BOOL);
  return int_::make(self.boolval? 1: 0);
}

value __float__(value self) {
  assert(self.type == value::BOOL);
  return float_::make(self.boolval? 1.0: 0.0);
}

value __and__(value x, value y) {
    assert(x.type == value::BOOL && y.type == value::BOOL);
    return make(x.boolval & y.boolval);
}

value __or__(value x, value y) {
    assert(x.type == value::BOOL && y.type == value::BOOL);
    return make(x.boolval | y.boolval);
}

value __xor__(value x, value y) {
    assert(x.type == value::BOOL && y.type == value::BOOL);
    return make(x.boolval ^ y.boolval);
}

}