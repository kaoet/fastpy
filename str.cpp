#include <algorithm>
#include "str.h"
#include "int.h"
#include "bool.h"
#include "assert.h"

value make$str(const char *v) {
  value ret;
  ret.type = value::STR;
  ret.strval = new str_t(v);
  return ret;
}

value __getitem__$str$(value self, value k) {
  assert(self.type == value::STR);
  switch (k.type) {
  case value::INT:
    return __getitem__$str$int_(self, k);
  case value::SLICE: 
    return __getitem__$str$slice(self, k);
  }
  throw std::runtime_error("Illegal argument type for str::__getitem__");
}

value __getitem__$str$int_(value self, value k) {
  return value{.type = value::STR,
                 .strval = new str_t(1, self.strval->at(k.intval))};
}

value __getitem__$str$slice(value self, value k) {
  long start = k.sliceval->start;
  long stop = k.sliceval->stop;
  long step = k.sliceval->step;
  if (start < 0)
    start = (long)self.strval->size() + start;
  if (stop < 0)
    stop = (long)self.strval->size() + stop;

  str_t *ret = new str_t();
  if (step > 0) {
    start = std::max(0L, start);
    stop = std::min((long)self.strval->size(), stop);
    for (long i = start; i < stop; i += step) {
      ret->push_back(self.strval->at(i));
    }
  } else {
    start = std::min((long)self.strval->size() - 1L, start);
    stop = std::max(-1L, stop);
    for (long i = start; i > stop; i += step) {
      ret->push_back(self.strval->at(i));
    }
  }

  return value{.type = value::STR, .strval = ret};
}

value __len__$str(value self) {
  assert(self.type == value::STR);
  return make$int_(self.strval->size());
}

value __add__$str$str(value x, value y) {
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


value __mul__$str$bool_(value self, value n) {
  assert(self.type == value::STR && n.type == value::BOOL);
  return __mul__$str$int_(self, __int__$bool_(n));
}
value __mul__$bool_$str(value n, value self) {
  assert(self.type == value::STR && n.type == value::BOOL);
  return __mul__$int_$str(__int__$bool_(n), self);
}

value __mul__$int_$str(value n, value self) {
  assert(self.type == value::STR && n.type == value::INT);
  return __mul__$str$int_(self, n);
}

value __mul__$str$int_(value self, value n) {
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

value __eq__$str$str(value x, value y) {
  assert(x.type == value::STR && y.type == value::STR);
  return make$bool_(*x.strval == *y.strval);
}

value __ne__$str$str(value x, value y) {
  assert(x.type == value::STR && y.type == value::STR);
  return make$bool_(*x.strval != *y.strval);
}

value __lt__$str$str(value x, value y) {
  assert(x.type == value::STR && y.type == value::STR);
  return make$bool_(*x.strval < *y.strval);
}

value __le__$str$str(value x, value y) {
  assert(x.type == value::STR && y.type == value::STR);
  return make$bool_(*x.strval <= *y.strval);
}

value __ge__$str$str(value x, value y) {
  assert(x.type == value::STR && y.type == value::STR);
  return make$bool_(*x.strval >= *y.strval);
}

value __gt__$str$str(value x, value y) {
  assert(x.type == value::STR && y.type == value::STR);
  return make$bool_(*x.strval > *y.strval);
}

value __contains__$str$str(value self, value sub) {
  assert(self.type == value::STR && sub.type == value::STR);
  return make$bool_(self.strval->find(*sub.strval) != std::string::npos);
}

value __bool__$str(value self) {
  assert(self.type == value::STR);
  return make$bool_(!self.strval->empty());
}
