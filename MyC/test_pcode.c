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
LOADI(5)
MINUSI
LOADI(4)
LOADI(8)
MULTI
ADDI
LOADI(7)
ADDI
LOADI(6)
LOADI(4)
DIVI
SUBI
LOADI(6)
ADDI
}
