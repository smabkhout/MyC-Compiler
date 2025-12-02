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
// Declare counter of type int with offset 0 at depth 0
LOADI(0)

// Declare sum of type int with offset 1 at depth 0
LOADI(0)

}

void pcode_main() {
LOADI(0)
// Loading global var counter adress (used at depth 1)
LOADI(0) // loading offset 0 of variable counter
// Storing variable counter (right) value
STORE
LOADI(0)
// Loading global var sum adress (used at depth 1)
LOADI(1) // loading offset 1 of variable sum
// Storing variable sum (right) value
STORE
StartLoop_0: // chargement condition boucle while 0
// Loading global var counter adress (used at depth 1)
LOADI(0) // loading offset 0 of variable counter
// Loading variable counter (right) value
LOAD
LOADI(5)
LTI
IFN(EndLoop_0)
// Debut boucle while 0
SAVEBP // Entering instructions block of depth 2
// Loading global var sum adress (used at depth 2)
LOADBP
LOAD // accessing upper block depth 1
LOAD // accessing upper block depth 0
SHIFT(1) // applying offset 1 of variable sum
// Loading variable sum (right) value
LOAD
// Loading global var counter adress (used at depth 2)
LOADBP
LOAD // accessing upper block depth 1
LOAD // accessing upper block depth 0
// Loading variable counter (right) value
LOAD
ADDI
// Loading global var sum adress (used at depth 2)
LOADBP
LOAD // accessing upper block depth 1
LOAD // accessing upper block depth 0
SHIFT(1) // applying offset 1 of variable sum
// Storing variable sum (right) value
STORE
// Loading global var counter adress (used at depth 2)
LOADBP
LOAD // accessing upper block depth 1
LOAD // accessing upper block depth 0
// Loading variable counter (right) value
LOAD
LOADI(1)
ADDI
// Loading global var counter adress (used at depth 2)
LOADBP
LOAD // accessing upper block depth 1
LOAD // accessing upper block depth 0
// Storing variable counter (right) value
STORE
RESTOREBP // Exiting instructions block of depth 2
GOTO(StartLoop_0)
// Fin boucle while 0
EndLoop_0:
}
