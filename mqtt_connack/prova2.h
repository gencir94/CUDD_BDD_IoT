
//GENNARO MOD *_*

#include <sys/types.h>
#include <sys/time.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>
#include "cudd.h"


void print_dd (DdManager*,DdNode*,int, int);
void write_dd (DdManager*,DdNode*, char*);
DdNode* scrivi_bdd_zero(DdManager*, DdNode*, DdNode*);
DdNode* scrivi_bdd_uno(DdManager*, DdNode*, DdNode*);
DdNode* scrivi_bdd_due(DdManager*, DdNode*, DdNode*);
DdNode* scrivi_bdd_tre(DdManager*, DdNode*, DdNode*);
