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

// Declare y of type float with offset 0 at depth 0
LOADF(0.0)

}

void pcode_main() {
LOADF(3.500000)
// Loading global var x adress (used at depth 0)
LOADI(0) // loading offset 0 of variable x
// Storing variable x (right) value
STORE
LOADI(5)
// Loading global var y adress (used at depth 0)
LOADF(1) // loading offset 1 of variable y
// Storing variable y (right) value
STORE
}
