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

// Argument y of function plus in TDS with offset -1
// Argument x of function plus in TDS with offset -2
void pcode_plus() {
// Debut conditionelle 0
LOADI(1)
IFN(False_0)
// la condition 0 est vraie
LOADI(2)
GOTO(End_0)
False_0:
// la condition 0 est fausse
SAVEBP // Entering instructions block of depth 2
LOADI(5)
// Loading local var x adress declared at depth 1 (used at depth 2)
LOADBP
LOAD // accessing upper block depth 1
SHIFT(-2) // applying offset -2 of variable x
// Loading variable x (right) value
LOAD
// Loading function return address
LOADBP
SHIFT(-3) // apply returned value offset -3
STORE // store returned value
RESTOREBP // Exiting instructions block of depth 2
End_0:
// Fin conditionelle 0
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
ADDI
// Loading function return address
LOADBP
SHIFT(-3) // apply returned value offset -3
STORE // store returned value
}

void pcode_main() {
// Declare z of type float with offset 1 at depth 1
LOADF(0.0)

// loading default returned value
LOADI(0)
// loading function plus arguments
LOADI(1)
LOADI(2)
SAVEBP
CALL(pcode_plus)
RESTOREBP
I2F2
// Loading local var z adress declared at depth 1 (used at depth 1)
LOADBP
SHIFT(1) // applying offset 1 of variable z
// Storing variable z (right) value
STORE
// Removing variable z at depth 1
}

