#ifndef H_BYTECODE
#define H_BYTECODE

#define BEGIN_STRING 0x0001
#define END_STRING   0x0002
#define SET_VARIABLE 0x0003
#define VARIABLE_START 0x0004
#define VARIABLE_END 0x0005
#define FREE_VARIABLE 0x0006
#define GET_VARIABLE 0x0007
#define BEGIN_EXPRESSION 0x0008
#define END_EXPRESSION 0x0009
#define GREATER_THAN 0x0010
#define LESS_THAN 0x0011
#define EQUAL_TO 0x0012
#define OR_STATEMENT 0x0013
#define IF_STATEMENT 0x0014
#define ELSE_STATEMENT 0x0015
#define PRINT_STATEMENT 0x0016
#define END_IF_ELSE_STATEMENT 0x0017

/*
Example bytecode
0x0003 sets the variable
0x0004 variable Id
jeff
0x0005 end of variable id
5 variable value
0x0005 end of setting variable

0x0014 0x0008 0x0007 0x0004 jeff 0x0005 0x0010 0x40 0x0009 if jeff is greater than 40
0x0016 0x0001his name is jeff0x0002
0x0017

*/

#endif
