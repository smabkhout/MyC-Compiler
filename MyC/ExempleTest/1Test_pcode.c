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
LOADI(410)
LOADI(6)
LOADI(9)
ADDI
LOADI(8)
LOADI(6)
MULTI
LOADI(9)
MINUSI
}
