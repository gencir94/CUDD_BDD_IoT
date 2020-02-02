
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
//funzioni connect
DdNode* scrivi_bdd_zero(DdManager*, DdNode*, DdNode*);
DdNode* scrivi_bdd_uno(DdManager*, DdNode*, DdNode*);
DdNode* scrivi_bdd_due(DdManager*, DdNode*, DdNode*);
DdNode* scrivi_bdd_tre(DdManager*, DdNode*, DdNode*);

//funzioni conack
DdNode* scrivi_bdd_zero1(DdManager*, DdNode*, DdNode*);
DdNode* scrivi_bdd_uno1(DdManager*, DdNode*, DdNode*);
DdNode* scrivi_bdd_due1(DdManager*, DdNode*, DdNode*);

//funzioni publish
DdNode* scrivi_bdd_zero2(DdManager*, DdNode*, DdNode*);
DdNode* scrivi_bdd_uno2(DdManager*, DdNode*, DdNode*);
DdNode* scrivi_bdd_due2(DdManager*, DdNode*, DdNode*);
DdNode* scrivi_bdd_tre2(DdManager*, DdNode*, DdNode*);
DdNode* scrivi_bdd_quattro2(DdManager*, DdNode*, DdNode*);

//funzioni puback
DdNode* scrivi_bdd_zero3(DdManager*, DdNode*, DdNode*);
DdNode* scrivi_bdd_uno3(DdManager*, DdNode*, DdNode*);

//funzioni pubrec
DdNode* scrivi_bdd_zero4(DdManager*, DdNode*, DdNode*);
DdNode* scrivi_bdd_uno4(DdManager*, DdNode*, DdNode*);

//funzioni pubrel
DdNode* scrivi_bdd_zero5(DdManager*, DdNode*, DdNode*);
DdNode* scrivi_bdd_uno5(DdManager*, DdNode*, DdNode*);

//funzioni pubcomp
DdNode* scrivi_bdd_zero6(DdManager*, DdNode*, DdNode*);
DdNode* scrivi_bdd_uno6(DdManager*, DdNode*, DdNode*);


//funzioni subscribe
DdNode* scrivi_bdd_zero7(DdManager*, DdNode*, DdNode*);
DdNode* scrivi_bdd_uno7(DdManager*, DdNode*, DdNode*);
DdNode* scrivi_bdd_due7(DdManager*, DdNode*, DdNode*);
DdNode* scrivi_bdd_tre7(DdManager*, DdNode*, DdNode*);

//funzioni unsuback
DdNode* scrivi_bdd_zero8(DdManager*, DdNode*, DdNode*);
DdNode* scrivi_bdd_uno8(DdManager*, DdNode*, DdNode*);



//funzioni unsubscribe
DdNode* scrivi_bdd_zero9(DdManager*, DdNode*, DdNode*);
DdNode* scrivi_bdd_uno9(DdManager*, DdNode*, DdNode*);
DdNode* scrivi_bdd_due9(DdManager*, DdNode*, DdNode*);
DdNode* scrivi_bdd_tre9(DdManager*, DdNode*, DdNode*);

//funzioni pingreq
DdNode* scrivi_bdd_zero10(DdManager*, DdNode*, DdNode*);

//funzioni pingresp
DdNode* scrivi_bdd_zero11(DdManager*, DdNode*, DdNode*);

//funzioni disconnect
DdNode* scrivi_bdd_zero12(DdManager*, DdNode*, DdNode*);

//funzioni suback

DdNode* scrivi_bdd_zero13(DdManager*, DdNode*, DdNode*);
DdNode* scrivi_bdd_uno13(DdManager*, DdNode*, DdNode*);
DdNode* scrivi_bdd_due13(DdManager*, DdNode*, DdNode*);
DdNode* scrivi_bdd_tre13(DdManager*, DdNode*, DdNode*);

