#include "func.h"
#include "list.h"
#include "int.h"
#include "float.h"
#include "str.h"
#include "dict.h"
#include "bool.h"
#include "set.h"
#include "none.h"

void print(value v) {
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
  case value::DICT:
    throw std::runtime_error("not implemented");
  default:
    throw std::runtime_error("invalid argument type for len");
  }
}

value __getitem__(value self, value k) {
  switch (self.type) {
  case value::STR:
    if (k.type == value::INT)
      return str::__getitem__(self, k);
    break;
  case value::LIST:
    if (k.type == value::INT)
      return list::__getitem__(self, k);
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

void __setitem__(value self, value k, value v) {
  switch (self.type) {
  case value::LIST:
    if (k.type == value::INT) {
      list::__setitem__(self, k, v);
      return;
    }
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

void __delitem__(value self, value k) {
  switch (self.type) {
  case value::LIST:
    list::__delitem__(self, k);
    return;
  case value::DICT:
    switch (k.type) {
    case value::NONE:
    case value::BOOL:
    case value::INT:
    case value::FLOAT:
    case value::STR:
      dict::__delitem__(self, k);
      return;
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