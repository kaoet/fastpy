#include "func.h"
#include "list.h"
#include "int.h"
#include "float.h"
#include "str.h"
#include "dict.h"
#include "bool.h"
#include "set.h"
#include "none.h"
#include "range.h"
#include "range_iterator.h"

value print(value v) {
  switch (v.type) {
  case value::NONE:
    printf(" None");
    break;
  case value::BOOL:
    if (v.boolval)
      printf(" True");
    else
      printf(" False");
    break;
  case value::INT:
    printf(" %ld", v.intval);
    break;
  case value::FLOAT:
    printf(" %f", v.floatval);
    break;
  case value::LIST:
    printf("[");
    for (value v : *v.listval) {
      print(v);
      printf(",");
    }
    printf("]");
    break;
  case value::STR:
    printf(" '%s'", v.strval->c_str());
    break;
  case value::SET:
    printf("{");
    for (auto it = v.setval->begin(); it != v.setval->end(); ++it) {
      print(*it);
      printf(",");
    }
    printf("}");
    break;
  case value::DICT:
    printf("{");
    for (auto it = v.dictval->begin(); it != v.dictval->end(); ++it) {
      print(it->first);
      printf(":");
      print(it->second);
      printf(",");
    }
    printf("}");
    break;
  default:
    throw std::runtime_error("invalid value to print");
  }
  return none::make();
}

value __add__(value x, value y) {
  switch (x.type) {
  case value::INT:
    switch (y.type) {
    case value::INT:
      return int_::__add__(x, y);
    case value::FLOAT:
      return float_::__add__(int_::__float__(x), y);
    }
    break;
  case value::FLOAT:
    switch (y.type) {
    case value::INT:
      return float_::__add__(x, int_::__float__(y));
    case value::FLOAT:
      return float_::__add__(x, y);
    }
    break;
  case value::LIST:
    if (y.type == value::LIST) {
      return list::__add__(x, y);
    }
    break;
  case value::STR:
    if (y.type == value::STR) {
      return str::__add__(x, y);
    }
  }
  throw std::runtime_error("invalid argument type for +");
}

value __sub__(value x, value y) {
  switch (x.type) {
  case value::INT:
    switch (y.type) {
    case value::INT:
      return int_::__sub__(x, y);
    case value::FLOAT:
      return float_::__sub__(int_::__float__(x), y);
    }
    break;
  case value::FLOAT:
    switch (y.type) {
    case value::INT:
      return float_::__sub__(x, int_::__float__(y));
    case value::FLOAT:
      return float_::__sub__(x, y);
    }
  }
  throw std::runtime_error("invalid argument type for -");
}

value __mul__(value x, value y) {
  switch (x.type) {
  case value::INT:
    switch (y.type) {
    case value::INT:
      return int_::__mul__(x, y);
    case value::FLOAT:
      return float_::__mul__(int_::__float__(x), y);
    case value::STR:
      return str::__mul__(y, x);
    case value::LIST:
      return list::__mul__(y, x);
    }
    break;
  case value::FLOAT:
    switch (y.type) {
    case value::INT:
      return float_::__mul__(x, int_::__float__(y));
    case value::FLOAT:
      return float_::__mul__(x, y);
    }
    break;
  case value::STR:
    if (y.type == value::INT) {
      return str::__mul__(x, y);
    }
    break;
  case value::LIST:
    if (y.type == value::INT) {
      return list::__mul__(x, y);
    }
  }
  throw std::runtime_error("invalid argument type for *");
}

value __truediv__(value x, value y) {
  switch (x.type) {
  case value::INT:
    switch (y.type) {
    case value::INT:
      return int_::__truediv__(x, y);
    case value::FLOAT:
      return float_::__truediv__(int_::__float__(x), y);
    }
    break;
  case value::FLOAT:
    switch (y.type) {
    case value::INT:
      return float_::__truediv__(x, int_::__float__(y));
    case value::FLOAT:
      return float_::__truediv__(x, y);
    }
  }
  throw std::runtime_error("invalid argument type for /");
}

value __mod__(value x, value y) {
  switch (x.type) {
  case value::INT:
    switch (y.type) {
    case value::INT:
      return int_::__mod__(x, y);
    case value::FLOAT:
      return float_::__mod__(int_::__float__(x), y);
    }
    break;
  case value::FLOAT:
    switch (y.type) {
    case value::INT:
      return float_::__mod__(x, int_::__float__(y));
    case value::FLOAT:
      return float_::__mod__(x, y);
    }
  }
  throw std::runtime_error("invalid argument type for mod");
}

value __len__(value self) {
  switch (self.type) {
  case value::LIST:
    return list::__len__(self);
  case value::STR:
    return str::__len__(self);
  case value::SET:
    return set::__len__(self);
  case value::DICT:
    return dict::__len__(self);
  default:
    throw std::runtime_error("invalid argument type for len");
  }
}

value __getitem__(value self, value k) {
  switch (self.type) {
  case value::STR:
    switch (k.type) {
    case value::INT:
    case value::SLICE:
      return str::__getitem__(self, k);
    }
    break;
  case value::LIST:
    switch (k.type) {
    case value::INT:
    case value::SLICE:
      return list::__getitem__(self, k);
    }
    break;
  case value::DICT:
    switch (k.type) {
    case value::NONE:
    case value::BOOL:
    case value::INT:
    case value::FLOAT:
    case value::STR:
      return dict::__getitem__(self, k);
    }
  }
  throw std::runtime_error("invalid argument type for []");
}

value __contains__(value self, value v) {
  switch (self.type) {
  case value::STR:
    if (v.type == value::STR)
      return str::__contains__(self, v);
    break;
  case value::LIST:
    return list::__contains__(self, v);
  case value::SET:
    return set::__contains__(self, v);
  case value::DICT:
    switch (v.type) {
    case value::NONE:
    case value::BOOL:
    case value::INT:
    case value::FLOAT:
    case value::STR:
      return dict::__contains__(self, v);
    }
  }
  throw std::runtime_error("invalid argument type for in");
}

value __setitem__(value self, value k, value v) {
  switch (self.type) {
  case value::LIST:
    switch (k.type) {
    case value::INT:
    case value::SLICE:
      return list::__setitem__(self, k, v);
    }
    break;
  case value::DICT:
    switch (k.type) {
    case value::NONE:
    case value::BOOL:
    case value::INT:
    case value::FLOAT:
    case value::STR:
      return dict::__setitem__(self, k, v);
    }
  }
  throw std::runtime_error("invalid argument type for []=");
}

value __delitem__(value self, value k) {
  switch (self.type) {
  case value::LIST:
    return list::__delitem__(self, k);
  case value::DICT:
    switch (k.type) {
    case value::NONE:
    case value::BOOL:
    case value::INT:
    case value::FLOAT:
    case value::STR:
      return dict::__delitem__(self, k);
    }
  }
  throw std::runtime_error("invalid argument type for del");
}

value __bool__(value self) {
  switch (self.type) {
  case value::NONE:
    return none::__bool__(self);
  case value::BOOL:
    return bool_::__bool__(self);
  case value::INT:
    return int_::__bool__(self);
  case value::FLOAT:
    return float_::__bool__(self);
  case value::STR:
    return str::__bool__(self);
  case value::LIST:
    return list::__bool__(self);
  case value::SET:
    return set::__bool__(self);
  case value::DICT:
    return dict::__bool__(self);
  }
  throw std::runtime_error("invalid argument type for bool()");
}

value __eq__(value x, value y) {
  switch (x.type) {
  case value::NONE:
    if (y.type == value::NONE)
      return none::__eq__(x, y);
    break;
  case value::BOOL:
    switch (y.type) {
    case value::BOOL:
      return bool_::__eq__(x, y);
    case value::INT:
      return int_::__eq__(bool_::__int__(x), y);
    case value::FLOAT:
      return float_::__eq__(bool_::__float__(x), y);
    }
    break;
  case value::INT:
    switch (y.type) {
    case value::BOOL:
      return int_::__eq__(x, bool_::__int__(y));
    case value::INT:
      return int_::__eq__(x, y);
    case value::FLOAT:
      return float_::__eq__(int_::__float__(x), y);
    }
    break;
  case value::FLOAT:
    switch (y.type) {
    case value::BOOL:
      return float_::__eq__(x, bool_::__float__(y));
    case value::INT:
      return float_::__eq__(x, int_::__float__(y));
    case value::FLOAT:
      return float_::__eq__(x, y);
    }
    break;
  case value::STR:
    if (y.type == value::STR)
      return str::__eq__(x, y);
    break;
  case value::LIST:
    if (y.type == value::LIST)
      return list::__eq__(x, y);
    break;
  case value::SET:
    if (y.type == value::SET)
      return set::__eq__(x, y);
    break;
  case value::DICT:
    if (y.type == value::DICT)
      return dict::__eq__(x, y);
    break;
  }
  return bool_::make(false);
}

value __ne__(value x, value y) {
  switch (x.type) {
  case value::NONE:
    if (y.type == value::NONE)
      return none::__ne__(x, y);
    break;
  case value::BOOL:
    switch (y.type) {
    case value::BOOL:
      return bool_::__ne__(x, y);
    case value::INT:
      return int_::__ne__(bool_::__int__(x), y);
    case value::FLOAT:
      return float_::__ne__(bool_::__float__(x), y);
    }
    break;
  case value::INT:
    switch (y.type) {
    case value::BOOL:
      return int_::__ne__(x, bool_::__int__(y));
    case value::INT:
      return int_::__ne__(x, y);
    case value::FLOAT:
      return float_::__ne__(int_::__float__(x), y);
    }
    break;
  case value::FLOAT:
    switch (y.type) {
    case value::BOOL:
      return float_::__ne__(x, bool_::__float__(y));
    case value::INT:
      return float_::__ne__(x, int_::__float__(y));
    case value::FLOAT:
      return float_::__ne__(x, y);
    }
    break;
  case value::STR:
    if (y.type == value::STR)
      return str::__ne__(x, y);
    break;
  case value::LIST:
    if (y.type == value::LIST)
      return list::__ne__(x, y);
    break;
  case value::SET:
    if (y.type == value::SET)
      return set::__ne__(x, y);
    break;
  case value::DICT:
    if (y.type == value::DICT)
      return dict::__ne__(x, y);
    break;
  }
  return bool_::make(true);
}

value __lt__(value x, value y) {
  switch (x.type) {
  case value::BOOL:
    switch (y.type) {
    case value::BOOL:
      return bool_::__lt__(x, y);
    case value::INT:
      return int_::__lt__(bool_::__int__(x), y);
    case value::FLOAT:
      return float_::__lt__(bool_::__float__(x), y);
    }
    break;
  case value::INT:
    switch (y.type) {
    case value::BOOL:
      return int_::__lt__(x, bool_::__int__(y));
    case value::INT:
      return int_::__lt__(x, y);
    case value::FLOAT:
      return float_::__lt__(int_::__float__(x), y);
    }
    break;
  case value::FLOAT:
    switch (y.type) {
    case value::BOOL:
      return float_::__lt__(x, bool_::__float__(y));
    case value::INT:
      return float_::__lt__(x, int_::__float__(y));
    case value::FLOAT:
      return float_::__lt__(x, y);
    }
    break;
  case value::STR:
    if (y.type == value::STR)
      return str::__lt__(x, y);
    break;
  case value::LIST:
    if (y.type == value::LIST)
      return list::__lt__(x, y);
    break;
  case value::SET:
    if (y.type == value::SET)
      return set::__lt__(x, y);
    break;
  }
  throw std::runtime_error("invalid type for <");
}

value __le__(value x, value y) {
  switch (x.type) {
  case value::BOOL:
    switch (y.type) {
    case value::BOOL:
      return bool_::__le__(x, y);
    case value::INT:
      return int_::__le__(bool_::__int__(x), y);
    case value::FLOAT:
      return float_::__le__(bool_::__float__(x), y);
    }
    break;
  case value::INT:
    switch (y.type) {
    case value::BOOL:
      return int_::__le__(x, bool_::__int__(y));
    case value::INT:
      return int_::__le__(x, y);
    case value::FLOAT:
      return float_::__le__(int_::__float__(x), y);
    }
    break;
  case value::FLOAT:
    switch (y.type) {
    case value::BOOL:
      return float_::__le__(x, bool_::__float__(y));
    case value::INT:
      return float_::__le__(x, int_::__float__(y));
    case value::FLOAT:
      return float_::__le__(x, y);
    }
    break;
  case value::STR:
    if (y.type == value::STR)
      return str::__le__(x, y);
    break;
  case value::LIST:
    if (y.type == value::LIST)
      return list::__le__(x, y);
    break;
  case value::SET:
    if (y.type == value::SET)
      return set::__le__(x, y);
    break;
  }
  throw std::runtime_error("invalid type for <=");
}

value __ge__(value x, value y) {
  switch (x.type) {
  case value::BOOL:
    switch (y.type) {
    case value::BOOL:
      return bool_::__ge__(x, y);
    case value::INT:
      return int_::__ge__(bool_::__int__(x), y);
    case value::FLOAT:
      return float_::__ge__(bool_::__float__(x), y);
    }
    break;
  case value::INT:
    switch (y.type) {
    case value::BOOL:
      return int_::__ge__(x, bool_::__int__(y));
    case value::INT:
      return int_::__ge__(x, y);
    case value::FLOAT:
      return float_::__ge__(int_::__float__(x), y);
    }
    break;
  case value::FLOAT:
    switch (y.type) {
    case value::BOOL:
      return float_::__ge__(x, bool_::__float__(y));
    case value::INT:
      return float_::__ge__(x, int_::__float__(y));
    case value::FLOAT:
      return float_::__ge__(x, y);
    }
    break;
  case value::STR:
    if (y.type == value::STR)
      return str::__ge__(x, y);
    break;
  case value::LIST:
    if (y.type == value::LIST)
      return list::__ge__(x, y);
    break;
  case value::SET:
    if (y.type == value::SET)
      return set::__ge__(x, y);
    break;
  }
  throw std::runtime_error("invalid type for >=");
}

value __gt__(value x, value y) {
  switch (x.type) {
  case value::BOOL:
    switch (y.type) {
    case value::BOOL:
      return bool_::__gt__(x, y);
    case value::INT:
      return int_::__gt__(bool_::__int__(x), y);
    case value::FLOAT:
      return float_::__gt__(bool_::__float__(x), y);
    }
    break;
  case value::INT:
    switch (y.type) {
    case value::BOOL:
      return int_::__gt__(x, bool_::__int__(y));
    case value::INT:
      return int_::__gt__(x, y);
    case value::FLOAT:
      return float_::__gt__(int_::__float__(x), y);
    }
    break;
  case value::FLOAT:
    switch (y.type) {
    case value::BOOL:
      return float_::__gt__(x, bool_::__float__(y));
    case value::INT:
      return float_::__gt__(x, int_::__float__(y));
    case value::FLOAT:
      return float_::__gt__(x, y);
    }
    break;
  case value::STR:
    if (y.type == value::STR)
      return str::__gt__(x, y);
    break;
  case value::LIST:
    if (y.type == value::LIST)
      return list::__gt__(x, y);
    break;
  case value::SET:
    if (y.type == value::SET)
      return set::__gt__(x, y);
    break;
  }
  throw std::runtime_error("invalid type for >");
}

value __and__(value x, value y) {
  switch (x.type) {
  case value::BOOL:
    switch (y.type) {
    case value::BOOL:
      return bool_::__and__(x, y);
    case value::INT:
      return int_::__and__(bool_::__int__(x), y);
    }
    break;
  case value::INT:
    switch (y.type) {
    case value::BOOL:
      return int_::__and__(x, bool_::__int__(y));
    case value::INT:
      return int_::__and__(x, y);
    }
  }
  throw std::runtime_error("invalid type for &");
}

value __or__(value x, value y) {
  switch (x.type) {
  case value::BOOL:
    switch (y.type) {
    case value::BOOL:
      return bool_::__or__(x, y);
    case value::INT:
      return int_::__or__(bool_::__int__(x), y);
    }
    break;
  case value::INT:
    switch (y.type) {
    case value::BOOL:
      return int_::__or__(x, bool_::__int__(y));
    case value::INT:
      return int_::__or__(x, y);
    }
  }
  throw std::runtime_error("invalid type for |");
}

value __xor__(value x, value y) {
  switch (x.type) {
  case value::BOOL:
    switch (y.type) {
    case value::BOOL:
      return bool_::__xor__(x, y);
    case value::INT:
      return int_::__xor__(bool_::__int__(x), y);
    }
    break;
  case value::INT:
    switch (y.type) {
    case value::BOOL:
      return int_::__xor__(x, bool_::__int__(y));
    case value::INT:
      return int_::__xor__(x, y);
    }
  }
  throw std::runtime_error("invalid type for ^");
}

value __invert__(value self) {
  switch (self.type) {
  case value::BOOL:
    return int_::__invert__(bool_::__int__(self));
  case value::INT:
    return int_::__invert__(self);
  default:
    throw std::runtime_error("invalid type for ~");
  }
}

value __lshift__(value x, value y) {
  switch (x.type) {
  case value::BOOL:
    switch (y.type) {
    case value::BOOL:
      return int_::__lshift__(bool_::__int__(x), bool_::__int__(y));
    case value::INT:
      return int_::__lshift__(bool_::__int__(x), y);
    }
    break;
  case value::INT:
    switch (y.type) {
    case value::BOOL:
      return int_::__lshift__(x, bool_::__int__(y));
    case value::INT:
      return int_::__lshift__(x, y);
    }
  }
  throw std::runtime_error("invalid type for <<");
}

value __rshift__(value x, value y) {
  switch (x.type) {
  case value::BOOL:
    switch (y.type) {
    case value::BOOL:
      return int_::__rshift__(bool_::__int__(x), bool_::__int__(y));
    case value::INT:
      return int_::__rshift__(bool_::__int__(x), y);
    }
    break;
  case value::INT:
    switch (y.type) {
    case value::BOOL:
      return int_::__rshift__(x, bool_::__int__(y));
    case value::INT:
      return int_::__rshift__(x, y);
    }
  }
  throw std::runtime_error("invalid type for >>");
}

value __iter__(value self) {
  if (self.type == value::RANGE) {
    return range::__iter__(self);
  }
  throw std::runtime_error("invalid type for __iter__");
}

value __next__(value self) {
  if (self.type == value::RANGE_ITERATOR) {
    return range_iterator::__next__(self);
  }
  throw std::runtime_error("invalid type for __next__");
}

value append(value self, value v) {
  if (self.type == value::LIST) {
    return list::append(self, v);
  }
  throw std::runtime_error("invalid type for append");
}

value add(value self, value v) {
  if (self.type == value::SET) {
    return set::add(self, v);
  }
  throw std::runtime_error("invalid type for add");
}

value remove(value self, value v) {
  if (self.type == value::SET) {
    return set::remove(self, v);
  }
  throw std::runtime_error("invalid type for remove");
}

value pop(value self) {
  if (self.type == value::LIST) {
    return list::pop(self);
  }
  throw std::runtime_error("invalid type for pop");
}