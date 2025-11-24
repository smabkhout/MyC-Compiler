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

// Argument x of function plusUn in TDS with offset -1
void pcode_plusUn() {
// Loading local var x adress declared at depth 1 (used at depth 1)
LOADBP
SHIFT(-1) // applying offset -1 of variable x
// Loading variable x (right) value
LOAD
LOADI(1)
ADDI
// Loading function return adress
LOADBP
SHIFT(-2) // apply returned value offset -2
STORE // store returned value
// Removing variable x at depth 1
}
void pcode_main() {
// Declare x of type int with offset 1 at depth 1
LOADI(0)

// loading default returned value
LOADI(0)
// loading function plusUn arguments
LOADI(1)
SAVEBP
CALL(pcode_plusUn)
RESTOREBP
DROP(1) //remove 1 fun. parameters from stack
 // Loading local var x adress declared at depth 1 (used at depth 1)
LOADBP
SHIFT(1) // applying offset 1 of variable x
// Storing variable x (right) value
STORE
// Removing variable x at depth 1
}
