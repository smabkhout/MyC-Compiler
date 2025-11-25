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

// Argument n of function isEven in TDS with offset -1
// First declaration of function pcode_isEven
// Removing variable n at depth 1
// Argument n of function isOdd in TDS with offset -2
// First declaration of function pcode_isOdd
// Removing variable n at depth 1
// Argument n of function isEven in TDS with offset -3
void pcode_isEven() {
// Debut conditionelle 0
// Loading local var n adress declared at depth 1 (used at depth 1)
LOADBP
SHIFT(-3) // applying offset -3 of variable n
// Loading variable n (right) value
LOAD
LOADI(0)
EQI
IFN(False_0)
// la condition 0 est vraie
SAVEBP // Entering instructions block of depth 2
LOADI(1)
// Loading function return address
LOADBP
LOAD // accessing upper block depth 1
SHIFT(-4) // apply returned value offset -4
STORE // store returned value
RESTOREBP // Exiting instructions block of depth 2
GOTO(End_0)
False_0:
// la condition 0 est fausse
SAVEBP // Entering instructions block of depth 2
// loading default returned value
LOADI(0)
// loading function isOdd arguments
// Loading local var n adress declared at depth 1 (used at depth 2)
LOADBP
LOAD // accessing upper block depth 1
SHIFT(-3) // applying offset -3 of variable n
// Loading variable n (right) value
LOAD
LOADI(1)
SUBI
SAVEBP
CALL(pcode_isOdd)
RESTOREBP
DROP(1) //remove 1 fun. parameters from stack
// Loading function return address
LOADBP
LOAD // accessing upper block depth 1
SHIFT(-4) // apply returned value offset -4
STORE // store returned value
RESTOREBP // Exiting instructions block of depth 2
End_0:
// Fin conditionelle 0
// Removing variable n at depth 1
}
// Argument n of function isOdd in TDS with offset -1
void pcode_isOdd() {
// Debut conditionelle 1
// Loading local var n adress declared at depth 1 (used at depth 1)
LOADBP
SHIFT(-1) // applying offset -1 of variable n
// Loading variable n (right) value
LOAD
LOADI(0)
EQI
IFN(False_1)
// la condition 1 est vraie
SAVEBP // Entering instructions block of depth 2
LOADI(0)
// Loading function return address
LOADBP
LOAD // accessing upper block depth 1
SHIFT(-2) // apply returned value offset -2
STORE // store returned value
RESTOREBP // Exiting instructions block of depth 2
GOTO(End_1)
False_1:
// la condition 1 est fausse
SAVEBP // Entering instructions block of depth 2
// loading default returned value
LOADI(0)
// loading function isEven arguments
// Loading local var n adress declared at depth 1 (used at depth 2)
LOADBP
LOAD // accessing upper block depth 1
SHIFT(-1) // applying offset -1 of variable n
// Loading variable n (right) value
LOAD
LOADI(1)
SUBI
SAVEBP
CALL(pcode_isEven)
RESTOREBP
DROP(1) //remove 1 fun. parameters from stack
// Loading function return address
LOADBP
LOAD // accessing upper block depth 1
SHIFT(-2) // apply returned value offset -2
STORE // store returned value
RESTOREBP // Exiting instructions block of depth 2
End_1:
// Fin conditionelle 1
// Removing variable n at depth 1
}
void pcode_main() {
// Declare e of type int with offset 1 at depth 1
LOADI(0)

// Declare o of type int with offset 2 at depth 1
LOADI(0)

// loading default returned value
LOADI(0)
// loading function isEven arguments
LOADI(4)
SAVEBP
CALL(pcode_isEven)
RESTOREBP
DROP(1) //remove 1 fun. parameters from stack
// Loading local var e adress declared at depth 1 (used at depth 1)
LOADBP
SHIFT(1) // applying offset 1 of variable e
// Storing variable e (right) value
STORE
// loading default returned value
LOADI(0)
// loading function isOdd arguments
LOADI(4)
SAVEBP
CALL(pcode_isOdd)
RESTOREBP
DROP(1) //remove 1 fun. parameters from stack
// Loading local var o adress declared at depth 1 (used at depth 1)
LOADBP
SHIFT(2) // applying offset 2 of variable o
// Storing variable o (right) value
STORE
// Removing variable o at depth 1
// Removing variable e at depth 1
}
