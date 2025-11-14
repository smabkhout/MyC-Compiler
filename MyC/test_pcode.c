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
// Declare x of type float with offset 0 at depth 0
LOADF(0.0)

// Declare y of type float with offset 0 at depth 0
LOADF(0.0)

// Declare z of type int with offset 0 at depth 0
LOADI(0)

}

void pcode_main() {
LOADI(4)
LOADI(2)
ADDI
}
