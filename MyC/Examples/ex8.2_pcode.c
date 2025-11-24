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

// Argument y of function intMult in TDS with offset -1
// Argument x of function intMult in TDS with offset -2
void pcode_intMult() {
// Declare z of type float with offset 1 at depth 1
LOADF(0.0)

// Declare n of type int with offset 2 at depth 1
LOADI(0)

LOADI(0)
I2F2
// Loading local var z adress declared at depth 1 (used at depth 1)
LOADBP
SHIFT(1) // applying offset 1 of variable z
// Storing variable z (right) value
STORE
// Debut conditionelle 0
// Loading local var x adress declared at depth 1 (used at depth 1)
LOADBP
SHIFT(-2) // applying offset -2 of variable x
// Loading variable x (right) value
LOAD
LOADI(0)
LTI
IFN(False_0)
// la condition 0 est vraie
// Loading local var x adress declared at depth 1 (used at depth 1)
LOADBP
SHIFT(-2) // applying offset -2 of variable x
// Loading variable x (right) value
LOAD
MINUSI
// Loading local var n adress declared at depth 1 (used at depth 1)
LOADBP
SHIFT(2) // applying offset 2 of variable n
// Storing variable n (right) value
STORE
GOTO(End_0)
False_0:
// la condition 0 est fausse
// Loading local var x adress declared at depth 1 (used at depth 1)
LOADBP
SHIFT(-2) // applying offset -2 of variable x
// Loading variable x (right) value
LOAD
// Loading local var n adress declared at depth 1 (used at depth 1)
LOADBP
SHIFT(2) // applying offset 2 of variable n
// Storing variable n (right) value
STORE
End_0:
// Fin conditionelle 0
StartLoop_1: // chargement condition boucle while 1
// Loading local var n adress declared at depth 1 (used at depth 1)
LOADBP
SHIFT(2) // applying offset 2 of variable n
// Loading variable n (right) value
LOAD
LOADI(0)
GTI
IFN(EndLoop_1)
// Debut boucle while 1
SAVEBP // entering block
// Loading local var z adress declared at depth 1 (used at depth 2)
LOADBP
LOAD // accessing upper block depth 1
SHIFT(1) // applying offset 1 of variable z
// Loading variable z (right) value
LOAD
// Loading local var y adress declared at depth 1 (used at depth 2)
LOADBP
LOAD // accessing upper block depth 1
SHIFT(-1) // applying offset -1 of variable y
// Loading variable y (right) value
LOAD
ADDF
// Loading local var z adress declared at depth 1 (used at depth 2)
LOADBP
LOAD // accessing upper block depth 1
SHIFT(1) // applying offset 1 of variable z
// Storing variable z (right) value
STORE
// Loading local var n adress declared at depth 1 (used at depth 2)
LOADBP
LOAD // accessing upper block depth 1
SHIFT(2) // applying offset 2 of variable n
// Loading variable n (right) value
LOAD
LOADI(1)
SUBI
// Loading local var n adress declared at depth 1 (used at depth 2)
LOADBP
LOAD // accessing upper block depth 1
SHIFT(2) // applying offset 2 of variable n
// Storing variable n (right) value
STORE
RESTOREBP // exiting block
GOTO(StartLoop_1)
//Fin boucle while 1
 EndLoop_1:
 // Debut conditionelle 2
// Loading local var x adress declared at depth 1 (used at depth 1)
LOADBP
SHIFT(-2) // applying offset -2 of variable x
// Loading variable x (right) value
LOAD
LOADI(0)
LTI
IFN(False_2)
// la condition 2 est vraie
// Loading local var z adress declared at depth 1 (used at depth 1)
LOADBP
SHIFT(1) // applying offset 1 of variable z
// Loading variable z (right) value
LOAD
MINUSF
// Loading function return adress
LOADBP
SHIFT(-3) // apply returned value offset -3
STORE // store returned value
GOTO(End_2)
False_2:
// la condition 2 est fausse
// Loading local var z adress declared at depth 1 (used at depth 1)
LOADBP
SHIFT(1) // applying offset 1 of variable z
// Loading variable z (right) value
LOAD
// Loading function return adress
LOADBP
SHIFT(-3) // apply returned value offset -3
STORE // store returned value
End_2:
// Fin conditionelle 2
// Removing variable n at depth 1
// Removing variable z at depth 1
// Removing variable x at depth 1
// Removing variable y at depth 1
}
void pcode_main() {
// Declare z of type float with offset 1 at depth 1
LOADF(0.0)

// loading default returned value
LOADF(0)
// loading function intMult arguments
LOADI(4)
LOADF(2.300000)
SAVEBP
CALL(pcode_intMult)
RESTOREBP
DROP(2) //remove 2 fun. parameters from stack
 // Loading local var z adress declared at depth 1 (used at depth 1)
LOADBP
SHIFT(1) // applying offset 1 of variable z
// Storing variable z (right) value
STORE
// Removing variable z at depth 1
}
