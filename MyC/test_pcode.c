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
// Declare u of type int with offset 0 at depth 0
LOADI(0)

// Declare v of type int with offset 1 at depth 0
LOADI(0)

// Declare w of type int with offset 2 at depth 0
LOADI(0)

}

// Argument b of function addRec in TDS with offset -1
// Argument a of function addRec in TDS with offset -2
void pcode_addRec() {
// Debut conditionelle 0
// Loading local var a adress declared at depth 1 (used at depth 1)
LOADBP
SHIFT(-2) // applying offset -2 of variable a
// Loading variable a (right) value
LOAD
LOADI(0)
EQI
IFN(False_0)
// la condition 0 est vraie
// Loading local var b adress declared at depth 1 (used at depth 1)
LOADBP
SHIFT(-1) // applying offset -1 of variable b
// Loading variable b (right) value
LOAD
// Loading function return address
LOADBP
SHIFT(-3) // apply returned value offset -3
STORE // store returned value
GOTO(End_0)
False_0:
// la condition 0 est fausse
// loading default returned value
LOADI(0)
// loading function addRec arguments
// Loading local var a adress declared at depth 1 (used at depth 1)
LOADBP
SHIFT(-2) // applying offset -2 of variable a
// Loading variable a (right) value
LOAD
LOADI(1)
SUBI
// Loading local var b adress declared at depth 1 (used at depth 1)
LOADBP
SHIFT(-1) // applying offset -1 of variable b
// Loading variable b (right) value
LOAD
LOADI(1)
ADDI
SAVEBP
CALL(pcode_addRec)
RESTOREBP
DROP(2) //remove 2 fun. parameters from stack
// Loading function return address
LOADBP
SHIFT(-3) // apply returned value offset -3
STORE // store returned value
End_0:
// Fin conditionelle 0
// Removing variable a at depth 1
// Removing variable b at depth 1
}
void pcode_main() {
// Declare x of type int with offset 1 at depth 1
LOADI(0)

// loading default returned value
LOADI(0)
// loading function addRec arguments
LOADI(7)
LOADI(8)
SAVEBP
CALL(pcode_addRec)
RESTOREBP
DROP(2) //remove 2 fun. parameters from stack
// Loading local var x adress declared at depth 1 (used at depth 1)
LOADBP
SHIFT(1) // applying offset 1 of variable x
// Storing variable x (right) value
STORE
// Loading global var w adress (used at depth 1)
LOADI(2) // loading offset 2 of variable w
SHIFT(2) // applying offset 2 of variable w
// Loading variable w (right) value
LOAD
LOADI(5)
// Removing variable x at depth 1
}
