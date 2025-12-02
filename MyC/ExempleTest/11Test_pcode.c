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

// Argument b of function multiply in TDS with offset -1
// Argument a of function multiply in TDS with offset -2
void pcode_multiply() {
// Loading local var a adress declared at depth 1 (used at depth 1)
LOADBP
SHIFT(-2) // applying offset -2 of variable a
// Loading variable a (right) value
LOAD
// Loading local var b adress declared at depth 1 (used at depth 1)
LOADBP
SHIFT(-1) // applying offset -1 of variable b
// Loading variable b (right) value
LOAD
MULTI
// Loading function return address
LOADBP
SHIFT(-3) // apply returned value offset -3
STORE // store returned value
return ()
// Removing variable a at depth 1
// Removing variable b at depth 1
}
// Argument y of function add in TDS with offset -1
// Argument x of function add in TDS with offset -2
void pcode_add() {
// Loading local var x adress declared at depth 1 (used at depth 1)
LOADBP
SHIFT(-2) // applying offset -2 of variable x
// Loading variable x (right) value
LOAD
// Loading local var y adress declared at depth 1 (used at depth 1)
LOADBP
SHIFT(-1) // applying offset -1 of variable y
// Loading variable y (right) value
LOAD
ADDI
// Loading function return address
LOADBP
SHIFT(-3) // apply returned value offset -3
STORE // store returned value
return ()
// Removing variable x at depth 1
// Removing variable y at depth 1
}
void pcode_main() {
// Declare product of type int with offset 1 at depth 1
LOADI(0)

// Declare sum of type int with offset 2 at depth 1
LOADI(0)

// loading default returned value
LOADI(0)
// loading function multiply arguments
LOADI(3)
LOADI(4)
SAVEBP
CALL(pcode_multiply)
RESTOREBP
DROP(2) //remove 2 fun. parameters from stack
// Loading local var product adress declared at depth 1 (used at depth 1)
LOADBP
SHIFT(1) // applying offset 1 of variable product
// Storing variable product (right) value
STORE
// loading default returned value
LOADI(0)
// loading function add arguments
LOADI(5)
LOADI(7)
SAVEBP
CALL(pcode_add)
RESTOREBP
DROP(2) //remove 2 fun. parameters from stack
// Loading local var sum adress declared at depth 1 (used at depth 1)
LOADBP
SHIFT(2) // applying offset 2 of variable sum
// Storing variable sum (right) value
STORE
// Removing variable sum at depth 1
// Removing variable product at depth 1
}
