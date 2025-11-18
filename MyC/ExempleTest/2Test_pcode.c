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

// Declare t of type float with offset 3 at depth 0
LOADF(0.0)

// Declare pi of type float with offset 4 at depth 0
LOADF(0.0)

}

void pcode_main() {
// Entering function block of depth 1
LOADI(5)
// Loading global var x adress (used at depth 1)
LOADI(0) // loading offset 0 of variable x
// Storing variable x (right) value
STORE
LOADI(6)
// Loading global var y adress (used at depth 1)
LOADI(1) // loading offset 1 of variable y
// Storing variable y (right) value
STORE
// Loading global var x adress (used at depth 1)
LOADI(0) // loading offset 0 of variable x
// Loading variable x (right) value
LOAD
// Loading global var y adress (used at depth 1)
LOADI(1) // loading offset 1 of variable y
// Loading variable y (right) value
LOAD
ADDI
LOADF(3.500000)
// Loading global var t adress (used at depth 1)
LOADF(3) // loading offset 3 of variable t
// Storing variable t (right) value
STORE
// Loading global var t adress (used at depth 1)
LOADF(3) // loading offset 3 of variable t
// Loading variable t (right) value
LOAD
// Loading global var x adress (used at depth 1)
LOADI(0) // loading offset 0 of variable x
// Loading variable x (right) value
LOAD
I2F2 // converting second arg to float
ADDF
// Loading global var y adress (used at depth 1)
LOADI(1) // loading offset 1 of variable y
// Loading variable y (right) value
LOAD
I2F2 // converting second arg to float
ADDF
// Loading global var z adress (used at depth 1)
LOADF(2) // loading offset 2 of variable z
// Storing variable z (right) value
STORE
// Loading global var z adress (used at depth 1)
LOADF(2) // loading offset 2 of variable z
// Loading variable z (right) value
LOAD
// Loading global var pi adress (used at depth 1)
LOADF(4) // loading offset 4 of variable pi
// Loading variable pi (right) value
LOAD
SUBF
// Exiting function block of depth 1
}
