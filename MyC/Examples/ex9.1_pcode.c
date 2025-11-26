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

// Argument x of function fact in TDS with offset -1
void pcode_fact() {
// Debut conditionelle 0
// Loading local var x adress declared at depth 1 (used at depth 1)
LOADBP
SHIFT(-1) // applying offset -1 of variable x
// Loading variable x (right) value
LOAD
LOADI(1)
LTI
IFN(False_0)
// la condition 0 est vraie
LOADI(1)
// Loading function return adress
LOADBP
SHIFT(-2) // apply returned value offset -2
STORE // store returned value
False_0:
// la condition 0 est fausse
// Fin conditionelle 0
// Loading local var x adress declared at depth 1 (used at depth 1)
LOADBP
SHIFT(-1) // applying offset -1 of variable x
// Loading variable x (right) value
LOAD
// loading default returned value
LOADI(0)
// loading function fact arguments
// Loading local var x adress declared at depth 1 (used at depth 1)
LOADBP
SHIFT(-1) // applying offset -1 of variable x
// Loading variable x (right) value
LOAD
LOADI(1)
SUBI
SAVEBP
CALL(pcode_fact)
RESTOREBP
DROP(1) //remove 1 fun. parameters from stack
 MULTI
// Loading function return adress
LOADBP
SHIFT(-2) // apply returned value offset -2
STORE // store returned value
// Removing variable x at depth 1
}
void pcode_main() {
// loading default returned value
LOADI(0)
// loading function fact arguments
LOADI(5)
SAVEBP
CALL(pcode_fact)
RESTOREBP
DROP(1) //remove 1 fun. parameters from stack
 }
