#include "none.h"
#include "bool.h"
#include "assert.h"

namespace none {
    
value make() {
    value ret;
    ret.type = value::NONE;
    return ret;
}

value __bool__(value self) {
    assert(self.type == value::NONE);
    return bool_::make(false);
}

value __eq__(value x, value y) {
    assert(x.type == value::NONE && y.type == value::NONE);
    return bool_::make(true);
}

value __ne__(value x, value y) {
    assert(x.type == value::NONE && y.type == value::NONE);
    return bool_::make(false);
}

}