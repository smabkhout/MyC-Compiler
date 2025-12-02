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
// Declare global of type int with offset 0 at depth 0
LOADI(0)

}

void pcode_main() {
// Declare a of type int with offset 1 at depth 1
LOADI(0)

LOADI(10)
// Loading local var a adress declared at depth 1 (used at depth 1)
LOADBP
SHIFT(1) // applying offset 1 of variable a
// Storing variable a (right) value
STORE
SAVEBP // Entering instructions block of depth 2
// Declare b of type int with offset 1 at depth 2
LOADI(0)

LOADI(20)
// Loading local var b adress declared at depth 2 (used at depth 2)
LOADBP
SHIFT(1) // applying offset 1 of variable b
// Storing variable b (right) value
STORE
// Loading local var a adress declared at depth 1 (used at depth 2)
LOADBP
LOAD // accessing upper block depth 1
SHIFT(1) // applying offset 1 of variable a
// Loading variable a (right) value
LOAD
// Loading local var b adress declared at depth 2 (used at depth 2)
LOADBP
SHIFT(1) // applying offset 1 of variable b
// Loading variable b (right) value
LOAD
ADDI
// Loading global var global adress (used at depth 2)
LOADBP
LOAD // accessing upper block depth 1
LOAD // accessing upper block depth 0
// Storing variable global (right) value
STORE
// Removing variable b at depth 2
RESTOREBP // Exiting instructions block of depth 2
// Removing variable a at depth 1
}
