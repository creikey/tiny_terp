#ifndef H_BYTECODE
#define H_BYTECODE

#define BEGIN_EXPR 0x0001
#define END_EXPR 0x0002
#define VARIABLE_START 0x0003
#define VARIABLE_END 0x0004
#define GET_VARIABLE 0x0005
#define GREATER_THAN 0x0006
#define LESS_THAN 0x0007
#define EQUAL_TO 0x0008
#define SET_VARIABLE 0x0009

/*
example expression
0x001 0x003 foo 0x004 0x006 0x003 bar 0x004 0x002
begin var   foo endvar greater var bar varend end
is foo greater than bar?
should return 1 if greater, 0 if not
*/
#endif
