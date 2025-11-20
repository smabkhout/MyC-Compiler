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

}

void pcode_main() {
// Entering function block of depth 1
// Declare y of type int with offset 1 at depth 1
LOADI(0)

LOADI(3)
// Loading global var x adress (used at depth 1)
LOADI(0) // loading offset 0 of variable x
// Storing variable x (right) value
STORE
SAVEBP // Entering instructions block of depth 2
// Declare x of type int with offset 1 at depth 2
LOADI(0)

LOADI(4)
// Loading local var x adress declared at depth 2 (used at depth 2)
LOADBP
SHIFT(1) // applying offset 1 of variable x
// Storing variable x (right) value
STORE
// Loading local var x adress declared at depth 2 (used at depth 2)
LOADBP
SHIFT(1) // applying offset 1 of variable x
// Loading variable x (right) value
LOAD
// Loading local var y adress declared at depth 2 (used at depth 1)
LOADBP
SHIFT(1) // applying offset 1 of variable y
// Storing variable y (right) value
STORE
RESTOREBP // Exiting instructions block of depth 2
// Loading local var y adress declared at depth 1 (used at depth 1)
LOADBP
SHIFT(1) // applying offset 1 of variable y
// Loading variable y (right) value
LOAD
// Exiting function block of depth 1
}
