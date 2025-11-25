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

// Argument n of function isOdd in TDS with offset -1
// Argument n of function isEven in TDS with offset -2
void pcode_isEven() {
// Debut conditionelle 0
// Loading local var n adress declared at depth 1 (used at depth 1)
LOADBP
SHIFT(-2) // applying offset -2 of variable n
// Loading variable n (right) value
LOAD
LOADI(0)
EQI
IFN(False_0)
// la condition 0 est vraie
LOADI(1)
// Loading function return address
LOADBP
SHIFT(-3) // apply returned value offset -3
STORE // store returned value
False_0:
// la condition 0 est fausse
// Fin conditionelle 0
// loading default returned value
LOADI(0)
// loading function isOdd arguments
// Loading local var n adress declared at depth 1 (used at depth 1)
LOADBP
SHIFT(-2) // applying offset -2 of variable n
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
SHIFT(-3) // apply returned value offset -3
STORE // store returned value
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
LOADI(0)
// Loading function return address
LOADBP
SHIFT(-2) // apply returned value offset -2
STORE // store returned value
False_1:
// la condition 1 est fausse
// Fin conditionelle 1
// loading default returned value
LOADI(0)
// loading function isEven arguments
// Loading local var n adress declared at depth 1 (used at depth 1)
LOADBP
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
SHIFT(-2) // apply returned value offset -2
STORE // store returned value
// Removing variable n at depth 1
}
void pcode_main() {
// Declare result of type int with offset 1 at depth 1
LOADI(0)

// loading default returned value
LOADI(0)
// loading function isEven arguments
LOADI(5)
SAVEBP
CALL(pcode_isEven)
RESTOREBP
DROP(1) //remove 1 fun. parameters from stack
// Loading local var result adress declared at depth 1 (used at depth 1)
LOADBP
SHIFT(1) // applying offset 1 of variable result
// Storing variable result (right) value
STORE
// Removing variable result at depth 1
}
