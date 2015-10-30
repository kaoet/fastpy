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
  return make$none();
}

value __add__(value x, value y) {
  switch (x.type) {
  case value::BOOL:
    switch (y.type) {
    case value::BOOL:
      return __add__$int_$int_(__int__$bool_(x), __int__$bool_(y));
    case value::INT:
      return __add__$int_$int_(__int__$bool_(x), y);
    case value::FLOAT:
      return __add__$float_$float_(__float__$bool_(x), y);
    }
    break;
  case value::INT:
    switch (y.type) {
    case value::BOOL:
      return __add__$int_$int_(x, __int__$bool_(y));
    case value::INT:
      return __add__$int_$int_(x, y);
    case value::FLOAT:
      return __add__$float_$float_(__float__$int_(x), y);
    }
    break;
  case value::FLOAT:
    switch (y.type) {
    case value::BOOL:
      return __add__$float_$float_(x, __float__$bool_(y));
    case value::INT:
      return __add__$float_$float_(x, __float__$int_(y));
    case value::FLOAT:
      return __add__$float_$float_(x, y);
    }
    break;
  case value::LIST:
    if (y.type == value::LIST) {
      return __add__$list$list(x, y);
    }
    break;
  case value::STR:
    if (y.type == value::STR) {
      return __add__$str$str(x, y);
    }
  }
  throw std::runtime_error("invalid argument type for +");
}

value __sub__(value x, value y) {
  switch (x.type) {
  case value::BOOL:
    switch (y.type) {
    case value::BOOL:
      return __sub__$int_$int_(__int__$bool_(x), __int__$bool_(y));
    case value::INT:
      return __sub__$int_$int_(__int__$bool_(x), y);
    case value::FLOAT:
      return __sub__$float_$float_(__float__$bool_(x), y);
    }
    break;
  case value::INT:
    switch (y.type) {
    case value::BOOL:
      return __sub__$int_$int_(x, __int__$bool_(y));
    case value::INT:
      return __sub__$int_$int_(x, y);
    case value::FLOAT:
      return __sub__$float_$float_(__float__$int_(x), y);
    }
    break;
  case value::FLOAT:
    switch (y.type) {
    case value::BOOL:
      return __sub__$float_$float_(x, __float__$bool_(y));
    case value::INT:
      return __sub__$float_$float_(x, __float__$int_(y));
    case value::FLOAT:
      return __sub__$float_$float_(x, y);
    }
  }
  throw std::runtime_error("invalid argument type for -");
}

value __mul__(value x, value y) {
  switch (x.type) {
  case value::BOOL:
    switch (y.type) {
    case value::BOOL:
      return __mul__$int_$int_(__int__$bool_(x), __int__$bool_(y));
    case value::INT:
      return __mul__$int_$int_(__int__$bool_(x), y);
    case value::FLOAT:
      return __mul__$float_$float_(__float__$bool_(x), y);
    case value::STR:
      return __mul__$str$int_(y, __int__$bool_(x));
    case value::LIST:
      return __mul__$list$int_(y, __int__$bool_(x));
    }
    break;
  case value::INT:
    switch (y.type) {
    case value::BOOL:
      return __mul__$int_$int_(x, __int__$bool_(y));
    case value::INT:
      return __mul__$int_$int_(x, y);
    case value::FLOAT:
      return __mul__$float_$float_(__float__$int_(x), y);
    case value::STR:
      return __mul__$str$int_(y, x);
    case value::LIST:
      return __mul__$list$int_(y, x);
    }
    break;
  case value::FLOAT:
    switch (y.type) {
    case value::BOOL:
      return __mul__$float_$float_(x, __float__$bool_(y));
    case value::INT:
      return __mul__$float_$float_(x, __float__$int_(y));
    case value::FLOAT:
      return __mul__$float_$float_(x, y);
    }
    break;
  case value::STR:
    switch (y.type) {
    case value::BOOL:
      return __mul__$str$int_(x, __int__$bool_(y));
    case value::INT:
      return __mul__$str$int_(x, y);
    }
    break;
  case value::LIST:
    switch (y.type) {
    case value::BOOL:
      return __mul__$list$int_(x, __int__$bool_(y));
    case value::INT:
      return __mul__$list$int_(x, y);
    }
  }
  throw std::runtime_error("invalid argument type for *");
}

value __truediv__(value x, value y) {
  switch (x.type) {
  case value::BOOL:
    switch (y.type) {
    case value::BOOL:
      return __truediv__$float_$float_(__float__$bool_(x), __float__$bool_(y));
    case value::INT:
      return __truediv__$float_$float_(__float__$bool_(x), __float__$int_(y));
    case value::FLOAT:
      return __truediv__$float_$float_(__float__$bool_(x), y);
    }
    break;
  case value::INT:
    switch (y.type) {
    case value::BOOL:
      return __truediv__$float_$float_(__float__$int_(x), __float__$bool_(y));
    case value::INT:
      return __truediv__$float_$float_(__float__$int_(x), __float__$int_(y));
    case value::FLOAT:
      return __truediv__$float_$float_(__float__$int_(x), y);
    }
    break;
  case value::FLOAT:
    switch (y.type) {
    case value::BOOL:
      return __truediv__$float_$float_(x, __float__$bool_(y));
    case value::INT:
      return __truediv__$float_$float_(x, __float__$int_(y));
    case value::FLOAT:
      return __truediv__$float_$float_(x, y);
    }
  }
  throw std::runtime_error("invalid argument type for /");
}

value __mod__(value x, value y) {
  switch (x.type) {
  case value::BOOL:
    switch (y.type) {
    case value::BOOL:
      return __mod__$int_$int_(__int__$bool_(x), __int__$bool_(y));
    case value::INT:
      return __mod__$int_$int_(__int__$bool_(x), y);
    case value::FLOAT:
      return __mod__$float_$float_(__float__$bool_(x), y);
    }
    break;
  case value::INT:
    switch (y.type) {
    case value::BOOL:
      return __mod__$int_$int_(x, __int__$bool_(y));
    case value::INT:
      return __mod__$int_$int_(x, y);
    case value::FLOAT:
      return __mod__$float_$float_(__float__$int_(x), y);
    }
    break;
  case value::FLOAT:
    switch (y.type) {
    case value::BOOL:
      return __mod__$float_$float_(x, __float__$bool_(y));
    case value::INT:
      return __mod__$float_$float_(x, __float__$int_(y));
    case value::FLOAT:
      return __mod__$float_$float_(x, y);
    }
  }
  throw std::runtime_error("invalid argument type for mod");
}

value __len__(value self) {
  switch (self.type) {
  case value::LIST:
    return __len__$list(self);
  case value::STR:
    return __len__$str(self);
  case value::SET:
    return __len__$set(self);
  case value::DICT:
    return __len__$dict(self);
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
      return __getitem__$str$(self, k);
    }
    break;
  case value::LIST:
    switch (k.type) {
    case value::INT:
    case value::SLICE:
      return __getitem__$list$(self, k);
    }
    break;
  case value::DICT:
    switch (k.type) {
    case value::NONE:
    case value::BOOL:
    case value::INT:
    case value::FLOAT:
    case value::STR:
      return __getitem__$dict$(self, k);
    }
  }
  throw std::runtime_error("invalid argument type for []");
}

value __contains__(value self, value v) {
  switch (self.type) {
  case value::STR:
    if (v.type == value::STR)
      return __contains__$str$str(self, v);
    break;
  case value::LIST:
    return __contains__$list$(self, v);
  case value::SET:
    return __contains__$set$(self, v);
  case value::DICT:
    switch (v.type) {
    case value::NONE:
    case value::BOOL:
    case value::INT:
    case value::FLOAT:
    case value::STR:
      return __contains__$dict$(self, v);
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
      return __setitem__$list$$(self, k, v);
    }
    break;
  case value::DICT:
    switch (k.type) {
    case value::NONE:
    case value::BOOL:
    case value::INT:
    case value::FLOAT:
    case value::STR:
      return __setitem__$dict$$(self, k, v);
    }
  }
  throw std::runtime_error("invalid argument type for []=");
}

value __delitem__(value self, value k) {
  switch (self.type) {
  case value::LIST:
    switch (k.type) {
      case value::INT:
        return __delitem__$list$int_(self, k);
      case value::SLICE:
        return __delitem__$list$slice(self, k);
    }
    break;
  case value::DICT:
    switch (k.type) {
    case value::NONE:
    case value::BOOL:
    case value::INT:
    case value::FLOAT:
    case value::STR:
      return __delitem__$dict$(self, k);
    }
  }
  throw std::runtime_error("invalid argument type for del");
}

value __bool__(value self) {
  switch (self.type) {
  case value::NONE:
    return __bool__$none(self);
  case value::BOOL:
    return __bool__$bool_(self);
  case value::INT:
    return __bool__$int_(self);
  case value::FLOAT:
    return __bool__$float_(self);
  case value::STR:
    return __bool__$str(self);
  case value::LIST:
    return __bool__$list(self);
  case value::SET:
    return __bool__$set(self);
  case value::DICT:
    return __bool__$dict(self);
  }
  throw std::runtime_error("invalid argument type for bool()");
}

value __eq__(value x, value y) {
  switch (x.type) {
  case value::NONE:
    if (y.type == value::NONE)
      return __eq__$none$none(x, y);
    break;
  case value::BOOL:
    switch (y.type) {
    case value::BOOL:
      return __eq__$bool_$bool_(x, y);
    case value::INT:
      return __eq__$int_$int_(__int__$bool_(x), y);
    case value::FLOAT:
      return __eq__$float_$float_(__float__$bool_(x), y);
    }
    break;
  case value::INT:
    switch (y.type) {
    case value::BOOL:
      return __eq__$int_$int_(x, __int__$bool_(y));
    case value::INT:
      return __eq__$int_$int_(x, y);
    case value::FLOAT:
      return __eq__$float_$float_(__float__$int_(x), y);
    }
    break;
  case value::FLOAT:
    switch (y.type) {
    case value::BOOL:
      return __eq__$float_$float_(x, __float__$bool_(y));
    case value::INT:
      return __eq__$float_$float_(x, __float__$int_(y));
    case value::FLOAT:
      return __eq__$float_$float_(x, y);
    }
    break;
  case value::STR:
    if (y.type == value::STR)
      return __eq__$str$str(x, y);
    break;
  case value::LIST:
    if (y.type == value::LIST)
      return __eq__$list$list(x, y);
    break;
  case value::SET:
    if (y.type == value::SET)
      return __eq__$set$set(x, y);
    break;
  case value::DICT:
    if (y.type == value::DICT)
      return __eq__$dict$dict(x, y);
    break;
  }
  return make$bool_(false);
}

value __ne__(value x, value y) {
  switch (x.type) {
  case value::NONE:
    if (y.type == value::NONE)
      return __ne__$none$none(x, y);
    break;
  case value::BOOL:
    switch (y.type) {
    case value::BOOL:
      return __ne__$bool_$bool_(x, y);
    case value::INT:
      return __ne__$int_$int_(__int__$bool_(x), y);
    case value::FLOAT:
      return __ne__$float_$float_(__float__$bool_(x), y);
    }
    break;
  case value::INT:
    switch (y.type) {
    case value::BOOL:
      return __ne__$int_$int_(x, __int__$bool_(y));
    case value::INT:
      return __ne__$int_$int_(x, y);
    case value::FLOAT:
      return __ne__$float_$float_(__float__$int_(x), y);
    }
    break;
  case value::FLOAT:
    switch (y.type) {
    case value::BOOL:
      return __ne__$float_$float_(x, __float__$bool_(y));
    case value::INT:
      return __ne__$float_$float_(x, __float__$int_(y));
    case value::FLOAT:
      return __ne__$float_$float_(x, y);
    }
    break;
  case value::STR:
    if (y.type == value::STR)
      return __ne__$str$str(x, y);
    break;
  case value::LIST:
    if (y.type == value::LIST)
      return __ne__$list$list(x, y);
    break;
  case value::SET:
    if (y.type == value::SET)
      return __ne__$set$set(x, y);
    break;
  case value::DICT:
    if (y.type == value::DICT)
      return __ne__$dict$dict(x, y);
    break;
  }
  return make$bool_(true);
}

value __lt__(value x, value y) {
  switch (x.type) {
  case value::BOOL:
    switch (y.type) {
    case value::BOOL:
      return __lt__$bool_$bool_(x, y);
    case value::INT:
      return __lt__$int_$int_(__int__$bool_(x), y);
    case value::FLOAT:
      return __lt__$float_$float_(__float__$bool_(x), y);
    }
    break;
  case value::INT:
    switch (y.type) {
    case value::BOOL:
      return __lt__$int_$int_(x, __int__$bool_(y));
    case value::INT:
      return __lt__$int_$int_(x, y);
    case value::FLOAT:
      return __lt__$float_$float_(__float__$int_(x), y);
    }
    break;
  case value::FLOAT:
    switch (y.type) {
    case value::BOOL:
      return __lt__$float_$float_(x, __float__$bool_(y));
    case value::INT:
      return __lt__$float_$float_(x, __float__$int_(y));
    case value::FLOAT:
      return __lt__$float_$float_(x, y);
    }
    break;
  case value::STR:
    if (y.type == value::STR)
      return __lt__$str$str(x, y);
    break;
  case value::LIST:
    if (y.type == value::LIST)
      return __lt__$list$list(x, y);
    break;
  case value::SET:
    if (y.type == value::SET)
      return __lt__$set$set(x, y);
    break;
  }
  throw std::runtime_error("invalid type for <");
}

value __le__(value x, value y) {
  switch (x.type) {
  case value::BOOL:
    switch (y.type) {
    case value::BOOL:
      return __le__$bool_$bool_(x, y);
    case value::INT:
      return __le__$int_$int_(__int__$bool_(x), y);
    case value::FLOAT:
      return __le__$float_$float_(__float__$bool_(x), y);
    }
    break;
  case value::INT:
    switch (y.type) {
    case value::BOOL:
      return __le__$int_$int_(x, __int__$bool_(y));
    case value::INT:
      return __le__$int_$int_(x, y);
    case value::FLOAT:
      return __le__$float_$float_(__float__$int_(x), y);
    }
    break;
  case value::FLOAT:
    switch (y.type) {
    case value::BOOL:
      return __le__$float_$float_(x, __float__$bool_(y));
    case value::INT:
      return __le__$float_$float_(x, __float__$int_(y));
    case value::FLOAT:
      return __le__$float_$float_(x, y);
    }
    break;
  case value::STR:
    if (y.type == value::STR)
      return __le__$str$str(x, y);
    break;
  case value::LIST:
    if (y.type == value::LIST)
      return __le__$list$list(x, y);
    break;
  case value::SET:
    if (y.type == value::SET)
      return __le__$set$set(x, y);
    break;
  }
  throw std::runtime_error("invalid type for <=");
}

value __ge__(value x, value y) {
  switch (x.type) {
  case value::BOOL:
    switch (y.type) {
    case value::BOOL:
      return __ge__$bool_$bool_(x, y);
    case value::INT:
      return __ge__$int_$int_(__int__$bool_(x), y);
    case value::FLOAT:
      return __ge__$float_$float_(__float__$bool_(x), y);
    }
    break;
  case value::INT:
    switch (y.type) {
    case value::BOOL:
      return __ge__$int_$int_(x, __int__$bool_(y));
    case value::INT:
      return __ge__$int_$int_(x, y);
    case value::FLOAT:
      return __ge__$float_$float_(__float__$int_(x), y);
    }
    break;
  case value::FLOAT:
    switch (y.type) {
    case value::BOOL:
      return __ge__$float_$float_(x, __float__$bool_(y));
    case value::INT:
      return __ge__$float_$float_(x, __float__$int_(y));
    case value::FLOAT:
      return __ge__$float_$float_(x, y);
    }
    break;
  case value::STR:
    if (y.type == value::STR)
      return __ge__$str$str(x, y);
    break;
  case value::LIST:
    if (y.type == value::LIST)
      return __ge__$list$list(x, y);
    break;
  case value::SET:
    if (y.type == value::SET)
      return __ge__$set$set(x, y);
    break;
  }
  throw std::runtime_error("invalid type for >=");
}

value __gt__(value x, value y) {
  switch (x.type) {
  case value::BOOL:
    switch (y.type) {
    case value::BOOL:
      return __gt__$bool_$bool_(x, y);
    case value::INT:
      return __gt__$int_$int_(__int__$bool_(x), y);
    case value::FLOAT:
      return __gt__$float_$float_(__float__$bool_(x), y);
    }
    break;
  case value::INT:
    switch (y.type) {
    case value::BOOL:
      return __gt__$int_$int_(x, __int__$bool_(y));
    case value::INT:
      return __gt__$int_$int_(x, y);
    case value::FLOAT:
      return __gt__$float_$float_(__float__$int_(x), y);
    }
    break;
  case value::FLOAT:
    switch (y.type) {
    case value::BOOL:
      return __gt__$float_$float_(x, __float__$bool_(y));
    case value::INT:
      return __gt__$float_$float_(x, __float__$int_(y));
    case value::FLOAT:
      return __gt__$float_$float_(x, y);
    }
    break;
  case value::STR:
    if (y.type == value::STR)
      return __gt__$str$str(x, y);
    break;
  case value::LIST:
    if (y.type == value::LIST)
      return __gt__$list$list(x, y);
    break;
  case value::SET:
    if (y.type == value::SET)
      return __gt__$set$set(x, y);
    break;
  }
  throw std::runtime_error("invalid type for >");
}

value __and__(value x, value y) {
  switch (x.type) {
  case value::BOOL:
    switch (y.type) {
    case value::BOOL:
      return __and__$bool_$bool_(x, y);
    case value::INT:
      return __and__$int_$int_(__int__$bool_(x), y);
    }
    break;
  case value::INT:
    switch (y.type) {
    case value::BOOL:
      return __and__$int_$int_(x, __int__$bool_(y));
    case value::INT:
      return __and__$int_$int_(x, y);
    }
  }
  throw std::runtime_error("invalid type for &");
}

value __or__(value x, value y) {
  switch (x.type) {
  case value::BOOL:
    switch (y.type) {
    case value::BOOL:
      return __or__$bool_$bool_(x, y);
    case value::INT:
      return __or__$int_$int_(__int__$bool_(x), y);
    }
    break;
  case value::INT:
    switch (y.type) {
    case value::BOOL:
      return __or__$int_$int_(x, __int__$bool_(y));
    case value::INT:
      return __or__$int_$int_(x, y);
    }
  }
  throw std::runtime_error("invalid type for |");
}

value __xor__(value x, value y) {
  switch (x.type) {
  case value::BOOL:
    switch (y.type) {
    case value::BOOL:
      return __xor__$bool_$bool_(x, y);
    case value::INT:
      return __xor__$int_$int_(__int__$bool_(x), y);
    }
    break;
  case value::INT:
    switch (y.type) {
    case value::BOOL:
      return __xor__$int_$int_(x, __int__$bool_(y));
    case value::INT:
      return __xor__$int_$int_(x, y);
    }
  }
  throw std::runtime_error("invalid type for ^");
}

value __invert__(value self) {
  switch (self.type) {
  case value::BOOL:
    return __invert__$int_(__int__$bool_(self));
  case value::INT:
    return __invert__$int_(self);
  default:
    throw std::runtime_error("invalid type for ~");
  }
}

value __lshift__(value x, value y) {
  switch (x.type) {
  case value::BOOL:
    switch (y.type) {
    case value::BOOL:
      return __lshift__$int_$int_(__int__$bool_(x), __int__$bool_(y));
    case value::INT:
      return __lshift__$int_$int_(__int__$bool_(x), y);
    }
    break;
  case value::INT:
    switch (y.type) {
    case value::BOOL:
      return __lshift__$int_$int_(x, __int__$bool_(y));
    case value::INT:
      return __lshift__$int_$int_(x, y);
    }
  }
  throw std::runtime_error("invalid type for <<");
}

value __rshift__(value x, value y) {
  switch (x.type) {
  case value::BOOL:
    switch (y.type) {
    case value::BOOL:
      return __rshift__$int_$int_(__int__$bool_(x), __int__$bool_(y));
    case value::INT:
      return __rshift__$int_$int_(__int__$bool_(x), y);
    }
    break;
  case value::INT:
    switch (y.type) {
    case value::BOOL:
      return __rshift__$int_$int_(x, __int__$bool_(y));
    case value::INT:
      return __rshift__$int_$int_(x, y);
    }
  }
  throw std::runtime_error("invalid type for >>");
}

value __iter__(value self) {
  if (self.type == value::RANGE) {
    return __iter__$range(self);
  }
  throw std::runtime_error("invalid type for __iter__");
}

value __next__(value self) {
  if (self.type == value::RANGE_ITERATOR) {
    return __next__$range_iterator(self);
  }
  throw std::runtime_error("invalid type for __next__");
}

value append(value self, value v) {
  if (self.type == value::LIST) {
    return append$list$(self, v);
  }
  throw std::runtime_error("invalid type for append");
}

value add(value self, value v) {
  if (self.type == value::SET) {
    return add$set$(self, v);
  }
  throw std::runtime_error("invalid type for add");
}

value remove(value self, value v) {
  if (self.type == value::SET) {
    return remove$set$(self, v);
  }
  throw std::runtime_error("invalid type for remove");
}

value pop(value self) {
  if (self.type == value::LIST) {
    return pop$list(self);
  }
  throw std::runtime_error("invalid type for pop");
}