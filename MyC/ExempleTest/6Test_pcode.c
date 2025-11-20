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
// Declare y of type int with offset 0 at depth 0
LOADI(0)

// Declare x of type int with offset 1 at depth 0
LOADI(0)

}

void pcode_main() {
// Entering function block of depth 1
// Debut conditionelle 0
// Loading global var x adress (used at depth 1)
LOADI(1) // loading offset 1 of variable x
SHIFT(1) // applying offset 1 of variable x
// Loading variable x (right) value
LOAD
LOADI(0)
GTI
IFN(False_0)
// la condition 0 est vraie
SAVEBP // Entering instructions block of depth 2
StartLoop_1: // chargement condition boucle while 1
// Loading global var y adress (used at depth 2)
LOADBP
LOAD // accessing upper block depth 1
LOAD // accessing upper block depth 0
// Loading variable y (right) value
LOAD
LOADI(10)
LTI
IFN(EndLoop_1)
// Debut boucle while 1
SAVEBP // Entering instructions block of depth 3
// Loading global var y adress (used at depth 3)
LOADBP
LOAD // accessing upper block depth 2
LOAD // accessing upper block depth 1
LOAD // accessing upper block depth 0
// Loading variable y (right) value
LOAD
LOADI(1)
ADDI
// Loading global var y adress (used at depth 3)
LOADI(0) // loading offset 0 of variable y
// Storing variable y (right) value
STORE
RESTOREBP // Exiting instructions block of depth 3
GOTO(StartLoop_1)
// Fin boucle while 1
EndLoop_1:
RESTOREBP // Exiting instructions block of depth 2
False_0:
// la condition 0 est fausse
// Fin conditionelle 0
// Exiting function block of depth 1
}
