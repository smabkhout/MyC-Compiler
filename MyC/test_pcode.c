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
// Entering function block of depth 1
LOADI(1)
// Loading global var x adress (used at depth 1)
LOADI(0) // loading offset 0 of variable x
// Storing variable x (right) value
STORE
LOADI(10)
// Loading global var y adress (used at depth 1)
LOADI(1) // loading offset 1 of variable y
// Storing variable y (right) value
STORE
LOADI(5)
// Loading global var z adress (used at depth 1)
LOADI(2) // loading offset 2 of variable z
// Storing variable z (right) value
STORE
StartLoop_0: // chargement condition boucle while 0
// Loading global var x adress (used at depth 1)
LOADI(0) // loading offset 0 of variable x
// Loading variable x (right) value
LOAD
// Loading global var y adress (used at depth 1)
LOADI(1) // loading offset 1 of variable y
// Loading variable y (right) value
LOAD
LTI
IFN(EndLoop_0)
// Debut boucle while 0
SAVEBP // Entering instructions block of depth 2
// Declare var1 of type int with offset 3 at depth 2
LOADI(0)

LOADI(5)
// Loading global var var1 adress (used at depth 2)
LOADI(3) // loading offset 3 of variable var1
// Storing variable var1 (right) value
STORE
// Debut conditionelle 0
// Loading global var z adress (used at depth 1)
LOADI(2) // loading offset 2 of variable z
// Loading variable z (right) value
LOAD
// Loading global var x adress (used at depth 1)
LOADI(0) // loading offset 0 of variable x
// Loading variable x (right) value
LOAD
GTI
IFN(False_0)
// la condition 0 est vraie
// Loading global var z adress (used at depth 1)
LOADI(2) // loading offset 2 of variable z
// Loading variable z (right) value
LOAD
// Loading global var y adress (used at depth 1)
LOADI(1) // loading offset 1 of variable y
// Loading variable y (right) value
LOAD
ADDI
// Loading global var z adress (used at depth 2)
LOADI(2) // loading offset 2 of variable z
// Storing variable z (right) value
STORE
GOTO(End_0)
False_0:
// la condition 0 est fausse
// Loading global var z adress (used at depth 1)
LOADI(2) // loading offset 2 of variable z
// Loading variable z (right) value
LOAD
// Loading global var y adress (used at depth 1)
LOADI(1) // loading offset 1 of variable y
// Loading variable y (right) value
LOAD
SUBI
// Loading global var z adress (used at depth 2)
LOADI(2) // loading offset 2 of variable z
// Storing variable z (right) value
STORE
End_0:
// Fin conditionelle 0
// Loading global var z adress (used at depth 1)
LOADI(2) // loading offset 2 of variable z
// Loading variable z (right) value
LOAD
RESTOREBP // Exiting instructions block of depth 2
GOTO(StartLoop_0)
// Fin boucle while 0
EndLoop_0:
// Exiting function block of depth 1
}
