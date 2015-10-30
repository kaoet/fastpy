#include <cstdio>
#include <stdexcept>
#include "assert.h"
#include "type.h"
#include "list.h"
#include "int.h"
#include "float.h"
#include "str.h"
#include "dict.h"
#include "bool.h"
#include "set.h"
#include "func.h"
#include "none.h"
#include "range.h"
#include "range_iterator.h"
#include "slice.h"

void test_none() {
  assert(make$none() == make$none());
  assert(__bool__(make$none()) == make$bool_(false));
}

void test_bool() {
  assert(make$bool_(true) == make$int_(1));
  assert(make$bool_(false) == make$float_(0));
  assert(make$bool_(false) < make$bool_(true));
  assert(!(make$bool_(false) < make$bool_(false)));
  assert(make$bool_(true) <= make$bool_(true));
  assert(make$bool_(true) > make$int_(0));
  assert(make$bool_(true) >= make$float_(0.5));
  assert(__bool__(make$bool_(true)));
  assert(!__bool__(make$bool_(false)));
  assert(make$bool_(true) & make$bool_(true));
  assert(!(make$bool_(false) | make$bool_(false)));
  assert(!(make$bool_(true) ^ make$bool_(true)));
  assert(~make$bool_(true) == make$int_(-2));
  assert((make$bool_(true) << make$bool_(true)) == make$int_(2));
  assert((make$int_(3) >> make$bool_(true)) == make$int_(1));
}

void test_int() {
  assert(make$int_(1) + make$int_(2) == make$int_(3));
  assert(make$int_(1) - make$int_(2) == make$int_(-1));
  assert(make$int_(3) * make$int_(4) == make$int_(12));
  assert(make$int_(10) / make$int_(3) == make$float_(10.0 / 3.0));
  assert(make$int_(10) % make$int_(3) == make$int_(1));
  assert(make$int_(3) + make$float_(4.5) == make$float_(7.5));
  assert(make$int_(2) == make$float_(2.0));
  assert(make$int_(2) < make$float_(2.1));
  assert(__bool__(make$int_(1)));
  assert(!__bool__(make$int_(0)));
  assert((make$int_(123) & make$int_(456)) == make$int_(123 & 456));
  assert((make$int_(-3) >> make$int_(1)) == make$int_(-2));
}

void test_float() {
  assert(make$float_(1.1) + make$float_(2.2) == make$float_(1.1 + 2.2));
  assert(make$float_(1.1) - make$float_(2.2) == make$float_(1.1 - 2.2));
  assert(make$float_(1.1) * make$float_(2.2) == make$float_(1.1 * 2.2));
  assert(make$float_(1.1) / make$float_(2.2) == make$float_(1.1 / 2.2));
  assert(make$float_(10.75) % make$float_(5.25) == make$float_(0.25));
  assert(make$float_(3.8) >= make$float_(3.8));
}

void test_str() {
  assert(make$str("hello") == make$str("hello"));
  assert(__getitem__(make$str("hello"), make$int_(1)) == make$str("e"));
  assert(make$str("hello") + make$str("world") == make$str("helloworld"));
  assert(make$str("he") * make$int_(5) == make$str("hehehehehe"));
  assert(make$int_(-10) * make$str("whatever") == make$str(""));
  assert(__len__(make$str("12345")) == make$int_(5));
  assert(__contains__(make$str("foobar"), make$str("oob")) ==
         make$bool_(true));
  assert(__contains__(make$str("foobar"), make$str("boo")) ==
         make$bool_(false));
  assert(__bool__(make$str("")) == make$bool_(false));
  assert(__bool__(make$str("a")) == make$bool_(true));
  assert(make$str("abc") < make$str("abcd"));
  assert(make$str("abd") >= make$str("abcd"));
  assert(__getitem__(make$str("0123456"),
                     __init__$slice$int_$int_$int_(make$int_(1), make$int_(50),
                                     make$int_(2))) == make$str("135"));
}

value list1() {
  value l = make$list();
  append(l, make$int_(2));
  append(l, make$float_(3.0));
  append(l, make$str("4"));
  return l;
}

value list2() {
  value l = make$list();
  append(l, make$int_(5));
  append(l, make$float_(6.0));
  return l;
}

value list11() {
  value l = make$list();
  append(l, make$int_(2));
  append(l, make$str("w"));
  append(l, make$str("4"));
  return l;
}

value list12() {
  value l = make$list();
  append(l, make$int_(2));
  append(l, make$float_(3.0));
  append(l, make$str("4"));
  append(l, make$int_(5));
  append(l, make$float_(6.0));
  return l;
}

value list13() {
  value l = make$list();
  append(l, make$int_(2));
  append(l, make$float_(3.0));
  append(l, make$str("4"));
  append(l, make$int_(2));
  append(l, make$float_(3.0));
  append(l, make$str("4"));
  append(l, make$int_(2));
  append(l, make$float_(3.0));
  append(l, make$str("4"));
  return l;
}

value list1_del() {
  value l = make$list();
  append(l, make$int_(2));
  append(l, make$str("4"));
  return l;
}

value list1_pop() {
  value l = make$list();
  append(l, make$int_(2));
  append(l, make$float_(3.0));
  return l;
}

value list1_slice() {
  value l = make$list();
  append(l, make$str("4"));
  append(l, make$int_(2));
  return l;
}

value list3() {
  value l = make$list();
  append(l, make$int_(0));
  append(l, make$int_(1));
  append(l, make$int_(2));
  append(l, make$int_(3));
  append(l, make$int_(4));
  return l;
}

value list4() {
  value l = make$list();
  append(l, make$int_(50));
  append(l, make$int_(51));
  return l;
}

value list3_setslice1() {
  value l = make$list();
  append(l, make$int_(0));
  append(l, make$int_(51));
  append(l, make$int_(2));
  append(l, make$int_(50));
  append(l, make$int_(4));
  return l;
}

value list3_setslice2() {
  value l = make$list();
  append(l, make$int_(0));
  append(l, make$int_(1));
  append(l, make$int_(50));
  append(l, make$int_(51));
  append(l, make$int_(3));
  append(l, make$int_(4));
  return l;
}

void test_list() {
  assert(list1() == list1());
  assert(__len__(list1()) == make$int_(3));
  assert(__getitem__(list1(), make$int_(1)) == make$float_(3.0));
  assert(list1() + list2() == list12());
  assert(make$int_(3) * list1() == list13());
  assert(__contains__(list1(), make$str("4")) == make$bool_(true));
  assert(__contains__(list1(), make$str("5")) == make$bool_(false));
  assert(__bool__(make$list()) == make$bool_(false));
  assert(__bool__(list1()) == make$bool_(true));
  assert(list1() <= list12());
  assert(__getitem__(list1(), __init__$slice$int_$int_$int_(make$int_(10), make$int_(-10),
                                              make$int_(-2))) ==
         list1_slice());

  value l = list1();
  __setitem__(l, make$int_(1), make$str("w"));
  assert(l == list11());

  l = list1();
  __delitem__(l, make$int_(1));
  assert(l == list1_del());

  l = list1();
  assert(make$str("4") == pop(l));
  assert(l == list1_pop());

  l = list3();
  __setitem__(l,
              __init__$slice$int_$int_$int_(make$int_(3), make$int_(-50), make$int_(-2)),
              list4());
  assert(l == list3_setslice1());

  l = list3();
  __setitem__(l, __init__$slice$int_$int_$int_(make$int_(2), make$int_(3), make$int_(1)),
              list4());
  assert(l == list3_setslice2());
  
  value iter = __iter__(list1());
  assert(__next__(iter) == make$int_(2));
  assert(__next__(iter) == make$float_(3.0));
  assert(__next__(iter) == make$str("4"));
  assert(__next__(iter) == make$none());
}

value set1() {
  value s = make$set();
  add(s, make$int_(1));
  add(s, make$float_(2.0));
  add(s, make$str("3"));
  return s;
}

value set1_removed() {
  value s = make$set();
  add(s, make$int_(1));
  add(s, make$float_(2.0));
  return s;
}

void test_set() {
  assert(set1() == set1());
  assert(__len__(set1()) == make$int_(3));
  assert(__contains__(set1(), make$int_(1)));
  assert(!__contains__(set1(), make$int_(4)));
  assert(set1() > set1_removed());
  assert(!(set1() > set1()));
  assert(set1() >= set1());

  value s = set1();
  add(s, make$str("3"));
  assert(s == set1());

  s = set1();
  add(s, make$float_(1.0));
  assert(s == set1());

  s = set1();
  remove(s, make$str("3"));
  assert(s == set1_removed());
  
  value iter = __iter__(set1());
  assert(__next__(iter) != make$none());
  assert(__next__(iter) != make$none());
  assert(__next__(iter) != make$none());
  assert(__next__(iter) == make$none());
}

value dict1() {
  value d = make$dict();
  __setitem__(d, make$int_(1), make$int_(2));
  __setitem__(d, make$str("a"), make$str("b"));
  return d;
}

value dict1_added() {
  value d = make$dict();
  __setitem__(d, make$int_(1), make$str("foo"));
  __setitem__(d, make$str("a"), make$str("b"));
  return d;
}

value dict1_del() {
  value d = make$dict();
  __setitem__(d, make$int_(1), make$int_(2));
  return d;
}

void test_dict() {
  assert(dict1() == dict1());
  assert(__len__(dict1()) == make$int_(2));
  assert(__contains__(dict1(), make$int_(1)));
  assert(!__contains__(dict1(), make$int_(2)));
  assert(__getitem__(dict1(), make$int_(1)) == make$int_(2));

  value d = dict1();
  __setitem__(d, make$int_(1), make$str("foo"));
  assert(d == dict1_added());
  assert(d != dict1());

  d = dict1();
  __delitem__(d, make$str("a"));
  assert(d == dict1_del());
  
  value iter = __iter__(dict1());
  assert(__next__(iter) != make$none());
  assert(__next__(iter) != make$none());
  assert(__next__(iter) == make$none());
}

void test_range() {
  value r = __init__$range$int_(make$int_(3));
  value iter = __iter__(r);
  assert(__next__(iter) == make$int_(0));
  assert(__next__(iter) == make$int_(1));
  assert(__next__(iter) == make$int_(2));
  assert(__next__(iter) == make$none());

  r = __init__$range$int_$int_$int_(make$int_(5), make$int_(1), make$int_(-2));
  iter = __iter__(r);
  assert(__next__(iter) == make$int_(5));
  assert(__next__(iter) == make$int_(3));
  assert(__next__(iter) == make$none());
}

int main() {
  test_none();
  test_bool();
  test_int();
  test_float();
  test_str();
  test_list();
  test_set();
  test_dict();
  test_range();
}