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

// Argument y of function add in TDS with offset -1
// Argument x of function add in TDS with offset -2
void pcode_add() {
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
return ()
// Removing variable x at depth 1
// Removing variable y at depth 1
}
// Argument b of function multiply in TDS with offset -1
// Argument a of function multiply in TDS with offset -2
void pcode_multiply() {
// Loading local var a adress declared at depth 1 (used at depth 1)
LOADBP
SHIFT(-2) // applying offset -2 of variable a
// Loading variable a (right) value
LOAD
// Loading local var b adress declared at depth 1 (used at depth 1)
LOADBP
SHIFT(-1) // applying offset -1 of variable b
// Loading variable b (right) value
LOAD
SAVEBP // Entering instructions block of depth 2
SAVEBP // Entering instructions block of depth 3
SAVEBP // Entering instructions block of depth 4
SAVEBP // Entering instructions block of depth 5
SAVEBP // Entering instructions block of depth 6
SAVEBP // Entering instructions block of depth 7
// Loading local var a adress declared at depth 1 (used at depth 7)
LOADBP
LOAD // accessing upper block depth 6
LOAD // accessing upper block depth 5
LOAD // accessing upper block depth 4
LOAD // accessing upper block depth 3
LOAD // accessing upper block depth 2
LOAD // accessing upper block depth 1
SHIFT(-2) // applying offset -2 of variable a
// Loading variable a (right) value
LOAD
// Loading local var b adress declared at depth 1 (used at depth 7)
LOADBP
LOAD // accessing upper block depth 6
LOAD // accessing upper block depth 5
LOAD // accessing upper block depth 4
LOAD // accessing upper block depth 3
LOAD // accessing upper block depth 2
LOAD // accessing upper block depth 1
SHIFT(-1) // applying offset -1 of variable b
// Loading variable b (right) value
LOAD
MULTI
// Loading function return address
LOADBP
LOAD // accessing upper block depth 6
LOAD // accessing upper block depth 5
LOAD // accessing upper block depth 4
LOAD // accessing upper block depth 3
LOAD // accessing upper block depth 2
LOAD // accessing upper block depth 1
SHIFT(-3) // apply returned value offset -3
STORE // store returned value
RESTOREBP // Exiting instructions block of depth 6
RESTOREBP // Exiting instructions block of depth 5
RESTOREBP // Exiting instructions block of depth 4
RESTOREBP // Exiting instructions block of depth 3
RESTOREBP // Exiting instructions block of depth 2
return ()
RESTOREBP // Exiting instructions block of depth 7
RESTOREBP // Exiting instructions block of depth 6
RESTOREBP // Exiting instructions block of depth 5
RESTOREBP // Exiting instructions block of depth 4
RESTOREBP // Exiting instructions block of depth 3
RESTOREBP // Exiting instructions block of depth 2
// Loading local var a adress declared at depth 1 (used at depth 1)
LOADBP
SHIFT(-2) // applying offset -2 of variable a
// Loading variable a (right) value
LOAD
// Loading local var b adress declared at depth 1 (used at depth 1)
LOADBP
SHIFT(-1) // applying offset -1 of variable b
// Loading variable b (right) value
LOAD
MULTI
// Loading function return address
LOADBP
SHIFT(-3) // apply returned value offset -3
STORE // store returned value
return ()
// Removing variable a at depth 1
// Removing variable b at depth 1
}
void pcode_main() {
// Declare result of type int with offset 1 at depth 1
LOADI(0)

// loading default returned value
LOADI(0)
// loading function add arguments
// loading default returned value
LOADF(0.0)
// loading function multiply arguments
LOADI(2)
LOADI(3)
SAVEBP
CALL(pcode_multiply)
RESTOREBP
DROP(2) //remove 2 fun. parameters from stack
// loading default returned value
LOADF(0.0)
// loading function multiply arguments
LOADI(4)
LOADI(5)
SAVEBP
CALL(pcode_multiply)
RESTOREBP
DROP(3) //remove 3 fun. parameters from stack
SAVEBP
CALL(pcode_add)
RESTOREBP
DROP(1) //remove 1 fun. parameters from stack
// Loading local var result adress declared at depth 1 (used at depth 1)
LOADBP
SHIFT(1) // applying offset 1 of variable result
// Storing variable result (right) value
STORE
// Removing variable result at depth 1
}
