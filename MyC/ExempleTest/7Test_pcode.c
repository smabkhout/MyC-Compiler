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
// Declare i of type int with offset 0 at depth 0
LOADI(0)

// Declare total of type int with offset 1 at depth 0
LOADI(0)

}

void pcode_main() {
LOADI(0)
// Loading global var i adress (used at depth 1)
LOADI(0) // loading offset 0 of variable i
// Storing variable i (right) value
STORE
LOADI(0)
// Loading global var total adress (used at depth 1)
LOADI(1) // loading offset 1 of variable total
SHIFT(1) // applying offset 1 of variable total
// Storing variable total (right) value
STORE
StartLoop_0: // chargement condition boucle while 0
// Loading global var i adress (used at depth 1)
LOADI(0) // loading offset 0 of variable i
// Loading variable i (right) value
LOAD
LOADI(10)
LTI
IFN(EndLoop_0)
// Debut boucle while 0
SAVEBP // Entering instructions block of depth 2
// Debut conditionelle 1
// Loading global var i adress (used at depth 2)
LOADBP
LOAD // accessing upper block depth 1
LOAD // accessing upper block depth 0
// Loading variable i (right) value
LOAD
LOADI(2)
ADDI
LOADI(0)
EQI
IFN(False_1)
// la condition 1 est vraie
SAVEBP // Entering instructions block of depth 3
// Loading global var total adress (used at depth 3)
LOADBP
LOAD // accessing upper block depth 2
LOAD // accessing upper block depth 1
LOAD // accessing upper block depth 0
SHIFT(1) // applying offset 1 of variable total
// Loading variable total (right) value
LOAD
// Loading global var i adress (used at depth 3)
LOADBP
LOAD // accessing upper block depth 2
LOAD // accessing upper block depth 1
LOAD // accessing upper block depth 0
// Loading variable i (right) value
LOAD
ADDI
// Loading global var total adress (used at depth 3)
LOADBP
LOAD // accessing upper block depth 2
LOAD // accessing upper block depth 1
LOAD // accessing upper block depth 0
SHIFT(1) // applying offset 1 of variable total
// Storing variable total (right) value
STORE
RESTOREBP // Exiting instructions block of depth 3
False_1:
// la condition 1 est fausse
// Fin conditionelle 1
// Loading global var i adress (used at depth 2)
LOADBP
LOAD // accessing upper block depth 1
LOAD // accessing upper block depth 0
// Loading variable i (right) value
LOAD
LOADI(1)
ADDI
// Loading global var i adress (used at depth 2)
LOADBP
LOAD // accessing upper block depth 1
LOAD // accessing upper block depth 0
// Storing variable i (right) value
STORE
RESTOREBP // Exiting instructions block of depth 2
GOTO(StartLoop_0)
// Fin boucle while 0
EndLoop_0:
}
