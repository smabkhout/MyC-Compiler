# MyC Compiler

A compiler for **MyC**, a small imperative C-like language, written for the *Compilation* course at ENSEIRB-MATMECA (2A / S7). The compiler reads MyC source files and emits **PCode**, a stack-based intermediate representation realised as a set of C macros that can be compiled and executed on a small virtual stack machine.

## How it works

The pipeline is a classic Flex + Bison front end driving an ad-hoc code generator:

1. **Lexer** (`MyC/lang.l`, Flex) — tokenises operators, keywords (`int`, `float`, `void`, `if`, `else`, `while`, `return`), identifiers and numeric literals.
2. **Parser** (`MyC/lang.y`, Bison) — recognises declarations, expressions, control flow and function calls, and drives semantic actions that emit PCode.
3. **Symbol table** (`MyC/Table_des_symboles.{c,h}`) — associative array of `(name → {type, offset, depth})`, used for type checking and for resolving globals vs. locals.
4. **PCode runtime** (`MyC/PCode/PCode.{c,h}`) — defines the stack, the `sp` / `bp` registers and every instruction (`LOADI`, `ADDI`, `MULTF`, `IFT`, `GOTO`, `LOADBP`, `SHIFT`, `LOAD`, `STORE`, `SAVEBP`, `RESTOREBP`, `CALL`, `DROP`, …) as C macros. The generated `*_pcode.c` files are valid C programs that, once linked against `PCode.o`, run the compiled program.

## Implemented features

- **Types**: `int` and `float`, with automatic `int → float` promotion; the illegal `float → int` direction is rejected at compile time.
- **Global variables**: declaration, lookup and offset management through the symbol table.
- **Control flow**: `if`, `if/else`, `while`, with generated labels (`False_n`, `End_n`, `StartLoop_n`, `EndLoop_n`) and arbitrary nesting.
- **Lazy booleans**: short-circuit `&&` and `||` via conditional branches.
- **Nested blocks & local variables**: scope tracked by *depth*; globals are accessed with `LOADI 0; SHIFT(o); LOAD`, locals with `LOADBP; SHIFT(o); LOAD` (climbing depths as needed). Assignments end with `STORE`.
- **Functions**: declarations only at global scope; parameters get negative offsets, locals get positive ones; calls reserve a return slot, push arguments, `SAVEBP`, `CALL`, then `RESTOREBP` and `DROP(n)`. Recursive and mutually recursive functions are supported.

## Layout

```
ein7-proj1-27410/
├── MyC/
│   ├── lang.l, lang.y          # Flex + Bison sources
│   ├── Table_des_symboles.{c,h}
│   ├── PCode/                  # PCode macros & runtime
│   ├── Examples/               # Course example programs (.myc + expected .c)
│   ├── ExempleTest/            # Project test suite (1Test … 16Test)
│   ├── Makefile
│   ├── runComp                 # ./runComp <name>  → name.myc → name_pcode.c
│   └── runTests.sh             # runs every ExempleTest/*Test
└── Examples/                   # Same examples archived at the repo root
```

## Build & run

```bash
cd MyC
make            # produces the `lang` binary
./runComp Examples/ex1.0          # compiles ex1.0.myc → ex1.0_pcode.c
gcc Examples/ex1.0_pcode.c PCode/PCode.o -o prog && ./prog
./runTests.sh   # regenerates PCode for every ExempleTest/*Test
make clean
```

A MyC program is a sequence of function declarations ending in `void main() { ... }`. See `MyC/ExempleTest/16Test_mutually_recursive.myc` for an example exercising mutually recursive functions.
