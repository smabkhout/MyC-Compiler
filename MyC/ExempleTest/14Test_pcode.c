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

// Argument n of function factorial in TDS with offset -1
void pcode_factorial() {
// Debut conditionelle 0
// Loading local var n adress declared at depth 1 (used at depth 1)
LOADBP
SHIFT(-1) // applying offset -1 of variable n
// Loading variable n (right) value
LOAD
LOADI(2)
LTI
IFN(False_0)
// la condition 0 est vraie
SAVEBP // Entering instructions block of depth 2
LOADI(1)
// Loading function return address
LOADBP
LOAD // accessing upper block depth 1
SHIFT(-2) // apply returned value offset -2
STORE // store returned value
RESTOREBP // Exiting instructions block of depth 2
GOTO(End_0)
False_0:
// la condition 0 est fausse
SAVEBP // Entering instructions block of depth 2
// Loading local var n adress declared at depth 1 (used at depth 2)
LOADBP
LOAD // accessing upper block depth 1
SHIFT(-1) // applying offset -1 of variable n
// Loading variable n (right) value
LOAD
// loading default returned value
LOADI(0)
// loading function factorial arguments
// Loading local var n adress declared at depth 1 (used at depth 2)
LOADBP
LOAD // accessing upper block depth 1
SHIFT(-1) // applying offset -1 of variable n
// Loading variable n (right) value
LOAD
LOADI(1)
SUBI
SAVEBP
CALL(pcode_factorial)
RESTOREBP
DROP(1) //remove 1 fun. parameters from stack
MULTI
// Loading function return address
LOADBP
LOAD // accessing upper block depth 1
SHIFT(-2) // apply returned value offset -2
STORE // store returned value
RESTOREBP // Exiting instructions block of depth 2
End_0:
// Fin conditionelle 0
// Removing variable n at depth 1
}
void pcode_main() {
// Declare result of type int with offset 1 at depth 1
LOADI(0)

// loading default returned value
LOADI(0)
// loading function factorial arguments
LOADI(5)
SAVEBP
CALL(pcode_factorial)
RESTOREBP
DROP(1) //remove 1 fun. parameters from stack
// Loading local var result adress declared at depth 1 (used at depth 1)
LOADBP
SHIFT(1) // applying offset 1 of variable result
// Storing variable result (right) value
STORE
// Removing variable result at depth 1
}
