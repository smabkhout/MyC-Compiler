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

// Argument y of function min in TDS with offset -1
// Argument x of function min in TDS with offset -2
void pcode_min() {
// Debut conditionelle 0
// Loading local var x adress declared at depth 1 (used at depth 1)
LOADBP
SHIFT(-2) // applying offset -2 of variable x
// Loading variable x (right) value
LOAD
// Loading local var y adress declared at depth 1 (used at depth 1)
LOADBP
SHIFT(-1) // applying offset -1 of variable y
// Loading variable y (right) value
LOAD
LTI
IFN(False_0)
// la condition 0 est vraie
SAVEBP // entering block
// Loading local var x adress declared at depth 1 (used at depth 2)
LOADBP
LOAD // accessing upper block depth 1
SHIFT(-2) // applying offset -2 of variable x
// Loading variable x (right) value
LOAD
// Loading function return adress
LOADBP
LOAD // accessing upper block depth 1
SHIFT(-3) // apply returned value offset -3
STORE // store returned value
RESTOREBP // exiting block
GOTO(End_0)
False_0:
// la condition 0 est fausse
SAVEBP // entering block
// Loading local var y adress declared at depth 1 (used at depth 2)
LOADBP
LOAD // accessing upper block depth 1
SHIFT(-1) // applying offset -1 of variable y
// Loading variable y (right) value
LOAD
// Loading function return adress
LOADBP
LOAD // accessing upper block depth 1
SHIFT(-3) // apply returned value offset -3
STORE // store returned value
RESTOREBP // exiting block
End_0:
// Fin conditionelle 0
// Removing variable x at depth 1
// Removing variable y at depth 1
}
void pcode_main() {
// Declare z of type float with offset 1 at depth 1
LOADF(0.0)

// loading default returned value
LOADI(0)
// loading function min arguments
LOADI(1)
LOADI(2)
SAVEBP
CALL(pcode_min)
RESTOREBP
DROP(2) //remove 2 fun. parameters from stack
 I2F2
// Loading local var z adress declared at depth 1 (used at depth 1)
LOADBP
SHIFT(1) // applying offset 1 of variable z
// Storing variable z (right) value
STORE
// Removing variable z at depth 1
}
