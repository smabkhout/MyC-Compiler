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

// Argument target of function findI in TDS with offset -1
void pcode_findI() {
// Declare i of type int with offset 1 at depth 1
LOADI(0)

LOADI(1)
// Loading local var i adress declared at depth 1 (used at depth 1)
LOADBP
SHIFT(1) // applying offset 1 of variable i
// Storing variable i (right) value
STORE
SAVEBP // Entering instructions block of depth 2
// Declare u of type int with offset 1 at depth 2
LOADI(0)

// Debut conditionelle 0
// Loading local var i adress declared at depth 1 (used at depth 2)
LOADBP
LOAD // accessing upper block depth 1
SHIFT(1) // applying offset 1 of variable i
// Loading variable i (right) value
LOAD
// Loading local var target adress declared at depth 1 (used at depth 2)
LOADBP
LOAD // accessing upper block depth 1
SHIFT(-1) // applying offset -1 of variable target
// Loading variable target (right) value
LOAD
EQI
IFN(False_0)
// la condition 0 est vraie
SAVEBP // Entering instructions block of depth 3
// Loading local var i adress declared at depth 1 (used at depth 3)
LOADBP
LOAD // accessing upper block depth 2
LOAD // accessing upper block depth 1
SHIFT(1) // applying offset 1 of variable i
// Loading variable i (right) value
LOAD
// Loading function return address
LOADBP
LOAD // accessing upper block depth 2
LOAD // accessing upper block depth 1
SHIFT(-2) // apply returned value offset -2
STORE // store returned value
RESTOREBP // Exiting instructions block of depth 3
GOTO(End_0)
False_0:
// la condition 0 est fausse
SAVEBP // Entering instructions block of depth 3
// Loading local var u adress declared at depth 2 (used at depth 3)
LOADBP
LOAD // accessing upper block depth 2
SHIFT(1) // applying offset 1 of variable u
// Loading variable u (right) value
LOAD
// Loading function return address
LOADBP
LOAD // accessing upper block depth 2
LOAD // accessing upper block depth 1
SHIFT(-2) // apply returned value offset -2
STORE // store returned value
RESTOREBP // Exiting instructions block of depth 3
End_0:
// Fin conditionelle 0
// Removing variable u at depth 2
RESTOREBP // Exiting instructions block of depth 2
}
void pcode_main() {
// Declare found of type int with offset 1 at depth 1
LOADI(0)

// loading default returned value
LOADI(0)
// loading function findI arguments
LOADI(7)
SAVEBP
CALL(pcode_findI)
RESTOREBP
DROP(1) //remove 1 fun. parameters from stack
// Loading local var found adress declared at depth 1 (used at depth 1)
LOADBP
SHIFT(1) // applying offset 1 of variable found
// Storing variable found (right) value
STORE
}
