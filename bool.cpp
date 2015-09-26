#include <cassert>
#include "bool.h"
#include "int.h"
#include "float.h"

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

value __bool__(value self) {
  assert(self.type == value::BOOL);
  return self;
}

value __int__(value self) {
  assert(self.type == value::BOOL);
  return int_::make(1);
}

value __float__(value self) {
  assert(self.type == value::BOOL);
  return float_::make(1.0);
}

}