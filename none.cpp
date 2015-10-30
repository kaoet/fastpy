#include "none.h"
#include "bool.h"
#include "assert.h"
 
value make$none() {
    value ret;
    ret.type = value::NONE;
    return ret;
}

value __bool__$none(value self) {
    assert(self.type == value::NONE);
    return make$bool_(false);
}

value __eq__$none$none(value x, value y) {
    assert(x.type == value::NONE && y.type == value::NONE);
    return make$bool_(true);
}

value __ne__$none$none(value x, value y) {
    assert(x.type == value::NONE && y.type == value::NONE);
    return make$bool_(false);
}
