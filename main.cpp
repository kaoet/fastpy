#include <cstdio>
#include <stdexcept>
#include "type.h"
#include "list.h"
#include "int.h"
#include "float.h"
#include "str.h"
#include "dict.h"
#include "bool.h"
#include "set.h"
#include "func.h"

int main() {
    /*
    value x = list::make();
    value i = int_::make(0);
    while (i != int_::make(2000)) {
        value xx = list::make();
        value j = int_::make(0);
        while (j != int_::make(2000)) {
            list::append(xx, int_::make(0));
            j = __add__(j, int_::make(1));
        }
        list::append(x, xx);
        i = __add__(i, int_::make(1));
    }
    
    value checksum = int_::make(0);
    
    i = int_::make(0);
    while (i != int_::make(2000)) {
        value j = int_::make(0);
        while (j != int_::make(2000)) {
            if (i != int_::make(0) && j != int_::make(0)) {
                value v1 = __getitem__(__getitem__(x, __sub__(i, int_::make(1))), j);
                value v2 = __getitem__(__getitem__(x, i), __sub__(j, int_::make(1)));
                value sum = __add__(v1, v2);
                __setitem__(__getitem__(x, i), j, __mod__(sum, int_::make(123456)));
            } else {
                __setitem__(__getitem__(x, i), j, int_::make(1));
            }
            checksum = __mod__(__add__(checksum, __getitem__(__getitem__(x, i), j)), int_::make(123456));
            j = __add__(j, int_::make(1));
        }
        i = __add__(i, int_::make(1));
    }
    
    print(checksum);
    */
    
    printf("1 / 3 = ");
    print(__truediv__(int_::make(1), int_::make(3)));
    puts("");
    
    printf("1.7 - 2 = ");
    print(__sub__(float_::make(1.7), int_::make(2)));
    puts("");
    
    printf("3 * 2.8 = ");
    print(__mul__(int_::make(3), float_::make(2.8)));
    puts("");
    
    printf("'foo' * 5 = ");
    print(__mul__(str::make("foo"), int_::make(5)));
    puts("");
    
    printf("-1 * 'foo' = ");
    print(__mul__(int_::make(-1), str::make("foo")));
    puts("");
    
    {
        printf("[1, 2] * 5 = ");
        value x = list::make();
        list::append(x, int_::make(1));
        list::append(x, int_::make(2));
        print(__mul__(x, int_::make(5)));
        puts("");
    }
    
    printf("3.6 + 7.4 = ");
    print(__add__(float_::make(3.6), float_::make(7.4)));
    puts("");
    
    printf("'hello' + ' world' = ");
    print(__add__(str::make("hello"), str::make(" world")));
    puts("");
    
    {
        printf("[1, 2] + ['a', 'b'] = ");
        value lista = list::make();
        list::append(lista, int_::make(1));
        list::append(lista, int_::make(2));
        value listb = list::make();
        list::append(listb, str::make("a"));
        list::append(listb, str::make("b"));
        print(__add__(lista, listb));
        puts("");
    }
    
    printf("'a' == 'a' = ");
    print(__eq__(str::make("a"), str::make("a")));
    puts("");
    
    printf("len('hello') = ");
    print(__len__(str::make("hello")));
    puts("");
    
    {
        printf("len([1,'x']) = ");
        value x = list::make();
        list::append(x, int_::make(1));
        list::append(x, str::make("x"));
        print(__len__(x));
        puts("");
    }
    
    printf("'hello'[1] = ");
    print(__getitem__(str::make("hello"), int_::make(1)));
    puts("");
    
    {
        printf("[1,2,3][1] = ");
        value x = list::make();
        list::append(x, int_::make(1));
        list::append(x, int_::make(2));
        list::append(x, int_::make(3));
        print(__getitem__(x, int_::make(1)));
        puts("");
        
        printf("x = [1,2,3]; x[1] = 'foo'; x = ");
        __setitem__(x, int_::make(1), str::make("foo"));
        print(x);
        puts("");
        
        printf("x = [1,'foo',3]; del x[1]; x = ");
        __delitem__(x, int_::make(1));
        print(x);
        puts("");
    }
    
    {
        printf("{1: 2, 'a': 'b'}['a'] = ");
        value d = dict::make();
        __setitem__(d, int_::make(1), int_::make(2));
        __setitem__(d, str::make("a"), str::make("b"));
        print(__getitem__(d, str::make("a")));
        puts("");
        printf("{1: 2, 'a': 'b'}['1'] = ");
        print(__getitem__(d, int_::make(1)));
        puts("");
        printf("1 in {1: 2, 'a': 'b'} = ");
        print(__contains__(d, int_::make(1)));
        puts("");
        printf("1.2 in {1: 2, 'a': 'b'} = ");
        print(__contains__(d, float_::make(1.2)));
        puts("");
        printf("d = {1: 2, 'a': 'b'}; del d['a']; d = ");
        __delitem__(d, str::make("a"));
        print(d);
        puts("");
    }
    
    {
        printf("{1, 2}.add(3) = ");
        value s = set::make();
        set::add(s, int_::make(1));
        set::add(s, int_::make(2));
        set::add(s, int_::make(3));
        print(s);
        puts("");
        
        printf("2 in {1, 2, 3} = ");
        print(__contains__(s, int_::make(2)));
        puts("");
        
        printf("s = {1, 2, 3}; s.remove(3); s = ");
        set::remove(s, int_::make(3));
        print(s);
        puts("");
    }
    
    printf("bool(list()) = ");
    print(__bool__(list::make()));
    puts("");
    
    printf("bool('hello') = ");
    print(__bool__(str::make("hello")));
    puts("");
}