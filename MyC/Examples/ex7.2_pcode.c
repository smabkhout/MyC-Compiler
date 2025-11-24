// Begin PCode Header
#include "PCode.h"

void pcode_main();
void init_glob_var();

int main() {
init_glob_var();
pcode_main();
return stack[sp-1].int_value;
}
// End PCode Header

void init_glob_var(){
}

void pcode_one() {
LOADI(1)
// Loading function return adress
LOADBP
SHIFT(-1) // apply returned value offset -1
STORE // store returned value
}
void pcode_main() {
// Declare x of type int with offset 1 at depth 1
LOADI(0)

// loading default returned value
LOADI(0)
// loading function one arguments
SAVEBP
CALL(pcode_one)
RESTOREBP
// Loading local var x adress declared at depth 1 (used at depth 1)
LOADBP
SHIFT(1) // applying offset 1 of variable x
// Storing variable x (right) value
STORE
// Removing variable x at depth 1
}
