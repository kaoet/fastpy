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

void test_none() {
  assert(none::make() == none::make());
  assert(__bool__(none::make()) == bool_::make(false));
}

void test_bool() {
  assert(bool_::make(true) == int_::make(1));
  assert(bool_::make(false) == float_::make(0));
  assert(bool_::make(false) < bool_::make(true));
  assert(!(bool_::make(false) < bool_::make(false)));
  assert(bool_::make(true) <= bool_::make(true));
  assert(bool_::make(true) > int_::make(0));
  assert(bool_::make(true) >= float_::make(0.5));
  assert(__bool__(bool_::make(true)));
  assert(!__bool__(bool_::make(false)));
  assert(bool_::make(true) & bool_::make(true));
  assert(!(bool_::make(false) | bool_::make(false)));
  assert(!(bool_::make(true) ^ bool_::make(true)));
  assert(~bool_::make(true) == int_::make(-2));
  assert((bool_::make(true) << bool_::make(true)) == int_::make(2));
  assert((int_::make(3) >> bool_::make(true)) == int_::make(1));
}

void test_int() {
  assert(int_::make(1) + int_::make(2) == int_::make(3));
  assert(int_::make(1) - int_::make(2) == int_::make(-1));
  assert(int_::make(3) * int_::make(4) == int_::make(12));
  assert(int_::make(10) / int_::make(3) == float_::make(10.0 / 3.0));
  assert(int_::make(10) % int_::make(3) == int_::make(1));
  assert(int_::make(3) + float_::make(4.5) == float_::make(7.5));
  assert(int_::make(2) == float_::make(2.0));
  assert(int_::make(2) < float_::make(2.1));
  assert(__bool__(int_::make(1)));
  assert(!__bool__(int_::make(0)));
  assert((int_::make(123) & int_::make(456)) == int_::make(123 & 456));
  assert((int_::make(-3) >> int_::make(1)) == int_::make(-2));
}

void test_float() {
  assert(float_::make(1.1) + float_::make(2.2) == float_::make(1.1 + 2.2));
  assert(float_::make(1.1) - float_::make(2.2) == float_::make(1.1 - 2.2));
  assert(float_::make(1.1) * float_::make(2.2) == float_::make(1.1 * 2.2));
  assert(float_::make(1.1) / float_::make(2.2) == float_::make(1.1 / 2.2));
  assert(float_::make(10.75) % float_::make(5.25) == float_::make(0.25));
  assert(float_::make(3.8) >= float_::make(3.8));
}

void test_str() {
  assert(str::make("hello") == str::make("hello"));
  assert(__getitem__(str::make("hello"), int_::make(1)) == str::make("e"));
  assert(str::make("hello") + str::make("world") == str::make("helloworld"));
  assert(str::make("he") * int_::make(5) == str::make("hehehehehe"));
  assert(int_::make(-10) * str::make("whatever") == str::make(""));
  assert(__len__(str::make("12345")) == int_::make(5));
  assert(__contains__(str::make("foobar"), str::make("oob")) ==
         bool_::make(true));
  assert(__contains__(str::make("foobar"), str::make("boo")) ==
         bool_::make(false));
  assert(__bool__(str::make("")) == bool_::make(false));
  assert(__bool__(str::make("a")) == bool_::make(true));
  assert(str::make("abc") < str::make("abcd"));
  assert(str::make("abd") >= str::make("abcd"));
}

value list1() {
  value l = list::make();
  append(l, int_::make(2));
  append(l, float_::make(3.0));
  append(l, str::make("4"));
  return l;
}

value list2() {
  value l = list::make();
  append(l, int_::make(5));
  append(l, float_::make(6.0));
  return l;
}

value list11() {
  value l = list::make();
  append(l, int_::make(2));
  append(l, str::make("w"));
  append(l, str::make("4"));
  return l;
}

value list12() {
  value l = list::make();
  append(l, int_::make(2));
  append(l, float_::make(3.0));
  append(l, str::make("4"));
  append(l, int_::make(5));
  append(l, float_::make(6.0));
  return l;
}

value list13() {
  value l = list::make();
  append(l, int_::make(2));
  append(l, float_::make(3.0));
  append(l, str::make("4"));
  append(l, int_::make(2));
  append(l, float_::make(3.0));
  append(l, str::make("4"));
  append(l, int_::make(2));
  append(l, float_::make(3.0));
  append(l, str::make("4"));
  return l;
}

value list1_del() {
  value l = list::make();
  append(l, int_::make(2));
  append(l, str::make("4"));
  return l;
}

value list1_pop() {
  value l = list::make();
  append(l, int_::make(2));
  append(l, float_::make(3.0));
  return l;
}

void test_list() {
  assert(list1() == list1());
  assert(__len__(list1()) == int_::make(3));
  assert(__getitem__(list1(), int_::make(1)) == float_::make(3.0));
  assert(list1() + list2() == list12());
  assert(int_::make(3) * list1() == list13());
  assert(__contains__(list1(), str::make("4")) == bool_::make(true));
  assert(__contains__(list1(), str::make("5")) == bool_::make(false));
  assert(__bool__(list::make()) == bool_::make(false));
  assert(__bool__(list1()) == bool_::make(true));
  assert(list1() <= list12());

  value l = list1();
  __setitem__(l, int_::make(1), str::make("w"));
  assert(l == list11());

  l = list1();
  __delitem__(l, int_::make(1));
  assert(l == list1_del());

  l = list1();
  assert(str::make("4") == pop(l));
  assert(l == list1_pop());
}

value set1() {
  value s = set::make();
  add(s, int_::make(1));
  add(s, float_::make(2.0));
  add(s, str::make("3"));
  return s;
}

value set1_removed() {
  value s = set::make();
  add(s, int_::make(1));
  add(s, float_::make(2.0));
  return s;
}

void test_set() {
  assert(set1() == set1());
  assert(__len__(set1()) == int_::make(3));
  assert(__contains__(set1(), int_::make(1)));
  assert(!__contains__(set1(), int_::make(4)));
  assert(set1() > set1_removed());
  assert(!(set1() > set1()));
  assert(set1() >= set1());

  value s = set1();
  add(s, str::make("3"));
  assert(s == set1());

  s = set1();
  add(s, float_::make(1.0));
  assert(s == set1());

  s = set1();
  remove(s, str::make("3"));
  assert(s == set1_removed());
}

value dict1() {
  value d = dict::make();
  __setitem__(d, int_::make(1), int_::make(2));
  __setitem__(d, str::make("a"), str::make("b"));
  return d;
}

value dict1_added() {
  value d = dict::make();
  __setitem__(d, int_::make(1), str::make("foo"));
  __setitem__(d, str::make("a"), str::make("b"));
  return d;
}

value dict1_del() {
  value d = dict::make();
  __setitem__(d, int_::make(1), int_::make(2));
  return d;
}

void test_dict() {
  assert(dict1() == dict1());
  assert(__len__(dict1()) == int_::make(2));
  assert(__contains__(dict1(), int_::make(1)));
  assert(!__contains__(dict1(), int_::make(2)));
  assert(__getitem__(dict1(), int_::make(1)) == int_::make(2));

  value d = dict1();
  __setitem__(d, int_::make(1), str::make("foo"));
  assert(d == dict1_added());
  assert(d != dict1());

  d = dict1();
  __delitem__(d, str::make("a"));
  assert(d == dict1_del());
}

void test_range() {
  value r = range::__init__(int_::make(3));
  value iter = __iter__(r);
  assert(__next__(iter) == int_::make(0));
  assert(__next__(iter) == int_::make(1));
  assert(__next__(iter) == int_::make(2));
  assert(__next__(iter) == none::make());

  r = range::__init__(int_::make(5), int_::make(1), int_::make(-2));
  iter = __iter__(r);
  assert(__next__(iter) == int_::make(5));
  assert(__next__(iter) == int_::make(3));
  assert(__next__(iter) == none::make());
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