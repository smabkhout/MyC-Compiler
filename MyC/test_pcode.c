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

// Declare y of type int with offset 1 at depth 0
LOADI(0)

}

void pcode_main() {
// Entering function block of depth 1
// Declare z of type int with offset 1 at depth 1
LOADI(0)

LOADI(5)
LOADI(4)
ADDI
// Debut conditionelle 0
LOADI(5)
IFN(False_0)
// la condition 0 est vraie
LOADI(7)
GOTO(End_0)
False_0:
// la condition 0 est fausse
LOADI(5555)
End_0:
// Fin conditionelle 0
// Debut conditionelle 1
LOADI(8998)
IFN(False_1)
// la condition 1 est vraie
LOADI(7)
GOTO(End_1)
False_1:
// la condition 1 est fausse
LOADI(5555)
End_1:
// Fin conditionelle 1
// Debut conditionelle 2
LOADI(8998)
IFN(Lazy_Else_2)
LOADI(5)
IFN(False_2)
// la condition 2 est vraie
LOADI(7)
GOTO(End_2)
False_2:
// la condition 2 est fausse
LOADI(5555)
End_2:
// Fin conditionelle 2
// Debut conditionelle 3
LOADI(3444)
IFN(Skip_3)
GOTO(Lazy_Then_3) //evaluation paresseuse
Skip_3:
LOADI(9)
IFN(False_3)
// la condition 3 est vraie
LOADI(2)
GOTO(End_3)
False_3:
// la condition 3 est fausse
LOADI(4444)
End_3:
// Fin conditionelle 3
// Exiting function block of depth 1
}
