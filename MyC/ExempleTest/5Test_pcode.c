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
// Declare a of type int with offset 0 at depth 0
LOADI(0)

// Declare b of type int with offset 1 at depth 0
LOADI(0)

// Declare max of type int with offset 2 at depth 0
LOADI(0)

}

void pcode_main() {
LOADI(8)
// Loading global var a adress (used at depth 1)
LOADI(0) // loading offset 0 of variable a
// Storing variable a (right) value
STORE
LOADI(12)
// Loading global var b adress (used at depth 1)
LOADI(1) // loading offset 1 of variable b
// Storing variable b (right) value
STORE
// Debut conditionelle 0
// Loading global var a adress (used at depth 1)
LOADI(0) // loading offset 0 of variable a
// Loading variable a (right) value
LOAD
// Loading global var b adress (used at depth 1)
LOADI(1) // loading offset 1 of variable b
// Loading variable b (right) value
LOAD
GTI
IFN(False_0)
// la condition 0 est vraie
SAVEBP // Entering instructions block of depth 2
// Loading global var a adress (used at depth 2)
LOADBP
LOAD // accessing upper block depth 1
LOAD // accessing upper block depth 0
// Loading variable a (right) value
LOAD
// Loading global var max adress (used at depth 2)
LOADBP
LOAD // accessing upper block depth 1
LOAD // accessing upper block depth 0
SHIFT(2) // applying offset 2 of variable max
// Storing variable max (right) value
STORE
RESTOREBP // Exiting instructions block of depth 2
GOTO(End_0)
False_0:
// la condition 0 est fausse
SAVEBP // Entering instructions block of depth 2
// Loading global var b adress (used at depth 2)
LOADBP
LOAD // accessing upper block depth 1
LOAD // accessing upper block depth 0
SHIFT(1) // applying offset 1 of variable b
// Loading variable b (right) value
LOAD
// Loading global var max adress (used at depth 2)
LOADBP
LOAD // accessing upper block depth 1
LOAD // accessing upper block depth 0
SHIFT(2) // applying offset 2 of variable max
// Storing variable max (right) value
STORE
RESTOREBP // Exiting instructions block of depth 2
End_0:
// Fin conditionelle 0
}
