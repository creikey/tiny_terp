#ifndef H_BYTECODE
#define H_BYTECODE

const int BEGIN_EXPR = 0x0001;
const int END_EXPR = 0x0002;
const int VARIABLE_START = 0x0003;
const int VARIABLE_END = 0x0004;
const int GET_VARIABLE = 0x0005;
const int GREATER_THAN = 0x0006;
const int LESS_THAN = 0x0007;
const int EQUAL_TO = 0x0008;
const int SET_VARIABLE = 0x0009;

extern const int possible_bytes[];

/*
example expression
0x001 0x003 foo 0x004 0x006 0x003 bar 0x004 0x002
begin var   foo endvar greater var bar varend end
is foo greater than bar?
should return 1 if greater, 0 if not
*/
#endif
