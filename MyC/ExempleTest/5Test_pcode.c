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

void pcode_main() {
// Entering function block of depth 1
LOADI(5)
// Loading global var x adress (used at depth 1)
LOADI(0) // loading offset 0 of variable x
// Storing variable x (right) value
STORE
StartLoop_0: // chargement condition boucle while 0
// Loading global var x adress (used at depth 1)
LOADI(0) // loading offset 0 of variable x
// Loading variable x (right) value
LOAD
LOADI(0)
GTI
IFN(EndLoop_0)
// Debut boucle while 0
SAVEBP // Entering instructions block of depth 2
// Loading global var x adress (used at depth 2)
LOADBP
LOAD // accessing upper block depth 1
LOAD // accessing upper block depth 0
// Loading variable x (right) value
LOAD
LOADI(1)
SUBI
// Loading global var x adress (used at depth 2)
LOADI(0) // loading offset 0 of variable x
// Storing variable x (right) value
STORE
RESTOREBP // Exiting instructions block of depth 2
GOTO(StartLoop_0)
// Fin boucle while 0
EndLoop_0:
// Exiting function block of depth 1
}
