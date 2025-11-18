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
// Entering function block of depth 1
LOADI(1)
LOADI(2)
MULTI
LOADF(3.500000)
LOADI(4)
I2F2 // converting second arg to float
MULTF
I2F1 // converting first arg to float
ADDF
LOADI(5)
MINUSI
LOADI(9)
LOADI(4)
LOADF(8.500000)
I2F1 // converting first arg to float
SUBF
I2F1 // converting first arg to float
MULTF
I2F1 // converting first arg to float
ADDF
LOADF(1.200000)
LOADI(6)
I2F2 // converting second arg to float
ADDF
LOADF(4.800000)
LOADI(7)
I2F2 // converting second arg to float
SUBF
LOADI(12)
I2F2 // converting second arg to float
MULTF
SUBF
// Exiting function block of depth 1
}
