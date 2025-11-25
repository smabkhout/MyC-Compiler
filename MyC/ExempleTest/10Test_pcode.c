// PCode Header
#include "PCode.h"

void pcode_main();
void init_glob_var();

int main() {
init_glob_var();
pcode_main();
return stack[sp-1].int_value;
}


void init_glob_var(){
}

void pcode_getConstant() {
LOADI(42)
}
void pcode_main() {
// Declare result of type int with offset 1 at depth 1
LOADI(0)

// loading default returned value
// loading function getConstant arguments
SAVEBP
CALL(pcode_getConstant)
RESTOREBP
// Loading local var result adress declared at depth 1 (used at depth 1)
LOADBP
SHIFT(1) // applying offset 1 of variable result
// Storing variable result (right) value
STORE
}
