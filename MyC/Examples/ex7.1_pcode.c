// Begin PCode Header
#include "PCode.h"

void pcode_main();
void init_glob_var();

int main() {
init_glob_var();
pcode_main();
return stack[sp-1].int_value;
}
// End PCode Header

void init_glob_var(){
}

void pcode_one() {
LOADI(1)
}
void pcode_main() {
// loading default returned value
// loading function one arguments
SAVEBP
CALL(pcode_one)
RESTOREBP
}
