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

// Declare z of type float with offset 2 at depth 0
LOADF(0.0)

}

void pcode_main() {
LOADI(5)
// Loading global var x adress (used at depth 1)
LOADI(0) // loading offset 0 of variable x
// Storing variable x (right) value
STORE
LOADI(9)
// Loading global var y adress (used at depth 1)
LOADI(1) // loading offset 1 of variable y
SHIFT(1) // applying offset 1 of variable y
// Storing variable y (right) value
STORE
// Loading global var x adress (used at depth 1)
LOADI(0) // loading offset 0 of variable x
// Loading variable x (right) value
LOAD
// Loading global var y adress (used at depth 1)
LOADI(1) // loading offset 1 of variable y
SHIFT(1) // applying offset 1 of variable y
// Loading variable y (right) value
LOAD
ADDI
I2F2
// Loading global var z adress (used at depth 1)
LOADI(2) // loading offset 2 of variable z
SHIFT(2) // applying offset 2 of variable z
// Storing variable z (right) value
STORE
}
