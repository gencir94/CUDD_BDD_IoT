
//MOD BY GENNA :)

#include <sys/types.h>
#include <sys/time.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>
#include "cudd.h"
#include "prova2.h"


int main() {

    char filename[30];
    DdManager *gbm; /* Global BDD manager. */
    gbm = Cudd_Init(0,0,CUDD_UNIQUE_SLOTS,CUDD_CACHE_SLOTS,0); /* Initialize a new BDD manager. */
    DdNode *bdd,*bdd1,*bdd2,*bdd3,*bdd4,*bdd5, *var;
    DdNode *tmp1;
    

    bdd = scrivi_bdd_zero (gbm, bdd, var); 
    bdd1 = scrivi_bdd_uno(gbm,bdd1,var);
    bdd2 = scrivi_bdd_due(gbm,bdd2,var);
    bdd3 = Cudd_bddOr(gbm,bdd1,bdd2); 
   
    bdd = Cudd_bddAnd(gbm,bdd,bdd3); 
   
//    bdd = Cudd_bddOr(gbm,bdd3,bdd4); 
//    bdd = Cudd_bddOr(gbm,bdd,bdd2); 
//    bdd = Cudd_bddOr(gbm,bdd,bdd3); 

    Cudd_Ref(bdd);          /*Update the reference count for the node just created.*/
    bdd = Cudd_BddToAdd(gbm, bdd); /*Convert BDD to ADD for display purpose*/
     
    print_dd (gbm, bdd, 2,4);   /*Print the dd to standard output*/
    sprintf(filename, "./bdd/graph.dot"); /*Write .dot filename to a string*/
    write_dd(gbm, bdd, filename);  /*Write the resulting cascade dd to a file*/
    Cudd_Quit(gbm);
    return 0; 

}
