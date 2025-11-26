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
// loading default returned value
LOADI(0)
// loading function x arguments
SAVEBP
CALL(pcode_x)
RESTOREBP
DROP(0) //remove 0 fun. parameters from stack
}
