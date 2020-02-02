
//GENNARO MOD *.*

#include <sys/types.h>
#include <sys/time.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>
#include "cudd.h"
#include "prova2.h"


void print_dd (DdManager *gbm, DdNode *dd, int n, int pr )
{
    printf("DdManager nodes: %ld | ", Cudd_ReadNodeCount(gbm)); /*Reports the number of live nodes in BDDs and ADDs*/
    printf("DdManager vars: %d | ", Cudd_ReadSize(gbm) ); /*Returns the number of BDD variables in existence*/
    printf("DdManager reorderings: %d | ", Cudd_ReadReorderings(gbm) ); /*Returns the number of times reordering has occurred*/
    printf("DdManager memory: %ld \n", Cudd_ReadMemoryInUse(gbm) ); /*Returns the memory in use by the manager measured in bytes*/
    Cudd_PrintDebug(gbm, dd, n, pr);  // Prints to the standard output a DD and its statistics: number of nodes, number of leaves, number of minterms.
}


/**
 * Writes a dot file representing the argument DDs
 * @param the node object
 */
void write_dd (DdManager *gbm, DdNode *dd, char* filename)
{
    FILE *outfile; // output file pointer for .dot file
    outfile = fopen(filename,"w");
    DdNode **ddnodearray = (DdNode**)malloc(sizeof(DdNode*)); // initialize the function array
    ddnodearray[0] = dd;
    Cudd_DumpDot(gbm,1, ddnodearray, NULL, NULL, outfile); // dump the function to .dot file
    free(ddnodearray);
    fclose (outfile); // close the file */

}

DdNode* scrivi_bdd_zero (DdManager *gbm, DdNode *bdd, DdNode * var) 
{
     
 DdNode *bdd1, *bdd2, *bdd3, *bdd4, *bdd5, *bdd6, *bdd7, *bdd8, *bdd9,*tmp,*tmp_neg;
     bdd = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd); /*Increases the reference count of a node*/
     int i; 
     
     bdd1 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
    
     Cudd_Ref(bdd1); /*Increases the reference count of a node*/
         for (i = 0; i < 8; i++) {
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
     if(i != 2) {
      tmp_neg = Cudd_Not(var); /*Perform NOT Boolean operation*/
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd); /*Perform AND Boolean operation*/
      }else{
      tmp = Cudd_bddAnd(gbm,var,bdd); /*Perform AND Boolean operation*/
     }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd);
      bdd = tmp;
    }

    Cudd_Ref(bdd);
  for (i = 8; i < 16; i++) {
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
     if(i != 14) {
      tmp_neg = Cudd_Not(var); /*Perform NOT Boolean operation*/
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd1); /*Perform AND Boolean operation*/
      }else{
      tmp = Cudd_bddAnd(gbm,var,bdd1); /*Perform AND Boolean operation*/
     }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd1);
      bdd1 = tmp;
    }

    bdd = Cudd_bddAnd(gbm,bdd,bdd1);
    Cudd_Ref(bdd);   
    return bdd;
}




DdNode* scrivi_bdd_uno (DdManager *gbm, DdNode *bdd, DdNode * var) 
{
 
 DdNode* bdd_rec[128];
 DdNode *bdd1, *bdd2, *bdd3, *bdd4, *bdd5, *bdd6, *bdd7, *bdd8, *bdd9,*tmp,*tmp_neg;
     bdd = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd); /*Increases the reference count of a node*/
     int i; 
     
     bdd1 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd1); /*Increases the reference count of a node*/
     bdd2 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd2); /*Increases the reference count of a node*/
     bdd3 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd3); /*Increases the reference count of a node*/
     bdd4 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd4); /*Increases the reference count of a node*/
     bdd5 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd5); /*Increases the reference count of a node*/
     bdd9 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd9); /*Increases the reference count of a node*/
         
     for (i = 16; i < 24; i++) {
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
      tmp_neg = Cudd_Not(var); 
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd); 
     
     Cudd_Ref(tmp);
     Cudd_RecursiveDeref(gbm,bdd);
     bdd = tmp;
    }

    Cudd_Ref(bdd);
    
 
    for (i = 24; i < 32; i++) {
     var = Cudd_bddIthVar(gbm,i); 
      tmp_neg = Cudd_Not(var); 
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd1); 
     
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd1);
      bdd1 = tmp;
    }



  for (i = 24; i < 32; i++) {
     var = Cudd_bddIthVar(gbm,i); 
     if(i != 31) {
      tmp_neg = Cudd_Not(var); 
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd9); 
      }else{
      tmp = Cudd_bddAnd(gbm,var,bdd9); 
     }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd9);
      bdd9 = tmp;
    }

    bdd1 = Cudd_bddOr(gbm,bdd1,bdd9);
    Cudd_Ref(bdd);   

    for (i = 24; i < 32; i++) {
     var = Cudd_bddIthVar(gbm,i); 
     if(i != 30){
      tmp_neg = Cudd_Not(var); 
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd2); 
     }else{
      tmp = Cudd_bddAnd(gbm, var, bdd2); 
     }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd2);
      bdd2 = tmp;
     }
   
    bdd1= Cudd_bddOr(gbm,bdd1,bdd2);
    Cudd_Ref(bdd);

    for (i = 24; i < 32; i++) {
     var = Cudd_bddIthVar(gbm,i); 
     if(i != 31 && i != 30){
      tmp_neg = Cudd_Not(var); 
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd3); 
     }else{
      tmp = Cudd_bddAnd(gbm, var, bdd3); 
     }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd3);
      bdd3 = tmp;
    }
    
    bdd1 = Cudd_bddOr(gbm,bdd1,bdd3);
    Cudd_Ref(bdd);
    
    for (i = 24; i < 32; i++) {
     var = Cudd_bddIthVar(gbm,i); 
     if(i != 29){
      tmp_neg = Cudd_Not(var); 
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd4); 
     }else{
      tmp = Cudd_bddAnd(gbm, var, bdd4); 
     }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd4);
      bdd4 = tmp;
    }
    
    bdd1 = Cudd_bddOr(gbm,bdd1,bdd4);
    Cudd_Ref(bdd);
    
    for (i = 24; i < 32; i++) {
     var = Cudd_bddIthVar(gbm,i); 
     if(i != 29 && i != 31){
      tmp_neg = Cudd_Not(var); 
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd5); 
     }else{
      tmp = Cudd_bddAnd(gbm, var, bdd5);
     }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd5);
      bdd5 = tmp;
    }

    bdd1 = Cudd_bddOr(gbm,bdd1,bdd5);
    Cudd_Ref(bdd);
   bdd = Cudd_bddAnd(gbm,bdd1,bdd);
   return bdd; 
}	



DdNode* scrivi_bdd_due (DdManager *gbm, DdNode *bdd, DdNode * var) 
{
 DdNode* bdd_rec[128];
 DdNode *bdd1, *bdd2, *bdd3, *bdd4, *bdd5, *bdd6, *bdd7, *bdd8, *bdd9,*tmp,*tmp_neg;
     bdd = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd); /*Increases the reference count of a node*/
     int i; 
     
     bdd1 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd1); /*Increases the reference count of a node*/
     bdd2 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd2); /*Increases the reference count of a node*/
     bdd3 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd3); /*Increases the reference count of a node*/
     bdd4 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd4); /*Increases the reference count of a node*/
     bdd5 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd5); /*Increases the reference count of a node*/
     bdd9 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd9); /*Increases the reference count of a node*/
   
     for (i = 16; i < 24; i++) {
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
     if (i != 23) {
      tmp_neg = Cudd_Not(var); 
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd); 
     } else {
      tmp = Cudd_bddAnd(gbm,var,bdd); /*Perform AND Boolean operation*/
     }
     Cudd_Ref(tmp);
     Cudd_RecursiveDeref(gbm,bdd);
     bdd = tmp;
    }

    Cudd_Ref(bdd);
 
    for (i = 24; i < 32; i++) {
      var = Cudd_bddIthVar(gbm,i); 
      tmp_neg = Cudd_Not(var); 
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd1); 
     
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd1);
      bdd1 = tmp;

    
    }



  for (i = 24; i < 32; i++) {
     var = Cudd_bddIthVar(gbm,i); 
     if(i != 31) {
      tmp_neg = Cudd_Not(var); 
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd9); 
      }else{
      tmp = Cudd_bddAnd(gbm,var,bdd9); 
     }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd9);
      bdd9 = tmp;
    }

    bdd1 = Cudd_bddOr(gbm,bdd1,bdd9);
    Cudd_Ref(bdd);   
    
    for (i = 24; i < 32; i++) {
     var = Cudd_bddIthVar(gbm,i); 
     if(i != 30){
      tmp_neg = Cudd_Not(var); 
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd2); 
     }else{
      tmp = Cudd_bddAnd(gbm, var, bdd2); 
     }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd2);
      bdd2 = tmp;
     }
   
    bdd1 = Cudd_bddOr(gbm,bdd1,bdd2);
    Cudd_Ref(bdd);
    
    for (i = 24; i < 32; i++) {
     var = Cudd_bddIthVar(gbm,i); 
     if(i != 30 && i != 31){
      tmp_neg = Cudd_Not(var); 
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd3); 
     }else{
      tmp = Cudd_bddAnd(gbm, var, bdd3); 
     }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd3);
      bdd3 = tmp;
    }
    
    bdd1 = Cudd_bddOr(gbm,bdd1,bdd3);
    Cudd_Ref(bdd);
    
    for (i = 24; i < 32; i++) {
     var = Cudd_bddIthVar(gbm,i); 
     if(i != 29){
      tmp_neg = Cudd_Not(var); 
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd4); 
     }else{
      tmp = Cudd_bddAnd(gbm, var, bdd4); 
     }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd4);
      bdd4 = tmp;
    }
    
    bdd1 = Cudd_bddOr(gbm,bdd1,bdd4);
    Cudd_Ref(bdd);
    
    for (i = 24; i < 32; i++) {
     var = Cudd_bddIthVar(gbm,i); 
     if(i != 29 && i != 31  ){
      tmp_neg = Cudd_Not(var); 
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd5); 
     }else{
      tmp = Cudd_bddAnd(gbm, var, bdd5);
     }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd5);
      bdd5 = tmp;
    }

    bdd1 = Cudd_bddOr(gbm,bdd1,bdd5);
    Cudd_Ref(bdd);
    
    bdd = Cudd_bddAnd(gbm,bdd,bdd1);
    Cudd_Ref(bdd);   
return bdd;
    

}



