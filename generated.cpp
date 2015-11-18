
#include "generated.h"
#include "bool.h"
#include "int.h"
#include "float.h"
#include "assert.h"
#include "str.h"
#include "list.h"

value __add__$float_$int_(value x, value y) {
	assert(x.type == value::FLOAT && y.type == value::INT);
	return __add__$float_$float_(x, __float__$int_(y));
}
value __sub__$float_$int_(value x, value y) {
	assert(x.type == value::FLOAT && y.type == value::INT);
	return __sub__$float_$float_(x, __float__$int_(y));
}
value __mul__$float_$int_(value x, value y) {
	assert(x.type == value::FLOAT && y.type == value::INT);
	return __mul__$float_$float_(x, __float__$int_(y));
}
value __truediv__$float_$int_(value x, value y) {
	assert(x.type == value::FLOAT && y.type == value::INT);
	return __truediv__$float_$float_(x, __float__$int_(y));
}
value __lt__$float_$int_(value x, value y) {
	assert(x.type == value::FLOAT && y.type == value::INT);
	return __lt__$float_$float_(x, __float__$int_(y));
}
value __le__$float_$int_(value x, value y) {
	assert(x.type == value::FLOAT && y.type == value::INT);
	return __le__$float_$float_(x, __float__$int_(y));
}
value __gt__$float_$int_(value x, value y) {
	assert(x.type == value::FLOAT && y.type == value::INT);
	return __gt__$float_$float_(x, __float__$int_(y));
}
value __ge__$float_$int_(value x, value y) {
	assert(x.type == value::FLOAT && y.type == value::INT);
	return __ge__$float_$float_(x, __float__$int_(y));
}
value __mod__$float_$int_(value x, value y) {
	assert(x.type == value::FLOAT && y.type == value::INT);
	return __mod__$float_$float_(x, __float__$int_(y));
}
value __eq__$float_$int_(value x, value y) {
	assert(x.type == value::FLOAT && y.type == value::INT);
	return __eq__$float_$float_(x, __float__$int_(y));
}
value __ne__$float_$int_(value x, value y) {
	assert(x.type == value::FLOAT && y.type == value::INT);
	return __ne__$float_$float_(x, __float__$int_(y));
}
value __add__$float_$bool_(value x, value y) {
	assert(x.type == value::FLOAT && y.type == value::BOOL);
	return __add__$float_$float_(x, __float__$bool_(y));
}
value __sub__$float_$bool_(value x, value y) {
	assert(x.type == value::FLOAT && y.type == value::BOOL);
	return __sub__$float_$float_(x, __float__$bool_(y));
}
value __mul__$float_$bool_(value x, value y) {
	assert(x.type == value::FLOAT && y.type == value::BOOL);
	return __mul__$float_$float_(x, __float__$bool_(y));
}
value __truediv__$float_$bool_(value x, value y) {
	assert(x.type == value::FLOAT && y.type == value::BOOL);
	return __truediv__$float_$float_(x, __float__$bool_(y));
}
value __lt__$float_$bool_(value x, value y) {
	assert(x.type == value::FLOAT && y.type == value::BOOL);
	return __lt__$float_$float_(x, __float__$bool_(y));
}
value __le__$float_$bool_(value x, value y) {
	assert(x.type == value::FLOAT && y.type == value::BOOL);
	return __le__$float_$float_(x, __float__$bool_(y));
}
value __gt__$float_$bool_(value x, value y) {
	assert(x.type == value::FLOAT && y.type == value::BOOL);
	return __gt__$float_$float_(x, __float__$bool_(y));
}
value __ge__$float_$bool_(value x, value y) {
	assert(x.type == value::FLOAT && y.type == value::BOOL);
	return __ge__$float_$float_(x, __float__$bool_(y));
}
value __mod__$float_$bool_(value x, value y) {
	assert(x.type == value::FLOAT && y.type == value::BOOL);
	return __mod__$float_$float_(x, __float__$bool_(y));
}
value __eq__$float_$bool_(value x, value y) {
	assert(x.type == value::FLOAT && y.type == value::BOOL);
	return __eq__$float_$float_(x, __float__$bool_(y));
}
value __ne__$float_$bool_(value x, value y) {
	assert(x.type == value::FLOAT && y.type == value::BOOL);
	return __ne__$float_$float_(x, __float__$bool_(y));
}
value __add__$int_$float_(value x, value y) {
	assert(x.type == value::INT && y.type == value::FLOAT);
	return __add__$float_$float_(__float__$int_(x), y);
}
value __sub__$int_$float_(value x, value y) {
	assert(x.type == value::INT && y.type == value::FLOAT);
	return __sub__$float_$float_(__float__$int_(x), y);
}
value __mul__$int_$float_(value x, value y) {
	assert(x.type == value::INT && y.type == value::FLOAT);
	return __mul__$float_$float_(__float__$int_(x), y);
}
value __truediv__$int_$float_(value x, value y) {
	assert(x.type == value::INT && y.type == value::FLOAT);
	return __truediv__$float_$float_(__float__$int_(x), y);
}
value __lt__$int_$float_(value x, value y) {
	assert(x.type == value::INT && y.type == value::FLOAT);
	return __lt__$float_$float_(__float__$int_(x), y);
}
value __le__$int_$float_(value x, value y) {
	assert(x.type == value::INT && y.type == value::FLOAT);
	return __le__$float_$float_(__float__$int_(x), y);
}
value __gt__$int_$float_(value x, value y) {
	assert(x.type == value::INT && y.type == value::FLOAT);
	return __gt__$float_$float_(__float__$int_(x), y);
}
value __ge__$int_$float_(value x, value y) {
	assert(x.type == value::INT && y.type == value::FLOAT);
	return __ge__$float_$float_(__float__$int_(x), y);
}
value __mod__$int_$float_(value x, value y) {
	assert(x.type == value::INT && y.type == value::FLOAT);
	return __mod__$float_$float_(__float__$int_(x), y);
}
value __eq__$int_$float_(value x, value y) {
	assert(x.type == value::INT && y.type == value::FLOAT);
	return __eq__$float_$float_(__float__$int_(x), y);
}
value __ne__$int_$float_(value x, value y) {
	assert(x.type == value::INT && y.type == value::FLOAT);
	return __ne__$float_$float_(__float__$int_(x), y);
}
value __add__$int_$bool_(value x, value y) {
	assert(x.type == value::INT && y.type == value::BOOL);
	return __add__$int_$int_(x, __int__$bool_(y));
}
value __sub__$int_$bool_(value x, value y) {
	assert(x.type == value::INT && y.type == value::BOOL);
	return __sub__$int_$int_(x, __int__$bool_(y));
}
value __mul__$int_$bool_(value x, value y) {
	assert(x.type == value::INT && y.type == value::BOOL);
	return __mul__$int_$int_(x, __int__$bool_(y));
}
value __truediv__$int_$bool_(value x, value y) {
	assert(x.type == value::INT && y.type == value::BOOL);
	return __truediv__$int_$int_(x, __int__$bool_(y));
}
value __lt__$int_$bool_(value x, value y) {
	assert(x.type == value::INT && y.type == value::BOOL);
	return __lt__$int_$int_(x, __int__$bool_(y));
}
value __le__$int_$bool_(value x, value y) {
	assert(x.type == value::INT && y.type == value::BOOL);
	return __le__$int_$int_(x, __int__$bool_(y));
}
value __gt__$int_$bool_(value x, value y) {
	assert(x.type == value::INT && y.type == value::BOOL);
	return __gt__$int_$int_(x, __int__$bool_(y));
}
value __ge__$int_$bool_(value x, value y) {
	assert(x.type == value::INT && y.type == value::BOOL);
	return __ge__$int_$int_(x, __int__$bool_(y));
}
value __xor__$int_$bool_(value x, value y) {
	assert(x.type == value::INT && y.type == value::BOOL);
	return __xor__$int_$int_(x, __int__$bool_(y));
}
value __and__$int_$bool_(value x, value y) {
	assert(x.type == value::INT && y.type == value::BOOL);
	return __and__$int_$int_(x, __int__$bool_(y));
}
value __or__$int_$bool_(value x, value y) {
	assert(x.type == value::INT && y.type == value::BOOL);
	return __or__$int_$int_(x, __int__$bool_(y));
}
value __mod__$int_$bool_(value x, value y) {
	assert(x.type == value::INT && y.type == value::BOOL);
	return __mod__$int_$int_(x, __int__$bool_(y));
}
value __eq__$int_$bool_(value x, value y) {
	assert(x.type == value::INT && y.type == value::BOOL);
	return __eq__$int_$int_(x, __int__$bool_(y));
}
value __ne__$int_$bool_(value x, value y) {
	assert(x.type == value::INT && y.type == value::BOOL);
	return __ne__$int_$int_(x, __int__$bool_(y));
}
value __lshift__$int_$bool_(value x, value y) {
	assert(x.type == value::INT && y.type == value::BOOL);
	return __lshift__$int_$int_(x, __int__$bool_(y));
}
value __rshift__$int_$bool_(value x, value y) {
	assert(x.type == value::INT && y.type == value::BOOL);
	return __rshift__$int_$int_(x, __int__$bool_(y));
}
value __add__$bool_$float_(value x, value y) {
	assert(x.type == value::BOOL && y.type == value::FLOAT);
	return __add__$float_$float_(__float__$bool_(x), y);
}
value __sub__$bool_$float_(value x, value y) {
	assert(x.type == value::BOOL && y.type == value::FLOAT);
	return __sub__$float_$float_(__float__$bool_(x), y);
}
value __mul__$bool_$float_(value x, value y) {
	assert(x.type == value::BOOL && y.type == value::FLOAT);
	return __mul__$float_$float_(__float__$bool_(x), y);
}
value __truediv__$bool_$float_(value x, value y) {
	assert(x.type == value::BOOL && y.type == value::FLOAT);
	return __truediv__$float_$float_(__float__$bool_(x), y);
}
value __lt__$bool_$float_(value x, value y) {
	assert(x.type == value::BOOL && y.type == value::FLOAT);
	return __lt__$float_$float_(__float__$bool_(x), y);
}
value __le__$bool_$float_(value x, value y) {
	assert(x.type == value::BOOL && y.type == value::FLOAT);
	return __le__$float_$float_(__float__$bool_(x), y);
}
value __gt__$bool_$float_(value x, value y) {
	assert(x.type == value::BOOL && y.type == value::FLOAT);
	return __gt__$float_$float_(__float__$bool_(x), y);
}
value __ge__$bool_$float_(value x, value y) {
	assert(x.type == value::BOOL && y.type == value::FLOAT);
	return __ge__$float_$float_(__float__$bool_(x), y);
}
value __mod__$bool_$float_(value x, value y) {
	assert(x.type == value::BOOL && y.type == value::FLOAT);
	return __mod__$float_$float_(__float__$bool_(x), y);
}
value __eq__$bool_$float_(value x, value y) {
	assert(x.type == value::BOOL && y.type == value::FLOAT);
	return __eq__$float_$float_(__float__$bool_(x), y);
}
value __ne__$bool_$float_(value x, value y) {
	assert(x.type == value::BOOL && y.type == value::FLOAT);
	return __ne__$float_$float_(__float__$bool_(x), y);
}
value __add__$bool_$int_(value x, value y) {
	assert(x.type == value::BOOL && y.type == value::INT);
	return __add__$int_$int_(__int__$bool_(x), y);
}
value __sub__$bool_$int_(value x, value y) {
	assert(x.type == value::BOOL && y.type == value::INT);
	return __sub__$int_$int_(__int__$bool_(x), y);
}
value __mul__$bool_$int_(value x, value y) {
	assert(x.type == value::BOOL && y.type == value::INT);
	return __mul__$int_$int_(__int__$bool_(x), y);
}
value __truediv__$bool_$int_(value x, value y) {
	assert(x.type == value::BOOL && y.type == value::INT);
	return __truediv__$int_$int_(__int__$bool_(x), y);
}
value __lt__$bool_$int_(value x, value y) {
	assert(x.type == value::BOOL && y.type == value::INT);
	return __lt__$int_$int_(__int__$bool_(x), y);
}
value __le__$bool_$int_(value x, value y) {
	assert(x.type == value::BOOL && y.type == value::INT);
	return __le__$int_$int_(__int__$bool_(x), y);
}
value __gt__$bool_$int_(value x, value y) {
	assert(x.type == value::BOOL && y.type == value::INT);
	return __gt__$int_$int_(__int__$bool_(x), y);
}
value __ge__$bool_$int_(value x, value y) {
	assert(x.type == value::BOOL && y.type == value::INT);
	return __ge__$int_$int_(__int__$bool_(x), y);
}
value __xor__$bool_$int_(value x, value y) {
	assert(x.type == value::BOOL && y.type == value::INT);
	return __xor__$int_$int_(__int__$bool_(x), y);
}
value __and__$bool_$int_(value x, value y) {
	assert(x.type == value::BOOL && y.type == value::INT);
	return __and__$int_$int_(__int__$bool_(x), y);
}
value __or__$bool_$int_(value x, value y) {
	assert(x.type == value::BOOL && y.type == value::INT);
	return __or__$int_$int_(__int__$bool_(x), y);
}
value __mod__$bool_$int_(value x, value y) {
	assert(x.type == value::BOOL && y.type == value::INT);
	return __mod__$int_$int_(__int__$bool_(x), y);
}
value __eq__$bool_$int_(value x, value y) {
	assert(x.type == value::BOOL && y.type == value::INT);
	return __eq__$int_$int_(__int__$bool_(x), y);
}
value __ne__$bool_$int_(value x, value y) {
	assert(x.type == value::BOOL && y.type == value::INT);
	return __ne__$int_$int_(__int__$bool_(x), y);
}
value __lshift__$bool_$int_(value x, value y) {
	assert(x.type == value::BOOL && y.type == value::INT);
	return __lshift__$int_$int_(__int__$bool_(x), y);
}
value __rshift__$bool_$int_(value x, value y) {
	assert(x.type == value::BOOL && y.type == value::INT);
	return __rshift__$int_$int_(__int__$bool_(x), y);
}
