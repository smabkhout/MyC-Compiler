%{


#include "Table_des_symboles.h"

#include <stdio.h>
#include <stdlib.h>
  
extern int yylex();
extern int yyparse();

void yyerror (char* s) {
  printf ("%s\n",s);
  exit(0);
  }
		
int depth=0; // block depth
int global_offset=0; // global for now
int condition_number=0; // pour chaque instruction if
 

%}

%union { 
  struct ATTRIBUTE * symbol_value;
  char * string_value;
  int int_value;
  float float_value;
  int type_value;
  int label_value;
  int offset_value;
}

%token <int_value> NUM
%token <float_value> DEC


%token INT FLOAT VOID

%token <string_value> ID
%token AO AF PO PF PV VIR
%token RETURN  EQ
%token <label_value> IF ELSE WHILE

%token <label_value> AND OR NOT DIFF EQUAL SUP INF
%token PLUS MOINS STAR DIV
%token DOT ARR

%nonassoc IFX
%left OR                       // higher priority on ||
%left AND                      // higher priority on &&
%left DIFF EQUAL SUP INF       // higher priority on comparison
%left PLUS MOINS               // higher priority on + - 
%left STAR DIV                 // higher priority on * /
%left DOT ARR                  // higher priority on . and -> 
%nonassoc UNA                  // highest priority on unary operator
%nonassoc ELSE
//l'ordre de priorité des opérations (augmente du haut vers le bas)

%{
char * type2string (int c) {
  switch (c)
    {
    case INT:
      return("int");
    case FLOAT:
      return("float");
    case VOID:
      return("void");
    default:
      return("type error");
    }  
};

int op_code(int type1, int operation, int type2) {
  const char* op_int[] = {"ADDI", "SUBI", "MULTI", "DIVI", "LTI", "GTI", "EQI", "DIFI", "ANDI", "ORI"}; //improvisées apres GTI (à demander)
    const char* op_float[] = {"ADDF", "SUBF", "MULTF", "DIVF", "LTF", "GTF", "EQF", "DIFF", "ANDF", "ORF"}; //aussi
    
    if (type1 == INT && type2 == INT) {
        printf("%s\n", op_int[operation]);
        return INT;
    } else if (type1 == FLOAT && type2 == FLOAT) {
        printf("%s\n", op_float[operation]);
        return FLOAT;
    } else if (type1 == INT && type2 == FLOAT) {
        printf("I2F1 // converting first arg to float\n");  
        printf("%s\n", op_float[operation]);
        return FLOAT;
    } else if (type1 == FLOAT && type2 == INT) {
        printf("I2F2 // converting second arg to float\n");
        printf("%s\n", op_float[operation]);
        return FLOAT;
    }
};


// ajoute le symbole "symbole_name" de type "type" et depth "depth" dans notre table de symboles
void add_symbol(char* symbol_name, int type, int depth){
  attribute att = makeSymbol(type, global_offset, depth);
  set_symbol_value(symbol_name, att);
  global_offset++;
};

// fonction pour deplacer le code d'affection
void aff_func(char* symbol, int exp_type, int current_depth) {
  attribute att = get_symbol_value(symbol);  
  if (exp_type == FLOAT && att->type == INT) {
    yyerror("ERREUR : Conversion implicite int->float interdite!!");
  }
  if (exp_type == INT && att->type == FLOAT) {
    printf("I2F2\n");
  }
  printf("// Loading global var %s adress (used at depth %d)\n", symbol, current_depth); //to be changed if the var is global or local
  if (att->type == INT) {
    printf("LOADI(%d) // loading offset %d of variable %s\n", att->offset, att->offset, symbol);
  } else if (att->type == FLOAT) {
    printf("LOADF(%d) // loading offset %d of variable %s\n", att->offset, att->offset, symbol);
  } else {
    yyerror("Erreur de type lors de l'affectation.");
  }
  printf("// Storing variable %s (right) value\n", symbol);
  printf("STORE\n");
};

 // dirty trick to end function init_glob_var() definition (see rule po : PO)
void end_glob_var_decl(){
  static int unfinished=1;
  if (unfinished) {
    unfinished = 0;
    printf("}\n\n");
  }
}

// Votre code C peut aller ci-dessous pour factoriser (un peu) le code des actions semantiques
 
  %}


%start prog  

// liste de tous les type des attributs des non terminaux que vous voulez manipuler l'attribut (il faudra en ajouter plein ;-) )
%type <type_value> type exp  typename vlist block if bool_cond ao af inst fao faf fun_body
%type <string_value> fun_head

%%

 // O. Déclaration globale

prog : glob_decl_list              {}
;

glob_decl_list : glob_var_list glob_fun_list {}
;

glob_var_list : glob_var_list decl PV {}
| { printf("void init_glob_var(){\n"); // starting  function init_glob_var() definition in target code
 }
;

glob_fun_list : glob_fun_list fun {}
| fun {}
;

// I. Functions

fun : type fun_head fun_body   {}
;

po: PO {end_glob_var_decl();}  // dirty trick to end function init_glob_var() definition in target code
  
fun_head : ID po PF            {
  // Pas de déclaration de fonction à l'intérieur de fonctions !
  if (depth>0) yyerror("Function must be declared at top level~!\n");
  printf("void pcode_%s() ", $1);
  ++depth; //so that a declaration in the main function would be of depth 1
  }

| ID po params PF              {
   // Pas de déclaration de fonction à l'intérieur de fonctions !
  if (depth>0) yyerror("Function must be declared at top level~!\n");
  printf("void pcode_%s() ", $1);
 }
;

params: type ID vir params     {} // récursion droite pour numéroter les paramètres du dernier au premier
| type ID                      {}


vir : VIR                      {}
;

fun_body : fao block faf       {}
;

fao : AO                       {
  $<int_value>0=$$;
  printf("{\n");
  $$=depth++;
  printf("// Entering function block of depth %d\n", $$);
}
;
faf : AF                       {
  $$=$<int_value>-1;
  printf("// Getting out of function block of depth %d\n", $$);
  printf("}\n");
  depth--;
}
;


// II. Block
block:
decl_list inst_list            {}
;

// III. Declarations

decl_list : decl_list decl PV   {} 
|                               {}
;

decl: var_decl                  {}
;

var_decl : type vlist          {}
;

vlist: vlist vir ID            {
  add_symbol($3, $<int_value>0, $<int_value>-2);
  $$ = $1;
  printf("// Declare %s of type %s with offset %d at depth %d\n", $3, type2string($<int_value>0), global_offset-1, $<int_value>-2); //-2 fait reference à af qui stocke le depth courant
  if ($<int_value>0 == INT) {
    printf("LOADI(0)\n\n");
  } else if ($<int_value>0 == FLOAT) {
    printf("LOADF(0.0)\n\n");
  } else {
    yyerror("Erreur de type");
  }
} // récursion gauche pour traiter les variables déclararées de gauche à droite
| ID                           {
  add_symbol($1, $<int_value>0, $<int_value>-2);
  printf("// Declare %s of type %s with offset %d at depth %d\n", $1, type2string($<int_value>0), global_offset-1, $<int_value>-2); //-2 fait reference à af qui stocke le depth courant
  if ($<int_value>0 == INT) {
    printf("LOADI(0)\n\n");
  } else if ($<int_value>0 == FLOAT) {
    printf("LOADF(0.0)\n\n");
  } else {
    yyerror("Erreur de type");
  }
  }
;

type
: typename                     {}
;

typename // Utilisation des terminaux comme codage (entier) du type !!!
: INT                          {$$=INT;} 
| FLOAT                        {$$=FLOAT;}
| VOID                         {$$=VOID;}
;

// IV. Intructions

inst_list: inst_list inst   {} 
| inst                      {}
;

pv : PV                       {}
;
 
inst:
ao block af                   {}
| exp pv                      {}
| aff pv                      {}
| ret pv                      {}
| cond                        {}
| loop                        {}
| pv                          {}
;

// Accolades explicites pour gerer l'entrée et la sortie d'un sous-bloc

ao : AO                       { $$=depth++; $<int_value>0=$$; printf("// Entering instructions block of depth %d\n", $$); }
;

af : AF                       { $$=$<int_value>-1; printf("// Getting out of instructions block of depth %d\n", $$); depth--; }
;


// IV.1 Affectations

aff : ID EQ exp               {
  aff_func($1, $3, $<int_value>-2);
}
;



// IV.2 Return
ret : RETURN exp              {}
| RETURN PO PF                {}
;

// IV.3. Conditionelles
//           N.B. ces rêgles génèrent un conflit déclage reduction
//           qui est résolu comme on le souhaite par un décalage (shift)
//           avec ELSE en entrée (voir y.output)

cond :
if bool_cond inst  elsop       { printf("// Fin conditionelle %d\n", $1); $2=$1; }
;

elsop : else inst              { printf("End_%d:\n", $<int_value>-2); }
|                  %prec IFX   { printf("False_%d:\n// la condition %d est fausse\n", $<int_value>-2, $<int_value>-2); } // juste un "truc" pour éviter le message de conflit shift / reduce
;

bool_cond : PO exp PF         { printf("IFN(False_%d)\n// la condition %d est vraie\n", $<int_value>0, $<int_value>0); }
;

if : IF                       { $$=condition_number++; printf("// Debut conditionelle %d\n", $$); }
;

else : ELSE                   { printf("GOTO(End_%d)\nFalse_%d:\n// la condition %d est fausse\n", $<int_value>-2, $<int_value>-2, $<int_value>-2); }
;

// IV.4. Iterations

loop : while while_cond inst  {}
;

while_cond : PO exp PF        {}

while : WHILE                 {}
;


// V. Expressions


exp
// V.1 Exp. arithmetiques
: MOINS exp %prec UNA         {$$ = $2;
                                if ($2 == INT) {
                                    printf("MINUSI\n");
                                }   else if ($2 == FLOAT) {
                                    printf("MINUSF\n");
                                }   else {
                                    yyerror("Erreur de type");
                                }
                              }
         // -x + y lue comme (- x) + y  et pas - (x + y)
| exp PLUS exp                { $$=op_code($1, 0, $3); }
| exp MOINS exp               { $$=op_code($1, 1, $3); }
| exp STAR exp                { $$=op_code($1, 2, $3); }
| exp DIV exp                 { $$=op_code($1, 3, $3); }
| PO exp PF                   { $$=$2; }
| ID                          {
  attribute att = get_symbol_value($1);
  if (att == NULL) {
    yyerror("Variable non déclarée !!!");
  }
  $$=att->type;
  printf("// Loading global var %s adress (used at depth %d)\n", $1, att->depth+1);
  if (att->type == INT) {
    printf("LOADI(%d) // loading offset %d of variable %s\n", att->offset, att->offset, $1);
  } else if (att->type == FLOAT) {
    printf("LOADF(%d) // loading offset %d of variable %s\n", att->offset, att->offset, $1);
  } else {
    yyerror("Erreur de type.");
  }
  printf("// Loading variable %s (right) value\n", $1);
  printf("LOAD\n");
}
| app                         {}
| NUM                         { $$=INT; printf("LOADI(%i)\n", $1); }
| DEC                         { $$=FLOAT; printf("LOADF(%f)\n", $1); }


// V.2. Booléens

| NOT exp %prec UNA           {}
| exp INF exp                 { $$=op_code($1, 4, $3); }
| exp SUP exp                 { $$=op_code($1, 5, $3); }
| exp EQUAL exp               { $$=op_code($1, 6, $3); } //improvisées à cause du manque des exemples
| exp DIFF exp                { $$=op_code($1, 7, $3); }
| exp AND exp                 { $$=op_code($1, 8, $3); } //à modifier pour implémenter la gestion des Booléens paresseuse
| exp OR exp                  { $$=op_code($1, 9, $3); } //aussi

;

// V.3 Applications de fonctions


app : fid PO args PF          {}
;

fid : ID                      {}

args :  arglist               {}
|                             {}
;

arglist : arglist VIR exp     {} // récursion gauche pour empiler les arguements de la fonction de gauche à droite
| exp                         {}
;



%% 
int main () {

  /* Ici on peut ouvrir le fichier source, avec les messages 
     d'erreur usuel si besoin, et rediriger l'entrée standard 
     sur ce fichier pour lancer dessus la compilation.
   */

char * header=
"// PCode Header\n\
#include \"PCode.h\"\n\
\n\
void pcode_main();\n\
void init_glob_var();\n\
\n\
int main() {\n\
init_glob_var();\n\
pcode_main();\n\
return stack[sp-1].int_value;\n\
}\n\
\n";  

printf("%s\n",header); // ouput header
  
return yyparse (); // output your compilation
 
 
} 

