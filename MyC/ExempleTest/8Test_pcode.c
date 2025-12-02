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

// Declare z of type int with offset 2 at depth 0
LOADI(0)

}

void pcode_main() {
LOADI(5)
// Loading global var x adress (used at depth 1)
LOADI(0) // loading offset 0 of variable x
// Storing variable x (right) value
STORE
LOADI(0)
// Loading global var y adress (used at depth 1)
LOADI(1) // loading offset 1 of variable y
// Storing variable y (right) value
STORE
LOADI(10)
// Loading global var z adress (used at depth 1)
LOADI(2) // loading offset 2 of variable z
// Storing variable z (right) value
STORE
// Debut conditionelle 0
// Loading global var y adress (used at depth 1)
LOADI(1) // loading offset 1 of variable y
// Loading variable y (right) value
LOAD
LOADI(0)
LTI
// Loading global var x adress (used at depth 1)
LOADI(0) // loading offset 0 of variable x
// Loading variable x (right) value
LOAD
LOADI(2)
GTI
ANDI
IFN(False_0)
// la condition 0 est vraie
SAVEBP // Entering instructions block of depth 2
LOADI(1)
// Loading global var z adress (used at depth 2)
LOADBP
LOAD // accessing upper block depth 1
LOAD // accessing upper block depth 0
SHIFT(2) // applying offset 2 of variable z
// Storing variable z (right) value
STORE
RESTOREBP // Exiting instructions block of depth 2
False_0:
// la condition 0 est fausse
// Fin conditionelle 0
}
