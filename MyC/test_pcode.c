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
}

void pcode_main() {
LOADI(8)
LOADI(2)
ADDI
LOADF(3.500000)
syntax error
