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

// Declare z of type int with offset 1 at depth 0
LOADI(0)

// Declare C of type int with offset 2 at depth 0
LOADI(0)

}

void pcode_main() {
// Entering function block of depth 1
// Declare y of type int with offset 1 at depth 1
LOADI(0)

SAVEBP // Entering instructions block of depth 2
SAVEBP // Entering instructions block of depth 3
SAVEBP // Entering instructions block of depth 4
SAVEBP // Entering instructions block of depth 5
// Loading global var C adress (used at depth 5)
LOADBP
LOAD // accessing upper block depth 4
LOAD // accessing upper block depth 3
LOAD // accessing upper block depth 2
LOAD // accessing upper block depth 1
LOAD // accessing upper block depth 0
SHIFT(2) // applying offset 2 of variable C
// Loading variable C (right) value
LOAD
RESTOREBP // Exiting instructions block of depth 5
RESTOREBP // Exiting instructions block of depth 4
RESTOREBP // Exiting instructions block of depth 3
RESTOREBP // Exiting instructions block of depth 2
// Exiting function block of depth 1
}
