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
LOADF(1.500000)
LOADF(3.600000)
LOADF(9.400000)
ADDF
LOADF(1.500000)
LOADI(2)
I2F2 // converting second arg to float
ADDF
LOADI(5)
MINUSI
LOADF(3.600000)
I2F1 // converting first arg to float
MULTF
}
