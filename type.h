#pragma once

#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include "func.h"

struct value;
typedef std::vector<value> list_t;
typedef std::string str_t;
typedef std::unordered_set<value> set_t;
typedef std::unordered_map<value, value> dict_t;
typedef struct { long start, stop, step; } range_t;
typedef range_t range_iterator_t;

struct value {
    enum { NONE, BOOL, INT, FLOAT, STR, LIST, SET, DICT, RANGE, RANGE_ITERATOR } type;
    union {
        bool boolval;
        long intval;
        double floatval;
        str_t *strval;
        list_t *listval;
        set_t *setval;
        dict_t *dictval;
        range_t *rangeval;
        range_iterator_t *range_iteratorval;
    };
    
    bool operator ==(value other) const {
        return __eq__(*this, other).boolval;
    }
    
    bool operator !=(value other) const {
        return __ne__(*this, other).boolval;
    }
    
    bool operator <(value other) const {
        return __lt__(*this, other).boolval;
    }
    
    bool operator >(value other) const {
        return __gt__(*this, other).boolval;
    }
    
    bool operator <=(value other) const {
        return __le__(*this, other).boolval;
    }
    
    bool operator >=(value other) const {
        return __ge__(*this, other).boolval;
    }
    
    value operator +(value other) const {
        return __add__(*this, other);
    }
    
    value operator -(value other) const {
        return __sub__(*this, other);
    }
    
    value operator *(value other) const {
        return __mul__(*this, other);
    }
    
    value operator /(value other) const {
        return __truediv__(*this, other);
    }
    
    value operator %(value other) const {
        return __mod__(*this, other);
    }
    
    value operator &(value other) const {
        return __and__(*this, other);
    }
    
    value operator |(value other) const {
        return __or__(*this, other);
    }
    
    value operator ^(value other) const {
        return __xor__(*this, other);
    }
    
    value operator ~() const {
        return __invert__(*this);
    }
    
    value operator <<(value other) const {
        return __lshift__(*this, other);
    }

    value operator >>(value other) const {
        return __rshift__(*this, other);
    }
        
    operator bool() const {
        return __bool__(*this).boolval;
    }
};

namespace std {
    template<>
    struct hash<value> {
        size_t operator ()(value v) const {
            switch (v.type) {
            case value::NONE:
                return -9223372036577629359;
            case value::BOOL:
                return std::hash<bool>()(v.boolval);
            case value::INT:
                return std::hash<long>()(v.intval);
            case value::FLOAT:
                if (v.floatval == (long)v.floatval)
                    return std::hash<long>()((long)v.floatval);
                return std::hash<double>()(v.floatval);
            case value::STR:
                return std::hash<str_t>()(*v.strval);
            default:
                throw std::runtime_error("unhashable type");
            }
        }
    };
}