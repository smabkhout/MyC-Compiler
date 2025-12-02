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

// Declare w of type int with offset 3 at depth 0
LOADI(0)

}

void pcode_main() {
LOADI(3)
// Loading global var x adress (used at depth 1)
LOADI(0) // loading offset 0 of variable x
// Storing variable x (right) value
STORE
SAVEBP // Entering instructions block of depth 2
// Declare a of type int with offset 1 at depth 2
LOADI(0)

LOADI(4)
// Loading local var a adress declared at depth 2 (used at depth 2)
LOADBP
SHIFT(1) // applying offset 1 of variable a
// Storing variable a (right) value
STORE
LOADI(1)
// Loading global var w adress (used at depth 2)
LOADBP
LOAD // accessing upper block depth 1
LOAD // accessing upper block depth 0
SHIFT(3) // applying offset 3 of variable w
// Storing variable w (right) value
STORE
// Loading global var z adress (used at depth 2)
LOADBP
LOAD // accessing upper block depth 1
LOAD // accessing upper block depth 0
SHIFT(2) // applying offset 2 of variable z
// Loading variable z (right) value
LOAD
// Removing variable a at depth 2
RESTOREBP // Exiting instructions block of depth 2
}
