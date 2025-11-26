/*
 *  Table des symboles.c
 *
 *  Created by Janin on 12/10/10.
 *  Copyright 2010 LaBRI. All rights reserved.
 *
 */


#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "Table_des_symboles.h"

/* bit  type handling */

  


/* Attribute types */

attribute new_attribute () {
  attribute r;
  r  = malloc (sizeof (struct ATTRIBUTE));
  if (r==NULL) {printf("Failed Malloc\n"); exit(-1);}
  return r;
};

attribute makeSymbol(int type, int offset, int depth)
{
  attribute r = new_attribute();
  r -> type = type;
  r -> offset = offset;
  r -> depth = depth;
  // r -> symb_type = symb_type; //selon si le symbole represente une variable ou une fonction
  return r;
}


/* The storage structure is implemented as a linked chain */

/* linked element def */

typedef struct elem {
	char * symbol_name;
	attribute symbol_value;
	struct elem * next;
} elem;

/* linked chain initial element */
static elem * storage=NULL;

/* get the symbol value of symb_id from the symbol table */
attribute get_symbol_value(char * symb_id) {
	elem * tracker=storage;

	/* look into the linked list for the symbol value */
	while (tracker) {
	  if (! strcmp(tracker -> symbol_name, symb_id))
	    return tracker -> symbol_value;  
	  tracker = tracker -> next;
	}
    
	/* if not found does cause an error */
	fprintf(stderr,"Erreur : symbole %s absent de la table des symboles\n",
		symb_id);
	return NULL;
};

/* add the symbol symb_id with given value */
attribute set_symbol_value(char * symb_id,attribute value) {

	elem * tracker;	
	tracker = malloc(sizeof(elem));
	tracker -> symbol_name = symb_id;
	tracker -> symbol_value = value;
	tracker -> next = storage;
	storage = tracker;
	return storage -> symbol_value;
}

int removeSymbol(char* symb_id) {
	elem * tracker=storage;
	if (!tracker) { fprintf(stderr,"Table vide!!\n"); }

	// check the first element
	if (strcmp(tracker->symbol_name, symb_id)) {
		printf("// Removing variable %s at depth %d\n", symb_id, tracker->symbol_value->depth);
		storage = tracker->next;
		free(tracker->symbol_value);
		free(tracker);
		return 0;
	}

	/* look into the linked list for the symbol value */
	while (tracker->next) {
	  if (! strcmp(tracker->next-> symbol_name, symb_id)) {
		printf("// Removing variable %s at depth %d\n", symb_id, tracker->next->symbol_value->depth);
		elem* next = tracker->next->next;
		elem* removed = tracker->next;
		tracker->next = next;
		free(removed->symbol_value);
		free(removed);
	    return 0;
	  }
	  tracker = tracker -> next;
	}
    
	/* if not found does cause an error */
	fprintf(stderr,"Erreur : symbole %s absent de la table des symboles\n", symb_id);
	return 1;
} // so far not needed


int removeLocalSymbols(int depth){
	elem * tracker=storage;
	if (!tracker) { fprintf(stderr,"Table vide!!\n"); }
	/* look into the linked list for the symbol value */
	while (tracker && tracker->symbol_value->depth == depth) {
		printf("// Removing variable %s at depth %d\n", tracker->symbol_name, depth);
		storage = tracker->next;
		elem *removed = tracker;
		free(removed->symbol_value);
		free(removed);
		tracker = storage;
	}
	return 0;
};