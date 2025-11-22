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
LOADI(4)
IFN(False_0)
// la condition 0 est vraie
LOADI(7)
GOTO(End_0)
False_0:
// la condition 0 est fausse
Lazy_0:
LOADI(8842)
End_0:
// Fin conditionelle 0
// Debut conditionelle 1
LOADI(4)
IFN(False_1)
// la condition 1 est vraie
LOADI(7)
GOTO(End_1)
False_1:
// la condition 1 est fausse
Lazy_1:
LOADI(8842)
End_1:
// Fin conditionelle 1
// Debut conditionelle 2
LOADI(4)
IFN(False_2)
// la condition 2 est vraie
LOADI(7)
GOTO(End_2)
False_2:
// la condition 2 est fausse
Lazy_2:
LOADI(8842)
End_2:
// Fin conditionelle 2
// Debut conditionelle 3
LOADI(4)
IFN(False_3)
// la condition 3 est vraie
LOADI(7)
GOTO(End_3)
False_3:
// la condition 3 est fausse
Lazy_3:
LOADI(8842)
End_3:
// Fin conditionelle 3
// Debut conditionelle 4
LOADI(4)
IFN(False_4)
// la condition 4 est vraie
LOADI(7)
GOTO(End_4)
False_4:
// la condition 4 est fausse
Lazy_4:
LOADI(8842)
End_4:
// Fin conditionelle 4
// Debut conditionelle 5
LOADI(4)
IFN(False_5)
// la condition 5 est vraie
LOADI(7)
GOTO(End_5)
False_5:
// la condition 5 est fausse
Lazy_5:
LOADI(8842)
End_5:
// Fin conditionelle 5
// Debut conditionelle 6
LOADI(4)
IFN(False_6)
// la condition 6 est vraie
LOADI(7)
GOTO(End_6)
False_6:
// la condition 6 est fausse
Lazy_6:
LOADI(8842)
End_6:
// Fin conditionelle 6
// Debut conditionelle 7
LOADI(4)
IFN(False_7)
// la condition 7 est vraie
LOADI(7)
GOTO(End_7)
False_7:
// la condition 7 est fausse
Lazy_7:
LOADI(8842)
End_7:
// Fin conditionelle 7
// Debut conditionelle 8
LOADI(4)
IFN(False_8)
// la condition 8 est vraie
LOADI(7)
GOTO(End_8)
False_8:
// la condition 8 est fausse
Lazy_8:
LOADI(8842)
End_8:
// Fin conditionelle 8
// Debut conditionelle 9
LOADI(4)
IFN(False_9)
// la condition 9 est vraie
LOADI(7)
GOTO(End_9)
False_9:
// la condition 9 est fausse
Lazy_9:
LOADI(8842)
End_9:
// Fin conditionelle 9
// Debut conditionelle 10
LOADI(4)
IFN(False_10)
// la condition 10 est vraie
LOADI(7)
GOTO(End_10)
False_10:
// la condition 10 est fausse
Lazy_10:
LOADI(8842)
End_10:
// Fin conditionelle 10
// Debut conditionelle 11
LOADI(8998)
IFN(Lazy_11)
LOADI(5)
ANDI
IFN(False_11)
// la condition 11 est vraie
LOADI(7)
GOTO(End_11)
False_11:
// la condition 11 est fausse
Lazy_11:
LOADI(5555)
End_11:
// Fin conditionelle 11
// Debut conditionelle 12
LOADI(4)
IFN(False_12)
// la condition 12 est vraie
LOADI(7)
GOTO(End_12)
False_12:
// la condition 12 est fausse
Lazy_12:
LOADI(8842)
End_12:
// Fin conditionelle 12
// Debut conditionelle 13
LOADI(4)
IFN(False_13)
// la condition 13 est vraie
LOADI(7)
GOTO(End_13)
False_13:
// la condition 13 est fausse
Lazy_13:
LOADI(8842)
End_13:
// Fin conditionelle 13
// Debut conditionelle 14
LOADI(4)
IFN(False_14)
// la condition 14 est vraie
LOADI(7)
GOTO(End_14)
False_14:
// la condition 14 est fausse
Lazy_14:
LOADI(8842)
End_14:
// Fin conditionelle 14
// Debut conditionelle 15
LOADI(8998)
IFN(Statement_2)
GOTO(Lazy_15) //evaluation paresseuse
Statement_2:
LOADI(5)
ORI
IFN(False_15)
// la condition 15 est vraie
LOADI(7)
GOTO(End_15)
False_15:
// la condition 15 est fausse
Lazy_15:
LOADI(5555)
End_15:
// Fin conditionelle 15
// Exiting function block of depth 1
}
