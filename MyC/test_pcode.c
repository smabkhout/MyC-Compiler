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
// Declare x of type int with offset 0 at depth 0
LOADI(0)

// Declare y of type int with offset 1 at depth 0
LOADI(0)

}

// Argument n of function factorialRec in TDS with offset -1
void pcode_factorialRec() {
// Debut conditionelle 0
// Loading local var n adress declared at depth 1 (used at depth 1)
LOADBP
SHIFT(-1) // applying offset -1 of variable n
// Loading variable n (right) value
LOAD
LOADI(1)
EQI
IFN(False_0)
// la condition 0 est vraie
LOADI(1)
// Loading function return address
LOADBP
SHIFT(-2) // apply returned value offset -2
STORE // store returned value
GOTO(End_0)
False_0:
// la condition 0 est fausse
// Loading local var n adress declared at depth 1 (used at depth 1)
LOADBP
SHIFT(-1) // applying offset -1 of variable n
// Loading variable n (right) value
LOAD
// loading default returned value
LOADI(0)
// loading function factorialRec arguments
// Loading local var n adress declared at depth 1 (used at depth 1)
LOADBP
SHIFT(-1) // applying offset -1 of variable n
// Loading variable n (right) value
LOAD
LOADI(1)
SUBI
SAVEBP
CALL(pcode_factorialRec)
RESTOREBP
DROP(1) //remove 1 fun. parameters from stack
MULTI
// Loading function return address
LOADBP
SHIFT(-2) // apply returned value offset -2
STORE // store returned value
End_0:
// Fin conditionelle 0
// Removing variable n at depth 1
}
void pcode_main() {
LOADI(5)
// Loading global var x adress (used at depth 1)
LOADI(0) // loading offset 0 of variable x
// Storing variable x (right) value
STORE
// loading default returned value
LOADI(0)
// loading function factorialRec arguments
// Loading global var x adress (used at depth 1)
LOADI(0) // loading offset 0 of variable x
// Loading variable x (right) value
LOAD
SAVEBP
CALL(pcode_factorialRec)
RESTOREBP
DROP(1) //remove 1 fun. parameters from stack
// Loading global var y adress (used at depth 1)
LOADI(1) // loading offset 1 of variable y
// Storing variable y (right) value
STORE
}
