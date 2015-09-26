#pragma once

struct value;

void print(value v);
value __add__(value x, value y);
value __sub__(value x, value y);
value __mul__(value x, value y);
value __truediv__(value x, value y);
value __mod__(value x, value y);
value __len__(value self);
value __getitem__(value self, value k);
value __contains__(value self, value v);
void __setitem__(value self, value k, value v);
void __delitem__(value self, value k);
value __bool__(value self);
value __eq__(value x, value y);
value __ne__(value x, value y);
value __ge__(value x, value y);
value __gt__(value x, value y);
value __lt__(value x, value y);
value __le__(value x, value y);
value __and__(value x, value y);
value __or__(value x, value y);
value __xor__(value x, value y);
value __invert__(value self);
value __lshift__(value x, value y);
value __rshift__(value x, value y);