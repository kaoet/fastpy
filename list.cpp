#include <stdexcept>
#include <algorithm>
#include "list.h"
#include "int.h"
#include "bool.h"
#include "func.h"
#include "assert.h"
#include "none.h"
#include "list_iterator.h"

value make$list() {
  value ret;
  ret.type = value::LIST;
  ret.listval = new list_t();
  return ret;
}

value append$list$(value self, value v) {
  assert(self.type == value::LIST);
  self.listval->push_back(v);
  return make$none();
}

value pop$list(value self) {
  assert(self.type == value::LIST);
  value ret = self.listval->back();
  self.listval->pop_back();
  return ret;
}

value __getitem__$list$(value self, value k) {
  assert(self.type == value::LIST);
  switch (k.type) {
  case value::INT:
    return __getitem__$list$int_(self, k);
  case value::SLICE: 
    return __getitem__$list$slice(self, k);
  }
  throw std::runtime_error("Invalid argument type for list::__getitem__");
}

value __setitem__$list$$(value self, value k, value v) {
  assert(self.type == value::LIST);
  switch (k.type) {
  case value::INT:
    return __setitem__$list$int_$(self, k, v);
  case value::SLICE:
    return __setitem__$list$slice$(self, k, v);
  }
  return make$none();
}

value __add__$list$list(value x, value y) {
  assert(x.type == value::LIST && y.type == value::LIST);

  list_t *merged = new list_t();
  merged->reserve(x.listval->size() + y.listval->size());
  merged->insert(merged->end(), x.listval->begin(), x.listval->end());
  merged->insert(merged->end(), y.listval->begin(), y.listval->end());

  value ret;
  ret.type = value::LIST;
  ret.listval = merged;
  return ret;
}

value __mul__$list$int_(value self, value n) {
  assert(self.type == value::LIST && n.type == value::INT);

  list_t *duped = new list_t();
  if (n.intval > 0) {
    duped->reserve(self.listval->size() * n.intval);
    for (long i = 0; i < n.intval; i++)
      duped->insert(duped->end(), self.listval->begin(), self.listval->end());
  }

  value ret;
  ret.type = value::LIST;
  ret.listval = duped;
  return ret;
}

value __len__$list(value self) {
  assert(self.type == value::LIST);
  return make$int_(self.listval->size());
}

value __eq__$list$list(value x, value y) {
  assert(x.type == value::LIST && y.type == value::LIST);
  return make$bool_(*x.listval == *y.listval);
}

value __ne__$list$list(value x, value y) {
  assert(x.type == value::LIST && y.type == value::LIST);
  return make$bool_(*x.listval != *y.listval);
}

value __lt__$list$list(value x, value y) {
  assert(x.type == value::LIST && y.type == value::LIST);
  return make$bool_(*x.listval < *y.listval);
}

value __le__$list$list(value x, value y) {
  assert(x.type == value::LIST && y.type == value::LIST);
  return make$bool_(*x.listval <= *y.listval);
}

value __ge__$list$list(value x, value y) {
  assert(x.type == value::LIST && y.type == value::LIST);
  return make$bool_(*x.listval >= *y.listval);
}

value __gt__$list$list(value x, value y) {
  assert(x.type == value::LIST && y.type == value::LIST);
  return make$bool_(*x.listval > *y.listval);
}

value __contains__$list$(value self, value v) {
  assert(self.type == value::LIST);

  for (size_t i = 0; i < self.listval->size(); i++)
    if ((*self.listval)[i] == v)
      return make$bool_(true);
  return make$bool_(false);
}

value __delitem__$list$int_(value self, value k) {
  assert(self.type == value::LIST && k.type == value::INT);
  self.listval->erase(self.listval->begin() + k.intval);
  return make$none();
}

value __delitem__$list$slice(value self, value k) {
  assert(false);
  return make$none();
}

value __bool__$list(value self) {
  assert(self.type == value::LIST);
  return make$bool_(!self.listval->empty());
}


value __getitem__$list$int_(value self, value k) {
  return self.listval->at(k.intval);
}

value __getitem__$list$slice(value self, value k) {
    long start = k.sliceval->start;
    long stop = k.sliceval->stop;
    long step = k.sliceval->step;
    if (start < 0)
      start = (long)self.listval->size() + start;
    if (stop < 0)
      stop = (long)self.listval->size() + stop;

    list_t *ret = new list_t();
    if (step > 0) {
      start = std::max(0L, start);
      stop = std::min((long)self.listval->size(), stop);
      for (long i = start; i < stop; i += step) {
        ret->push_back(self.listval->at(i));
      }
    } else {
      start = std::min((long)self.listval->size() - 1L, start);
      stop = std::max(-1L, stop);
      for (long i = start; i > stop; i += step) {
        ret->push_back(self.listval->at(i));
      }
    }

    return value{.type = value::LIST, .listval = ret};
}

value __setitem__$list$int_$(value self, value k, value v) {
  assert(self.type == value::LIST && k.type == value::INT);
  self.listval->at(k.intval) = v;
  return make$none();
}

value __setitem__$list$slice$(value self, value k, value v) {
  assert(self.type == value::LIST && k.type == value::SLICE);
  if (v.type != value::LIST)
    throw std::runtime_error("list::__setitem__ must pass in a list");
  long start = k.sliceval->start;
  long stop = k.sliceval->stop;
  long step = k.sliceval->step;
  if (start < 0)
    start = (long)self.listval->size() + start;
  if (stop < 0)
    stop = (long)self.listval->size() + stop;

  if (step > 0) {
    start = std::min((long)self.listval->size(), std::max(0L, start));
    stop = std::max(start, std::min((long)self.listval->size(), stop));
    if (step == 1) {
      self.listval->erase(self.listval->begin() + start,
                          self.listval->begin() + stop);
      self.listval->insert(self.listval->begin() + start, v.listval->begin(),
                           v.listval->end());
    } else {
      long count = (stop - start + step - 1) / step;
      if (count != v.listval->size())
        throw std::runtime_error(
            "list::__setitem__ slice length not match value length");
      for (long i = 0; i < count; i++) {
        self.listval->at(start + step * i) = v.listval->at(i);
      }
    }
  } else {
    start = std::min((long)self.listval->size() - 1L, std::max(-1L, start));
    stop = std::min(start, std::max(-1L, stop));
    long count = (start - stop + -step - 1) / -step;
    if (count != v.listval->size())
      throw std::runtime_error(
          "list::__setitem__ slice length not match value length");
    for (long i = 0; i < count; i++) {
      self.listval->at(start + i * step) = v.listval->at(i);
    }
  }
  return make$none();
}

value __iter__$list(value self) {
  assert(self.type == value::LIST);
  return make$list_iterator(self.listval);
}
