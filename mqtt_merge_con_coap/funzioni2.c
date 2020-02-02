
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
     DdNode* bdd_rec[128];
     DdNode *bdd1, *bdd2, *bdd3, *bdd4, *bdd5, *bdd6, *bdd7, *bdd8, *bdd9,*tmp,*tmp_neg;
     bdd = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd); /*Increases the reference count of a node*/
     int i; 
     
     for(i = 0; i < 128; i++){
     bdd_rec[i] = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd_rec[i]); /*Increases the reference count of a node*/
     } 
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
     bdd6 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd6); /*Increases the reference count of a node*/
     bdd7 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd7); /*Increases the reference count of a node*/
     bdd8 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd8); /*Increases the reference count of a node*/
   
     
     for (i = 0; i < 8; i++) {
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
     if(i != 3) {
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

int j;int k = 0;
     for(j = 0;j<128;j++){ 
       for (i = 8; i < 16; i++) {
          var = Cudd_bddIthVar(gbm,i); 
          if(i%8 ==  0) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	  }
	  else if(i == 9+k && j < 64 ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
          }else if(i == 9+k && j >= 64) {
	  tmp = Cudd_bddAnd(gbm, var, bdd_rec[j]); 
          }
	  else if ( (i == 10 + k) && ( ( j < 32 ) || ( j >= 64 && j < 96 ) ) ) {
          tmp_neg = Cudd_Not(var);
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
          } else if ( i == 10 + k && ( ( j >= 32 && j < 64 ) || ( j >= 96 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
	  } else if (i == 11 + k && ( (j<16) || (j>=32 && j<48) || (j>=64 && j<80) || (j>=96 && j<112) ) ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	  } else if (i == 11 + k && ( (j >= 16 && j < 32) || ( j >= 48 && j < 64 ) || ( j >= 80 && j < 96 ) || ( j >= 112 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
          } else if ( i == 12 + k && ( ( j < 8 ) || ( j >= 16 && j < 24) || (j >= 32 && j < 40) || (j>=48 && j<56) || ( j >= 64 && j < 72 ) || 
		    (j >= 80 && j < 88) || (j >= 96 && j < 104) || (j>=112 && j<120) ) ) {
	   tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
           } else if (i == 12 + k && ( ( j >= 8 && j < 16 ) || ( j >= 24 && j < 32 ) || ( j >= 40 && j < 48) || ( j >= 56 && j < 64) 
			|| (j>72 && j<=80) || (j>=88 && j<96) || (j>=104 && j<112) || (j>=120) ) ) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]);  
 	   } else if (i == 13 + k && ( (j < 4) || (j >= 8 && j < 12) || (j >= 16 && j < 20) || (j >= 24 && j < 28) || (j >= 32 && j < 36) || (j >= 40 && j < 44)
			|| (j >= 48 && j < 52)  || (j >= 56 && j < 60)|| (j >= 64 && j < 68) || (j >= 72 && j < 76) || (j >= 80 && j < 84) || (j >= 88 && j < 92) 	
			|| (j >= 96 && j < 100) || (j >= 104 && j < 108) || (j >= 112 && j < 116) || (j >= 120 && j < 124))) {
	   tmp_neg = Cudd_Not(var);
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   
	   } else if (i == 13 + k && ( (j>=4 && j<8) || ( j >= 12 && j < 16 ) || ( j >= 20 && j < 24 ) || ( j >= 28 && j < 32 ) || ( j >= 36 && j < 40 ) 
			|| ( j >= 44 && j < 48 ) || ( j >= 52 && j < 56 ) || ( j >= 60 && j < 64 ) || ( j >= 68 && j < 72 ) || ( j >= 76 && j < 80 ) 	  
		        || ( j >= 84 && j < 88 ) || ( j >= 92 && j < 96 ) || ( j >= 100 && j < 104 ) || ( j >= 108 && j < 112 ) 
			|| ( j >= 116 && j < 120  ) 	|| ( j >= 124 && j < 128 ))) {
          
		   tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
           } else if ( i == 14 + k && ( (j<2) || (j>=4 && j<6)  || (j>=8 && j<10) || (j>=12 && j<14) || (j>=16 && j<18) || (j>=20 && j<22) || (j>=24 && j<26)
			|| (j>=28 && j<30) || (j>=32 && j<34) || (j>=36 && j<38) || (j>=40 && j<42) || (j>=44 && j<46) || (j>=48 && j<50) || (j>=52 && j<54) 	  
			|| (j>=56 && j<58) || (j>=60 && j<62) || (j>=64 && j<66) || (j>=68 && j<70) || (j>=72 && j<74) || (j>=76 && j<78) || (j>=80 && j<82) 
                	|| (j>=84 && j<86) || (j>=88 && j<90) || (j>=92 && j<94) || (j>=96 && j<98) || (j>=100 && j<102) || (j>=104 && j<106) || (j>=108 && j<110) || 
                	(j>=112 && j<114) || (j>=116 && j<118)     || (j>=120 && j<122) || (j>=124 && j<126)
			)) {
	    tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   } else if (i == 14 + k && ( (j>=2 && j<4) || (j>=6 && j<8) || (j>=10 && j<12) || (j>=14 && j<16) || (j>=18 && j<20) || (j>=22 && j<24) || (j>=26 && j<28)
			|| (j>=30 && j<32) || (j>=34 && j<36) || (j>=38 && j<40) || (j>=42 && j<44) || (j>=46 && j<48) || (j>=50 && j<52) 
			|| (j>=54 && j<56) || (j>=58 && j<60) || (j>=62 && j<64) || (j>=66 && j<68) || (j>=70 && j<72) || (j>=74 && j<76) 
			|| (j>=78 && j<80) || (j>=82 && j<84) || (j>=86 && j<88) || (j>=90 && j<92) || (j>=94 && j<96)
                        || (j>=98 && j<100) || (j>=102 && j<104) || (j>=106 && j<108) || (j>=110 && j<112) || (j>=114 && j<116) 
			|| (j>=118 && j<120) || (j>=122 && j<124) || (j>=126 && j<128) )) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 

	   } else if (i == 15 + k && j % 2 == 0) {
	   
	    tmp_neg = Cudd_Not(var); 
	    tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   
	   } else if (i == 15 + k && j % 2 == 1) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 

	   }
	  
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd_rec[j]);
      bdd_rec[j] = tmp;
    }
  }
    
    bdd1 = Cudd_bddOr(gbm,bdd_rec[0],bdd_rec[1]); 
    Cudd_Ref(bdd1);   
    
    for (k = 2;k<128;k++) {
    bdd1 = Cudd_bddOr(gbm,bdd1,bdd_rec[k]);
    Cudd_Ref(bdd1);   
     }

    bdd = Cudd_bddAnd(gbm,bdd,bdd1);
    Cudd_Ref(bdd);   
/*
    for (i = 16; i < 24; i++) {
     var = Cudd_bddIthVar(gbm,i); 
     
      tmp_neg = Cudd_Not(var); 
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd2);
    
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd2);
      bdd2 = tmp;
    }
   
    bdd = Cudd_bddAnd(gbm,bdd,bdd2);
    Cudd_Ref(bdd);
    
    for (i = 24; i < 32; i++) {
     var = Cudd_bddIthVar(gbm,i); 
     if(i != 29){
      tmp_neg = Cudd_Not(var); 
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd3); 
     }else{
      tmp = Cudd_bddAnd(gbm, var, bdd3); 
     }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd3);
      bdd3 = tmp;
    }
    
    bdd = Cudd_bddAnd(gbm,bdd,bdd3);
    Cudd_Ref(bdd);
    
    for (i = 32; i < 40; i++) {
     var = Cudd_bddIthVar(gbm,i); 
     if(i != 33 && i!= 36 && i != 37 && i != 39){
      tmp_neg = Cudd_Not(var); 
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd4); 
     }else{
      tmp = Cudd_bddAnd(gbm, var, bdd4);
     }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd4);
      bdd4 = tmp;
    }
    
    bdd = Cudd_bddAnd(gbm,bdd,bdd4);
    Cudd_Ref(bdd);
    
    for (i = 40; i < 48; i++) {
     var = Cudd_bddIthVar(gbm,i); 
     if(i != 41 && i!= 43 && i != 47 ){
      tmp_neg = Cudd_Not(var); 
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd5);
     }else{
      tmp = Cudd_bddAnd(gbm, var, bdd5); 
     }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd5);
      bdd5 = tmp;
    }

    bdd = Cudd_bddAnd(gbm,bdd,bdd5);
    Cudd_Ref(bdd);
    
    for (i = 48; i < 56; i++) {
     var = Cudd_bddIthVar(gbm,i); 
     if(i != 49 && i!= 51 && i != 53 ){
      tmp_neg = Cudd_Not(var); 
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd6); 
     }else{
      tmp = Cudd_bddAnd(gbm, var, bdd6); 
     }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd6);
      bdd6 = tmp;
    }
    
     bdd = Cudd_bddAnd(gbm,bdd,bdd6);
     Cudd_Ref(bdd);
    
    for (i = 56; i < 64; i++) {
     var = Cudd_bddIthVar(gbm,i); 
     if(i != 57 && i!= 59 && i != 61 ){
      tmp_neg = Cudd_Not(var); 
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd7);
     }else{
      tmp = Cudd_bddAnd(gbm, var, bdd7); 
     }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd7);
      bdd7 = tmp;
    }
     
    bdd = Cudd_bddAnd(gbm,bdd,bdd7);
    Cudd_Ref(bdd);
    
for (i = 64; i < 72; i++) {
     var = Cudd_bddIthVar(gbm,i); 
     if(i != 69){
      tmp_neg = Cudd_Not(var);
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd8); 
     }else{
      tmp = Cudd_bddAnd(gbm, var, bdd8); 
     }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd8);
      bdd8 = tmp;
    }
     bdd = Cudd_bddAnd(gbm,bdd,bdd8);
*/
    DdNode* bdd71;
   
    bdd71 = Cudd_ReadOne(gbm); 
     Cudd_Ref(bdd71); 

     for (i = 16; i < 18; i++) {  
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd71); 
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd71);
      bdd71 = tmp;
    }
    
    
    bdd = Cudd_bddAnd(gbm,bdd,bdd71);
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
     
     for(i = 0; i < 128; i++){
     bdd_rec[i] = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd_rec[i]); /*Increases the reference count of a node*/
     } 
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
     bdd6 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd6); /*Increases the reference count of a node*/
     bdd7 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd7); /*Increases the reference count of a node*/
     bdd8 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd8); /*Increases the reference count of a node*/
     bdd9 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd9); /*Increases the reference count of a node*/
   
     for (i = 0; i < 8; i++) {
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
     if(i != 3) {
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

    int j;int k = 0;
     for(j = 0;j<128;j++){ 
       for (i = 8; i < 16; i++) {
          var = Cudd_bddIthVar(gbm,i); 
          if(i%8 ==  0) {
          //tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, var, bdd_rec[j]); 
	  }
	  else if(i == 9+k && j < 64 ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
          }else if(i == 9+k && j >= 64) {
	  tmp = Cudd_bddAnd(gbm, var, bdd_rec[j]); 
          }
	  else if ( (i == 10 + k) && ( ( j < 32 ) || ( j >= 64 && j < 96 ) ) ) {
          tmp_neg = Cudd_Not(var);
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
          } else if ( i == 10 + k && ( ( j >= 32 && j < 64 ) || ( j >= 96 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
	  } else if (i == 11 + k && ( (j<16) || (j>=32 && j<48) || (j>=64 && j<80) || (j>=96 && j<112) ) ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	  } else if (i == 11 + k && ( (j >= 16 && j < 32) || ( j >= 48 && j < 64 ) || ( j >= 80 && j < 96 ) || ( j >= 112 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
          } else if ( i == 12 + k && ( ( j < 8 ) || ( j >= 16 && j < 24) || (j >= 32 && j < 40) || (j>=48 && j<56) || ( j >= 64 && j < 72 ) || 
		    (j >= 80 && j < 88) || (j >= 96 && j < 104) || (j>=112 && j<120) ) ) {
	   tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
           } else if (i == 12 + k && ( ( j >= 8 && j < 16 ) || ( j >= 24 && j < 32 ) || ( j >= 40 && j < 48) || ( j >= 56 && j < 64) 
			|| (j>72 && j<=80) || (j>=88 && j<96) || (j>=104 && j<112) || (j>=120) ) ) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]);  
 	   } else if (i == 13 + k && ( (j < 4) || (j >= 8 && j < 12) || (j >= 16 && j < 20) || (j >= 24 && j < 28) || (j >= 32 && j < 36) || (j >= 40 && j < 44)
			|| (j >= 48 && j < 52)  || (j >= 56 && j < 60)|| (j >= 64 && j < 68) || (j >= 72 && j < 76) || (j >= 80 && j < 84) || (j >= 88 && j < 92) 	
			|| (j >= 96 && j < 100) || (j >= 104 && j < 108) || (j >= 112 && j < 116) || (j >= 120 && j < 124))) {
	   tmp_neg = Cudd_Not(var);
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   
	   } else if (i == 13 + k && ( (j>=4 && j<8) || ( j >= 12 && j < 16 ) || ( j >= 20 && j < 24 ) || ( j >= 28 && j < 32 ) || ( j >= 36 && j < 40 ) 
			|| ( j >= 44 && j < 48 ) || ( j >= 52 && j < 56 ) || ( j >= 60 && j < 64 ) || ( j >= 68 && j < 72 ) || ( j >= 76 && j < 80 ) 	  
		        || ( j >= 84 && j < 88 ) || ( j >= 92 && j < 96 ) || ( j >= 100 && j < 104 ) || ( j >= 108 && j < 112 ) 
			|| ( j >= 116 && j < 120  ) 	|| ( j >= 124 && j < 128 ))) {
          
		   tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
           } else if ( i == 14 + k && ( (j<2) || (j>=4 && j<6)  || (j>=8 && j<10) || (j>=12 && j<14) || (j>=16 && j<18) || (j>=20 && j<22) || (j>=24 && j<26)
			|| (j>=28 && j<30) || (j>=32 && j<34) || (j>=36 && j<38) || (j>=40 && j<42) || (j>=44 && j<46) || (j>=48 && j<50) || (j>=52 && j<54) 	  
			|| (j>=56 && j<58) || (j>=60 && j<62) || (j>=64 && j<66) || (j>=68 && j<70) || (j>=72 && j<74) || (j>=76 && j<78) || (j>=80 && j<82) 
                	|| (j>=84 && j<86) || (j>=88 && j<90) || (j>=92 && j<94) || (j>=96 && j<98) || (j>=100 && j<102) || (j>=104 && j<106) || (j>=108 && j<110) || 
                	(j>=112 && j<114) || (j>=116 && j<118)     || (j>=120 && j<122) || (j>=124 && j<126)
			)) {
	    tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   } else if (i == 14 + k && ( (j>=2 && j<4) || (j>=6 && j<8) || (j>=10 && j<12) || (j>=14 && j<16) || (j>=18 && j<20) || (j>=22 && j<24) || (j>=26 && j<28)
			|| (j>=30 && j<32) || (j>=34 && j<36) || (j>=38 && j<40) || (j>=42 && j<44) || (j>=46 && j<48) || (j>=50 && j<52) 
			|| (j>=54 && j<56) || (j>=58 && j<60) || (j>=62 && j<64) || (j>=66 && j<68) || (j>=70 && j<72) || (j>=74 && j<76) 
			|| (j>=78 && j<80) || (j>=82 && j<84) || (j>=86 && j<88) || (j>=90 && j<92) || (j>=94 && j<96)
                        || (j>=98 && j<100) || (j>=102 && j<104) || (j>=106 && j<108) || (j>=110 && j<112) || (j>=114 && j<116) 
			|| (j>=118 && j<120) || (j>=122 && j<124) || (j>=126 && j<128) )) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 

	   } else if (i == 15 + k && j % 2 == 0) {
	   
	    tmp_neg = Cudd_Not(var); 
	    tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   
	   } else if (i == 15 + k && j % 2 == 1) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 

	   }
	  
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd_rec[j]);
      bdd_rec[j] = tmp;
    }
  }
    
    bdd1 = Cudd_bddOr(gbm,bdd_rec[0],bdd_rec[1]); 
    Cudd_Ref(bdd1);   
    
    for (k = 2;k<128;k++) {
    bdd1 = Cudd_bddOr(gbm,bdd1,bdd_rec[k]);
    Cudd_Ref(bdd1);   
     }
    bdd = Cudd_bddAnd(gbm,bdd,bdd1);
    Cudd_Ref(bdd);   
/*

     for(j = 0;j<128;j++){ 
       for (i = 16; i < 24; i++) {
          var = Cudd_bddIthVar(gbm,i); 
          if(i%8 ==  0) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	  }
	  else if(i == 17+k && j < 64 ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
          }else if(i == 17+k && j >= 64) {
	  tmp = Cudd_bddAnd(gbm, var, bdd_rec[j]); 
          }
	  else if ( (i == 18 + k) && ( ( j < 32 ) || ( j >= 64 && j < 96 ) ) ) {
          tmp_neg = Cudd_Not(var);
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
          } else if ( i == 18 + k && ( ( j >= 32 && j < 64 ) || ( j >= 96 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
	  } else if (i == 19 + k && ( (j<16) || (j>=32 && j<48) || (j>=64 && j<80) || (j>=96 && j<112) ) ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	  } else if (i == 19 + k && ( (j >= 16 && j < 32) || ( j >= 48 && j < 64 ) || ( j >= 80 && j < 96 ) || ( j >= 112 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
          } else if ( i == 20 + k && ( ( j < 8 ) || ( j >= 16 && j < 24) || (j >= 32 && j < 40) || (j>=48 && j<56) || ( j >= 64 && j < 72 ) || 
		    (j >= 80 && j < 88) || (j >= 96 && j < 104) || (j>=112 && j<120) ) ) {
	   tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
           } else if (i == 20 + k && ( ( j >= 8 && j < 16 ) || ( j >= 24 && j < 32 ) || ( j >= 40 && j < 48) || ( j >= 56 && j < 64) 
			|| (j>72 && j<=80) || (j>=88 && j<96) || (j>=104 && j<112) || (j>=120) ) ) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]);  
 	   } else if (i == 21 + k && ( (j < 4) || (j >= 8 && j < 12) || (j >= 16 && j < 20) || (j >= 24 && j < 28) || (j >= 32 && j < 36) || (j >= 40 && j < 44)
			|| (j >= 48 && j < 52)  || (j >= 56 && j < 60)|| (j >= 64 && j < 68) || (j >= 72 && j < 76) || (j >= 80 && j < 84) || (j >= 88 && j < 92) 	
			|| (j >= 96 && j < 100) || (j >= 104 && j < 108) || (j >= 112 && j < 116) || (j >= 120 && j < 124))) {
	   tmp_neg = Cudd_Not(var);
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   
	   } else if (i == 21 + k && ( (j>=4 && j<8) || ( j >= 12 && j < 16 ) || ( j >= 20 && j < 24 ) || ( j >= 28 && j < 32 ) || ( j >= 36 && j < 40 ) 
			|| ( j >= 44 && j < 48 ) || ( j >= 52 && j < 56 ) || ( j >= 60 && j < 64 ) || ( j >= 68 && j < 72 ) || ( j >= 76 && j < 80 ) 	  
		        || ( j >= 84 && j < 88 ) || ( j >= 92 && j < 96 ) || ( j >= 100 && j < 104 ) || ( j >= 108 && j < 112 ) 
			|| ( j >= 116 && j < 120  ) 	|| ( j >= 124 && j < 128 ))) {
          
		   tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
           } else if ( i == 22 + k && ( (j<2) || (j>=4 && j<6)  || (j>=8 && j<10) || (j>=12 && j<14) || (j>=16 && j<18) || (j>=20 && j<22) || (j>=24 && j<26)
			|| (j>=28 && j<30) || (j>=32 && j<34) || (j>=36 && j<38) || (j>=40 && j<42) || (j>=44 && j<46) || (j>=48 && j<50) || (j>=52 && j<54) 	  
			|| (j>=56 && j<58) || (j>=60 && j<62) || (j>=64 && j<66) || (j>=68 && j<70) || (j>=72 && j<74) || (j>=76 && j<78) || (j>=80 && j<82) 
                	|| (j>=84 && j<86) || (j>=88 && j<90) || (j>=92 && j<94) || (j>=96 && j<98) || (j>=100 && j<102) || (j>=104 && j<106) || (j>=108 && j<110) || 
                	(j>=112 && j<114) || (j>=116 && j<118)     || (j>=120 && j<122) || (j>=124 && j<126)
			)) {
	    tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   } else if (i == 22 + k && ( (j>=2 && j<4) || (j>=6 && j<8) || (j>=10 && j<12) || (j>=14 && j<16) || (j>=18 && j<20) || (j>=22 && j<24) || (j>=26 && j<28)
			|| (j>=30 && j<32) || (j>=34 && j<36) || (j>=38 && j<40) || (j>=42 && j<44) || (j>=46 && j<48) || (j>=50 && j<52) 
			|| (j>=54 && j<56) || (j>=58 && j<60) || (j>=62 && j<64) || (j>=66 && j<68) || (j>=70 && j<72) || (j>=74 && j<76) 
			|| (j>=78 && j<80) || (j>=82 && j<84) || (j>=86 && j<88) || (j>=90 && j<92) || (j>=94 && j<96)
                        || (j>=98 && j<100) || (j>=102 && j<104) || (j>=106 && j<108) || (j>=110 && j<112) || (j>=114 && j<116) 
			|| (j>=118 && j<120) || (j>=122 && j<124) || (j>=126 && j<128) )) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 

	   } else if (i == 23 + k && j % 2 == 0) {
	   
	    tmp_neg = Cudd_Not(var); 
	    tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   
	   } else if (i == 23 + k && j % 2 == 1) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 

	   }
	  
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd_rec[j]);
      bdd_rec[j] = tmp;
    }
  }
    

    bdd9 = Cudd_bddOr(gbm,bdd_rec[0],bdd_rec[1]); 
    Cudd_Ref(bdd1);   
    
    for (k = 2;k<128;k++) {
    bdd9 = Cudd_bddOr(gbm,bdd9,bdd_rec[k]);
    Cudd_Ref(bdd1);   
     }

    bdd = Cudd_bddAnd(gbm,bdd,bdd9);
    Cudd_Ref(bdd);   
    
    for (i = 24; i < 32; i++) {
     var = Cudd_bddIthVar(gbm,i); 
     
      tmp_neg = Cudd_Not(var); 
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd2); 
    
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd2);
      bdd2 = tmp;
    }
   
    bdd = Cudd_bddAnd(gbm,bdd,bdd2);
    Cudd_Ref(bdd);
    
    for (i = 32; i < 40; i++) {
     var = Cudd_bddIthVar(gbm,i); 
     if(i != 37){
      tmp_neg = Cudd_Not(var); 
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd3); 
     }else{
      tmp = Cudd_bddAnd(gbm, var, bdd3); 
     }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd3);
      bdd3 = tmp;
    }
    
    bdd = Cudd_bddAnd(gbm,bdd,bdd3);
    Cudd_Ref(bdd);
    
    for (i = 40; i < 48; i++) {
     var = Cudd_bddIthVar(gbm,i); 
     if(i != 41 && i!= 44 && i != 45 && i != 47){
      tmp_neg = Cudd_Not(var); 
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd4); 
     }else{
      tmp = Cudd_bddAnd(gbm, var, bdd4);
     }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd4);
      bdd4 = tmp;
    }
    
    bdd = Cudd_bddAnd(gbm,bdd,bdd4);
    Cudd_Ref(bdd);
    
    for (i = 48; i < 56; i++) {
     var = Cudd_bddIthVar(gbm,i); 
     if(i != 49 && i!= 51 && i != 55 ){
      tmp_neg = Cudd_Not(var); 
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd5); 
     }else{
      tmp = Cudd_bddAnd(gbm, var, bdd5); 
     }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd5);
      bdd5 = tmp;
    }

    bdd = Cudd_bddAnd(gbm,bdd,bdd5);
    Cudd_Ref(bdd);
    
    for (i = 56; i < 64; i++) {
     var = Cudd_bddIthVar(gbm,i); 
     if(i != 57 && i!= 59 && i != 61 ){
      tmp_neg = Cudd_Not(var); 
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd6);
     }else{
      tmp = Cudd_bddAnd(gbm, var, bdd6); 
     }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd6);
      bdd6 = tmp;
    }
    
     bdd = Cudd_bddAnd(gbm,bdd,bdd6);
     Cudd_Ref(bdd);
    
    for (i = 64; i < 72; i++) {
     var = Cudd_bddIthVar(gbm,i); 
     if(i != 65 && i!= 67 && i != 69 ){
      tmp_neg = Cudd_Not(var); 
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd7);
     }else{
      tmp = Cudd_bddAnd(gbm, var, bdd7);
     }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd7);
      bdd7 = tmp;
    }
     
    bdd = Cudd_bddAnd(gbm,bdd,bdd7);
    Cudd_Ref(bdd);
    
for (i = 72; i < 80; i++) {
     var = Cudd_bddIthVar(gbm,i); 
     if(i != 77){
      tmp_neg = Cudd_Not(var); 
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd8); 
     }else{
      tmp = Cudd_bddAnd(gbm, var, bdd8);
     }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd8);
      bdd8 = tmp;
    }
     bdd = Cudd_bddAnd(gbm,bdd,bdd8);
*/
    DdNode* bdd71;
   
    bdd71 = Cudd_ReadOne(gbm); 
     Cudd_Ref(bdd71); 

     for (i = 16; i < 18; i++) {  
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd71); 
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd71);
      bdd71 = tmp;
    }
    
    
    bdd = Cudd_bddAnd(gbm,bdd,bdd71);
    Cudd_Ref(bdd);

return bdd;


}	



DdNode* scrivi_bdd_due (DdManager *gbm, DdNode *bdd, DdNode * var) {
 DdNode* bdd_rec[128];
 DdNode *bdd1, *bdd2, *bdd3, *bdd4, *bdd5, *bdd6, *bdd7, *bdd8, *bdd9,*bdd10,*tmp,*tmp_neg;
     bdd = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd); /*Increases the reference count of a node*/
     int i; 
     
     for(i = 0; i < 128; i++){
     bdd_rec[i] = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd_rec[i]); /*Increases the reference count of a node*/
     } 
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
     bdd6 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd6); /*Increases the reference count of a node*/
     bdd7 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd7); /*Increases the reference count of a node*/
     bdd8 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd8); /*Increases the reference count of a node*/
     bdd9 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd9); /*Increases the reference count of a node*/
   
     for (i = 0; i < 8; i++) {
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
     if(i != 3) {
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

    int j;int k = 0;
     for(j = 0;j<128;j++){ 
       for (i = 8; i < 16; i++) {
          var = Cudd_bddIthVar(gbm,i); 
          if(i%8 ==  0) {
          //tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, var, bdd_rec[j]); 
	  }
	  else if(i == 9+k && j < 64 ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
          }else if(i == 9+k && j >= 64) {
	  tmp = Cudd_bddAnd(gbm, var, bdd_rec[j]); 
          }
	  else if ( (i == 10 + k) && ( ( j < 32 ) || ( j >= 64 && j < 96 ) ) ) {
          tmp_neg = Cudd_Not(var);
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
          } else if ( i == 10 + k && ( ( j >= 32 && j < 64 ) || ( j >= 96 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
	  } else if (i == 11 + k && ( (j<16) || (j>=32 && j<48) || (j>=64 && j<80) || (j>=96 && j<112) ) ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	  } else if (i == 11 + k && ( (j >= 16 && j < 32) || ( j >= 48 && j < 64 ) || ( j >= 80 && j < 96 ) || ( j >= 112 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
          } else if ( i == 12 + k && ( ( j < 8 ) || ( j >= 16 && j < 24) || (j >= 32 && j < 40) || (j>=48 && j<56) || ( j >= 64 && j < 72 ) || 
		    (j >= 80 && j < 88) || (j >= 96 && j < 104) || (j>=112 && j<120) ) ) {
	   tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
           } else if (i == 12 + k && ( ( j >= 8 && j < 16 ) || ( j >= 24 && j < 32 ) || ( j >= 40 && j < 48) || ( j >= 56 && j < 64) 
			|| (j>72 && j<=80) || (j>=88 && j<96) || (j>=104 && j<112) || (j>=120) ) ) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]);  
 	   } else if (i == 13 + k && ( (j < 4) || (j >= 8 && j < 12) || (j >= 16 && j < 20) || (j >= 24 && j < 28) || (j >= 32 && j < 36) || (j >= 40 && j < 44)
			|| (j >= 48 && j < 52)  || (j >= 56 && j < 60)|| (j >= 64 && j < 68) || (j >= 72 && j < 76) || (j >= 80 && j < 84) || (j >= 88 && j < 92) 	
			|| (j >= 96 && j < 100) || (j >= 104 && j < 108) || (j >= 112 && j < 116) || (j >= 120 && j < 124))) {
	   tmp_neg = Cudd_Not(var);
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   
	   } else if (i == 13 + k && ( (j>=4 && j<8) || ( j >= 12 && j < 16 ) || ( j >= 20 && j < 24 ) || ( j >= 28 && j < 32 ) || ( j >= 36 && j < 40 ) 
			|| ( j >= 44 && j < 48 ) || ( j >= 52 && j < 56 ) || ( j >= 60 && j < 64 ) || ( j >= 68 && j < 72 ) || ( j >= 76 && j < 80 ) 	  
		        || ( j >= 84 && j < 88 ) || ( j >= 92 && j < 96 ) || ( j >= 100 && j < 104 ) || ( j >= 108 && j < 112 ) 
			|| ( j >= 116 && j < 120  ) 	|| ( j >= 124 && j < 128 ))) {
          
		   tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
           } else if ( i == 14 + k && ( (j<2) || (j>=4 && j<6)  || (j>=8 && j<10) || (j>=12 && j<14) || (j>=16 && j<18) || (j>=20 && j<22) || (j>=24 && j<26)
			|| (j>=28 && j<30) || (j>=32 && j<34) || (j>=36 && j<38) || (j>=40 && j<42) || (j>=44 && j<46) || (j>=48 && j<50) || (j>=52 && j<54) 	  
			|| (j>=56 && j<58) || (j>=60 && j<62) || (j>=64 && j<66) || (j>=68 && j<70) || (j>=72 && j<74) || (j>=76 && j<78) || (j>=80 && j<82) 
                	|| (j>=84 && j<86) || (j>=88 && j<90) || (j>=92 && j<94) || (j>=96 && j<98) || (j>=100 && j<102) || (j>=104 && j<106) || (j>=108 && j<110) || 
                	(j>=112 && j<114) || (j>=116 && j<118)     || (j>=120 && j<122) || (j>=124 && j<126)
			)) {
	    tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   } else if (i == 14 + k && ( (j>=2 && j<4) || (j>=6 && j<8) || (j>=10 && j<12) || (j>=14 && j<16) || (j>=18 && j<20) || (j>=22 && j<24) || (j>=26 && j<28)
			|| (j>=30 && j<32) || (j>=34 && j<36) || (j>=38 && j<40) || (j>=42 && j<44) || (j>=46 && j<48) || (j>=50 && j<52) 
			|| (j>=54 && j<56) || (j>=58 && j<60) || (j>=62 && j<64) || (j>=66 && j<68) || (j>=70 && j<72) || (j>=74 && j<76) 
			|| (j>=78 && j<80) || (j>=82 && j<84) || (j>=86 && j<88) || (j>=90 && j<92) || (j>=94 && j<96)
                        || (j>=98 && j<100) || (j>=102 && j<104) || (j>=106 && j<108) || (j>=110 && j<112) || (j>=114 && j<116) 
			|| (j>=118 && j<120) || (j>=122 && j<124) || (j>=126 && j<128) )) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 

	   } else if (i == 15 + k && j % 2 == 0) {
	   
	    tmp_neg = Cudd_Not(var); 
	    tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   
	   } else if (i == 15 + k && j % 2 == 1) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 

	   }
	  
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd_rec[j]);
      bdd_rec[j] = tmp;
    }
  }
    
    bdd1 = Cudd_bddOr(gbm,bdd_rec[0],bdd_rec[1]); 
    Cudd_Ref(bdd1);   
    
    for (k = 2;k<128;k++) {
    bdd1 = Cudd_bddOr(gbm,bdd1,bdd_rec[k]);
    Cudd_Ref(bdd1);   
     }
    bdd = Cudd_bddAnd(gbm,bdd,bdd1);
    Cudd_Ref(bdd);   
/*

     for(j = 0;j<128;j++){ 
       for (i = 16; i < 24; i++) {
          var = Cudd_bddIthVar(gbm,i); 
          if(i%8 ==  0) {
          //tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, var, bdd_rec[j]); 
	  }
	  else if(i == 17+k && j < 64 ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
          }else if(i == 17+k && j >= 64) {
	  tmp = Cudd_bddAnd(gbm, var, bdd_rec[j]); 
          }
	  else if ( (i == 18 + k) && ( ( j < 32 ) || ( j >= 64 && j < 96 ) ) ) {
          tmp_neg = Cudd_Not(var);
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
          } else if ( i == 18 + k && ( ( j >= 32 && j < 64 ) || ( j >= 96 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
	  } else if (i == 19 + k && ( (j<16) || (j>=32 && j<48) || (j>=64 && j<80) || (j>=96 && j<112) ) ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	  } else if (i == 19 + k && ( (j >= 16 && j < 32) || ( j >= 48 && j < 64 ) || ( j >= 80 && j < 96 ) || ( j >= 112 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
          } else if ( i == 20 + k && ( ( j < 8 ) || ( j >= 16 && j < 24) || (j >= 32 && j < 40) || (j>=48 && j<56) || ( j >= 64 && j < 72 ) || 
		    (j >= 80 && j < 88) || (j >= 96 && j < 104) || (j>=112 && j<120) ) ) {
	   tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
           } else if (i == 20 + k && ( ( j >= 8 && j < 16 ) || ( j >= 24 && j < 32 ) || ( j >= 40 && j < 48) || ( j >= 56 && j < 64) 
			|| (j>72 && j<=80) || (j>=88 && j<96) || (j>=104 && j<112) || (j>=120) ) ) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]);  
 	   } else if (i == 21 + k && ( (j < 4) || (j >= 8 && j < 12) || (j >= 16 && j < 20) || (j >= 24 && j < 28) || (j >= 32 && j < 36) || (j >= 40 && j < 44)
			|| (j >= 48 && j < 52)  || (j >= 56 && j < 60)|| (j >= 64 && j < 68) || (j >= 72 && j < 76) || (j >= 80 && j < 84) || (j >= 88 && j < 92) 	
			|| (j >= 96 && j < 100) || (j >= 104 && j < 108) || (j >= 112 && j < 116) || (j >= 120 && j < 124))) {
	   tmp_neg = Cudd_Not(var);
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   
	   } else if (i == 21 + k && ( (j>=4 && j<8) || ( j >= 12 && j < 16 ) || ( j >= 20 && j < 24 ) || ( j >= 28 && j < 32 ) || ( j >= 36 && j < 40 ) 
			|| ( j >= 44 && j < 48 ) || ( j >= 52 && j < 56 ) || ( j >= 60 && j < 64 ) || ( j >= 68 && j < 72 ) || ( j >= 76 && j < 80 ) 	  
		        || ( j >= 84 && j < 88 ) || ( j >= 92 && j < 96 ) || ( j >= 100 && j < 104 ) || ( j >= 108 && j < 112 ) 
			|| ( j >= 116 && j < 120  ) 	|| ( j >= 124 && j < 128 ))) {
          
		   tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
           } else if ( i == 22 + k && ( (j<2) || (j>=4 && j<6)  || (j>=8 && j<10) || (j>=12 && j<14) || (j>=16 && j<18) || (j>=20 && j<22) || (j>=24 && j<26)
			|| (j>=28 && j<30) || (j>=32 && j<34) || (j>=36 && j<38) || (j>=40 && j<42) || (j>=44 && j<46) || (j>=48 && j<50) || (j>=52 && j<54) 	  
			|| (j>=56 && j<58) || (j>=60 && j<62) || (j>=64 && j<66) || (j>=68 && j<70) || (j>=72 && j<74) || (j>=76 && j<78) || (j>=80 && j<82) 
                	|| (j>=84 && j<86) || (j>=88 && j<90) || (j>=92 && j<94) || (j>=96 && j<98) || (j>=100 && j<102) || (j>=104 && j<106) || (j>=108 && j<110) || 
                	(j>=112 && j<114) || (j>=116 && j<118)     || (j>=120 && j<122) || (j>=124 && j<126)
			)) {
	    tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   } else if (i == 22 + k && ( (j>=2 && j<4) || (j>=6 && j<8) || (j>=10 && j<12) || (j>=14 && j<16) || (j>=18 && j<20) || (j>=22 && j<24) || (j>=26 && j<28)
			|| (j>=30 && j<32) || (j>=34 && j<36) || (j>=38 && j<40) || (j>=42 && j<44) || (j>=46 && j<48) || (j>=50 && j<52) 
			|| (j>=54 && j<56) || (j>=58 && j<60) || (j>=62 && j<64) || (j>=66 && j<68) || (j>=70 && j<72) || (j>=74 && j<76) 
			|| (j>=78 && j<80) || (j>=82 && j<84) || (j>=86 && j<88) || (j>=90 && j<92) || (j>=94 && j<96)
                        || (j>=98 && j<100) || (j>=102 && j<104) || (j>=106 && j<108) || (j>=110 && j<112) || (j>=114 && j<116) 
			|| (j>=118 && j<120) || (j>=122 && j<124) || (j>=126 && j<128) )) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 

	   } else if (i == 23 + k && j % 2 == 0) {
	   
	    tmp_neg = Cudd_Not(var); 
	    tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   
	   } else if (i == 23 + k && j % 2 == 1) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 

	   }
	  
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd_rec[j]);
      bdd_rec[j] = tmp;
    }
  }
    

    bdd9 = Cudd_bddOr(gbm,bdd_rec[0],bdd_rec[1]); 
    Cudd_Ref(bdd1);   
    
    for (k = 2;k<128;k++) {
    bdd9 = Cudd_bddOr(gbm,bdd9,bdd_rec[k]);
    Cudd_Ref(bdd1);   
    }

    bdd = Cudd_bddAnd(gbm,bdd,bdd9);
    Cudd_Ref(bdd);   

     for(j = 0;j<128;j++){ 
       for (i = 24; i < 32; i++) {
          var = Cudd_bddIthVar(gbm,i); 
          if(i%8 ==  0) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	  }
	  else if(i == 25+k && j < 64 ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
          }else if(i == 25+k && j >= 64) {
	  tmp = Cudd_bddAnd(gbm, var, bdd_rec[j]); 
          }
	  else if ( (i == 26 + k) && ( ( j < 32 ) || ( j >= 64 && j < 96 ) ) ) {
          tmp_neg = Cudd_Not(var);
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
          } else if ( i == 26 + k && ( ( j >= 32 && j < 64 ) || ( j >= 96 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
	  } else if (i == 27 + k && ( (j<16) || (j>=32 && j<48) || (j>=64 && j<80) || (j>=96 && j<112) ) ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	  } else if (i == 27 + k && ( (j >= 16 && j < 32) || ( j >= 48 && j < 64 ) || ( j >= 80 && j < 96 ) || ( j >= 112 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
          } else if ( i == 28 + k && ( ( j < 8 ) || ( j >= 16 && j < 24) || (j >= 32 && j < 40) || (j>=48 && j<56) || ( j >= 64 && j < 72 ) || 
		    (j >= 80 && j < 88) || (j >= 96 && j < 104) || (j>=112 && j<120) ) ) {
	   tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
           } else if (i == 28 + k && ( ( j >= 8 && j < 16 ) || ( j >= 24 && j < 32 ) || ( j >= 40 && j < 48) || ( j >= 56 && j < 64) 
			|| (j>72 && j<=80) || (j>=88 && j<96) || (j>=104 && j<112) || (j>=120) ) ) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]);  
 	   } else if (i == 29 + k && ( (j < 4) || (j >= 8 && j < 12) || (j >= 16 && j < 20) || (j >= 24 && j < 28) || (j >= 32 && j < 36) || (j >= 40 && j < 44)
			|| (j >= 48 && j < 52)  || (j >= 56 && j < 60)|| (j >= 64 && j < 68) || (j >= 72 && j < 76) || (j >= 80 && j < 84) || (j >= 88 && j < 92) 	
			|| (j >= 96 && j < 100) || (j >= 104 && j < 108) || (j >= 112 && j < 116) || (j >= 120 && j < 124))) {
	   tmp_neg = Cudd_Not(var);
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   
	   } else if (i == 29 + k && ( (j>=4 && j<8) || ( j >= 12 && j < 16 ) || ( j >= 20 && j < 24 ) || ( j >= 28 && j < 32 ) || ( j >= 36 && j < 40 ) 
			|| ( j >= 44 && j < 48 ) || ( j >= 52 && j < 56 ) || ( j >= 60 && j < 64 ) || ( j >= 68 && j < 72 ) || ( j >= 76 && j < 80 ) 	  
		        || ( j >= 84 && j < 88 ) || ( j >= 92 && j < 96 ) || ( j >= 100 && j < 104 ) || ( j >= 108 && j < 112 ) 
			|| ( j >= 116 && j < 120  ) 	|| ( j >= 124 && j < 128 ))) {
          
		   tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
           } else if ( i == 30 + k && ( (j<2) || (j>=4 && j<6)  || (j>=8 && j<10) || (j>=12 && j<14) || (j>=16 && j<18) || (j>=20 && j<22) || (j>=24 && j<26)
			|| (j>=28 && j<30) || (j>=32 && j<34) || (j>=36 && j<38) || (j>=40 && j<42) || (j>=44 && j<46) || (j>=48 && j<50) || (j>=52 && j<54) 	  
			|| (j>=56 && j<58) || (j>=60 && j<62) || (j>=64 && j<66) || (j>=68 && j<70) || (j>=72 && j<74) || (j>=76 && j<78) || (j>=80 && j<82) 
                	|| (j>=84 && j<86) || (j>=88 && j<90) || (j>=92 && j<94) || (j>=96 && j<98) || (j>=100 && j<102) || (j>=104 && j<106) || (j>=108 && j<110) || 
                	(j>=112 && j<114) || (j>=116 && j<118)     || (j>=120 && j<122) || (j>=124 && j<126)
			)) {
	    tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   } else if (i == 30 + k && ( (j>=2 && j<4) || (j>=6 && j<8) || (j>=10 && j<12) || (j>=14 && j<16) || (j>=18 && j<20) || (j>=22 && j<24) || (j>=26 && j<28)
			|| (j>=30 && j<32) || (j>=34 && j<36) || (j>=38 && j<40) || (j>=42 && j<44) || (j>=46 && j<48) || (j>=50 && j<52) 
			|| (j>=54 && j<56) || (j>=58 && j<60) || (j>=62 && j<64) || (j>=66 && j<68) || (j>=70 && j<72) || (j>=74 && j<76) 
			|| (j>=78 && j<80) || (j>=82 && j<84) || (j>=86 && j<88) || (j>=90 && j<92) || (j>=94 && j<96)
                        || (j>=98 && j<100) || (j>=102 && j<104) || (j>=106 && j<108) || (j>=110 && j<112) || (j>=114 && j<116) 
			|| (j>=118 && j<120) || (j>=122 && j<124) || (j>=126 && j<128) )) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 

	   } else if (i == 31 + k && j % 2 == 0) {
	   
	    tmp_neg = Cudd_Not(var); 
	    tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   
	   } else if (i == 31 + k && j % 2 == 1) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 

	   }
	  
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd_rec[j]);
      bdd_rec[j] = tmp;
    }
  }
    
    bdd10 = Cudd_bddOr(gbm,bdd_rec[0],bdd_rec[1]); 
    Cudd_Ref(bdd10);   
    
    for (k = 2;k<128;k++) {
    bdd10 = Cudd_bddOr(gbm,bdd10,bdd_rec[k]);
    Cudd_Ref(bdd10);   
     }
    bdd = Cudd_bddAnd(gbm,bdd,bdd10);
    Cudd_Ref(bdd);   

    for (i = 32; i < 40; i++) {
     var = Cudd_bddIthVar(gbm,i); 
     
      tmp_neg = Cudd_Not(var); 
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd2);
    
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd2);
      bdd2 = tmp;
    }
   
    bdd = Cudd_bddAnd(gbm,bdd,bdd2);
    Cudd_Ref(bdd);
    
    for (i = 40; i < 48; i++) {
     var = Cudd_bddIthVar(gbm,i); 
     if(i != 45){
      tmp_neg = Cudd_Not(var); 
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd3); 
     }else{
      tmp = Cudd_bddAnd(gbm, var, bdd3); 
     }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd3);
      bdd3 = tmp;
    }
    
    bdd = Cudd_bddAnd(gbm,bdd,bdd3);
    Cudd_Ref(bdd);
    
    for (i = 48; i < 56; i++) {
     var = Cudd_bddIthVar(gbm,i); 
     if(i != 49 && i!= 52 && i != 53 && i != 55){
      tmp_neg = Cudd_Not(var); 
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd4); 
     }else{
      tmp = Cudd_bddAnd(gbm, var, bdd4); 
     }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd4);
      bdd4 = tmp;
    }
    
    bdd = Cudd_bddAnd(gbm,bdd,bdd4);
    Cudd_Ref(bdd);
    
    for (i = 56; i < 64; i++) {
     var = Cudd_bddIthVar(gbm,i); 
     if(i != 57 && i!= 59 && i != 63 ){
      tmp_neg = Cudd_Not(var); 
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd5); 
     }else{
      tmp = Cudd_bddAnd(gbm, var, bdd5); 
     }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd5);
      bdd5 = tmp;
    }

    bdd = Cudd_bddAnd(gbm,bdd,bdd5);
    Cudd_Ref(bdd);
    
    for (i = 64; i < 72; i++) {
     var = Cudd_bddIthVar(gbm,i);
     if(i != 65 && i!= 67 && i != 69 ){
      tmp_neg = Cudd_Not(var); 
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd6); 
     }else{
      tmp = Cudd_bddAnd(gbm, var, bdd6);
     }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd6);
      bdd6 = tmp;
    }
    
     bdd = Cudd_bddAnd(gbm,bdd,bdd6);
     Cudd_Ref(bdd);
    
    for (i = 72; i < 80; i++) {
     var = Cudd_bddIthVar(gbm,i); 
     if(i != 73 && i!= 75 && i != 77 ){
      tmp_neg = Cudd_Not(var); 
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd7);
     }else{
      tmp = Cudd_bddAnd(gbm, var, bdd7);
     }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd7);
      bdd7 = tmp;
    }
     
    bdd = Cudd_bddAnd(gbm,bdd,bdd7);
    Cudd_Ref(bdd);
    
for (i = 80; i < 88; i++) {
     var = Cudd_bddIthVar(gbm,i); 
     if(i != 85){
      tmp_neg = Cudd_Not(var); 
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd8); 
     }else{
      tmp = Cudd_bddAnd(gbm, var, bdd8);
     }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd8);
      bdd8 = tmp;
    }
     bdd = Cudd_bddAnd(gbm,bdd,bdd8);

*/

    DdNode* bdd71;
   
    bdd71 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd71); /*Increases the reference count of a node*/

     for (i = 16; i < 18; i++) {  
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd71); 
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd71);
      bdd71 = tmp;
    }
    
    
    bdd = Cudd_bddAnd(gbm,bdd,bdd71);
    Cudd_Ref(bdd);

return bdd;

}	



DdNode* scrivi_bdd_tre (DdManager *gbm, DdNode *bdd, DdNode * var) {

 DdNode* bdd_rec[128];
 DdNode *bdd1, *bdd2, *bdd3, *bdd4, *bdd5, *bdd6, *bdd7, *bdd8, *bdd9,*bdd10,*tmp,*tmp_neg,*bdd11;
     bdd = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd); /*Increases the reference count of a node*/
     int i; 
     
     for(i = 0; i < 128; i++){
     bdd_rec[i] = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd_rec[i]); /*Increases the reference count of a node*/
     } 
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
     bdd6 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd6); /*Increases the reference count of a node*/
     bdd7 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd7); /*Increases the reference count of a node*/
     bdd8 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd8); /*Increases the reference count of a node*/
     bdd9 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd9); /*Increases the reference count of a node*/
   
     for (i = 0; i < 8; i++) {
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
     if(i != 3) {
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

    int j;int k = 0;
     for(j = 0;j<128;j++){ 
       for (i = 8; i < 16; i++) {
          var = Cudd_bddIthVar(gbm,i); 
          if(i%8 ==  0) {
          //tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, var, bdd_rec[j]); 
	  }
	  else if(i == 9+k && j < 64 ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
          }else if(i == 9+k && j >= 64) {
	  tmp = Cudd_bddAnd(gbm, var, bdd_rec[j]); 
          }
	  else if ( (i == 10 + k) && ( ( j < 32 ) || ( j >= 64 && j < 96 ) ) ) {
          tmp_neg = Cudd_Not(var);
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
          } else if ( i == 10 + k && ( ( j >= 32 && j < 64 ) || ( j >= 96 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
	  } else if (i == 11 + k && ( (j<16) || (j>=32 && j<48) || (j>=64 && j<80) || (j>=96 && j<112) ) ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	  } else if (i == 11 + k && ( (j >= 16 && j < 32) || ( j >= 48 && j < 64 ) || ( j >= 80 && j < 96 ) || ( j >= 112 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
          } else if ( i == 12 + k && ( ( j < 8 ) || ( j >= 16 && j < 24) || (j >= 32 && j < 40) || (j>=48 && j<56) || ( j >= 64 && j < 72 ) || 
		    (j >= 80 && j < 88) || (j >= 96 && j < 104) || (j>=112 && j<120) ) ) {
	   tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
           } else if (i == 12 + k && ( ( j >= 8 && j < 16 ) || ( j >= 24 && j < 32 ) || ( j >= 40 && j < 48) || ( j >= 56 && j < 64) 
			|| (j>72 && j<=80) || (j>=88 && j<96) || (j>=104 && j<112) || (j>=120) ) ) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]);  
 	   } else if (i == 13 + k && ( (j < 4) || (j >= 8 && j < 12) || (j >= 16 && j < 20) || (j >= 24 && j < 28) || (j >= 32 && j < 36) || (j >= 40 && j < 44)
			|| (j >= 48 && j < 52)  || (j >= 56 && j < 60)|| (j >= 64 && j < 68) || (j >= 72 && j < 76) || (j >= 80 && j < 84) || (j >= 88 && j < 92) 	
			|| (j >= 96 && j < 100) || (j >= 104 && j < 108) || (j >= 112 && j < 116) || (j >= 120 && j < 124))) {
	   tmp_neg = Cudd_Not(var);
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   
	   } else if (i == 13 + k && ( (j>=4 && j<8) || ( j >= 12 && j < 16 ) || ( j >= 20 && j < 24 ) || ( j >= 28 && j < 32 ) || ( j >= 36 && j < 40 ) 
			|| ( j >= 44 && j < 48 ) || ( j >= 52 && j < 56 ) || ( j >= 60 && j < 64 ) || ( j >= 68 && j < 72 ) || ( j >= 76 && j < 80 ) 	  
		        || ( j >= 84 && j < 88 ) || ( j >= 92 && j < 96 ) || ( j >= 100 && j < 104 ) || ( j >= 108 && j < 112 ) 
			|| ( j >= 116 && j < 120  ) 	|| ( j >= 124 && j < 128 ))) {
          
		   tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
           } else if ( i == 14 + k && ( (j<2) || (j>=4 && j<6)  || (j>=8 && j<10) || (j>=12 && j<14) || (j>=16 && j<18) || (j>=20 && j<22) || (j>=24 && j<26)
			|| (j>=28 && j<30) || (j>=32 && j<34) || (j>=36 && j<38) || (j>=40 && j<42) || (j>=44 && j<46) || (j>=48 && j<50) || (j>=52 && j<54) 	  
			|| (j>=56 && j<58) || (j>=60 && j<62) || (j>=64 && j<66) || (j>=68 && j<70) || (j>=72 && j<74) || (j>=76 && j<78) || (j>=80 && j<82) 
                	|| (j>=84 && j<86) || (j>=88 && j<90) || (j>=92 && j<94) || (j>=96 && j<98) || (j>=100 && j<102) || (j>=104 && j<106) || (j>=108 && j<110) || 
                	(j>=112 && j<114) || (j>=116 && j<118)     || (j>=120 && j<122) || (j>=124 && j<126)
			)) {
	    tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   } else if (i == 14 + k && ( (j>=2 && j<4) || (j>=6 && j<8) || (j>=10 && j<12) || (j>=14 && j<16) || (j>=18 && j<20) || (j>=22 && j<24) || (j>=26 && j<28)
			|| (j>=30 && j<32) || (j>=34 && j<36) || (j>=38 && j<40) || (j>=42 && j<44) || (j>=46 && j<48) || (j>=50 && j<52) 
			|| (j>=54 && j<56) || (j>=58 && j<60) || (j>=62 && j<64) || (j>=66 && j<68) || (j>=70 && j<72) || (j>=74 && j<76) 
			|| (j>=78 && j<80) || (j>=82 && j<84) || (j>=86 && j<88) || (j>=90 && j<92) || (j>=94 && j<96)
                        || (j>=98 && j<100) || (j>=102 && j<104) || (j>=106 && j<108) || (j>=110 && j<112) || (j>=114 && j<116) 
			|| (j>=118 && j<120) || (j>=122 && j<124) || (j>=126 && j<128) )) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 

	   } else if (i == 15 + k && j % 2 == 0) {
	   
	    tmp_neg = Cudd_Not(var); 
	    tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   
	   } else if (i == 15 + k && j % 2 == 1) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 

	   }
	  
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd_rec[j]);
      bdd_rec[j] = tmp;
    }
  }
    
    bdd1 = Cudd_bddOr(gbm,bdd_rec[0],bdd_rec[1]); 
    Cudd_Ref(bdd1);   
    
    for (k = 2;k<128;k++) {
    bdd1 = Cudd_bddOr(gbm,bdd1,bdd_rec[k]);
    Cudd_Ref(bdd1);   
     }
    bdd = Cudd_bddAnd(gbm,bdd,bdd1);
    Cudd_Ref(bdd);   
/*

     for(j = 0;j<128;j++){ 
       for (i = 16; i < 24; i++) {
          var = Cudd_bddIthVar(gbm,i); 
          if(i%8 ==  0) {
          //tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, var, bdd_rec[j]); 
	  }
	  else if(i == 17+k && j < 64 ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
          }else if(i == 17+k && j >= 64) {
	  tmp = Cudd_bddAnd(gbm, var, bdd_rec[j]); 
          }
	  else if ( (i == 18 + k) && ( ( j < 32 ) || ( j >= 64 && j < 96 ) ) ) {
          tmp_neg = Cudd_Not(var);
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
          } else if ( i == 18 + k && ( ( j >= 32 && j < 64 ) || ( j >= 96 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
	  } else if (i == 19 + k && ( (j<16) || (j>=32 && j<48) || (j>=64 && j<80) || (j>=96 && j<112) ) ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	  } else if (i == 19 + k && ( (j >= 16 && j < 32) || ( j >= 48 && j < 64 ) || ( j >= 80 && j < 96 ) || ( j >= 112 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
          } else if ( i == 20 + k && ( ( j < 8 ) || ( j >= 16 && j < 24) || (j >= 32 && j < 40) || (j>=48 && j<56) || ( j >= 64 && j < 72 ) || 
		    (j >= 80 && j < 88) || (j >= 96 && j < 104) || (j>=112 && j<120) ) ) {
	   tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
           } else if (i == 20 + k && ( ( j >= 8 && j < 16 ) || ( j >= 24 && j < 32 ) || ( j >= 40 && j < 48) || ( j >= 56 && j < 64) 
			|| (j>72 && j<=80) || (j>=88 && j<96) || (j>=104 && j<112) || (j>=120) ) ) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]);  
 	   } else if (i == 21 + k && ( (j < 4) || (j >= 8 && j < 12) || (j >= 16 && j < 20) || (j >= 24 && j < 28) || (j >= 32 && j < 36) || (j >= 40 && j < 44)
			|| (j >= 48 && j < 52)  || (j >= 56 && j < 60)|| (j >= 64 && j < 68) || (j >= 72 && j < 76) || (j >= 80 && j < 84) || (j >= 88 && j < 92) 	
			|| (j >= 96 && j < 100) || (j >= 104 && j < 108) || (j >= 112 && j < 116) || (j >= 120 && j < 124))) {
	   tmp_neg = Cudd_Not(var);
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   
	   } else if (i == 21 + k && ( (j>=4 && j<8) || ( j >= 12 && j < 16 ) || ( j >= 20 && j < 24 ) || ( j >= 28 && j < 32 ) || ( j >= 36 && j < 40 ) 
			|| ( j >= 44 && j < 48 ) || ( j >= 52 && j < 56 ) || ( j >= 60 && j < 64 ) || ( j >= 68 && j < 72 ) || ( j >= 76 && j < 80 ) 	  
		        || ( j >= 84 && j < 88 ) || ( j >= 92 && j < 96 ) || ( j >= 100 && j < 104 ) || ( j >= 108 && j < 112 ) 
			|| ( j >= 116 && j < 120  ) 	|| ( j >= 124 && j < 128 ))) {
          
		   tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
           } else if ( i == 22 + k && ( (j<2) || (j>=4 && j<6)  || (j>=8 && j<10) || (j>=12 && j<14) || (j>=16 && j<18) || (j>=20 && j<22) || (j>=24 && j<26)
			|| (j>=28 && j<30) || (j>=32 && j<34) || (j>=36 && j<38) || (j>=40 && j<42) || (j>=44 && j<46) || (j>=48 && j<50) || (j>=52 && j<54) 	  
			|| (j>=56 && j<58) || (j>=60 && j<62) || (j>=64 && j<66) || (j>=68 && j<70) || (j>=72 && j<74) || (j>=76 && j<78) || (j>=80 && j<82) 
                	|| (j>=84 && j<86) || (j>=88 && j<90) || (j>=92 && j<94) || (j>=96 && j<98) || (j>=100 && j<102) || (j>=104 && j<106) || (j>=108 && j<110) || 
                	(j>=112 && j<114) || (j>=116 && j<118)     || (j>=120 && j<122) || (j>=124 && j<126)
			)) {
	    tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   } else if (i == 22 + k && ( (j>=2 && j<4) || (j>=6 && j<8) || (j>=10 && j<12) || (j>=14 && j<16) || (j>=18 && j<20) || (j>=22 && j<24) || (j>=26 && j<28)
			|| (j>=30 && j<32) || (j>=34 && j<36) || (j>=38 && j<40) || (j>=42 && j<44) || (j>=46 && j<48) || (j>=50 && j<52) 
			|| (j>=54 && j<56) || (j>=58 && j<60) || (j>=62 && j<64) || (j>=66 && j<68) || (j>=70 && j<72) || (j>=74 && j<76) 
			|| (j>=78 && j<80) || (j>=82 && j<84) || (j>=86 && j<88) || (j>=90 && j<92) || (j>=94 && j<96)
                        || (j>=98 && j<100) || (j>=102 && j<104) || (j>=106 && j<108) || (j>=110 && j<112) || (j>=114 && j<116) 
			|| (j>=118 && j<120) || (j>=122 && j<124) || (j>=126 && j<128) )) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 

	   } else if (i == 23 + k && j % 2 == 0) {
	   
	    tmp_neg = Cudd_Not(var); 
	    tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   
	   } else if (i == 23 + k && j % 2 == 1) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 

	   }
	  
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd_rec[j]);
      bdd_rec[j] = tmp;
    }
  }
    

    bdd9 = Cudd_bddOr(gbm,bdd_rec[0],bdd_rec[1]); 
    Cudd_Ref(bdd1);   
    
    for (k = 2;k<128;k++) {
    bdd9 = Cudd_bddOr(gbm,bdd9,bdd_rec[k]);
    Cudd_Ref(bdd1);   
    }

    bdd = Cudd_bddAnd(gbm,bdd,bdd9);
    Cudd_Ref(bdd);   

     for(j = 0;j<128;j++){ 
       for (i = 24; i < 32; i++) {
          var = Cudd_bddIthVar(gbm,i); 
          if(i%8 ==  0) {
          //tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, var, bdd_rec[j]); 
	  }
	  else if(i == 25+k && j < 64 ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
          }else if(i == 25+k && j >= 64) {
	  tmp = Cudd_bddAnd(gbm, var, bdd_rec[j]); 
          }
	  else if ( (i == 26 + k) && ( ( j < 32 ) || ( j >= 64 && j < 96 ) ) ) {
          tmp_neg = Cudd_Not(var);
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
          } else if ( i == 26 + k && ( ( j >= 32 && j < 64 ) || ( j >= 96 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
	  } else if (i == 27 + k && ( (j<16) || (j>=32 && j<48) || (j>=64 && j<80) || (j>=96 && j<112) ) ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	  } else if (i == 27 + k && ( (j >= 16 && j < 32) || ( j >= 48 && j < 64 ) || ( j >= 80 && j < 96 ) || ( j >= 112 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
          } else if ( i == 28 + k && ( ( j < 8 ) || ( j >= 16 && j < 24) || (j >= 32 && j < 40) || (j>=48 && j<56) || ( j >= 64 && j < 72 ) || 
		    (j >= 80 && j < 88) || (j >= 96 && j < 104) || (j>=112 && j<120) ) ) {
	   tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
           } else if (i == 28 + k && ( ( j >= 8 && j < 16 ) || ( j >= 24 && j < 32 ) || ( j >= 40 && j < 48) || ( j >= 56 && j < 64) 
			|| (j>72 && j<=80) || (j>=88 && j<96) || (j>=104 && j<112) || (j>=120) ) ) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]);  
 	   } else if (i == 29 + k && ( (j < 4) || (j >= 8 && j < 12) || (j >= 16 && j < 20) || (j >= 24 && j < 28) || (j >= 32 && j < 36) || (j >= 40 && j < 44)
			|| (j >= 48 && j < 52)  || (j >= 56 && j < 60)|| (j >= 64 && j < 68) || (j >= 72 && j < 76) || (j >= 80 && j < 84) || (j >= 88 && j < 92) 	
			|| (j >= 96 && j < 100) || (j >= 104 && j < 108) || (j >= 112 && j < 116) || (j >= 120 && j < 124))) {
	   tmp_neg = Cudd_Not(var);
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   
	   } else if (i == 29 + k && ( (j>=4 && j<8) || ( j >= 12 && j < 16 ) || ( j >= 20 && j < 24 ) || ( j >= 28 && j < 32 ) || ( j >= 36 && j < 40 ) 
			|| ( j >= 44 && j < 48 ) || ( j >= 52 && j < 56 ) || ( j >= 60 && j < 64 ) || ( j >= 68 && j < 72 ) || ( j >= 76 && j < 80 ) 	  
		        || ( j >= 84 && j < 88 ) || ( j >= 92 && j < 96 ) || ( j >= 100 && j < 104 ) || ( j >= 108 && j < 112 ) 
			|| ( j >= 116 && j < 120  ) 	|| ( j >= 124 && j < 128 ))) {
          
		   tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
           } else if ( i == 30 + k && ( (j<2) || (j>=4 && j<6)  || (j>=8 && j<10) || (j>=12 && j<14) || (j>=16 && j<18) || (j>=20 && j<22) || (j>=24 && j<26)
			|| (j>=28 && j<30) || (j>=32 && j<34) || (j>=36 && j<38) || (j>=40 && j<42) || (j>=44 && j<46) || (j>=48 && j<50) || (j>=52 && j<54) 	  
			|| (j>=56 && j<58) || (j>=60 && j<62) || (j>=64 && j<66) || (j>=68 && j<70) || (j>=72 && j<74) || (j>=76 && j<78) || (j>=80 && j<82) 
                	|| (j>=84 && j<86) || (j>=88 && j<90) || (j>=92 && j<94) || (j>=96 && j<98) || (j>=100 && j<102) || (j>=104 && j<106) || (j>=108 && j<110) || 
                	(j>=112 && j<114) || (j>=116 && j<118)     || (j>=120 && j<122) || (j>=124 && j<126)
			)) {
	    tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   } else if (i == 30 + k && ( (j>=2 && j<4) || (j>=6 && j<8) || (j>=10 && j<12) || (j>=14 && j<16) || (j>=18 && j<20) || (j>=22 && j<24) || (j>=26 && j<28)
			|| (j>=30 && j<32) || (j>=34 && j<36) || (j>=38 && j<40) || (j>=42 && j<44) || (j>=46 && j<48) || (j>=50 && j<52) 
			|| (j>=54 && j<56) || (j>=58 && j<60) || (j>=62 && j<64) || (j>=66 && j<68) || (j>=70 && j<72) || (j>=74 && j<76) 
			|| (j>=78 && j<80) || (j>=82 && j<84) || (j>=86 && j<88) || (j>=90 && j<92) || (j>=94 && j<96)
                        || (j>=98 && j<100) || (j>=102 && j<104) || (j>=106 && j<108) || (j>=110 && j<112) || (j>=114 && j<116) 
			|| (j>=118 && j<120) || (j>=122 && j<124) || (j>=126 && j<128) )) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 

	   } else if (i == 31 + k && j % 2 == 0) {
	   
	    tmp_neg = Cudd_Not(var); 
	    tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   
	   } else if (i == 31 + k && j % 2 == 1) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 

	   }
	  
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd_rec[j]);
      bdd_rec[j] = tmp;
    }
  }
    
    bdd10 = Cudd_bddOr(gbm,bdd_rec[0],bdd_rec[1]); 
    Cudd_Ref(bdd10);   
    
    for (k = 2;k<128;k++) {
    bdd10 = Cudd_bddOr(gbm,bdd10,bdd_rec[k]);
    Cudd_Ref(bdd10);   
     }
    bdd = Cudd_bddAnd(gbm,bdd,bdd10);
    Cudd_Ref(bdd);   

     for(j = 0;j<128;j++){ 
       for (i = 32; i < 40; i++) {
          var = Cudd_bddIthVar(gbm,i); 
          if(i%8 ==  0) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	  }
	  else if(i == 33+k && j < 64 ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
          }else if(i == 33+k && j >= 64) {
	  tmp = Cudd_bddAnd(gbm, var, bdd_rec[j]); 
          }
	  else if ( (i == 34 + k) && ( ( j < 32 ) || ( j >= 64 && j < 96 ) ) ) {
          tmp_neg = Cudd_Not(var);
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
          } else if ( i == 34 + k && ( ( j >= 32 && j < 64 ) || ( j >= 96 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
	  } else if (i == 35 + k && ( (j<16) || (j>=32 && j<48) || (j>=64 && j<80) || (j>=96 && j<112) ) ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	  } else if (i == 35 + k && ( (j >= 16 && j < 32) || ( j >= 48 && j < 64 ) || ( j >= 80 && j < 96 ) || ( j >= 112 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
          } else if ( i == 36 + k && ( ( j < 8 ) || ( j >= 16 && j < 24) || (j >= 32 && j < 40) || (j>=48 && j<56) || ( j >= 64 && j < 72 ) || 
		    (j >= 80 && j < 88) || (j >= 96 && j < 104) || (j>=112 && j<120) ) ) {
	   tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
           } else if (i == 36 + k && ( ( j >= 8 && j < 16 ) || ( j >= 24 && j < 32 ) || ( j >= 40 && j < 48) || ( j >= 56 && j < 64) 
			|| (j>72 && j<=80) || (j>=88 && j<96) || (j>=104 && j<112) || (j>=120) ) ) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]);  
 	   } else if (i == 37 + k && ( (j < 4) || (j >= 8 && j < 12) || (j >= 16 && j < 20) || (j >= 24 && j < 28) || (j >= 32 && j < 36) || (j >= 40 && j < 44)
			|| (j >= 48 && j < 52)  || (j >= 56 && j < 60)|| (j >= 64 && j < 68) || (j >= 72 && j < 76) || (j >= 80 && j < 84) || (j >= 88 && j < 92) 	
			|| (j >= 96 && j < 100) || (j >= 104 && j < 108) || (j >= 112 && j < 116) || (j >= 120 && j < 124))) {
	   tmp_neg = Cudd_Not(var);
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   
	   } else if (i == 37 + k && ( (j>=4 && j<8) || ( j >= 12 && j < 16 ) || ( j >= 20 && j < 24 ) || ( j >= 28 && j < 32 ) || ( j >= 36 && j < 40 ) 
			|| ( j >= 44 && j < 48 ) || ( j >= 52 && j < 56 ) || ( j >= 60 && j < 64 ) || ( j >= 68 && j < 72 ) || ( j >= 76 && j < 80 ) 	  
		        || ( j >= 84 && j < 88 ) || ( j >= 92 && j < 96 ) || ( j >= 100 && j < 104 ) || ( j >= 108 && j < 112 ) 
			|| ( j >= 116 && j < 120  ) 	|| ( j >= 124 && j < 128 ))) {
          
		   tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
           } else if ( i == 38 + k && ( (j<2) || (j>=4 && j<6)  || (j>=8 && j<10) || (j>=12 && j<14) || (j>=16 && j<18) || (j>=20 && j<22) || (j>=24 && j<26)
			|| (j>=28 && j<30) || (j>=32 && j<34) || (j>=36 && j<38) || (j>=40 && j<42) || (j>=44 && j<46) || (j>=48 && j<50) || (j>=52 && j<54) 	  
			|| (j>=56 && j<58) || (j>=60 && j<62) || (j>=64 && j<66) || (j>=68 && j<70) || (j>=72 && j<74) || (j>=76 && j<78) || (j>=80 && j<82) 
                	|| (j>=84 && j<86) || (j>=88 && j<90) || (j>=92 && j<94) || (j>=96 && j<98) || (j>=100 && j<102) || (j>=104 && j<106) || (j>=108 && j<110) || 
                	(j>=112 && j<114) || (j>=116 && j<118)     || (j>=120 && j<122) || (j>=124 && j<126)
			)) {
	    tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   } else if (i == 38 + k && ( (j>=2 && j<4) || (j>=6 && j<8) || (j>=10 && j<12) || (j>=14 && j<16) || (j>=18 && j<20) || (j>=22 && j<24) || (j>=26 && j<28)
			|| (j>=30 && j<32) || (j>=34 && j<36) || (j>=38 && j<40) || (j>=42 && j<44) || (j>=46 && j<48) || (j>=50 && j<52) 
			|| (j>=54 && j<56) || (j>=58 && j<60) || (j>=62 && j<64) || (j>=66 && j<68) || (j>=70 && j<72) || (j>=74 && j<76) 
			|| (j>=78 && j<80) || (j>=82 && j<84) || (j>=86 && j<88) || (j>=90 && j<92) || (j>=94 && j<96)
                        || (j>=98 && j<100) || (j>=102 && j<104) || (j>=106 && j<108) || (j>=110 && j<112) || (j>=114 && j<116) 
			|| (j>=118 && j<120) || (j>=122 && j<124) || (j>=126 && j<128) )) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 

	   } else if (i == 39 + k && j % 2 == 0) {
	   
	    tmp_neg = Cudd_Not(var); 
	    tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   
	   } else if (i == 39 + k && j % 2 == 1) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 

	   }
	  
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd_rec[j]);
      bdd_rec[j] = tmp;
    }
  }
    bdd11 = Cudd_bddOr(gbm,bdd_rec[0],bdd_rec[1]); 
    Cudd_Ref(bdd11);   
    
    for (k = 2;k<128;k++) {
    bdd11 = Cudd_bddOr(gbm,bdd11,bdd_rec[k]);
    Cudd_Ref(bdd11);   
     }
    bdd = Cudd_bddAnd(gbm,bdd,bdd11);
    Cudd_Ref(bdd);   

    for (i = 40; i < 48; i++) {
     var = Cudd_bddIthVar(gbm,i); 
     
      tmp_neg = Cudd_Not(var); 
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd2); 
    
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd2);
      bdd2 = tmp;
    }
   
    bdd = Cudd_bddAnd(gbm,bdd,bdd2);
    Cudd_Ref(bdd);
    
    for (i = 48; i < 56; i++) {
     var = Cudd_bddIthVar(gbm,i); 
     if(i != 53){
      tmp_neg = Cudd_Not(var); 
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd3);
     }else{
      tmp = Cudd_bddAnd(gbm, var, bdd3); 
     }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd3);
      bdd3 = tmp;
    }
    
    bdd = Cudd_bddAnd(gbm,bdd,bdd3);
    Cudd_Ref(bdd);
    
    for (i = 56; i < 64; i++) {
     var = Cudd_bddIthVar(gbm,i); 
     if(i != 57 && i!= 60 && i != 61 && i != 63){
      tmp_neg = Cudd_Not(var);
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd4); 
     }else{
      tmp = Cudd_bddAnd(gbm, var, bdd4); 
     }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd4);
      bdd4 = tmp;
    }
    
    bdd = Cudd_bddAnd(gbm,bdd,bdd4);
    Cudd_Ref(bdd);
    
    for (i = 64; i < 72; i++) {
     var = Cudd_bddIthVar(gbm,i); 
     if(i != 65 && i!= 67 && i != 71 ){
      tmp_neg = Cudd_Not(var); 
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd5);
     }else{
      tmp = Cudd_bddAnd(gbm, var, bdd5); 
     }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd5);
      bdd5 = tmp;
    }

    bdd = Cudd_bddAnd(gbm,bdd,bdd5);
    Cudd_Ref(bdd);
    
    for (i = 72; i < 80; i++) {
     var = Cudd_bddIthVar(gbm,i); 
     if(i != 73 && i!= 75 && i != 77 ){
      tmp_neg = Cudd_Not(var); 
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd6); 
     }else{
      tmp = Cudd_bddAnd(gbm, var, bdd6);
     }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd6);
      bdd6 = tmp;
    }
    
     bdd = Cudd_bddAnd(gbm,bdd,bdd6);
     Cudd_Ref(bdd);
    
    for (i = 80; i < 88; i++) {
     var = Cudd_bddIthVar(gbm,i); 
     if(i != 81 && i!= 83 && i != 85 ){
      tmp_neg = Cudd_Not(var);
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd7); 
     }else{
      tmp = Cudd_bddAnd(gbm, var, bdd7); 
     }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd7);
      bdd7 = tmp;
    }
     
    bdd = Cudd_bddAnd(gbm,bdd,bdd7);
    Cudd_Ref(bdd);
    
for (i = 88; i < 96; i++) {
     var = Cudd_bddIthVar(gbm,i); 
     if(i != 93){
      tmp_neg = Cudd_Not(var); 
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd8); 
     }else{
      tmp = Cudd_bddAnd(gbm, var, bdd8); 
     }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd8);
      bdd8 = tmp;
    }
     bdd = Cudd_bddAnd(gbm,bdd,bdd8);
*/
    DdNode* bdd71;
   
    bdd71 = Cudd_ReadOne(gbm); 
     Cudd_Ref(bdd71); 

     for (i = 16; i < 18; i++) {  
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd71); 
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd71);
      bdd71 = tmp;
    }
    
    
    bdd = Cudd_bddAnd(gbm,bdd,bdd71);
    Cudd_Ref(bdd);

return bdd;

    

}

//FUNZIONI CONNACK


DdNode* scrivi_bdd_zero1 (DdManager *gbm, DdNode *bdd, DdNode * var) 
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




DdNode* scrivi_bdd_uno1 (DdManager *gbm, DdNode *bdd, DdNode * var) 
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
    /*     
     for (i = 16; i < 24; i++) {
     var = Cudd_bddIthVar(gbm,i);
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
  */ 
    DdNode* bdd71;
   
    bdd71 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd71); /*Increases the reference count of a node*/

     for (i = 16; i < 18; i++) {  
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd71); 
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd71);
      bdd71 = tmp;
    }
    
    
    bdd = Cudd_bddAnd(gbm,bdd,bdd71);
    Cudd_Ref(bdd);


   return bdd; 
}	



DdNode* scrivi_bdd_due1 (DdManager *gbm, DdNode *bdd, DdNode * var) 
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
  /* 
     for (i = 16; i < 24; i++) {
     var = Cudd_bddIthVar(gbm,i); 
     if (i != 23) {
      tmp_neg = Cudd_Not(var); 
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd); 
     } else {
      tmp = Cudd_bddAnd(gbm,var,bdd); 
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
*/
    DdNode* bdd71;
   
    bdd71 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd71); /*Increases the reference count of a node*/

     for (i = 16; i < 18; i++) {  
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd71); 
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd71);
      bdd71 = tmp;
    }
    
    
    bdd = Cudd_bddAnd(gbm,bdd,bdd71);
    Cudd_Ref(bdd);


    
    return bdd;
    

}





//FUNZIONI PUBLISH

DdNode* scrivi_bdd_zero2 (DdManager *gbm, DdNode *bdd, DdNode * var) 
{
     DdNode* bdd_rec[128];
     DdNode *bdd1, *bdd2, *bdd3, *bdd4, *bdd5, *bdd6, *bdd7, *bdd8, *bdd9,*tmp,*tmp_neg, *bdd10, *bdd11;
     bdd = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd); /*Increases the reference count of a node*/
     int i; 
     
     for(i = 0; i < 128; i++){
     bdd_rec[i] = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd_rec[i]); /*Increases the reference count of a node*/
     } 
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
     bdd6 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd6); /*Increases the reference count of a node*/
     bdd7 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd7); /*Increases the reference count of a node*/
     bdd8 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd8); /*Increases the reference count of a node*/
     bdd9 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd9); /*Increases the reference count of a node*/
     bdd10 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd10); /*Increases the reference count of a node*/
     bdd11 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd11); /*Increases the reference count of a node*/
   
    for (i = 0; i < 8; i++) {
      var = Cudd_bddIthVar(gbm,i); 
     if( (i != 2) && (i != 3) ) {
      tmp_neg = Cudd_Not(var); /*Perform NOT Boolean operation*/
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd); /*Perform AND Boolean operation*/
      }else{
      tmp = Cudd_bddAnd(gbm,var,bdd); /*Perform AND Boolean operation*/
printf("ciao\n");
      }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd);
      bdd = tmp;
 
   
    }
    
    Cudd_Ref(bdd);
 
     for (i = 0; i < 8; i++) {
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
     if(i != 2 && i != 3 && i != 7) {
      tmp_neg = Cudd_Not(var); /*Perform NOT Boolean operation*/
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd1); /*Perform AND Boolean operation*/
      }else{
      tmp = Cudd_bddAnd(gbm,var,bdd1); /*Perform AND Boolean operation*/
     }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd1);
      bdd1 = tmp;
    }

    
    bdd = Cudd_bddOr(gbm,bdd,bdd1); 
    Cudd_Ref(bdd);   
    
     for (i = 0; i < 8; i++) {
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
     if(i != 2 && i != 3 && i != 6) {
      tmp_neg = Cudd_Not(var); /*Perform NOT Boolean operation*/
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd2); /*Perform AND Boolean operation*/
      }else{
      tmp = Cudd_bddAnd(gbm,var,bdd2); /*Perform AND Boolean operation*/
     }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd2);
      bdd2 = tmp;
    }
    bdd = Cudd_bddOr(gbm,bdd,bdd2); 
    Cudd_Ref(bdd);   

     for (i = 0; i < 8; i++) {
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
     if(i != 2 && i != 3 && i != 6 && i != 7) {
      tmp_neg = Cudd_Not(var); /*Perform NOT Boolean operation*/
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd3); /*Perform AND Boolean operation*/
      }else{
      tmp = Cudd_bddAnd(gbm,var,bdd3); /*Perform AND Boolean operation*/
     }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd3);
      bdd3 = tmp;
    }
  
    bdd = Cudd_bddOr(gbm,bdd,bdd3); 
    Cudd_Ref(bdd);   
     
    for (i = 0; i < 8; i++) {
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
     if(i != 2 && i != 3 && i != 5) {
      tmp_neg = Cudd_Not(var); /*Perform NOT Boolean operation*/
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd4); /*Perform AND Boolean operation*/
      }else{
      tmp = Cudd_bddAnd(gbm,var,bdd4); /*Perform AND Boolean operation*/
     }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd4);
      bdd4 = tmp;
    }
    
    bdd = Cudd_bddOr(gbm,bdd,bdd4); 
    Cudd_Ref(bdd);   

    for (i = 0; i < 8; i++) {
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
     if(i != 2 && i != 3 && i != 5 & i != 7) {
      tmp_neg = Cudd_Not(var); /*Perform NOT Boolean operation*/
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd5); /*Perform AND Boolean operation*/
      }else{
      tmp = Cudd_bddAnd(gbm,var,bdd5); /*Perform AND Boolean operation*/
     }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd5);
      bdd5 = tmp;
    }
    bdd = Cudd_bddOr(gbm,bdd,bdd5); 
    Cudd_Ref(bdd);   
    
    for (i = 0; i < 8; i++) {
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
     if(i != 2 && i != 3 && i != 4) {
      tmp_neg = Cudd_Not(var); /*Perform NOT Boolean operation*/
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd6); /*Perform AND Boolean operation*/
      }else{
      tmp = Cudd_bddAnd(gbm,var,bdd6); /*Perform AND Boolean operation*/
     }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd6);
      bdd6 = tmp;
    }
    bdd = Cudd_bddOr(gbm,bdd,bdd6); 
    Cudd_Ref(bdd);   
    
    for (i = 0; i < 8; i++) {
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
     if(i != 2 && i != 3 && i != 4 && i != 7) {
      tmp_neg = Cudd_Not(var); /*Perform NOT Boolean operation*/
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd7); /*Perform AND Boolean operation*/
      }else{
      tmp = Cudd_bddAnd(gbm,var,bdd7); /*Perform AND Boolean operation*/
     }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd7);
      bdd7 = tmp;
    }
    bdd = Cudd_bddOr(gbm,bdd,bdd7); 
    Cudd_Ref(bdd);   
    
    for (i = 0; i < 8; i++) {
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
     if(i != 2 && i != 3 && i != 4 && i != 6) {
      tmp_neg = Cudd_Not(var); /*Perform NOT Boolean operation*/
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd8); /*Perform AND Boolean operation*/
      }else{
      tmp = Cudd_bddAnd(gbm,var,bdd8); /*Perform AND Boolean operation*/
     }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd8);
      bdd8 = tmp;
    }
    bdd = Cudd_bddOr(gbm,bdd,bdd8); 
    Cudd_Ref(bdd);   
    
    for (i = 0; i < 8; i++) {
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
     if(i != 2 && i != 3 && i != 4 && i != 6 && i != 7) {
      tmp_neg = Cudd_Not(var); /*Perform NOT Boolean operation*/
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd9); /*Perform AND Boolean operation*/
      }else{
      tmp = Cudd_bddAnd(gbm,var,bdd9); /*Perform AND Boolean operation*/
     }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd9);
      bdd9 = tmp;
    }
    bdd = Cudd_bddOr(gbm,bdd,bdd9); 
    Cudd_Ref(bdd);   
    
    for (i = 0; i < 8; i++) {
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
     if(i != 2 && i != 3 && i != 4 && i != 5) {
      tmp_neg = Cudd_Not(var); /*Perform NOT Boolean operation*/
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd10); /*Perform AND Boolean operation*/
      }else{
      tmp = Cudd_bddAnd(gbm,var,bdd10); /*Perform AND Boolean operation*/
     }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd10);
      bdd10 = tmp;
    }
    bdd = Cudd_bddOr(gbm,bdd,bdd10); 
    Cudd_Ref(bdd);   
    
    for (i = 0; i < 8; i++) {
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
     if(i != 2 && i != 3 && i != 4 && i != 5 && i != 6) {
      tmp_neg = Cudd_Not(var); /*Perform NOT Boolean operation*/
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd11); /*Perform AND Boolean operation*/
      }else{
      tmp = Cudd_bddAnd(gbm,var,bdd11); /*Perform AND Boolean operation*/
     }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd11);
      bdd11 = tmp;
    }
    bdd = Cudd_bddOr(gbm,bdd,bdd11); 
    Cudd_Ref(bdd);   


    DdNode* bdd71;
   
    bdd71 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd71); /*Increases the reference count of a node*/

     for (i = 16; i < 18; i++) {  
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd71); 
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd71);
      bdd71 = tmp;
    }
    
    
    bdd = Cudd_bddAnd(gbm,bdd,bdd71);
    Cudd_Ref(bdd);

return bdd;

}




DdNode* scrivi_bdd_uno2 (DdManager *gbm, DdNode *bdd, DdNode * var) 
{
 
 DdNode* bdd_rec[128];
 DdNode *bdd1, *bdd2, *bdd3, *bdd4, *bdd5, *bdd6, *bdd7, *bdd8, *bdd9,*tmp,*tmp_neg;
     bdd = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd); /*Increases the reference count of a node*/
     int i; 
     
     for(i = 0; i < 128; i++){
     bdd_rec[i] = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd_rec[i]); /*Increases the reference count of a node*/
     } 
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
     bdd6 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd6); /*Increases the reference count of a node*/
     bdd7 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd7); /*Increases the reference count of a node*/
     bdd8 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd8); /*Increases the reference count of a node*/
     bdd9 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd9); /*Increases the reference count of a node*/
   
    int j;int k = 0;
     for(j = 0;j<128;j++){ 
       for (i = 8; i < 16; i++) {
          var = Cudd_bddIthVar(gbm,i); 
          if(i%8 ==  0) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	  }
	  else if(i == 9+k && j < 64 ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
          }else if(i == 9+k && j >= 64) {
	  tmp = Cudd_bddAnd(gbm, var, bdd_rec[j]); 
          }
	  else if ( (i == 10 + k) && ( ( j < 32 ) || ( j >= 64 && j < 96 ) ) ) {
          tmp_neg = Cudd_Not(var);
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
          } else if ( i == 10 + k && ( ( j >= 32 && j < 64 ) || ( j >= 96 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
	  } else if (i == 11 + k && ( (j<16) || (j>=32 && j<48) || (j>=64 && j<80) || (j>=96 && j<112) ) ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	  } else if (i == 11 + k && ( (j >= 16 && j < 32) || ( j >= 48 && j < 64 ) || ( j >= 80 && j < 96 ) || ( j >= 112 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
          } else if ( i == 12 + k && ( ( j < 8 ) || ( j >= 16 && j < 24) || (j >= 32 && j < 40) || (j>=48 && j<56) || ( j >= 64 && j < 72 ) || 
		    (j >= 80 && j < 88) || (j >= 96 && j < 104) || (j>=112 && j<120) ) ) {
	   tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
           } else if (i == 12 + k && ( ( j >= 8 && j < 16 ) || ( j >= 24 && j < 32 ) || ( j >= 40 && j < 48) || ( j >= 56 && j < 64) 
			|| (j>72 && j<=80) || (j>=88 && j<96) || (j>=104 && j<112) || (j>=120) ) ) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]);  
 	   } else if (i == 13 + k && ( (j < 4) || (j >= 8 && j < 12) || (j >= 16 && j < 20) || (j >= 24 && j < 28) || (j >= 32 && j < 36) || (j >= 40 && j < 44)
			|| (j >= 48 && j < 52)  || (j >= 56 && j < 60)|| (j >= 64 && j < 68) || (j >= 72 && j < 76) || (j >= 80 && j < 84) || (j >= 88 && j < 92) 	
			|| (j >= 96 && j < 100) || (j >= 104 && j < 108) || (j >= 112 && j < 116) || (j >= 120 && j < 124))) {
	   tmp_neg = Cudd_Not(var);
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   
	   } else if (i == 13 + k && ( (j>=4 && j<8) || ( j >= 12 && j < 16 ) || ( j >= 20 && j < 24 ) || ( j >= 28 && j < 32 ) || ( j >= 36 && j < 40 ) 
			|| ( j >= 44 && j < 48 ) || ( j >= 52 && j < 56 ) || ( j >= 60 && j < 64 ) || ( j >= 68 && j < 72 ) || ( j >= 76 && j < 80 ) 	  
		        || ( j >= 84 && j < 88 ) || ( j >= 92 && j < 96 ) || ( j >= 100 && j < 104 ) || ( j >= 108 && j < 112 ) 
			|| ( j >= 116 && j < 120  ) 	|| ( j >= 124 && j < 128 ))) {
          
		   tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
           } else if ( i == 14 + k && ( (j<2) || (j>=4 && j<6)  || (j>=8 && j<10) || (j>=12 && j<14) || (j>=16 && j<18) || (j>=20 && j<22) || (j>=24 && j<26)
			|| (j>=28 && j<30) || (j>=32 && j<34) || (j>=36 && j<38) || (j>=40 && j<42) || (j>=44 && j<46) || (j>=48 && j<50) || (j>=52 && j<54) 	  
			|| (j>=56 && j<58) || (j>=60 && j<62) || (j>=64 && j<66) || (j>=68 && j<70) || (j>=72 && j<74) || (j>=76 && j<78) || (j>=80 && j<82) 
                	|| (j>=84 && j<86) || (j>=88 && j<90) || (j>=92 && j<94) || (j>=96 && j<98) || (j>=100 && j<102) || (j>=104 && j<106) || (j>=108 && j<110) || 
                	(j>=112 && j<114) || (j>=116 && j<118)     || (j>=120 && j<122) || (j>=124 && j<126)
			)) {
	    tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   } else if (i == 14 + k && ( (j>=2 && j<4) || (j>=6 && j<8) || (j>=10 && j<12) || (j>=14 && j<16) || (j>=18 && j<20) || (j>=22 && j<24) || (j>=26 && j<28)
			|| (j>=30 && j<32) || (j>=34 && j<36) || (j>=38 && j<40) || (j>=42 && j<44) || (j>=46 && j<48) || (j>=50 && j<52) 
			|| (j>=54 && j<56) || (j>=58 && j<60) || (j>=62 && j<64) || (j>=66 && j<68) || (j>=70 && j<72) || (j>=74 && j<76) 
			|| (j>=78 && j<80) || (j>=82 && j<84) || (j>=86 && j<88) || (j>=90 && j<92) || (j>=94 && j<96)
                        || (j>=98 && j<100) || (j>=102 && j<104) || (j>=106 && j<108) || (j>=110 && j<112) || (j>=114 && j<116) 
			|| (j>=118 && j<120) || (j>=122 && j<124) || (j>=126 && j<128) )) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 

	   } else if (i == 15 + k && j % 2 == 0) {
	   
	    tmp_neg = Cudd_Not(var); 
	    tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   
	   } else if (i == 15 + k && j % 2 == 1) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 

	   }
	  
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd_rec[j]);
      bdd_rec[j] = tmp;
    }
  }
    
    bdd1 = Cudd_bddOr(gbm,bdd_rec[0],bdd_rec[1]); 
    Cudd_Ref(bdd1);   
    
    for (k = 2;k<128;k++) {
    bdd1 = Cudd_bddOr(gbm,bdd1,bdd_rec[k]);
    Cudd_Ref(bdd1);   
     }
    bdd = Cudd_bddAnd(gbm,bdd,bdd1);
    Cudd_Ref(bdd);   


    
    DdNode* bdd71;
   
    bdd71 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd71); /*Increases the reference count of a node*/

     for (i = 16; i < 18; i++) {  
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd71); 
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd71);
      bdd71 = tmp;
    }
    
    
    bdd = Cudd_bddAnd(gbm,bdd,bdd71);
    Cudd_Ref(bdd);

   return bdd;


}	



DdNode* scrivi_bdd_due2 (DdManager *gbm, DdNode *bdd, DdNode * var) {
 DdNode* bdd_rec[128];
 DdNode *bdd1, *bdd2, *bdd3, *bdd4, *bdd5, *bdd6, *bdd7, *bdd8, *bdd9,*bdd10,*tmp,*tmp_neg;
     bdd = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd); /*Increases the reference count of a node*/
     int i; 
     
     for(i = 0; i < 128; i++){
     bdd_rec[i] = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd_rec[i]); /*Increases the reference count of a node*/
     } 
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
     bdd6 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd6); /*Increases the reference count of a node*/
     bdd7 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd7); /*Increases the reference count of a node*/
     bdd8 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd8); /*Increases the reference count of a node*/
     bdd9 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd9); /*Increases the reference count of a node*/
   

    int j;int k = 0;
     for(j = 0;j<128;j++){ 
       for (i = 8; i < 16; i++) {
          var = Cudd_bddIthVar(gbm,i); 
          if(i%8 ==  0) {
          //tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, var, bdd_rec[j]); 
	  }
	  else if(i == 9+k && j < 64 ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
          }else if(i == 9+k && j >= 64) {
	  tmp = Cudd_bddAnd(gbm, var, bdd_rec[j]); 
          }
	  else if ( (i == 10 + k) && ( ( j < 32 ) || ( j >= 64 && j < 96 ) ) ) {
          tmp_neg = Cudd_Not(var);
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
          } else if ( i == 10 + k && ( ( j >= 32 && j < 64 ) || ( j >= 96 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
	  } else if (i == 11 + k && ( (j<16) || (j>=32 && j<48) || (j>=64 && j<80) || (j>=96 && j<112) ) ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	  } else if (i == 11 + k && ( (j >= 16 && j < 32) || ( j >= 48 && j < 64 ) || ( j >= 80 && j < 96 ) || ( j >= 112 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
          } else if ( i == 12 + k && ( ( j < 8 ) || ( j >= 16 && j < 24) || (j >= 32 && j < 40) || (j>=48 && j<56) || ( j >= 64 && j < 72 ) || 
		    (j >= 80 && j < 88) || (j >= 96 && j < 104) || (j>=112 && j<120) ) ) {
	   tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
           } else if (i == 12 + k && ( ( j >= 8 && j < 16 ) || ( j >= 24 && j < 32 ) || ( j >= 40 && j < 48) || ( j >= 56 && j < 64) 
			|| (j>72 && j<=80) || (j>=88 && j<96) || (j>=104 && j<112) || (j>=120) ) ) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]);  
 	   } else if (i == 13 + k && ( (j < 4) || (j >= 8 && j < 12) || (j >= 16 && j < 20) || (j >= 24 && j < 28) || (j >= 32 && j < 36) || (j >= 40 && j < 44)
			|| (j >= 48 && j < 52)  || (j >= 56 && j < 60)|| (j >= 64 && j < 68) || (j >= 72 && j < 76) || (j >= 80 && j < 84) || (j >= 88 && j < 92) 	
			|| (j >= 96 && j < 100) || (j >= 104 && j < 108) || (j >= 112 && j < 116) || (j >= 120 && j < 124))) {
	   tmp_neg = Cudd_Not(var);
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   
	   } else if (i == 13 + k && ( (j>=4 && j<8) || ( j >= 12 && j < 16 ) || ( j >= 20 && j < 24 ) || ( j >= 28 && j < 32 ) || ( j >= 36 && j < 40 ) 
			|| ( j >= 44 && j < 48 ) || ( j >= 52 && j < 56 ) || ( j >= 60 && j < 64 ) || ( j >= 68 && j < 72 ) || ( j >= 76 && j < 80 ) 	  
		        || ( j >= 84 && j < 88 ) || ( j >= 92 && j < 96 ) || ( j >= 100 && j < 104 ) || ( j >= 108 && j < 112 ) 
			|| ( j >= 116 && j < 120  ) 	|| ( j >= 124 && j < 128 ))) {
          
		   tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
           } else if ( i == 14 + k && ( (j<2) || (j>=4 && j<6)  || (j>=8 && j<10) || (j>=12 && j<14) || (j>=16 && j<18) || (j>=20 && j<22) || (j>=24 && j<26)
			|| (j>=28 && j<30) || (j>=32 && j<34) || (j>=36 && j<38) || (j>=40 && j<42) || (j>=44 && j<46) || (j>=48 && j<50) || (j>=52 && j<54) 	  
			|| (j>=56 && j<58) || (j>=60 && j<62) || (j>=64 && j<66) || (j>=68 && j<70) || (j>=72 && j<74) || (j>=76 && j<78) || (j>=80 && j<82) 
                	|| (j>=84 && j<86) || (j>=88 && j<90) || (j>=92 && j<94) || (j>=96 && j<98) || (j>=100 && j<102) || (j>=104 && j<106) || (j>=108 && j<110) || 
                	(j>=112 && j<114) || (j>=116 && j<118)     || (j>=120 && j<122) || (j>=124 && j<126)
			)) {
	    tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   } else if (i == 14 + k && ( (j>=2 && j<4) || (j>=6 && j<8) || (j>=10 && j<12) || (j>=14 && j<16) || (j>=18 && j<20) || (j>=22 && j<24) || (j>=26 && j<28)
			|| (j>=30 && j<32) || (j>=34 && j<36) || (j>=38 && j<40) || (j>=42 && j<44) || (j>=46 && j<48) || (j>=50 && j<52) 
			|| (j>=54 && j<56) || (j>=58 && j<60) || (j>=62 && j<64) || (j>=66 && j<68) || (j>=70 && j<72) || (j>=74 && j<76) 
			|| (j>=78 && j<80) || (j>=82 && j<84) || (j>=86 && j<88) || (j>=90 && j<92) || (j>=94 && j<96)
                        || (j>=98 && j<100) || (j>=102 && j<104) || (j>=106 && j<108) || (j>=110 && j<112) || (j>=114 && j<116) 
			|| (j>=118 && j<120) || (j>=122 && j<124) || (j>=126 && j<128) )) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 

	   } else if (i == 15 + k && j % 2 == 0) {
	   
	    tmp_neg = Cudd_Not(var); 
	    tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   
	   } else if (i == 15 + k && j % 2 == 1) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 

	   }
	  
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd_rec[j]);
      bdd_rec[j] = tmp;
    }
  }
    
    bdd1 = Cudd_bddOr(gbm,bdd_rec[0],bdd_rec[1]); 
    Cudd_Ref(bdd1);   
    
    for (k = 2;k<128;k++) {
    bdd1 = Cudd_bddOr(gbm,bdd1,bdd_rec[k]);
    Cudd_Ref(bdd1);   
     }
    //bdd = Cudd_bddAnd(gbm,bdd,bdd1);
    //Cudd_Ref(bdd);   


     for(j = 0;j<128;j++){ 
       for (i = 16; i < 24; i++) {
          var = Cudd_bddIthVar(gbm,i); 
          if(i%8 ==  0) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	  }
	  else if(i == 17+k && j < 64 ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
          }else if(i == 17+k && j >= 64) {
	  tmp = Cudd_bddAnd(gbm, var, bdd_rec[j]); 
          }
	  else if ( (i == 18 + k) && ( ( j < 32 ) || ( j >= 64 && j < 96 ) ) ) {
          tmp_neg = Cudd_Not(var);
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
          } else if ( i == 18 + k && ( ( j >= 32 && j < 64 ) || ( j >= 96 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
	  } else if (i == 19 + k && ( (j<16) || (j>=32 && j<48) || (j>=64 && j<80) || (j>=96 && j<112) ) ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	  } else if (i == 19 + k && ( (j >= 16 && j < 32) || ( j >= 48 && j < 64 ) || ( j >= 80 && j < 96 ) || ( j >= 112 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
          } else if ( i == 20 + k && ( ( j < 8 ) || ( j >= 16 && j < 24) || (j >= 32 && j < 40) || (j>=48 && j<56) || ( j >= 64 && j < 72 ) || 
		    (j >= 80 && j < 88) || (j >= 96 && j < 104) || (j>=112 && j<120) ) ) {
	   tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
           } else if (i == 20 + k && ( ( j >= 8 && j < 16 ) || ( j >= 24 && j < 32 ) || ( j >= 40 && j < 48) || ( j >= 56 && j < 64) 
			|| (j>72 && j<=80) || (j>=88 && j<96) || (j>=104 && j<112) || (j>=120) ) ) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]);  
 	   } else if (i == 21 + k && ( (j < 4) || (j >= 8 && j < 12) || (j >= 16 && j < 20) || (j >= 24 && j < 28) || (j >= 32 && j < 36) || (j >= 40 && j < 44)
			|| (j >= 48 && j < 52)  || (j >= 56 && j < 60)|| (j >= 64 && j < 68) || (j >= 72 && j < 76) || (j >= 80 && j < 84) || (j >= 88 && j < 92) 	
			|| (j >= 96 && j < 100) || (j >= 104 && j < 108) || (j >= 112 && j < 116) || (j >= 120 && j < 124))) {
	   tmp_neg = Cudd_Not(var);
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   
	   } else if (i == 21 + k && ( (j>=4 && j<8) || ( j >= 12 && j < 16 ) || ( j >= 20 && j < 24 ) || ( j >= 28 && j < 32 ) || ( j >= 36 && j < 40 ) 
			|| ( j >= 44 && j < 48 ) || ( j >= 52 && j < 56 ) || ( j >= 60 && j < 64 ) || ( j >= 68 && j < 72 ) || ( j >= 76 && j < 80 ) 	  
		        || ( j >= 84 && j < 88 ) || ( j >= 92 && j < 96 ) || ( j >= 100 && j < 104 ) || ( j >= 108 && j < 112 ) 
			|| ( j >= 116 && j < 120  ) 	|| ( j >= 124 && j < 128 ))) {
          
		   tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
           } else if ( i == 22 + k && ( (j<2) || (j>=4 && j<6)  || (j>=8 && j<10) || (j>=12 && j<14) || (j>=16 && j<18) || (j>=20 && j<22) || (j>=24 && j<26)
			|| (j>=28 && j<30) || (j>=32 && j<34) || (j>=36 && j<38) || (j>=40 && j<42) || (j>=44 && j<46) || (j>=48 && j<50) || (j>=52 && j<54) 	  
			|| (j>=56 && j<58) || (j>=60 && j<62) || (j>=64 && j<66) || (j>=68 && j<70) || (j>=72 && j<74) || (j>=76 && j<78) || (j>=80 && j<82) 
                	|| (j>=84 && j<86) || (j>=88 && j<90) || (j>=92 && j<94) || (j>=96 && j<98) || (j>=100 && j<102) || (j>=104 && j<106) || (j>=108 && j<110) || 
                	(j>=112 && j<114) || (j>=116 && j<118)     || (j>=120 && j<122) || (j>=124 && j<126)
			)) {
	    tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   } else if (i == 22 + k && ( (j>=2 && j<4) || (j>=6 && j<8) || (j>=10 && j<12) || (j>=14 && j<16) || (j>=18 && j<20) || (j>=22 && j<24) || (j>=26 && j<28)
			|| (j>=30 && j<32) || (j>=34 && j<36) || (j>=38 && j<40) || (j>=42 && j<44) || (j>=46 && j<48) || (j>=50 && j<52) 
			|| (j>=54 && j<56) || (j>=58 && j<60) || (j>=62 && j<64) || (j>=66 && j<68) || (j>=70 && j<72) || (j>=74 && j<76) 
			|| (j>=78 && j<80) || (j>=82 && j<84) || (j>=86 && j<88) || (j>=90 && j<92) || (j>=94 && j<96)
                        || (j>=98 && j<100) || (j>=102 && j<104) || (j>=106 && j<108) || (j>=110 && j<112) || (j>=114 && j<116) 
			|| (j>=118 && j<120) || (j>=122 && j<124) || (j>=126 && j<128) )) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 

	   } else if (i == 23 + k && j % 2 == 0) {
	   
	    tmp_neg = Cudd_Not(var); 
	    tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   
	   } else if (i == 23 + k && j % 2 == 1) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 

	   }
	  
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd_rec[j]);
      bdd_rec[j] = tmp;
    }
  }
    

    bdd9 = Cudd_bddOr(gbm,bdd_rec[0],bdd_rec[1]); 
    Cudd_Ref(bdd1);   
    
    for (k = 2;k<128;k++) {
    bdd9 = Cudd_bddOr(gbm,bdd9,bdd_rec[k]);
    Cudd_Ref(bdd1);   
    }

    bdd = Cudd_bddAnd(gbm,bdd1,bdd9);
    Cudd_Ref(bdd);   


    DdNode* bdd71;
   
    bdd71 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd71); /*Increases the reference count of a node*/

     for (i = 16; i < 18; i++) {  
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd71); 
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd71);
      bdd71 = tmp;
    }
    
    
    bdd = Cudd_bddAnd(gbm,bdd,bdd71);
    Cudd_Ref(bdd);

return bdd;

}	



DdNode* scrivi_bdd_tre2 (DdManager *gbm, DdNode *bdd, DdNode * var) {

 DdNode* bdd_rec[128];
 DdNode *bdd1, *bdd2, *bdd3, *bdd4, *bdd5, *bdd6, *bdd7, *bdd8, *bdd9,*bdd10,*tmp,*tmp_neg,*bdd11;
     bdd = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd); /*Increases the reference count of a node*/
     int i; 
     
     for(i = 0; i < 128; i++){
     bdd_rec[i] = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd_rec[i]); /*Increases the reference count of a node*/
     } 
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
     bdd6 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd6); /*Increases the reference count of a node*/
     bdd7 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd7); /*Increases the reference count of a node*/
     bdd8 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd8); /*Increases the reference count of a node*/
     bdd9 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd9); /*Increases the reference count of a node*/
   

    int j;int k = 0;
     for(j = 0;j<128;j++){ 
       for (i = 8; i < 16; i++) {
          var = Cudd_bddIthVar(gbm,i); 
          if(i%8 ==  0) {
          //tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, var, bdd_rec[j]); 
	  }
	  else if(i == 9+k && j < 64 ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
          }else if(i == 9+k && j >= 64) {
	  tmp = Cudd_bddAnd(gbm, var, bdd_rec[j]); 
          }
	  else if ( (i == 10 + k) && ( ( j < 32 ) || ( j >= 64 && j < 96 ) ) ) {
          tmp_neg = Cudd_Not(var);
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
          } else if ( i == 10 + k && ( ( j >= 32 && j < 64 ) || ( j >= 96 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
	  } else if (i == 11 + k && ( (j<16) || (j>=32 && j<48) || (j>=64 && j<80) || (j>=96 && j<112) ) ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	  } else if (i == 11 + k && ( (j >= 16 && j < 32) || ( j >= 48 && j < 64 ) || ( j >= 80 && j < 96 ) || ( j >= 112 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
          } else if ( i == 12 + k && ( ( j < 8 ) || ( j >= 16 && j < 24) || (j >= 32 && j < 40) || (j>=48 && j<56) || ( j >= 64 && j < 72 ) || 
		    (j >= 80 && j < 88) || (j >= 96 && j < 104) || (j>=112 && j<120) ) ) {
	   tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
           } else if (i == 12 + k && ( ( j >= 8 && j < 16 ) || ( j >= 24 && j < 32 ) || ( j >= 40 && j < 48) || ( j >= 56 && j < 64) 
			|| (j>72 && j<=80) || (j>=88 && j<96) || (j>=104 && j<112) || (j>=120) ) ) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]);  
 	   } else if (i == 13 + k && ( (j < 4) || (j >= 8 && j < 12) || (j >= 16 && j < 20) || (j >= 24 && j < 28) || (j >= 32 && j < 36) || (j >= 40 && j < 44)
			|| (j >= 48 && j < 52)  || (j >= 56 && j < 60)|| (j >= 64 && j < 68) || (j >= 72 && j < 76) || (j >= 80 && j < 84) || (j >= 88 && j < 92) 	
			|| (j >= 96 && j < 100) || (j >= 104 && j < 108) || (j >= 112 && j < 116) || (j >= 120 && j < 124))) {
	   tmp_neg = Cudd_Not(var);
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   
	   } else if (i == 13 + k && ( (j>=4 && j<8) || ( j >= 12 && j < 16 ) || ( j >= 20 && j < 24 ) || ( j >= 28 && j < 32 ) || ( j >= 36 && j < 40 ) 
			|| ( j >= 44 && j < 48 ) || ( j >= 52 && j < 56 ) || ( j >= 60 && j < 64 ) || ( j >= 68 && j < 72 ) || ( j >= 76 && j < 80 ) 	  
		        || ( j >= 84 && j < 88 ) || ( j >= 92 && j < 96 ) || ( j >= 100 && j < 104 ) || ( j >= 108 && j < 112 ) 
			|| ( j >= 116 && j < 120  ) 	|| ( j >= 124 && j < 128 ))) {
          
		   tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
           } else if ( i == 14 + k && ( (j<2) || (j>=4 && j<6)  || (j>=8 && j<10) || (j>=12 && j<14) || (j>=16 && j<18) || (j>=20 && j<22) || (j>=24 && j<26)
			|| (j>=28 && j<30) || (j>=32 && j<34) || (j>=36 && j<38) || (j>=40 && j<42) || (j>=44 && j<46) || (j>=48 && j<50) || (j>=52 && j<54) 	  
			|| (j>=56 && j<58) || (j>=60 && j<62) || (j>=64 && j<66) || (j>=68 && j<70) || (j>=72 && j<74) || (j>=76 && j<78) || (j>=80 && j<82) 
                	|| (j>=84 && j<86) || (j>=88 && j<90) || (j>=92 && j<94) || (j>=96 && j<98) || (j>=100 && j<102) || (j>=104 && j<106) || (j>=108 && j<110) || 
                	(j>=112 && j<114) || (j>=116 && j<118)     || (j>=120 && j<122) || (j>=124 && j<126)
			)) {
	    tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   } else if (i == 14 + k && ( (j>=2 && j<4) || (j>=6 && j<8) || (j>=10 && j<12) || (j>=14 && j<16) || (j>=18 && j<20) || (j>=22 && j<24) || (j>=26 && j<28)
			|| (j>=30 && j<32) || (j>=34 && j<36) || (j>=38 && j<40) || (j>=42 && j<44) || (j>=46 && j<48) || (j>=50 && j<52) 
			|| (j>=54 && j<56) || (j>=58 && j<60) || (j>=62 && j<64) || (j>=66 && j<68) || (j>=70 && j<72) || (j>=74 && j<76) 
			|| (j>=78 && j<80) || (j>=82 && j<84) || (j>=86 && j<88) || (j>=90 && j<92) || (j>=94 && j<96)
                        || (j>=98 && j<100) || (j>=102 && j<104) || (j>=106 && j<108) || (j>=110 && j<112) || (j>=114 && j<116) 
			|| (j>=118 && j<120) || (j>=122 && j<124) || (j>=126 && j<128) )) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 

	   } else if (i == 15 + k && j % 2 == 0) {
	   
	    tmp_neg = Cudd_Not(var); 
	    tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   
	   } else if (i == 15 + k && j % 2 == 1) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 

	   }
	  
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd_rec[j]);
      bdd_rec[j] = tmp;
    }
  }
    
    bdd1 = Cudd_bddOr(gbm,bdd_rec[0],bdd_rec[1]); 
    Cudd_Ref(bdd1);   
    
    for (k = 2;k<128;k++) {
    bdd1 = Cudd_bddOr(gbm,bdd1,bdd_rec[k]);
    Cudd_Ref(bdd1);   
     }
    bdd = Cudd_bddAnd(gbm,bdd,bdd1);
    Cudd_Ref(bdd);   
/*

     for(j = 0;j<128;j++){ 
       for (i = 16; i < 24; i++) {
          var = Cudd_bddIthVar(gbm,i); 
          if(i%8 ==  0) {
          //tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, var, bdd_rec[j]); 
	  }
	  else if(i == 17+k && j < 64 ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
          }else if(i == 17+k && j >= 64) {
	  tmp = Cudd_bddAnd(gbm, var, bdd_rec[j]); 
          }
	  else if ( (i == 18 + k) && ( ( j < 32 ) || ( j >= 64 && j < 96 ) ) ) {
          tmp_neg = Cudd_Not(var);
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
          } else if ( i == 18 + k && ( ( j >= 32 && j < 64 ) || ( j >= 96 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
	  } else if (i == 19 + k && ( (j<16) || (j>=32 && j<48) || (j>=64 && j<80) || (j>=96 && j<112) ) ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	  } else if (i == 19 + k && ( (j >= 16 && j < 32) || ( j >= 48 && j < 64 ) || ( j >= 80 && j < 96 ) || ( j >= 112 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
          } else if ( i == 20 + k && ( ( j < 8 ) || ( j >= 16 && j < 24) || (j >= 32 && j < 40) || (j>=48 && j<56) || ( j >= 64 && j < 72 ) || 
		    (j >= 80 && j < 88) || (j >= 96 && j < 104) || (j>=112 && j<120) ) ) {
	   tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
           } else if (i == 20 + k && ( ( j >= 8 && j < 16 ) || ( j >= 24 && j < 32 ) || ( j >= 40 && j < 48) || ( j >= 56 && j < 64) 
			|| (j>72 && j<=80) || (j>=88 && j<96) || (j>=104 && j<112) || (j>=120) ) ) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]);  
 	   } else if (i == 21 + k && ( (j < 4) || (j >= 8 && j < 12) || (j >= 16 && j < 20) || (j >= 24 && j < 28) || (j >= 32 && j < 36) || (j >= 40 && j < 44)
			|| (j >= 48 && j < 52)  || (j >= 56 && j < 60)|| (j >= 64 && j < 68) || (j >= 72 && j < 76) || (j >= 80 && j < 84) || (j >= 88 && j < 92) 	
			|| (j >= 96 && j < 100) || (j >= 104 && j < 108) || (j >= 112 && j < 116) || (j >= 120 && j < 124))) {
	   tmp_neg = Cudd_Not(var);
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   
	   } else if (i == 21 + k && ( (j>=4 && j<8) || ( j >= 12 && j < 16 ) || ( j >= 20 && j < 24 ) || ( j >= 28 && j < 32 ) || ( j >= 36 && j < 40 ) 
			|| ( j >= 44 && j < 48 ) || ( j >= 52 && j < 56 ) || ( j >= 60 && j < 64 ) || ( j >= 68 && j < 72 ) || ( j >= 76 && j < 80 ) 	  
		        || ( j >= 84 && j < 88 ) || ( j >= 92 && j < 96 ) || ( j >= 100 && j < 104 ) || ( j >= 108 && j < 112 ) 
			|| ( j >= 116 && j < 120  ) 	|| ( j >= 124 && j < 128 ))) {
          
		   tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
           } else if ( i == 22 + k && ( (j<2) || (j>=4 && j<6)  || (j>=8 && j<10) || (j>=12 && j<14) || (j>=16 && j<18) || (j>=20 && j<22) || (j>=24 && j<26)
			|| (j>=28 && j<30) || (j>=32 && j<34) || (j>=36 && j<38) || (j>=40 && j<42) || (j>=44 && j<46) || (j>=48 && j<50) || (j>=52 && j<54) 	  
			|| (j>=56 && j<58) || (j>=60 && j<62) || (j>=64 && j<66) || (j>=68 && j<70) || (j>=72 && j<74) || (j>=76 && j<78) || (j>=80 && j<82) 
                	|| (j>=84 && j<86) || (j>=88 && j<90) || (j>=92 && j<94) || (j>=96 && j<98) || (j>=100 && j<102) || (j>=104 && j<106) || (j>=108 && j<110) || 
                	(j>=112 && j<114) || (j>=116 && j<118)     || (j>=120 && j<122) || (j>=124 && j<126)
			)) {
	    tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   } else if (i == 22 + k && ( (j>=2 && j<4) || (j>=6 && j<8) || (j>=10 && j<12) || (j>=14 && j<16) || (j>=18 && j<20) || (j>=22 && j<24) || (j>=26 && j<28)
			|| (j>=30 && j<32) || (j>=34 && j<36) || (j>=38 && j<40) || (j>=42 && j<44) || (j>=46 && j<48) || (j>=50 && j<52) 
			|| (j>=54 && j<56) || (j>=58 && j<60) || (j>=62 && j<64) || (j>=66 && j<68) || (j>=70 && j<72) || (j>=74 && j<76) 
			|| (j>=78 && j<80) || (j>=82 && j<84) || (j>=86 && j<88) || (j>=90 && j<92) || (j>=94 && j<96)
                        || (j>=98 && j<100) || (j>=102 && j<104) || (j>=106 && j<108) || (j>=110 && j<112) || (j>=114 && j<116) 
			|| (j>=118 && j<120) || (j>=122 && j<124) || (j>=126 && j<128) )) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 

	   } else if (i == 23 + k && j % 2 == 0) {
	   
	    tmp_neg = Cudd_Not(var); 
	    tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   
	   } else if (i == 23 + k && j % 2 == 1) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 

	   }
	  
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd_rec[j]);
      bdd_rec[j] = tmp;
    }
  }
    

    bdd9 = Cudd_bddOr(gbm,bdd_rec[0],bdd_rec[1]); 
    Cudd_Ref(bdd1);   
    
    for (k = 2;k<128;k++) {
    bdd9 = Cudd_bddOr(gbm,bdd9,bdd_rec[k]);
    Cudd_Ref(bdd1);   
    }

    bdd = Cudd_bddAnd(gbm,bdd,bdd9);
    Cudd_Ref(bdd);   

     for(j = 0;j<128;j++){ 
       for (i = 24; i < 32; i++) {
          var = Cudd_bddIthVar(gbm,i); 
          if(i%8 ==  0) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	  }
	  else if(i == 25+k && j < 64 ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
          }else if(i == 25+k && j >= 64) {
	  tmp = Cudd_bddAnd(gbm, var, bdd_rec[j]); 
          }
	  else if ( (i == 26 + k) && ( ( j < 32 ) || ( j >= 64 && j < 96 ) ) ) {
          tmp_neg = Cudd_Not(var);
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
          } else if ( i == 26 + k && ( ( j >= 32 && j < 64 ) || ( j >= 96 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
	  } else if (i == 27 + k && ( (j<16) || (j>=32 && j<48) || (j>=64 && j<80) || (j>=96 && j<112) ) ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	  } else if (i == 27 + k && ( (j >= 16 && j < 32) || ( j >= 48 && j < 64 ) || ( j >= 80 && j < 96 ) || ( j >= 112 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
          } else if ( i == 28 + k && ( ( j < 8 ) || ( j >= 16 && j < 24) || (j >= 32 && j < 40) || (j>=48 && j<56) || ( j >= 64 && j < 72 ) || 
		    (j >= 80 && j < 88) || (j >= 96 && j < 104) || (j>=112 && j<120) ) ) {
	   tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
           } else if (i == 28 + k && ( ( j >= 8 && j < 16 ) || ( j >= 24 && j < 32 ) || ( j >= 40 && j < 48) || ( j >= 56 && j < 64) 
			|| (j>72 && j<=80) || (j>=88 && j<96) || (j>=104 && j<112) || (j>=120) ) ) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]);  
 	   } else if (i == 29 + k && ( (j < 4) || (j >= 8 && j < 12) || (j >= 16 && j < 20) || (j >= 24 && j < 28) || (j >= 32 && j < 36) || (j >= 40 && j < 44)
			|| (j >= 48 && j < 52)  || (j >= 56 && j < 60)|| (j >= 64 && j < 68) || (j >= 72 && j < 76) || (j >= 80 && j < 84) || (j >= 88 && j < 92) 	
			|| (j >= 96 && j < 100) || (j >= 104 && j < 108) || (j >= 112 && j < 116) || (j >= 120 && j < 124))) {
	   tmp_neg = Cudd_Not(var);
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   
	   } else if (i == 29 + k && ( (j>=4 && j<8) || ( j >= 12 && j < 16 ) || ( j >= 20 && j < 24 ) || ( j >= 28 && j < 32 ) || ( j >= 36 && j < 40 ) 
			|| ( j >= 44 && j < 48 ) || ( j >= 52 && j < 56 ) || ( j >= 60 && j < 64 ) || ( j >= 68 && j < 72 ) || ( j >= 76 && j < 80 ) 	  
		        || ( j >= 84 && j < 88 ) || ( j >= 92 && j < 96 ) || ( j >= 100 && j < 104 ) || ( j >= 108 && j < 112 ) 
			|| ( j >= 116 && j < 120  ) 	|| ( j >= 124 && j < 128 ))) {
          
		   tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
           } else if ( i == 30 + k && ( (j<2) || (j>=4 && j<6)  || (j>=8 && j<10) || (j>=12 && j<14) || (j>=16 && j<18) || (j>=20 && j<22) || (j>=24 && j<26)
			|| (j>=28 && j<30) || (j>=32 && j<34) || (j>=36 && j<38) || (j>=40 && j<42) || (j>=44 && j<46) || (j>=48 && j<50) || (j>=52 && j<54) 	  
			|| (j>=56 && j<58) || (j>=60 && j<62) || (j>=64 && j<66) || (j>=68 && j<70) || (j>=72 && j<74) || (j>=76 && j<78) || (j>=80 && j<82) 
                	|| (j>=84 && j<86) || (j>=88 && j<90) || (j>=92 && j<94) || (j>=96 && j<98) || (j>=100 && j<102) || (j>=104 && j<106) || (j>=108 && j<110) || 
                	(j>=112 && j<114) || (j>=116 && j<118)     || (j>=120 && j<122) || (j>=124 && j<126)
			)) {
	    tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   } else if (i == 30 + k && ( (j>=2 && j<4) || (j>=6 && j<8) || (j>=10 && j<12) || (j>=14 && j<16) || (j>=18 && j<20) || (j>=22 && j<24) || (j>=26 && j<28)
			|| (j>=30 && j<32) || (j>=34 && j<36) || (j>=38 && j<40) || (j>=42 && j<44) || (j>=46 && j<48) || (j>=50 && j<52) 
			|| (j>=54 && j<56) || (j>=58 && j<60) || (j>=62 && j<64) || (j>=66 && j<68) || (j>=70 && j<72) || (j>=74 && j<76) 
			|| (j>=78 && j<80) || (j>=82 && j<84) || (j>=86 && j<88) || (j>=90 && j<92) || (j>=94 && j<96)
                        || (j>=98 && j<100) || (j>=102 && j<104) || (j>=106 && j<108) || (j>=110 && j<112) || (j>=114 && j<116) 
			|| (j>=118 && j<120) || (j>=122 && j<124) || (j>=126 && j<128) )) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 

	   } else if (i == 31 + k && j % 2 == 0) {
	   
	    tmp_neg = Cudd_Not(var); 
	    tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   
	   } else if (i == 31 + k && j % 2 == 1) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 

	   }
	  
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd_rec[j]);
      bdd_rec[j] = tmp;
    }
  }
    
    bdd10 = Cudd_bddOr(gbm,bdd_rec[0],bdd_rec[1]); 
    Cudd_Ref(bdd10);   
    
    for (k = 2;k<128;k++) {
    bdd10 = Cudd_bddOr(gbm,bdd10,bdd_rec[k]);
    Cudd_Ref(bdd10);   
     }
    bdd = Cudd_bddAnd(gbm,bdd,bdd10);
    Cudd_Ref(bdd);   

*/
    DdNode* bdd71;
   
    bdd71 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd71); /*Increases the reference count of a node*/

     for (i = 16; i < 18; i++) {  
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd71); 
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd71);
      bdd71 = tmp;
    }
    
    
    bdd = Cudd_bddAnd(gbm,bdd,bdd71);
    Cudd_Ref(bdd);

return bdd;

    

}


DdNode* scrivi_bdd_quattro2 (DdManager *gbm, DdNode *bdd, DdNode * var) {

 DdNode* bdd_rec[128];
 DdNode *bdd1, *bdd2, *bdd3, *bdd4, *bdd5, *bdd6, *bdd7, *bdd8, *bdd9,*bdd10,*tmp,*tmp_neg,*bdd11;
     bdd = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd); /*Increases the reference count of a node*/
     int i; 
     
     for(i = 0; i < 128; i++){
     bdd_rec[i] = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd_rec[i]); /*Increases the reference count of a node*/
     } 
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
     bdd6 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd6); /*Increases the reference count of a node*/
     bdd7 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd7); /*Increases the reference count of a node*/
     bdd8 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd8); /*Increases the reference count of a node*/
     bdd9 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd9); /*Increases the reference count of a node*/
   

    int j;int k = 0;
     for(j = 0;j<128;j++){ 
       for (i = 8; i < 16; i++) {
          var = Cudd_bddIthVar(gbm,i); 
          if(i%8 ==  0) {
          //tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, var, bdd_rec[j]); 
	  }
	  else if(i == 9+k && j < 64 ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
          }else if(i == 9+k && j >= 64) {
	  tmp = Cudd_bddAnd(gbm, var, bdd_rec[j]); 
          }
	  else if ( (i == 10 + k) && ( ( j < 32 ) || ( j >= 64 && j < 96 ) ) ) {
          tmp_neg = Cudd_Not(var);
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
          } else if ( i == 10 + k && ( ( j >= 32 && j < 64 ) || ( j >= 96 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
	  } else if (i == 11 + k && ( (j<16) || (j>=32 && j<48) || (j>=64 && j<80) || (j>=96 && j<112) ) ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	  } else if (i == 11 + k && ( (j >= 16 && j < 32) || ( j >= 48 && j < 64 ) || ( j >= 80 && j < 96 ) || ( j >= 112 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
          } else if ( i == 12 + k && ( ( j < 8 ) || ( j >= 16 && j < 24) || (j >= 32 && j < 40) || (j>=48 && j<56) || ( j >= 64 && j < 72 ) || 
		    (j >= 80 && j < 88) || (j >= 96 && j < 104) || (j>=112 && j<120) ) ) {
	   tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
           } else if (i == 12 + k && ( ( j >= 8 && j < 16 ) || ( j >= 24 && j < 32 ) || ( j >= 40 && j < 48) || ( j >= 56 && j < 64) 
			|| (j>72 && j<=80) || (j>=88 && j<96) || (j>=104 && j<112) || (j>=120) ) ) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]);  
 	   } else if (i == 13 + k && ( (j < 4) || (j >= 8 && j < 12) || (j >= 16 && j < 20) || (j >= 24 && j < 28) || (j >= 32 && j < 36) || (j >= 40 && j < 44)
			|| (j >= 48 && j < 52)  || (j >= 56 && j < 60)|| (j >= 64 && j < 68) || (j >= 72 && j < 76) || (j >= 80 && j < 84) || (j >= 88 && j < 92) 	
			|| (j >= 96 && j < 100) || (j >= 104 && j < 108) || (j >= 112 && j < 116) || (j >= 120 && j < 124))) {
	   tmp_neg = Cudd_Not(var);
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   
	   } else if (i == 13 + k && ( (j>=4 && j<8) || ( j >= 12 && j < 16 ) || ( j >= 20 && j < 24 ) || ( j >= 28 && j < 32 ) || ( j >= 36 && j < 40 ) 
			|| ( j >= 44 && j < 48 ) || ( j >= 52 && j < 56 ) || ( j >= 60 && j < 64 ) || ( j >= 68 && j < 72 ) || ( j >= 76 && j < 80 ) 	  
		        || ( j >= 84 && j < 88 ) || ( j >= 92 && j < 96 ) || ( j >= 100 && j < 104 ) || ( j >= 108 && j < 112 ) 
			|| ( j >= 116 && j < 120  ) 	|| ( j >= 124 && j < 128 ))) {
          
		   tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
           } else if ( i == 14 + k && ( (j<2) || (j>=4 && j<6)  || (j>=8 && j<10) || (j>=12 && j<14) || (j>=16 && j<18) || (j>=20 && j<22) || (j>=24 && j<26)
			|| (j>=28 && j<30) || (j>=32 && j<34) || (j>=36 && j<38) || (j>=40 && j<42) || (j>=44 && j<46) || (j>=48 && j<50) || (j>=52 && j<54) 	  
			|| (j>=56 && j<58) || (j>=60 && j<62) || (j>=64 && j<66) || (j>=68 && j<70) || (j>=72 && j<74) || (j>=76 && j<78) || (j>=80 && j<82) 
                	|| (j>=84 && j<86) || (j>=88 && j<90) || (j>=92 && j<94) || (j>=96 && j<98) || (j>=100 && j<102) || (j>=104 && j<106) || (j>=108 && j<110) || 
                	(j>=112 && j<114) || (j>=116 && j<118)     || (j>=120 && j<122) || (j>=124 && j<126)
			)) {
	    tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   } else if (i == 14 + k && ( (j>=2 && j<4) || (j>=6 && j<8) || (j>=10 && j<12) || (j>=14 && j<16) || (j>=18 && j<20) || (j>=22 && j<24) || (j>=26 && j<28)
			|| (j>=30 && j<32) || (j>=34 && j<36) || (j>=38 && j<40) || (j>=42 && j<44) || (j>=46 && j<48) || (j>=50 && j<52) 
			|| (j>=54 && j<56) || (j>=58 && j<60) || (j>=62 && j<64) || (j>=66 && j<68) || (j>=70 && j<72) || (j>=74 && j<76) 
			|| (j>=78 && j<80) || (j>=82 && j<84) || (j>=86 && j<88) || (j>=90 && j<92) || (j>=94 && j<96)
                        || (j>=98 && j<100) || (j>=102 && j<104) || (j>=106 && j<108) || (j>=110 && j<112) || (j>=114 && j<116) 
			|| (j>=118 && j<120) || (j>=122 && j<124) || (j>=126 && j<128) )) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 

	   } else if (i == 15 + k && j % 2 == 0) {
	   
	    tmp_neg = Cudd_Not(var); 
	    tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   
	   } else if (i == 15 + k && j % 2 == 1) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 

	   }
	  
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd_rec[j]);
      bdd_rec[j] = tmp;
    }
  }
    
    bdd1 = Cudd_bddOr(gbm,bdd_rec[0],bdd_rec[1]); 
    Cudd_Ref(bdd1);   
    
    for (k = 2;k<128;k++) {
    bdd1 = Cudd_bddOr(gbm,bdd1,bdd_rec[k]);
    Cudd_Ref(bdd1);   
     }
    bdd = Cudd_bddAnd(gbm,bdd,bdd1);
    Cudd_Ref(bdd);   

/*
     for(j = 0;j<128;j++){ 
       for (i = 16; i < 24; i++) {
          var = Cudd_bddIthVar(gbm,i); 
          if(i%8 ==  0) {
          //tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, var, bdd_rec[j]); 
	  }
	  else if(i == 17+k && j < 64 ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
          }else if(i == 17+k && j >= 64) {
	  tmp = Cudd_bddAnd(gbm, var, bdd_rec[j]); 
          }
	  else if ( (i == 18 + k) && ( ( j < 32 ) || ( j >= 64 && j < 96 ) ) ) {
          tmp_neg = Cudd_Not(var);
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
          } else if ( i == 18 + k && ( ( j >= 32 && j < 64 ) || ( j >= 96 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
	  } else if (i == 19 + k && ( (j<16) || (j>=32 && j<48) || (j>=64 && j<80) || (j>=96 && j<112) ) ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	  } else if (i == 19 + k && ( (j >= 16 && j < 32) || ( j >= 48 && j < 64 ) || ( j >= 80 && j < 96 ) || ( j >= 112 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
          } else if ( i == 20 + k && ( ( j < 8 ) || ( j >= 16 && j < 24) || (j >= 32 && j < 40) || (j>=48 && j<56) || ( j >= 64 && j < 72 ) || 
		    (j >= 80 && j < 88) || (j >= 96 && j < 104) || (j>=112 && j<120) ) ) {
	   tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
           } else if (i == 20 + k && ( ( j >= 8 && j < 16 ) || ( j >= 24 && j < 32 ) || ( j >= 40 && j < 48) || ( j >= 56 && j < 64) 
			|| (j>72 && j<=80) || (j>=88 && j<96) || (j>=104 && j<112) || (j>=120) ) ) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]);  
 	   } else if (i == 21 + k && ( (j < 4) || (j >= 8 && j < 12) || (j >= 16 && j < 20) || (j >= 24 && j < 28) || (j >= 32 && j < 36) || (j >= 40 && j < 44)
			|| (j >= 48 && j < 52)  || (j >= 56 && j < 60)|| (j >= 64 && j < 68) || (j >= 72 && j < 76) || (j >= 80 && j < 84) || (j >= 88 && j < 92) 	
			|| (j >= 96 && j < 100) || (j >= 104 && j < 108) || (j >= 112 && j < 116) || (j >= 120 && j < 124))) {
	   tmp_neg = Cudd_Not(var);
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   
	   } else if (i == 21 + k && ( (j>=4 && j<8) || ( j >= 12 && j < 16 ) || ( j >= 20 && j < 24 ) || ( j >= 28 && j < 32 ) || ( j >= 36 && j < 40 ) 
			|| ( j >= 44 && j < 48 ) || ( j >= 52 && j < 56 ) || ( j >= 60 && j < 64 ) || ( j >= 68 && j < 72 ) || ( j >= 76 && j < 80 ) 	  
		        || ( j >= 84 && j < 88 ) || ( j >= 92 && j < 96 ) || ( j >= 100 && j < 104 ) || ( j >= 108 && j < 112 ) 
			|| ( j >= 116 && j < 120  ) 	|| ( j >= 124 && j < 128 ))) {
          
		   tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
           } else if ( i == 22 + k && ( (j<2) || (j>=4 && j<6)  || (j>=8 && j<10) || (j>=12 && j<14) || (j>=16 && j<18) || (j>=20 && j<22) || (j>=24 && j<26)
			|| (j>=28 && j<30) || (j>=32 && j<34) || (j>=36 && j<38) || (j>=40 && j<42) || (j>=44 && j<46) || (j>=48 && j<50) || (j>=52 && j<54) 	  
			|| (j>=56 && j<58) || (j>=60 && j<62) || (j>=64 && j<66) || (j>=68 && j<70) || (j>=72 && j<74) || (j>=76 && j<78) || (j>=80 && j<82) 
                	|| (j>=84 && j<86) || (j>=88 && j<90) || (j>=92 && j<94) || (j>=96 && j<98) || (j>=100 && j<102) || (j>=104 && j<106) || (j>=108 && j<110) || 
                	(j>=112 && j<114) || (j>=116 && j<118)     || (j>=120 && j<122) || (j>=124 && j<126)
			)) {
	    tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   } else if (i == 22 + k && ( (j>=2 && j<4) || (j>=6 && j<8) || (j>=10 && j<12) || (j>=14 && j<16) || (j>=18 && j<20) || (j>=22 && j<24) || (j>=26 && j<28)
			|| (j>=30 && j<32) || (j>=34 && j<36) || (j>=38 && j<40) || (j>=42 && j<44) || (j>=46 && j<48) || (j>=50 && j<52) 
			|| (j>=54 && j<56) || (j>=58 && j<60) || (j>=62 && j<64) || (j>=66 && j<68) || (j>=70 && j<72) || (j>=74 && j<76) 
			|| (j>=78 && j<80) || (j>=82 && j<84) || (j>=86 && j<88) || (j>=90 && j<92) || (j>=94 && j<96)
                        || (j>=98 && j<100) || (j>=102 && j<104) || (j>=106 && j<108) || (j>=110 && j<112) || (j>=114 && j<116) 
			|| (j>=118 && j<120) || (j>=122 && j<124) || (j>=126 && j<128) )) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 

	   } else if (i == 23 + k && j % 2 == 0) {
	   
	    tmp_neg = Cudd_Not(var); 
	    tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   
	   } else if (i == 23 + k && j % 2 == 1) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 

	   }
	  
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd_rec[j]);
      bdd_rec[j] = tmp;
    }
  }
    

    bdd9 = Cudd_bddOr(gbm,bdd_rec[0],bdd_rec[1]); 
    Cudd_Ref(bdd1);   
    
    for (k = 2;k<128;k++) {
    bdd9 = Cudd_bddOr(gbm,bdd9,bdd_rec[k]);
    Cudd_Ref(bdd1);   
    }

    bdd = Cudd_bddAnd(gbm,bdd,bdd9);
    Cudd_Ref(bdd);   

     for(j = 0;j<128;j++){ 
       for (i = 24; i < 32; i++) {
          var = Cudd_bddIthVar(gbm,i); 
          if(i%8 ==  0) {
          //tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, var, bdd_rec[j]); 
	  }
	  else if(i == 25+k && j < 64 ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
          }else if(i == 25+k && j >= 64) {
	  tmp = Cudd_bddAnd(gbm, var, bdd_rec[j]); 
          }
	  else if ( (i == 26 + k) && ( ( j < 32 ) || ( j >= 64 && j < 96 ) ) ) {
          tmp_neg = Cudd_Not(var);
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
          } else if ( i == 26 + k && ( ( j >= 32 && j < 64 ) || ( j >= 96 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
	  } else if (i == 27 + k && ( (j<16) || (j>=32 && j<48) || (j>=64 && j<80) || (j>=96 && j<112) ) ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	  } else if (i == 27 + k && ( (j >= 16 && j < 32) || ( j >= 48 && j < 64 ) || ( j >= 80 && j < 96 ) || ( j >= 112 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
          } else if ( i == 28 + k && ( ( j < 8 ) || ( j >= 16 && j < 24) || (j >= 32 && j < 40) || (j>=48 && j<56) || ( j >= 64 && j < 72 ) || 
		    (j >= 80 && j < 88) || (j >= 96 && j < 104) || (j>=112 && j<120) ) ) {
	   tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
           } else if (i == 28 + k && ( ( j >= 8 && j < 16 ) || ( j >= 24 && j < 32 ) || ( j >= 40 && j < 48) || ( j >= 56 && j < 64) 
			|| (j>72 && j<=80) || (j>=88 && j<96) || (j>=104 && j<112) || (j>=120) ) ) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]);  
 	   } else if (i == 29 + k && ( (j < 4) || (j >= 8 && j < 12) || (j >= 16 && j < 20) || (j >= 24 && j < 28) || (j >= 32 && j < 36) || (j >= 40 && j < 44)
			|| (j >= 48 && j < 52)  || (j >= 56 && j < 60)|| (j >= 64 && j < 68) || (j >= 72 && j < 76) || (j >= 80 && j < 84) || (j >= 88 && j < 92) 	
			|| (j >= 96 && j < 100) || (j >= 104 && j < 108) || (j >= 112 && j < 116) || (j >= 120 && j < 124))) {
	   tmp_neg = Cudd_Not(var);
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   
	   } else if (i == 29 + k && ( (j>=4 && j<8) || ( j >= 12 && j < 16 ) || ( j >= 20 && j < 24 ) || ( j >= 28 && j < 32 ) || ( j >= 36 && j < 40 ) 
			|| ( j >= 44 && j < 48 ) || ( j >= 52 && j < 56 ) || ( j >= 60 && j < 64 ) || ( j >= 68 && j < 72 ) || ( j >= 76 && j < 80 ) 	  
		        || ( j >= 84 && j < 88 ) || ( j >= 92 && j < 96 ) || ( j >= 100 && j < 104 ) || ( j >= 108 && j < 112 ) 
			|| ( j >= 116 && j < 120  ) 	|| ( j >= 124 && j < 128 ))) {
          
		   tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
           } else if ( i == 30 + k && ( (j<2) || (j>=4 && j<6)  || (j>=8 && j<10) || (j>=12 && j<14) || (j>=16 && j<18) || (j>=20 && j<22) || (j>=24 && j<26)
			|| (j>=28 && j<30) || (j>=32 && j<34) || (j>=36 && j<38) || (j>=40 && j<42) || (j>=44 && j<46) || (j>=48 && j<50) || (j>=52 && j<54) 	  
			|| (j>=56 && j<58) || (j>=60 && j<62) || (j>=64 && j<66) || (j>=68 && j<70) || (j>=72 && j<74) || (j>=76 && j<78) || (j>=80 && j<82) 
                	|| (j>=84 && j<86) || (j>=88 && j<90) || (j>=92 && j<94) || (j>=96 && j<98) || (j>=100 && j<102) || (j>=104 && j<106) || (j>=108 && j<110) || 
                	(j>=112 && j<114) || (j>=116 && j<118)     || (j>=120 && j<122) || (j>=124 && j<126)
			)) {
	    tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   } else if (i == 30 + k && ( (j>=2 && j<4) || (j>=6 && j<8) || (j>=10 && j<12) || (j>=14 && j<16) || (j>=18 && j<20) || (j>=22 && j<24) || (j>=26 && j<28)
			|| (j>=30 && j<32) || (j>=34 && j<36) || (j>=38 && j<40) || (j>=42 && j<44) || (j>=46 && j<48) || (j>=50 && j<52) 
			|| (j>=54 && j<56) || (j>=58 && j<60) || (j>=62 && j<64) || (j>=66 && j<68) || (j>=70 && j<72) || (j>=74 && j<76) 
			|| (j>=78 && j<80) || (j>=82 && j<84) || (j>=86 && j<88) || (j>=90 && j<92) || (j>=94 && j<96)
                        || (j>=98 && j<100) || (j>=102 && j<104) || (j>=106 && j<108) || (j>=110 && j<112) || (j>=114 && j<116) 
			|| (j>=118 && j<120) || (j>=122 && j<124) || (j>=126 && j<128) )) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 

	   } else if (i == 31 + k && j % 2 == 0) {
	   
	    tmp_neg = Cudd_Not(var); 
	    tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   
	   } else if (i == 31 + k && j % 2 == 1) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 

	   }
	  
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd_rec[j]);
      bdd_rec[j] = tmp;
    }
  }
    
    bdd10 = Cudd_bddOr(gbm,bdd_rec[0],bdd_rec[1]); 
    Cudd_Ref(bdd10);   
    
    for (k = 2;k<128;k++) {
    bdd10 = Cudd_bddOr(gbm,bdd10,bdd_rec[k]);
    Cudd_Ref(bdd10);   
     }
    bdd = Cudd_bddAnd(gbm,bdd,bdd10);
    Cudd_Ref(bdd);   
*/
    /*
     for(j = 0;j<128;j++){ 
       for (i = 32; i < 40; i++) {
          var = Cudd_bddIthVar(gbm,i); 
          if(i%8 ==  0) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	  }
	  else if(i == 33+k && j < 64 ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
          }else if(i == 33+k && j >= 64) {
	  tmp = Cudd_bddAnd(gbm, var, bdd_rec[j]); 
          }
	  else if ( (i == 34 + k) && ( ( j < 32 ) || ( j >= 64 && j < 96 ) ) ) {
          tmp_neg = Cudd_Not(var);
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
          } else if ( i == 34 + k && ( ( j >= 32 && j < 64 ) || ( j >= 96 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
	  } else if (i == 35 + k && ( (j<16) || (j>=32 && j<48) || (j>=64 && j<80) || (j>=96 && j<112) ) ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	  } else if (i == 35 + k && ( (j >= 16 && j < 32) || ( j >= 48 && j < 64 ) || ( j >= 80 && j < 96 ) || ( j >= 112 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
          } else if ( i == 36 + k && ( ( j < 8 ) || ( j >= 16 && j < 24) || (j >= 32 && j < 40) || (j>=48 && j<56) || ( j >= 64 && j < 72 ) || 
		    (j >= 80 && j < 88) || (j >= 96 && j < 104) || (j>=112 && j<120) ) ) {
	   tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
           } else if (i == 36 + k && ( ( j >= 8 && j < 16 ) || ( j >= 24 && j < 32 ) || ( j >= 40 && j < 48) || ( j >= 56 && j < 64) 
			|| (j>72 && j<=80) || (j>=88 && j<96) || (j>=104 && j<112) || (j>=120) ) ) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]);  
 	   } else if (i == 37 + k && ( (j < 4) || (j >= 8 && j < 12) || (j >= 16 && j < 20) || (j >= 24 && j < 28) || (j >= 32 && j < 36) || (j >= 40 && j < 44)
			|| (j >= 48 && j < 52)  || (j >= 56 && j < 60)|| (j >= 64 && j < 68) || (j >= 72 && j < 76) || (j >= 80 && j < 84) || (j >= 88 && j < 92) 	
			|| (j >= 96 && j < 100) || (j >= 104 && j < 108) || (j >= 112 && j < 116) || (j >= 120 && j < 124))) {
	   tmp_neg = Cudd_Not(var);
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   
	   } else if (i == 37 + k && ( (j>=4 && j<8) || ( j >= 12 && j < 16 ) || ( j >= 20 && j < 24 ) || ( j >= 28 && j < 32 ) || ( j >= 36 && j < 40 ) 
			|| ( j >= 44 && j < 48 ) || ( j >= 52 && j < 56 ) || ( j >= 60 && j < 64 ) || ( j >= 68 && j < 72 ) || ( j >= 76 && j < 80 ) 	  
		        || ( j >= 84 && j < 88 ) || ( j >= 92 && j < 96 ) || ( j >= 100 && j < 104 ) || ( j >= 108 && j < 112 ) 
			|| ( j >= 116 && j < 120  ) 	|| ( j >= 124 && j < 128 ))) {
          
		   tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
           } else if ( i == 38 + k && ( (j<2) || (j>=4 && j<6)  || (j>=8 && j<10) || (j>=12 && j<14) || (j>=16 && j<18) || (j>=20 && j<22) || (j>=24 && j<26)
			|| (j>=28 && j<30) || (j>=32 && j<34) || (j>=36 && j<38) || (j>=40 && j<42) || (j>=44 && j<46) || (j>=48 && j<50) || (j>=52 && j<54) 	  
			|| (j>=56 && j<58) || (j>=60 && j<62) || (j>=64 && j<66) || (j>=68 && j<70) || (j>=72 && j<74) || (j>=76 && j<78) || (j>=80 && j<82) 
                	|| (j>=84 && j<86) || (j>=88 && j<90) || (j>=92 && j<94) || (j>=96 && j<98) || (j>=100 && j<102) || (j>=104 && j<106) || (j>=108 && j<110) || 
                	(j>=112 && j<114) || (j>=116 && j<118)     || (j>=120 && j<122) || (j>=124 && j<126)
			)) {
	    tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   } else if (i == 38 + k && ( (j>=2 && j<4) || (j>=6 && j<8) || (j>=10 && j<12) || (j>=14 && j<16) || (j>=18 && j<20) || (j>=22 && j<24) || (j>=26 && j<28)
			|| (j>=30 && j<32) || (j>=34 && j<36) || (j>=38 && j<40) || (j>=42 && j<44) || (j>=46 && j<48) || (j>=50 && j<52) 
			|| (j>=54 && j<56) || (j>=58 && j<60) || (j>=62 && j<64) || (j>=66 && j<68) || (j>=70 && j<72) || (j>=74 && j<76) 
			|| (j>=78 && j<80) || (j>=82 && j<84) || (j>=86 && j<88) || (j>=90 && j<92) || (j>=94 && j<96)
                        || (j>=98 && j<100) || (j>=102 && j<104) || (j>=106 && j<108) || (j>=110 && j<112) || (j>=114 && j<116) 
			|| (j>=118 && j<120) || (j>=122 && j<124) || (j>=126 && j<128) )) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 

	   } else if (i == 39 + k && j % 2 == 0) {
	   
	    tmp_neg = Cudd_Not(var); 
	    tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   
	   } else if (i == 39 + k && j % 2 == 1) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 

	   }
	  
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd_rec[j]);
      bdd_rec[j] = tmp;
    }
  }
    bdd11 = Cudd_bddOr(gbm,bdd_rec[0],bdd_rec[1]); 
    Cudd_Ref(bdd11);   
    
    for (k = 2;k<128;k++) {
    bdd11 = Cudd_bddOr(gbm,bdd11,bdd_rec[k]);
    Cudd_Ref(bdd11);   
     }
    bdd = Cudd_bddAnd(gbm,bdd,bdd11);
    Cudd_Ref(bdd);   
*/
    DdNode* bdd71;
   
    bdd71 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd71); /*Increases the reference count of a node*/

     for (i = 16; i < 18; i++) {  
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd71); 
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd71);
      bdd71 = tmp;
    }
    
    
    bdd = Cudd_bddAnd(gbm,bdd,bdd71);
    Cudd_Ref(bdd);

    return bdd;

    

}




//FUNZIONI PUBACK

DdNode* scrivi_bdd_zero3 (DdManager *gbm, DdNode *bdd, DdNode * var) 
{
     DdNode* bdd_rec[128];
     DdNode* bdd_rec2[128];
     
     DdNode *bdd1, *bdd2, *bdd3, *bdd4, *bdd5, *bdd6, *bdd7, *bdd8, *bdd9,*tmp,*tmp_neg;
     bdd = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd); /*Increases the reference count of a node*/
     int i; 
     
     for(i = 0; i < 128; i++){
     bdd_rec[i] = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd_rec[i]); /*Increases the reference count of a node*/
     } 
     for(i = 0; i < 128; i++){
     bdd_rec2[i] = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd_rec2[i]); /*Increases the reference count of a node*/
     } 

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
     bdd6 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd6); /*Increases the reference count of a node*/
     bdd7 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd7); /*Increases the reference count of a node*/
     bdd8 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd8); /*Increases the reference count of a node*/
   
     
     for (i = 0; i < 8; i++) {
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
     if(i != 1) {
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

    Cudd_Ref(bdd);
    bdd = Cudd_bddAnd(gbm,bdd,bdd1);

    
    int j,k;
/*
     for(j = 0;j<128;j++){ 
       for (i = 16; i < 24; i++) {
          var = Cudd_bddIthVar(gbm,i); 
          if(i%8 ==  0) {
          //tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, var, bdd_rec[j]); 
	  }
	  else if(i == 17+k && j < 64 ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
          }else if(i == 17+k && j >= 64) {
	  tmp = Cudd_bddAnd(gbm, var, bdd_rec[j]); 
          }
	  else if ( (i == 18 + k) && ( ( j < 32 ) || ( j >= 64 && j < 96 ) ) ) {
          tmp_neg = Cudd_Not(var);
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
          } else if ( i == 18 + k && ( ( j >= 32 && j < 64 ) || ( j >= 96 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
	  } else if (i == 19 + k && ( (j<16) || (j>=32 && j<48) || (j>=64 && j<80) || (j>=96 && j<112) ) ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	  } else if (i == 19 + k && ( (j >= 16 && j < 32) || ( j >= 48 && j < 64 ) || ( j >= 80 && j < 96 ) || ( j >= 112 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
          } else if ( i == 20 + k && ( ( j < 8 ) || ( j >= 16 && j < 24) || (j >= 32 && j < 40) || (j>=48 && j<56) || ( j >= 64 && j < 72 ) || 
		    (j >= 80 && j < 88) || (j >= 96 && j < 104) || (j>=112 && j<120) ) ) {
	   tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
           } else if (i == 20 + k && ( ( j >= 8 && j < 16 ) || ( j >= 24 && j < 32 ) || ( j >= 40 && j < 48) || ( j >= 56 && j < 64) 
			|| (j>72 && j<=80) || (j>=88 && j<96) || (j>=104 && j<112) || (j>=120) ) ) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]);  
 	   } else if (i == 21 + k && ( (j < 4) || (j >= 8 && j < 12) || (j >= 16 && j < 20) || (j >= 24 && j < 28) || (j >= 32 && j < 36) || (j >= 40 && j < 44)
			|| (j >= 48 && j < 52)  || (j >= 56 && j < 60)|| (j >= 64 && j < 68) || (j >= 72 && j < 76) || (j >= 80 && j < 84) || (j >= 88 && j < 92) 	
			|| (j >= 96 && j < 100) || (j >= 104 && j < 108) || (j >= 112 && j < 116) || (j >= 120 && j < 124))) {
	   tmp_neg = Cudd_Not(var);
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   
	   } else if (i == 21 + k && ( (j>=4 && j<8) || ( j >= 12 && j < 16 ) || ( j >= 20 && j < 24 ) || ( j >= 28 && j < 32 ) || ( j >= 36 && j < 40 ) 
			|| ( j >= 44 && j < 48 ) || ( j >= 52 && j < 56 ) || ( j >= 60 && j < 64 ) || ( j >= 68 && j < 72 ) || ( j >= 76 && j < 80 ) 	  
		        || ( j >= 84 && j < 88 ) || ( j >= 92 && j < 96 ) || ( j >= 100 && j < 104 ) || ( j >= 108 && j < 112 ) 
			|| ( j >= 116 && j < 120  ) 	|| ( j >= 124 && j < 128 ))) {
          
		   tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
           } else if ( i == 22 + k && ( (j<2) || (j>=4 && j<6)  || (j>=8 && j<10) || (j>=12 && j<14) || (j>=16 && j<18) || (j>=20 && j<22) || (j>=24 && j<26)
			|| (j>=28 && j<30) || (j>=32 && j<34) || (j>=36 && j<38) || (j>=40 && j<42) || (j>=44 && j<46) || (j>=48 && j<50) || (j>=52 && j<54) 	  
			|| (j>=56 && j<58) || (j>=60 && j<62) || (j>=64 && j<66) || (j>=68 && j<70) || (j>=72 && j<74) || (j>=76 && j<78) || (j>=80 && j<82) 
                	|| (j>=84 && j<86) || (j>=88 && j<90) || (j>=92 && j<94) || (j>=96 && j<98) || (j>=100 && j<102) || (j>=104 && j<106) || (j>=108 && j<110) || 
                	(j>=112 && j<114) || (j>=116 && j<118)     || (j>=120 && j<122) || (j>=124 && j<126)
			)) {
	    tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   } else if (i == 22 + k && ( (j>=2 && j<4) || (j>=6 && j<8) || (j>=10 && j<12) || (j>=14 && j<16) || (j>=18 && j<20) || (j>=22 && j<24) || (j>=26 && j<28)
			|| (j>=30 && j<32) || (j>=34 && j<36) || (j>=38 && j<40) || (j>=42 && j<44) || (j>=46 && j<48) || (j>=50 && j<52) 
			|| (j>=54 && j<56) || (j>=58 && j<60) || (j>=62 && j<64) || (j>=66 && j<68) || (j>=70 && j<72) || (j>=74 && j<76) 
			|| (j>=78 && j<80) || (j>=82 && j<84) || (j>=86 && j<88) || (j>=90 && j<92) || (j>=94 && j<96)
                        || (j>=98 && j<100) || (j>=102 && j<104) || (j>=106 && j<108) || (j>=110 && j<112) || (j>=114 && j<116) 
			|| (j>=118 && j<120) || (j>=122 && j<124) || (j>=126 && j<128) )) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 

	   } else if (i == 23 + k && j % 2 == 0) {
	   
	    tmp_neg = Cudd_Not(var); 
	    tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   
	   } else if (i == 23 + k && j % 2 == 1) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 

	   }
	  
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd_rec[j]);
      bdd_rec[j] = tmp;
    }
  }
    

    bdd9 = Cudd_bddOr(gbm,bdd_rec[0],bdd_rec[1]); 
    Cudd_Ref(bdd9);   
    
    for (k = 2;k<128;k++) {
    bdd9 = Cudd_bddOr(gbm,bdd9,bdd_rec[k]);
    }

     
     for(j = 0;j<128;j++){ 
       for (i = 16; i < 24; i++) {
          var = Cudd_bddIthVar(gbm,i); 
          if(i%8 ==  0) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec2[j]); 
	  }
	  else if(i == 17+k && j < 64 ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec2[j]); 
          }else if(i == 17+k && j >= 64) {
	  tmp = Cudd_bddAnd(gbm, var, bdd_rec2[j]); 
          }
	  else if ( (i == 18 + k) && ( ( j < 32 ) || ( j >= 64 && j < 96 ) ) ) {
          tmp_neg = Cudd_Not(var);
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec2[j]); 
          } else if ( i == 18 + k && ( ( j >= 32 && j < 64 ) || ( j >= 96 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec2[j]); 
	  } else if (i == 19 + k && ( (j<16) || (j>=32 && j<48) || (j>=64 && j<80) || (j>=96 && j<112) ) ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec2[j]); 
	  } else if (i == 19 + k && ( (j >= 16 && j < 32) || ( j >= 48 && j < 64 ) || ( j >= 80 && j < 96 ) || ( j >= 112 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec2[j]); 
          } else if ( i == 20 + k && ( ( j < 8 ) || ( j >= 16 && j < 24) || (j >= 32 && j < 40) || (j>=48 && j<56) || ( j >= 64 && j < 72 ) || 
		    (j >= 80 && j < 88) || (j >= 96 && j < 104) || (j>=112 && j<120) ) ) {
	   tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec2[j]); 
           } else if (i == 20 + k && ( ( j >= 8 && j < 16 ) || ( j >= 24 && j < 32 ) || ( j >= 40 && j < 48) || ( j >= 56 && j < 64) 
			|| (j>72 && j<=80) || (j>=88 && j<96) || (j>=104 && j<112) || (j>=120) ) ) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec2[j]);  
 	   } else if (i == 21 + k && ( (j < 4) || (j >= 8 && j < 12) || (j >= 16 && j < 20) || (j >= 24 && j < 28) || (j >= 32 && j < 36) || (j >= 40 && j < 44)
			|| (j >= 48 && j < 52)  || (j >= 56 && j < 60)|| (j >= 64 && j < 68) || (j >= 72 && j < 76) || (j >= 80 && j < 84) || (j >= 88 && j < 92) 	
			|| (j >= 96 && j < 100) || (j >= 104 && j < 108) || (j >= 112 && j < 116) || (j >= 120 && j < 124))) {
	   tmp_neg = Cudd_Not(var);
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec2[j]); 
	   
	   } else if (i == 21 + k && ( (j>=4 && j<8) || ( j >= 12 && j < 16 ) || ( j >= 20 && j < 24 ) || ( j >= 28 && j < 32 ) || ( j >= 36 && j < 40 ) 
			|| ( j >= 44 && j < 48 ) || ( j >= 52 && j < 56 ) || ( j >= 60 && j < 64 ) || ( j >= 68 && j < 72 ) || ( j >= 76 && j < 80 ) 	  
		        || ( j >= 84 && j < 88 ) || ( j >= 92 && j < 96 ) || ( j >= 100 && j < 104 ) || ( j >= 108 && j < 112 ) 
			|| ( j >= 116 && j < 120  ) 	|| ( j >= 124 && j < 128 ))) {
          
		   tmp = Cudd_bddAnd(gbm,var,bdd_rec2[j]); 
           } else if ( i == 22 + k && ( (j<2) || (j>=4 && j<6)  || (j>=8 && j<10) || (j>=12 && j<14) || (j>=16 && j<18) || (j>=20 && j<22) || (j>=24 && j<26)
			|| (j>=28 && j<30) || (j>=32 && j<34) || (j>=36 && j<38) || (j>=40 && j<42) || (j>=44 && j<46) || (j>=48 && j<50) || (j>=52 && j<54) 	  
			|| (j>=56 && j<58) || (j>=60 && j<62) || (j>=64 && j<66) || (j>=68 && j<70) || (j>=72 && j<74) || (j>=76 && j<78) || (j>=80 && j<82) 
                	|| (j>=84 && j<86) || (j>=88 && j<90) || (j>=92 && j<94) || (j>=96 && j<98) || (j>=100 && j<102) || (j>=104 && j<106) || (j>=108 && j<110) || 
                	(j>=112 && j<114) || (j>=116 && j<118)     || (j>=120 && j<122) || (j>=124 && j<126)
			)) {
	    tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec2[j]); 
	   } else if (i == 22 + k && ( (j>=2 && j<4) || (j>=6 && j<8) || (j>=10 && j<12) || (j>=14 && j<16) || (j>=18 && j<20) || (j>=22 && j<24) || (j>=26 && j<28)
			|| (j>=30 && j<32) || (j>=34 && j<36) || (j>=38 && j<40) || (j>=42 && j<44) || (j>=46 && j<48) || (j>=50 && j<52) 
			|| (j>=54 && j<56) || (j>=58 && j<60) || (j>=62 && j<64) || (j>=66 && j<68) || (j>=70 && j<72) || (j>=74 && j<76) 
			|| (j>=78 && j<80) || (j>=82 && j<84) || (j>=86 && j<88) || (j>=90 && j<92) || (j>=94 && j<96)
                        || (j>=98 && j<100) || (j>=102 && j<104) || (j>=106 && j<108) || (j>=110 && j<112) || (j>=114 && j<116) 
			|| (j>=118 && j<120) || (j>=122 && j<124) || (j>=126 && j<128) )) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec2[j]); 

	   } else if (i == 23 + k && j % 2 == 0) {
	   
	    tmp_neg = Cudd_Not(var); 
	    tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec2[j]); 
	   
	   } else if (i == 23 + k && j % 2 == 1) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec2[j]); 

	   }
	  
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd_rec2[j]);
      bdd_rec2[j] = tmp;
    }
  }   
    bdd3 = Cudd_bddOr(gbm,bdd_rec2[0],bdd_rec2[1]); 
    Cudd_Ref(bdd3);   
    
    for (k = 2;k<128;k++) {
    bdd3 = Cudd_bddOr(gbm,bdd3,bdd_rec2[k]);
    Cudd_Ref(bdd3);   
     }
    bdd2 = Cudd_bddOr(gbm,bdd9,bdd3);
    bdd = Cudd_bddAnd(gbm,bdd,bdd2);
    Cudd_Ref(bdd);   
*/

    DdNode* bdd71;
   
    bdd71 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd71); /*Increases the reference count of a node*/

     for (i = 16; i < 18; i++) {  
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd71); 
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd71);
      bdd71 = tmp;
    }
    
    
    bdd = Cudd_bddAnd(gbm,bdd,bdd71);
    Cudd_Ref(bdd);
    return bdd;

}




DdNode* scrivi_bdd_uno3 (DdManager *gbm, DdNode *bdd, DdNode * var) 
{
 
 DdNode* bdd_rec[128];
 DdNode* bdd_rec2[128];
 
 DdNode *bdd1, *bdd2, *bdd3, *bdd4, *bdd5, *bdd6, *bdd7, *bdd8, *bdd9,*bdd10,*tmp,*tmp_neg;
     bdd = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd); /*Increases the reference count of a node*/
     int i; 
     
     for(i = 0; i < 128; i++){
     bdd_rec2[i] = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd_rec2[i]); /*Increases the reference count of a node*/
     } 
     
     for(i = 0; i < 128; i++){
     bdd_rec[i] = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd_rec[i]); /*Increases the reference count of a node*/
     } 
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
     bdd6 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd6); /*Increases the reference count of a node*/
     bdd7 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd7); /*Increases the reference count of a node*/
     bdd8 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd8); /*Increases the reference count of a node*/
     bdd9 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd9); /*Increases the reference count of a node*/
  int j,k;
/*
     for(j = 0;j<128;j++){ 
       for (i = 24; i < 32; i++) {
          var = Cudd_bddIthVar(gbm,i); 
          if(i%8 ==  0) {
          //tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, var, bdd_rec[j]); 
	  }
	  else if(i == 25+k && j < 64 ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
          }else if(i == 25+k && j >= 64) {
	  tmp = Cudd_bddAnd(gbm, var, bdd_rec[j]); 
          }
	  else if ( (i == 26 + k) && ( ( j < 32 ) || ( j >= 64 && j < 96 ) ) ) {
          tmp_neg = Cudd_Not(var);
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
          } else if ( i == 26 + k && ( ( j >= 32 && j < 64 ) || ( j >= 96 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
	  } else if (i == 27 + k && ( (j<16) || (j>=32 && j<48) || (j>=64 && j<80) || (j>=96 && j<112) ) ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	  } else if (i == 27 + k && ( (j >= 16 && j < 32) || ( j >= 48 && j < 64 ) || ( j >= 80 && j < 96 ) || ( j >= 112 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
          } else if ( i == 28 + k && ( ( j < 8 ) || ( j >= 16 && j < 24) || (j >= 32 && j < 40) || (j>=48 && j<56) || ( j >= 64 && j < 72 ) || 
		    (j >= 80 && j < 88) || (j >= 96 && j < 104) || (j>=112 && j<120) ) ) {
	   tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
           } else if (i == 28 + k && ( ( j >= 8 && j < 16 ) || ( j >= 24 && j < 32 ) || ( j >= 40 && j < 48) || ( j >= 56 && j < 64) 
			|| (j>72 && j<=80) || (j>=88 && j<96) || (j>=104 && j<112) || (j>=120) ) ) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]);  
 	   } else if (i == 29 + k && ( (j < 4) || (j >= 8 && j < 12) || (j >= 16 && j < 20) || (j >= 24 && j < 28) || (j >= 32 && j < 36) || (j >= 40 && j < 44)
			|| (j >= 48 && j < 52)  || (j >= 56 && j < 60)|| (j >= 64 && j < 68) || (j >= 72 && j < 76) || (j >= 80 && j < 84) || (j >= 88 && j < 92) 	
			|| (j >= 96 && j < 100) || (j >= 104 && j < 108) || (j >= 112 && j < 116) || (j >= 120 && j < 124))) {
	   tmp_neg = Cudd_Not(var);
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   
	   } else if (i == 29 + k && ( (j>=4 && j<8) || ( j >= 12 && j < 16 ) || ( j >= 20 && j < 24 ) || ( j >= 28 && j < 32 ) || ( j >= 36 && j < 40 ) 
			|| ( j >= 44 && j < 48 ) || ( j >= 52 && j < 56 ) || ( j >= 60 && j < 64 ) || ( j >= 68 && j < 72 ) || ( j >= 76 && j < 80 ) 	  
		        || ( j >= 84 && j < 88 ) || ( j >= 92 && j < 96 ) || ( j >= 100 && j < 104 ) || ( j >= 108 && j < 112 ) 
			|| ( j >= 116 && j < 120  ) 	|| ( j >= 124 && j < 128 ))) {
          
		   tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
           } else if ( i == 30 + k && ( (j<2) || (j>=4 && j<6)  || (j>=8 && j<10) || (j>=12 && j<14) || (j>=16 && j<18) || (j>=20 && j<22) || (j>=24 && j<26)
			|| (j>=28 && j<30) || (j>=32 && j<34) || (j>=36 && j<38) || (j>=40 && j<42) || (j>=44 && j<46) || (j>=48 && j<50) || (j>=52 && j<54) 	  
			|| (j>=56 && j<58) || (j>=60 && j<62) || (j>=64 && j<66) || (j>=68 && j<70) || (j>=72 && j<74) || (j>=76 && j<78) || (j>=80 && j<82) 
                	|| (j>=84 && j<86) || (j>=88 && j<90) || (j>=92 && j<94) || (j>=96 && j<98) || (j>=100 && j<102) || (j>=104 && j<106) || (j>=108 && j<110) || 
                	(j>=112 && j<114) || (j>=116 && j<118)     || (j>=120 && j<122) || (j>=124 && j<126)
			)) {
	    tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   } else if (i == 30 + k && ( (j>=2 && j<4) || (j>=6 && j<8) || (j>=10 && j<12) || (j>=14 && j<16) || (j>=18 && j<20) || (j>=22 && j<24) || (j>=26 && j<28)
			|| (j>=30 && j<32) || (j>=34 && j<36) || (j>=38 && j<40) || (j>=42 && j<44) || (j>=46 && j<48) || (j>=50 && j<52) 
			|| (j>=54 && j<56) || (j>=58 && j<60) || (j>=62 && j<64) || (j>=66 && j<68) || (j>=70 && j<72) || (j>=74 && j<76) 
			|| (j>=78 && j<80) || (j>=82 && j<84) || (j>=86 && j<88) || (j>=90 && j<92) || (j>=94 && j<96)
                        || (j>=98 && j<100) || (j>=102 && j<104) || (j>=106 && j<108) || (j>=110 && j<112) || (j>=114 && j<116) 
			|| (j>=118 && j<120) || (j>=122 && j<124) || (j>=126 && j<128) )) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 

	   } else if (i == 31 + k && j % 2 == 0) {
	   
	    tmp_neg = Cudd_Not(var); 
	    tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   
	   } else if (i == 31 + k && j % 2 == 1) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 

	   }
	  
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd_rec[j]);
      bdd_rec[j] = tmp;
    }
  }
    
    bdd10 = Cudd_bddOr(gbm,bdd_rec[0],bdd_rec[1]); 
    Cudd_Ref(bdd10);   
    
    for (k = 2;k<128;k++) {
    bdd10 = Cudd_bddOr(gbm,bdd10,bdd_rec[k]);
    Cudd_Ref(bdd10);   
     }
    //bdd = Cudd_bddAnd(gbm,bdd,bdd10);
    //Cudd_Ref(bdd);   
     for(j = 0;j<128;j++){ 
       for (i = 24; i < 32; i++) {
          var = Cudd_bddIthVar(gbm,i); 
          if(i%8 ==  0) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec2[j]); 
	  }
	  else if(i == 25+k && j < 64 ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec2[j]); 
          }else if(i == 25+k && j >= 64) {
	  tmp = Cudd_bddAnd(gbm, var, bdd_rec2[j]); 
          }
	  else if ( (i == 26 + k) && ( ( j < 32 ) || ( j >= 64 && j < 96 ) ) ) {
          tmp_neg = Cudd_Not(var);
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec2[j]); 
          } else if ( i == 26 + k && ( ( j >= 32 && j < 64 ) || ( j >= 96 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec2[j]); 
	  } else if (i == 27 + k && ( (j<16) || (j>=32 && j<48) || (j>=64 && j<80) || (j>=96 && j<112) ) ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec2[j]); 
	  } else if (i == 27 + k && ( (j >= 16 && j < 32) || ( j >= 48 && j < 64 ) || ( j >= 80 && j < 96 ) || ( j >= 112 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec2[j]); 
          } else if ( i == 28 + k && ( ( j < 8 ) || ( j >= 16 && j < 24) || (j >= 32 && j < 40) || (j>=48 && j<56) || ( j >= 64 && j < 72 ) || 
		    (j >= 80 && j < 88) || (j >= 96 && j < 104) || (j>=112 && j<120) ) ) {
	   tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec2[j]); 
           } else if (i == 28 + k && ( ( j >= 8 && j < 16 ) || ( j >= 24 && j < 32 ) || ( j >= 40 && j < 48) || ( j >= 56 && j < 64) 
			|| (j>72 && j<=80) || (j>=88 && j<96) || (j>=104 && j<112) || (j>=120) ) ) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec2[j]);  
 	   } else if (i == 29 + k && ( (j < 4) || (j >= 8 && j < 12) || (j >= 16 && j < 20) || (j >= 24 && j < 28) || (j >= 32 && j < 36) || (j >= 40 && j < 44)
			|| (j >= 48 && j < 52)  || (j >= 56 && j < 60)|| (j >= 64 && j < 68) || (j >= 72 && j < 76) || (j >= 80 && j < 84) || (j >= 88 && j < 92) 	
			|| (j >= 96 && j < 100) || (j >= 104 && j < 108) || (j >= 112 && j < 116) || (j >= 120 && j < 124))) {
	   tmp_neg = Cudd_Not(var);
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec2[j]); 
	   
	   } else if (i == 29 + k && ( (j>=4 && j<8) || ( j >= 12 && j < 16 ) || ( j >= 20 && j < 24 ) || ( j >= 28 && j < 32 ) || ( j >= 36 && j < 40 ) 
			|| ( j >= 44 && j < 48 ) || ( j >= 52 && j < 56 ) || ( j >= 60 && j < 64 ) || ( j >= 68 && j < 72 ) || ( j >= 76 && j < 80 ) 	  
		        || ( j >= 84 && j < 88 ) || ( j >= 92 && j < 96 ) || ( j >= 100 && j < 104 ) || ( j >= 108 && j < 112 ) 
			|| ( j >= 116 && j < 120  ) 	|| ( j >= 124 && j < 128 ))) {
          
		   tmp = Cudd_bddAnd(gbm,var,bdd_rec2[j]); 
           } else if ( i == 30 + k && ( (j<2) || (j>=4 && j<6)  || (j>=8 && j<10) || (j>=12 && j<14) || (j>=16 && j<18) || (j>=20 && j<22) || (j>=24 && j<26)
			|| (j>=28 && j<30) || (j>=32 && j<34) || (j>=36 && j<38) || (j>=40 && j<42) || (j>=44 && j<46) || (j>=48 && j<50) || (j>=52 && j<54) 	  
			|| (j>=56 && j<58) || (j>=60 && j<62) || (j>=64 && j<66) || (j>=68 && j<70) || (j>=72 && j<74) || (j>=76 && j<78) || (j>=80 && j<82) 
                	|| (j>=84 && j<86) || (j>=88 && j<90) || (j>=92 && j<94) || (j>=96 && j<98) || (j>=100 && j<102) || (j>=104 && j<106) || (j>=108 && j<110) || 
                	(j>=112 && j<114) || (j>=116 && j<118)     || (j>=120 && j<122) || (j>=124 && j<126)
			)) {
	    tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec2[j]); 
	   } else if (i == 30 + k && ( (j>=2 && j<4) || (j>=6 && j<8) || (j>=10 && j<12) || (j>=14 && j<16) || (j>=18 && j<20) || (j>=22 && j<24) || (j>=26 && j<28)
			|| (j>=30 && j<32) || (j>=34 && j<36) || (j>=38 && j<40) || (j>=42 && j<44) || (j>=46 && j<48) || (j>=50 && j<52) 
			|| (j>=54 && j<56) || (j>=58 && j<60) || (j>=62 && j<64) || (j>=66 && j<68) || (j>=70 && j<72) || (j>=74 && j<76) 
			|| (j>=78 && j<80) || (j>=82 && j<84) || (j>=86 && j<88) || (j>=90 && j<92) || (j>=94 && j<96)
                        || (j>=98 && j<100) || (j>=102 && j<104) || (j>=106 && j<108) || (j>=110 && j<112) || (j>=114 && j<116) 
			|| (j>=118 && j<120) || (j>=122 && j<124) || (j>=126 && j<128) )) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec2[j]); 

	   } else if (i == 31 + k && j % 2 == 0) {
	   
	    tmp_neg = Cudd_Not(var); 
	    tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec2[j]); 
	   
	   } else if (i == 31 + k && j % 2 == 1) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec2[j]); 

	   }
	  
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd_rec2[j]);
      bdd_rec2[j] = tmp;
    }
  }
    
    bdd9 = Cudd_bddOr(gbm,bdd_rec2[0],bdd_rec2[1]); 
    Cudd_Ref(bdd9);   
    
    for (k = 2;k<128;k++) {
    bdd9 = Cudd_bddOr(gbm,bdd9,bdd_rec2[k]);
    Cudd_Ref(bdd9);   
     }

    bdd1 = Cudd_bddOr(gbm,bdd9,bdd10);
   // bdd = Cudd_bddAnd(gbm,bdd,bdd1);
    */
    DdNode* bdd71;
   
    bdd71 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd71); /*Increases the reference count of a node*/

     for (i = 16; i < 18; i++) {  
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd71); 
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd71);
      bdd71 = tmp;
    }
    
    
    bdd1 = Cudd_bddAnd(gbm,bdd1,bdd71);
    Cudd_Ref(bdd1);


    return bdd1;


}	



//FUNZIONI PUBREC
DdNode* scrivi_bdd_zero4 (DdManager *gbm, DdNode *bdd, DdNode * var) 
{
     DdNode* bdd_rec[128];
     DdNode* bdd_rec2[128];
     
     DdNode *bdd1, *bdd2, *bdd3, *bdd4, *bdd5, *bdd6, *bdd7, *bdd8, *bdd9,*tmp,*tmp_neg;
     bdd = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd); /*Increases the reference count of a node*/
     int i; 
     
     for(i = 0; i < 128; i++){
     bdd_rec[i] = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd_rec[i]); /*Increases the reference count of a node*/
     } 
     for(i = 0; i < 128; i++){
     bdd_rec2[i] = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd_rec2[i]); /*Increases the reference count of a node*/
     } 

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
     bdd6 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd6); /*Increases the reference count of a node*/
     bdd7 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd7); /*Increases the reference count of a node*/
     bdd8 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd8); /*Increases the reference count of a node*/
   
     
     for (i = 0; i < 8; i++) {
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
     if(i != 1 && i != 3) {
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

    Cudd_Ref(bdd);
    bdd = Cudd_bddAnd(gbm,bdd,bdd1);

    
    int j,k;
/*
     for(j = 0;j<128;j++){ 
       for (i = 16; i < 24; i++) {
          var = Cudd_bddIthVar(gbm,i); 
          if(i%8 ==  0) {
          //tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, var, bdd_rec[j]); 
	  }
	  else if(i == 17+k && j < 64 ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
          }else if(i == 17+k && j >= 64) {
	  tmp = Cudd_bddAnd(gbm, var, bdd_rec[j]); 
          }
	  else if ( (i == 18 + k) && ( ( j < 32 ) || ( j >= 64 && j < 96 ) ) ) {
          tmp_neg = Cudd_Not(var);
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
          } else if ( i == 18 + k && ( ( j >= 32 && j < 64 ) || ( j >= 96 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
	  } else if (i == 19 + k && ( (j<16) || (j>=32 && j<48) || (j>=64 && j<80) || (j>=96 && j<112) ) ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	  } else if (i == 19 + k && ( (j >= 16 && j < 32) || ( j >= 48 && j < 64 ) || ( j >= 80 && j < 96 ) || ( j >= 112 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
          } else if ( i == 20 + k && ( ( j < 8 ) || ( j >= 16 && j < 24) || (j >= 32 && j < 40) || (j>=48 && j<56) || ( j >= 64 && j < 72 ) || 
		    (j >= 80 && j < 88) || (j >= 96 && j < 104) || (j>=112 && j<120) ) ) {
	   tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
           } else if (i == 20 + k && ( ( j >= 8 && j < 16 ) || ( j >= 24 && j < 32 ) || ( j >= 40 && j < 48) || ( j >= 56 && j < 64) 
			|| (j>72 && j<=80) || (j>=88 && j<96) || (j>=104 && j<112) || (j>=120) ) ) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]);  
 	   } else if (i == 21 + k && ( (j < 4) || (j >= 8 && j < 12) || (j >= 16 && j < 20) || (j >= 24 && j < 28) || (j >= 32 && j < 36) || (j >= 40 && j < 44)
			|| (j >= 48 && j < 52)  || (j >= 56 && j < 60)|| (j >= 64 && j < 68) || (j >= 72 && j < 76) || (j >= 80 && j < 84) || (j >= 88 && j < 92) 	
			|| (j >= 96 && j < 100) || (j >= 104 && j < 108) || (j >= 112 && j < 116) || (j >= 120 && j < 124))) {
	   tmp_neg = Cudd_Not(var);
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   
	   } else if (i == 21 + k && ( (j>=4 && j<8) || ( j >= 12 && j < 16 ) || ( j >= 20 && j < 24 ) || ( j >= 28 && j < 32 ) || ( j >= 36 && j < 40 ) 
			|| ( j >= 44 && j < 48 ) || ( j >= 52 && j < 56 ) || ( j >= 60 && j < 64 ) || ( j >= 68 && j < 72 ) || ( j >= 76 && j < 80 ) 	  
		        || ( j >= 84 && j < 88 ) || ( j >= 92 && j < 96 ) || ( j >= 100 && j < 104 ) || ( j >= 108 && j < 112 ) 
			|| ( j >= 116 && j < 120  ) 	|| ( j >= 124 && j < 128 ))) {
          
		   tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
           } else if ( i == 22 + k && ( (j<2) || (j>=4 && j<6)  || (j>=8 && j<10) || (j>=12 && j<14) || (j>=16 && j<18) || (j>=20 && j<22) || (j>=24 && j<26)
			|| (j>=28 && j<30) || (j>=32 && j<34) || (j>=36 && j<38) || (j>=40 && j<42) || (j>=44 && j<46) || (j>=48 && j<50) || (j>=52 && j<54) 	  
			|| (j>=56 && j<58) || (j>=60 && j<62) || (j>=64 && j<66) || (j>=68 && j<70) || (j>=72 && j<74) || (j>=76 && j<78) || (j>=80 && j<82) 
                	|| (j>=84 && j<86) || (j>=88 && j<90) || (j>=92 && j<94) || (j>=96 && j<98) || (j>=100 && j<102) || (j>=104 && j<106) || (j>=108 && j<110) || 
                	(j>=112 && j<114) || (j>=116 && j<118)     || (j>=120 && j<122) || (j>=124 && j<126)
			)) {
	    tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   } else if (i == 22 + k && ( (j>=2 && j<4) || (j>=6 && j<8) || (j>=10 && j<12) || (j>=14 && j<16) || (j>=18 && j<20) || (j>=22 && j<24) || (j>=26 && j<28)
			|| (j>=30 && j<32) || (j>=34 && j<36) || (j>=38 && j<40) || (j>=42 && j<44) || (j>=46 && j<48) || (j>=50 && j<52) 
			|| (j>=54 && j<56) || (j>=58 && j<60) || (j>=62 && j<64) || (j>=66 && j<68) || (j>=70 && j<72) || (j>=74 && j<76) 
			|| (j>=78 && j<80) || (j>=82 && j<84) || (j>=86 && j<88) || (j>=90 && j<92) || (j>=94 && j<96)
                        || (j>=98 && j<100) || (j>=102 && j<104) || (j>=106 && j<108) || (j>=110 && j<112) || (j>=114 && j<116) 
			|| (j>=118 && j<120) || (j>=122 && j<124) || (j>=126 && j<128) )) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 

	   } else if (i == 23 + k && j % 2 == 0) {
	   
	    tmp_neg = Cudd_Not(var); 
	    tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   
	   } else if (i == 23 + k && j % 2 == 1) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 

	   }
	  
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd_rec[j]);
      bdd_rec[j] = tmp;
    }
  }
    

    bdd9 = Cudd_bddOr(gbm,bdd_rec[0],bdd_rec[1]); 
    Cudd_Ref(bdd1);   
    
    for (k = 2;k<128;k++) {
    bdd9 = Cudd_bddOr(gbm,bdd9,bdd_rec[k]);
    }

     
     for(j = 0;j<128;j++){ 
       for (i = 16; i < 24; i++) {
          var = Cudd_bddIthVar(gbm,i); 
          if(i%8 ==  0) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec2[j]); 
	  }
	  else if(i == 17+k && j < 64 ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec2[j]); 
          }else if(i == 17+k && j >= 64) {
	  tmp = Cudd_bddAnd(gbm, var, bdd_rec2[j]); 
          }
	  else if ( (i == 18 + k) && ( ( j < 32 ) || ( j >= 64 && j < 96 ) ) ) {
          tmp_neg = Cudd_Not(var);
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec2[j]); 
          } else if ( i == 18 + k && ( ( j >= 32 && j < 64 ) || ( j >= 96 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec2[j]); 
	  } else if (i == 19 + k && ( (j<16) || (j>=32 && j<48) || (j>=64 && j<80) || (j>=96 && j<112) ) ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec2[j]); 
	  } else if (i == 19 + k && ( (j >= 16 && j < 32) || ( j >= 48 && j < 64 ) || ( j >= 80 && j < 96 ) || ( j >= 112 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec2[j]); 
          } else if ( i == 20 + k && ( ( j < 8 ) || ( j >= 16 && j < 24) || (j >= 32 && j < 40) || (j>=48 && j<56) || ( j >= 64 && j < 72 ) || 
		    (j >= 80 && j < 88) || (j >= 96 && j < 104) || (j>=112 && j<120) ) ) {
	   tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec2[j]); 
           } else if (i == 20 + k && ( ( j >= 8 && j < 16 ) || ( j >= 24 && j < 32 ) || ( j >= 40 && j < 48) || ( j >= 56 && j < 64) 
			|| (j>72 && j<=80) || (j>=88 && j<96) || (j>=104 && j<112) || (j>=120) ) ) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec2[j]);  
 	   } else if (i == 21 + k && ( (j < 4) || (j >= 8 && j < 12) || (j >= 16 && j < 20) || (j >= 24 && j < 28) || (j >= 32 && j < 36) || (j >= 40 && j < 44)
			|| (j >= 48 && j < 52)  || (j >= 56 && j < 60)|| (j >= 64 && j < 68) || (j >= 72 && j < 76) || (j >= 80 && j < 84) || (j >= 88 && j < 92) 	
			|| (j >= 96 && j < 100) || (j >= 104 && j < 108) || (j >= 112 && j < 116) || (j >= 120 && j < 124))) {
	   tmp_neg = Cudd_Not(var);
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec2[j]); 
	   
	   } else if (i == 21 + k && ( (j>=4 && j<8) || ( j >= 12 && j < 16 ) || ( j >= 20 && j < 24 ) || ( j >= 28 && j < 32 ) || ( j >= 36 && j < 40 ) 
			|| ( j >= 44 && j < 48 ) || ( j >= 52 && j < 56 ) || ( j >= 60 && j < 64 ) || ( j >= 68 && j < 72 ) || ( j >= 76 && j < 80 ) 	  
		        || ( j >= 84 && j < 88 ) || ( j >= 92 && j < 96 ) || ( j >= 100 && j < 104 ) || ( j >= 108 && j < 112 ) 
			|| ( j >= 116 && j < 120  ) 	|| ( j >= 124 && j < 128 ))) {
          
		   tmp = Cudd_bddAnd(gbm,var,bdd_rec2[j]); 
           } else if ( i == 22 + k && ( (j<2) || (j>=4 && j<6)  || (j>=8 && j<10) || (j>=12 && j<14) || (j>=16 && j<18) || (j>=20 && j<22) || (j>=24 && j<26)
			|| (j>=28 && j<30) || (j>=32 && j<34) || (j>=36 && j<38) || (j>=40 && j<42) || (j>=44 && j<46) || (j>=48 && j<50) || (j>=52 && j<54) 	  
			|| (j>=56 && j<58) || (j>=60 && j<62) || (j>=64 && j<66) || (j>=68 && j<70) || (j>=72 && j<74) || (j>=76 && j<78) || (j>=80 && j<82) 
                	|| (j>=84 && j<86) || (j>=88 && j<90) || (j>=92 && j<94) || (j>=96 && j<98) || (j>=100 && j<102) || (j>=104 && j<106) || (j>=108 && j<110) || 
                	(j>=112 && j<114) || (j>=116 && j<118)     || (j>=120 && j<122) || (j>=124 && j<126)
			)) {
	    tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec2[j]); 
	   } else if (i == 22 + k && ( (j>=2 && j<4) || (j>=6 && j<8) || (j>=10 && j<12) || (j>=14 && j<16) || (j>=18 && j<20) || (j>=22 && j<24) || (j>=26 && j<28)
			|| (j>=30 && j<32) || (j>=34 && j<36) || (j>=38 && j<40) || (j>=42 && j<44) || (j>=46 && j<48) || (j>=50 && j<52) 
			|| (j>=54 && j<56) || (j>=58 && j<60) || (j>=62 && j<64) || (j>=66 && j<68) || (j>=70 && j<72) || (j>=74 && j<76) 
			|| (j>=78 && j<80) || (j>=82 && j<84) || (j>=86 && j<88) || (j>=90 && j<92) || (j>=94 && j<96)
                        || (j>=98 && j<100) || (j>=102 && j<104) || (j>=106 && j<108) || (j>=110 && j<112) || (j>=114 && j<116) 
			|| (j>=118 && j<120) || (j>=122 && j<124) || (j>=126 && j<128) )) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec2[j]); 

	   } else if (i == 23 + k && j % 2 == 0) {
	   
	    tmp_neg = Cudd_Not(var); 
	    tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec2[j]); 
	   
	   } else if (i == 23 + k && j % 2 == 1) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec2[j]); 

	   }
	  
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd_rec2[j]);
      bdd_rec2[j] = tmp;
    }
  }   
    bdd3 = Cudd_bddOr(gbm,bdd_rec2[0],bdd_rec2[1]); 
    Cudd_Ref(bdd3);   
    
    for (k = 2;k<128;k++) {
    bdd3 = Cudd_bddOr(gbm,bdd3,bdd_rec2[k]);
    Cudd_Ref(bdd3);   
     }
    bdd2 = Cudd_bddOr(gbm,bdd9,bdd3);
    bdd = Cudd_bddAnd(gbm,bdd,bdd2);
    Cudd_Ref(bdd);   
*/
    DdNode* bdd71;
   
    bdd71 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd71); /*Increases the reference count of a node*/

     for (i = 16; i < 18; i++) {  
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd71); 
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd71);
      bdd71 = tmp;
    }
    
    
    bdd = Cudd_bddAnd(gbm,bdd,bdd71);
    Cudd_Ref(bdd);

    return bdd;

}




DdNode* scrivi_bdd_uno4 (DdManager *gbm, DdNode *bdd, DdNode * var) 
{
 
 DdNode* bdd_rec[128];
 DdNode* bdd_rec2[128];
 
 DdNode *bdd1, *bdd2, *bdd3, *bdd4, *bdd5, *bdd6, *bdd7, *bdd8, *bdd9,*bdd10,*tmp,*tmp_neg;
     bdd = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd); /*Increases the reference count of a node*/
     int i; 
     
     for(i = 0; i < 128; i++){
     bdd_rec2[i] = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd_rec2[i]); /*Increases the reference count of a node*/
     } 
     
     for(i = 0; i < 128; i++){
     bdd_rec[i] = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd_rec[i]); /*Increases the reference count of a node*/
     } 
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
     bdd6 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd6); /*Increases the reference count of a node*/
     bdd7 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd7); /*Increases the reference count of a node*/
     bdd8 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd8); /*Increases the reference count of a node*/
     bdd9 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd9); /*Increases the reference count of a node*/
  int j,k;
/*
     for(j = 0;j<128;j++){ 
       for (i = 24; i < 32; i++) {
          var = Cudd_bddIthVar(gbm,i); 
          if(i%8 ==  0) {
          //tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, var, bdd_rec[j]); 
	  }
	  else if(i == 25+k && j < 64 ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
          }else if(i == 25+k && j >= 64) {
	  tmp = Cudd_bddAnd(gbm, var, bdd_rec[j]); 
          }
	  else if ( (i == 26 + k) && ( ( j < 32 ) || ( j >= 64 && j < 96 ) ) ) {
          tmp_neg = Cudd_Not(var);
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
          } else if ( i == 26 + k && ( ( j >= 32 && j < 64 ) || ( j >= 96 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
	  } else if (i == 27 + k && ( (j<16) || (j>=32 && j<48) || (j>=64 && j<80) || (j>=96 && j<112) ) ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	  } else if (i == 27 + k && ( (j >= 16 && j < 32) || ( j >= 48 && j < 64 ) || ( j >= 80 && j < 96 ) || ( j >= 112 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
          } else if ( i == 28 + k && ( ( j < 8 ) || ( j >= 16 && j < 24) || (j >= 32 && j < 40) || (j>=48 && j<56) || ( j >= 64 && j < 72 ) || 
		    (j >= 80 && j < 88) || (j >= 96 && j < 104) || (j>=112 && j<120) ) ) {
	   tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
           } else if (i == 28 + k && ( ( j >= 8 && j < 16 ) || ( j >= 24 && j < 32 ) || ( j >= 40 && j < 48) || ( j >= 56 && j < 64) 
			|| (j>72 && j<=80) || (j>=88 && j<96) || (j>=104 && j<112) || (j>=120) ) ) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]);  
 	   } else if (i == 29 + k && ( (j < 4) || (j >= 8 && j < 12) || (j >= 16 && j < 20) || (j >= 24 && j < 28) || (j >= 32 && j < 36) || (j >= 40 && j < 44)
			|| (j >= 48 && j < 52)  || (j >= 56 && j < 60)|| (j >= 64 && j < 68) || (j >= 72 && j < 76) || (j >= 80 && j < 84) || (j >= 88 && j < 92) 	
			|| (j >= 96 && j < 100) || (j >= 104 && j < 108) || (j >= 112 && j < 116) || (j >= 120 && j < 124))) {
	   tmp_neg = Cudd_Not(var);
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   
	   } else if (i == 29 + k && ( (j>=4 && j<8) || ( j >= 12 && j < 16 ) || ( j >= 20 && j < 24 ) || ( j >= 28 && j < 32 ) || ( j >= 36 && j < 40 ) 
			|| ( j >= 44 && j < 48 ) || ( j >= 52 && j < 56 ) || ( j >= 60 && j < 64 ) || ( j >= 68 && j < 72 ) || ( j >= 76 && j < 80 ) 	  
		        || ( j >= 84 && j < 88 ) || ( j >= 92 && j < 96 ) || ( j >= 100 && j < 104 ) || ( j >= 108 && j < 112 ) 
			|| ( j >= 116 && j < 120  ) 	|| ( j >= 124 && j < 128 ))) {
          
		   tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
           } else if ( i == 30 + k && ( (j<2) || (j>=4 && j<6)  || (j>=8 && j<10) || (j>=12 && j<14) || (j>=16 && j<18) || (j>=20 && j<22) || (j>=24 && j<26)
			|| (j>=28 && j<30) || (j>=32 && j<34) || (j>=36 && j<38) || (j>=40 && j<42) || (j>=44 && j<46) || (j>=48 && j<50) || (j>=52 && j<54) 	  
			|| (j>=56 && j<58) || (j>=60 && j<62) || (j>=64 && j<66) || (j>=68 && j<70) || (j>=72 && j<74) || (j>=76 && j<78) || (j>=80 && j<82) 
                	|| (j>=84 && j<86) || (j>=88 && j<90) || (j>=92 && j<94) || (j>=96 && j<98) || (j>=100 && j<102) || (j>=104 && j<106) || (j>=108 && j<110) || 
                	(j>=112 && j<114) || (j>=116 && j<118)     || (j>=120 && j<122) || (j>=124 && j<126)
			)) {
	    tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   } else if (i == 30 + k && ( (j>=2 && j<4) || (j>=6 && j<8) || (j>=10 && j<12) || (j>=14 && j<16) || (j>=18 && j<20) || (j>=22 && j<24) || (j>=26 && j<28)
			|| (j>=30 && j<32) || (j>=34 && j<36) || (j>=38 && j<40) || (j>=42 && j<44) || (j>=46 && j<48) || (j>=50 && j<52) 
			|| (j>=54 && j<56) || (j>=58 && j<60) || (j>=62 && j<64) || (j>=66 && j<68) || (j>=70 && j<72) || (j>=74 && j<76) 
			|| (j>=78 && j<80) || (j>=82 && j<84) || (j>=86 && j<88) || (j>=90 && j<92) || (j>=94 && j<96)
                        || (j>=98 && j<100) || (j>=102 && j<104) || (j>=106 && j<108) || (j>=110 && j<112) || (j>=114 && j<116) 
			|| (j>=118 && j<120) || (j>=122 && j<124) || (j>=126 && j<128) )) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 

	   } else if (i == 31 + k && j % 2 == 0) {
	   
	    tmp_neg = Cudd_Not(var); 
	    tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   
	   } else if (i == 31 + k && j % 2 == 1) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 

	   }
	  
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd_rec[j]);
      bdd_rec[j] = tmp;
    }
  }
    
    bdd10 = Cudd_bddOr(gbm,bdd_rec[0],bdd_rec[1]); 
    Cudd_Ref(bdd10);   
    
    for (k = 2;k<128;k++) {
    bdd10 = Cudd_bddOr(gbm,bdd10,bdd_rec[k]);
    Cudd_Ref(bdd10);   
     }
    //bdd = Cudd_bddAnd(gbm,bdd,bdd10);
    //Cudd_Ref(bdd);   
     for(j = 0;j<128;j++){ 
       for (i = 24; i < 32; i++) {
          var = Cudd_bddIthVar(gbm,i); 
          if(i%8 ==  0) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec2[j]); 
	  }
	  else if(i == 25+k && j < 64 ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec2[j]); 
          }else if(i == 25+k && j >= 64) {
	  tmp = Cudd_bddAnd(gbm, var, bdd_rec2[j]); 
          }
	  else if ( (i == 26 + k) && ( ( j < 32 ) || ( j >= 64 && j < 96 ) ) ) {
          tmp_neg = Cudd_Not(var);
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec2[j]); 
          } else if ( i == 26 + k && ( ( j >= 32 && j < 64 ) || ( j >= 96 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec2[j]); 
	  } else if (i == 27 + k && ( (j<16) || (j>=32 && j<48) || (j>=64 && j<80) || (j>=96 && j<112) ) ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec2[j]); 
	  } else if (i == 27 + k && ( (j >= 16 && j < 32) || ( j >= 48 && j < 64 ) || ( j >= 80 && j < 96 ) || ( j >= 112 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec2[j]); 
          } else if ( i == 28 + k && ( ( j < 8 ) || ( j >= 16 && j < 24) || (j >= 32 && j < 40) || (j>=48 && j<56) || ( j >= 64 && j < 72 ) || 
		    (j >= 80 && j < 88) || (j >= 96 && j < 104) || (j>=112 && j<120) ) ) {
	   tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec2[j]); 
           } else if (i == 28 + k && ( ( j >= 8 && j < 16 ) || ( j >= 24 && j < 32 ) || ( j >= 40 && j < 48) || ( j >= 56 && j < 64) 
			|| (j>72 && j<=80) || (j>=88 && j<96) || (j>=104 && j<112) || (j>=120) ) ) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec2[j]);  
 	   } else if (i == 29 + k && ( (j < 4) || (j >= 8 && j < 12) || (j >= 16 && j < 20) || (j >= 24 && j < 28) || (j >= 32 && j < 36) || (j >= 40 && j < 44)
			|| (j >= 48 && j < 52)  || (j >= 56 && j < 60)|| (j >= 64 && j < 68) || (j >= 72 && j < 76) || (j >= 80 && j < 84) || (j >= 88 && j < 92) 	
			|| (j >= 96 && j < 100) || (j >= 104 && j < 108) || (j >= 112 && j < 116) || (j >= 120 && j < 124))) {
	   tmp_neg = Cudd_Not(var);
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec2[j]); 
	   
	   } else if (i == 29 + k && ( (j>=4 && j<8) || ( j >= 12 && j < 16 ) || ( j >= 20 && j < 24 ) || ( j >= 28 && j < 32 ) || ( j >= 36 && j < 40 ) 
			|| ( j >= 44 && j < 48 ) || ( j >= 52 && j < 56 ) || ( j >= 60 && j < 64 ) || ( j >= 68 && j < 72 ) || ( j >= 76 && j < 80 ) 	  
		        || ( j >= 84 && j < 88 ) || ( j >= 92 && j < 96 ) || ( j >= 100 && j < 104 ) || ( j >= 108 && j < 112 ) 
			|| ( j >= 116 && j < 120  ) 	|| ( j >= 124 && j < 128 ))) {
          
		   tmp = Cudd_bddAnd(gbm,var,bdd_rec2[j]); 
           } else if ( i == 30 + k && ( (j<2) || (j>=4 && j<6)  || (j>=8 && j<10) || (j>=12 && j<14) || (j>=16 && j<18) || (j>=20 && j<22) || (j>=24 && j<26)
			|| (j>=28 && j<30) || (j>=32 && j<34) || (j>=36 && j<38) || (j>=40 && j<42) || (j>=44 && j<46) || (j>=48 && j<50) || (j>=52 && j<54) 	  
			|| (j>=56 && j<58) || (j>=60 && j<62) || (j>=64 && j<66) || (j>=68 && j<70) || (j>=72 && j<74) || (j>=76 && j<78) || (j>=80 && j<82) 
                	|| (j>=84 && j<86) || (j>=88 && j<90) || (j>=92 && j<94) || (j>=96 && j<98) || (j>=100 && j<102) || (j>=104 && j<106) || (j>=108 && j<110) || 
                	(j>=112 && j<114) || (j>=116 && j<118)     || (j>=120 && j<122) || (j>=124 && j<126)
			)) {
	    tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec2[j]); 
	   } else if (i == 30 + k && ( (j>=2 && j<4) || (j>=6 && j<8) || (j>=10 && j<12) || (j>=14 && j<16) || (j>=18 && j<20) || (j>=22 && j<24) || (j>=26 && j<28)
			|| (j>=30 && j<32) || (j>=34 && j<36) || (j>=38 && j<40) || (j>=42 && j<44) || (j>=46 && j<48) || (j>=50 && j<52) 
			|| (j>=54 && j<56) || (j>=58 && j<60) || (j>=62 && j<64) || (j>=66 && j<68) || (j>=70 && j<72) || (j>=74 && j<76) 
			|| (j>=78 && j<80) || (j>=82 && j<84) || (j>=86 && j<88) || (j>=90 && j<92) || (j>=94 && j<96)
                        || (j>=98 && j<100) || (j>=102 && j<104) || (j>=106 && j<108) || (j>=110 && j<112) || (j>=114 && j<116) 
			|| (j>=118 && j<120) || (j>=122 && j<124) || (j>=126 && j<128) )) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec2[j]); 

	   } else if (i == 31 + k && j % 2 == 0) {
	   
	    tmp_neg = Cudd_Not(var); 
	    tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec2[j]); 
	   
	   } else if (i == 31 + k && j % 2 == 1) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec2[j]); 

	   }
	  
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd_rec2[j]);
      bdd_rec2[j] = tmp;
    }
  }
    
    bdd9 = Cudd_bddOr(gbm,bdd_rec2[0],bdd_rec2[1]); 
    Cudd_Ref(bdd9);   
    
    for (k = 2;k<128;k++) {
    bdd9 = Cudd_bddOr(gbm,bdd9,bdd_rec2[k]);
    Cudd_Ref(bdd9);   
     }

    bdd1 = Cudd_bddOr(gbm,bdd9,bdd10);
   // bdd = Cudd_bddAnd(gbm,bdd,bdd1);
  */  DdNode* bdd71;
   
    bdd71 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd71); /*Increases the reference count of a node*/

     for (i = 16; i < 18; i++) {  
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd71); 
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd71);
      bdd71 = tmp;
    }
    
    
    bdd1 = Cudd_bddAnd(gbm,bdd1,bdd71);
    Cudd_Ref(bdd1);

    return bdd1;


}	

//FUNZIONI PUBREL

DdNode* scrivi_bdd_zero5 (DdManager *gbm, DdNode *bdd, DdNode * var) 
{
     DdNode* bdd_rec[128];
     DdNode* bdd_rec2[128];
     
     DdNode *bdd1, *bdd2, *bdd3, *bdd4, *bdd5, *bdd6, *bdd7, *bdd8, *bdd9,*tmp,*tmp_neg;
     bdd = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd); /*Increases the reference count of a node*/
     int i; 
     
     for(i = 0; i < 128; i++){
     bdd_rec[i] = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd_rec[i]); /*Increases the reference count of a node*/
     } 
     for(i = 0; i < 128; i++){
     bdd_rec2[i] = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd_rec2[i]); /*Increases the reference count of a node*/
     } 

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
     bdd6 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd6); /*Increases the reference count of a node*/
     bdd7 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd7); /*Increases the reference count of a node*/
     bdd8 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd8); /*Increases the reference count of a node*/
   
     
     for (i = 0; i < 8; i++) {
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
     if(i != 1 && i != 2 && i != 6) {
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

    Cudd_Ref(bdd);
    bdd = Cudd_bddAnd(gbm,bdd,bdd1);

   /* 
    int j,k;

     for(j = 0;j<128;j++){ 
       for (i = 16; i < 24; i++) {
          var = Cudd_bddIthVar(gbm,i); 
          if(i%8 ==  0) {
          //tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, var, bdd_rec[j]); 
	  }
	  else if(i == 17+k && j < 64 ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
          }else if(i == 17+k && j >= 64) {
	  tmp = Cudd_bddAnd(gbm, var, bdd_rec[j]); 
          }
	  else if ( (i == 18 + k) && ( ( j < 32 ) || ( j >= 64 && j < 96 ) ) ) {
          tmp_neg = Cudd_Not(var);
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
          } else if ( i == 18 + k && ( ( j >= 32 && j < 64 ) || ( j >= 96 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
	  } else if (i == 19 + k && ( (j<16) || (j>=32 && j<48) || (j>=64 && j<80) || (j>=96 && j<112) ) ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	  } else if (i == 19 + k && ( (j >= 16 && j < 32) || ( j >= 48 && j < 64 ) || ( j >= 80 && j < 96 ) || ( j >= 112 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
          } else if ( i == 20 + k && ( ( j < 8 ) || ( j >= 16 && j < 24) || (j >= 32 && j < 40) || (j>=48 && j<56) || ( j >= 64 && j < 72 ) || 
		    (j >= 80 && j < 88) || (j >= 96 && j < 104) || (j>=112 && j<120) ) ) {
	   tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
           } else if (i == 20 + k && ( ( j >= 8 && j < 16 ) || ( j >= 24 && j < 32 ) || ( j >= 40 && j < 48) || ( j >= 56 && j < 64) 
			|| (j>72 && j<=80) || (j>=88 && j<96) || (j>=104 && j<112) || (j>=120) ) ) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]);  
 	   } else if (i == 21 + k && ( (j < 4) || (j >= 8 && j < 12) || (j >= 16 && j < 20) || (j >= 24 && j < 28) || (j >= 32 && j < 36) || (j >= 40 && j < 44)
			|| (j >= 48 && j < 52)  || (j >= 56 && j < 60)|| (j >= 64 && j < 68) || (j >= 72 && j < 76) || (j >= 80 && j < 84) || (j >= 88 && j < 92) 	
			|| (j >= 96 && j < 100) || (j >= 104 && j < 108) || (j >= 112 && j < 116) || (j >= 120 && j < 124))) {
	   tmp_neg = Cudd_Not(var);
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   
	   } else if (i == 21 + k && ( (j>=4 && j<8) || ( j >= 12 && j < 16 ) || ( j >= 20 && j < 24 ) || ( j >= 28 && j < 32 ) || ( j >= 36 && j < 40 ) 
			|| ( j >= 44 && j < 48 ) || ( j >= 52 && j < 56 ) || ( j >= 60 && j < 64 ) || ( j >= 68 && j < 72 ) || ( j >= 76 && j < 80 ) 	  
		        || ( j >= 84 && j < 88 ) || ( j >= 92 && j < 96 ) || ( j >= 100 && j < 104 ) || ( j >= 108 && j < 112 ) 
			|| ( j >= 116 && j < 120  ) 	|| ( j >= 124 && j < 128 ))) {
          
		   tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
           } else if ( i == 22 + k && ( (j<2) || (j>=4 && j<6)  || (j>=8 && j<10) || (j>=12 && j<14) || (j>=16 && j<18) || (j>=20 && j<22) || (j>=24 && j<26)
			|| (j>=28 && j<30) || (j>=32 && j<34) || (j>=36 && j<38) || (j>=40 && j<42) || (j>=44 && j<46) || (j>=48 && j<50) || (j>=52 && j<54) 	  
			|| (j>=56 && j<58) || (j>=60 && j<62) || (j>=64 && j<66) || (j>=68 && j<70) || (j>=72 && j<74) || (j>=76 && j<78) || (j>=80 && j<82) 
                	|| (j>=84 && j<86) || (j>=88 && j<90) || (j>=92 && j<94) || (j>=96 && j<98) || (j>=100 && j<102) || (j>=104 && j<106) || (j>=108 && j<110) || 
                	(j>=112 && j<114) || (j>=116 && j<118)     || (j>=120 && j<122) || (j>=124 && j<126)
			)) {
	    tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   } else if (i == 22 + k && ( (j>=2 && j<4) || (j>=6 && j<8) || (j>=10 && j<12) || (j>=14 && j<16) || (j>=18 && j<20) || (j>=22 && j<24) || (j>=26 && j<28)
			|| (j>=30 && j<32) || (j>=34 && j<36) || (j>=38 && j<40) || (j>=42 && j<44) || (j>=46 && j<48) || (j>=50 && j<52) 
			|| (j>=54 && j<56) || (j>=58 && j<60) || (j>=62 && j<64) || (j>=66 && j<68) || (j>=70 && j<72) || (j>=74 && j<76) 
			|| (j>=78 && j<80) || (j>=82 && j<84) || (j>=86 && j<88) || (j>=90 && j<92) || (j>=94 && j<96)
                        || (j>=98 && j<100) || (j>=102 && j<104) || (j>=106 && j<108) || (j>=110 && j<112) || (j>=114 && j<116) 
			|| (j>=118 && j<120) || (j>=122 && j<124) || (j>=126 && j<128) )) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 

	   } else if (i == 23 + k && j % 2 == 0) {
	   
	    tmp_neg = Cudd_Not(var); 
	    tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   
	   } else if (i == 23 + k && j % 2 == 1) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 

	   }
	  
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd_rec[j]);
      bdd_rec[j] = tmp;
    }
  }
    

    bdd9 = Cudd_bddOr(gbm,bdd_rec[0],bdd_rec[1]); 
    Cudd_Ref(bdd1);   
    
    for (k = 2;k<128;k++) {
    bdd9 = Cudd_bddOr(gbm,bdd9,bdd_rec[k]);
    }

     
     for(j = 0;j<128;j++){ 
       for (i = 16; i < 24; i++) {
          var = Cudd_bddIthVar(gbm,i); 
          if(i%8 ==  0) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec2[j]); 
	  }
	  else if(i == 17+k && j < 64 ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec2[j]); 
          }else if(i == 17+k && j >= 64) {
	  tmp = Cudd_bddAnd(gbm, var, bdd_rec2[j]); 
          }
	  else if ( (i == 18 + k) && ( ( j < 32 ) || ( j >= 64 && j < 96 ) ) ) {
          tmp_neg = Cudd_Not(var);
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec2[j]); 
          } else if ( i == 18 + k && ( ( j >= 32 && j < 64 ) || ( j >= 96 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec2[j]); 
	  } else if (i == 19 + k && ( (j<16) || (j>=32 && j<48) || (j>=64 && j<80) || (j>=96 && j<112) ) ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec2[j]); 
	  } else if (i == 19 + k && ( (j >= 16 && j < 32) || ( j >= 48 && j < 64 ) || ( j >= 80 && j < 96 ) || ( j >= 112 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec2[j]); 
          } else if ( i == 20 + k && ( ( j < 8 ) || ( j >= 16 && j < 24) || (j >= 32 && j < 40) || (j>=48 && j<56) || ( j >= 64 && j < 72 ) || 
		    (j >= 80 && j < 88) || (j >= 96 && j < 104) || (j>=112 && j<120) ) ) {
	   tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec2[j]); 
           } else if (i == 20 + k && ( ( j >= 8 && j < 16 ) || ( j >= 24 && j < 32 ) || ( j >= 40 && j < 48) || ( j >= 56 && j < 64) 
			|| (j>72 && j<=80) || (j>=88 && j<96) || (j>=104 && j<112) || (j>=120) ) ) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec2[j]);  
 	   } else if (i == 21 + k && ( (j < 4) || (j >= 8 && j < 12) || (j >= 16 && j < 20) || (j >= 24 && j < 28) || (j >= 32 && j < 36) || (j >= 40 && j < 44)
			|| (j >= 48 && j < 52)  || (j >= 56 && j < 60)|| (j >= 64 && j < 68) || (j >= 72 && j < 76) || (j >= 80 && j < 84) || (j >= 88 && j < 92) 	
			|| (j >= 96 && j < 100) || (j >= 104 && j < 108) || (j >= 112 && j < 116) || (j >= 120 && j < 124))) {
	   tmp_neg = Cudd_Not(var);
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec2[j]); 
	   
	   } else if (i == 21 + k && ( (j>=4 && j<8) || ( j >= 12 && j < 16 ) || ( j >= 20 && j < 24 ) || ( j >= 28 && j < 32 ) || ( j >= 36 && j < 40 ) 
			|| ( j >= 44 && j < 48 ) || ( j >= 52 && j < 56 ) || ( j >= 60 && j < 64 ) || ( j >= 68 && j < 72 ) || ( j >= 76 && j < 80 ) 	  
		        || ( j >= 84 && j < 88 ) || ( j >= 92 && j < 96 ) || ( j >= 100 && j < 104 ) || ( j >= 108 && j < 112 ) 
			|| ( j >= 116 && j < 120  ) 	|| ( j >= 124 && j < 128 ))) {
          
		   tmp = Cudd_bddAnd(gbm,var,bdd_rec2[j]); 
           } else if ( i == 22 + k && ( (j<2) || (j>=4 && j<6)  || (j>=8 && j<10) || (j>=12 && j<14) || (j>=16 && j<18) || (j>=20 && j<22) || (j>=24 && j<26)
			|| (j>=28 && j<30) || (j>=32 && j<34) || (j>=36 && j<38) || (j>=40 && j<42) || (j>=44 && j<46) || (j>=48 && j<50) || (j>=52 && j<54) 	  
			|| (j>=56 && j<58) || (j>=60 && j<62) || (j>=64 && j<66) || (j>=68 && j<70) || (j>=72 && j<74) || (j>=76 && j<78) || (j>=80 && j<82) 
                	|| (j>=84 && j<86) || (j>=88 && j<90) || (j>=92 && j<94) || (j>=96 && j<98) || (j>=100 && j<102) || (j>=104 && j<106) || (j>=108 && j<110) || 
                	(j>=112 && j<114) || (j>=116 && j<118)     || (j>=120 && j<122) || (j>=124 && j<126)
			)) {
	    tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec2[j]); 
	   } else if (i == 22 + k && ( (j>=2 && j<4) || (j>=6 && j<8) || (j>=10 && j<12) || (j>=14 && j<16) || (j>=18 && j<20) || (j>=22 && j<24) || (j>=26 && j<28)
			|| (j>=30 && j<32) || (j>=34 && j<36) || (j>=38 && j<40) || (j>=42 && j<44) || (j>=46 && j<48) || (j>=50 && j<52) 
			|| (j>=54 && j<56) || (j>=58 && j<60) || (j>=62 && j<64) || (j>=66 && j<68) || (j>=70 && j<72) || (j>=74 && j<76) 
			|| (j>=78 && j<80) || (j>=82 && j<84) || (j>=86 && j<88) || (j>=90 && j<92) || (j>=94 && j<96)
                        || (j>=98 && j<100) || (j>=102 && j<104) || (j>=106 && j<108) || (j>=110 && j<112) || (j>=114 && j<116) 
			|| (j>=118 && j<120) || (j>=122 && j<124) || (j>=126 && j<128) )) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec2[j]); 

	   } else if (i == 23 + k && j % 2 == 0) {
	   
	    tmp_neg = Cudd_Not(var); 
	    tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec2[j]); 
	   
	   } else if (i == 23 + k && j % 2 == 1) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec2[j]); 

	   }
	  
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd_rec2[j]);
      bdd_rec2[j] = tmp;
    }
  }   
    bdd3 = Cudd_bddOr(gbm,bdd_rec2[0],bdd_rec2[1]); 
    Cudd_Ref(bdd3);   
    
    for (k = 2;k<128;k++) {
    bdd3 = Cudd_bddOr(gbm,bdd3,bdd_rec2[k]);
    Cudd_Ref(bdd3);   
     }
    bdd2 = Cudd_bddOr(gbm,bdd9,bdd3);
    bdd = Cudd_bddAnd(gbm,bdd,bdd2);
    Cudd_Ref(bdd);   
*/
    DdNode* bdd71;
   
    bdd71 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd71); /*Increases the reference count of a node*/

     for (i = 16; i < 18; i++) {  
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd71); 
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd71);
      bdd71 = tmp;
    }
    
    
    bdd = Cudd_bddAnd(gbm,bdd,bdd71);
    Cudd_Ref(bdd);

    return bdd;

}




DdNode* scrivi_bdd_uno5 (DdManager *gbm, DdNode *bdd, DdNode * var) 
{
 
 DdNode* bdd_rec[128];
 DdNode* bdd_rec2[128];
 
DdNode *bdd1, *bdd2, *bdd3, *bdd4, *bdd5, *bdd6, *bdd7, *bdd8, *bdd9,*bdd10,*tmp,*tmp_neg;
     bdd = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd); /*Increases the reference count of a node*/
     int i; 
     
     for(i = 0; i < 128; i++){
     bdd_rec2[i] = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd_rec2[i]); /*Increases the reference count of a node*/
     } 
     
     for(i = 0; i < 128; i++){
     bdd_rec[i] = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd_rec[i]); /*Increases the reference count of a node*/
     } 
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
     bdd6 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd6); /*Increases the reference count of a node*/
     bdd7 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd7); /*Increases the reference count of a node*/
     bdd8 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd8); /*Increases the reference count of a node*/
     bdd9 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd9); /*Increases the reference count of a node*/
  int j,k;
/*
     for(j = 0;j<128;j++){ 
       for (i = 24; i < 32; i++) {
          var = Cudd_bddIthVar(gbm,i); 
          if(i%8 ==  0) {
          //tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, var, bdd_rec[j]); 
	  }
	  else if(i == 25+k && j < 64 ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
          }else if(i == 25+k && j >= 64) {
	  tmp = Cudd_bddAnd(gbm, var, bdd_rec[j]); 
          }
	  else if ( (i == 26 + k) && ( ( j < 32 ) || ( j >= 64 && j < 96 ) ) ) {
          tmp_neg = Cudd_Not(var);
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
          } else if ( i == 26 + k && ( ( j >= 32 && j < 64 ) || ( j >= 96 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
	  } else if (i == 27 + k && ( (j<16) || (j>=32 && j<48) || (j>=64 && j<80) || (j>=96 && j<112) ) ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	  } else if (i == 27 + k && ( (j >= 16 && j < 32) || ( j >= 48 && j < 64 ) || ( j >= 80 && j < 96 ) || ( j >= 112 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
          } else if ( i == 28 + k && ( ( j < 8 ) || ( j >= 16 && j < 24) || (j >= 32 && j < 40) || (j>=48 && j<56) || ( j >= 64 && j < 72 ) || 
		    (j >= 80 && j < 88) || (j >= 96 && j < 104) || (j>=112 && j<120) ) ) {
	   tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
           } else if (i == 28 + k && ( ( j >= 8 && j < 16 ) || ( j >= 24 && j < 32 ) || ( j >= 40 && j < 48) || ( j >= 56 && j < 64) 
			|| (j>72 && j<=80) || (j>=88 && j<96) || (j>=104 && j<112) || (j>=120) ) ) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]);  
 	   } else if (i == 29 + k && ( (j < 4) || (j >= 8 && j < 12) || (j >= 16 && j < 20) || (j >= 24 && j < 28) || (j >= 32 && j < 36) || (j >= 40 && j < 44)
			|| (j >= 48 && j < 52)  || (j >= 56 && j < 60)|| (j >= 64 && j < 68) || (j >= 72 && j < 76) || (j >= 80 && j < 84) || (j >= 88 && j < 92) 	
			|| (j >= 96 && j < 100) || (j >= 104 && j < 108) || (j >= 112 && j < 116) || (j >= 120 && j < 124))) {
	   tmp_neg = Cudd_Not(var);
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   
	   } else if (i == 29 + k && ( (j>=4 && j<8) || ( j >= 12 && j < 16 ) || ( j >= 20 && j < 24 ) || ( j >= 28 && j < 32 ) || ( j >= 36 && j < 40 ) 
			|| ( j >= 44 && j < 48 ) || ( j >= 52 && j < 56 ) || ( j >= 60 && j < 64 ) || ( j >= 68 && j < 72 ) || ( j >= 76 && j < 80 ) 	  
		        || ( j >= 84 && j < 88 ) || ( j >= 92 && j < 96 ) || ( j >= 100 && j < 104 ) || ( j >= 108 && j < 112 ) 
			|| ( j >= 116 && j < 120  ) 	|| ( j >= 124 && j < 128 ))) {
          
		   tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
           } else if ( i == 30 + k && ( (j<2) || (j>=4 && j<6)  || (j>=8 && j<10) || (j>=12 && j<14) || (j>=16 && j<18) || (j>=20 && j<22) || (j>=24 && j<26)
			|| (j>=28 && j<30) || (j>=32 && j<34) || (j>=36 && j<38) || (j>=40 && j<42) || (j>=44 && j<46) || (j>=48 && j<50) || (j>=52 && j<54) 	  
			|| (j>=56 && j<58) || (j>=60 && j<62) || (j>=64 && j<66) || (j>=68 && j<70) || (j>=72 && j<74) || (j>=76 && j<78) || (j>=80 && j<82) 
                	|| (j>=84 && j<86) || (j>=88 && j<90) || (j>=92 && j<94) || (j>=96 && j<98) || (j>=100 && j<102) || (j>=104 && j<106) || (j>=108 && j<110) || 
                	(j>=112 && j<114) || (j>=116 && j<118)     || (j>=120 && j<122) || (j>=124 && j<126)
			)) {
	    tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   } else if (i == 30 + k && ( (j>=2 && j<4) || (j>=6 && j<8) || (j>=10 && j<12) || (j>=14 && j<16) || (j>=18 && j<20) || (j>=22 && j<24) || (j>=26 && j<28)
			|| (j>=30 && j<32) || (j>=34 && j<36) || (j>=38 && j<40) || (j>=42 && j<44) || (j>=46 && j<48) || (j>=50 && j<52) 
			|| (j>=54 && j<56) || (j>=58 && j<60) || (j>=62 && j<64) || (j>=66 && j<68) || (j>=70 && j<72) || (j>=74 && j<76) 
			|| (j>=78 && j<80) || (j>=82 && j<84) || (j>=86 && j<88) || (j>=90 && j<92) || (j>=94 && j<96)
                        || (j>=98 && j<100) || (j>=102 && j<104) || (j>=106 && j<108) || (j>=110 && j<112) || (j>=114 && j<116) 
			|| (j>=118 && j<120) || (j>=122 && j<124) || (j>=126 && j<128) )) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 

	   } else if (i == 31 + k && j % 2 == 0) {
	   
	    tmp_neg = Cudd_Not(var); 
	    tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   
	   } else if (i == 31 + k && j % 2 == 1) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 

	   }
	  
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd_rec[j]);
      bdd_rec[j] = tmp;
    }
  }
    
    bdd10 = Cudd_bddOr(gbm,bdd_rec[0],bdd_rec[1]); 
    Cudd_Ref(bdd10);   
    
    for (k = 2;k<128;k++) {
    bdd10 = Cudd_bddOr(gbm,bdd10,bdd_rec[k]);
    Cudd_Ref(bdd10);   
     }
    //bdd = Cudd_bddAnd(gbm,bdd,bdd10);
    //Cudd_Ref(bdd);   
     for(j = 0;j<128;j++){ 
       for (i = 24; i < 32; i++) {
          var = Cudd_bddIthVar(gbm,i); 
          if(i%8 ==  0) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec2[j]); 
	  }
	  else if(i == 25+k && j < 64 ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec2[j]); 
          }else if(i == 25+k && j >= 64) {
	  tmp = Cudd_bddAnd(gbm, var, bdd_rec2[j]); 
          }
	  else if ( (i == 26 + k) && ( ( j < 32 ) || ( j >= 64 && j < 96 ) ) ) {
          tmp_neg = Cudd_Not(var);
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec2[j]); 
          } else if ( i == 26 + k && ( ( j >= 32 && j < 64 ) || ( j >= 96 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec2[j]); 
	  } else if (i == 27 + k && ( (j<16) || (j>=32 && j<48) || (j>=64 && j<80) || (j>=96 && j<112) ) ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec2[j]); 
	  } else if (i == 27 + k && ( (j >= 16 && j < 32) || ( j >= 48 && j < 64 ) || ( j >= 80 && j < 96 ) || ( j >= 112 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec2[j]); 
          } else if ( i == 28 + k && ( ( j < 8 ) || ( j >= 16 && j < 24) || (j >= 32 && j < 40) || (j>=48 && j<56) || ( j >= 64 && j < 72 ) || 
		    (j >= 80 && j < 88) || (j >= 96 && j < 104) || (j>=112 && j<120) ) ) {
	   tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec2[j]); 
           } else if (i == 28 + k && ( ( j >= 8 && j < 16 ) || ( j >= 24 && j < 32 ) || ( j >= 40 && j < 48) || ( j >= 56 && j < 64) 
			|| (j>72 && j<=80) || (j>=88 && j<96) || (j>=104 && j<112) || (j>=120) ) ) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec2[j]);  
 	   } else if (i == 29 + k && ( (j < 4) || (j >= 8 && j < 12) || (j >= 16 && j < 20) || (j >= 24 && j < 28) || (j >= 32 && j < 36) || (j >= 40 && j < 44)
			|| (j >= 48 && j < 52)  || (j >= 56 && j < 60)|| (j >= 64 && j < 68) || (j >= 72 && j < 76) || (j >= 80 && j < 84) || (j >= 88 && j < 92) 	
			|| (j >= 96 && j < 100) || (j >= 104 && j < 108) || (j >= 112 && j < 116) || (j >= 120 && j < 124))) {
	   tmp_neg = Cudd_Not(var);
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec2[j]); 
	   
	   } else if (i == 29 + k && ( (j>=4 && j<8) || ( j >= 12 && j < 16 ) || ( j >= 20 && j < 24 ) || ( j >= 28 && j < 32 ) || ( j >= 36 && j < 40 ) 
			|| ( j >= 44 && j < 48 ) || ( j >= 52 && j < 56 ) || ( j >= 60 && j < 64 ) || ( j >= 68 && j < 72 ) || ( j >= 76 && j < 80 ) 	  
		        || ( j >= 84 && j < 88 ) || ( j >= 92 && j < 96 ) || ( j >= 100 && j < 104 ) || ( j >= 108 && j < 112 ) 
			|| ( j >= 116 && j < 120  ) 	|| ( j >= 124 && j < 128 ))) {
          
		   tmp = Cudd_bddAnd(gbm,var,bdd_rec2[j]); 
           } else if ( i == 30 + k && ( (j<2) || (j>=4 && j<6)  || (j>=8 && j<10) || (j>=12 && j<14) || (j>=16 && j<18) || (j>=20 && j<22) || (j>=24 && j<26)
			|| (j>=28 && j<30) || (j>=32 && j<34) || (j>=36 && j<38) || (j>=40 && j<42) || (j>=44 && j<46) || (j>=48 && j<50) || (j>=52 && j<54) 	  
			|| (j>=56 && j<58) || (j>=60 && j<62) || (j>=64 && j<66) || (j>=68 && j<70) || (j>=72 && j<74) || (j>=76 && j<78) || (j>=80 && j<82) 
                	|| (j>=84 && j<86) || (j>=88 && j<90) || (j>=92 && j<94) || (j>=96 && j<98) || (j>=100 && j<102) || (j>=104 && j<106) || (j>=108 && j<110) || 
                	(j>=112 && j<114) || (j>=116 && j<118)     || (j>=120 && j<122) || (j>=124 && j<126)
			)) {
	    tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec2[j]); 
	   } else if (i == 30 + k && ( (j>=2 && j<4) || (j>=6 && j<8) || (j>=10 && j<12) || (j>=14 && j<16) || (j>=18 && j<20) || (j>=22 && j<24) || (j>=26 && j<28)
			|| (j>=30 && j<32) || (j>=34 && j<36) || (j>=38 && j<40) || (j>=42 && j<44) || (j>=46 && j<48) || (j>=50 && j<52) 
			|| (j>=54 && j<56) || (j>=58 && j<60) || (j>=62 && j<64) || (j>=66 && j<68) || (j>=70 && j<72) || (j>=74 && j<76) 
			|| (j>=78 && j<80) || (j>=82 && j<84) || (j>=86 && j<88) || (j>=90 && j<92) || (j>=94 && j<96)
                        || (j>=98 && j<100) || (j>=102 && j<104) || (j>=106 && j<108) || (j>=110 && j<112) || (j>=114 && j<116) 
			|| (j>=118 && j<120) || (j>=122 && j<124) || (j>=126 && j<128) )) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec2[j]); 

	   } else if (i == 31 + k && j % 2 == 0) {
	   
	    tmp_neg = Cudd_Not(var); 
	    tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec2[j]); 
	   
	   } else if (i == 31 + k && j % 2 == 1) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec2[j]); 

	   }
	  
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd_rec2[j]);
      bdd_rec2[j] = tmp;
    }
  }
    
    bdd9 = Cudd_bddOr(gbm,bdd_rec2[0],bdd_rec2[1]); 
    Cudd_Ref(bdd9);   
    
    for (k = 2;k<128;k++) {
    bdd9 = Cudd_bddOr(gbm,bdd9,bdd_rec2[k]);
    Cudd_Ref(bdd9);   
     }

    bdd1 = Cudd_bddOr(gbm,bdd9,bdd10);
   // bdd = Cudd_bddAnd(gbm,bdd,bdd1);
*/
    DdNode* bdd71;
   
    bdd71 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd71); /*Increases the reference count of a node*/

     for (i = 16; i < 18; i++) {  
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd71); 
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd71);
      bdd71 = tmp;
    }
    
    
    bdd = Cudd_bddAnd(gbm,bdd,bdd71);
    Cudd_Ref(bdd);


    return bdd1;


}	

//FUNZIONI PUBCOMP


DdNode* scrivi_bdd_zero6 (DdManager *gbm, DdNode *bdd, DdNode * var) 
{
     DdNode* bdd_rec[128];
     DdNode* bdd_rec2[128];
     
     DdNode *bdd1, *bdd2, *bdd3, *bdd4, *bdd5, *bdd6, *bdd7, *bdd8, *bdd9,*tmp,*tmp_neg;
     bdd = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd); /*Increases the reference count of a node*/
     int i; 
     
     for(i = 0; i < 128; i++){
     bdd_rec[i] = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd_rec[i]); /*Increases the reference count of a node*/
     } 
     for(i = 0; i < 128; i++){
     bdd_rec2[i] = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd_rec2[i]); /*Increases the reference count of a node*/
     } 

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
     bdd6 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd6); /*Increases the reference count of a node*/
     bdd7 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd7); /*Increases the reference count of a node*/
     bdd8 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd8); /*Increases the reference count of a node*/
   
     
     for (i = 0; i < 8; i++) {
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
     if(i != 1 && i != 2 && i != 3) {
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

    Cudd_Ref(bdd);
    bdd = Cudd_bddAnd(gbm,bdd,bdd1);

    
    int j,k;
/*
     for(j = 0;j<128;j++){ 
       for (i = 16; i < 24; i++) {
          var = Cudd_bddIthVar(gbm,i); 
          if(i%8 ==  0) {
          //tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, var, bdd_rec[j]); 
	  }
	  else if(i == 17+k && j < 64 ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
          }else if(i == 17+k && j >= 64) {
	  tmp = Cudd_bddAnd(gbm, var, bdd_rec[j]); 
          }
	  else if ( (i == 18 + k) && ( ( j < 32 ) || ( j >= 64 && j < 96 ) ) ) {
          tmp_neg = Cudd_Not(var);
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
          } else if ( i == 18 + k && ( ( j >= 32 && j < 64 ) || ( j >= 96 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
	  } else if (i == 19 + k && ( (j<16) || (j>=32 && j<48) || (j>=64 && j<80) || (j>=96 && j<112) ) ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	  } else if (i == 19 + k && ( (j >= 16 && j < 32) || ( j >= 48 && j < 64 ) || ( j >= 80 && j < 96 ) || ( j >= 112 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
          } else if ( i == 20 + k && ( ( j < 8 ) || ( j >= 16 && j < 24) || (j >= 32 && j < 40) || (j>=48 && j<56) || ( j >= 64 && j < 72 ) || 
		    (j >= 80 && j < 88) || (j >= 96 && j < 104) || (j>=112 && j<120) ) ) {
	   tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
           } else if (i == 20 + k && ( ( j >= 8 && j < 16 ) || ( j >= 24 && j < 32 ) || ( j >= 40 && j < 48) || ( j >= 56 && j < 64) 
			|| (j>72 && j<=80) || (j>=88 && j<96) || (j>=104 && j<112) || (j>=120) ) ) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]);  
 	   } else if (i == 21 + k && ( (j < 4) || (j >= 8 && j < 12) || (j >= 16 && j < 20) || (j >= 24 && j < 28) || (j >= 32 && j < 36) || (j >= 40 && j < 44)
			|| (j >= 48 && j < 52)  || (j >= 56 && j < 60)|| (j >= 64 && j < 68) || (j >= 72 && j < 76) || (j >= 80 && j < 84) || (j >= 88 && j < 92) 	
			|| (j >= 96 && j < 100) || (j >= 104 && j < 108) || (j >= 112 && j < 116) || (j >= 120 && j < 124))) {
	   tmp_neg = Cudd_Not(var);
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   
	   } else if (i == 21 + k && ( (j>=4 && j<8) || ( j >= 12 && j < 16 ) || ( j >= 20 && j < 24 ) || ( j >= 28 && j < 32 ) || ( j >= 36 && j < 40 ) 
			|| ( j >= 44 && j < 48 ) || ( j >= 52 && j < 56 ) || ( j >= 60 && j < 64 ) || ( j >= 68 && j < 72 ) || ( j >= 76 && j < 80 ) 	  
		        || ( j >= 84 && j < 88 ) || ( j >= 92 && j < 96 ) || ( j >= 100 && j < 104 ) || ( j >= 108 && j < 112 ) 
			|| ( j >= 116 && j < 120  ) 	|| ( j >= 124 && j < 128 ))) {
          
		   tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
           } else if ( i == 22 + k && ( (j<2) || (j>=4 && j<6)  || (j>=8 && j<10) || (j>=12 && j<14) || (j>=16 && j<18) || (j>=20 && j<22) || (j>=24 && j<26)
			|| (j>=28 && j<30) || (j>=32 && j<34) || (j>=36 && j<38) || (j>=40 && j<42) || (j>=44 && j<46) || (j>=48 && j<50) || (j>=52 && j<54) 	  
			|| (j>=56 && j<58) || (j>=60 && j<62) || (j>=64 && j<66) || (j>=68 && j<70) || (j>=72 && j<74) || (j>=76 && j<78) || (j>=80 && j<82) 
                	|| (j>=84 && j<86) || (j>=88 && j<90) || (j>=92 && j<94) || (j>=96 && j<98) || (j>=100 && j<102) || (j>=104 && j<106) || (j>=108 && j<110) || 
                	(j>=112 && j<114) || (j>=116 && j<118)     || (j>=120 && j<122) || (j>=124 && j<126)
			)) {
	    tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   } else if (i == 22 + k && ( (j>=2 && j<4) || (j>=6 && j<8) || (j>=10 && j<12) || (j>=14 && j<16) || (j>=18 && j<20) || (j>=22 && j<24) || (j>=26 && j<28)
			|| (j>=30 && j<32) || (j>=34 && j<36) || (j>=38 && j<40) || (j>=42 && j<44) || (j>=46 && j<48) || (j>=50 && j<52) 
			|| (j>=54 && j<56) || (j>=58 && j<60) || (j>=62 && j<64) || (j>=66 && j<68) || (j>=70 && j<72) || (j>=74 && j<76) 
			|| (j>=78 && j<80) || (j>=82 && j<84) || (j>=86 && j<88) || (j>=90 && j<92) || (j>=94 && j<96)
                        || (j>=98 && j<100) || (j>=102 && j<104) || (j>=106 && j<108) || (j>=110 && j<112) || (j>=114 && j<116) 
			|| (j>=118 && j<120) || (j>=122 && j<124) || (j>=126 && j<128) )) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 

	   } else if (i == 23 + k && j % 2 == 0) {
	   
	    tmp_neg = Cudd_Not(var); 
	    tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   
	   } else if (i == 23 + k && j % 2 == 1) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 

	   }
	  
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd_rec[j]);
      bdd_rec[j] = tmp;
    }
  }
    

    bdd9 = Cudd_bddOr(gbm,bdd_rec[0],bdd_rec[1]); 
    Cudd_Ref(bdd1);   
    
    for (k = 2;k<128;k++) {
    bdd9 = Cudd_bddOr(gbm,bdd9,bdd_rec[k]);
    }

     
     for(j = 0;j<128;j++){ 
       for (i = 16; i < 24; i++) {
          var = Cudd_bddIthVar(gbm,i); 
          if(i%8 ==  0) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec2[j]); 
	  }
	  else if(i == 17+k && j < 64 ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec2[j]); 
          }else if(i == 17+k && j >= 64) {
	  tmp = Cudd_bddAnd(gbm, var, bdd_rec2[j]); 
          }
	  else if ( (i == 18 + k) && ( ( j < 32 ) || ( j >= 64 && j < 96 ) ) ) {
          tmp_neg = Cudd_Not(var);
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec2[j]); 
          } else if ( i == 18 + k && ( ( j >= 32 && j < 64 ) || ( j >= 96 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec2[j]); 
	  } else if (i == 19 + k && ( (j<16) || (j>=32 && j<48) || (j>=64 && j<80) || (j>=96 && j<112) ) ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec2[j]); 
	  } else if (i == 19 + k && ( (j >= 16 && j < 32) || ( j >= 48 && j < 64 ) || ( j >= 80 && j < 96 ) || ( j >= 112 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec2[j]); 
          } else if ( i == 20 + k && ( ( j < 8 ) || ( j >= 16 && j < 24) || (j >= 32 && j < 40) || (j>=48 && j<56) || ( j >= 64 && j < 72 ) || 
		    (j >= 80 && j < 88) || (j >= 96 && j < 104) || (j>=112 && j<120) ) ) {
	   tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec2[j]); 
           } else if (i == 20 + k && ( ( j >= 8 && j < 16 ) || ( j >= 24 && j < 32 ) || ( j >= 40 && j < 48) || ( j >= 56 && j < 64) 
			|| (j>72 && j<=80) || (j>=88 && j<96) || (j>=104 && j<112) || (j>=120) ) ) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec2[j]);  
 	   } else if (i == 21 + k && ( (j < 4) || (j >= 8 && j < 12) || (j >= 16 && j < 20) || (j >= 24 && j < 28) || (j >= 32 && j < 36) || (j >= 40 && j < 44)
			|| (j >= 48 && j < 52)  || (j >= 56 && j < 60)|| (j >= 64 && j < 68) || (j >= 72 && j < 76) || (j >= 80 && j < 84) || (j >= 88 && j < 92) 	
			|| (j >= 96 && j < 100) || (j >= 104 && j < 108) || (j >= 112 && j < 116) || (j >= 120 && j < 124))) {
	   tmp_neg = Cudd_Not(var);
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec2[j]); 
	   
	   } else if (i == 21 + k && ( (j>=4 && j<8) || ( j >= 12 && j < 16 ) || ( j >= 20 && j < 24 ) || ( j >= 28 && j < 32 ) || ( j >= 36 && j < 40 ) 
			|| ( j >= 44 && j < 48 ) || ( j >= 52 && j < 56 ) || ( j >= 60 && j < 64 ) || ( j >= 68 && j < 72 ) || ( j >= 76 && j < 80 ) 	  
		        || ( j >= 84 && j < 88 ) || ( j >= 92 && j < 96 ) || ( j >= 100 && j < 104 ) || ( j >= 108 && j < 112 ) 
			|| ( j >= 116 && j < 120  ) 	|| ( j >= 124 && j < 128 ))) {
          
		   tmp = Cudd_bddAnd(gbm,var,bdd_rec2[j]); 
           } else if ( i == 22 + k && ( (j<2) || (j>=4 && j<6)  || (j>=8 && j<10) || (j>=12 && j<14) || (j>=16 && j<18) || (j>=20 && j<22) || (j>=24 && j<26)
			|| (j>=28 && j<30) || (j>=32 && j<34) || (j>=36 && j<38) || (j>=40 && j<42) || (j>=44 && j<46) || (j>=48 && j<50) || (j>=52 && j<54) 	  
			|| (j>=56 && j<58) || (j>=60 && j<62) || (j>=64 && j<66) || (j>=68 && j<70) || (j>=72 && j<74) || (j>=76 && j<78) || (j>=80 && j<82) 
                	|| (j>=84 && j<86) || (j>=88 && j<90) || (j>=92 && j<94) || (j>=96 && j<98) || (j>=100 && j<102) || (j>=104 && j<106) || (j>=108 && j<110) || 
                	(j>=112 && j<114) || (j>=116 && j<118)     || (j>=120 && j<122) || (j>=124 && j<126)
			)) {
	    tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec2[j]); 
	   } else if (i == 22 + k && ( (j>=2 && j<4) || (j>=6 && j<8) || (j>=10 && j<12) || (j>=14 && j<16) || (j>=18 && j<20) || (j>=22 && j<24) || (j>=26 && j<28)
			|| (j>=30 && j<32) || (j>=34 && j<36) || (j>=38 && j<40) || (j>=42 && j<44) || (j>=46 && j<48) || (j>=50 && j<52) 
			|| (j>=54 && j<56) || (j>=58 && j<60) || (j>=62 && j<64) || (j>=66 && j<68) || (j>=70 && j<72) || (j>=74 && j<76) 
			|| (j>=78 && j<80) || (j>=82 && j<84) || (j>=86 && j<88) || (j>=90 && j<92) || (j>=94 && j<96)
                        || (j>=98 && j<100) || (j>=102 && j<104) || (j>=106 && j<108) || (j>=110 && j<112) || (j>=114 && j<116) 
			|| (j>=118 && j<120) || (j>=122 && j<124) || (j>=126 && j<128) )) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec2[j]); 

	   } else if (i == 23 + k && j % 2 == 0) {
	   
	    tmp_neg = Cudd_Not(var); 
	    tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec2[j]); 
	   
	   } else if (i == 23 + k && j % 2 == 1) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec2[j]); 

	   }
	  
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd_rec2[j]);
      bdd_rec2[j] = tmp;
    }
  }   
    bdd3 = Cudd_bddOr(gbm,bdd_rec2[0],bdd_rec2[1]); 
    Cudd_Ref(bdd3);   
    
    for (k = 2;k<128;k++) {
    bdd3 = Cudd_bddOr(gbm,bdd3,bdd_rec2[k]);
    Cudd_Ref(bdd3);   
     }
    bdd2 = Cudd_bddOr(gbm,bdd9,bdd3);
    bdd = Cudd_bddAnd(gbm,bdd,bdd2);
    Cudd_Ref(bdd);   
*/
    DdNode* bdd71;
   
    bdd71 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd71); /*Increases the reference count of a node*/

     for (i = 16; i < 18; i++) {  
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd71); 
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd71);
      bdd71 = tmp;
    }
    
    
    bdd = Cudd_bddAnd(gbm,bdd,bdd71);
    Cudd_Ref(bdd);

    return bdd;

}




DdNode* scrivi_bdd_uno6 (DdManager *gbm, DdNode *bdd, DdNode * var) 
{
 
 DdNode* bdd_rec[128];
 DdNode* bdd_rec2[128];
 
 DdNode *bdd1, *bdd2, *bdd3, *bdd4, *bdd5, *bdd6, *bdd7, *bdd8, *bdd9,*bdd10,*tmp,*tmp_neg;
     bdd = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd); /*Increases the reference count of a node*/
     int i; 
     
     for(i = 0; i < 128; i++){
     bdd_rec2[i] = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd_rec2[i]); /*Increases the reference count of a node*/
     } 
     
     for(i = 0; i < 128; i++){
     bdd_rec[i] = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd_rec[i]); /*Increases the reference count of a node*/
     } 
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
     bdd6 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd6); /*Increases the reference count of a node*/
     bdd7 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd7); /*Increases the reference count of a node*/
     bdd8 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd8); /*Increases the reference count of a node*/
     bdd9 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd9); /*Increases the reference count of a node*/
  int j,k;

  /*
     for(j = 0;j<128;j++){ 
       for (i = 24; i < 32; i++) {
          var = Cudd_bddIthVar(gbm,i); 
          if(i%8 ==  0) {
          //tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, var, bdd_rec[j]); 
	  }
	  else if(i == 25+k && j < 64 ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
          }else if(i == 25+k && j >= 64) {
	  tmp = Cudd_bddAnd(gbm, var, bdd_rec[j]); 
          }
	  else if ( (i == 26 + k) && ( ( j < 32 ) || ( j >= 64 && j < 96 ) ) ) {
          tmp_neg = Cudd_Not(var);
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
          } else if ( i == 26 + k && ( ( j >= 32 && j < 64 ) || ( j >= 96 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
	  } else if (i == 27 + k && ( (j<16) || (j>=32 && j<48) || (j>=64 && j<80) || (j>=96 && j<112) ) ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	  } else if (i == 27 + k && ( (j >= 16 && j < 32) || ( j >= 48 && j < 64 ) || ( j >= 80 && j < 96 ) || ( j >= 112 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
          } else if ( i == 28 + k && ( ( j < 8 ) || ( j >= 16 && j < 24) || (j >= 32 && j < 40) || (j>=48 && j<56) || ( j >= 64 && j < 72 ) || 
		    (j >= 80 && j < 88) || (j >= 96 && j < 104) || (j>=112 && j<120) ) ) {
	   tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
           } else if (i == 28 + k && ( ( j >= 8 && j < 16 ) || ( j >= 24 && j < 32 ) || ( j >= 40 && j < 48) || ( j >= 56 && j < 64) 
			|| (j>72 && j<=80) || (j>=88 && j<96) || (j>=104 && j<112) || (j>=120) ) ) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]);  
 	   } else if (i == 29 + k && ( (j < 4) || (j >= 8 && j < 12) || (j >= 16 && j < 20) || (j >= 24 && j < 28) || (j >= 32 && j < 36) || (j >= 40 && j < 44)
			|| (j >= 48 && j < 52)  || (j >= 56 && j < 60)|| (j >= 64 && j < 68) || (j >= 72 && j < 76) || (j >= 80 && j < 84) || (j >= 88 && j < 92) 	
			|| (j >= 96 && j < 100) || (j >= 104 && j < 108) || (j >= 112 && j < 116) || (j >= 120 && j < 124))) {
	   tmp_neg = Cudd_Not(var);
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   
	   } else if (i == 29 + k && ( (j>=4 && j<8) || ( j >= 12 && j < 16 ) || ( j >= 20 && j < 24 ) || ( j >= 28 && j < 32 ) || ( j >= 36 && j < 40 ) 
			|| ( j >= 44 && j < 48 ) || ( j >= 52 && j < 56 ) || ( j >= 60 && j < 64 ) || ( j >= 68 && j < 72 ) || ( j >= 76 && j < 80 ) 	  
		        || ( j >= 84 && j < 88 ) || ( j >= 92 && j < 96 ) || ( j >= 100 && j < 104 ) || ( j >= 108 && j < 112 ) 
			|| ( j >= 116 && j < 120  ) 	|| ( j >= 124 && j < 128 ))) {
          
		   tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
           } else if ( i == 30 + k && ( (j<2) || (j>=4 && j<6)  || (j>=8 && j<10) || (j>=12 && j<14) || (j>=16 && j<18) || (j>=20 && j<22) || (j>=24 && j<26)
			|| (j>=28 && j<30) || (j>=32 && j<34) || (j>=36 && j<38) || (j>=40 && j<42) || (j>=44 && j<46) || (j>=48 && j<50) || (j>=52 && j<54) 	  
			|| (j>=56 && j<58) || (j>=60 && j<62) || (j>=64 && j<66) || (j>=68 && j<70) || (j>=72 && j<74) || (j>=76 && j<78) || (j>=80 && j<82) 
                	|| (j>=84 && j<86) || (j>=88 && j<90) || (j>=92 && j<94) || (j>=96 && j<98) || (j>=100 && j<102) || (j>=104 && j<106) || (j>=108 && j<110) || 
                	(j>=112 && j<114) || (j>=116 && j<118)     || (j>=120 && j<122) || (j>=124 && j<126)
			)) {
	    tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   } else if (i == 30 + k && ( (j>=2 && j<4) || (j>=6 && j<8) || (j>=10 && j<12) || (j>=14 && j<16) || (j>=18 && j<20) || (j>=22 && j<24) || (j>=26 && j<28)
			|| (j>=30 && j<32) || (j>=34 && j<36) || (j>=38 && j<40) || (j>=42 && j<44) || (j>=46 && j<48) || (j>=50 && j<52) 
			|| (j>=54 && j<56) || (j>=58 && j<60) || (j>=62 && j<64) || (j>=66 && j<68) || (j>=70 && j<72) || (j>=74 && j<76) 
			|| (j>=78 && j<80) || (j>=82 && j<84) || (j>=86 && j<88) || (j>=90 && j<92) || (j>=94 && j<96)
                        || (j>=98 && j<100) || (j>=102 && j<104) || (j>=106 && j<108) || (j>=110 && j<112) || (j>=114 && j<116) 
			|| (j>=118 && j<120) || (j>=122 && j<124) || (j>=126 && j<128) )) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 

	   } else if (i == 31 + k && j % 2 == 0) {
	   
	    tmp_neg = Cudd_Not(var); 
	    tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   
	   } else if (i == 31 + k && j % 2 == 1) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 

	   }
	  
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd_rec[j]);
      bdd_rec[j] = tmp;
    }
  }
    
    bdd10 = Cudd_bddOr(gbm,bdd_rec[0],bdd_rec[1]); 
    Cudd_Ref(bdd10);   
    
    for (k = 2;k<128;k++) {
    bdd10 = Cudd_bddOr(gbm,bdd10,bdd_rec[k]);
    Cudd_Ref(bdd10);   
     }
    //bdd = Cudd_bddAnd(gbm,bdd,bdd10);
    //Cudd_Ref(bdd);   
     for(j = 0;j<128;j++){ 
       for (i = 24; i < 32; i++) {
          var = Cudd_bddIthVar(gbm,i); 
          if(i%8 ==  0) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec2[j]); 
	  }
	  else if(i == 25+k && j < 64 ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec2[j]); 
          }else if(i == 25+k && j >= 64) {
	  tmp = Cudd_bddAnd(gbm, var, bdd_rec2[j]); 
          }
	  else if ( (i == 26 + k) && ( ( j < 32 ) || ( j >= 64 && j < 96 ) ) ) {
          tmp_neg = Cudd_Not(var);
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec2[j]); 
          } else if ( i == 26 + k && ( ( j >= 32 && j < 64 ) || ( j >= 96 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec2[j]); 
	  } else if (i == 27 + k && ( (j<16) || (j>=32 && j<48) || (j>=64 && j<80) || (j>=96 && j<112) ) ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec2[j]); 
	  } else if (i == 27 + k && ( (j >= 16 && j < 32) || ( j >= 48 && j < 64 ) || ( j >= 80 && j < 96 ) || ( j >= 112 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec2[j]); 
          } else if ( i == 28 + k && ( ( j < 8 ) || ( j >= 16 && j < 24) || (j >= 32 && j < 40) || (j>=48 && j<56) || ( j >= 64 && j < 72 ) || 
		    (j >= 80 && j < 88) || (j >= 96 && j < 104) || (j>=112 && j<120) ) ) {
	   tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec2[j]); 
           } else if (i == 28 + k && ( ( j >= 8 && j < 16 ) || ( j >= 24 && j < 32 ) || ( j >= 40 && j < 48) || ( j >= 56 && j < 64) 
			|| (j>72 && j<=80) || (j>=88 && j<96) || (j>=104 && j<112) || (j>=120) ) ) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec2[j]);  
 	   } else if (i == 29 + k && ( (j < 4) || (j >= 8 && j < 12) || (j >= 16 && j < 20) || (j >= 24 && j < 28) || (j >= 32 && j < 36) || (j >= 40 && j < 44)
			|| (j >= 48 && j < 52)  || (j >= 56 && j < 60)|| (j >= 64 && j < 68) || (j >= 72 && j < 76) || (j >= 80 && j < 84) || (j >= 88 && j < 92) 	
			|| (j >= 96 && j < 100) || (j >= 104 && j < 108) || (j >= 112 && j < 116) || (j >= 120 && j < 124))) {
	   tmp_neg = Cudd_Not(var);
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec2[j]); 
	   
	   } else if (i == 29 + k && ( (j>=4 && j<8) || ( j >= 12 && j < 16 ) || ( j >= 20 && j < 24 ) || ( j >= 28 && j < 32 ) || ( j >= 36 && j < 40 ) 
			|| ( j >= 44 && j < 48 ) || ( j >= 52 && j < 56 ) || ( j >= 60 && j < 64 ) || ( j >= 68 && j < 72 ) || ( j >= 76 && j < 80 ) 	  
		        || ( j >= 84 && j < 88 ) || ( j >= 92 && j < 96 ) || ( j >= 100 && j < 104 ) || ( j >= 108 && j < 112 ) 
			|| ( j >= 116 && j < 120  ) 	|| ( j >= 124 && j < 128 ))) {
          
		   tmp = Cudd_bddAnd(gbm,var,bdd_rec2[j]); 
           } else if ( i == 30 + k && ( (j<2) || (j>=4 && j<6)  || (j>=8 && j<10) || (j>=12 && j<14) || (j>=16 && j<18) || (j>=20 && j<22) || (j>=24 && j<26)
			|| (j>=28 && j<30) || (j>=32 && j<34) || (j>=36 && j<38) || (j>=40 && j<42) || (j>=44 && j<46) || (j>=48 && j<50) || (j>=52 && j<54) 	  
			|| (j>=56 && j<58) || (j>=60 && j<62) || (j>=64 && j<66) || (j>=68 && j<70) || (j>=72 && j<74) || (j>=76 && j<78) || (j>=80 && j<82) 
                	|| (j>=84 && j<86) || (j>=88 && j<90) || (j>=92 && j<94) || (j>=96 && j<98) || (j>=100 && j<102) || (j>=104 && j<106) || (j>=108 && j<110) || 
                	(j>=112 && j<114) || (j>=116 && j<118)     || (j>=120 && j<122) || (j>=124 && j<126)
			)) {
	    tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec2[j]); 
	   } else if (i == 30 + k && ( (j>=2 && j<4) || (j>=6 && j<8) || (j>=10 && j<12) || (j>=14 && j<16) || (j>=18 && j<20) || (j>=22 && j<24) || (j>=26 && j<28)
			|| (j>=30 && j<32) || (j>=34 && j<36) || (j>=38 && j<40) || (j>=42 && j<44) || (j>=46 && j<48) || (j>=50 && j<52) 
			|| (j>=54 && j<56) || (j>=58 && j<60) || (j>=62 && j<64) || (j>=66 && j<68) || (j>=70 && j<72) || (j>=74 && j<76) 
			|| (j>=78 && j<80) || (j>=82 && j<84) || (j>=86 && j<88) || (j>=90 && j<92) || (j>=94 && j<96)
                        || (j>=98 && j<100) || (j>=102 && j<104) || (j>=106 && j<108) || (j>=110 && j<112) || (j>=114 && j<116) 
			|| (j>=118 && j<120) || (j>=122 && j<124) || (j>=126 && j<128) )) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec2[j]); 

	   } else if (i == 31 + k && j % 2 == 0) {
	   
	    tmp_neg = Cudd_Not(var); 
	    tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec2[j]); 
	   
	   } else if (i == 31 + k && j % 2 == 1) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec2[j]); 

	   }
	  
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd_rec2[j]);
      bdd_rec2[j] = tmp;
    }
  }
    
    bdd9 = Cudd_bddOr(gbm,bdd_rec2[0],bdd_rec2[1]); 
    Cudd_Ref(bdd9);   
    
    for (k = 2;k<128;k++) {
    bdd9 = Cudd_bddOr(gbm,bdd9,bdd_rec2[k]);
    Cudd_Ref(bdd9);   
     }

    bdd1 = Cudd_bddOr(gbm,bdd9,bdd10);
   // bdd = Cudd_bddAnd(gbm,bdd,bdd1);
    */
    DdNode* bdd71;
   
    bdd71 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd71); /*Increases the reference count of a node*/

     for (i = 16; i < 18; i++) {  
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd71); 
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd71);
      bdd71 = tmp;
    }
    
    
    bdd1 = Cudd_bddAnd(gbm,bdd1,bdd71);
    Cudd_Ref(bdd1);

    return bdd1;


}	

//FUNZIONI SUBSCRIBE

DdNode* scrivi_bdd_zero7 (DdManager *gbm, DdNode *bdd, DdNode * var) 
{
     DdNode* bdd_rec[128];
     DdNode *bdd1, *bdd2, *bdd3, *bdd4, *bdd5, *bdd6, *bdd7, *bdd8, *bdd9,*tmp,*tmp_neg;
     bdd = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd); /*Increases the reference count of a node*/
     int i; 
     
     for(i = 0; i < 128; i++){
     bdd_rec[i] = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd_rec[i]); /*Increases the reference count of a node*/
     } 
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
     bdd6 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd6); /*Increases the reference count of a node*/
     bdd7 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd7); /*Increases the reference count of a node*/
     bdd8 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd8); /*Increases the reference count of a node*/
   
     
     for (i = 0; i < 8; i++) {
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
     if(i != 0 && i != 6) {
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

int j;int k = 0;
     for(j = 0;j<128;j++){ 
       for (i = 8; i < 16; i++) {
          var = Cudd_bddIthVar(gbm,i); 
          if(i%8 ==  0) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	  }
	  else if(i == 9+k && j < 64 ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
          }else if(i == 9+k && j >= 64) {
	  tmp = Cudd_bddAnd(gbm, var, bdd_rec[j]); 
          }
	  else if ( (i == 10 + k) && ( ( j < 32 ) || ( j >= 64 && j < 96 ) ) ) {
          tmp_neg = Cudd_Not(var);
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
          } else if ( i == 10 + k && ( ( j >= 32 && j < 64 ) || ( j >= 96 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
	  } else if (i == 11 + k && ( (j<16) || (j>=32 && j<48) || (j>=64 && j<80) || (j>=96 && j<112) ) ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	  } else if (i == 11 + k && ( (j >= 16 && j < 32) || ( j >= 48 && j < 64 ) || ( j >= 80 && j < 96 ) || ( j >= 112 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
          } else if ( i == 12 + k && ( ( j < 8 ) || ( j >= 16 && j < 24) || (j >= 32 && j < 40) || (j>=48 && j<56) || ( j >= 64 && j < 72 ) || 
		    (j >= 80 && j < 88) || (j >= 96 && j < 104) || (j>=112 && j<120) ) ) {
	   tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
           } else if (i == 12 + k && ( ( j >= 8 && j < 16 ) || ( j >= 24 && j < 32 ) || ( j >= 40 && j < 48) || ( j >= 56 && j < 64) 
			|| (j>72 && j<=80) || (j>=88 && j<96) || (j>=104 && j<112) || (j>=120) ) ) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]);  
 	   } else if (i == 13 + k && ( (j < 4) || (j >= 8 && j < 12) || (j >= 16 && j < 20) || (j >= 24 && j < 28) || (j >= 32 && j < 36) || (j >= 40 && j < 44)
			|| (j >= 48 && j < 52)  || (j >= 56 && j < 60)|| (j >= 64 && j < 68) || (j >= 72 && j < 76) || (j >= 80 && j < 84) || (j >= 88 && j < 92) 	
			|| (j >= 96 && j < 100) || (j >= 104 && j < 108) || (j >= 112 && j < 116) || (j >= 120 && j < 124))) {
	   tmp_neg = Cudd_Not(var);
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   
	   } else if (i == 13 + k && ( (j>=4 && j<8) || ( j >= 12 && j < 16 ) || ( j >= 20 && j < 24 ) || ( j >= 28 && j < 32 ) || ( j >= 36 && j < 40 ) 
			|| ( j >= 44 && j < 48 ) || ( j >= 52 && j < 56 ) || ( j >= 60 && j < 64 ) || ( j >= 68 && j < 72 ) || ( j >= 76 && j < 80 ) 	  
		        || ( j >= 84 && j < 88 ) || ( j >= 92 && j < 96 ) || ( j >= 100 && j < 104 ) || ( j >= 108 && j < 112 ) 
			|| ( j >= 116 && j < 120  ) 	|| ( j >= 124 && j < 128 ))) {
          
		   tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
           } else if ( i == 14 + k && ( (j<2) || (j>=4 && j<6)  || (j>=8 && j<10) || (j>=12 && j<14) || (j>=16 && j<18) || (j>=20 && j<22) || (j>=24 && j<26)
			|| (j>=28 && j<30) || (j>=32 && j<34) || (j>=36 && j<38) || (j>=40 && j<42) || (j>=44 && j<46) || (j>=48 && j<50) || (j>=52 && j<54) 	  
			|| (j>=56 && j<58) || (j>=60 && j<62) || (j>=64 && j<66) || (j>=68 && j<70) || (j>=72 && j<74) || (j>=76 && j<78) || (j>=80 && j<82) 
                	|| (j>=84 && j<86) || (j>=88 && j<90) || (j>=92 && j<94) || (j>=96 && j<98) || (j>=100 && j<102) || (j>=104 && j<106) || (j>=108 && j<110) || 
                	(j>=112 && j<114) || (j>=116 && j<118)     || (j>=120 && j<122) || (j>=124 && j<126)
			)) {
	    tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   } else if (i == 14 + k && ( (j>=2 && j<4) || (j>=6 && j<8) || (j>=10 && j<12) || (j>=14 && j<16) || (j>=18 && j<20) || (j>=22 && j<24) || (j>=26 && j<28)
			|| (j>=30 && j<32) || (j>=34 && j<36) || (j>=38 && j<40) || (j>=42 && j<44) || (j>=46 && j<48) || (j>=50 && j<52) 
			|| (j>=54 && j<56) || (j>=58 && j<60) || (j>=62 && j<64) || (j>=66 && j<68) || (j>=70 && j<72) || (j>=74 && j<76) 
			|| (j>=78 && j<80) || (j>=82 && j<84) || (j>=86 && j<88) || (j>=90 && j<92) || (j>=94 && j<96)
                        || (j>=98 && j<100) || (j>=102 && j<104) || (j>=106 && j<108) || (j>=110 && j<112) || (j>=114 && j<116) 
			|| (j>=118 && j<120) || (j>=122 && j<124) || (j>=126 && j<128) )) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 

	   } else if (i == 15 + k && j % 2 == 0) {
	   
	    tmp_neg = Cudd_Not(var); 
	    tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   
	   } else if (i == 15 + k && j % 2 == 1) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 

	   }
	  
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd_rec[j]);
      bdd_rec[j] = tmp;
    }
  }
    
    bdd1 = Cudd_bddOr(gbm,bdd_rec[0],bdd_rec[1]); 
    Cudd_Ref(bdd1);   
    
    for (k = 2;k<128;k++) {
    bdd1 = Cudd_bddOr(gbm,bdd1,bdd_rec[k]);
    Cudd_Ref(bdd1);   
     }

    bdd = Cudd_bddAnd(gbm,bdd,bdd1);
    Cudd_Ref(bdd);   
    /*
    for (i = 16; i < 24; i++) {
     var = Cudd_bddIthVar(gbm,i); 
     
      tmp_neg = Cudd_Not(var); 
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd2);
    
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd2);
      bdd2 = tmp;
    }
   
    bdd = Cudd_bddAnd(gbm,bdd,bdd2);
    Cudd_Ref(bdd);
    
    for (i = 24; i < 32; i++) {
     var = Cudd_bddIthVar(gbm,i); 
     if(i != 28 && i != 30){
      tmp_neg = Cudd_Not(var); 
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd3); 
     }else{
      tmp = Cudd_bddAnd(gbm, var, bdd3);
     }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd3);
      bdd3 = tmp;
    }
    
    bdd = Cudd_bddAnd(gbm,bdd,bdd3);
    Cudd_Ref(bdd);
    */
    DdNode* bdd71;
   
    bdd71 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd71); /*Increases the reference count of a node*/

     for (i = 16; i < 18; i++) {  
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd71); 
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd71);
      bdd71 = tmp;
    }
    
    
    bdd = Cudd_bddAnd(gbm,bdd,bdd71);
    Cudd_Ref(bdd);
    
return bdd;

}




DdNode* scrivi_bdd_uno7 (DdManager *gbm, DdNode *bdd, DdNode * var) 
{
 
 DdNode* bdd_rec[128];
 DdNode *bdd1, *bdd2, *bdd3, *bdd4, *bdd5, *bdd6, *bdd7, *bdd8, *bdd9,*tmp,*tmp_neg;
     bdd = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd); /*Increases the reference count of a node*/
     int i; 
     
     for(i = 0; i < 128; i++){
     bdd_rec[i] = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd_rec[i]); /*Increases the reference count of a node*/
     } 
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
     bdd6 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd6); /*Increases the reference count of a node*/
     bdd7 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd7); /*Increases the reference count of a node*/
     bdd8 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd8); /*Increases the reference count of a node*/
     bdd9 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd9); /*Increases the reference count of a node*/
     
     for (i = 0; i < 8; i++) {
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
     if(i != 0 && i != 6) {
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

    int j;int k = 0;
     for(j = 0;j<128;j++){ 
       for (i = 8; i < 16; i++) {
          var = Cudd_bddIthVar(gbm,i); 
          if(i%8 ==  0) {
          //tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, var, bdd_rec[j]); 
	  }
	  else if(i == 9+k && j < 64 ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
          }else if(i == 9+k && j >= 64) {
	  tmp = Cudd_bddAnd(gbm, var, bdd_rec[j]); 
          }
	  else if ( (i == 10 + k) && ( ( j < 32 ) || ( j >= 64 && j < 96 ) ) ) {
          tmp_neg = Cudd_Not(var);
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
          } else if ( i == 10 + k && ( ( j >= 32 && j < 64 ) || ( j >= 96 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
	  } else if (i == 11 + k && ( (j<16) || (j>=32 && j<48) || (j>=64 && j<80) || (j>=96 && j<112) ) ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	  } else if (i == 11 + k && ( (j >= 16 && j < 32) || ( j >= 48 && j < 64 ) || ( j >= 80 && j < 96 ) || ( j >= 112 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
          } else if ( i == 12 + k && ( ( j < 8 ) || ( j >= 16 && j < 24) || (j >= 32 && j < 40) || (j>=48 && j<56) || ( j >= 64 && j < 72 ) || 
		    (j >= 80 && j < 88) || (j >= 96 && j < 104) || (j>=112 && j<120) ) ) {
	   tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
           } else if (i == 12 + k && ( ( j >= 8 && j < 16 ) || ( j >= 24 && j < 32 ) || ( j >= 40 && j < 48) || ( j >= 56 && j < 64) 
			|| (j>72 && j<=80) || (j>=88 && j<96) || (j>=104 && j<112) || (j>=120) ) ) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]);  
 	   } else if (i == 13 + k && ( (j < 4) || (j >= 8 && j < 12) || (j >= 16 && j < 20) || (j >= 24 && j < 28) || (j >= 32 && j < 36) || (j >= 40 && j < 44)
			|| (j >= 48 && j < 52)  || (j >= 56 && j < 60)|| (j >= 64 && j < 68) || (j >= 72 && j < 76) || (j >= 80 && j < 84) || (j >= 88 && j < 92) 	
			|| (j >= 96 && j < 100) || (j >= 104 && j < 108) || (j >= 112 && j < 116) || (j >= 120 && j < 124))) {
	   tmp_neg = Cudd_Not(var);
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   
	   } else if (i == 13 + k && ( (j>=4 && j<8) || ( j >= 12 && j < 16 ) || ( j >= 20 && j < 24 ) || ( j >= 28 && j < 32 ) || ( j >= 36 && j < 40 ) 
			|| ( j >= 44 && j < 48 ) || ( j >= 52 && j < 56 ) || ( j >= 60 && j < 64 ) || ( j >= 68 && j < 72 ) || ( j >= 76 && j < 80 ) 	  
		        || ( j >= 84 && j < 88 ) || ( j >= 92 && j < 96 ) || ( j >= 100 && j < 104 ) || ( j >= 108 && j < 112 ) 
			|| ( j >= 116 && j < 120  ) 	|| ( j >= 124 && j < 128 ))) {
          
		   tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
           } else if ( i == 14 + k && ( (j<2) || (j>=4 && j<6)  || (j>=8 && j<10) || (j>=12 && j<14) || (j>=16 && j<18) || (j>=20 && j<22) || (j>=24 && j<26)
			|| (j>=28 && j<30) || (j>=32 && j<34) || (j>=36 && j<38) || (j>=40 && j<42) || (j>=44 && j<46) || (j>=48 && j<50) || (j>=52 && j<54) 	  
			|| (j>=56 && j<58) || (j>=60 && j<62) || (j>=64 && j<66) || (j>=68 && j<70) || (j>=72 && j<74) || (j>=76 && j<78) || (j>=80 && j<82) 
                	|| (j>=84 && j<86) || (j>=88 && j<90) || (j>=92 && j<94) || (j>=96 && j<98) || (j>=100 && j<102) || (j>=104 && j<106) || (j>=108 && j<110) || 
                	(j>=112 && j<114) || (j>=116 && j<118)     || (j>=120 && j<122) || (j>=124 && j<126)
			)) {
	    tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   } else if (i == 14 + k && ( (j>=2 && j<4) || (j>=6 && j<8) || (j>=10 && j<12) || (j>=14 && j<16) || (j>=18 && j<20) || (j>=22 && j<24) || (j>=26 && j<28)
			|| (j>=30 && j<32) || (j>=34 && j<36) || (j>=38 && j<40) || (j>=42 && j<44) || (j>=46 && j<48) || (j>=50 && j<52) 
			|| (j>=54 && j<56) || (j>=58 && j<60) || (j>=62 && j<64) || (j>=66 && j<68) || (j>=70 && j<72) || (j>=74 && j<76) 
			|| (j>=78 && j<80) || (j>=82 && j<84) || (j>=86 && j<88) || (j>=90 && j<92) || (j>=94 && j<96)
                        || (j>=98 && j<100) || (j>=102 && j<104) || (j>=106 && j<108) || (j>=110 && j<112) || (j>=114 && j<116) 
			|| (j>=118 && j<120) || (j>=122 && j<124) || (j>=126 && j<128) )) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 

	   } else if (i == 15 + k && j % 2 == 0) {
	   
	    tmp_neg = Cudd_Not(var); 
	    tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   
	   } else if (i == 15 + k && j % 2 == 1) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 

	   }
	  
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd_rec[j]);
      bdd_rec[j] = tmp;
    }
  }
    
    bdd1 = Cudd_bddOr(gbm,bdd_rec[0],bdd_rec[1]); 
    Cudd_Ref(bdd1);   
    
    for (k = 2;k<128;k++) {
    bdd1 = Cudd_bddOr(gbm,bdd1,bdd_rec[k]);
    Cudd_Ref(bdd1);   
     }
    bdd = Cudd_bddAnd(gbm,bdd,bdd1);
    Cudd_Ref(bdd);   
/*
     for(j = 0;j<128;j++){ 
       for (i = 16; i < 24; i++) {
          var = Cudd_bddIthVar(gbm,i); 
          if(i%8 ==  0) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	  }
	  else if(i == 17+k && j < 64 ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
          }else if(i == 17+k && j >= 64) {
	  tmp = Cudd_bddAnd(gbm, var, bdd_rec[j]); 
          }
	  else if ( (i == 18 + k) && ( ( j < 32 ) || ( j >= 64 && j < 96 ) ) ) {
          tmp_neg = Cudd_Not(var);
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
          } else if ( i == 18 + k && ( ( j >= 32 && j < 64 ) || ( j >= 96 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
	  } else if (i == 19 + k && ( (j<16) || (j>=32 && j<48) || (j>=64 && j<80) || (j>=96 && j<112) ) ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	  } else if (i == 19 + k && ( (j >= 16 && j < 32) || ( j >= 48 && j < 64 ) || ( j >= 80 && j < 96 ) || ( j >= 112 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
          } else if ( i == 20 + k && ( ( j < 8 ) || ( j >= 16 && j < 24) || (j >= 32 && j < 40) || (j>=48 && j<56) || ( j >= 64 && j < 72 ) || 
		    (j >= 80 && j < 88) || (j >= 96 && j < 104) || (j>=112 && j<120) ) ) {
	   tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
           } else if (i == 20 + k && ( ( j >= 8 && j < 16 ) || ( j >= 24 && j < 32 ) || ( j >= 40 && j < 48) || ( j >= 56 && j < 64) 
			|| (j>72 && j<=80) || (j>=88 && j<96) || (j>=104 && j<112) || (j>=120) ) ) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]);  
 	   } else if (i == 21 + k && ( (j < 4) || (j >= 8 && j < 12) || (j >= 16 && j < 20) || (j >= 24 && j < 28) || (j >= 32 && j < 36) || (j >= 40 && j < 44)
			|| (j >= 48 && j < 52)  || (j >= 56 && j < 60)|| (j >= 64 && j < 68) || (j >= 72 && j < 76) || (j >= 80 && j < 84) || (j >= 88 && j < 92) 	
			|| (j >= 96 && j < 100) || (j >= 104 && j < 108) || (j >= 112 && j < 116) || (j >= 120 && j < 124))) {
	   tmp_neg = Cudd_Not(var);
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   
	   } else if (i == 21 + k && ( (j>=4 && j<8) || ( j >= 12 && j < 16 ) || ( j >= 20 && j < 24 ) || ( j >= 28 && j < 32 ) || ( j >= 36 && j < 40 ) 
			|| ( j >= 44 && j < 48 ) || ( j >= 52 && j < 56 ) || ( j >= 60 && j < 64 ) || ( j >= 68 && j < 72 ) || ( j >= 76 && j < 80 ) 	  
		        || ( j >= 84 && j < 88 ) || ( j >= 92 && j < 96 ) || ( j >= 100 && j < 104 ) || ( j >= 108 && j < 112 ) 
			|| ( j >= 116 && j < 120  ) 	|| ( j >= 124 && j < 128 ))) {
          
		   tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
           } else if ( i == 22 + k && ( (j<2) || (j>=4 && j<6)  || (j>=8 && j<10) || (j>=12 && j<14) || (j>=16 && j<18) || (j>=20 && j<22) || (j>=24 && j<26)
			|| (j>=28 && j<30) || (j>=32 && j<34) || (j>=36 && j<38) || (j>=40 && j<42) || (j>=44 && j<46) || (j>=48 && j<50) || (j>=52 && j<54) 	  
			|| (j>=56 && j<58) || (j>=60 && j<62) || (j>=64 && j<66) || (j>=68 && j<70) || (j>=72 && j<74) || (j>=76 && j<78) || (j>=80 && j<82) 
                	|| (j>=84 && j<86) || (j>=88 && j<90) || (j>=92 && j<94) || (j>=96 && j<98) || (j>=100 && j<102) || (j>=104 && j<106) || (j>=108 && j<110) || 
                	(j>=112 && j<114) || (j>=116 && j<118)     || (j>=120 && j<122) || (j>=124 && j<126)
			)) {
	    tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   } else if (i == 22 + k && ( (j>=2 && j<4) || (j>=6 && j<8) || (j>=10 && j<12) || (j>=14 && j<16) || (j>=18 && j<20) || (j>=22 && j<24) || (j>=26 && j<28)
			|| (j>=30 && j<32) || (j>=34 && j<36) || (j>=38 && j<40) || (j>=42 && j<44) || (j>=46 && j<48) || (j>=50 && j<52) 
			|| (j>=54 && j<56) || (j>=58 && j<60) || (j>=62 && j<64) || (j>=66 && j<68) || (j>=70 && j<72) || (j>=74 && j<76) 
			|| (j>=78 && j<80) || (j>=82 && j<84) || (j>=86 && j<88) || (j>=90 && j<92) || (j>=94 && j<96)
                        || (j>=98 && j<100) || (j>=102 && j<104) || (j>=106 && j<108) || (j>=110 && j<112) || (j>=114 && j<116) 
			|| (j>=118 && j<120) || (j>=122 && j<124) || (j>=126 && j<128) )) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 

	   } else if (i == 23 + k && j % 2 == 0) {
	   
	    tmp_neg = Cudd_Not(var); 
	    tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   
	   } else if (i == 23 + k && j % 2 == 1) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 

	   }
	  
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd_rec[j]);
      bdd_rec[j] = tmp;
    }
  }
    

    bdd9 = Cudd_bddOr(gbm,bdd_rec[0],bdd_rec[1]); 
    Cudd_Ref(bdd1);   
    
    for (k = 2;k<128;k++) {
    bdd9 = Cudd_bddOr(gbm,bdd9,bdd_rec[k]);
    Cudd_Ref(bdd1);   
     }

    bdd = Cudd_bddAnd(gbm,bdd,bdd9);
    Cudd_Ref(bdd);   
    
    for (i = 24; i < 32; i++) {
     var = Cudd_bddIthVar(gbm,i); 
     
      tmp_neg = Cudd_Not(var);
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd2); 
    
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd2);
      bdd2 = tmp;
    }
   
    bdd = Cudd_bddAnd(gbm,bdd,bdd2);
    Cudd_Ref(bdd);
  
    */
    /* 
    for (i = 32; i < 40; i++) {
     var = Cudd_bddIthVar(gbm,i); 
     if(i != 36 && i != 38){
      tmp_neg = Cudd_Not(var); 
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd3); 
     }else{
      tmp = Cudd_bddAnd(gbm, var, bdd3); 
     }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd3);
      bdd3 = tmp;
    }
    
    bdd = Cudd_bddAnd(gbm,bdd,bdd3);
    Cudd_Ref(bdd);
    */
    DdNode* bdd71;
   
    bdd71 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd71); /*Increases the reference count of a node*/

     for (i = 16; i < 18; i++) {  
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd71); 
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd71);
      bdd71 = tmp;
    }
    
    
    bdd = Cudd_bddAnd(gbm,bdd,bdd71);
    Cudd_Ref(bdd);
    
   return bdd;


}	



DdNode* scrivi_bdd_due7 (DdManager *gbm, DdNode *bdd, DdNode * var) {
 DdNode* bdd_rec[128];
 DdNode *bdd1, *bdd2, *bdd3, *bdd4, *bdd5, *bdd6, *bdd7, *bdd8, *bdd9,*bdd10,*tmp,*tmp_neg;
     bdd = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd); /*Increases the reference count of a node*/
     int i; 
     
     for(i = 0; i < 128; i++){
     bdd_rec[i] = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd_rec[i]); /*Increases the reference count of a node*/
     } 
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
     bdd6 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd6); /*Increases the reference count of a node*/
     bdd7 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd7); /*Increases the reference count of a node*/
     bdd8 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd8); /*Increases the reference count of a node*/
     bdd9 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd9); /*Increases the reference count of a node*/
     
     for (i = 0; i < 8; i++) {
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
     if(i != 0 && i != 6) {
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

    int j;int k = 0;
     for(j = 0;j<128;j++){ 
       for (i = 8; i < 16; i++) {
          var = Cudd_bddIthVar(gbm,i); 
          if(i%8 ==  0) {
          //tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, var, bdd_rec[j]); 
	  }
	  else if(i == 9+k && j < 64 ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
          }else if(i == 9+k && j >= 64) {
	  tmp = Cudd_bddAnd(gbm, var, bdd_rec[j]); 
          }
	  else if ( (i == 10 + k) && ( ( j < 32 ) || ( j >= 64 && j < 96 ) ) ) {
          tmp_neg = Cudd_Not(var);
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
          } else if ( i == 10 + k && ( ( j >= 32 && j < 64 ) || ( j >= 96 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
	  } else if (i == 11 + k && ( (j<16) || (j>=32 && j<48) || (j>=64 && j<80) || (j>=96 && j<112) ) ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	  } else if (i == 11 + k && ( (j >= 16 && j < 32) || ( j >= 48 && j < 64 ) || ( j >= 80 && j < 96 ) || ( j >= 112 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
          } else if ( i == 12 + k && ( ( j < 8 ) || ( j >= 16 && j < 24) || (j >= 32 && j < 40) || (j>=48 && j<56) || ( j >= 64 && j < 72 ) || 
		    (j >= 80 && j < 88) || (j >= 96 && j < 104) || (j>=112 && j<120) ) ) {
	   tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
           } else if (i == 12 + k && ( ( j >= 8 && j < 16 ) || ( j >= 24 && j < 32 ) || ( j >= 40 && j < 48) || ( j >= 56 && j < 64) 
			|| (j>72 && j<=80) || (j>=88 && j<96) || (j>=104 && j<112) || (j>=120) ) ) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]);  
 	   } else if (i == 13 + k && ( (j < 4) || (j >= 8 && j < 12) || (j >= 16 && j < 20) || (j >= 24 && j < 28) || (j >= 32 && j < 36) || (j >= 40 && j < 44)
			|| (j >= 48 && j < 52)  || (j >= 56 && j < 60)|| (j >= 64 && j < 68) || (j >= 72 && j < 76) || (j >= 80 && j < 84) || (j >= 88 && j < 92) 	
			|| (j >= 96 && j < 100) || (j >= 104 && j < 108) || (j >= 112 && j < 116) || (j >= 120 && j < 124))) {
	   tmp_neg = Cudd_Not(var);
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   
	   } else if (i == 13 + k && ( (j>=4 && j<8) || ( j >= 12 && j < 16 ) || ( j >= 20 && j < 24 ) || ( j >= 28 && j < 32 ) || ( j >= 36 && j < 40 ) 
			|| ( j >= 44 && j < 48 ) || ( j >= 52 && j < 56 ) || ( j >= 60 && j < 64 ) || ( j >= 68 && j < 72 ) || ( j >= 76 && j < 80 ) 	  
		        || ( j >= 84 && j < 88 ) || ( j >= 92 && j < 96 ) || ( j >= 100 && j < 104 ) || ( j >= 108 && j < 112 ) 
			|| ( j >= 116 && j < 120  ) 	|| ( j >= 124 && j < 128 ))) {
          
		   tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
           } else if ( i == 14 + k && ( (j<2) || (j>=4 && j<6)  || (j>=8 && j<10) || (j>=12 && j<14) || (j>=16 && j<18) || (j>=20 && j<22) || (j>=24 && j<26)
			|| (j>=28 && j<30) || (j>=32 && j<34) || (j>=36 && j<38) || (j>=40 && j<42) || (j>=44 && j<46) || (j>=48 && j<50) || (j>=52 && j<54) 	  
			|| (j>=56 && j<58) || (j>=60 && j<62) || (j>=64 && j<66) || (j>=68 && j<70) || (j>=72 && j<74) || (j>=76 && j<78) || (j>=80 && j<82) 
                	|| (j>=84 && j<86) || (j>=88 && j<90) || (j>=92 && j<94) || (j>=96 && j<98) || (j>=100 && j<102) || (j>=104 && j<106) || (j>=108 && j<110) || 
                	(j>=112 && j<114) || (j>=116 && j<118)     || (j>=120 && j<122) || (j>=124 && j<126)
			)) {
	    tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   } else if (i == 14 + k && ( (j>=2 && j<4) || (j>=6 && j<8) || (j>=10 && j<12) || (j>=14 && j<16) || (j>=18 && j<20) || (j>=22 && j<24) || (j>=26 && j<28)
			|| (j>=30 && j<32) || (j>=34 && j<36) || (j>=38 && j<40) || (j>=42 && j<44) || (j>=46 && j<48) || (j>=50 && j<52) 
			|| (j>=54 && j<56) || (j>=58 && j<60) || (j>=62 && j<64) || (j>=66 && j<68) || (j>=70 && j<72) || (j>=74 && j<76) 
			|| (j>=78 && j<80) || (j>=82 && j<84) || (j>=86 && j<88) || (j>=90 && j<92) || (j>=94 && j<96)
                        || (j>=98 && j<100) || (j>=102 && j<104) || (j>=106 && j<108) || (j>=110 && j<112) || (j>=114 && j<116) 
			|| (j>=118 && j<120) || (j>=122 && j<124) || (j>=126 && j<128) )) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 

	   } else if (i == 15 + k && j % 2 == 0) {
	   
	    tmp_neg = Cudd_Not(var); 
	    tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   
	   } else if (i == 15 + k && j % 2 == 1) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 

	   }
	  
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd_rec[j]);
      bdd_rec[j] = tmp;
    }
  }
    
    bdd1 = Cudd_bddOr(gbm,bdd_rec[0],bdd_rec[1]); 
    Cudd_Ref(bdd1);   
    
    for (k = 2;k<128;k++) {
    bdd1 = Cudd_bddOr(gbm,bdd1,bdd_rec[k]);
    Cudd_Ref(bdd1);   
     }
    bdd = Cudd_bddAnd(gbm,bdd,bdd1);
    Cudd_Ref(bdd);   
/*

     for(j = 0;j<128;j++){ 
       for (i = 16; i < 24; i++) {
          var = Cudd_bddIthVar(gbm,i); 
          if(i%8 ==  0) {
          //tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, var, bdd_rec[j]); 
	  }
	  else if(i == 17+k && j < 64 ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
          }else if(i == 17+k && j >= 64) {
	  tmp = Cudd_bddAnd(gbm, var, bdd_rec[j]); 
          }
	  else if ( (i == 18 + k) && ( ( j < 32 ) || ( j >= 64 && j < 96 ) ) ) {
          tmp_neg = Cudd_Not(var);
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
          } else if ( i == 18 + k && ( ( j >= 32 && j < 64 ) || ( j >= 96 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
	  } else if (i == 19 + k && ( (j<16) || (j>=32 && j<48) || (j>=64 && j<80) || (j>=96 && j<112) ) ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	  } else if (i == 19 + k && ( (j >= 16 && j < 32) || ( j >= 48 && j < 64 ) || ( j >= 80 && j < 96 ) || ( j >= 112 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
          } else if ( i == 20 + k && ( ( j < 8 ) || ( j >= 16 && j < 24) || (j >= 32 && j < 40) || (j>=48 && j<56) || ( j >= 64 && j < 72 ) || 
		    (j >= 80 && j < 88) || (j >= 96 && j < 104) || (j>=112 && j<120) ) ) {
	   tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
           } else if (i == 20 + k && ( ( j >= 8 && j < 16 ) || ( j >= 24 && j < 32 ) || ( j >= 40 && j < 48) || ( j >= 56 && j < 64) 
			|| (j>72 && j<=80) || (j>=88 && j<96) || (j>=104 && j<112) || (j>=120) ) ) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]);  
 	   } else if (i == 21 + k && ( (j < 4) || (j >= 8 && j < 12) || (j >= 16 && j < 20) || (j >= 24 && j < 28) || (j >= 32 && j < 36) || (j >= 40 && j < 44)
			|| (j >= 48 && j < 52)  || (j >= 56 && j < 60)|| (j >= 64 && j < 68) || (j >= 72 && j < 76) || (j >= 80 && j < 84) || (j >= 88 && j < 92) 	
			|| (j >= 96 && j < 100) || (j >= 104 && j < 108) || (j >= 112 && j < 116) || (j >= 120 && j < 124))) {
	   tmp_neg = Cudd_Not(var);
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   
	   } else if (i == 21 + k && ( (j>=4 && j<8) || ( j >= 12 && j < 16 ) || ( j >= 20 && j < 24 ) || ( j >= 28 && j < 32 ) || ( j >= 36 && j < 40 ) 
			|| ( j >= 44 && j < 48 ) || ( j >= 52 && j < 56 ) || ( j >= 60 && j < 64 ) || ( j >= 68 && j < 72 ) || ( j >= 76 && j < 80 ) 	  
		        || ( j >= 84 && j < 88 ) || ( j >= 92 && j < 96 ) || ( j >= 100 && j < 104 ) || ( j >= 108 && j < 112 ) 
			|| ( j >= 116 && j < 120  ) 	|| ( j >= 124 && j < 128 ))) {
          
		   tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
           } else if ( i == 22 + k && ( (j<2) || (j>=4 && j<6)  || (j>=8 && j<10) || (j>=12 && j<14) || (j>=16 && j<18) || (j>=20 && j<22) || (j>=24 && j<26)
			|| (j>=28 && j<30) || (j>=32 && j<34) || (j>=36 && j<38) || (j>=40 && j<42) || (j>=44 && j<46) || (j>=48 && j<50) || (j>=52 && j<54) 	  
			|| (j>=56 && j<58) || (j>=60 && j<62) || (j>=64 && j<66) || (j>=68 && j<70) || (j>=72 && j<74) || (j>=76 && j<78) || (j>=80 && j<82) 
                	|| (j>=84 && j<86) || (j>=88 && j<90) || (j>=92 && j<94) || (j>=96 && j<98) || (j>=100 && j<102) || (j>=104 && j<106) || (j>=108 && j<110) || 
                	(j>=112 && j<114) || (j>=116 && j<118)     || (j>=120 && j<122) || (j>=124 && j<126)
			)) {
	    tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   } else if (i == 22 + k && ( (j>=2 && j<4) || (j>=6 && j<8) || (j>=10 && j<12) || (j>=14 && j<16) || (j>=18 && j<20) || (j>=22 && j<24) || (j>=26 && j<28)
			|| (j>=30 && j<32) || (j>=34 && j<36) || (j>=38 && j<40) || (j>=42 && j<44) || (j>=46 && j<48) || (j>=50 && j<52) 
			|| (j>=54 && j<56) || (j>=58 && j<60) || (j>=62 && j<64) || (j>=66 && j<68) || (j>=70 && j<72) || (j>=74 && j<76) 
			|| (j>=78 && j<80) || (j>=82 && j<84) || (j>=86 && j<88) || (j>=90 && j<92) || (j>=94 && j<96)
                        || (j>=98 && j<100) || (j>=102 && j<104) || (j>=106 && j<108) || (j>=110 && j<112) || (j>=114 && j<116) 
			|| (j>=118 && j<120) || (j>=122 && j<124) || (j>=126 && j<128) )) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 

	   } else if (i == 23 + k && j % 2 == 0) {
	   
	    tmp_neg = Cudd_Not(var); 
	    tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   
	   } else if (i == 23 + k && j % 2 == 1) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 

	   }
	  
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd_rec[j]);
      bdd_rec[j] = tmp;
    }
  }
    

    bdd9 = Cudd_bddOr(gbm,bdd_rec[0],bdd_rec[1]); 
    Cudd_Ref(bdd1);   
    
    for (k = 2;k<128;k++) {
    bdd9 = Cudd_bddOr(gbm,bdd9,bdd_rec[k]);
    Cudd_Ref(bdd1);   
    }

    bdd = Cudd_bddAnd(gbm,bdd,bdd9);
    Cudd_Ref(bdd);   

     for(j = 0;j<128;j++){ 
       for (i = 24; i < 32; i++) {
          var = Cudd_bddIthVar(gbm,i); 
          if(i%8 ==  0) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	  }
	  else if(i == 25+k && j < 64 ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
          }else if(i == 25+k && j >= 64) {
	  tmp = Cudd_bddAnd(gbm, var, bdd_rec[j]); 
          }
	  else if ( (i == 26 + k) && ( ( j < 32 ) || ( j >= 64 && j < 96 ) ) ) {
          tmp_neg = Cudd_Not(var);
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
          } else if ( i == 26 + k && ( ( j >= 32 && j < 64 ) || ( j >= 96 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
	  } else if (i == 27 + k && ( (j<16) || (j>=32 && j<48) || (j>=64 && j<80) || (j>=96 && j<112) ) ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	  } else if (i == 27 + k && ( (j >= 16 && j < 32) || ( j >= 48 && j < 64 ) || ( j >= 80 && j < 96 ) || ( j >= 112 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
          } else if ( i == 28 + k && ( ( j < 8 ) || ( j >= 16 && j < 24) || (j >= 32 && j < 40) || (j>=48 && j<56) || ( j >= 64 && j < 72 ) || 
		    (j >= 80 && j < 88) || (j >= 96 && j < 104) || (j>=112 && j<120) ) ) {
	   tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
           } else if (i == 28 + k && ( ( j >= 8 && j < 16 ) || ( j >= 24 && j < 32 ) || ( j >= 40 && j < 48) || ( j >= 56 && j < 64) 
			|| (j>72 && j<=80) || (j>=88 && j<96) || (j>=104 && j<112) || (j>=120) ) ) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]);  
 	   } else if (i == 29 + k && ( (j < 4) || (j >= 8 && j < 12) || (j >= 16 && j < 20) || (j >= 24 && j < 28) || (j >= 32 && j < 36) || (j >= 40 && j < 44)
			|| (j >= 48 && j < 52)  || (j >= 56 && j < 60)|| (j >= 64 && j < 68) || (j >= 72 && j < 76) || (j >= 80 && j < 84) || (j >= 88 && j < 92) 	
			|| (j >= 96 && j < 100) || (j >= 104 && j < 108) || (j >= 112 && j < 116) || (j >= 120 && j < 124))) {
	   tmp_neg = Cudd_Not(var);
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   
	   } else if (i == 29 + k && ( (j>=4 && j<8) || ( j >= 12 && j < 16 ) || ( j >= 20 && j < 24 ) || ( j >= 28 && j < 32 ) || ( j >= 36 && j < 40 ) 
			|| ( j >= 44 && j < 48 ) || ( j >= 52 && j < 56 ) || ( j >= 60 && j < 64 ) || ( j >= 68 && j < 72 ) || ( j >= 76 && j < 80 ) 	  
		        || ( j >= 84 && j < 88 ) || ( j >= 92 && j < 96 ) || ( j >= 100 && j < 104 ) || ( j >= 108 && j < 112 ) 
			|| ( j >= 116 && j < 120  ) 	|| ( j >= 124 && j < 128 ))) {
          
		   tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
           } else if ( i == 30 + k && ( (j<2) || (j>=4 && j<6)  || (j>=8 && j<10) || (j>=12 && j<14) || (j>=16 && j<18) || (j>=20 && j<22) || (j>=24 && j<26)
			|| (j>=28 && j<30) || (j>=32 && j<34) || (j>=36 && j<38) || (j>=40 && j<42) || (j>=44 && j<46) || (j>=48 && j<50) || (j>=52 && j<54) 	  
			|| (j>=56 && j<58) || (j>=60 && j<62) || (j>=64 && j<66) || (j>=68 && j<70) || (j>=72 && j<74) || (j>=76 && j<78) || (j>=80 && j<82) 
                	|| (j>=84 && j<86) || (j>=88 && j<90) || (j>=92 && j<94) || (j>=96 && j<98) || (j>=100 && j<102) || (j>=104 && j<106) || (j>=108 && j<110) || 
                	(j>=112 && j<114) || (j>=116 && j<118)     || (j>=120 && j<122) || (j>=124 && j<126)
			)) {
	    tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   } else if (i == 30 + k && ( (j>=2 && j<4) || (j>=6 && j<8) || (j>=10 && j<12) || (j>=14 && j<16) || (j>=18 && j<20) || (j>=22 && j<24) || (j>=26 && j<28)
			|| (j>=30 && j<32) || (j>=34 && j<36) || (j>=38 && j<40) || (j>=42 && j<44) || (j>=46 && j<48) || (j>=50 && j<52) 
			|| (j>=54 && j<56) || (j>=58 && j<60) || (j>=62 && j<64) || (j>=66 && j<68) || (j>=70 && j<72) || (j>=74 && j<76) 
			|| (j>=78 && j<80) || (j>=82 && j<84) || (j>=86 && j<88) || (j>=90 && j<92) || (j>=94 && j<96)
                        || (j>=98 && j<100) || (j>=102 && j<104) || (j>=106 && j<108) || (j>=110 && j<112) || (j>=114 && j<116) 
			|| (j>=118 && j<120) || (j>=122 && j<124) || (j>=126 && j<128) )) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 

	   } else if (i == 31 + k && j % 2 == 0) {
	   
	    tmp_neg = Cudd_Not(var); 
	    tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   
	   } else if (i == 31 + k && j % 2 == 1) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 

	   }
	  
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd_rec[j]);
      bdd_rec[j] = tmp;
    }
  }
    
    bdd10 = Cudd_bddOr(gbm,bdd_rec[0],bdd_rec[1]); 
    Cudd_Ref(bdd10);   
    
    for (k = 2;k<128;k++) {
    bdd10 = Cudd_bddOr(gbm,bdd10,bdd_rec[k]);
    Cudd_Ref(bdd10);   
     }
    bdd = Cudd_bddAnd(gbm,bdd,bdd10);
    Cudd_Ref(bdd);   
*/
    /*
    for (i = 32; i < 40; i++) {
     var = Cudd_bddIthVar(gbm,i); 
     
      tmp_neg = Cudd_Not(var); 
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd2); 
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd2);
      bdd2 = tmp;
    }
   
    bdd = Cudd_bddAnd(gbm,bdd,bdd2);
    Cudd_Ref(bdd);
    
    for (i = 40; i < 48; i++) {
     var = Cudd_bddIthVar(gbm,i); 
     if(i != 44 && i != 46){
      tmp_neg = Cudd_Not(var); 
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd3); 
     }else{
      tmp = Cudd_bddAnd(gbm, var, bdd3); 
     }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd3);
      bdd3 = tmp;
    }
    
    bdd = Cudd_bddAnd(gbm,bdd,bdd3);
    Cudd_Ref(bdd);
    */
    DdNode* bdd71;
   
    bdd71 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd71); /*Increases the reference count of a node*/

     for (i = 16; i < 18; i++) {  
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd71); 
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd71);
      bdd71 = tmp;
    }
    
    
    bdd = Cudd_bddAnd(gbm,bdd,bdd71);
    Cudd_Ref(bdd);

return bdd;

}	



DdNode* scrivi_bdd_tre7 (DdManager *gbm, DdNode *bdd, DdNode * var) {

 DdNode* bdd_rec[128];
 DdNode *bdd1, *bdd2, *bdd3, *bdd4, *bdd5, *bdd6, *bdd7, *bdd8, *bdd9,*bdd10,*tmp,*tmp_neg,*bdd11;
     bdd = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd); /*Increases the reference count of a node*/
     int i; 
     
     for(i = 0; i < 128; i++){
     bdd_rec[i] = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd_rec[i]); /*Increases the reference count of a node*/
     } 
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
     bdd6 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd6); /*Increases the reference count of a node*/
     bdd7 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd7); /*Increases the reference count of a node*/
     bdd8 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd8); /*Increases the reference count of a node*/
     bdd9 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd9); /*Increases the reference count of a node*/
   
    Cudd_Ref(bdd);

    for (i = 0; i < 8; i++) {
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
     if(i != 0 && i != 6) {
      tmp_neg = Cudd_Not(var); /*Perform NOT Boolean operation*/
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd); /*Perform AND Boolean operation*/
      }else{
      tmp = Cudd_bddAnd(gbm,var,bdd); /*Perform AND Boolean operation*/
     }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd);
      bdd = tmp;
    }
   
    

    int j;int k = 0;
     for(j = 0;j<128;j++){ 
       for (i = 8; i < 16; i++) {
          var = Cudd_bddIthVar(gbm,i); 
          if(i%8 ==  0) {
          //tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, var, bdd_rec[j]); 
	  }
	  else if(i == 9+k && j < 64 ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
          }else if(i == 9+k && j >= 64) {
	  tmp = Cudd_bddAnd(gbm, var, bdd_rec[j]); 
          }
	  else if ( (i == 10 + k) && ( ( j < 32 ) || ( j >= 64 && j < 96 ) ) ) {
          tmp_neg = Cudd_Not(var);
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
          } else if ( i == 10 + k && ( ( j >= 32 && j < 64 ) || ( j >= 96 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
	  } else if (i == 11 + k && ( (j<16) || (j>=32 && j<48) || (j>=64 && j<80) || (j>=96 && j<112) ) ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	  } else if (i == 11 + k && ( (j >= 16 && j < 32) || ( j >= 48 && j < 64 ) || ( j >= 80 && j < 96 ) || ( j >= 112 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
          } else if ( i == 12 + k && ( ( j < 8 ) || ( j >= 16 && j < 24) || (j >= 32 && j < 40) || (j>=48 && j<56) || ( j >= 64 && j < 72 ) || 
		    (j >= 80 && j < 88) || (j >= 96 && j < 104) || (j>=112 && j<120) ) ) {
	   tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
           } else if (i == 12 + k && ( ( j >= 8 && j < 16 ) || ( j >= 24 && j < 32 ) || ( j >= 40 && j < 48) || ( j >= 56 && j < 64) 
			|| (j>72 && j<=80) || (j>=88 && j<96) || (j>=104 && j<112) || (j>=120) ) ) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]);  
 	   } else if (i == 13 + k && ( (j < 4) || (j >= 8 && j < 12) || (j >= 16 && j < 20) || (j >= 24 && j < 28) || (j >= 32 && j < 36) || (j >= 40 && j < 44)
			|| (j >= 48 && j < 52)  || (j >= 56 && j < 60)|| (j >= 64 && j < 68) || (j >= 72 && j < 76) || (j >= 80 && j < 84) || (j >= 88 && j < 92) 	
			|| (j >= 96 && j < 100) || (j >= 104 && j < 108) || (j >= 112 && j < 116) || (j >= 120 && j < 124))) {
	   tmp_neg = Cudd_Not(var);
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   
	   } else if (i == 13 + k && ( (j>=4 && j<8) || ( j >= 12 && j < 16 ) || ( j >= 20 && j < 24 ) || ( j >= 28 && j < 32 ) || ( j >= 36 && j < 40 ) 
			|| ( j >= 44 && j < 48 ) || ( j >= 52 && j < 56 ) || ( j >= 60 && j < 64 ) || ( j >= 68 && j < 72 ) || ( j >= 76 && j < 80 ) 	  
		        || ( j >= 84 && j < 88 ) || ( j >= 92 && j < 96 ) || ( j >= 100 && j < 104 ) || ( j >= 108 && j < 112 ) 
			|| ( j >= 116 && j < 120  ) 	|| ( j >= 124 && j < 128 ))) {
          
		   tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
           } else if ( i == 14 + k && ( (j<2) || (j>=4 && j<6)  || (j>=8 && j<10) || (j>=12 && j<14) || (j>=16 && j<18) || (j>=20 && j<22) || (j>=24 && j<26)
			|| (j>=28 && j<30) || (j>=32 && j<34) || (j>=36 && j<38) || (j>=40 && j<42) || (j>=44 && j<46) || (j>=48 && j<50) || (j>=52 && j<54) 	  
			|| (j>=56 && j<58) || (j>=60 && j<62) || (j>=64 && j<66) || (j>=68 && j<70) || (j>=72 && j<74) || (j>=76 && j<78) || (j>=80 && j<82) 
                	|| (j>=84 && j<86) || (j>=88 && j<90) || (j>=92 && j<94) || (j>=96 && j<98) || (j>=100 && j<102) || (j>=104 && j<106) || (j>=108 && j<110) || 
                	(j>=112 && j<114) || (j>=116 && j<118)     || (j>=120 && j<122) || (j>=124 && j<126)
			)) {
	    tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   } else if (i == 14 + k && ( (j>=2 && j<4) || (j>=6 && j<8) || (j>=10 && j<12) || (j>=14 && j<16) || (j>=18 && j<20) || (j>=22 && j<24) || (j>=26 && j<28)
			|| (j>=30 && j<32) || (j>=34 && j<36) || (j>=38 && j<40) || (j>=42 && j<44) || (j>=46 && j<48) || (j>=50 && j<52) 
			|| (j>=54 && j<56) || (j>=58 && j<60) || (j>=62 && j<64) || (j>=66 && j<68) || (j>=70 && j<72) || (j>=74 && j<76) 
			|| (j>=78 && j<80) || (j>=82 && j<84) || (j>=86 && j<88) || (j>=90 && j<92) || (j>=94 && j<96)
                        || (j>=98 && j<100) || (j>=102 && j<104) || (j>=106 && j<108) || (j>=110 && j<112) || (j>=114 && j<116) 
			|| (j>=118 && j<120) || (j>=122 && j<124) || (j>=126 && j<128) )) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 

	   } else if (i == 15 + k && j % 2 == 0) {
	   
	    tmp_neg = Cudd_Not(var); 
	    tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   
	   } else if (i == 15 + k && j % 2 == 1) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 

	   }
	  
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd_rec[j]);
      bdd_rec[j] = tmp;
    }
  }
    
    bdd1 = Cudd_bddOr(gbm,bdd_rec[0],bdd_rec[1]); 
    Cudd_Ref(bdd1);   
    
    for (k = 2;k<128;k++) {
    bdd1 = Cudd_bddOr(gbm,bdd1,bdd_rec[k]);
    Cudd_Ref(bdd1);   
     }
    bdd = Cudd_bddAnd(gbm,bdd,bdd1);
    Cudd_Ref(bdd);   

/*
     for(j = 0;j<128;j++){ 
       for (i = 16; i < 24; i++) {
          var = Cudd_bddIthVar(gbm,i); 
          if(i%8 ==  0) {
          //tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, var, bdd_rec[j]); 
	  }
	  else if(i == 17+k && j < 64 ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
          }else if(i == 17+k && j >= 64) {
	  tmp = Cudd_bddAnd(gbm, var, bdd_rec[j]); 
          }
	  else if ( (i == 18 + k) && ( ( j < 32 ) || ( j >= 64 && j < 96 ) ) ) {
          tmp_neg = Cudd_Not(var);
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
          } else if ( i == 18 + k && ( ( j >= 32 && j < 64 ) || ( j >= 96 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
	  } else if (i == 19 + k && ( (j<16) || (j>=32 && j<48) || (j>=64 && j<80) || (j>=96 && j<112) ) ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	  } else if (i == 19 + k && ( (j >= 16 && j < 32) || ( j >= 48 && j < 64 ) || ( j >= 80 && j < 96 ) || ( j >= 112 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
          } else if ( i == 20 + k && ( ( j < 8 ) || ( j >= 16 && j < 24) || (j >= 32 && j < 40) || (j>=48 && j<56) || ( j >= 64 && j < 72 ) || 
		    (j >= 80 && j < 88) || (j >= 96 && j < 104) || (j>=112 && j<120) ) ) {
	   tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
           } else if (i == 20 + k && ( ( j >= 8 && j < 16 ) || ( j >= 24 && j < 32 ) || ( j >= 40 && j < 48) || ( j >= 56 && j < 64) 
			|| (j>72 && j<=80) || (j>=88 && j<96) || (j>=104 && j<112) || (j>=120) ) ) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]);  
 	   } else if (i == 21 + k && ( (j < 4) || (j >= 8 && j < 12) || (j >= 16 && j < 20) || (j >= 24 && j < 28) || (j >= 32 && j < 36) || (j >= 40 && j < 44)
			|| (j >= 48 && j < 52)  || (j >= 56 && j < 60)|| (j >= 64 && j < 68) || (j >= 72 && j < 76) || (j >= 80 && j < 84) || (j >= 88 && j < 92) 	
			|| (j >= 96 && j < 100) || (j >= 104 && j < 108) || (j >= 112 && j < 116) || (j >= 120 && j < 124))) {
	   tmp_neg = Cudd_Not(var);
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   
	   } else if (i == 21 + k && ( (j>=4 && j<8) || ( j >= 12 && j < 16 ) || ( j >= 20 && j < 24 ) || ( j >= 28 && j < 32 ) || ( j >= 36 && j < 40 ) 
			|| ( j >= 44 && j < 48 ) || ( j >= 52 && j < 56 ) || ( j >= 60 && j < 64 ) || ( j >= 68 && j < 72 ) || ( j >= 76 && j < 80 ) 	  
		        || ( j >= 84 && j < 88 ) || ( j >= 92 && j < 96 ) || ( j >= 100 && j < 104 ) || ( j >= 108 && j < 112 ) 
			|| ( j >= 116 && j < 120  ) 	|| ( j >= 124 && j < 128 ))) {
          
		   tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
           } else if ( i == 22 + k && ( (j<2) || (j>=4 && j<6)  || (j>=8 && j<10) || (j>=12 && j<14) || (j>=16 && j<18) || (j>=20 && j<22) || (j>=24 && j<26)
			|| (j>=28 && j<30) || (j>=32 && j<34) || (j>=36 && j<38) || (j>=40 && j<42) || (j>=44 && j<46) || (j>=48 && j<50) || (j>=52 && j<54) 	  
			|| (j>=56 && j<58) || (j>=60 && j<62) || (j>=64 && j<66) || (j>=68 && j<70) || (j>=72 && j<74) || (j>=76 && j<78) || (j>=80 && j<82) 
                	|| (j>=84 && j<86) || (j>=88 && j<90) || (j>=92 && j<94) || (j>=96 && j<98) || (j>=100 && j<102) || (j>=104 && j<106) || (j>=108 && j<110) || 
                	(j>=112 && j<114) || (j>=116 && j<118)     || (j>=120 && j<122) || (j>=124 && j<126)
			)) {
	    tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   } else if (i == 22 + k && ( (j>=2 && j<4) || (j>=6 && j<8) || (j>=10 && j<12) || (j>=14 && j<16) || (j>=18 && j<20) || (j>=22 && j<24) || (j>=26 && j<28)
			|| (j>=30 && j<32) || (j>=34 && j<36) || (j>=38 && j<40) || (j>=42 && j<44) || (j>=46 && j<48) || (j>=50 && j<52) 
			|| (j>=54 && j<56) || (j>=58 && j<60) || (j>=62 && j<64) || (j>=66 && j<68) || (j>=70 && j<72) || (j>=74 && j<76) 
			|| (j>=78 && j<80) || (j>=82 && j<84) || (j>=86 && j<88) || (j>=90 && j<92) || (j>=94 && j<96)
                        || (j>=98 && j<100) || (j>=102 && j<104) || (j>=106 && j<108) || (j>=110 && j<112) || (j>=114 && j<116) 
			|| (j>=118 && j<120) || (j>=122 && j<124) || (j>=126 && j<128) )) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 

	   } else if (i == 23 + k && j % 2 == 0) {
	   
	    tmp_neg = Cudd_Not(var); 
	    tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   
	   } else if (i == 23 + k && j % 2 == 1) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 

	   }
	  
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd_rec[j]);
      bdd_rec[j] = tmp;
    }
  }
    

    bdd9 = Cudd_bddOr(gbm,bdd_rec[0],bdd_rec[1]); 
    Cudd_Ref(bdd1);   
    
    for (k = 2;k<128;k++) {
    bdd9 = Cudd_bddOr(gbm,bdd9,bdd_rec[k]);
    Cudd_Ref(bdd1);   
    }

    bdd = Cudd_bddAnd(gbm,bdd,bdd9);
    Cudd_Ref(bdd);   

     for(j = 0;j<128;j++){ 
       for (i = 24; i < 32; i++) {
          var = Cudd_bddIthVar(gbm,i); 
          if(i%8 ==  0) {
          //tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, var, bdd_rec[j]); 
	  }
	  else if(i == 25+k && j < 64 ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
          }else if(i == 25+k && j >= 64) {
	  tmp = Cudd_bddAnd(gbm, var, bdd_rec[j]); 
          }
	  else if ( (i == 26 + k) && ( ( j < 32 ) || ( j >= 64 && j < 96 ) ) ) {
          tmp_neg = Cudd_Not(var);
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
          } else if ( i == 26 + k && ( ( j >= 32 && j < 64 ) || ( j >= 96 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
	  } else if (i == 27 + k && ( (j<16) || (j>=32 && j<48) || (j>=64 && j<80) || (j>=96 && j<112) ) ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	  } else if (i == 27 + k && ( (j >= 16 && j < 32) || ( j >= 48 && j < 64 ) || ( j >= 80 && j < 96 ) || ( j >= 112 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
          } else if ( i == 28 + k && ( ( j < 8 ) || ( j >= 16 && j < 24) || (j >= 32 && j < 40) || (j>=48 && j<56) || ( j >= 64 && j < 72 ) || 
		    (j >= 80 && j < 88) || (j >= 96 && j < 104) || (j>=112 && j<120) ) ) {
	   tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
           } else if (i == 28 + k && ( ( j >= 8 && j < 16 ) || ( j >= 24 && j < 32 ) || ( j >= 40 && j < 48) || ( j >= 56 && j < 64) 
			|| (j>72 && j<=80) || (j>=88 && j<96) || (j>=104 && j<112) || (j>=120) ) ) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]);  
 	   } else if (i == 29 + k && ( (j < 4) || (j >= 8 && j < 12) || (j >= 16 && j < 20) || (j >= 24 && j < 28) || (j >= 32 && j < 36) || (j >= 40 && j < 44)
			|| (j >= 48 && j < 52)  || (j >= 56 && j < 60)|| (j >= 64 && j < 68) || (j >= 72 && j < 76) || (j >= 80 && j < 84) || (j >= 88 && j < 92) 	
			|| (j >= 96 && j < 100) || (j >= 104 && j < 108) || (j >= 112 && j < 116) || (j >= 120 && j < 124))) {
	   tmp_neg = Cudd_Not(var);
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   
	   } else if (i == 29 + k && ( (j>=4 && j<8) || ( j >= 12 && j < 16 ) || ( j >= 20 && j < 24 ) || ( j >= 28 && j < 32 ) || ( j >= 36 && j < 40 ) 
			|| ( j >= 44 && j < 48 ) || ( j >= 52 && j < 56 ) || ( j >= 60 && j < 64 ) || ( j >= 68 && j < 72 ) || ( j >= 76 && j < 80 ) 	  
		        || ( j >= 84 && j < 88 ) || ( j >= 92 && j < 96 ) || ( j >= 100 && j < 104 ) || ( j >= 108 && j < 112 ) 
			|| ( j >= 116 && j < 120  ) 	|| ( j >= 124 && j < 128 ))) {
          
		   tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
           } else if ( i == 30 + k && ( (j<2) || (j>=4 && j<6)  || (j>=8 && j<10) || (j>=12 && j<14) || (j>=16 && j<18) || (j>=20 && j<22) || (j>=24 && j<26)
			|| (j>=28 && j<30) || (j>=32 && j<34) || (j>=36 && j<38) || (j>=40 && j<42) || (j>=44 && j<46) || (j>=48 && j<50) || (j>=52 && j<54) 	  
			|| (j>=56 && j<58) || (j>=60 && j<62) || (j>=64 && j<66) || (j>=68 && j<70) || (j>=72 && j<74) || (j>=76 && j<78) || (j>=80 && j<82) 
                	|| (j>=84 && j<86) || (j>=88 && j<90) || (j>=92 && j<94) || (j>=96 && j<98) || (j>=100 && j<102) || (j>=104 && j<106) || (j>=108 && j<110) || 
                	(j>=112 && j<114) || (j>=116 && j<118)     || (j>=120 && j<122) || (j>=124 && j<126)
			)) {
	    tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   } else if (i == 30 + k && ( (j>=2 && j<4) || (j>=6 && j<8) || (j>=10 && j<12) || (j>=14 && j<16) || (j>=18 && j<20) || (j>=22 && j<24) || (j>=26 && j<28)
			|| (j>=30 && j<32) || (j>=34 && j<36) || (j>=38 && j<40) || (j>=42 && j<44) || (j>=46 && j<48) || (j>=50 && j<52) 
			|| (j>=54 && j<56) || (j>=58 && j<60) || (j>=62 && j<64) || (j>=66 && j<68) || (j>=70 && j<72) || (j>=74 && j<76) 
			|| (j>=78 && j<80) || (j>=82 && j<84) || (j>=86 && j<88) || (j>=90 && j<92) || (j>=94 && j<96)
                        || (j>=98 && j<100) || (j>=102 && j<104) || (j>=106 && j<108) || (j>=110 && j<112) || (j>=114 && j<116) 
			|| (j>=118 && j<120) || (j>=122 && j<124) || (j>=126 && j<128) )) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 

	   } else if (i == 31 + k && j % 2 == 0) {
	   
	    tmp_neg = Cudd_Not(var); 
	    tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   
	   } else if (i == 31 + k && j % 2 == 1) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 

	   }
	  
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd_rec[j]);
      bdd_rec[j] = tmp;
    }
  }
    
    bdd10 = Cudd_bddOr(gbm,bdd_rec[0],bdd_rec[1]); 
    Cudd_Ref(bdd10);   
    
    for (k = 2;k<128;k++) {
    bdd10 = Cudd_bddOr(gbm,bdd10,bdd_rec[k]);
    Cudd_Ref(bdd10);   
     }
    bdd = Cudd_bddAnd(gbm,bdd,bdd10);
    Cudd_Ref(bdd);   
*/
	/*
     for(j = 0;j<128;j++){ 
       for (i = 32; i < 40; i++) {
          var = Cudd_bddIthVar(gbm,i); 
          if(i%8 ==  0) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	  }
	  else if(i == 33+k && j < 64 ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
          }else if(i == 33+k && j >= 64) {
	  tmp = Cudd_bddAnd(gbm, var, bdd_rec[j]); 
          }
	  else if ( (i == 34 + k) && ( ( j < 32 ) || ( j >= 64 && j < 96 ) ) ) {
          tmp_neg = Cudd_Not(var);
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
          } else if ( i == 34 + k && ( ( j >= 32 && j < 64 ) || ( j >= 96 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
	  } else if (i == 35 + k && ( (j<16) || (j>=32 && j<48) || (j>=64 && j<80) || (j>=96 && j<112) ) ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	  } else if (i == 35 + k && ( (j >= 16 && j < 32) || ( j >= 48 && j < 64 ) || ( j >= 80 && j < 96 ) || ( j >= 112 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
          } else if ( i == 36 + k && ( ( j < 8 ) || ( j >= 16 && j < 24) || (j >= 32 && j < 40) || (j>=48 && j<56) || ( j >= 64 && j < 72 ) || 
		    (j >= 80 && j < 88) || (j >= 96 && j < 104) || (j>=112 && j<120) ) ) {
	   tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
           } else if (i == 36 + k && ( ( j >= 8 && j < 16 ) || ( j >= 24 && j < 32 ) || ( j >= 40 && j < 48) || ( j >= 56 && j < 64) 
			|| (j>72 && j<=80) || (j>=88 && j<96) || (j>=104 && j<112) || (j>=120) ) ) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]);  
 	   } else if (i == 37 + k && ( (j < 4) || (j >= 8 && j < 12) || (j >= 16 && j < 20) || (j >= 24 && j < 28) || (j >= 32 && j < 36) || (j >= 40 && j < 44)
			|| (j >= 48 && j < 52)  || (j >= 56 && j < 60)|| (j >= 64 && j < 68) || (j >= 72 && j < 76) || (j >= 80 && j < 84) || (j >= 88 && j < 92) 	
			|| (j >= 96 && j < 100) || (j >= 104 && j < 108) || (j >= 112 && j < 116) || (j >= 120 && j < 124))) {
	   tmp_neg = Cudd_Not(var);
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   
	   } else if (i == 37 + k && ( (j>=4 && j<8) || ( j >= 12 && j < 16 ) || ( j >= 20 && j < 24 ) || ( j >= 28 && j < 32 ) || ( j >= 36 && j < 40 ) 
			|| ( j >= 44 && j < 48 ) || ( j >= 52 && j < 56 ) || ( j >= 60 && j < 64 ) || ( j >= 68 && j < 72 ) || ( j >= 76 && j < 80 ) 	  
		        || ( j >= 84 && j < 88 ) || ( j >= 92 && j < 96 ) || ( j >= 100 && j < 104 ) || ( j >= 108 && j < 112 ) 
			|| ( j >= 116 && j < 120  ) 	|| ( j >= 124 && j < 128 ))) {
          
		   tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
           } else if ( i == 38 + k && ( (j<2) || (j>=4 && j<6)  || (j>=8 && j<10) || (j>=12 && j<14) || (j>=16 && j<18) || (j>=20 && j<22) || (j>=24 && j<26)
			|| (j>=28 && j<30) || (j>=32 && j<34) || (j>=36 && j<38) || (j>=40 && j<42) || (j>=44 && j<46) || (j>=48 && j<50) || (j>=52 && j<54) 	  
			|| (j>=56 && j<58) || (j>=60 && j<62) || (j>=64 && j<66) || (j>=68 && j<70) || (j>=72 && j<74) || (j>=76 && j<78) || (j>=80 && j<82) 
                	|| (j>=84 && j<86) || (j>=88 && j<90) || (j>=92 && j<94) || (j>=96 && j<98) || (j>=100 && j<102) || (j>=104 && j<106) || (j>=108 && j<110) || 
                	(j>=112 && j<114) || (j>=116 && j<118)     || (j>=120 && j<122) || (j>=124 && j<126)
			)) {
	    tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   } else if (i == 38 + k && ( (j>=2 && j<4) || (j>=6 && j<8) || (j>=10 && j<12) || (j>=14 && j<16) || (j>=18 && j<20) || (j>=22 && j<24) || (j>=26 && j<28)
			|| (j>=30 && j<32) || (j>=34 && j<36) || (j>=38 && j<40) || (j>=42 && j<44) || (j>=46 && j<48) || (j>=50 && j<52) 
			|| (j>=54 && j<56) || (j>=58 && j<60) || (j>=62 && j<64) || (j>=66 && j<68) || (j>=70 && j<72) || (j>=74 && j<76) 
			|| (j>=78 && j<80) || (j>=82 && j<84) || (j>=86 && j<88) || (j>=90 && j<92) || (j>=94 && j<96)
                        || (j>=98 && j<100) || (j>=102 && j<104) || (j>=106 && j<108) || (j>=110 && j<112) || (j>=114 && j<116) 
			|| (j>=118 && j<120) || (j>=122 && j<124) || (j>=126 && j<128) )) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 

	   } else if (i == 39 + k && j % 2 == 0) {
	   
	    tmp_neg = Cudd_Not(var); 
	    tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   
	   } else if (i == 39 + k && j % 2 == 1) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 

	   }
	  
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd_rec[j]);
      bdd_rec[j] = tmp;
    }
  }
    bdd11 = Cudd_bddOr(gbm,bdd_rec[0],bdd_rec[1]); 
    Cudd_Ref(bdd11);   
    
    for (k = 2;k<128;k++) {
    bdd11 = Cudd_bddOr(gbm,bdd11,bdd_rec[k]);
    Cudd_Ref(bdd11);   
     }
    bdd = Cudd_bddAnd(gbm,bdd,bdd11);
    Cudd_Ref(bdd);   

    for (i = 40; i < 48; i++) {
     var = Cudd_bddIthVar(gbm,i); 
     
      tmp_neg = Cudd_Not(var); 
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd2); 
    
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd2);
      bdd2 = tmp;
    }
   
    bdd = Cudd_bddAnd(gbm,bdd,bdd2);
    Cudd_Ref(bdd);
    
    for (i = 48; i < 56; i++) {
     var = Cudd_bddIthVar(gbm,i);
     if(i != 52 && i != 54){
      tmp_neg = Cudd_Not(var); 
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd3); 
     }else{
      tmp = Cudd_bddAnd(gbm, var, bdd3); 
     }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd3);
      bdd3 = tmp;
    }
    
    bdd = Cudd_bddAnd(gbm,bdd,bdd3);
    Cudd_Ref(bdd);
    */
    DdNode* bdd71;
   
    bdd71 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd71); /*Increases the reference count of a node*/

     for (i = 16; i < 18; i++) {  
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd71); 
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd71);
      bdd71 = tmp;
    }
    
    
    bdd = Cudd_bddAnd(gbm,bdd,bdd71);
    Cudd_Ref(bdd);
    
  
return bdd;

    

}



//FUNZIONI UNSUBACK 

DdNode* scrivi_bdd_zero8 (DdManager *gbm, DdNode *bdd, DdNode * var) 
{
     DdNode* bdd_rec[128];
     DdNode* bdd_rec2[128];
     
     DdNode *bdd1, *bdd2, *bdd3, *bdd4, *bdd5, *bdd6, *bdd7, *bdd8, *bdd9,*tmp,*tmp_neg;
     bdd = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd); /*Increases the reference count of a node*/
     int i; 
     
     for(i = 0; i < 128; i++){
     bdd_rec[i] = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd_rec[i]); /*Increases the reference count of a node*/
     } 
     for(i = 0; i < 128; i++){
     bdd_rec2[i] = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd_rec2[i]); /*Increases the reference count of a node*/
     } 

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
     bdd6 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd6); /*Increases the reference count of a node*/
     bdd7 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd7); /*Increases the reference count of a node*/
     bdd8 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd8); /*Increases the reference count of a node*/
   
     
     for (i = 0; i < 8; i++) {
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
     if(i != 0 && i != 2 && i != 3) {
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

    Cudd_Ref(bdd);
    bdd = Cudd_bddAnd(gbm,bdd,bdd1);

    
    int j,k;
/*
     for(j = 0;j<128;j++){ 
       for (i = 16; i < 24; i++) {
          var = Cudd_bddIthVar(gbm,i); 
          if(i%8 ==  0) {
          //tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, var, bdd_rec[j]); 
	  }
	  else if(i == 17+k && j < 64 ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
          }else if(i == 17+k && j >= 64) {
	  tmp = Cudd_bddAnd(gbm, var, bdd_rec[j]); 
          }
	  else if ( (i == 18 + k) && ( ( j < 32 ) || ( j >= 64 && j < 96 ) ) ) {
          tmp_neg = Cudd_Not(var);
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
          } else if ( i == 18 + k && ( ( j >= 32 && j < 64 ) || ( j >= 96 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
	  } else if (i == 19 + k && ( (j<16) || (j>=32 && j<48) || (j>=64 && j<80) || (j>=96 && j<112) ) ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	  } else if (i == 19 + k && ( (j >= 16 && j < 32) || ( j >= 48 && j < 64 ) || ( j >= 80 && j < 96 ) || ( j >= 112 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
          } else if ( i == 20 + k && ( ( j < 8 ) || ( j >= 16 && j < 24) || (j >= 32 && j < 40) || (j>=48 && j<56) || ( j >= 64 && j < 72 ) || 
		    (j >= 80 && j < 88) || (j >= 96 && j < 104) || (j>=112 && j<120) ) ) {
	   tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
           } else if (i == 20 + k && ( ( j >= 8 && j < 16 ) || ( j >= 24 && j < 32 ) || ( j >= 40 && j < 48) || ( j >= 56 && j < 64) 
			|| (j>72 && j<=80) || (j>=88 && j<96) || (j>=104 && j<112) || (j>=120) ) ) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]);  
 	   } else if (i == 21 + k && ( (j < 4) || (j >= 8 && j < 12) || (j >= 16 && j < 20) || (j >= 24 && j < 28) || (j >= 32 && j < 36) || (j >= 40 && j < 44)
			|| (j >= 48 && j < 52)  || (j >= 56 && j < 60)|| (j >= 64 && j < 68) || (j >= 72 && j < 76) || (j >= 80 && j < 84) || (j >= 88 && j < 92) 	
			|| (j >= 96 && j < 100) || (j >= 104 && j < 108) || (j >= 112 && j < 116) || (j >= 120 && j < 124))) {
	   tmp_neg = Cudd_Not(var);
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   
	   } else if (i == 21 + k && ( (j>=4 && j<8) || ( j >= 12 && j < 16 ) || ( j >= 20 && j < 24 ) || ( j >= 28 && j < 32 ) || ( j >= 36 && j < 40 ) 
			|| ( j >= 44 && j < 48 ) || ( j >= 52 && j < 56 ) || ( j >= 60 && j < 64 ) || ( j >= 68 && j < 72 ) || ( j >= 76 && j < 80 ) 	  
		        || ( j >= 84 && j < 88 ) || ( j >= 92 && j < 96 ) || ( j >= 100 && j < 104 ) || ( j >= 108 && j < 112 ) 
			|| ( j >= 116 && j < 120  ) 	|| ( j >= 124 && j < 128 ))) {
          
		   tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
           } else if ( i == 22 + k && ( (j<2) || (j>=4 && j<6)  || (j>=8 && j<10) || (j>=12 && j<14) || (j>=16 && j<18) || (j>=20 && j<22) || (j>=24 && j<26)
			|| (j>=28 && j<30) || (j>=32 && j<34) || (j>=36 && j<38) || (j>=40 && j<42) || (j>=44 && j<46) || (j>=48 && j<50) || (j>=52 && j<54) 	  
			|| (j>=56 && j<58) || (j>=60 && j<62) || (j>=64 && j<66) || (j>=68 && j<70) || (j>=72 && j<74) || (j>=76 && j<78) || (j>=80 && j<82) 
                	|| (j>=84 && j<86) || (j>=88 && j<90) || (j>=92 && j<94) || (j>=96 && j<98) || (j>=100 && j<102) || (j>=104 && j<106) || (j>=108 && j<110) || 
                	(j>=112 && j<114) || (j>=116 && j<118)     || (j>=120 && j<122) || (j>=124 && j<126)
			)) {
	    tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   } else if (i == 22 + k && ( (j>=2 && j<4) || (j>=6 && j<8) || (j>=10 && j<12) || (j>=14 && j<16) || (j>=18 && j<20) || (j>=22 && j<24) || (j>=26 && j<28)
			|| (j>=30 && j<32) || (j>=34 && j<36) || (j>=38 && j<40) || (j>=42 && j<44) || (j>=46 && j<48) || (j>=50 && j<52) 
			|| (j>=54 && j<56) || (j>=58 && j<60) || (j>=62 && j<64) || (j>=66 && j<68) || (j>=70 && j<72) || (j>=74 && j<76) 
			|| (j>=78 && j<80) || (j>=82 && j<84) || (j>=86 && j<88) || (j>=90 && j<92) || (j>=94 && j<96)
                        || (j>=98 && j<100) || (j>=102 && j<104) || (j>=106 && j<108) || (j>=110 && j<112) || (j>=114 && j<116) 
			|| (j>=118 && j<120) || (j>=122 && j<124) || (j>=126 && j<128) )) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 

	   } else if (i == 23 + k && j % 2 == 0) {
	   
	    tmp_neg = Cudd_Not(var); 
	    tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   
	   } else if (i == 23 + k && j % 2 == 1) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 

	   }
	  
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd_rec[j]);
      bdd_rec[j] = tmp;
    }
  }
    

    bdd9 = Cudd_bddOr(gbm,bdd_rec[0],bdd_rec[1]); 
    Cudd_Ref(bdd1);   
    
    for (k = 2;k<128;k++) {
    bdd9 = Cudd_bddOr(gbm,bdd9,bdd_rec[k]);
    }

     
     for(j = 0;j<128;j++){ 
       for (i = 16; i < 24; i++) {
          var = Cudd_bddIthVar(gbm,i); 
          if(i%8 ==  0) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec2[j]); 
	  }
	  else if(i == 17+k && j < 64 ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec2[j]); 
          }else if(i == 17+k && j >= 64) {
	  tmp = Cudd_bddAnd(gbm, var, bdd_rec2[j]); 
          }
	  else if ( (i == 18 + k) && ( ( j < 32 ) || ( j >= 64 && j < 96 ) ) ) {
          tmp_neg = Cudd_Not(var);
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec2[j]); 
          } else if ( i == 18 + k && ( ( j >= 32 && j < 64 ) || ( j >= 96 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec2[j]); 
	  } else if (i == 19 + k && ( (j<16) || (j>=32 && j<48) || (j>=64 && j<80) || (j>=96 && j<112) ) ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec2[j]); 
	  } else if (i == 19 + k && ( (j >= 16 && j < 32) || ( j >= 48 && j < 64 ) || ( j >= 80 && j < 96 ) || ( j >= 112 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec2[j]); 
          } else if ( i == 20 + k && ( ( j < 8 ) || ( j >= 16 && j < 24) || (j >= 32 && j < 40) || (j>=48 && j<56) || ( j >= 64 && j < 72 ) || 
		    (j >= 80 && j < 88) || (j >= 96 && j < 104) || (j>=112 && j<120) ) ) {
	   tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec2[j]); 
           } else if (i == 20 + k && ( ( j >= 8 && j < 16 ) || ( j >= 24 && j < 32 ) || ( j >= 40 && j < 48) || ( j >= 56 && j < 64) 
			|| (j>72 && j<=80) || (j>=88 && j<96) || (j>=104 && j<112) || (j>=120) ) ) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec2[j]);  
 	   } else if (i == 21 + k && ( (j < 4) || (j >= 8 && j < 12) || (j >= 16 && j < 20) || (j >= 24 && j < 28) || (j >= 32 && j < 36) || (j >= 40 && j < 44)
			|| (j >= 48 && j < 52)  || (j >= 56 && j < 60)|| (j >= 64 && j < 68) || (j >= 72 && j < 76) || (j >= 80 && j < 84) || (j >= 88 && j < 92) 	
			|| (j >= 96 && j < 100) || (j >= 104 && j < 108) || (j >= 112 && j < 116) || (j >= 120 && j < 124))) {
	   tmp_neg = Cudd_Not(var);
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec2[j]); 
	   
	   } else if (i == 21 + k && ( (j>=4 && j<8) || ( j >= 12 && j < 16 ) || ( j >= 20 && j < 24 ) || ( j >= 28 && j < 32 ) || ( j >= 36 && j < 40 ) 
			|| ( j >= 44 && j < 48 ) || ( j >= 52 && j < 56 ) || ( j >= 60 && j < 64 ) || ( j >= 68 && j < 72 ) || ( j >= 76 && j < 80 ) 	  
		        || ( j >= 84 && j < 88 ) || ( j >= 92 && j < 96 ) || ( j >= 100 && j < 104 ) || ( j >= 108 && j < 112 ) 
			|| ( j >= 116 && j < 120  ) 	|| ( j >= 124 && j < 128 ))) {
          
		   tmp = Cudd_bddAnd(gbm,var,bdd_rec2[j]); 
           } else if ( i == 22 + k && ( (j<2) || (j>=4 && j<6)  || (j>=8 && j<10) || (j>=12 && j<14) || (j>=16 && j<18) || (j>=20 && j<22) || (j>=24 && j<26)
			|| (j>=28 && j<30) || (j>=32 && j<34) || (j>=36 && j<38) || (j>=40 && j<42) || (j>=44 && j<46) || (j>=48 && j<50) || (j>=52 && j<54) 	  
			|| (j>=56 && j<58) || (j>=60 && j<62) || (j>=64 && j<66) || (j>=68 && j<70) || (j>=72 && j<74) || (j>=76 && j<78) || (j>=80 && j<82) 
                	|| (j>=84 && j<86) || (j>=88 && j<90) || (j>=92 && j<94) || (j>=96 && j<98) || (j>=100 && j<102) || (j>=104 && j<106) || (j>=108 && j<110) || 
                	(j>=112 && j<114) || (j>=116 && j<118)     || (j>=120 && j<122) || (j>=124 && j<126)
			)) {
	    tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec2[j]); 
	   } else if (i == 22 + k && ( (j>=2 && j<4) || (j>=6 && j<8) || (j>=10 && j<12) || (j>=14 && j<16) || (j>=18 && j<20) || (j>=22 && j<24) || (j>=26 && j<28)
			|| (j>=30 && j<32) || (j>=34 && j<36) || (j>=38 && j<40) || (j>=42 && j<44) || (j>=46 && j<48) || (j>=50 && j<52) 
			|| (j>=54 && j<56) || (j>=58 && j<60) || (j>=62 && j<64) || (j>=66 && j<68) || (j>=70 && j<72) || (j>=74 && j<76) 
			|| (j>=78 && j<80) || (j>=82 && j<84) || (j>=86 && j<88) || (j>=90 && j<92) || (j>=94 && j<96)
                        || (j>=98 && j<100) || (j>=102 && j<104) || (j>=106 && j<108) || (j>=110 && j<112) || (j>=114 && j<116) 
			|| (j>=118 && j<120) || (j>=122 && j<124) || (j>=126 && j<128) )) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec2[j]); 

	   } else if (i == 23 + k && j % 2 == 0) {
	   
	    tmp_neg = Cudd_Not(var); 
	    tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec2[j]); 
	   
	   } else if (i == 23 + k && j % 2 == 1) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec2[j]); 

	   }
	  
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd_rec2[j]);
      bdd_rec2[j] = tmp;
    }
  }   
    bdd3 = Cudd_bddOr(gbm,bdd_rec2[0],bdd_rec2[1]); 
    Cudd_Ref(bdd3);   
    
    for (k = 2;k<128;k++) {
    bdd3 = Cudd_bddOr(gbm,bdd3,bdd_rec2[k]);
    Cudd_Ref(bdd3);   
     }
    bdd2 = Cudd_bddOr(gbm,bdd9,bdd3);
    bdd = Cudd_bddAnd(gbm,bdd,bdd2);
    Cudd_Ref(bdd);   
*/
    DdNode* bdd71;
   
    bdd71 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd71); /*Increases the reference count of a node*/

     for (i = 16; i < 18; i++) {  
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd71); 
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd71);
      bdd71 = tmp;
    }
    
    
    bdd = Cudd_bddAnd(gbm,bdd,bdd71);
    Cudd_Ref(bdd);

    return bdd;

}




DdNode* scrivi_bdd_uno8 (DdManager *gbm, DdNode *bdd, DdNode * var) 
{
 
 DdNode* bdd_rec[128];
 DdNode* bdd_rec2[128];
 
 DdNode *bdd1, *bdd2, *bdd3, *bdd4, *bdd5, *bdd6, *bdd7, *bdd8, *bdd9,*bdd10,*tmp,*tmp_neg;
     bdd = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd); /*Increases the reference count of a node*/
     int i; 
     
     for(i = 0; i < 128; i++){
     bdd_rec2[i] = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd_rec2[i]); /*Increases the reference count of a node*/
     } 
     
     for(i = 0; i < 128; i++){
     bdd_rec[i] = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd_rec[i]); /*Increases the reference count of a node*/
     } 
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
     bdd6 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd6); /*Increases the reference count of a node*/
     bdd7 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd7); /*Increases the reference count of a node*/
     bdd8 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd8); /*Increases the reference count of a node*/
     bdd9 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd9); /*Increases the reference count of a node*/
  int j,k;
/*
     for(j = 0;j<128;j++){ 
       for (i = 24; i < 32; i++) {
          var = Cudd_bddIthVar(gbm,i); 
          if(i%8 ==  0) {
          //tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, var, bdd_rec[j]); 
	  }
	  else if(i == 25+k && j < 64 ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
          }else if(i == 25+k && j >= 64) {
	  tmp = Cudd_bddAnd(gbm, var, bdd_rec[j]); 
          }
	  else if ( (i == 26 + k) && ( ( j < 32 ) || ( j >= 64 && j < 96 ) ) ) {
          tmp_neg = Cudd_Not(var);
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
          } else if ( i == 26 + k && ( ( j >= 32 && j < 64 ) || ( j >= 96 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
	  } else if (i == 27 + k && ( (j<16) || (j>=32 && j<48) || (j>=64 && j<80) || (j>=96 && j<112) ) ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	  } else if (i == 27 + k && ( (j >= 16 && j < 32) || ( j >= 48 && j < 64 ) || ( j >= 80 && j < 96 ) || ( j >= 112 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
          } else if ( i == 28 + k && ( ( j < 8 ) || ( j >= 16 && j < 24) || (j >= 32 && j < 40) || (j>=48 && j<56) || ( j >= 64 && j < 72 ) || 
		    (j >= 80 && j < 88) || (j >= 96 && j < 104) || (j>=112 && j<120) ) ) {
	   tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
           } else if (i == 28 + k && ( ( j >= 8 && j < 16 ) || ( j >= 24 && j < 32 ) || ( j >= 40 && j < 48) || ( j >= 56 && j < 64) 
			|| (j>72 && j<=80) || (j>=88 && j<96) || (j>=104 && j<112) || (j>=120) ) ) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]);  
 	   } else if (i == 29 + k && ( (j < 4) || (j >= 8 && j < 12) || (j >= 16 && j < 20) || (j >= 24 && j < 28) || (j >= 32 && j < 36) || (j >= 40 && j < 44)
			|| (j >= 48 && j < 52)  || (j >= 56 && j < 60)|| (j >= 64 && j < 68) || (j >= 72 && j < 76) || (j >= 80 && j < 84) || (j >= 88 && j < 92) 	
			|| (j >= 96 && j < 100) || (j >= 104 && j < 108) || (j >= 112 && j < 116) || (j >= 120 && j < 124))) {
	   tmp_neg = Cudd_Not(var);
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   
	   } else if (i == 29 + k && ( (j>=4 && j<8) || ( j >= 12 && j < 16 ) || ( j >= 20 && j < 24 ) || ( j >= 28 && j < 32 ) || ( j >= 36 && j < 40 ) 
			|| ( j >= 44 && j < 48 ) || ( j >= 52 && j < 56 ) || ( j >= 60 && j < 64 ) || ( j >= 68 && j < 72 ) || ( j >= 76 && j < 80 ) 	  
		        || ( j >= 84 && j < 88 ) || ( j >= 92 && j < 96 ) || ( j >= 100 && j < 104 ) || ( j >= 108 && j < 112 ) 
			|| ( j >= 116 && j < 120  ) 	|| ( j >= 124 && j < 128 ))) {
          
		   tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
           } else if ( i == 30 + k && ( (j<2) || (j>=4 && j<6)  || (j>=8 && j<10) || (j>=12 && j<14) || (j>=16 && j<18) || (j>=20 && j<22) || (j>=24 && j<26)
			|| (j>=28 && j<30) || (j>=32 && j<34) || (j>=36 && j<38) || (j>=40 && j<42) || (j>=44 && j<46) || (j>=48 && j<50) || (j>=52 && j<54) 	  
			|| (j>=56 && j<58) || (j>=60 && j<62) || (j>=64 && j<66) || (j>=68 && j<70) || (j>=72 && j<74) || (j>=76 && j<78) || (j>=80 && j<82) 
                	|| (j>=84 && j<86) || (j>=88 && j<90) || (j>=92 && j<94) || (j>=96 && j<98) || (j>=100 && j<102) || (j>=104 && j<106) || (j>=108 && j<110) || 
                	(j>=112 && j<114) || (j>=116 && j<118)     || (j>=120 && j<122) || (j>=124 && j<126)
			)) {
	    tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   } else if (i == 30 + k && ( (j>=2 && j<4) || (j>=6 && j<8) || (j>=10 && j<12) || (j>=14 && j<16) || (j>=18 && j<20) || (j>=22 && j<24) || (j>=26 && j<28)
			|| (j>=30 && j<32) || (j>=34 && j<36) || (j>=38 && j<40) || (j>=42 && j<44) || (j>=46 && j<48) || (j>=50 && j<52) 
			|| (j>=54 && j<56) || (j>=58 && j<60) || (j>=62 && j<64) || (j>=66 && j<68) || (j>=70 && j<72) || (j>=74 && j<76) 
			|| (j>=78 && j<80) || (j>=82 && j<84) || (j>=86 && j<88) || (j>=90 && j<92) || (j>=94 && j<96)
                        || (j>=98 && j<100) || (j>=102 && j<104) || (j>=106 && j<108) || (j>=110 && j<112) || (j>=114 && j<116) 
			|| (j>=118 && j<120) || (j>=122 && j<124) || (j>=126 && j<128) )) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 

	   } else if (i == 31 + k && j % 2 == 0) {
	   
	    tmp_neg = Cudd_Not(var); 
	    tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   
	   } else if (i == 31 + k && j % 2 == 1) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 

	   }
	  
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd_rec[j]);
      bdd_rec[j] = tmp;
    }
  }
    
    bdd10 = Cudd_bddOr(gbm,bdd_rec[0],bdd_rec[1]); 
    Cudd_Ref(bdd10);   
    
    for (k = 2;k<128;k++) {
    bdd10 = Cudd_bddOr(gbm,bdd10,bdd_rec[k]);
    Cudd_Ref(bdd10);   
     }
    //bdd = Cudd_bddAnd(gbm,bdd,bdd10);
    //Cudd_Ref(bdd);   
     for(j = 0;j<128;j++){ 
       for (i = 24; i < 32; i++) {
          var = Cudd_bddIthVar(gbm,i); 
          if(i%8 ==  0) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec2[j]); 
	  }
	  else if(i == 25+k && j < 64 ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec2[j]); 
          }else if(i == 25+k && j >= 64) {
	  tmp = Cudd_bddAnd(gbm, var, bdd_rec2[j]); 
          }
	  else if ( (i == 26 + k) && ( ( j < 32 ) || ( j >= 64 && j < 96 ) ) ) {
          tmp_neg = Cudd_Not(var);
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec2[j]); 
          } else if ( i == 26 + k && ( ( j >= 32 && j < 64 ) || ( j >= 96 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec2[j]); 
	  } else if (i == 27 + k && ( (j<16) || (j>=32 && j<48) || (j>=64 && j<80) || (j>=96 && j<112) ) ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec2[j]); 
	  } else if (i == 27 + k && ( (j >= 16 && j < 32) || ( j >= 48 && j < 64 ) || ( j >= 80 && j < 96 ) || ( j >= 112 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec2[j]); 
          } else if ( i == 28 + k && ( ( j < 8 ) || ( j >= 16 && j < 24) || (j >= 32 && j < 40) || (j>=48 && j<56) || ( j >= 64 && j < 72 ) || 
		    (j >= 80 && j < 88) || (j >= 96 && j < 104) || (j>=112 && j<120) ) ) {
	   tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec2[j]); 
           } else if (i == 28 + k && ( ( j >= 8 && j < 16 ) || ( j >= 24 && j < 32 ) || ( j >= 40 && j < 48) || ( j >= 56 && j < 64) 
			|| (j>72 && j<=80) || (j>=88 && j<96) || (j>=104 && j<112) || (j>=120) ) ) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec2[j]);  
 	   } else if (i == 29 + k && ( (j < 4) || (j >= 8 && j < 12) || (j >= 16 && j < 20) || (j >= 24 && j < 28) || (j >= 32 && j < 36) || (j >= 40 && j < 44)
			|| (j >= 48 && j < 52)  || (j >= 56 && j < 60)|| (j >= 64 && j < 68) || (j >= 72 && j < 76) || (j >= 80 && j < 84) || (j >= 88 && j < 92) 	
			|| (j >= 96 && j < 100) || (j >= 104 && j < 108) || (j >= 112 && j < 116) || (j >= 120 && j < 124))) {
	   tmp_neg = Cudd_Not(var);
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec2[j]); 
	   
	   } else if (i == 29 + k && ( (j>=4 && j<8) || ( j >= 12 && j < 16 ) || ( j >= 20 && j < 24 ) || ( j >= 28 && j < 32 ) || ( j >= 36 && j < 40 ) 
			|| ( j >= 44 && j < 48 ) || ( j >= 52 && j < 56 ) || ( j >= 60 && j < 64 ) || ( j >= 68 && j < 72 ) || ( j >= 76 && j < 80 ) 	  
		        || ( j >= 84 && j < 88 ) || ( j >= 92 && j < 96 ) || ( j >= 100 && j < 104 ) || ( j >= 108 && j < 112 ) 
			|| ( j >= 116 && j < 120  ) 	|| ( j >= 124 && j < 128 ))) {
          
		   tmp = Cudd_bddAnd(gbm,var,bdd_rec2[j]); 
           } else if ( i == 30 + k && ( (j<2) || (j>=4 && j<6)  || (j>=8 && j<10) || (j>=12 && j<14) || (j>=16 && j<18) || (j>=20 && j<22) || (j>=24 && j<26)
			|| (j>=28 && j<30) || (j>=32 && j<34) || (j>=36 && j<38) || (j>=40 && j<42) || (j>=44 && j<46) || (j>=48 && j<50) || (j>=52 && j<54) 	  
			|| (j>=56 && j<58) || (j>=60 && j<62) || (j>=64 && j<66) || (j>=68 && j<70) || (j>=72 && j<74) || (j>=76 && j<78) || (j>=80 && j<82) 
                	|| (j>=84 && j<86) || (j>=88 && j<90) || (j>=92 && j<94) || (j>=96 && j<98) || (j>=100 && j<102) || (j>=104 && j<106) || (j>=108 && j<110) || 
                	(j>=112 && j<114) || (j>=116 && j<118)     || (j>=120 && j<122) || (j>=124 && j<126)
			)) {
	    tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec2[j]); 
	   } else if (i == 30 + k && ( (j>=2 && j<4) || (j>=6 && j<8) || (j>=10 && j<12) || (j>=14 && j<16) || (j>=18 && j<20) || (j>=22 && j<24) || (j>=26 && j<28)
			|| (j>=30 && j<32) || (j>=34 && j<36) || (j>=38 && j<40) || (j>=42 && j<44) || (j>=46 && j<48) || (j>=50 && j<52) 
			|| (j>=54 && j<56) || (j>=58 && j<60) || (j>=62 && j<64) || (j>=66 && j<68) || (j>=70 && j<72) || (j>=74 && j<76) 
			|| (j>=78 && j<80) || (j>=82 && j<84) || (j>=86 && j<88) || (j>=90 && j<92) || (j>=94 && j<96)
                        || (j>=98 && j<100) || (j>=102 && j<104) || (j>=106 && j<108) || (j>=110 && j<112) || (j>=114 && j<116) 
			|| (j>=118 && j<120) || (j>=122 && j<124) || (j>=126 && j<128) )) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec2[j]); 

	   } else if (i == 31 + k && j % 2 == 0) {
	   
	    tmp_neg = Cudd_Not(var); 
	    tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec2[j]); 
	   
	   } else if (i == 31 + k && j % 2 == 1) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec2[j]); 

	   }
	  
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd_rec2[j]);
      bdd_rec2[j] = tmp;
    }
  }
    
    bdd9 = Cudd_bddOr(gbm,bdd_rec2[0],bdd_rec2[1]); 
    Cudd_Ref(bdd9);   
    
    for (k = 2;k<128;k++) {
    bdd9 = Cudd_bddOr(gbm,bdd9,bdd_rec2[k]);
    Cudd_Ref(bdd9);   
     }

    bdd1 = Cudd_bddOr(gbm,bdd9,bdd10);
   // bdd = Cudd_bddAnd(gbm,bdd,bdd1);
   */
    DdNode* bdd71;
   
    bdd71 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd71); /*Increases the reference count of a node*/

     for (i = 16; i < 18; i++) {  
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd71); 
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd71);
      bdd71 = tmp;
    }
    
    
    bdd1 = Cudd_bddAnd(gbm,bdd1,bdd71);
    Cudd_Ref(bdd1);

    return bdd1;


}	

//FUNZIONI UNSUBSCRIBE

DdNode* scrivi_bdd_zero9 (DdManager *gbm, DdNode *bdd, DdNode * var) 
{
     DdNode* bdd_rec[128];
     DdNode* bdd_rec2[128];
     DdNode* bdd_rec3[128];
     DdNode* bdd_rec4[128];

     DdNode *bdd1, *bdd2, *bdd3, *bdd4, *bdd5, *bdd6, *bdd7, *bdd8, *bdd9,*tmp,*tmp_neg;
     bdd = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd); /*Increases the reference count of a node*/
     int i; 
     
     for(i = 0; i < 128; i++){
     bdd_rec[i] = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd_rec[i]); /*Increases the reference count of a node*/
     } 
     for(i = 0; i < 128; i++){
     bdd_rec2[i] = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd_rec2[i]); /*Increases the reference count of a node*/
     } 
     for(i = 0; i < 128; i++){
     bdd_rec3[i] = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd_rec3[i]); /*Increases the reference count of a node*/
     } 
     for(i = 0; i < 128; i++){
     bdd_rec4[i] = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd_rec4[i]); /*Increases the reference count of a node*/
     } 
     
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
     bdd6 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd6); /*Increases the reference count of a node*/
     bdd7 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd7); /*Increases the reference count of a node*/
     bdd8 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd8); /*Increases the reference count of a node*/
   
     
     for (i = 0; i < 8; i++) {
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
     if(i != 0 && i != 2 && i != 6) {
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

int j;int k = 0;
     for(j = 0;j<128;j++){ 
       for (i = 8; i < 16; i++) {
          var = Cudd_bddIthVar(gbm,i); 
          if(i%8 ==  0) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	  }
	  else if(i == 9+k && j < 64 ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
          }else if(i == 9+k && j >= 64) {
	  tmp = Cudd_bddAnd(gbm, var, bdd_rec[j]); 
          }
	  else if ( (i == 10 + k) && ( ( j < 32 ) || ( j >= 64 && j < 96 ) ) ) {
          tmp_neg = Cudd_Not(var);
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
          } else if ( i == 10 + k && ( ( j >= 32 && j < 64 ) || ( j >= 96 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
	  } else if (i == 11 + k && ( (j<16) || (j>=32 && j<48) || (j>=64 && j<80) || (j>=96 && j<112) ) ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	  } else if (i == 11 + k && ( (j >= 16 && j < 32) || ( j >= 48 && j < 64 ) || ( j >= 80 && j < 96 ) || ( j >= 112 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
          } else if ( i == 12 + k && ( ( j < 8 ) || ( j >= 16 && j < 24) || (j >= 32 && j < 40) || (j>=48 && j<56) || ( j >= 64 && j < 72 ) || 
		    (j >= 80 && j < 88) || (j >= 96 && j < 104) || (j>=112 && j<120) ) ) {
	   tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
           } else if (i == 12 + k && ( ( j >= 8 && j < 16 ) || ( j >= 24 && j < 32 ) || ( j >= 40 && j < 48) || ( j >= 56 && j < 64) 
			|| (j>72 && j<=80) || (j>=88 && j<96) || (j>=104 && j<112) || (j>=120) ) ) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]);  
 	   } else if (i == 13 + k && ( (j < 4) || (j >= 8 && j < 12) || (j >= 16 && j < 20) || (j >= 24 && j < 28) || (j >= 32 && j < 36) || (j >= 40 && j < 44)
			|| (j >= 48 && j < 52)  || (j >= 56 && j < 60)|| (j >= 64 && j < 68) || (j >= 72 && j < 76) || (j >= 80 && j < 84) || (j >= 88 && j < 92) 	
			|| (j >= 96 && j < 100) || (j >= 104 && j < 108) || (j >= 112 && j < 116) || (j >= 120 && j < 124))) {
	   tmp_neg = Cudd_Not(var);
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   
	   } else if (i == 13 + k && ( (j>=4 && j<8) || ( j >= 12 && j < 16 ) || ( j >= 20 && j < 24 ) || ( j >= 28 && j < 32 ) || ( j >= 36 && j < 40 ) 
			|| ( j >= 44 && j < 48 ) || ( j >= 52 && j < 56 ) || ( j >= 60 && j < 64 ) || ( j >= 68 && j < 72 ) || ( j >= 76 && j < 80 ) 	  
		        || ( j >= 84 && j < 88 ) || ( j >= 92 && j < 96 ) || ( j >= 100 && j < 104 ) || ( j >= 108 && j < 112 ) 
			|| ( j >= 116 && j < 120  ) 	|| ( j >= 124 && j < 128 ))) {
          
		   tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
           } else if ( i == 14 + k && ( (j<2) || (j>=4 && j<6)  || (j>=8 && j<10) || (j>=12 && j<14) || (j>=16 && j<18) || (j>=20 && j<22) || (j>=24 && j<26)
			|| (j>=28 && j<30) || (j>=32 && j<34) || (j>=36 && j<38) || (j>=40 && j<42) || (j>=44 && j<46) || (j>=48 && j<50) || (j>=52 && j<54) 	  
			|| (j>=56 && j<58) || (j>=60 && j<62) || (j>=64 && j<66) || (j>=68 && j<70) || (j>=72 && j<74) || (j>=76 && j<78) || (j>=80 && j<82) 
                	|| (j>=84 && j<86) || (j>=88 && j<90) || (j>=92 && j<94) || (j>=96 && j<98) || (j>=100 && j<102) || (j>=104 && j<106) || (j>=108 && j<110) || 
                	(j>=112 && j<114) || (j>=116 && j<118)     || (j>=120 && j<122) || (j>=124 && j<126)
			)) {
	    tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   } else if (i == 14 + k && ( (j>=2 && j<4) || (j>=6 && j<8) || (j>=10 && j<12) || (j>=14 && j<16) || (j>=18 && j<20) || (j>=22 && j<24) || (j>=26 && j<28)
			|| (j>=30 && j<32) || (j>=34 && j<36) || (j>=38 && j<40) || (j>=42 && j<44) || (j>=46 && j<48) || (j>=50 && j<52) 
			|| (j>=54 && j<56) || (j>=58 && j<60) || (j>=62 && j<64) || (j>=66 && j<68) || (j>=70 && j<72) || (j>=74 && j<76) 
			|| (j>=78 && j<80) || (j>=82 && j<84) || (j>=86 && j<88) || (j>=90 && j<92) || (j>=94 && j<96)
                        || (j>=98 && j<100) || (j>=102 && j<104) || (j>=106 && j<108) || (j>=110 && j<112) || (j>=114 && j<116) 
			|| (j>=118 && j<120) || (j>=122 && j<124) || (j>=126 && j<128) )) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 

	   } else if (i == 15 + k && j % 2 == 0) {
	   
	    tmp_neg = Cudd_Not(var); 
	    tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   
	   } else if (i == 15 + k && j % 2 == 1) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 

	   }
	  
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd_rec[j]);
      bdd_rec[j] = tmp;
    }
  }
    
    bdd1 = Cudd_bddOr(gbm,bdd_rec[0],bdd_rec[1]); 
    Cudd_Ref(bdd1);   
    
    for (k = 2;k<128;k++) {
    bdd1 = Cudd_bddOr(gbm,bdd1,bdd_rec[k]);
    Cudd_Ref(bdd1);   
     }

    bdd = Cudd_bddAnd(gbm,bdd,bdd1);
    Cudd_Ref(bdd);   

   
/*
     for(j = 0;j<128;j++){ 
       for (i = 16; i < 24; i++) {
          var = Cudd_bddIthVar(gbm,i); 
          if(i%8 ==  0) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	  }
	  else if(i == 17+k && j < 64 ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
          }else if(i == 17+k && j >= 64) {
	  tmp = Cudd_bddAnd(gbm, var, bdd_rec[j]); 
          }
	  else if ( (i == 18 + k) && ( ( j < 32 ) || ( j >= 64 && j < 96 ) ) ) {
          tmp_neg = Cudd_Not(var);
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
          } else if ( i == 18 + k && ( ( j >= 32 && j < 64 ) || ( j >= 96 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
	  } else if (i == 19 + k && ( (j<16) || (j>=32 && j<48) || (j>=64 && j<80) || (j>=96 && j<112) ) ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	  } else if (i == 19 + k && ( (j >= 16 && j < 32) || ( j >= 48 && j < 64 ) || ( j >= 80 && j < 96 ) || ( j >= 112 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
          } else if ( i == 20 + k && ( ( j < 8 ) || ( j >= 16 && j < 24) || (j >= 32 && j < 40) || (j>=48 && j<56) || ( j >= 64 && j < 72 ) || 
		    (j >= 80 && j < 88) || (j >= 96 && j < 104) || (j>=112 && j<120) ) ) {
	   tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
           } else if (i == 20 + k && ( ( j >= 8 && j < 16 ) || ( j >= 24 && j < 32 ) || ( j >= 40 && j < 48) || ( j >= 56 && j < 64) 
			|| (j>72 && j<=80) || (j>=88 && j<96) || (j>=104 && j<112) || (j>=120) ) ) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]);  
 	   } else if (i == 21 + k && ( (j < 4) || (j >= 8 && j < 12) || (j >= 16 && j < 20) || (j >= 24 && j < 28) || (j >= 32 && j < 36) || (j >= 40 && j < 44)
			|| (j >= 48 && j < 52)  || (j >= 56 && j < 60)|| (j >= 64 && j < 68) || (j >= 72 && j < 76) || (j >= 80 && j < 84) || (j >= 88 && j < 92) 	
			|| (j >= 96 && j < 100) || (j >= 104 && j < 108) || (j >= 112 && j < 116) || (j >= 120 && j < 124))) {
	   tmp_neg = Cudd_Not(var);
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   
	   } else if (i == 21 + k && ( (j>=4 && j<8) || ( j >= 12 && j < 16 ) || ( j >= 20 && j < 24 ) || ( j >= 28 && j < 32 ) || ( j >= 36 && j < 40 ) 
			|| ( j >= 44 && j < 48 ) || ( j >= 52 && j < 56 ) || ( j >= 60 && j < 64 ) || ( j >= 68 && j < 72 ) || ( j >= 76 && j < 80 ) 	  
		        || ( j >= 84 && j < 88 ) || ( j >= 92 && j < 96 ) || ( j >= 100 && j < 104 ) || ( j >= 108 && j < 112 ) 
			|| ( j >= 116 && j < 120  ) 	|| ( j >= 124 && j < 128 ))) {
          
		   tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
           } else if ( i == 22 + k && ( (j<2) || (j>=4 && j<6)  || (j>=8 && j<10) || (j>=12 && j<14) || (j>=16 && j<18) || (j>=20 && j<22) || (j>=24 && j<26)
			|| (j>=28 && j<30) || (j>=32 && j<34) || (j>=36 && j<38) || (j>=40 && j<42) || (j>=44 && j<46) || (j>=48 && j<50) || (j>=52 && j<54) 	  
			|| (j>=56 && j<58) || (j>=60 && j<62) || (j>=64 && j<66) || (j>=68 && j<70) || (j>=72 && j<74) || (j>=76 && j<78) || (j>=80 && j<82) 
                	|| (j>=84 && j<86) || (j>=88 && j<90) || (j>=92 && j<94) || (j>=96 && j<98) || (j>=100 && j<102) || (j>=104 && j<106) || (j>=108 && j<110) || 
                	(j>=112 && j<114) || (j>=116 && j<118)     || (j>=120 && j<122) || (j>=124 && j<126)
			)) {
	    tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   } else if (i == 22 + k && ( (j>=2 && j<4) || (j>=6 && j<8) || (j>=10 && j<12) || (j>=14 && j<16) || (j>=18 && j<20) || (j>=22 && j<24) || (j>=26 && j<28)
			|| (j>=30 && j<32) || (j>=34 && j<36) || (j>=38 && j<40) || (j>=42 && j<44) || (j>=46 && j<48) || (j>=50 && j<52) 
			|| (j>=54 && j<56) || (j>=58 && j<60) || (j>=62 && j<64) || (j>=66 && j<68) || (j>=70 && j<72) || (j>=74 && j<76) 
			|| (j>=78 && j<80) || (j>=82 && j<84) || (j>=86 && j<88) || (j>=90 && j<92) || (j>=94 && j<96)
                        || (j>=98 && j<100) || (j>=102 && j<104) || (j>=106 && j<108) || (j>=110 && j<112) || (j>=114 && j<116) 
			|| (j>=118 && j<120) || (j>=122 && j<124) || (j>=126 && j<128) )) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 

	   } else if (i == 23 + k && j % 2 == 0) {
	   
	    tmp_neg = Cudd_Not(var); 
	    tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   
	   } else if (i == 23 + k && j % 2 == 1) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 

	   }
	  
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd_rec[j]);
      bdd_rec[j] = tmp;
    }
  }
    
    bdd4 = Cudd_bddOr(gbm,bdd_rec[0],bdd_rec[1]); 
    Cudd_Ref(bdd4);   
    
    for (k = 2;k<128;k++) {
    bdd4 = Cudd_bddOr(gbm,bdd4,bdd_rec[k]);
    Cudd_Ref(bdd4);   
     }

////    bdd = Cudd_bddAnd(gbm,bdd,bdd4);
    
    
     for(j = 0;j<128;j++){ 
       for (i = 16; i < 24; i++) {
          var = Cudd_bddIthVar(gbm,i); 
          if(i%8 ==  0) {
         // tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, var, bdd_rec2[j]); 
	  }
	  else if(i == 17+k && j < 64 ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec2[j]); 
          }else if(i == 17+k && j >= 64) {
	  tmp = Cudd_bddAnd(gbm, var, bdd_rec2[j]); 
          }
	  else if ( (i == 18 + k) && ( ( j < 32 ) || ( j >= 64 && j < 96 ) ) ) {
          tmp_neg = Cudd_Not(var);
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec2[j]); 
          } else if ( i == 18 + k && ( ( j >= 32 && j < 64 ) || ( j >= 96 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec2[j]); 
	  } else if (i == 19 + k && ( (j<16) || (j>=32 && j<48) || (j>=64 && j<80) || (j>=96 && j<112) ) ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec2[j]); 
	  } else if (i == 19 + k && ( (j >= 16 && j < 32) || ( j >= 48 && j < 64 ) || ( j >= 80 && j < 96 ) || ( j >= 112 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec2[j]); 
          } else if ( i == 20 + k && ( ( j < 8 ) || ( j >= 16 && j < 24) || (j >= 32 && j < 40) || (j>=48 && j<56) || ( j >= 64 && j < 72 ) || 
		    (j >= 80 && j < 88) || (j >= 96 && j < 104) || (j>=112 && j<120) ) ) {
	   tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec2[j]); 
           } else if (i == 20 + k && ( ( j >= 8 && j < 16 ) || ( j >= 24 && j < 32 ) || ( j >= 40 && j < 48) || ( j >= 56 && j < 64) 
			|| (j>72 && j<=80) || (j>=88 && j<96) || (j>=104 && j<112) || (j>=120) ) ) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec2[j]);  
 	   } else if (i == 21 + k && ( (j < 4) || (j >= 8 && j < 12) || (j >= 16 && j < 20) || (j >= 24 && j < 28) || (j >= 32 && j < 36) || (j >= 40 && j < 44)
			|| (j >= 48 && j < 52)  || (j >= 56 && j < 60)|| (j >= 64 && j < 68) || (j >= 72 && j < 76) || (j >= 80 && j < 84) || (j >= 88 && j < 92) 	
			|| (j >= 96 && j < 100) || (j >= 104 && j < 108) || (j >= 112 && j < 116) || (j >= 120 && j < 124))) {
	   tmp_neg = Cudd_Not(var);
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec2[j]); 
	   
	   } else if (i == 21 + k && ( (j>=4 && j<8) || ( j >= 12 && j < 16 ) || ( j >= 20 && j < 24 ) || ( j >= 28 && j < 32 ) || ( j >= 36 && j < 40 ) 
			|| ( j >= 44 && j < 48 ) || ( j >= 52 && j < 56 ) || ( j >= 60 && j < 64 ) || ( j >= 68 && j < 72 ) || ( j >= 76 && j < 80 ) 	  
		        || ( j >= 84 && j < 88 ) || ( j >= 92 && j < 96 ) || ( j >= 100 && j < 104 ) || ( j >= 108 && j < 112 ) 
			|| ( j >= 116 && j < 120  ) 	|| ( j >= 124 && j < 128 ))) {
          
		   tmp = Cudd_bddAnd(gbm,var,bdd_rec2[j]); 
           } else if ( i == 22 + k && ( (j<2) || (j>=4 && j<6)  || (j>=8 && j<10) || (j>=12 && j<14) || (j>=16 && j<18) || (j>=20 && j<22) || (j>=24 && j<26)
			|| (j>=28 && j<30) || (j>=32 && j<34) || (j>=36 && j<38) || (j>=40 && j<42) || (j>=44 && j<46) || (j>=48 && j<50) || (j>=52 && j<54) 	  
			|| (j>=56 && j<58) || (j>=60 && j<62) || (j>=64 && j<66) || (j>=68 && j<70) || (j>=72 && j<74) || (j>=76 && j<78) || (j>=80 && j<82) 
                	|| (j>=84 && j<86) || (j>=88 && j<90) || (j>=92 && j<94) || (j>=96 && j<98) || (j>=100 && j<102) || (j>=104 && j<106) || (j>=108 && j<110) || 
                	(j>=112 && j<114) || (j>=116 && j<118)     || (j>=120 && j<122) || (j>=124 && j<126)
			)) {
	    tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec2[j]); 
	   } else if (i == 22 + k && ( (j>=2 && j<4) || (j>=6 && j<8) || (j>=10 && j<12) || (j>=14 && j<16) || (j>=18 && j<20) || (j>=22 && j<24) || (j>=26 && j<28)
			|| (j>=30 && j<32) || (j>=34 && j<36) || (j>=38 && j<40) || (j>=42 && j<44) || (j>=46 && j<48) || (j>=50 && j<52) 
			|| (j>=54 && j<56) || (j>=58 && j<60) || (j>=62 && j<64) || (j>=66 && j<68) || (j>=70 && j<72) || (j>=74 && j<76) 
			|| (j>=78 && j<80) || (j>=82 && j<84) || (j>=86 && j<88) || (j>=90 && j<92) || (j>=94 && j<96)
                        || (j>=98 && j<100) || (j>=102 && j<104) || (j>=106 && j<108) || (j>=110 && j<112) || (j>=114 && j<116) 
			|| (j>=118 && j<120) || (j>=122 && j<124) || (j>=126 && j<128) )) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec2[j]); 

	   } else if (i == 23 + k && j % 2 == 0) {
	   
	    tmp_neg = Cudd_Not(var); 
	    tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec2[j]); 
	   
	   } else if (i == 23 + k && j % 2 == 1) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec2[j]); 

	   }
	  
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd_rec2[j]);
      bdd_rec2[j] = tmp;
    }
  }
    
    
    bdd5 = Cudd_bddOr(gbm,bdd_rec2[0],bdd_rec2[1]); 
    Cudd_Ref(bdd5);   
    
    for (k = 2;k<128;k++) {
    bdd5 = Cudd_bddOr(gbm,bdd5,bdd_rec2[k]);
    Cudd_Ref(bdd5);   
     }
 
    bdd6 = Cudd_bddOr(gbm,bdd4,bdd5);
 
    bdd = Cudd_bddAnd(gbm, bdd,bdd6);
 

	 

     for(j = 0;j<128;j++){ 
       for (i = 24; i < 32; i++) {
          var = Cudd_bddIthVar(gbm,i); 
          if(i%8 ==  0) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec3[j]); 
	  }
	  else if(i == 25+k && j < 64 ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec3[j]); 
          }else if(i == 25+k && j >= 64) {
	  tmp = Cudd_bddAnd(gbm, var, bdd_rec3[j]); 
          }
	  else if ( (i == 26 + k) && ( ( j < 32 ) || ( j >= 64 && j < 96 ) ) ) {
          tmp_neg = Cudd_Not(var);
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec3[j]); 
          } else if ( i == 26 + k && ( ( j >= 32 && j < 64 ) || ( j >= 96 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec3[j]); 
	  } else if (i == 27 + k && ( (j<16) || (j>=32 && j<48) || (j>=64 && j<80) || (j>=96 && j<112) ) ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec3[j]); 
	  } else if (i == 27 + k && ( (j >= 16 && j < 32) || ( j >= 48 && j < 64 ) || ( j >= 80 && j < 96 ) || ( j >= 112 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec3[j]); 
          } else if ( i == 28 + k && ( ( j < 8 ) || ( j >= 16 && j < 24) || (j >= 32 && j < 40) || (j>=48 && j<56) || ( j >= 64 && j < 72 ) || 
		    (j >= 80 && j < 88) || (j >= 96 && j < 104) || (j>=112 && j<120) ) ) {
	   tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec3[j]); 
           } else if (i == 28 + k && ( ( j >= 8 && j < 16 ) || ( j >= 24 && j < 32 ) || ( j >= 40 && j < 48) || ( j >= 56 && j < 64) 
			|| (j>72 && j<=80) || (j>=88 && j<96) || (j>=104 && j<112) || (j>=120) ) ) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec3[j]);  
 	   } else if (i == 29 + k && ( (j < 4) || (j >= 8 && j < 12) || (j >= 16 && j < 20) || (j >= 24 && j < 28) || (j >= 32 && j < 36) || (j >= 40 && j < 44)
			|| (j >= 48 && j < 52)  || (j >= 56 && j < 60)|| (j >= 64 && j < 68) || (j >= 72 && j < 76) || (j >= 80 && j < 84) || (j >= 88 && j < 92) 	
			|| (j >= 96 && j < 100) || (j >= 104 && j < 108) || (j >= 112 && j < 116) || (j >= 120 && j < 124))) {
	   tmp_neg = Cudd_Not(var);
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec3[j]); 
	   
	   } else if (i == 29 + k && ( (j>=4 && j<8) || ( j >= 12 && j < 16 ) || ( j >= 20 && j < 24 ) || ( j >= 28 && j < 32 ) || ( j >= 36 && j < 40 ) 
			|| ( j >= 44 && j < 48 ) || ( j >= 52 && j < 56 ) || ( j >= 60 && j < 64 ) || ( j >= 68 && j < 72 ) || ( j >= 76 && j < 80 ) 	  
		        || ( j >= 84 && j < 88 ) || ( j >= 92 && j < 96 ) || ( j >= 100 && j < 104 ) || ( j >= 108 && j < 112 ) 
			|| ( j >= 116 && j < 120  ) 	|| ( j >= 124 && j < 128 ))) {
          
		   tmp = Cudd_bddAnd(gbm,var,bdd_rec3[j]); 
           } else if ( i == 30 + k && ( (j<2) || (j>=4 && j<6)  || (j>=8 && j<10) || (j>=12 && j<14) || (j>=16 && j<18) || (j>=20 && j<22) || (j>=24 && j<26)
			|| (j>=28 && j<30) || (j>=32 && j<34) || (j>=36 && j<38) || (j>=40 && j<42) || (j>=44 && j<46) || (j>=48 && j<50) || (j>=52 && j<54) 	  
			|| (j>=56 && j<58) || (j>=60 && j<62) || (j>=64 && j<66) || (j>=68 && j<70) || (j>=72 && j<74) || (j>=76 && j<78) || (j>=80 && j<82) 
                	|| (j>=84 && j<86) || (j>=88 && j<90) || (j>=92 && j<94) || (j>=96 && j<98) || (j>=100 && j<102) || (j>=104 && j<106) || (j>=108 && j<110) || 
                	(j>=112 && j<114) || (j>=116 && j<118)     || (j>=120 && j<122) || (j>=124 && j<126)
			)) {
	    tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec3[j]); 
	   } else if (i == 30 + k && ( (j>=2 && j<4) || (j>=6 && j<8) || (j>=10 && j<12) || (j>=14 && j<16) || (j>=18 && j<20) || (j>=22 && j<24) || (j>=26 && j<28)
			|| (j>=30 && j<32) || (j>=34 && j<36) || (j>=38 && j<40) || (j>=42 && j<44) || (j>=46 && j<48) || (j>=50 && j<52) 
			|| (j>=54 && j<56) || (j>=58 && j<60) || (j>=62 && j<64) || (j>=66 && j<68) || (j>=70 && j<72) || (j>=74 && j<76) 
			|| (j>=78 && j<80) || (j>=82 && j<84) || (j>=86 && j<88) || (j>=90 && j<92) || (j>=94 && j<96)
                        || (j>=98 && j<100) || (j>=102 && j<104) || (j>=106 && j<108) || (j>=110 && j<112) || (j>=114 && j<116) 
			|| (j>=118 && j<120) || (j>=122 && j<124) || (j>=126 && j<128) )) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec3[j]); 

	   } else if (i == 31 + k && j % 2 == 0) {
	   
	    tmp_neg = Cudd_Not(var); 
	    tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec3[j]); 
	   
	   } else if (i == 31 + k && j % 2 == 1) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec3[j]); 

	   }
	  
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd_rec3[j]);
      bdd_rec3[j] = tmp;
    }
  }
    
    bdd7 = Cudd_bddOr(gbm,bdd_rec3[0],bdd_rec3[1]); 
    Cudd_Ref(bdd7);   
    
    for (k = 2;k<128;k++) {
    bdd7 = Cudd_bddOr(gbm,bdd7,bdd_rec3[k]);
    Cudd_Ref(bdd7);   
     }

     for(j = 0;j<128;j++){ 
       for (i = 24; i < 32; i++) {
          var = Cudd_bddIthVar(gbm,i); 
          if(i%8 ==  0) {
         // tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, var, bdd_rec4[j]); 
	  }
	  else if(i == 25+k && j < 64 ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec4[j]); 
          }else if(i == 25+k && j >= 64) {
	  tmp = Cudd_bddAnd(gbm, var, bdd_rec4[j]); 
          }
	  else if ( (i == 26 + k) && ( ( j < 32 ) || ( j >= 64 && j < 96 ) ) ) {
          tmp_neg = Cudd_Not(var);
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec4[j]); 
          } else if ( i == 26 + k && ( ( j >= 32 && j < 64 ) || ( j >= 96 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec4[j]); 
	  } else if (i == 27 + k && ( (j<16) || (j>=32 && j<48) || (j>=64 && j<80) || (j>=96 && j<112) ) ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec4[j]); 
	  } else if (i == 27 + k && ( (j >= 16 && j < 32) || ( j >= 48 && j < 64 ) || ( j >= 80 && j < 96 ) || ( j >= 112 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec4[j]); 
          } else if ( i == 28 + k && ( ( j < 8 ) || ( j >= 16 && j < 24) || (j >= 32 && j < 40) || (j>=48 && j<56) || ( j >= 64 && j < 72 ) || 
		    (j >= 80 && j < 88) || (j >= 96 && j < 104) || (j>=112 && j<120) ) ) {
	   tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec4[j]); 
           } else if (i == 28 + k && ( ( j >= 8 && j < 16 ) || ( j >= 24 && j < 32 ) || ( j >= 40 && j < 48) || ( j >= 56 && j < 64) 
			|| (j>72 && j<=80) || (j>=88 && j<96) || (j>=104 && j<112) || (j>=120) ) ) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec4[j]);  
 	   } else if (i == 29 + k && ( (j < 4) || (j >= 8 && j < 12) || (j >= 16 && j < 20) || (j >= 24 && j < 28) || (j >= 32 && j < 36) || (j >= 40 && j < 44)
			|| (j >= 48 && j < 52)  || (j >= 56 && j < 60)|| (j >= 64 && j < 68) || (j >= 72 && j < 76) || (j >= 80 && j < 84) || (j >= 88 && j < 92) 	
			|| (j >= 96 && j < 100) || (j >= 104 && j < 108) || (j >= 112 && j < 116) || (j >= 120 && j < 124))) {
	   tmp_neg = Cudd_Not(var);
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec4[j]); 
	   
	   } else if (i == 29 + k && ( (j>=4 && j<8) || ( j >= 12 && j < 16 ) || ( j >= 20 && j < 24 ) || ( j >= 28 && j < 32 ) || ( j >= 36 && j < 40 ) 
			|| ( j >= 44 && j < 48 ) || ( j >= 52 && j < 56 ) || ( j >= 60 && j < 64 ) || ( j >= 68 && j < 72 ) || ( j >= 76 && j < 80 ) 	  
		        || ( j >= 84 && j < 88 ) || ( j >= 92 && j < 96 ) || ( j >= 100 && j < 104 ) || ( j >= 108 && j < 112 ) 
			|| ( j >= 116 && j < 120  ) 	|| ( j >= 124 && j < 128 ))) {
          
		   tmp = Cudd_bddAnd(gbm,var,bdd_rec4[j]); 
           } else if ( i == 30 + k && ( (j<2) || (j>=4 && j<6)  || (j>=8 && j<10) || (j>=12 && j<14) || (j>=16 && j<18) || (j>=20 && j<22) || (j>=24 && j<26)
			|| (j>=28 && j<30) || (j>=32 && j<34) || (j>=36 && j<38) || (j>=40 && j<42) || (j>=44 && j<46) || (j>=48 && j<50) || (j>=52 && j<54) 	  
			|| (j>=56 && j<58) || (j>=60 && j<62) || (j>=64 && j<66) || (j>=68 && j<70) || (j>=72 && j<74) || (j>=76 && j<78) || (j>=80 && j<82) 
                	|| (j>=84 && j<86) || (j>=88 && j<90) || (j>=92 && j<94) || (j>=96 && j<98) || (j>=100 && j<102) || (j>=104 && j<106) || (j>=108 && j<110) || 
                	(j>=112 && j<114) || (j>=116 && j<118)     || (j>=120 && j<122) || (j>=124 && j<126)
			)) {
	    tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec4[j]); 
	   } else if (i == 30 + k && ( (j>=2 && j<4) || (j>=6 && j<8) || (j>=10 && j<12) || (j>=14 && j<16) || (j>=18 && j<20) || (j>=22 && j<24) || (j>=26 && j<28)
			|| (j>=30 && j<32) || (j>=34 && j<36) || (j>=38 && j<40) || (j>=42 && j<44) || (j>=46 && j<48) || (j>=50 && j<52) 
			|| (j>=54 && j<56) || (j>=58 && j<60) || (j>=62 && j<64) || (j>=66 && j<68) || (j>=70 && j<72) || (j>=74 && j<76) 
			|| (j>=78 && j<80) || (j>=82 && j<84) || (j>=86 && j<88) || (j>=90 && j<92) || (j>=94 && j<96)
                        || (j>=98 && j<100) || (j>=102 && j<104) || (j>=106 && j<108) || (j>=110 && j<112) || (j>=114 && j<116) 
			|| (j>=118 && j<120) || (j>=122 && j<124) || (j>=126 && j<128) )) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec4[j]); 

	   } else if (i == 31 + k && j % 2 == 0) {
	   
	    tmp_neg = Cudd_Not(var); 
	    tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec4[j]); 
	   
	   } else if (i == 31 + k && j % 2 == 1) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec4[j]); 

	   }
	  
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd_rec4[j]);
      bdd_rec4[j] = tmp;
    }
  }
    
    
    bdd8 = Cudd_bddOr(gbm,bdd_rec4[0],bdd_rec4[1]); 
    Cudd_Ref(bdd8);   
    
    for (k = 2;k<128;k++) {
    bdd8 = Cudd_bddOr(gbm,bdd8,bdd_rec4[k]);
    Cudd_Ref(bdd8);   
     }
 
    bdd9 = Cudd_bddOr(gbm,bdd7,bdd8);
    bdd = Cudd_bddAnd(gbm,bdd,bdd9);
*/
    DdNode* bdd71;
   
    bdd71 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd71); /*Increases the reference count of a node*/

     for (i = 16; i < 18; i++) {  
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd71); 
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd71);
      bdd71 = tmp;
    }
    
    
    bdd = Cudd_bddAnd(gbm,bdd,bdd71);
    Cudd_Ref(bdd);


    return bdd;

}




DdNode* scrivi_bdd_uno9 (DdManager *gbm, DdNode *bdd, DdNode * var) 
{
     DdNode* bdd_rec[128];
     DdNode* bdd_rec2[128];
     DdNode* bdd_rec3[128];
     DdNode* bdd_rec4[128];

     DdNode *bdd1, *bdd2, *bdd3, *bdd4, *bdd5, *bdd6, *bdd7, *bdd8, *bdd9,*tmp,*tmp_neg;
     bdd = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd); /*Increases the reference count of a node*/
     int i; 
     
     for(i = 0; i < 128; i++){
     bdd_rec[i] = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd_rec[i]); /*Increases the reference count of a node*/
     } 
     for(i = 0; i < 128; i++){
     bdd_rec2[i] = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd_rec2[i]); /*Increases the reference count of a node*/
     } 
     for(i = 0; i < 128; i++){
     bdd_rec3[i] = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd_rec3[i]); /*Increases the reference count of a node*/
     } 
     for(i = 0; i < 128; i++){
     bdd_rec4[i] = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd_rec4[i]); /*Increases the reference count of a node*/
     } 
     
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
     bdd6 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd6); /*Increases the reference count of a node*/
     bdd7 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd7); /*Increases the reference count of a node*/
     bdd8 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd8); /*Increases the reference count of a node*/
   
     
     for (i = 0; i < 8; i++) {
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
     if(i != 0 && i != 2 && i != 6) {
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

int j;int k = 0;
     for(j = 0;j<128;j++){ 
       for (i = 8; i < 16; i++) {
          var = Cudd_bddIthVar(gbm,i); 
          if(i%8 ==  0) {
     //     tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, var, bdd_rec[j]); 
	  }
	  else if(i == 9+k && j < 64 ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
          }else if(i == 9+k && j >= 64) {
	  tmp = Cudd_bddAnd(gbm, var, bdd_rec[j]); 
          }
	  else if ( (i == 10 + k) && ( ( j < 32 ) || ( j >= 64 && j < 96 ) ) ) {
          tmp_neg = Cudd_Not(var);
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
          } else if ( i == 10 + k && ( ( j >= 32 && j < 64 ) || ( j >= 96 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
	  } else if (i == 11 + k && ( (j<16) || (j>=32 && j<48) || (j>=64 && j<80) || (j>=96 && j<112) ) ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	  } else if (i == 11 + k && ( (j >= 16 && j < 32) || ( j >= 48 && j < 64 ) || ( j >= 80 && j < 96 ) || ( j >= 112 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
          } else if ( i == 12 + k && ( ( j < 8 ) || ( j >= 16 && j < 24) || (j >= 32 && j < 40) || (j>=48 && j<56) || ( j >= 64 && j < 72 ) || 
		    (j >= 80 && j < 88) || (j >= 96 && j < 104) || (j>=112 && j<120) ) ) {
	   tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
           } else if (i == 12 + k && ( ( j >= 8 && j < 16 ) || ( j >= 24 && j < 32 ) || ( j >= 40 && j < 48) || ( j >= 56 && j < 64) 
			|| (j>72 && j<=80) || (j>=88 && j<96) || (j>=104 && j<112) || (j>=120) ) ) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]);  
 	   } else if (i == 13 + k && ( (j < 4) || (j >= 8 && j < 12) || (j >= 16 && j < 20) || (j >= 24 && j < 28) || (j >= 32 && j < 36) || (j >= 40 && j < 44)
			|| (j >= 48 && j < 52)  || (j >= 56 && j < 60)|| (j >= 64 && j < 68) || (j >= 72 && j < 76) || (j >= 80 && j < 84) || (j >= 88 && j < 92) 	
			|| (j >= 96 && j < 100) || (j >= 104 && j < 108) || (j >= 112 && j < 116) || (j >= 120 && j < 124))) {
	   tmp_neg = Cudd_Not(var);
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   
	   } else if (i == 13 + k && ( (j>=4 && j<8) || ( j >= 12 && j < 16 ) || ( j >= 20 && j < 24 ) || ( j >= 28 && j < 32 ) || ( j >= 36 && j < 40 ) 
			|| ( j >= 44 && j < 48 ) || ( j >= 52 && j < 56 ) || ( j >= 60 && j < 64 ) || ( j >= 68 && j < 72 ) || ( j >= 76 && j < 80 ) 	  
		        || ( j >= 84 && j < 88 ) || ( j >= 92 && j < 96 ) || ( j >= 100 && j < 104 ) || ( j >= 108 && j < 112 ) 
			|| ( j >= 116 && j < 120  ) 	|| ( j >= 124 && j < 128 ))) {
          
		   tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
           } else if ( i == 14 + k && ( (j<2) || (j>=4 && j<6)  || (j>=8 && j<10) || (j>=12 && j<14) || (j>=16 && j<18) || (j>=20 && j<22) || (j>=24 && j<26)
			|| (j>=28 && j<30) || (j>=32 && j<34) || (j>=36 && j<38) || (j>=40 && j<42) || (j>=44 && j<46) || (j>=48 && j<50) || (j>=52 && j<54) 	  
			|| (j>=56 && j<58) || (j>=60 && j<62) || (j>=64 && j<66) || (j>=68 && j<70) || (j>=72 && j<74) || (j>=76 && j<78) || (j>=80 && j<82) 
                	|| (j>=84 && j<86) || (j>=88 && j<90) || (j>=92 && j<94) || (j>=96 && j<98) || (j>=100 && j<102) || (j>=104 && j<106) || (j>=108 && j<110) || 
                	(j>=112 && j<114) || (j>=116 && j<118)     || (j>=120 && j<122) || (j>=124 && j<126)
			)) {
	    tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   } else if (i == 14 + k && ( (j>=2 && j<4) || (j>=6 && j<8) || (j>=10 && j<12) || (j>=14 && j<16) || (j>=18 && j<20) || (j>=22 && j<24) || (j>=26 && j<28)
			|| (j>=30 && j<32) || (j>=34 && j<36) || (j>=38 && j<40) || (j>=42 && j<44) || (j>=46 && j<48) || (j>=50 && j<52) 
			|| (j>=54 && j<56) || (j>=58 && j<60) || (j>=62 && j<64) || (j>=66 && j<68) || (j>=70 && j<72) || (j>=74 && j<76) 
			|| (j>=78 && j<80) || (j>=82 && j<84) || (j>=86 && j<88) || (j>=90 && j<92) || (j>=94 && j<96)
                        || (j>=98 && j<100) || (j>=102 && j<104) || (j>=106 && j<108) || (j>=110 && j<112) || (j>=114 && j<116) 
			|| (j>=118 && j<120) || (j>=122 && j<124) || (j>=126 && j<128) )) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 

	   } else if (i == 15 + k && j % 2 == 0) {
	   
	    tmp_neg = Cudd_Not(var); 
	    tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   
	   } else if (i == 15 + k && j % 2 == 1) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 

	   }
	  
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd_rec[j]);
      bdd_rec[j] = tmp;
    }
  }
    
    bdd1 = Cudd_bddOr(gbm,bdd_rec[0],bdd_rec[1]); 
    Cudd_Ref(bdd1);   
    
    for (k = 2;k<128;k++) {
    bdd1 = Cudd_bddOr(gbm,bdd1,bdd_rec[k]);
    Cudd_Ref(bdd1);   
     }

    bdd = Cudd_bddAnd(gbm,bdd,bdd1);
    Cudd_Ref(bdd);   
/*
     for(j = 0;j<128;j++){ 
       for (i = 16; i < 24; i++) {
          var = Cudd_bddIthVar(gbm,i); 
          if(i%8 ==  0) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	  }
	  else if(i == 17+k && j < 64 ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
          }else if(i == 17+k && j >= 64) {
	  tmp = Cudd_bddAnd(gbm, var, bdd_rec[j]); 
          }
	  else if ( (i == 18 + k) && ( ( j < 32 ) || ( j >= 64 && j < 96 ) ) ) {
          tmp_neg = Cudd_Not(var);
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
          } else if ( i == 18 + k && ( ( j >= 32 && j < 64 ) || ( j >= 96 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
	  } else if (i == 19 + k && ( (j<16) || (j>=32 && j<48) || (j>=64 && j<80) || (j>=96 && j<112) ) ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	  } else if (i == 19 + k && ( (j >= 16 && j < 32) || ( j >= 48 && j < 64 ) || ( j >= 80 && j < 96 ) || ( j >= 112 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
          } else if ( i == 20 + k && ( ( j < 8 ) || ( j >= 16 && j < 24) || (j >= 32 && j < 40) || (j>=48 && j<56) || ( j >= 64 && j < 72 ) || 
		    (j >= 80 && j < 88) || (j >= 96 && j < 104) || (j>=112 && j<120) ) ) {
	   tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
           } else if (i == 20 + k && ( ( j >= 8 && j < 16 ) || ( j >= 24 && j < 32 ) || ( j >= 40 && j < 48) || ( j >= 56 && j < 64) 
			|| (j>72 && j<=80) || (j>=88 && j<96) || (j>=104 && j<112) || (j>=120) ) ) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]);  
 	   } else if (i == 21 + k && ( (j < 4) || (j >= 8 && j < 12) || (j >= 16 && j < 20) || (j >= 24 && j < 28) || (j >= 32 && j < 36) || (j >= 40 && j < 44)
			|| (j >= 48 && j < 52)  || (j >= 56 && j < 60)|| (j >= 64 && j < 68) || (j >= 72 && j < 76) || (j >= 80 && j < 84) || (j >= 88 && j < 92) 	
			|| (j >= 96 && j < 100) || (j >= 104 && j < 108) || (j >= 112 && j < 116) || (j >= 120 && j < 124))) {
	   tmp_neg = Cudd_Not(var);
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   
	   } else if (i == 21 + k && ( (j>=4 && j<8) || ( j >= 12 && j < 16 ) || ( j >= 20 && j < 24 ) || ( j >= 28 && j < 32 ) || ( j >= 36 && j < 40 ) 
			|| ( j >= 44 && j < 48 ) || ( j >= 52 && j < 56 ) || ( j >= 60 && j < 64 ) || ( j >= 68 && j < 72 ) || ( j >= 76 && j < 80 ) 	  
		        || ( j >= 84 && j < 88 ) || ( j >= 92 && j < 96 ) || ( j >= 100 && j < 104 ) || ( j >= 108 && j < 112 ) 
			|| ( j >= 116 && j < 120  ) 	|| ( j >= 124 && j < 128 ))) {
          
		   tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
           } else if ( i == 22 + k && ( (j<2) || (j>=4 && j<6)  || (j>=8 && j<10) || (j>=12 && j<14) || (j>=16 && j<18) || (j>=20 && j<22) || (j>=24 && j<26)
			|| (j>=28 && j<30) || (j>=32 && j<34) || (j>=36 && j<38) || (j>=40 && j<42) || (j>=44 && j<46) || (j>=48 && j<50) || (j>=52 && j<54) 	  
			|| (j>=56 && j<58) || (j>=60 && j<62) || (j>=64 && j<66) || (j>=68 && j<70) || (j>=72 && j<74) || (j>=76 && j<78) || (j>=80 && j<82) 
                	|| (j>=84 && j<86) || (j>=88 && j<90) || (j>=92 && j<94) || (j>=96 && j<98) || (j>=100 && j<102) || (j>=104 && j<106) || (j>=108 && j<110) || 
                	(j>=112 && j<114) || (j>=116 && j<118)     || (j>=120 && j<122) || (j>=124 && j<126)
			)) {
	    tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   } else if (i == 22 + k && ( (j>=2 && j<4) || (j>=6 && j<8) || (j>=10 && j<12) || (j>=14 && j<16) || (j>=18 && j<20) || (j>=22 && j<24) || (j>=26 && j<28)
			|| (j>=30 && j<32) || (j>=34 && j<36) || (j>=38 && j<40) || (j>=42 && j<44) || (j>=46 && j<48) || (j>=50 && j<52) 
			|| (j>=54 && j<56) || (j>=58 && j<60) || (j>=62 && j<64) || (j>=66 && j<68) || (j>=70 && j<72) || (j>=74 && j<76) 
			|| (j>=78 && j<80) || (j>=82 && j<84) || (j>=86 && j<88) || (j>=90 && j<92) || (j>=94 && j<96)
                        || (j>=98 && j<100) || (j>=102 && j<104) || (j>=106 && j<108) || (j>=110 && j<112) || (j>=114 && j<116) 
			|| (j>=118 && j<120) || (j>=122 && j<124) || (j>=126 && j<128) )) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 

	   } else if (i == 23 + k && j % 2 == 0) {
	   
	    tmp_neg = Cudd_Not(var); 
	    tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   
	   } else if (i == 23 + k && j % 2 == 1) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 

	   }
	  
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd_rec[j]);
      bdd_rec[j] = tmp;
    }
  }
    
    bdd2 = Cudd_bddOr(gbm,bdd_rec[0],bdd_rec[1]); 
    Cudd_Ref(bdd2);   
    
    for (k = 2;k<128;k++) {
    bdd2 = Cudd_bddOr(gbm,bdd2,bdd_rec[k]);
    Cudd_Ref(bdd2);   
     }

    bdd = Cudd_bddAnd(gbm,bdd,bdd2);
    Cudd_Ref(bdd);   
   

     for(j = 0;j<128;j++){ 
       for (i = 24; i < 32; i++) {
          var = Cudd_bddIthVar(gbm,i); 
          if(i%8 ==  0) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	  }
	  else if(i == 25+k && j < 64 ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
          }else if(i == 25+k && j >= 64) {
	  tmp = Cudd_bddAnd(gbm, var, bdd_rec[j]); 
          }
	  else if ( (i == 26 + k) && ( ( j < 32 ) || ( j >= 64 && j < 96 ) ) ) {
          tmp_neg = Cudd_Not(var);
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
          } else if ( i == 26 + k && ( ( j >= 32 && j < 64 ) || ( j >= 96 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
	  } else if (i == 27 + k && ( (j<16) || (j>=32 && j<48) || (j>=64 && j<80) || (j>=96 && j<112) ) ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	  } else if (i == 27 + k && ( (j >= 16 && j < 32) || ( j >= 48 && j < 64 ) || ( j >= 80 && j < 96 ) || ( j >= 112 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
          } else if ( i == 28 + k && ( ( j < 8 ) || ( j >= 16 && j < 24) || (j >= 32 && j < 40) || (j>=48 && j<56) || ( j >= 64 && j < 72 ) || 
		    (j >= 80 && j < 88) || (j >= 96 && j < 104) || (j>=112 && j<120) ) ) {
	   tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
           } else if (i == 28 + k && ( ( j >= 8 && j < 16 ) || ( j >= 24 && j < 32 ) || ( j >= 40 && j < 48) || ( j >= 56 && j < 64) 
			|| (j>72 && j<=80) || (j>=88 && j<96) || (j>=104 && j<112) || (j>=120) ) ) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]);  
 	   } else if (i == 29 + k && ( (j < 4) || (j >= 8 && j < 12) || (j >= 16 && j < 20) || (j >= 24 && j < 28) || (j >= 32 && j < 36) || (j >= 40 && j < 44)
			|| (j >= 48 && j < 52)  || (j >= 56 && j < 60)|| (j >= 64 && j < 68) || (j >= 72 && j < 76) || (j >= 80 && j < 84) || (j >= 88 && j < 92) 	
			|| (j >= 96 && j < 100) || (j >= 104 && j < 108) || (j >= 112 && j < 116) || (j >= 120 && j < 124))) {
	   tmp_neg = Cudd_Not(var);
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   
	   } else if (i == 29 + k && ( (j>=4 && j<8) || ( j >= 12 && j < 16 ) || ( j >= 20 && j < 24 ) || ( j >= 28 && j < 32 ) || ( j >= 36 && j < 40 ) 
			|| ( j >= 44 && j < 48 ) || ( j >= 52 && j < 56 ) || ( j >= 60 && j < 64 ) || ( j >= 68 && j < 72 ) || ( j >= 76 && j < 80 ) 	  
		        || ( j >= 84 && j < 88 ) || ( j >= 92 && j < 96 ) || ( j >= 100 && j < 104 ) || ( j >= 108 && j < 112 ) 
			|| ( j >= 116 && j < 120  ) 	|| ( j >= 124 && j < 128 ))) {
          
		   tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
           } else if ( i == 30 + k && ( (j<2) || (j>=4 && j<6)  || (j>=8 && j<10) || (j>=12 && j<14) || (j>=16 && j<18) || (j>=20 && j<22) || (j>=24 && j<26)
			|| (j>=28 && j<30) || (j>=32 && j<34) || (j>=36 && j<38) || (j>=40 && j<42) || (j>=44 && j<46) || (j>=48 && j<50) || (j>=52 && j<54) 	  
			|| (j>=56 && j<58) || (j>=60 && j<62) || (j>=64 && j<66) || (j>=68 && j<70) || (j>=72 && j<74) || (j>=76 && j<78) || (j>=80 && j<82) 
                	|| (j>=84 && j<86) || (j>=88 && j<90) || (j>=92 && j<94) || (j>=96 && j<98) || (j>=100 && j<102) || (j>=104 && j<106) || (j>=108 && j<110) || 
                	(j>=112 && j<114) || (j>=116 && j<118)     || (j>=120 && j<122) || (j>=124 && j<126)
			)) {
	    tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   } else if (i == 30 + k && ( (j>=2 && j<4) || (j>=6 && j<8) || (j>=10 && j<12) || (j>=14 && j<16) || (j>=18 && j<20) || (j>=22 && j<24) || (j>=26 && j<28)
			|| (j>=30 && j<32) || (j>=34 && j<36) || (j>=38 && j<40) || (j>=42 && j<44) || (j>=46 && j<48) || (j>=50 && j<52) 
			|| (j>=54 && j<56) || (j>=58 && j<60) || (j>=62 && j<64) || (j>=66 && j<68) || (j>=70 && j<72) || (j>=74 && j<76) 
			|| (j>=78 && j<80) || (j>=82 && j<84) || (j>=86 && j<88) || (j>=90 && j<92) || (j>=94 && j<96)
                        || (j>=98 && j<100) || (j>=102 && j<104) || (j>=106 && j<108) || (j>=110 && j<112) || (j>=114 && j<116) 
			|| (j>=118 && j<120) || (j>=122 && j<124) || (j>=126 && j<128) )) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 

	   } else if (i == 31 + k && j % 2 == 0) {
	   
	    tmp_neg = Cudd_Not(var); 
	    tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   
	   } else if (i == 31 + k && j % 2 == 1) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 

	   }
	  
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd_rec[j]);
      bdd_rec[j] = tmp;
    }
  }
    
    bdd4 = Cudd_bddOr(gbm,bdd_rec[0],bdd_rec[1]); 
    Cudd_Ref(bdd4);   
    
    for (k = 2;k<128;k++) {
    bdd4 = Cudd_bddOr(gbm,bdd4,bdd_rec[k]);
    Cudd_Ref(bdd4);   
     }

////    bdd = Cudd_bddAnd(gbm,bdd,bdd4);
    
    
     for(j = 0;j<128;j++){ 
       for (i = 24; i < 32; i++) {
          var = Cudd_bddIthVar(gbm,i); 
          if(i%8 ==  0) {
         // tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, var, bdd_rec2[j]); 
	  }
	  else if(i == 25+k && j < 64 ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec2[j]); 
          }else if(i == 25+k && j >= 64) {
	  tmp = Cudd_bddAnd(gbm, var, bdd_rec2[j]); 
          }
	  else if ( (i == 26 + k) && ( ( j < 32 ) || ( j >= 64 && j < 96 ) ) ) {
          tmp_neg = Cudd_Not(var);
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec2[j]); 
          } else if ( i == 26 + k && ( ( j >= 32 && j < 64 ) || ( j >= 96 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec2[j]); 
	  } else if (i == 27 + k && ( (j<16) || (j>=32 && j<48) || (j>=64 && j<80) || (j>=96 && j<112) ) ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec2[j]); 
	  } else if (i == 27 + k && ( (j >= 16 && j < 32) || ( j >= 48 && j < 64 ) || ( j >= 80 && j < 96 ) || ( j >= 112 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec2[j]); 
          } else if ( i == 28 + k && ( ( j < 8 ) || ( j >= 16 && j < 24) || (j >= 32 && j < 40) || (j>=48 && j<56) || ( j >= 64 && j < 72 ) || 
		    (j >= 80 && j < 88) || (j >= 96 && j < 104) || (j>=112 && j<120) ) ) {
	   tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec2[j]); 
           } else if (i == 28 + k && ( ( j >= 8 && j < 16 ) || ( j >= 24 && j < 32 ) || ( j >= 40 && j < 48) || ( j >= 56 && j < 64) 
			|| (j>72 && j<=80) || (j>=88 && j<96) || (j>=104 && j<112) || (j>=120) ) ) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec2[j]);  
 	   } else if (i == 29 + k && ( (j < 4) || (j >= 8 && j < 12) || (j >= 16 && j < 20) || (j >= 24 && j < 28) || (j >= 32 && j < 36) || (j >= 40 && j < 44)
			|| (j >= 48 && j < 52)  || (j >= 56 && j < 60)|| (j >= 64 && j < 68) || (j >= 72 && j < 76) || (j >= 80 && j < 84) || (j >= 88 && j < 92) 	
			|| (j >= 96 && j < 100) || (j >= 104 && j < 108) || (j >= 112 && j < 116) || (j >= 120 && j < 124))) {
	   tmp_neg = Cudd_Not(var);
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec2[j]); 
	   
	   } else if (i == 29 + k && ( (j>=4 && j<8) || ( j >= 12 && j < 16 ) || ( j >= 20 && j < 24 ) || ( j >= 28 && j < 32 ) || ( j >= 36 && j < 40 ) 
			|| ( j >= 44 && j < 48 ) || ( j >= 52 && j < 56 ) || ( j >= 60 && j < 64 ) || ( j >= 68 && j < 72 ) || ( j >= 76 && j < 80 ) 	  
		        || ( j >= 84 && j < 88 ) || ( j >= 92 && j < 96 ) || ( j >= 100 && j < 104 ) || ( j >= 108 && j < 112 ) 
			|| ( j >= 116 && j < 120  ) 	|| ( j >= 124 && j < 128 ))) {
          
		   tmp = Cudd_bddAnd(gbm,var,bdd_rec2[j]); 
           } else if ( i == 30 + k && ( (j<2) || (j>=4 && j<6)  || (j>=8 && j<10) || (j>=12 && j<14) || (j>=16 && j<18) || (j>=20 && j<22) || (j>=24 && j<26)
			|| (j>=28 && j<30) || (j>=32 && j<34) || (j>=36 && j<38) || (j>=40 && j<42) || (j>=44 && j<46) || (j>=48 && j<50) || (j>=52 && j<54) 	  
			|| (j>=56 && j<58) || (j>=60 && j<62) || (j>=64 && j<66) || (j>=68 && j<70) || (j>=72 && j<74) || (j>=76 && j<78) || (j>=80 && j<82) 
                	|| (j>=84 && j<86) || (j>=88 && j<90) || (j>=92 && j<94) || (j>=96 && j<98) || (j>=100 && j<102) || (j>=104 && j<106) || (j>=108 && j<110) || 
                	(j>=112 && j<114) || (j>=116 && j<118)     || (j>=120 && j<122) || (j>=124 && j<126)
			)) {
	    tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec2[j]); 
	   } else if (i == 30 + k && ( (j>=2 && j<4) || (j>=6 && j<8) || (j>=10 && j<12) || (j>=14 && j<16) || (j>=18 && j<20) || (j>=22 && j<24) || (j>=26 && j<28)
			|| (j>=30 && j<32) || (j>=34 && j<36) || (j>=38 && j<40) || (j>=42 && j<44) || (j>=46 && j<48) || (j>=50 && j<52) 
			|| (j>=54 && j<56) || (j>=58 && j<60) || (j>=62 && j<64) || (j>=66 && j<68) || (j>=70 && j<72) || (j>=74 && j<76) 
			|| (j>=78 && j<80) || (j>=82 && j<84) || (j>=86 && j<88) || (j>=90 && j<92) || (j>=94 && j<96)
                        || (j>=98 && j<100) || (j>=102 && j<104) || (j>=106 && j<108) || (j>=110 && j<112) || (j>=114 && j<116) 
			|| (j>=118 && j<120) || (j>=122 && j<124) || (j>=126 && j<128) )) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec2[j]); 

	   } else if (i == 31 + k && j % 2 == 0) {
	   
	    tmp_neg = Cudd_Not(var); 
	    tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec2[j]); 
	   
	   } else if (i == 31 + k && j % 2 == 1) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec2[j]); 

	   }
	  
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd_rec2[j]);
      bdd_rec2[j] = tmp;
    }
  }
    
    
    bdd5 = Cudd_bddOr(gbm,bdd_rec2[0],bdd_rec2[1]); 
    Cudd_Ref(bdd5);   
    
    for (k = 2;k<128;k++) {
    bdd5 = Cudd_bddOr(gbm,bdd5,bdd_rec2[k]);
    Cudd_Ref(bdd5);   
     }
 
    bdd6 = Cudd_bddOr(gbm,bdd4,bdd5);
 
    bdd = Cudd_bddAnd(gbm, bdd,bdd6);
 

	 */
/*
     for(j = 0;j<128;j++){ 
       for (i = 32; i < 40; i++) {
          var = Cudd_bddIthVar(gbm,i); 
          if(i%8 ==  0) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec3[j]); 
	  }
	  else if(i == 33+k && j < 64 ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec3[j]); 
          }else if(i == 33+k && j >= 64) {
	  tmp = Cudd_bddAnd(gbm, var, bdd_rec3[j]); 
          }
	  else if ( (i == 34 + k) && ( ( j < 32 ) || ( j >= 64 && j < 96 ) ) ) {
          tmp_neg = Cudd_Not(var);
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec3[j]); 
          } else if ( i == 34 + k && ( ( j >= 32 && j < 64 ) || ( j >= 96 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec3[j]); 
	  } else if (i == 35 + k && ( (j<16) || (j>=32 && j<48) || (j>=64 && j<80) || (j>=96 && j<112) ) ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec3[j]); 
	  } else if (i == 35 + k && ( (j >= 16 && j < 32) || ( j >= 48 && j < 64 ) || ( j >= 80 && j < 96 ) || ( j >= 112 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec3[j]); 
          } else if ( i == 36 + k && ( ( j < 8 ) || ( j >= 16 && j < 24) || (j >= 32 && j < 40) || (j>=48 && j<56) || ( j >= 64 && j < 72 ) || 
		    (j >= 80 && j < 88) || (j >= 96 && j < 104) || (j>=112 && j<120) ) ) {
	   tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec3[j]); 
           } else if (i == 36 + k && ( ( j >= 8 && j < 16 ) || ( j >= 24 && j < 32 ) || ( j >= 40 && j < 48) || ( j >= 56 && j < 64) 
			|| (j>72 && j<=80) || (j>=88 && j<96) || (j>=104 && j<112) || (j>=120) ) ) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec3[j]);  
 	   } else if (i == 37 + k && ( (j < 4) || (j >= 8 && j < 12) || (j >= 16 && j < 20) || (j >= 24 && j < 28) || (j >= 32 && j < 36) || (j >= 40 && j < 44)
			|| (j >= 48 && j < 52)  || (j >= 56 && j < 60)|| (j >= 64 && j < 68) || (j >= 72 && j < 76) || (j >= 80 && j < 84) || (j >= 88 && j < 92) 	
			|| (j >= 96 && j < 100) || (j >= 104 && j < 108) || (j >= 112 && j < 116) || (j >= 120 && j < 124))) {
	   tmp_neg = Cudd_Not(var);
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec3[j]); 
	   
	   } else if (i == 37 + k && ( (j>=4 && j<8) || ( j >= 12 && j < 16 ) || ( j >= 20 && j < 24 ) || ( j >= 28 && j < 32 ) || ( j >= 36 && j < 40 ) 
			|| ( j >= 44 && j < 48 ) || ( j >= 52 && j < 56 ) || ( j >= 60 && j < 64 ) || ( j >= 68 && j < 72 ) || ( j >= 76 && j < 80 ) 	  
		        || ( j >= 84 && j < 88 ) || ( j >= 92 && j < 96 ) || ( j >= 100 && j < 104 ) || ( j >= 108 && j < 112 ) 
			|| ( j >= 116 && j < 120  ) 	|| ( j >= 124 && j < 128 ))) {
          
		   tmp = Cudd_bddAnd(gbm,var,bdd_rec3[j]); 
           } else if ( i == 38 + k && ( (j<2) || (j>=4 && j<6)  || (j>=8 && j<10) || (j>=12 && j<14) || (j>=16 && j<18) || (j>=20 && j<22) || (j>=24 && j<26)
			|| (j>=28 && j<30) || (j>=32 && j<34) || (j>=36 && j<38) || (j>=40 && j<42) || (j>=44 && j<46) || (j>=48 && j<50) || (j>=52 && j<54) 	  
			|| (j>=56 && j<58) || (j>=60 && j<62) || (j>=64 && j<66) || (j>=68 && j<70) || (j>=72 && j<74) || (j>=76 && j<78) || (j>=80 && j<82) 
                	|| (j>=84 && j<86) || (j>=88 && j<90) || (j>=92 && j<94) || (j>=96 && j<98) || (j>=100 && j<102) || (j>=104 && j<106) || (j>=108 && j<110) || 
                	(j>=112 && j<114) || (j>=116 && j<118)     || (j>=120 && j<122) || (j>=124 && j<126)
			)) {
	    tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec3[j]); 
	   } else if (i == 38 + k && ( (j>=2 && j<4) || (j>=6 && j<8) || (j>=10 && j<12) || (j>=14 && j<16) || (j>=18 && j<20) || (j>=22 && j<24) || (j>=26 && j<28)
			|| (j>=30 && j<32) || (j>=34 && j<36) || (j>=38 && j<40) || (j>=42 && j<44) || (j>=46 && j<48) || (j>=50 && j<52) 
			|| (j>=54 && j<56) || (j>=58 && j<60) || (j>=62 && j<64) || (j>=66 && j<68) || (j>=70 && j<72) || (j>=74 && j<76) 
			|| (j>=78 && j<80) || (j>=82 && j<84) || (j>=86 && j<88) || (j>=90 && j<92) || (j>=94 && j<96)
                        || (j>=98 && j<100) || (j>=102 && j<104) || (j>=106 && j<108) || (j>=110 && j<112) || (j>=114 && j<116) 
			|| (j>=118 && j<120) || (j>=122 && j<124) || (j>=126 && j<128) )) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec3[j]); 

	   } else if (i == 39 + k && j % 2 == 0) {
	   
	    tmp_neg = Cudd_Not(var); 
	    tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec3[j]); 
	   
	   } else if (i == 39 + k && j % 2 == 1) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec3[j]); 

	   }
	  
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd_rec3[j]);
      bdd_rec3[j] = tmp;
    }
  }
    
    bdd7 = Cudd_bddOr(gbm,bdd_rec3[0],bdd_rec3[1]); 
    Cudd_Ref(bdd7);   
    
    for (k = 2;k<128;k++) {
    bdd7 = Cudd_bddOr(gbm,bdd7,bdd_rec3[k]);
    Cudd_Ref(bdd7);   
     }

     for(j = 0;j<128;j++){ 
       for (i = 32; i < 40; i++) {
          var = Cudd_bddIthVar(gbm,i); 
          if(i%8 ==  0) {
         // tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, var, bdd_rec4[j]); 
	  }
	  else if(i == 33+k && j < 64 ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec4[j]); 
          }else if(i == 33+k && j >= 64) {
	  tmp = Cudd_bddAnd(gbm, var, bdd_rec4[j]); 
          }
	  else if ( (i == 34 + k) && ( ( j < 32 ) || ( j >= 64 && j < 96 ) ) ) {
          tmp_neg = Cudd_Not(var);
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec4[j]); 
          } else if ( i == 34 + k && ( ( j >= 32 && j < 64 ) || ( j >= 96 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec4[j]); 
	  } else if (i == 35 + k && ( (j<16) || (j>=32 && j<48) || (j>=64 && j<80) || (j>=96 && j<112) ) ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec4[j]); 
	  } else if (i == 35 + k && ( (j >= 16 && j < 32) || ( j >= 48 && j < 64 ) || ( j >= 80 && j < 96 ) || ( j >= 112 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec4[j]); 
          } else if ( i == 36 + k && ( ( j < 8 ) || ( j >= 16 && j < 24) || (j >= 32 && j < 40) || (j>=48 && j<56) || ( j >= 64 && j < 72 ) || 
		    (j >= 80 && j < 88) || (j >= 96 && j < 104) || (j>=112 && j<120) ) ) {
	   tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec4[j]); 
           } else if (i == 36 + k && ( ( j >= 8 && j < 16 ) || ( j >= 24 && j < 32 ) || ( j >= 40 && j < 48) || ( j >= 56 && j < 64) 
			|| (j>72 && j<=80) || (j>=88 && j<96) || (j>=104 && j<112) || (j>=120) ) ) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec4[j]);  
 	   } else if (i == 37 + k && ( (j < 4) || (j >= 8 && j < 12) || (j >= 16 && j < 20) || (j >= 24 && j < 28) || (j >= 32 && j < 36) || (j >= 40 && j < 44)
			|| (j >= 48 && j < 52)  || (j >= 56 && j < 60)|| (j >= 64 && j < 68) || (j >= 72 && j < 76) || (j >= 80 && j < 84) || (j >= 88 && j < 92) 	
			|| (j >= 96 && j < 100) || (j >= 104 && j < 108) || (j >= 112 && j < 116) || (j >= 120 && j < 124))) {
	   tmp_neg = Cudd_Not(var);
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec4[j]); 
	   
	   } else if (i == 37 + k && ( (j>=4 && j<8) || ( j >= 12 && j < 16 ) || ( j >= 20 && j < 24 ) || ( j >= 28 && j < 32 ) || ( j >= 36 && j < 40 ) 
			|| ( j >= 44 && j < 48 ) || ( j >= 52 && j < 56 ) || ( j >= 60 && j < 64 ) || ( j >= 68 && j < 72 ) || ( j >= 76 && j < 80 ) 	  
		        || ( j >= 84 && j < 88 ) || ( j >= 92 && j < 96 ) || ( j >= 100 && j < 104 ) || ( j >= 108 && j < 112 ) 
			|| ( j >= 116 && j < 120  ) 	|| ( j >= 124 && j < 128 ))) {
          
		   tmp = Cudd_bddAnd(gbm,var,bdd_rec4[j]); 
           } else if ( i == 38 + k && ( (j<2) || (j>=4 && j<6)  || (j>=8 && j<10) || (j>=12 && j<14) || (j>=16 && j<18) || (j>=20 && j<22) || (j>=24 && j<26)
			|| (j>=28 && j<30) || (j>=32 && j<34) || (j>=36 && j<38) || (j>=40 && j<42) || (j>=44 && j<46) || (j>=48 && j<50) || (j>=52 && j<54) 	  
			|| (j>=56 && j<58) || (j>=60 && j<62) || (j>=64 && j<66) || (j>=68 && j<70) || (j>=72 && j<74) || (j>=76 && j<78) || (j>=80 && j<82) 
                	|| (j>=84 && j<86) || (j>=88 && j<90) || (j>=92 && j<94) || (j>=96 && j<98) || (j>=100 && j<102) || (j>=104 && j<106) || (j>=108 && j<110) || 
                	(j>=112 && j<114) || (j>=116 && j<118)     || (j>=120 && j<122) || (j>=124 && j<126)
			)) {
	    tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec4[j]); 
	   } else if (i == 38 + k && ( (j>=2 && j<4) || (j>=6 && j<8) || (j>=10 && j<12) || (j>=14 && j<16) || (j>=18 && j<20) || (j>=22 && j<24) || (j>=26 && j<28)
			|| (j>=30 && j<32) || (j>=34 && j<36) || (j>=38 && j<40) || (j>=42 && j<44) || (j>=46 && j<48) || (j>=50 && j<52) 
			|| (j>=54 && j<56) || (j>=58 && j<60) || (j>=62 && j<64) || (j>=66 && j<68) || (j>=70 && j<72) || (j>=74 && j<76) 
			|| (j>=78 && j<80) || (j>=82 && j<84) || (j>=86 && j<88) || (j>=90 && j<92) || (j>=94 && j<96)
                        || (j>=98 && j<100) || (j>=102 && j<104) || (j>=106 && j<108) || (j>=110 && j<112) || (j>=114 && j<116) 
			|| (j>=118 && j<120) || (j>=122 && j<124) || (j>=126 && j<128) )) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec4[j]); 

	   } else if (i == 39 + k && j % 2 == 0) {
	   
	    tmp_neg = Cudd_Not(var); 
	    tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec4[j]); 
	   
	   } else if (i == 39 + k && j % 2 == 1) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec4[j]); 

	   }
	  
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd_rec4[j]);
      bdd_rec4[j] = tmp;
    }
  }
    
    
    bdd8 = Cudd_bddOr(gbm,bdd_rec4[0],bdd_rec4[1]); 
    Cudd_Ref(bdd8);   
    
    for (k = 2;k<128;k++) {
    bdd8 = Cudd_bddOr(gbm,bdd8,bdd_rec4[k]);
    Cudd_Ref(bdd8);   
     }
 
    bdd9 = Cudd_bddOr(gbm,bdd7,bdd8);
    bdd = Cudd_bddAnd(gbm,bdd,bdd9);
*/
    DdNode* bdd71;
   
    bdd71 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd71); /*Increases the reference count of a node*/

     for (i = 16; i < 18; i++) {  
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd71); 
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd71);
      bdd71 = tmp;
    }
    
    
    bdd = Cudd_bddAnd(gbm,bdd,bdd71);
    Cudd_Ref(bdd);


    return bdd;




}	



DdNode* scrivi_bdd_due9 (DdManager *gbm, DdNode *bdd, DdNode * var) {
     DdNode* bdd_rec[128];
     DdNode* bdd_rec2[128];
     DdNode* bdd_rec3[128];
     DdNode* bdd_rec4[128];

     DdNode *bdd1, *bdd2, *bdd3, *bdd4, *bdd5, *bdd6, *bdd7, *bdd8, *bdd9,*tmp,*tmp_neg;
     bdd = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd); /*Increases the reference count of a node*/
     int i; 
     
     for(i = 0; i < 128; i++){
     bdd_rec[i] = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd_rec[i]); /*Increases the reference count of a node*/
     } 
     for(i = 0; i < 128; i++){
     bdd_rec2[i] = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd_rec2[i]); /*Increases the reference count of a node*/
     } 
     for(i = 0; i < 128; i++){
     bdd_rec3[i] = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd_rec3[i]); /*Increases the reference count of a node*/
     } 
     for(i = 0; i < 128; i++){
     bdd_rec4[i] = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd_rec4[i]); /*Increases the reference count of a node*/
     } 
     
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
     bdd6 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd6); /*Increases the reference count of a node*/
     bdd7 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd7); /*Increases the reference count of a node*/
     bdd8 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd8); /*Increases the reference count of a node*/
   
     
     for (i = 0; i < 8; i++) {
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
     if(i != 0 && i != 2 && i != 6) {
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

int j;int k = 0;
     for(j = 0;j<128;j++){ 
       for (i = 8; i < 16; i++) {
          var = Cudd_bddIthVar(gbm,i); 
          if(i%8 ==  0) {
          //tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, var, bdd_rec[j]); 
	  }
	  else if(i == 9+k && j < 64 ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
          }else if(i == 9+k && j >= 64) {
	  tmp = Cudd_bddAnd(gbm, var, bdd_rec[j]); 
          }
	  else if ( (i == 10 + k) && ( ( j < 32 ) || ( j >= 64 && j < 96 ) ) ) {
          tmp_neg = Cudd_Not(var);
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
          } else if ( i == 10 + k && ( ( j >= 32 && j < 64 ) || ( j >= 96 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
	  } else if (i == 11 + k && ( (j<16) || (j>=32 && j<48) || (j>=64 && j<80) || (j>=96 && j<112) ) ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	  } else if (i == 11 + k && ( (j >= 16 && j < 32) || ( j >= 48 && j < 64 ) || ( j >= 80 && j < 96 ) || ( j >= 112 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
          } else if ( i == 12 + k && ( ( j < 8 ) || ( j >= 16 && j < 24) || (j >= 32 && j < 40) || (j>=48 && j<56) || ( j >= 64 && j < 72 ) || 
		    (j >= 80 && j < 88) || (j >= 96 && j < 104) || (j>=112 && j<120) ) ) {
	   tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
           } else if (i == 12 + k && ( ( j >= 8 && j < 16 ) || ( j >= 24 && j < 32 ) || ( j >= 40 && j < 48) || ( j >= 56 && j < 64) 
			|| (j>72 && j<=80) || (j>=88 && j<96) || (j>=104 && j<112) || (j>=120) ) ) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]);  
 	   } else if (i == 13 + k && ( (j < 4) || (j >= 8 && j < 12) || (j >= 16 && j < 20) || (j >= 24 && j < 28) || (j >= 32 && j < 36) || (j >= 40 && j < 44)
			|| (j >= 48 && j < 52)  || (j >= 56 && j < 60)|| (j >= 64 && j < 68) || (j >= 72 && j < 76) || (j >= 80 && j < 84) || (j >= 88 && j < 92) 	
			|| (j >= 96 && j < 100) || (j >= 104 && j < 108) || (j >= 112 && j < 116) || (j >= 120 && j < 124))) {
	   tmp_neg = Cudd_Not(var);
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   
	   } else if (i == 13 + k && ( (j>=4 && j<8) || ( j >= 12 && j < 16 ) || ( j >= 20 && j < 24 ) || ( j >= 28 && j < 32 ) || ( j >= 36 && j < 40 ) 
			|| ( j >= 44 && j < 48 ) || ( j >= 52 && j < 56 ) || ( j >= 60 && j < 64 ) || ( j >= 68 && j < 72 ) || ( j >= 76 && j < 80 ) 	  
		        || ( j >= 84 && j < 88 ) || ( j >= 92 && j < 96 ) || ( j >= 100 && j < 104 ) || ( j >= 108 && j < 112 ) 
			|| ( j >= 116 && j < 120  ) 	|| ( j >= 124 && j < 128 ))) {
          
		   tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
           } else if ( i == 14 + k && ( (j<2) || (j>=4 && j<6)  || (j>=8 && j<10) || (j>=12 && j<14) || (j>=16 && j<18) || (j>=20 && j<22) || (j>=24 && j<26)
			|| (j>=28 && j<30) || (j>=32 && j<34) || (j>=36 && j<38) || (j>=40 && j<42) || (j>=44 && j<46) || (j>=48 && j<50) || (j>=52 && j<54) 	  
			|| (j>=56 && j<58) || (j>=60 && j<62) || (j>=64 && j<66) || (j>=68 && j<70) || (j>=72 && j<74) || (j>=76 && j<78) || (j>=80 && j<82) 
                	|| (j>=84 && j<86) || (j>=88 && j<90) || (j>=92 && j<94) || (j>=96 && j<98) || (j>=100 && j<102) || (j>=104 && j<106) || (j>=108 && j<110) || 
                	(j>=112 && j<114) || (j>=116 && j<118)     || (j>=120 && j<122) || (j>=124 && j<126)
			)) {
	    tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   } else if (i == 14 + k && ( (j>=2 && j<4) || (j>=6 && j<8) || (j>=10 && j<12) || (j>=14 && j<16) || (j>=18 && j<20) || (j>=22 && j<24) || (j>=26 && j<28)
			|| (j>=30 && j<32) || (j>=34 && j<36) || (j>=38 && j<40) || (j>=42 && j<44) || (j>=46 && j<48) || (j>=50 && j<52) 
			|| (j>=54 && j<56) || (j>=58 && j<60) || (j>=62 && j<64) || (j>=66 && j<68) || (j>=70 && j<72) || (j>=74 && j<76) 
			|| (j>=78 && j<80) || (j>=82 && j<84) || (j>=86 && j<88) || (j>=90 && j<92) || (j>=94 && j<96)
                        || (j>=98 && j<100) || (j>=102 && j<104) || (j>=106 && j<108) || (j>=110 && j<112) || (j>=114 && j<116) 
			|| (j>=118 && j<120) || (j>=122 && j<124) || (j>=126 && j<128) )) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 

	   } else if (i == 15 + k && j % 2 == 0) {
	   
	    tmp_neg = Cudd_Not(var); 
	    tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   
	   } else if (i == 15 + k && j % 2 == 1) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 

	   }
	  
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd_rec[j]);
      bdd_rec[j] = tmp;
    }
  }
    
    bdd1 = Cudd_bddOr(gbm,bdd_rec[0],bdd_rec[1]); 
    Cudd_Ref(bdd1);   
    
    for (k = 2;k<128;k++) {
    bdd1 = Cudd_bddOr(gbm,bdd1,bdd_rec[k]);
    Cudd_Ref(bdd1);   
     }

    bdd = Cudd_bddAnd(gbm,bdd,bdd1);
    Cudd_Ref(bdd);   
/*
     for(j = 0;j<128;j++){ 
       for (i = 16; i < 24; i++) {
          var = Cudd_bddIthVar(gbm,i); 
          if(i%8 ==  0) {
          //tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, var, bdd_rec[j]); 
	  }
	  else if(i == 17+k && j < 64 ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
          }else if(i == 17+k && j >= 64) {
	  tmp = Cudd_bddAnd(gbm, var, bdd_rec[j]); 
          }
	  else if ( (i == 18 + k) && ( ( j < 32 ) || ( j >= 64 && j < 96 ) ) ) {
          tmp_neg = Cudd_Not(var);
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
          } else if ( i == 18 + k && ( ( j >= 32 && j < 64 ) || ( j >= 96 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
	  } else if (i == 19 + k && ( (j<16) || (j>=32 && j<48) || (j>=64 && j<80) || (j>=96 && j<112) ) ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	  } else if (i == 19 + k && ( (j >= 16 && j < 32) || ( j >= 48 && j < 64 ) || ( j >= 80 && j < 96 ) || ( j >= 112 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
          } else if ( i == 20 + k && ( ( j < 8 ) || ( j >= 16 && j < 24) || (j >= 32 && j < 40) || (j>=48 && j<56) || ( j >= 64 && j < 72 ) || 
		    (j >= 80 && j < 88) || (j >= 96 && j < 104) || (j>=112 && j<120) ) ) {
	   tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
           } else if (i == 20 + k && ( ( j >= 8 && j < 16 ) || ( j >= 24 && j < 32 ) || ( j >= 40 && j < 48) || ( j >= 56 && j < 64) 
			|| (j>72 && j<=80) || (j>=88 && j<96) || (j>=104 && j<112) || (j>=120) ) ) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]);  
 	   } else if (i == 21 + k && ( (j < 4) || (j >= 8 && j < 12) || (j >= 16 && j < 20) || (j >= 24 && j < 28) || (j >= 32 && j < 36) || (j >= 40 && j < 44)
			|| (j >= 48 && j < 52)  || (j >= 56 && j < 60)|| (j >= 64 && j < 68) || (j >= 72 && j < 76) || (j >= 80 && j < 84) || (j >= 88 && j < 92) 	
			|| (j >= 96 && j < 100) || (j >= 104 && j < 108) || (j >= 112 && j < 116) || (j >= 120 && j < 124))) {
	   tmp_neg = Cudd_Not(var);
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   
	   } else if (i == 21 + k && ( (j>=4 && j<8) || ( j >= 12 && j < 16 ) || ( j >= 20 && j < 24 ) || ( j >= 28 && j < 32 ) || ( j >= 36 && j < 40 ) 
			|| ( j >= 44 && j < 48 ) || ( j >= 52 && j < 56 ) || ( j >= 60 && j < 64 ) || ( j >= 68 && j < 72 ) || ( j >= 76 && j < 80 ) 	  
		        || ( j >= 84 && j < 88 ) || ( j >= 92 && j < 96 ) || ( j >= 100 && j < 104 ) || ( j >= 108 && j < 112 ) 
			|| ( j >= 116 && j < 120  ) 	|| ( j >= 124 && j < 128 ))) {
          
		   tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
           } else if ( i == 22 + k && ( (j<2) || (j>=4 && j<6)  || (j>=8 && j<10) || (j>=12 && j<14) || (j>=16 && j<18) || (j>=20 && j<22) || (j>=24 && j<26)
			|| (j>=28 && j<30) || (j>=32 && j<34) || (j>=36 && j<38) || (j>=40 && j<42) || (j>=44 && j<46) || (j>=48 && j<50) || (j>=52 && j<54) 	  
			|| (j>=56 && j<58) || (j>=60 && j<62) || (j>=64 && j<66) || (j>=68 && j<70) || (j>=72 && j<74) || (j>=76 && j<78) || (j>=80 && j<82) 
                	|| (j>=84 && j<86) || (j>=88 && j<90) || (j>=92 && j<94) || (j>=96 && j<98) || (j>=100 && j<102) || (j>=104 && j<106) || (j>=108 && j<110) || 
                	(j>=112 && j<114) || (j>=116 && j<118)     || (j>=120 && j<122) || (j>=124 && j<126)
			)) {
	    tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   } else if (i == 22 + k && ( (j>=2 && j<4) || (j>=6 && j<8) || (j>=10 && j<12) || (j>=14 && j<16) || (j>=18 && j<20) || (j>=22 && j<24) || (j>=26 && j<28)
			|| (j>=30 && j<32) || (j>=34 && j<36) || (j>=38 && j<40) || (j>=42 && j<44) || (j>=46 && j<48) || (j>=50 && j<52) 
			|| (j>=54 && j<56) || (j>=58 && j<60) || (j>=62 && j<64) || (j>=66 && j<68) || (j>=70 && j<72) || (j>=74 && j<76) 
			|| (j>=78 && j<80) || (j>=82 && j<84) || (j>=86 && j<88) || (j>=90 && j<92) || (j>=94 && j<96)
                        || (j>=98 && j<100) || (j>=102 && j<104) || (j>=106 && j<108) || (j>=110 && j<112) || (j>=114 && j<116) 
			|| (j>=118 && j<120) || (j>=122 && j<124) || (j>=126 && j<128) )) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 

	   } else if (i == 23 + k && j % 2 == 0) {
	   
	    tmp_neg = Cudd_Not(var); 
	    tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   
	   } else if (i == 23 + k && j % 2 == 1) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 

	   }
	  
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd_rec[j]);
      bdd_rec[j] = tmp;
    }
  }
    
    bdd2 = Cudd_bddOr(gbm,bdd_rec[0],bdd_rec[1]); 
    Cudd_Ref(bdd2);   
    
    for (k = 2;k<128;k++) {
    bdd2 = Cudd_bddOr(gbm,bdd2,bdd_rec[k]);
    Cudd_Ref(bdd2);   
     }

    bdd = Cudd_bddAnd(gbm,bdd,bdd2);
    Cudd_Ref(bdd);   
   
     for(j = 0;j<128;j++){ 
       for (i = 24; i < 32; i++) {
          var = Cudd_bddIthVar(gbm,i); 
          if(i%8 ==  0) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	  }
	  else if(i == 25+k && j < 64 ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
          }else if(i == 25+k && j >= 64) {
	  tmp = Cudd_bddAnd(gbm, var, bdd_rec[j]); 
          }
	  else if ( (i == 26 + k) && ( ( j < 32 ) || ( j >= 64 && j < 96 ) ) ) {
          tmp_neg = Cudd_Not(var);
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
          } else if ( i == 26 + k && ( ( j >= 32 && j < 64 ) || ( j >= 96 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
	  } else if (i == 27 + k && ( (j<16) || (j>=32 && j<48) || (j>=64 && j<80) || (j>=96 && j<112) ) ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	  } else if (i == 27 + k && ( (j >= 16 && j < 32) || ( j >= 48 && j < 64 ) || ( j >= 80 && j < 96 ) || ( j >= 112 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
          } else if ( i == 28 + k && ( ( j < 8 ) || ( j >= 16 && j < 24) || (j >= 32 && j < 40) || (j>=48 && j<56) || ( j >= 64 && j < 72 ) || 
		    (j >= 80 && j < 88) || (j >= 96 && j < 104) || (j>=112 && j<120) ) ) {
	   tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
           } else if (i == 28 + k && ( ( j >= 8 && j < 16 ) || ( j >= 24 && j < 32 ) || ( j >= 40 && j < 48) || ( j >= 56 && j < 64) 
			|| (j>72 && j<=80) || (j>=88 && j<96) || (j>=104 && j<112) || (j>=120) ) ) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]);  
 	   } else if (i == 29 + k && ( (j < 4) || (j >= 8 && j < 12) || (j >= 16 && j < 20) || (j >= 24 && j < 28) || (j >= 32 && j < 36) || (j >= 40 && j < 44)
			|| (j >= 48 && j < 52)  || (j >= 56 && j < 60)|| (j >= 64 && j < 68) || (j >= 72 && j < 76) || (j >= 80 && j < 84) || (j >= 88 && j < 92) 	
			|| (j >= 96 && j < 100) || (j >= 104 && j < 108) || (j >= 112 && j < 116) || (j >= 120 && j < 124))) {
	   tmp_neg = Cudd_Not(var);
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   
	   } else if (i == 29 + k && ( (j>=4 && j<8) || ( j >= 12 && j < 16 ) || ( j >= 20 && j < 24 ) || ( j >= 28 && j < 32 ) || ( j >= 36 && j < 40 ) 
			|| ( j >= 44 && j < 48 ) || ( j >= 52 && j < 56 ) || ( j >= 60 && j < 64 ) || ( j >= 68 && j < 72 ) || ( j >= 76 && j < 80 ) 	  
		        || ( j >= 84 && j < 88 ) || ( j >= 92 && j < 96 ) || ( j >= 100 && j < 104 ) || ( j >= 108 && j < 112 ) 
			|| ( j >= 116 && j < 120  ) 	|| ( j >= 124 && j < 128 ))) {
          
		   tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
           } else if ( i == 30 + k && ( (j<2) || (j>=4 && j<6)  || (j>=8 && j<10) || (j>=12 && j<14) || (j>=16 && j<18) || (j>=20 && j<22) || (j>=24 && j<26)
			|| (j>=28 && j<30) || (j>=32 && j<34) || (j>=36 && j<38) || (j>=40 && j<42) || (j>=44 && j<46) || (j>=48 && j<50) || (j>=52 && j<54) 	  
			|| (j>=56 && j<58) || (j>=60 && j<62) || (j>=64 && j<66) || (j>=68 && j<70) || (j>=72 && j<74) || (j>=76 && j<78) || (j>=80 && j<82) 
                	|| (j>=84 && j<86) || (j>=88 && j<90) || (j>=92 && j<94) || (j>=96 && j<98) || (j>=100 && j<102) || (j>=104 && j<106) || (j>=108 && j<110) || 
                	(j>=112 && j<114) || (j>=116 && j<118)     || (j>=120 && j<122) || (j>=124 && j<126)
			)) {
	    tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   } else if (i == 30 + k && ( (j>=2 && j<4) || (j>=6 && j<8) || (j>=10 && j<12) || (j>=14 && j<16) || (j>=18 && j<20) || (j>=22 && j<24) || (j>=26 && j<28)
			|| (j>=30 && j<32) || (j>=34 && j<36) || (j>=38 && j<40) || (j>=42 && j<44) || (j>=46 && j<48) || (j>=50 && j<52) 
			|| (j>=54 && j<56) || (j>=58 && j<60) || (j>=62 && j<64) || (j>=66 && j<68) || (j>=70 && j<72) || (j>=74 && j<76) 
			|| (j>=78 && j<80) || (j>=82 && j<84) || (j>=86 && j<88) || (j>=90 && j<92) || (j>=94 && j<96)
                        || (j>=98 && j<100) || (j>=102 && j<104) || (j>=106 && j<108) || (j>=110 && j<112) || (j>=114 && j<116) 
			|| (j>=118 && j<120) || (j>=122 && j<124) || (j>=126 && j<128) )) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 

	   } else if (i == 31 + k && j % 2 == 0) {
	   
	    tmp_neg = Cudd_Not(var); 
	    tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   
	   } else if (i == 31 + k && j % 2 == 1) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 

	   }
	  
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd_rec[j]);
      bdd_rec[j] = tmp;
    }
  }
    
    bdd3 = Cudd_bddOr(gbm,bdd_rec[0],bdd_rec[1]); 
    Cudd_Ref(bdd3);   
    
    for (k = 2;k<128;k++) {
    bdd3 = Cudd_bddOr(gbm,bdd3,bdd_rec[k]);
    Cudd_Ref(bdd3);   
     }

    bdd = Cudd_bddAnd(gbm,bdd,bdd3);
    Cudd_Ref(bdd);   
   
*/
	 
/*
     for(j = 0;j<128;j++){ 
       for (i = 32; i < 40; i++) {
          var = Cudd_bddIthVar(gbm,i); 
          if(i%8 ==  0) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec3[j]); 
	  }
	  else if(i == 33+k && j < 64 ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec3[j]); 
          }else if(i == 33+k && j >= 64) {
	  tmp = Cudd_bddAnd(gbm, var, bdd_rec3[j]); 
          }
	  else if ( (i == 34 + k) && ( ( j < 32 ) || ( j >= 64 && j < 96 ) ) ) {
          tmp_neg = Cudd_Not(var);
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec3[j]); 
          } else if ( i == 34 + k && ( ( j >= 32 && j < 64 ) || ( j >= 96 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec3[j]); 
	  } else if (i == 35 + k && ( (j<16) || (j>=32 && j<48) || (j>=64 && j<80) || (j>=96 && j<112) ) ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec3[j]); 
	  } else if (i == 35 + k && ( (j >= 16 && j < 32) || ( j >= 48 && j < 64 ) || ( j >= 80 && j < 96 ) || ( j >= 112 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec3[j]); 
          } else if ( i == 36 + k && ( ( j < 8 ) || ( j >= 16 && j < 24) || (j >= 32 && j < 40) || (j>=48 && j<56) || ( j >= 64 && j < 72 ) || 
		    (j >= 80 && j < 88) || (j >= 96 && j < 104) || (j>=112 && j<120) ) ) {
	   tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec3[j]); 
           } else if (i == 36 + k && ( ( j >= 8 && j < 16 ) || ( j >= 24 && j < 32 ) || ( j >= 40 && j < 48) || ( j >= 56 && j < 64) 
			|| (j>72 && j<=80) || (j>=88 && j<96) || (j>=104 && j<112) || (j>=120) ) ) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec3[j]);  
 	   } else if (i == 37 + k && ( (j < 4) || (j >= 8 && j < 12) || (j >= 16 && j < 20) || (j >= 24 && j < 28) || (j >= 32 && j < 36) || (j >= 40 && j < 44)
			|| (j >= 48 && j < 52)  || (j >= 56 && j < 60)|| (j >= 64 && j < 68) || (j >= 72 && j < 76) || (j >= 80 && j < 84) || (j >= 88 && j < 92) 	
			|| (j >= 96 && j < 100) || (j >= 104 && j < 108) || (j >= 112 && j < 116) || (j >= 120 && j < 124))) {
	   tmp_neg = Cudd_Not(var);
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec3[j]); 
	   
	   } else if (i == 37 + k && ( (j>=4 && j<8) || ( j >= 12 && j < 16 ) || ( j >= 20 && j < 24 ) || ( j >= 28 && j < 32 ) || ( j >= 36 && j < 40 ) 
			|| ( j >= 44 && j < 48 ) || ( j >= 52 && j < 56 ) || ( j >= 60 && j < 64 ) || ( j >= 68 && j < 72 ) || ( j >= 76 && j < 80 ) 	  
		        || ( j >= 84 && j < 88 ) || ( j >= 92 && j < 96 ) || ( j >= 100 && j < 104 ) || ( j >= 108 && j < 112 ) 
			|| ( j >= 116 && j < 120  ) 	|| ( j >= 124 && j < 128 ))) {
          
		   tmp = Cudd_bddAnd(gbm,var,bdd_rec3[j]); 
           } else if ( i == 38 + k && ( (j<2) || (j>=4 && j<6)  || (j>=8 && j<10) || (j>=12 && j<14) || (j>=16 && j<18) || (j>=20 && j<22) || (j>=24 && j<26)
			|| (j>=28 && j<30) || (j>=32 && j<34) || (j>=36 && j<38) || (j>=40 && j<42) || (j>=44 && j<46) || (j>=48 && j<50) || (j>=52 && j<54) 	  
			|| (j>=56 && j<58) || (j>=60 && j<62) || (j>=64 && j<66) || (j>=68 && j<70) || (j>=72 && j<74) || (j>=76 && j<78) || (j>=80 && j<82) 
                	|| (j>=84 && j<86) || (j>=88 && j<90) || (j>=92 && j<94) || (j>=96 && j<98) || (j>=100 && j<102) || (j>=104 && j<106) || (j>=108 && j<110) || 
                	(j>=112 && j<114) || (j>=116 && j<118)     || (j>=120 && j<122) || (j>=124 && j<126)
			)) {
	    tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec3[j]); 
	   } else if (i == 38 + k && ( (j>=2 && j<4) || (j>=6 && j<8) || (j>=10 && j<12) || (j>=14 && j<16) || (j>=18 && j<20) || (j>=22 && j<24) || (j>=26 && j<28)
			|| (j>=30 && j<32) || (j>=34 && j<36) || (j>=38 && j<40) || (j>=42 && j<44) || (j>=46 && j<48) || (j>=50 && j<52) 
			|| (j>=54 && j<56) || (j>=58 && j<60) || (j>=62 && j<64) || (j>=66 && j<68) || (j>=70 && j<72) || (j>=74 && j<76) 
			|| (j>=78 && j<80) || (j>=82 && j<84) || (j>=86 && j<88) || (j>=90 && j<92) || (j>=94 && j<96)
                        || (j>=98 && j<100) || (j>=102 && j<104) || (j>=106 && j<108) || (j>=110 && j<112) || (j>=114 && j<116) 
			|| (j>=118 && j<120) || (j>=122 && j<124) || (j>=126 && j<128) )) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec3[j]); 

	   } else if (i == 39 + k && j % 2 == 0) {
	   
	    tmp_neg = Cudd_Not(var); 
	    tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec3[j]); 
	   
	   } else if (i == 39 + k && j % 2 == 1) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec3[j]); 

	   }
	  
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd_rec3[j]);
      bdd_rec3[j] = tmp;
    }
  }
    
    bdd7 = Cudd_bddOr(gbm,bdd_rec3[0],bdd_rec3[1]); 
    Cudd_Ref(bdd7);   
    
    for (k = 2;k<128;k++) {
    bdd7 = Cudd_bddOr(gbm,bdd7,bdd_rec3[k]);
    Cudd_Ref(bdd7);   
     }

     for(j = 0;j<128;j++){ 
       for (i = 32; i < 40; i++) {
          var = Cudd_bddIthVar(gbm,i); 
          if(i%8 ==  0) {
         // tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, var, bdd_rec4[j]); 
	  }
	  else if(i == 33+k && j < 64 ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec4[j]); 
          }else if(i == 33+k && j >= 64) {
	  tmp = Cudd_bddAnd(gbm, var, bdd_rec4[j]); 
          }
	  else if ( (i == 34 + k) && ( ( j < 32 ) || ( j >= 64 && j < 96 ) ) ) {
          tmp_neg = Cudd_Not(var);
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec4[j]); 
          } else if ( i == 34 + k && ( ( j >= 32 && j < 64 ) || ( j >= 96 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec4[j]); 
	  } else if (i == 35 + k && ( (j<16) || (j>=32 && j<48) || (j>=64 && j<80) || (j>=96 && j<112) ) ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec4[j]); 
	  } else if (i == 35 + k && ( (j >= 16 && j < 32) || ( j >= 48 && j < 64 ) || ( j >= 80 && j < 96 ) || ( j >= 112 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec4[j]); 
          } else if ( i == 36 + k && ( ( j < 8 ) || ( j >= 16 && j < 24) || (j >= 32 && j < 40) || (j>=48 && j<56) || ( j >= 64 && j < 72 ) || 
		    (j >= 80 && j < 88) || (j >= 96 && j < 104) || (j>=112 && j<120) ) ) {
	   tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec4[j]); 
           } else if (i == 36 + k && ( ( j >= 8 && j < 16 ) || ( j >= 24 && j < 32 ) || ( j >= 40 && j < 48) || ( j >= 56 && j < 64) 
			|| (j>72 && j<=80) || (j>=88 && j<96) || (j>=104 && j<112) || (j>=120) ) ) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec4[j]);  
 	   } else if (i == 37 + k && ( (j < 4) || (j >= 8 && j < 12) || (j >= 16 && j < 20) || (j >= 24 && j < 28) || (j >= 32 && j < 36) || (j >= 40 && j < 44)
			|| (j >= 48 && j < 52)  || (j >= 56 && j < 60)|| (j >= 64 && j < 68) || (j >= 72 && j < 76) || (j >= 80 && j < 84) || (j >= 88 && j < 92) 	
			|| (j >= 96 && j < 100) || (j >= 104 && j < 108) || (j >= 112 && j < 116) || (j >= 120 && j < 124))) {
	   tmp_neg = Cudd_Not(var);
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec4[j]); 
	   
	   } else if (i == 37 + k && ( (j>=4 && j<8) || ( j >= 12 && j < 16 ) || ( j >= 20 && j < 24 ) || ( j >= 28 && j < 32 ) || ( j >= 36 && j < 40 ) 
			|| ( j >= 44 && j < 48 ) || ( j >= 52 && j < 56 ) || ( j >= 60 && j < 64 ) || ( j >= 68 && j < 72 ) || ( j >= 76 && j < 80 ) 	  
		        || ( j >= 84 && j < 88 ) || ( j >= 92 && j < 96 ) || ( j >= 100 && j < 104 ) || ( j >= 108 && j < 112 ) 
			|| ( j >= 116 && j < 120  ) 	|| ( j >= 124 && j < 128 ))) {
          
		   tmp = Cudd_bddAnd(gbm,var,bdd_rec4[j]); 
           } else if ( i == 38 + k && ( (j<2) || (j>=4 && j<6)  || (j>=8 && j<10) || (j>=12 && j<14) || (j>=16 && j<18) || (j>=20 && j<22) || (j>=24 && j<26)
			|| (j>=28 && j<30) || (j>=32 && j<34) || (j>=36 && j<38) || (j>=40 && j<42) || (j>=44 && j<46) || (j>=48 && j<50) || (j>=52 && j<54) 	  
			|| (j>=56 && j<58) || (j>=60 && j<62) || (j>=64 && j<66) || (j>=68 && j<70) || (j>=72 && j<74) || (j>=76 && j<78) || (j>=80 && j<82) 
                	|| (j>=84 && j<86) || (j>=88 && j<90) || (j>=92 && j<94) || (j>=96 && j<98) || (j>=100 && j<102) || (j>=104 && j<106) || (j>=108 && j<110) || 
                	(j>=112 && j<114) || (j>=116 && j<118)     || (j>=120 && j<122) || (j>=124 && j<126)
			)) {
	    tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec4[j]); 
	   } else if (i == 38 + k && ( (j>=2 && j<4) || (j>=6 && j<8) || (j>=10 && j<12) || (j>=14 && j<16) || (j>=18 && j<20) || (j>=22 && j<24) || (j>=26 && j<28)
			|| (j>=30 && j<32) || (j>=34 && j<36) || (j>=38 && j<40) || (j>=42 && j<44) || (j>=46 && j<48) || (j>=50 && j<52) 
			|| (j>=54 && j<56) || (j>=58 && j<60) || (j>=62 && j<64) || (j>=66 && j<68) || (j>=70 && j<72) || (j>=74 && j<76) 
			|| (j>=78 && j<80) || (j>=82 && j<84) || (j>=86 && j<88) || (j>=90 && j<92) || (j>=94 && j<96)
                        || (j>=98 && j<100) || (j>=102 && j<104) || (j>=106 && j<108) || (j>=110 && j<112) || (j>=114 && j<116) 
			|| (j>=118 && j<120) || (j>=122 && j<124) || (j>=126 && j<128) )) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec4[j]); 

	   } else if (i == 39 + k && j % 2 == 0) {
	   
	    tmp_neg = Cudd_Not(var); 
	    tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec4[j]); 
	   
	   } else if (i == 39 + k && j % 2 == 1) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec4[j]); 

	   }
	  
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd_rec4[j]);
      bdd_rec4[j] = tmp;
    }
  }
    
    
    bdd8 = Cudd_bddOr(gbm,bdd_rec4[0],bdd_rec4[1]); 
    Cudd_Ref(bdd8);   
    
    for (k = 2;k<128;k++) {
    bdd8 = Cudd_bddOr(gbm,bdd8,bdd_rec4[k]);
    Cudd_Ref(bdd8);   
     }
 
    bdd9 = Cudd_bddOr(gbm,bdd7,bdd8);
    bdd = Cudd_bddAnd(gbm,bdd,bdd9);
     
    for(j = 0;j<128;j++){ 
       for (i = 40; i < 48; i++) {
          var = Cudd_bddIthVar(gbm,i); 
          if(i%8 ==  0) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	  }
	  else if(i == 41+k && j < 64 ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
          }else if(i == 41+k && j >= 64) {
	  tmp = Cudd_bddAnd(gbm, var, bdd_rec[j]); 
          }
	  else if ( (i == 42 + k) && ( ( j < 32 ) || ( j >= 64 && j < 96 ) ) ) {
          tmp_neg = Cudd_Not(var);
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
          } else if ( i == 42 + k && ( ( j >= 32 && j < 64 ) || ( j >= 96 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
	  } else if (i == 43 + k && ( (j<16) || (j>=32 && j<48) || (j>=64 && j<80) || (j>=96 && j<112) ) ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	  } else if (i == 43 + k && ( (j >= 16 && j < 32) || ( j >= 48 && j < 64 ) || ( j >= 80 && j < 96 ) || ( j >= 112 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
          } else if ( i == 44 + k && ( ( j < 8 ) || ( j >= 16 && j < 24) || (j >= 32 && j < 40) || (j>=48 && j<56) || ( j >= 64 && j < 72 ) || 
		    (j >= 80 && j < 88) || (j >= 96 && j < 104) || (j>=112 && j<120) ) ) {
	   tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
           } else if (i == 44 + k && ( ( j >= 8 && j < 16 ) || ( j >= 24 && j < 32 ) || ( j >= 40 && j < 48) || ( j >= 56 && j < 64) 
			|| (j>72 && j<=80) || (j>=88 && j<96) || (j>=104 && j<112) || (j>=120) ) ) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]);  
 	   } else if (i == 45 + k && ( (j < 4) || (j >= 8 && j < 12) || (j >= 16 && j < 20) || (j >= 24 && j < 28) || (j >= 32 && j < 36) || (j >= 40 && j < 44)
			|| (j >= 48 && j < 52)  || (j >= 56 && j < 60)|| (j >= 64 && j < 68) || (j >= 72 && j < 76) || (j >= 80 && j < 84) || (j >= 88 && j < 92) 	
			|| (j >= 96 && j < 100) || (j >= 104 && j < 108) || (j >= 112 && j < 116) || (j >= 120 && j < 124))) {
	   tmp_neg = Cudd_Not(var);
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   
	   } else if (i == 45 + k && ( (j>=4 && j<8) || ( j >= 12 && j < 16 ) || ( j >= 20 && j < 24 ) || ( j >= 28 && j < 32 ) || ( j >= 36 && j < 40 ) 
			|| ( j >= 44 && j < 48 ) || ( j >= 52 && j < 56 ) || ( j >= 60 && j < 64 ) || ( j >= 68 && j < 72 ) || ( j >= 76 && j < 80 ) 	  
		        || ( j >= 84 && j < 88 ) || ( j >= 92 && j < 96 ) || ( j >= 100 && j < 104 ) || ( j >= 108 && j < 112 ) 
			|| ( j >= 116 && j < 120  ) 	|| ( j >= 124 && j < 128 ))) {
          
		   tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
           } else if ( i == 46 + k && ( (j<2) || (j>=4 && j<6)  || (j>=8 && j<10) || (j>=12 && j<14) || (j>=16 && j<18) || (j>=20 && j<22) || (j>=24 && j<26)
			|| (j>=28 && j<30) || (j>=32 && j<34) || (j>=36 && j<38) || (j>=40 && j<42) || (j>=44 && j<46) || (j>=48 && j<50) || (j>=52 && j<54) 	  
			|| (j>=56 && j<58) || (j>=60 && j<62) || (j>=64 && j<66) || (j>=68 && j<70) || (j>=72 && j<74) || (j>=76 && j<78) || (j>=80 && j<82) 
                	|| (j>=84 && j<86) || (j>=88 && j<90) || (j>=92 && j<94) || (j>=96 && j<98) || (j>=100 && j<102) || (j>=104 && j<106) || (j>=108 && j<110) || 
                	(j>=112 && j<114) || (j>=116 && j<118)     || (j>=120 && j<122) || (j>=124 && j<126)
			)) {
	    tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   } else if (i == 46 + k && ( (j>=2 && j<4) || (j>=6 && j<8) || (j>=10 && j<12) || (j>=14 && j<16) || (j>=18 && j<20) || (j>=22 && j<24) || (j>=26 && j<28)
			|| (j>=30 && j<32) || (j>=34 && j<36) || (j>=38 && j<40) || (j>=42 && j<44) || (j>=46 && j<48) || (j>=50 && j<52) 
			|| (j>=54 && j<56) || (j>=58 && j<60) || (j>=62 && j<64) || (j>=66 && j<68) || (j>=70 && j<72) || (j>=74 && j<76) 
			|| (j>=78 && j<80) || (j>=82 && j<84) || (j>=86 && j<88) || (j>=90 && j<92) || (j>=94 && j<96)
                        || (j>=98 && j<100) || (j>=102 && j<104) || (j>=106 && j<108) || (j>=110 && j<112) || (j>=114 && j<116) 
			|| (j>=118 && j<120) || (j>=122 && j<124) || (j>=126 && j<128) )) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 

	   } else if (i == 47 + k && j % 2 == 0) {
	   
	    tmp_neg = Cudd_Not(var); 
	    tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   
	   } else if (i == 47 + k && j % 2 == 1) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 

	   }
	  
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd_rec[j]);
      bdd_rec[j] = tmp;
    }
  }
    
    bdd4 = Cudd_bddOr(gbm,bdd_rec[0],bdd_rec[1]); 
    Cudd_Ref(bdd4);   
    
    for (k = 2;k<128;k++) {
    bdd4 = Cudd_bddOr(gbm,bdd4,bdd_rec[k]);
    Cudd_Ref(bdd4);   
     }

////    bdd = Cudd_bddAnd(gbm,bdd,bdd4);
    
    
     for(j = 0;j<128;j++){ 
       for (i = 40; i < 48; i++) {
          var = Cudd_bddIthVar(gbm,i); 
          if(i%8 ==  0) {
         // tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, var, bdd_rec2[j]); 
	  }
	  else if(i == 41+k && j < 64 ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec2[j]); 
          }else if(i == 41+k && j >= 64) {
	  tmp = Cudd_bddAnd(gbm, var, bdd_rec2[j]); 
          }
	  else if ( (i == 42 + k) && ( ( j < 32 ) || ( j >= 64 && j < 96 ) ) ) {
          tmp_neg = Cudd_Not(var);
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec2[j]); 
          } else if ( i == 42 + k && ( ( j >= 32 && j < 64 ) || ( j >= 96 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec2[j]); 
	  } else if (i == 43 + k && ( (j<16) || (j>=32 && j<48) || (j>=64 && j<80) || (j>=96 && j<112) ) ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec2[j]); 
	  } else if (i == 43 + k && ( (j >= 16 && j < 32) || ( j >= 48 && j < 64 ) || ( j >= 80 && j < 96 ) || ( j >= 112 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec2[j]); 
          } else if ( i == 44 + k && ( ( j < 8 ) || ( j >= 16 && j < 24) || (j >= 32 && j < 40) || (j>=48 && j<56) || ( j >= 64 && j < 72 ) || 
		    (j >= 80 && j < 88) || (j >= 96 && j < 104) || (j>=112 && j<120) ) ) {
	   tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec2[j]); 
           } else if (i == 44 + k && ( ( j >= 8 && j < 16 ) || ( j >= 24 && j < 32 ) || ( j >= 40 && j < 48) || ( j >= 56 && j < 64) 
			|| (j>72 && j<=80) || (j>=88 && j<96) || (j>=104 && j<112) || (j>=120) ) ) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec2[j]);  
 	   } else if (i == 45 + k && ( (j < 4) || (j >= 8 && j < 12) || (j >= 16 && j < 20) || (j >= 24 && j < 28) || (j >= 32 && j < 36) || (j >= 40 && j < 44)
			|| (j >= 48 && j < 52)  || (j >= 56 && j < 60)|| (j >= 64 && j < 68) || (j >= 72 && j < 76) || (j >= 80 && j < 84) || (j >= 88 && j < 92) 	
			|| (j >= 96 && j < 100) || (j >= 104 && j < 108) || (j >= 112 && j < 116) || (j >= 120 && j < 124))) {
	   tmp_neg = Cudd_Not(var);
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec2[j]); 
	   
	   } else if (i == 45 + k && ( (j>=4 && j<8) || ( j >= 12 && j < 16 ) || ( j >= 20 && j < 24 ) || ( j >= 28 && j < 32 ) || ( j >= 36 && j < 40 ) 
			|| ( j >= 44 && j < 48 ) || ( j >= 52 && j < 56 ) || ( j >= 60 && j < 64 ) || ( j >= 68 && j < 72 ) || ( j >= 76 && j < 80 ) 	  
		        || ( j >= 84 && j < 88 ) || ( j >= 92 && j < 96 ) || ( j >= 100 && j < 104 ) || ( j >= 108 && j < 112 ) 
			|| ( j >= 116 && j < 120  ) 	|| ( j >= 124 && j < 128 ))) {
          
		   tmp = Cudd_bddAnd(gbm,var,bdd_rec2[j]); 
           } else if ( i == 46 + k && ( (j<2) || (j>=4 && j<6)  || (j>=8 && j<10) || (j>=12 && j<14) || (j>=16 && j<18) || (j>=20 && j<22) || (j>=24 && j<26)
			|| (j>=28 && j<30) || (j>=32 && j<34) || (j>=36 && j<38) || (j>=40 && j<42) || (j>=44 && j<46) || (j>=48 && j<50) || (j>=52 && j<54) 	  
			|| (j>=56 && j<58) || (j>=60 && j<62) || (j>=64 && j<66) || (j>=68 && j<70) || (j>=72 && j<74) || (j>=76 && j<78) || (j>=80 && j<82) 
                	|| (j>=84 && j<86) || (j>=88 && j<90) || (j>=92 && j<94) || (j>=96 && j<98) || (j>=100 && j<102) || (j>=104 && j<106) || (j>=108 && j<110) || 
                	(j>=112 && j<114) || (j>=116 && j<118)     || (j>=120 && j<122) || (j>=124 && j<126)
			)) {
	    tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec2[j]); 
	   } else if (i == 46 + k && ( (j>=2 && j<4) || (j>=6 && j<8) || (j>=10 && j<12) || (j>=14 && j<16) || (j>=18 && j<20) || (j>=22 && j<24) || (j>=26 && j<28)
			|| (j>=30 && j<32) || (j>=34 && j<36) || (j>=38 && j<40) || (j>=42 && j<44) || (j>=46 && j<48) || (j>=50 && j<52) 
			|| (j>=54 && j<56) || (j>=58 && j<60) || (j>=62 && j<64) || (j>=66 && j<68) || (j>=70 && j<72) || (j>=74 && j<76) 
			|| (j>=78 && j<80) || (j>=82 && j<84) || (j>=86 && j<88) || (j>=90 && j<92) || (j>=94 && j<96)
                        || (j>=98 && j<100) || (j>=102 && j<104) || (j>=106 && j<108) || (j>=110 && j<112) || (j>=114 && j<116) 
			|| (j>=118 && j<120) || (j>=122 && j<124) || (j>=126 && j<128) )) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec2[j]); 

	   } else if (i == 47 + k && j % 2 == 0) {
	   
	    tmp_neg = Cudd_Not(var); 
	    tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec2[j]); 
	   
	   } else if (i == 47 + k && j % 2 == 1) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec2[j]); 

	   }
	  
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd_rec2[j]);
      bdd_rec2[j] = tmp;
    }
  }
    
    
    bdd5 = Cudd_bddOr(gbm,bdd_rec2[0],bdd_rec2[1]); 
    Cudd_Ref(bdd5);   
    
    for (k = 2;k<128;k++) {
    bdd5 = Cudd_bddOr(gbm,bdd5,bdd_rec2[k]);
    Cudd_Ref(bdd5);   
     }
 
    bdd6 = Cudd_bddOr(gbm,bdd4,bdd5);
 
    bdd = Cudd_bddAnd(gbm, bdd,bdd6);
 */
    DdNode* bdd71;
   
    bdd71 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd71); /*Increases the reference count of a node*/

     for (i = 16; i < 18; i++) {  
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd71); 
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd71);
      bdd71 = tmp;
    }
    
    
    bdd = Cudd_bddAnd(gbm,bdd,bdd71);
    Cudd_Ref(bdd);


    return bdd;




}	



DdNode* scrivi_bdd_tre9 (DdManager *gbm, DdNode *bdd, DdNode * var) {

     DdNode* bdd_rec[128];
     DdNode* bdd_rec2[128];
     DdNode* bdd_rec3[128];
     DdNode* bdd_rec4[128];
DdNode* bdd_rec5[128];
     DdNode *bdd1, *bdd2, *bdd3, *bdd4, *bdd5, *bdd6, *bdd7, *bdd8, *bdd9,*tmp,*tmp_neg,*bdd10, *bdd11;
     bdd = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd); /*Increases the reference count of a node*/
     int i; 
     
     for(i = 0; i < 128; i++){
     bdd_rec[i] = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd_rec[i]); /*Increases the reference count of a node*/
     } 
     for(i = 0; i < 128; i++){
     bdd_rec2[i] = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd_rec2[i]); /*Increases the reference count of a node*/
     } 
     for(i = 0; i < 128; i++){
     bdd_rec3[i] = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd_rec3[i]); /*Increases the reference count of a node*/
     } 
     for(i = 0; i < 128; i++){
     bdd_rec4[i] = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd_rec4[i]); /*Increases the reference count of a node*/
     } 
     for(i = 0; i < 128; i++){
     bdd_rec5[i] = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd_rec5[i]); /*Increases the reference count of a node*/
     } 
     
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
     bdd6 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd6); /*Increases the reference count of a node*/
     bdd7 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd7); /*Increases the reference count of a node*/
     bdd8 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd8); /*Increases the reference count of a node*/
     bdd9 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd9); /*Increases the reference count of a node*/
     bdd10 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd10); /*Increases the reference count of a node*/
     bdd11 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd11); /*Increases the reference count of a node*/

   
     
     for (i = 0; i < 8; i++) {
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
     if(i != 0 && i != 2 && i != 6) {
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

int j;int k = 0;
     for(j = 0;j<128;j++){ 
       for (i = 8; i < 16; i++) {
          var = Cudd_bddIthVar(gbm,i); 
          if(i%8 ==  0) {
          //tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, var, bdd_rec[j]); 
	  }
	  else if(i == 9+k && j < 64 ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
          }else if(i == 9+k && j >= 64) {
	  tmp = Cudd_bddAnd(gbm, var, bdd_rec[j]); 
          }
	  else if ( (i == 10 + k) && ( ( j < 32 ) || ( j >= 64 && j < 96 ) ) ) {
          tmp_neg = Cudd_Not(var);
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
          } else if ( i == 10 + k && ( ( j >= 32 && j < 64 ) || ( j >= 96 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
	  } else if (i == 11 + k && ( (j<16) || (j>=32 && j<48) || (j>=64 && j<80) || (j>=96 && j<112) ) ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	  } else if (i == 11 + k && ( (j >= 16 && j < 32) || ( j >= 48 && j < 64 ) || ( j >= 80 && j < 96 ) || ( j >= 112 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
          } else if ( i == 12 + k && ( ( j < 8 ) || ( j >= 16 && j < 24) || (j >= 32 && j < 40) || (j>=48 && j<56) || ( j >= 64 && j < 72 ) || 
		    (j >= 80 && j < 88) || (j >= 96 && j < 104) || (j>=112 && j<120) ) ) {
	   tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
           } else if (i == 12 + k && ( ( j >= 8 && j < 16 ) || ( j >= 24 && j < 32 ) || ( j >= 40 && j < 48) || ( j >= 56 && j < 64) 
			|| (j>72 && j<=80) || (j>=88 && j<96) || (j>=104 && j<112) || (j>=120) ) ) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]);  
 	   } else if (i == 13 + k && ( (j < 4) || (j >= 8 && j < 12) || (j >= 16 && j < 20) || (j >= 24 && j < 28) || (j >= 32 && j < 36) || (j >= 40 && j < 44)
			|| (j >= 48 && j < 52)  || (j >= 56 && j < 60)|| (j >= 64 && j < 68) || (j >= 72 && j < 76) || (j >= 80 && j < 84) || (j >= 88 && j < 92) 	
			|| (j >= 96 && j < 100) || (j >= 104 && j < 108) || (j >= 112 && j < 116) || (j >= 120 && j < 124))) {
	   tmp_neg = Cudd_Not(var);
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   
	   } else if (i == 13 + k && ( (j>=4 && j<8) || ( j >= 12 && j < 16 ) || ( j >= 20 && j < 24 ) || ( j >= 28 && j < 32 ) || ( j >= 36 && j < 40 ) 
			|| ( j >= 44 && j < 48 ) || ( j >= 52 && j < 56 ) || ( j >= 60 && j < 64 ) || ( j >= 68 && j < 72 ) || ( j >= 76 && j < 80 ) 	  
		        || ( j >= 84 && j < 88 ) || ( j >= 92 && j < 96 ) || ( j >= 100 && j < 104 ) || ( j >= 108 && j < 112 ) 
			|| ( j >= 116 && j < 120  ) 	|| ( j >= 124 && j < 128 ))) {
          
		   tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
           } else if ( i == 14 + k && ( (j<2) || (j>=4 && j<6)  || (j>=8 && j<10) || (j>=12 && j<14) || (j>=16 && j<18) || (j>=20 && j<22) || (j>=24 && j<26)
			|| (j>=28 && j<30) || (j>=32 && j<34) || (j>=36 && j<38) || (j>=40 && j<42) || (j>=44 && j<46) || (j>=48 && j<50) || (j>=52 && j<54) 	  
			|| (j>=56 && j<58) || (j>=60 && j<62) || (j>=64 && j<66) || (j>=68 && j<70) || (j>=72 && j<74) || (j>=76 && j<78) || (j>=80 && j<82) 
                	|| (j>=84 && j<86) || (j>=88 && j<90) || (j>=92 && j<94) || (j>=96 && j<98) || (j>=100 && j<102) || (j>=104 && j<106) || (j>=108 && j<110) || 
                	(j>=112 && j<114) || (j>=116 && j<118)     || (j>=120 && j<122) || (j>=124 && j<126)
			)) {
	    tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   } else if (i == 14 + k && ( (j>=2 && j<4) || (j>=6 && j<8) || (j>=10 && j<12) || (j>=14 && j<16) || (j>=18 && j<20) || (j>=22 && j<24) || (j>=26 && j<28)
			|| (j>=30 && j<32) || (j>=34 && j<36) || (j>=38 && j<40) || (j>=42 && j<44) || (j>=46 && j<48) || (j>=50 && j<52) 
			|| (j>=54 && j<56) || (j>=58 && j<60) || (j>=62 && j<64) || (j>=66 && j<68) || (j>=70 && j<72) || (j>=74 && j<76) 
			|| (j>=78 && j<80) || (j>=82 && j<84) || (j>=86 && j<88) || (j>=90 && j<92) || (j>=94 && j<96)
                        || (j>=98 && j<100) || (j>=102 && j<104) || (j>=106 && j<108) || (j>=110 && j<112) || (j>=114 && j<116) 
			|| (j>=118 && j<120) || (j>=122 && j<124) || (j>=126 && j<128) )) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 

	   } else if (i == 15 + k && j % 2 == 0) {
	   
	    tmp_neg = Cudd_Not(var); 
	    tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   
	   } else if (i == 15 + k && j % 2 == 1) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 

	   }
	  
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd_rec[j]);
      bdd_rec[j] = tmp;
    }
  }
    
    bdd1 = Cudd_bddOr(gbm,bdd_rec[0],bdd_rec[1]); 
    Cudd_Ref(bdd1);   
    
    for (k = 2;k<128;k++) {
    bdd1 = Cudd_bddOr(gbm,bdd1,bdd_rec[k]);
    Cudd_Ref(bdd1);   
     }

    bdd = Cudd_bddAnd(gbm,bdd,bdd1);
    Cudd_Ref(bdd);   

     for(j = 0;j<128;j++){ 
       for (i = 16; i < 24; i++) {
          var = Cudd_bddIthVar(gbm,i); 
          if(i%8 ==  0) {
          //tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, var, bdd_rec[j]); 
	  }
	  else if(i == 17+k && j < 64 ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
          }else if(i == 17+k && j >= 64) {
	  tmp = Cudd_bddAnd(gbm, var, bdd_rec[j]); 
          }
	  else if ( (i == 18 + k) && ( ( j < 32 ) || ( j >= 64 && j < 96 ) ) ) {
          tmp_neg = Cudd_Not(var);
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
          } else if ( i == 18 + k && ( ( j >= 32 && j < 64 ) || ( j >= 96 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
	  } else if (i == 19 + k && ( (j<16) || (j>=32 && j<48) || (j>=64 && j<80) || (j>=96 && j<112) ) ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	  } else if (i == 19 + k && ( (j >= 16 && j < 32) || ( j >= 48 && j < 64 ) || ( j >= 80 && j < 96 ) || ( j >= 112 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
          } else if ( i == 20 + k && ( ( j < 8 ) || ( j >= 16 && j < 24) || (j >= 32 && j < 40) || (j>=48 && j<56) || ( j >= 64 && j < 72 ) || 
		    (j >= 80 && j < 88) || (j >= 96 && j < 104) || (j>=112 && j<120) ) ) {
	   tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
           } else if (i == 20 + k && ( ( j >= 8 && j < 16 ) || ( j >= 24 && j < 32 ) || ( j >= 40 && j < 48) || ( j >= 56 && j < 64) 
			|| (j>72 && j<=80) || (j>=88 && j<96) || (j>=104 && j<112) || (j>=120) ) ) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]);  
 	   } else if (i == 21 + k && ( (j < 4) || (j >= 8 && j < 12) || (j >= 16 && j < 20) || (j >= 24 && j < 28) || (j >= 32 && j < 36) || (j >= 40 && j < 44)
			|| (j >= 48 && j < 52)  || (j >= 56 && j < 60)|| (j >= 64 && j < 68) || (j >= 72 && j < 76) || (j >= 80 && j < 84) || (j >= 88 && j < 92) 	
			|| (j >= 96 && j < 100) || (j >= 104 && j < 108) || (j >= 112 && j < 116) || (j >= 120 && j < 124))) {
	   tmp_neg = Cudd_Not(var);
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   
	   } else if (i == 21 + k && ( (j>=4 && j<8) || ( j >= 12 && j < 16 ) || ( j >= 20 && j < 24 ) || ( j >= 28 && j < 32 ) || ( j >= 36 && j < 40 ) 
			|| ( j >= 44 && j < 48 ) || ( j >= 52 && j < 56 ) || ( j >= 60 && j < 64 ) || ( j >= 68 && j < 72 ) || ( j >= 76 && j < 80 ) 	  
		        || ( j >= 84 && j < 88 ) || ( j >= 92 && j < 96 ) || ( j >= 100 && j < 104 ) || ( j >= 108 && j < 112 ) 
			|| ( j >= 116 && j < 120  ) 	|| ( j >= 124 && j < 128 ))) {
          
		   tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
           } else if ( i == 22 + k && ( (j<2) || (j>=4 && j<6)  || (j>=8 && j<10) || (j>=12 && j<14) || (j>=16 && j<18) || (j>=20 && j<22) || (j>=24 && j<26)
			|| (j>=28 && j<30) || (j>=32 && j<34) || (j>=36 && j<38) || (j>=40 && j<42) || (j>=44 && j<46) || (j>=48 && j<50) || (j>=52 && j<54) 	  
			|| (j>=56 && j<58) || (j>=60 && j<62) || (j>=64 && j<66) || (j>=68 && j<70) || (j>=72 && j<74) || (j>=76 && j<78) || (j>=80 && j<82) 
                	|| (j>=84 && j<86) || (j>=88 && j<90) || (j>=92 && j<94) || (j>=96 && j<98) || (j>=100 && j<102) || (j>=104 && j<106) || (j>=108 && j<110) || 
                	(j>=112 && j<114) || (j>=116 && j<118)     || (j>=120 && j<122) || (j>=124 && j<126)
			)) {
	    tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   } else if (i == 22 + k && ( (j>=2 && j<4) || (j>=6 && j<8) || (j>=10 && j<12) || (j>=14 && j<16) || (j>=18 && j<20) || (j>=22 && j<24) || (j>=26 && j<28)
			|| (j>=30 && j<32) || (j>=34 && j<36) || (j>=38 && j<40) || (j>=42 && j<44) || (j>=46 && j<48) || (j>=50 && j<52) 
			|| (j>=54 && j<56) || (j>=58 && j<60) || (j>=62 && j<64) || (j>=66 && j<68) || (j>=70 && j<72) || (j>=74 && j<76) 
			|| (j>=78 && j<80) || (j>=82 && j<84) || (j>=86 && j<88) || (j>=90 && j<92) || (j>=94 && j<96)
                        || (j>=98 && j<100) || (j>=102 && j<104) || (j>=106 && j<108) || (j>=110 && j<112) || (j>=114 && j<116) 
			|| (j>=118 && j<120) || (j>=122 && j<124) || (j>=126 && j<128) )) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 

	   } else if (i == 23 + k && j % 2 == 0) {
	   
	    tmp_neg = Cudd_Not(var); 
	    tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   
	   } else if (i == 23 + k && j % 2 == 1) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 

	   }
	  
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd_rec[j]);
      bdd_rec[j] = tmp;
    }
  }
    
    bdd2 = Cudd_bddOr(gbm,bdd_rec[0],bdd_rec[1]); 
    Cudd_Ref(bdd2);   
    
    for (k = 2;k<128;k++) {
    bdd2 = Cudd_bddOr(gbm,bdd2,bdd_rec[k]);
    Cudd_Ref(bdd2);   
     }

    bdd = Cudd_bddAnd(gbm,bdd,bdd2);
    Cudd_Ref(bdd);   
   
     for(j = 0;j<128;j++){ 
       for (i = 24; i < 32; i++) {
          var = Cudd_bddIthVar(gbm,i); 
          if(i%8 ==  0) {
          //tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, var, bdd_rec[j]); 
	  }
	  else if(i == 25+k && j < 64 ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
          }else if(i == 25+k && j >= 64) {
	  tmp = Cudd_bddAnd(gbm, var, bdd_rec[j]); 
          }
	  else if ( (i == 26 + k) && ( ( j < 32 ) || ( j >= 64 && j < 96 ) ) ) {
          tmp_neg = Cudd_Not(var);
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
          } else if ( i == 26 + k && ( ( j >= 32 && j < 64 ) || ( j >= 96 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
	  } else if (i == 27 + k && ( (j<16) || (j>=32 && j<48) || (j>=64 && j<80) || (j>=96 && j<112) ) ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	  } else if (i == 27 + k && ( (j >= 16 && j < 32) || ( j >= 48 && j < 64 ) || ( j >= 80 && j < 96 ) || ( j >= 112 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
          } else if ( i == 28 + k && ( ( j < 8 ) || ( j >= 16 && j < 24) || (j >= 32 && j < 40) || (j>=48 && j<56) || ( j >= 64 && j < 72 ) || 
		    (j >= 80 && j < 88) || (j >= 96 && j < 104) || (j>=112 && j<120) ) ) {
	   tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
           } else if (i == 28 + k && ( ( j >= 8 && j < 16 ) || ( j >= 24 && j < 32 ) || ( j >= 40 && j < 48) || ( j >= 56 && j < 64) 
			|| (j>72 && j<=80) || (j>=88 && j<96) || (j>=104 && j<112) || (j>=120) ) ) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]);  
 	   } else if (i == 29 + k && ( (j < 4) || (j >= 8 && j < 12) || (j >= 16 && j < 20) || (j >= 24 && j < 28) || (j >= 32 && j < 36) || (j >= 40 && j < 44)
			|| (j >= 48 && j < 52)  || (j >= 56 && j < 60)|| (j >= 64 && j < 68) || (j >= 72 && j < 76) || (j >= 80 && j < 84) || (j >= 88 && j < 92) 	
			|| (j >= 96 && j < 100) || (j >= 104 && j < 108) || (j >= 112 && j < 116) || (j >= 120 && j < 124))) {
	   tmp_neg = Cudd_Not(var);
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   
	   } else if (i == 29 + k && ( (j>=4 && j<8) || ( j >= 12 && j < 16 ) || ( j >= 20 && j < 24 ) || ( j >= 28 && j < 32 ) || ( j >= 36 && j < 40 ) 
			|| ( j >= 44 && j < 48 ) || ( j >= 52 && j < 56 ) || ( j >= 60 && j < 64 ) || ( j >= 68 && j < 72 ) || ( j >= 76 && j < 80 ) 	  
		        || ( j >= 84 && j < 88 ) || ( j >= 92 && j < 96 ) || ( j >= 100 && j < 104 ) || ( j >= 108 && j < 112 ) 
			|| ( j >= 116 && j < 120  ) 	|| ( j >= 124 && j < 128 ))) {
          
		   tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
           } else if ( i == 30 + k && ( (j<2) || (j>=4 && j<6)  || (j>=8 && j<10) || (j>=12 && j<14) || (j>=16 && j<18) || (j>=20 && j<22) || (j>=24 && j<26)
			|| (j>=28 && j<30) || (j>=32 && j<34) || (j>=36 && j<38) || (j>=40 && j<42) || (j>=44 && j<46) || (j>=48 && j<50) || (j>=52 && j<54) 	  
			|| (j>=56 && j<58) || (j>=60 && j<62) || (j>=64 && j<66) || (j>=68 && j<70) || (j>=72 && j<74) || (j>=76 && j<78) || (j>=80 && j<82) 
                	|| (j>=84 && j<86) || (j>=88 && j<90) || (j>=92 && j<94) || (j>=96 && j<98) || (j>=100 && j<102) || (j>=104 && j<106) || (j>=108 && j<110) || 
                	(j>=112 && j<114) || (j>=116 && j<118)     || (j>=120 && j<122) || (j>=124 && j<126)
			)) {
	    tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   } else if (i == 30 + k && ( (j>=2 && j<4) || (j>=6 && j<8) || (j>=10 && j<12) || (j>=14 && j<16) || (j>=18 && j<20) || (j>=22 && j<24) || (j>=26 && j<28)
			|| (j>=30 && j<32) || (j>=34 && j<36) || (j>=38 && j<40) || (j>=42 && j<44) || (j>=46 && j<48) || (j>=50 && j<52) 
			|| (j>=54 && j<56) || (j>=58 && j<60) || (j>=62 && j<64) || (j>=66 && j<68) || (j>=70 && j<72) || (j>=74 && j<76) 
			|| (j>=78 && j<80) || (j>=82 && j<84) || (j>=86 && j<88) || (j>=90 && j<92) || (j>=94 && j<96)
                        || (j>=98 && j<100) || (j>=102 && j<104) || (j>=106 && j<108) || (j>=110 && j<112) || (j>=114 && j<116) 
			|| (j>=118 && j<120) || (j>=122 && j<124) || (j>=126 && j<128) )) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 

	   } else if (i == 31 + k && j % 2 == 0) {
	   
	    tmp_neg = Cudd_Not(var); 
	    tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   
	   } else if (i == 31 + k && j % 2 == 1) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 

	   }
	  
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd_rec[j]);
      bdd_rec[j] = tmp;
    }
  }
    
    bdd3 = Cudd_bddOr(gbm,bdd_rec[0],bdd_rec[1]); 
    Cudd_Ref(bdd3);   
    
    for (k = 2;k<128;k++) {
    bdd3 = Cudd_bddOr(gbm,bdd3,bdd_rec[k]);
    Cudd_Ref(bdd3);   
     }

    bdd = Cudd_bddAnd(gbm,bdd,bdd3);
    Cudd_Ref(bdd);   
   

	 
/*
     for(j = 0;j<128;j++){ 
       for (i = 32; i < 40; i++) {
          var = Cudd_bddIthVar(gbm,i); 
          if(i%8 ==  0) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec3[j]); 
	  }
	  else if(i == 33+k && j < 64 ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec3[j]); 
          }else if(i == 33+k && j >= 64) {
	  tmp = Cudd_bddAnd(gbm, var, bdd_rec3[j]); 
          }
	  else if ( (i == 34 + k) && ( ( j < 32 ) || ( j >= 64 && j < 96 ) ) ) {
          tmp_neg = Cudd_Not(var);
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec3[j]); 
          } else if ( i == 34 + k && ( ( j >= 32 && j < 64 ) || ( j >= 96 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec3[j]); 
	  } else if (i == 35 + k && ( (j<16) || (j>=32 && j<48) || (j>=64 && j<80) || (j>=96 && j<112) ) ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec3[j]); 
	  } else if (i == 35 + k && ( (j >= 16 && j < 32) || ( j >= 48 && j < 64 ) || ( j >= 80 && j < 96 ) || ( j >= 112 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec3[j]); 
          } else if ( i == 36 + k && ( ( j < 8 ) || ( j >= 16 && j < 24) || (j >= 32 && j < 40) || (j>=48 && j<56) || ( j >= 64 && j < 72 ) || 
		    (j >= 80 && j < 88) || (j >= 96 && j < 104) || (j>=112 && j<120) ) ) {
	   tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec3[j]); 
           } else if (i == 36 + k && ( ( j >= 8 && j < 16 ) || ( j >= 24 && j < 32 ) || ( j >= 40 && j < 48) || ( j >= 56 && j < 64) 
			|| (j>72 && j<=80) || (j>=88 && j<96) || (j>=104 && j<112) || (j>=120) ) ) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec3[j]);  
 	   } else if (i == 37 + k && ( (j < 4) || (j >= 8 && j < 12) || (j >= 16 && j < 20) || (j >= 24 && j < 28) || (j >= 32 && j < 36) || (j >= 40 && j < 44)
			|| (j >= 48 && j < 52)  || (j >= 56 && j < 60)|| (j >= 64 && j < 68) || (j >= 72 && j < 76) || (j >= 80 && j < 84) || (j >= 88 && j < 92) 	
			|| (j >= 96 && j < 100) || (j >= 104 && j < 108) || (j >= 112 && j < 116) || (j >= 120 && j < 124))) {
	   tmp_neg = Cudd_Not(var);
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec3[j]); 
	   
	   } else if (i == 37 + k && ( (j>=4 && j<8) || ( j >= 12 && j < 16 ) || ( j >= 20 && j < 24 ) || ( j >= 28 && j < 32 ) || ( j >= 36 && j < 40 ) 
			|| ( j >= 44 && j < 48 ) || ( j >= 52 && j < 56 ) || ( j >= 60 && j < 64 ) || ( j >= 68 && j < 72 ) || ( j >= 76 && j < 80 ) 	  
		        || ( j >= 84 && j < 88 ) || ( j >= 92 && j < 96 ) || ( j >= 100 && j < 104 ) || ( j >= 108 && j < 112 ) 
			|| ( j >= 116 && j < 120  ) 	|| ( j >= 124 && j < 128 ))) {
          
		   tmp = Cudd_bddAnd(gbm,var,bdd_rec3[j]); 
           } else if ( i == 38 + k && ( (j<2) || (j>=4 && j<6)  || (j>=8 && j<10) || (j>=12 && j<14) || (j>=16 && j<18) || (j>=20 && j<22) || (j>=24 && j<26)
			|| (j>=28 && j<30) || (j>=32 && j<34) || (j>=36 && j<38) || (j>=40 && j<42) || (j>=44 && j<46) || (j>=48 && j<50) || (j>=52 && j<54) 	  
			|| (j>=56 && j<58) || (j>=60 && j<62) || (j>=64 && j<66) || (j>=68 && j<70) || (j>=72 && j<74) || (j>=76 && j<78) || (j>=80 && j<82) 
                	|| (j>=84 && j<86) || (j>=88 && j<90) || (j>=92 && j<94) || (j>=96 && j<98) || (j>=100 && j<102) || (j>=104 && j<106) || (j>=108 && j<110) || 
                	(j>=112 && j<114) || (j>=116 && j<118)     || (j>=120 && j<122) || (j>=124 && j<126)
			)) {
	    tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec3[j]); 
	   } else if (i == 38 + k && ( (j>=2 && j<4) || (j>=6 && j<8) || (j>=10 && j<12) || (j>=14 && j<16) || (j>=18 && j<20) || (j>=22 && j<24) || (j>=26 && j<28)
			|| (j>=30 && j<32) || (j>=34 && j<36) || (j>=38 && j<40) || (j>=42 && j<44) || (j>=46 && j<48) || (j>=50 && j<52) 
			|| (j>=54 && j<56) || (j>=58 && j<60) || (j>=62 && j<64) || (j>=66 && j<68) || (j>=70 && j<72) || (j>=74 && j<76) 
			|| (j>=78 && j<80) || (j>=82 && j<84) || (j>=86 && j<88) || (j>=90 && j<92) || (j>=94 && j<96)
                        || (j>=98 && j<100) || (j>=102 && j<104) || (j>=106 && j<108) || (j>=110 && j<112) || (j>=114 && j<116) 
			|| (j>=118 && j<120) || (j>=122 && j<124) || (j>=126 && j<128) )) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec3[j]); 

	   } else if (i == 39 + k && j % 2 == 0) {
	   
	    tmp_neg = Cudd_Not(var); 
	    tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec3[j]); 
	   
	   } else if (i == 39 + k && j % 2 == 1) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec3[j]); 

	   }
	  
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd_rec3[j]);
      bdd_rec3[j] = tmp;
    }
  }
    
    bdd7 = Cudd_bddOr(gbm,bdd_rec3[0],bdd_rec3[1]); 
    Cudd_Ref(bdd7);   
    
    for (k = 2;k<128;k++) {
    bdd7 = Cudd_bddOr(gbm,bdd7,bdd_rec3[k]);
    Cudd_Ref(bdd7);   
     }

    bdd = Cudd_bddAnd(gbm,bdd,bdd7);



     
    for(j = 0;j<128;j++){ 
       for (i = 40; i < 48; i++) {
          var = Cudd_bddIthVar(gbm,i); 
          if(i%8 ==  0) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	  }
	  else if(i == 41+k && j < 64 ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
          }else if(i == 41+k && j >= 64) {
	  tmp = Cudd_bddAnd(gbm, var, bdd_rec[j]); 
          }
	  else if ( (i == 42 + k) && ( ( j < 32 ) || ( j >= 64 && j < 96 ) ) ) {
          tmp_neg = Cudd_Not(var);
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
          } else if ( i == 42 + k && ( ( j >= 32 && j < 64 ) || ( j >= 96 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
	  } else if (i == 43 + k && ( (j<16) || (j>=32 && j<48) || (j>=64 && j<80) || (j>=96 && j<112) ) ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	  } else if (i == 43 + k && ( (j >= 16 && j < 32) || ( j >= 48 && j < 64 ) || ( j >= 80 && j < 96 ) || ( j >= 112 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
          } else if ( i == 44 + k && ( ( j < 8 ) || ( j >= 16 && j < 24) || (j >= 32 && j < 40) || (j>=48 && j<56) || ( j >= 64 && j < 72 ) || 
		    (j >= 80 && j < 88) || (j >= 96 && j < 104) || (j>=112 && j<120) ) ) {
	   tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
           } else if (i == 44 + k && ( ( j >= 8 && j < 16 ) || ( j >= 24 && j < 32 ) || ( j >= 40 && j < 48) || ( j >= 56 && j < 64) 
			|| (j>72 && j<=80) || (j>=88 && j<96) || (j>=104 && j<112) || (j>=120) ) ) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]);  
 	   } else if (i == 45 + k && ( (j < 4) || (j >= 8 && j < 12) || (j >= 16 && j < 20) || (j >= 24 && j < 28) || (j >= 32 && j < 36) || (j >= 40 && j < 44)
			|| (j >= 48 && j < 52)  || (j >= 56 && j < 60)|| (j >= 64 && j < 68) || (j >= 72 && j < 76) || (j >= 80 && j < 84) || (j >= 88 && j < 92) 	
			|| (j >= 96 && j < 100) || (j >= 104 && j < 108) || (j >= 112 && j < 116) || (j >= 120 && j < 124))) {
	   tmp_neg = Cudd_Not(var);
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   
	   } else if (i == 45 + k && ( (j>=4 && j<8) || ( j >= 12 && j < 16 ) || ( j >= 20 && j < 24 ) || ( j >= 28 && j < 32 ) || ( j >= 36 && j < 40 ) 
			|| ( j >= 44 && j < 48 ) || ( j >= 52 && j < 56 ) || ( j >= 60 && j < 64 ) || ( j >= 68 && j < 72 ) || ( j >= 76 && j < 80 ) 	  
		        || ( j >= 84 && j < 88 ) || ( j >= 92 && j < 96 ) || ( j >= 100 && j < 104 ) || ( j >= 108 && j < 112 ) 
			|| ( j >= 116 && j < 120  ) 	|| ( j >= 124 && j < 128 ))) {
          
		   tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
           } else if ( i == 46 + k && ( (j<2) || (j>=4 && j<6)  || (j>=8 && j<10) || (j>=12 && j<14) || (j>=16 && j<18) || (j>=20 && j<22) || (j>=24 && j<26)
			|| (j>=28 && j<30) || (j>=32 && j<34) || (j>=36 && j<38) || (j>=40 && j<42) || (j>=44 && j<46) || (j>=48 && j<50) || (j>=52 && j<54) 	  
			|| (j>=56 && j<58) || (j>=60 && j<62) || (j>=64 && j<66) || (j>=68 && j<70) || (j>=72 && j<74) || (j>=76 && j<78) || (j>=80 && j<82) 
                	|| (j>=84 && j<86) || (j>=88 && j<90) || (j>=92 && j<94) || (j>=96 && j<98) || (j>=100 && j<102) || (j>=104 && j<106) || (j>=108 && j<110) || 
                	(j>=112 && j<114) || (j>=116 && j<118)     || (j>=120 && j<122) || (j>=124 && j<126)
			)) {
	    tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   } else if (i == 46 + k && ( (j>=2 && j<4) || (j>=6 && j<8) || (j>=10 && j<12) || (j>=14 && j<16) || (j>=18 && j<20) || (j>=22 && j<24) || (j>=26 && j<28)
			|| (j>=30 && j<32) || (j>=34 && j<36) || (j>=38 && j<40) || (j>=42 && j<44) || (j>=46 && j<48) || (j>=50 && j<52) 
			|| (j>=54 && j<56) || (j>=58 && j<60) || (j>=62 && j<64) || (j>=66 && j<68) || (j>=70 && j<72) || (j>=74 && j<76) 
			|| (j>=78 && j<80) || (j>=82 && j<84) || (j>=86 && j<88) || (j>=90 && j<92) || (j>=94 && j<96)
                        || (j>=98 && j<100) || (j>=102 && j<104) || (j>=106 && j<108) || (j>=110 && j<112) || (j>=114 && j<116) 
			|| (j>=118 && j<120) || (j>=122 && j<124) || (j>=126 && j<128) )) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 

	   } else if (i == 47 + k && j % 2 == 0) {
	   
	    tmp_neg = Cudd_Not(var); 
	    tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   
	   } else if (i == 47 + k && j % 2 == 1) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 

	   }
	  
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd_rec[j]);
      bdd_rec[j] = tmp;
    }
  }
    
    bdd4 = Cudd_bddOr(gbm,bdd_rec[0],bdd_rec[1]); 
    Cudd_Ref(bdd4);   
    
    for (k = 2;k<128;k++) {
    bdd4 = Cudd_bddOr(gbm,bdd4,bdd_rec[k]);
    Cudd_Ref(bdd4);   
     }

////    bdd = Cudd_bddAnd(gbm,bdd,bdd4);
    
    
     for(j = 0;j<128;j++){ 
       for (i = 40; i < 48; i++) {
          var = Cudd_bddIthVar(gbm,i); 
          if(i%8 ==  0) {
         // tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, var, bdd_rec2[j]); 
	  }
	  else if(i == 41+k && j < 64 ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec2[j]); 
          }else if(i == 41+k && j >= 64) {
	  tmp = Cudd_bddAnd(gbm, var, bdd_rec2[j]); 
          }
	  else if ( (i == 42 + k) && ( ( j < 32 ) || ( j >= 64 && j < 96 ) ) ) {
          tmp_neg = Cudd_Not(var);
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec2[j]); 
          } else if ( i == 42 + k && ( ( j >= 32 && j < 64 ) || ( j >= 96 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec2[j]); 
	  } else if (i == 43 + k && ( (j<16) || (j>=32 && j<48) || (j>=64 && j<80) || (j>=96 && j<112) ) ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec2[j]); 
	  } else if (i == 43 + k && ( (j >= 16 && j < 32) || ( j >= 48 && j < 64 ) || ( j >= 80 && j < 96 ) || ( j >= 112 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec2[j]); 
          } else if ( i == 44 + k && ( ( j < 8 ) || ( j >= 16 && j < 24) || (j >= 32 && j < 40) || (j>=48 && j<56) || ( j >= 64 && j < 72 ) || 
		    (j >= 80 && j < 88) || (j >= 96 && j < 104) || (j>=112 && j<120) ) ) {
	   tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec2[j]); 
           } else if (i == 44 + k && ( ( j >= 8 && j < 16 ) || ( j >= 24 && j < 32 ) || ( j >= 40 && j < 48) || ( j >= 56 && j < 64) 
			|| (j>72 && j<=80) || (j>=88 && j<96) || (j>=104 && j<112) || (j>=120) ) ) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec2[j]);  
 	   } else if (i == 45 + k && ( (j < 4) || (j >= 8 && j < 12) || (j >= 16 && j < 20) || (j >= 24 && j < 28) || (j >= 32 && j < 36) || (j >= 40 && j < 44)
			|| (j >= 48 && j < 52)  || (j >= 56 && j < 60)|| (j >= 64 && j < 68) || (j >= 72 && j < 76) || (j >= 80 && j < 84) || (j >= 88 && j < 92) 	
			|| (j >= 96 && j < 100) || (j >= 104 && j < 108) || (j >= 112 && j < 116) || (j >= 120 && j < 124))) {
	   tmp_neg = Cudd_Not(var);
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec2[j]); 
	   
	   } else if (i == 45 + k && ( (j>=4 && j<8) || ( j >= 12 && j < 16 ) || ( j >= 20 && j < 24 ) || ( j >= 28 && j < 32 ) || ( j >= 36 && j < 40 ) 
			|| ( j >= 44 && j < 48 ) || ( j >= 52 && j < 56 ) || ( j >= 60 && j < 64 ) || ( j >= 68 && j < 72 ) || ( j >= 76 && j < 80 ) 	  
		        || ( j >= 84 && j < 88 ) || ( j >= 92 && j < 96 ) || ( j >= 100 && j < 104 ) || ( j >= 108 && j < 112 ) 
			|| ( j >= 116 && j < 120  ) 	|| ( j >= 124 && j < 128 ))) {
          
		   tmp = Cudd_bddAnd(gbm,var,bdd_rec2[j]); 
           } else if ( i == 46 + k && ( (j<2) || (j>=4 && j<6)  || (j>=8 && j<10) || (j>=12 && j<14) || (j>=16 && j<18) || (j>=20 && j<22) || (j>=24 && j<26)
			|| (j>=28 && j<30) || (j>=32 && j<34) || (j>=36 && j<38) || (j>=40 && j<42) || (j>=44 && j<46) || (j>=48 && j<50) || (j>=52 && j<54) 	  
			|| (j>=56 && j<58) || (j>=60 && j<62) || (j>=64 && j<66) || (j>=68 && j<70) || (j>=72 && j<74) || (j>=76 && j<78) || (j>=80 && j<82) 
                	|| (j>=84 && j<86) || (j>=88 && j<90) || (j>=92 && j<94) || (j>=96 && j<98) || (j>=100 && j<102) || (j>=104 && j<106) || (j>=108 && j<110) || 
                	(j>=112 && j<114) || (j>=116 && j<118)     || (j>=120 && j<122) || (j>=124 && j<126)
			)) {
	    tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec2[j]); 
	   } else if (i == 46 + k && ( (j>=2 && j<4) || (j>=6 && j<8) || (j>=10 && j<12) || (j>=14 && j<16) || (j>=18 && j<20) || (j>=22 && j<24) || (j>=26 && j<28)
			|| (j>=30 && j<32) || (j>=34 && j<36) || (j>=38 && j<40) || (j>=42 && j<44) || (j>=46 && j<48) || (j>=50 && j<52) 
			|| (j>=54 && j<56) || (j>=58 && j<60) || (j>=62 && j<64) || (j>=66 && j<68) || (j>=70 && j<72) || (j>=74 && j<76) 
			|| (j>=78 && j<80) || (j>=82 && j<84) || (j>=86 && j<88) || (j>=90 && j<92) || (j>=94 && j<96)
                        || (j>=98 && j<100) || (j>=102 && j<104) || (j>=106 && j<108) || (j>=110 && j<112) || (j>=114 && j<116) 
			|| (j>=118 && j<120) || (j>=122 && j<124) || (j>=126 && j<128) )) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec2[j]); 

	   } else if (i == 47 + k && j % 2 == 0) {
	   
	    tmp_neg = Cudd_Not(var); 
	    tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec2[j]); 
	   
	   } else if (i == 47 + k && j % 2 == 1) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec2[j]); 

	   }
	  
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd_rec2[j]);
      bdd_rec2[j] = tmp;
    }
  }
    
    
    bdd5 = Cudd_bddOr(gbm,bdd_rec2[0],bdd_rec2[1]); 
    Cudd_Ref(bdd5);   
    
    for (k = 2;k<128;k++) {
    bdd5 = Cudd_bddOr(gbm,bdd5,bdd_rec2[k]);
    Cudd_Ref(bdd5);   
     }
 
    bdd6 = Cudd_bddOr(gbm,bdd4,bdd5);
 
    bdd = Cudd_bddAnd(gbm, bdd,bdd6);
 
     for(j = 0;j<128;j++){ 
       for (i = 48; i < 52; i++) {
          var = Cudd_bddIthVar(gbm,i); 
          if(i%8 ==  0) {
         // tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, var, bdd_rec4[j]); 
	  }
	  else if(i == 49+k && j < 64 ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec4[j]); 
          }else if(i == 49+k && j >= 64) {
	  tmp = Cudd_bddAnd(gbm, var, bdd_rec4[j]); 
          }
	  else if ( (i == 50 + k) && ( ( j < 32 ) || ( j >= 64 && j < 96 ) ) ) {
          tmp_neg = Cudd_Not(var);
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec4[j]); 
          } else if ( i == 50 + k && ( ( j >= 32 && j < 64 ) || ( j >= 96 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec4[j]); 
	  } else if (i == 51 + k && ( (j<16) || (j>=32 && j<48) || (j>=64 && j<80) || (j>=96 && j<112) ) ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec4[j]); 
	  } else if (i == 51 + k && ( (j >= 16 && j < 32) || ( j >= 48 && j < 64 ) || ( j >= 80 && j < 96 ) || ( j >= 112 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec4[j]); 
          } else if ( i == 52 + k && ( ( j < 8 ) || ( j >= 16 && j < 24) || (j >= 32 && j < 40) || (j>=48 && j<56) || ( j >= 64 && j < 72 ) || 
		    (j >= 80 && j < 88) || (j >= 96 && j < 104) || (j>=112 && j<120) ) ) {
	   tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec4[j]); 
           } else if (i == 52 + k && ( ( j >= 8 && j < 16 ) || ( j >= 24 && j < 32 ) || ( j >= 40 && j < 48) || ( j >= 56 && j < 64) 
			|| (j>72 && j<=80) || (j>=88 && j<96) || (j>=104 && j<112) || (j>=120) ) ) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec4[j]);  
 	   } else if (i == 53 + k && ( (j < 4) || (j >= 8 && j < 12) || (j >= 16 && j < 20) || (j >= 24 && j < 28) || (j >= 32 && j < 36) || (j >= 40 && j < 44)
			|| (j >= 48 && j < 52)  || (j >= 56 && j < 60)|| (j >= 64 && j < 68) || (j >= 72 && j < 76) || (j >= 80 && j < 84) || (j >= 88 && j < 92) 	
			|| (j >= 96 && j < 100) || (j >= 104 && j < 108) || (j >= 112 && j < 116) || (j >= 120 && j < 124))) {
	   tmp_neg = Cudd_Not(var);
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec4[j]); 
	   
	   } else if (i == 53 + k && ( (j>=4 && j<8) || ( j >= 12 && j < 16 ) || ( j >= 20 && j < 24 ) || ( j >= 28 && j < 32 ) || ( j >= 36 && j < 40 ) 
			|| ( j >= 44 && j < 48 ) || ( j >= 52 && j < 56 ) || ( j >= 60 && j < 64 ) || ( j >= 68 && j < 72 ) || ( j >= 76 && j < 80 ) 	  
		        || ( j >= 84 && j < 88 ) || ( j >= 92 && j < 96 ) || ( j >= 100 && j < 104 ) || ( j >= 108 && j < 112 ) 
			|| ( j >= 116 && j < 120  ) 	|| ( j >= 124 && j < 128 ))) {
          
		   tmp = Cudd_bddAnd(gbm,var,bdd_rec4[j]); 
           } else if ( i == 54 + k && ( (j<2) || (j>=4 && j<6)  || (j>=8 && j<10) || (j>=12 && j<14) || (j>=16 && j<18) || (j>=20 && j<22) || (j>=24 && j<26)
			|| (j>=28 && j<30) || (j>=32 && j<34) || (j>=36 && j<38) || (j>=40 && j<42) || (j>=44 && j<46) || (j>=48 && j<50) || (j>=52 && j<54) 	  
			|| (j>=56 && j<58) || (j>=60 && j<62) || (j>=64 && j<66) || (j>=68 && j<70) || (j>=72 && j<74) || (j>=76 && j<78) || (j>=80 && j<82) 
                	|| (j>=84 && j<86) || (j>=88 && j<90) || (j>=92 && j<94) || (j>=96 && j<98) || (j>=100 && j<102) || (j>=104 && j<106) || (j>=108 && j<110) || 
                	(j>=112 && j<114) || (j>=116 && j<118)     || (j>=120 && j<122) || (j>=124 && j<126)
			)) {
	    tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec4[j]); 
	   } else if (i == 54 + k && ( (j>=2 && j<4) || (j>=6 && j<8) || (j>=10 && j<12) || (j>=14 && j<16) || (j>=18 && j<20) || (j>=22 && j<24) || (j>=26 && j<28)
			|| (j>=30 && j<32) || (j>=34 && j<36) || (j>=38 && j<40) || (j>=42 && j<44) || (j>=46 && j<48) || (j>=50 && j<52) 
			|| (j>=54 && j<56) || (j>=58 && j<60) || (j>=62 && j<64) || (j>=66 && j<68) || (j>=70 && j<72) || (j>=74 && j<76) 
			|| (j>=78 && j<80) || (j>=82 && j<84) || (j>=86 && j<88) || (j>=90 && j<92) || (j>=94 && j<96)
                        || (j>=98 && j<100) || (j>=102 && j<104) || (j>=106 && j<108) || (j>=110 && j<112) || (j>=114 && j<116) 
			|| (j>=118 && j<120) || (j>=122 && j<124) || (j>=126 && j<128) )) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec4[j]); 

	   } else if (i == 55 + k && j % 2 == 0) {
	   
	    tmp_neg = Cudd_Not(var); 
	    tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec4[j]); 
	   
	   } else if (i == 55 + k && j % 2 == 1) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec4[j]); 

	   }
	  
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd_rec4[j]);
      bdd_rec4[j] = tmp;
    }
  }
    
    
    bdd8 = Cudd_bddOr(gbm,bdd_rec4[0],bdd_rec4[1]); 
    Cudd_Ref(bdd8);   
    
    for (k = 2;k<128;k++) {
    bdd8 = Cudd_bddOr(gbm,bdd8,bdd_rec4[k]);
    Cudd_Ref(bdd8);   
     }
 
    //bdd9 = Cudd_bddOr(gbm,bdd7,bdd8);
    //bdd = Cudd_bddAnd(gbm,bdd,bdd9);
     for(j = 0;j<128;j++){ 
       for (i = 48; i < 56; i++) {
          var = Cudd_bddIthVar(gbm,i); 
          if(i%8 ==  0) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec5[j]); 
	  }
	  else if(i == 49+k && j < 64 ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec5[j]); 
          }else if(i == 49+k && j >= 64) {
	  tmp = Cudd_bddAnd(gbm, var, bdd_rec5[j]); 
          }
	  else if ( (i == 50 + k) && ( ( j < 32 ) || ( j >= 64 && j < 96 ) ) ) {
          tmp_neg = Cudd_Not(var);
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec5[j]); 
          } else if ( i == 50 + k && ( ( j >= 32 && j < 64 ) || ( j >= 96 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec5[j]); 
	  } else if (i == 51 + k && ( (j<16) || (j>=32 && j<48) || (j>=64 && j<80) || (j>=96 && j<112) ) ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec5[j]); 
	  } else if (i == 51 + k && ( (j >= 16 && j < 32) || ( j >= 48 && j < 64 ) || ( j >= 80 && j < 96 ) || ( j >= 112 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec5[j]); 
          } else if ( i == 52 + k && ( ( j < 8 ) || ( j >= 16 && j < 24) || (j >= 32 && j < 40) || (j>=48 && j<56) || ( j >= 64 && j < 72 ) || 
		    (j >= 80 && j < 88) || (j >= 96 && j < 104) || (j>=112 && j<120) ) ) {
	   tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec5[j]); 
           } else if (i == 52 + k && ( ( j >= 8 && j < 16 ) || ( j >= 24 && j < 32 ) || ( j >= 40 && j < 48) || ( j >= 56 && j < 64) 
			|| (j>72 && j<=80) || (j>=88 && j<96) || (j>=104 && j<112) || (j>=120) ) ) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec5[j]);  
 	   } else if (i == 53 + k && ( (j < 4) || (j >= 8 && j < 12) || (j >= 16 && j < 20) || (j >= 24 && j < 28) || (j >= 32 && j < 36) || (j >= 40 && j < 44)
			|| (j >= 48 && j < 52)  || (j >= 56 && j < 60)|| (j >= 64 && j < 68) || (j >= 72 && j < 76) || (j >= 80 && j < 84) || (j >= 88 && j < 92) 	
			|| (j >= 96 && j < 100) || (j >= 104 && j < 108) || (j >= 112 && j < 116) || (j >= 120 && j < 124))) {
	   tmp_neg = Cudd_Not(var);
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec5[j]); 
	   
	   } else if (i == 53 + k && ( (j>=4 && j<8) || ( j >= 12 && j < 16 ) || ( j >= 20 && j < 24 ) || ( j >= 28 && j < 32 ) || ( j >= 36 && j < 40 ) 
			|| ( j >= 44 && j < 48 ) || ( j >= 52 && j < 56 ) || ( j >= 60 && j < 64 ) || ( j >= 68 && j < 72 ) || ( j >= 76 && j < 80 ) 	  
		        || ( j >= 84 && j < 88 ) || ( j >= 92 && j < 96 ) || ( j >= 100 && j < 104 ) || ( j >= 108 && j < 112 ) 
			|| ( j >= 116 && j < 120  ) 	|| ( j >= 124 && j < 128 ))) {
          
		   tmp = Cudd_bddAnd(gbm,var,bdd_rec5[j]); 
           } else if ( i == 54 + k && ( (j<2) || (j>=4 && j<6)  || (j>=8 && j<10) || (j>=12 && j<14) || (j>=16 && j<18) || (j>=20 && j<22) || (j>=24 && j<26)
			|| (j>=28 && j<30) || (j>=32 && j<34) || (j>=36 && j<38) || (j>=40 && j<42) || (j>=44 && j<46) || (j>=48 && j<50) || (j>=52 && j<54) 	  
			|| (j>=56 && j<58) || (j>=60 && j<62) || (j>=64 && j<66) || (j>=68 && j<70) || (j>=72 && j<74) || (j>=76 && j<78) || (j>=80 && j<82) 
                	|| (j>=84 && j<86) || (j>=88 && j<90) || (j>=92 && j<94) || (j>=96 && j<98) || (j>=100 && j<102) || (j>=104 && j<106) || (j>=108 && j<110) || 
                	(j>=112 && j<114) || (j>=116 && j<118)     || (j>=120 && j<122) || (j>=124 && j<126)
			)) {
	    tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec5[j]); 
	   } else if (i == 54 + k && ( (j>=2 && j<4) || (j>=6 && j<8) || (j>=10 && j<12) || (j>=14 && j<16) || (j>=18 && j<20) || (j>=22 && j<24) || (j>=26 && j<28)
			|| (j>=30 && j<32) || (j>=34 && j<36) || (j>=38 && j<40) || (j>=42 && j<44) || (j>=46 && j<48) || (j>=50 && j<52) 
			|| (j>=54 && j<56) || (j>=58 && j<60) || (j>=62 && j<64) || (j>=66 && j<68) || (j>=70 && j<72) || (j>=74 && j<76) 
			|| (j>=78 && j<80) || (j>=82 && j<84) || (j>=86 && j<88) || (j>=90 && j<92) || (j>=94 && j<96)
                        || (j>=98 && j<100) || (j>=102 && j<104) || (j>=106 && j<108) || (j>=110 && j<112) || (j>=114 && j<116) 
			|| (j>=118 && j<120) || (j>=122 && j<124) || (j>=126 && j<128) )) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec5[j]); 

	   } else if (i == 55 + k && j % 2 == 0) {
	   
	    tmp_neg = Cudd_Not(var); 
	    tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec5[j]); 
	   
	   } else if (i == 55 + k && j % 2 == 1) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec5[j]); 

	   }
	  
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd_rec5[j]);
      bdd_rec5[j] = tmp;
    }
  }
    
    
    bdd11 = Cudd_bddOr(gbm,bdd_rec5[0],bdd_rec5[1]); 
    Cudd_Ref(bdd11);   
    
    for (k = 2;k<128;k++) {
    bdd11 = Cudd_bddOr(gbm,bdd11,bdd_rec5[k]);
    Cudd_Ref(bdd11);   
     }
 
    bdd11 = Cudd_bddOr(gbm,bdd11,bdd8);
    bdd = Cudd_bddAnd(gbm,bdd,bdd11);
*/
    DdNode* bdd71;
   
    bdd71 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd71); /*Increases the reference count of a node*/

     for (i = 16; i < 18; i++) {  
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd71); 
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd71);
      bdd71 = tmp;
    }
    
    
    bdd = Cudd_bddAnd(gbm,bdd,bdd71);
    Cudd_Ref(bdd);

    return bdd;

    

}

//FUNZIONI PINGREQ

DdNode* scrivi_bdd_zero10 (DdManager *gbm, DdNode *bdd, DdNode * var) 
{
     DdNode* bdd_rec[128];
     DdNode* bdd_rec2[128];
     
     DdNode *bdd1, *bdd2, *bdd3, *bdd4, *bdd5, *bdd6, *bdd7, *bdd8, *bdd9,*tmp,*tmp_neg;
     bdd = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd); /*Increases the reference count of a node*/
     int i; 
     
     for(i = 0; i < 128; i++){
     bdd_rec[i] = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd_rec[i]); /*Increases the reference count of a node*/
     } 
     for(i = 0; i < 128; i++){
     bdd_rec2[i] = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd_rec2[i]); /*Increases the reference count of a node*/
     } 

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
     bdd6 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd6); /*Increases the reference count of a node*/
     bdd7 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd7); /*Increases the reference count of a node*/
     bdd8 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd8); /*Increases the reference count of a node*/
   
     
     for (i = 0; i < 8; i++) {
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
     if(i != 0 && i != 1) {
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
      tmp_neg = Cudd_Not(var); /*Perform NOT Boolean operation*/
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd1); /*Perform AND Boolean operation*/
            
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd1);
      bdd1 = tmp;
    }

    Cudd_Ref(bdd);
    bdd = Cudd_bddAnd(gbm,bdd,bdd1);

    DdNode* bdd71;
   
    bdd71 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd71); /*Increases the reference count of a node*/

     for (i = 16; i < 18; i++) {  
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd71); 
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd71);
      bdd71 = tmp;
    }
    
    
    bdd = Cudd_bddAnd(gbm,bdd,bdd71);
    Cudd_Ref(bdd);


       return bdd;

}



//FUNZIONI PINGRESP
DdNode* scrivi_bdd_zero11 (DdManager *gbm, DdNode *bdd, DdNode * var) 
{
     DdNode* bdd_rec[128];
     DdNode* bdd_rec2[128];
     
     DdNode *bdd1, *bdd2, *bdd3, *bdd4, *bdd5, *bdd6, *bdd7, *bdd8, *bdd9,*tmp,*tmp_neg;
     bdd = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd); /*Increases the reference count of a node*/
     int i; 
     
     for(i = 0; i < 128; i++){
     bdd_rec[i] = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd_rec[i]); /*Increases the reference count of a node*/
     } 
     for(i = 0; i < 128; i++){
     bdd_rec2[i] = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd_rec2[i]); /*Increases the reference count of a node*/
     } 

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
     bdd6 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd6); /*Increases the reference count of a node*/
     bdd7 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd7); /*Increases the reference count of a node*/
     bdd8 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd8); /*Increases the reference count of a node*/
   
     
     for (i = 0; i < 8; i++) {
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
     if(i != 0 && i != 1 && i != 3) {
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
      tmp_neg = Cudd_Not(var); /*Perform NOT Boolean operation*/
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd1); /*Perform AND Boolean operation*/
            
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd1);
      bdd1 = tmp;
    }

    Cudd_Ref(bdd);
    bdd = Cudd_bddAnd(gbm,bdd,bdd1);

    DdNode* bdd71;
   
    bdd71 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd71); /*Increases the reference count of a node*/

     for (i = 16; i < 18; i++) {  
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd71); 
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd71);
      bdd71 = tmp;
    }
    
    
    bdd = Cudd_bddAnd(gbm,bdd,bdd71);
    Cudd_Ref(bdd);


       return bdd;

}


//FUNZIONI DISCONNECT


DdNode* scrivi_bdd_zero12 (DdManager *gbm, DdNode *bdd, DdNode * var) 
{
     DdNode* bdd_rec[128];
     DdNode* bdd_rec2[128];
     
     DdNode *bdd1, *bdd2, *bdd3, *bdd4, *bdd5, *bdd6, *bdd7, *bdd8, *bdd9,*tmp,*tmp_neg;
     bdd = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd); /*Increases the reference count of a node*/
     int i; 
     
     for(i = 0; i < 128; i++){
     bdd_rec[i] = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd_rec[i]); /*Increases the reference count of a node*/
     } 
     for(i = 0; i < 128; i++){
     bdd_rec2[i] = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd_rec2[i]); /*Increases the reference count of a node*/
     } 

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
     bdd6 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd6); /*Increases the reference count of a node*/
     bdd7 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd7); /*Increases the reference count of a node*/
     bdd8 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd8); /*Increases the reference count of a node*/
   
     
     for (i = 0; i < 8; i++) {
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
     if(i != 0 && i != 1 && i != 2) {
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
      tmp_neg = Cudd_Not(var); /*Perform NOT Boolean operation*/
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd1); /*Perform AND Boolean operation*/
            
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd1);
      bdd1 = tmp;
    }

    Cudd_Ref(bdd);
    bdd = Cudd_bddAnd(gbm,bdd,bdd1);

    DdNode* bdd71;
   
    bdd71 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd71); /*Increases the reference count of a node*/

     for (i = 16; i < 18; i++) {  
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd71); 
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd71);
      bdd71 = tmp;
    }
    
    
    bdd = Cudd_bddAnd(gbm,bdd,bdd71);
    Cudd_Ref(bdd);

       return bdd;

}



//FUNZIONI SUBACK


DdNode* scrivi_bdd_zero13 (DdManager *gbm, DdNode *bdd, DdNode * var) 
{
     DdNode* bdd_rec[128];
     DdNode* bdd_rec2[128];
     DdNode* bdd_rec3[128];
     DdNode* bdd_rec4[128];

     DdNode *bdd1, *bdd2, *bdd3, *bdd4, *bdd5, *bdd6, *bdd7, *bdd8, *bdd9,*tmp,*tmp_neg;
     bdd = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd); /*Increases the reference count of a node*/
     int i; 
     
     for(i = 0; i < 128; i++){
     bdd_rec[i] = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd_rec[i]); /*Increases the reference count of a node*/
     } 
     for(i = 0; i < 128; i++){
     bdd_rec2[i] = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd_rec2[i]); /*Increases the reference count of a node*/
     } 
     for(i = 0; i < 128; i++){
     bdd_rec3[i] = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd_rec3[i]); /*Increases the reference count of a node*/
     } 
     for(i = 0; i < 128; i++){
     bdd_rec4[i] = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd_rec4[i]); /*Increases the reference count of a node*/
     } 
     
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
     bdd6 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd6); /*Increases the reference count of a node*/
     bdd7 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd7); /*Increases the reference count of a node*/
     bdd8 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd8); /*Increases the reference count of a node*/
   
     
     for (i = 0; i < 8; i++) {
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
     if(i != 0 && i != 3) {
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

int j;int k = 0;
     for(j = 0;j<128;j++){ 
       for (i = 8; i < 16; i++) {
          var = Cudd_bddIthVar(gbm,i); 
          if(i%8 ==  0) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	  }
	  else if(i == 9+k && j < 64 ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
          }else if(i == 9+k && j >= 64) {
	  tmp = Cudd_bddAnd(gbm, var, bdd_rec[j]); 
          }
	  else if ( (i == 10 + k) && ( ( j < 32 ) || ( j >= 64 && j < 96 ) ) ) {
          tmp_neg = Cudd_Not(var);
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
          } else if ( i == 10 + k && ( ( j >= 32 && j < 64 ) || ( j >= 96 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
	  } else if (i == 11 + k && ( (j<16) || (j>=32 && j<48) || (j>=64 && j<80) || (j>=96 && j<112) ) ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	  } else if (i == 11 + k && ( (j >= 16 && j < 32) || ( j >= 48 && j < 64 ) || ( j >= 80 && j < 96 ) || ( j >= 112 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
          } else if ( i == 12 + k && ( ( j < 8 ) || ( j >= 16 && j < 24) || (j >= 32 && j < 40) || (j>=48 && j<56) || ( j >= 64 && j < 72 ) || 
		    (j >= 80 && j < 88) || (j >= 96 && j < 104) || (j>=112 && j<120) ) ) {
	   tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
           } else if (i == 12 + k && ( ( j >= 8 && j < 16 ) || ( j >= 24 && j < 32 ) || ( j >= 40 && j < 48) || ( j >= 56 && j < 64) 
			|| (j>72 && j<=80) || (j>=88 && j<96) || (j>=104 && j<112) || (j>=120) ) ) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]);  
 	   } else if (i == 13 + k && ( (j < 4) || (j >= 8 && j < 12) || (j >= 16 && j < 20) || (j >= 24 && j < 28) || (j >= 32 && j < 36) || (j >= 40 && j < 44)
			|| (j >= 48 && j < 52)  || (j >= 56 && j < 60)|| (j >= 64 && j < 68) || (j >= 72 && j < 76) || (j >= 80 && j < 84) || (j >= 88 && j < 92) 	
			|| (j >= 96 && j < 100) || (j >= 104 && j < 108) || (j >= 112 && j < 116) || (j >= 120 && j < 124))) {
	   tmp_neg = Cudd_Not(var);
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   
	   } else if (i == 13 + k && ( (j>=4 && j<8) || ( j >= 12 && j < 16 ) || ( j >= 20 && j < 24 ) || ( j >= 28 && j < 32 ) || ( j >= 36 && j < 40 ) 
			|| ( j >= 44 && j < 48 ) || ( j >= 52 && j < 56 ) || ( j >= 60 && j < 64 ) || ( j >= 68 && j < 72 ) || ( j >= 76 && j < 80 ) 	  
		        || ( j >= 84 && j < 88 ) || ( j >= 92 && j < 96 ) || ( j >= 100 && j < 104 ) || ( j >= 108 && j < 112 ) 
			|| ( j >= 116 && j < 120  ) 	|| ( j >= 124 && j < 128 ))) {
          
		   tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
           } else if ( i == 14 + k && ( (j<2) || (j>=4 && j<6)  || (j>=8 && j<10) || (j>=12 && j<14) || (j>=16 && j<18) || (j>=20 && j<22) || (j>=24 && j<26)
			|| (j>=28 && j<30) || (j>=32 && j<34) || (j>=36 && j<38) || (j>=40 && j<42) || (j>=44 && j<46) || (j>=48 && j<50) || (j>=52 && j<54) 	  
			|| (j>=56 && j<58) || (j>=60 && j<62) || (j>=64 && j<66) || (j>=68 && j<70) || (j>=72 && j<74) || (j>=76 && j<78) || (j>=80 && j<82) 
                	|| (j>=84 && j<86) || (j>=88 && j<90) || (j>=92 && j<94) || (j>=96 && j<98) || (j>=100 && j<102) || (j>=104 && j<106) || (j>=108 && j<110) || 
                	(j>=112 && j<114) || (j>=116 && j<118)     || (j>=120 && j<122) || (j>=124 && j<126)
			)) {
	    tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   } else if (i == 14 + k && ( (j>=2 && j<4) || (j>=6 && j<8) || (j>=10 && j<12) || (j>=14 && j<16) || (j>=18 && j<20) || (j>=22 && j<24) || (j>=26 && j<28)
			|| (j>=30 && j<32) || (j>=34 && j<36) || (j>=38 && j<40) || (j>=42 && j<44) || (j>=46 && j<48) || (j>=50 && j<52) 
			|| (j>=54 && j<56) || (j>=58 && j<60) || (j>=62 && j<64) || (j>=66 && j<68) || (j>=70 && j<72) || (j>=74 && j<76) 
			|| (j>=78 && j<80) || (j>=82 && j<84) || (j>=86 && j<88) || (j>=90 && j<92) || (j>=94 && j<96)
                        || (j>=98 && j<100) || (j>=102 && j<104) || (j>=106 && j<108) || (j>=110 && j<112) || (j>=114 && j<116) 
			|| (j>=118 && j<120) || (j>=122 && j<124) || (j>=126 && j<128) )) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 

	   } else if (i == 15 + k && j % 2 == 0) {
	   
	    tmp_neg = Cudd_Not(var); 
	    tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   
	   } else if (i == 15 + k && j % 2 == 1) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 

	   }
	  
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd_rec[j]);
      bdd_rec[j] = tmp;
    }
  }
    
    bdd1 = Cudd_bddOr(gbm,bdd_rec[0],bdd_rec[1]); 
    Cudd_Ref(bdd1);   
    
    for (k = 2;k<128;k++) {
    bdd1 = Cudd_bddOr(gbm,bdd1,bdd_rec[k]);
    Cudd_Ref(bdd1);   
     }

    bdd = Cudd_bddAnd(gbm,bdd,bdd1);
    Cudd_Ref(bdd);   

  /* 

     for(j = 0;j<128;j++){ 
       for (i = 16; i < 24; i++) {
          var = Cudd_bddIthVar(gbm,i); 
          if(i%8 ==  0) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	  }
	  else if(i == 17+k && j < 64 ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
          }else if(i == 17+k && j >= 64) {
	  tmp = Cudd_bddAnd(gbm, var, bdd_rec[j]); 
          }
	  else if ( (i == 18 + k) && ( ( j < 32 ) || ( j >= 64 && j < 96 ) ) ) {
          tmp_neg = Cudd_Not(var);
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
          } else if ( i == 18 + k && ( ( j >= 32 && j < 64 ) || ( j >= 96 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
	  } else if (i == 19 + k && ( (j<16) || (j>=32 && j<48) || (j>=64 && j<80) || (j>=96 && j<112) ) ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	  } else if (i == 19 + k && ( (j >= 16 && j < 32) || ( j >= 48 && j < 64 ) || ( j >= 80 && j < 96 ) || ( j >= 112 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
          } else if ( i == 20 + k && ( ( j < 8 ) || ( j >= 16 && j < 24) || (j >= 32 && j < 40) || (j>=48 && j<56) || ( j >= 64 && j < 72 ) || 
		    (j >= 80 && j < 88) || (j >= 96 && j < 104) || (j>=112 && j<120) ) ) {
	   tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
           } else if (i == 20 + k && ( ( j >= 8 && j < 16 ) || ( j >= 24 && j < 32 ) || ( j >= 40 && j < 48) || ( j >= 56 && j < 64) 
			|| (j>72 && j<=80) || (j>=88 && j<96) || (j>=104 && j<112) || (j>=120) ) ) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]);  
 	   } else if (i == 21 + k && ( (j < 4) || (j >= 8 && j < 12) || (j >= 16 && j < 20) || (j >= 24 && j < 28) || (j >= 32 && j < 36) || (j >= 40 && j < 44)
			|| (j >= 48 && j < 52)  || (j >= 56 && j < 60)|| (j >= 64 && j < 68) || (j >= 72 && j < 76) || (j >= 80 && j < 84) || (j >= 88 && j < 92) 	
			|| (j >= 96 && j < 100) || (j >= 104 && j < 108) || (j >= 112 && j < 116) || (j >= 120 && j < 124))) {
	   tmp_neg = Cudd_Not(var);
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   
	   } else if (i == 21 + k && ( (j>=4 && j<8) || ( j >= 12 && j < 16 ) || ( j >= 20 && j < 24 ) || ( j >= 28 && j < 32 ) || ( j >= 36 && j < 40 ) 
			|| ( j >= 44 && j < 48 ) || ( j >= 52 && j < 56 ) || ( j >= 60 && j < 64 ) || ( j >= 68 && j < 72 ) || ( j >= 76 && j < 80 ) 	  
		        || ( j >= 84 && j < 88 ) || ( j >= 92 && j < 96 ) || ( j >= 100 && j < 104 ) || ( j >= 108 && j < 112 ) 
			|| ( j >= 116 && j < 120  ) 	|| ( j >= 124 && j < 128 ))) {
          
		   tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
           } else if ( i == 22 + k && ( (j<2) || (j>=4 && j<6)  || (j>=8 && j<10) || (j>=12 && j<14) || (j>=16 && j<18) || (j>=20 && j<22) || (j>=24 && j<26)
			|| (j>=28 && j<30) || (j>=32 && j<34) || (j>=36 && j<38) || (j>=40 && j<42) || (j>=44 && j<46) || (j>=48 && j<50) || (j>=52 && j<54) 	  
			|| (j>=56 && j<58) || (j>=60 && j<62) || (j>=64 && j<66) || (j>=68 && j<70) || (j>=72 && j<74) || (j>=76 && j<78) || (j>=80 && j<82) 
                	|| (j>=84 && j<86) || (j>=88 && j<90) || (j>=92 && j<94) || (j>=96 && j<98) || (j>=100 && j<102) || (j>=104 && j<106) || (j>=108 && j<110) || 
                	(j>=112 && j<114) || (j>=116 && j<118)     || (j>=120 && j<122) || (j>=124 && j<126)
			)) {
	    tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   } else if (i == 22 + k && ( (j>=2 && j<4) || (j>=6 && j<8) || (j>=10 && j<12) || (j>=14 && j<16) || (j>=18 && j<20) || (j>=22 && j<24) || (j>=26 && j<28)
			|| (j>=30 && j<32) || (j>=34 && j<36) || (j>=38 && j<40) || (j>=42 && j<44) || (j>=46 && j<48) || (j>=50 && j<52) 
			|| (j>=54 && j<56) || (j>=58 && j<60) || (j>=62 && j<64) || (j>=66 && j<68) || (j>=70 && j<72) || (j>=74 && j<76) 
			|| (j>=78 && j<80) || (j>=82 && j<84) || (j>=86 && j<88) || (j>=90 && j<92) || (j>=94 && j<96)
                        || (j>=98 && j<100) || (j>=102 && j<104) || (j>=106 && j<108) || (j>=110 && j<112) || (j>=114 && j<116) 
			|| (j>=118 && j<120) || (j>=122 && j<124) || (j>=126 && j<128) )) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 

	   } else if (i == 23 + k && j % 2 == 0) {
	   
	    tmp_neg = Cudd_Not(var); 
	    tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   
	   } else if (i == 23 + k && j % 2 == 1) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 

	   }
	  
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd_rec[j]);
      bdd_rec[j] = tmp;
    }
  }
    
    bdd4 = Cudd_bddOr(gbm,bdd_rec[0],bdd_rec[1]); 
    Cudd_Ref(bdd4);   
    
    for (k = 2;k<128;k++) {
    bdd4 = Cudd_bddOr(gbm,bdd4,bdd_rec[k]);
    Cudd_Ref(bdd4);   
     }

////    bdd = Cudd_bddAnd(gbm,bdd,bdd4);
    
    
     for(j = 0;j<128;j++){ 
       for (i = 16; i < 24; i++) {
          var = Cudd_bddIthVar(gbm,i); 
          if(i%8 ==  0) {
         // tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, var, bdd_rec2[j]); 
	  }
	  else if(i == 17+k && j < 64 ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec2[j]); 
          }else if(i == 17+k && j >= 64) {
	  tmp = Cudd_bddAnd(gbm, var, bdd_rec2[j]); 
          }
	  else if ( (i == 18 + k) && ( ( j < 32 ) || ( j >= 64 && j < 96 ) ) ) {
          tmp_neg = Cudd_Not(var);
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec2[j]); 
          } else if ( i == 18 + k && ( ( j >= 32 && j < 64 ) || ( j >= 96 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec2[j]); 
	  } else if (i == 19 + k && ( (j<16) || (j>=32 && j<48) || (j>=64 && j<80) || (j>=96 && j<112) ) ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec2[j]); 
	  } else if (i == 19 + k && ( (j >= 16 && j < 32) || ( j >= 48 && j < 64 ) || ( j >= 80 && j < 96 ) || ( j >= 112 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec2[j]); 
          } else if ( i == 20 + k && ( ( j < 8 ) || ( j >= 16 && j < 24) || (j >= 32 && j < 40) || (j>=48 && j<56) || ( j >= 64 && j < 72 ) || 
		    (j >= 80 && j < 88) || (j >= 96 && j < 104) || (j>=112 && j<120) ) ) {
	   tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec2[j]); 
           } else if (i == 20 + k && ( ( j >= 8 && j < 16 ) || ( j >= 24 && j < 32 ) || ( j >= 40 && j < 48) || ( j >= 56 && j < 64) 
			|| (j>72 && j<=80) || (j>=88 && j<96) || (j>=104 && j<112) || (j>=120) ) ) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec2[j]);  
 	   } else if (i == 21 + k && ( (j < 4) || (j >= 8 && j < 12) || (j >= 16 && j < 20) || (j >= 24 && j < 28) || (j >= 32 && j < 36) || (j >= 40 && j < 44)
			|| (j >= 48 && j < 52)  || (j >= 56 && j < 60)|| (j >= 64 && j < 68) || (j >= 72 && j < 76) || (j >= 80 && j < 84) || (j >= 88 && j < 92) 	
			|| (j >= 96 && j < 100) || (j >= 104 && j < 108) || (j >= 112 && j < 116) || (j >= 120 && j < 124))) {
	   tmp_neg = Cudd_Not(var);
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec2[j]); 
	   
	   } else if (i == 21 + k && ( (j>=4 && j<8) || ( j >= 12 && j < 16 ) || ( j >= 20 && j < 24 ) || ( j >= 28 && j < 32 ) || ( j >= 36 && j < 40 ) 
			|| ( j >= 44 && j < 48 ) || ( j >= 52 && j < 56 ) || ( j >= 60 && j < 64 ) || ( j >= 68 && j < 72 ) || ( j >= 76 && j < 80 ) 	  
		        || ( j >= 84 && j < 88 ) || ( j >= 92 && j < 96 ) || ( j >= 100 && j < 104 ) || ( j >= 108 && j < 112 ) 
			|| ( j >= 116 && j < 120  ) 	|| ( j >= 124 && j < 128 ))) {
          
		   tmp = Cudd_bddAnd(gbm,var,bdd_rec2[j]); 
           } else if ( i == 22 + k && ( (j<2) || (j>=4 && j<6)  || (j>=8 && j<10) || (j>=12 && j<14) || (j>=16 && j<18) || (j>=20 && j<22) || (j>=24 && j<26)
			|| (j>=28 && j<30) || (j>=32 && j<34) || (j>=36 && j<38) || (j>=40 && j<42) || (j>=44 && j<46) || (j>=48 && j<50) || (j>=52 && j<54) 	  
			|| (j>=56 && j<58) || (j>=60 && j<62) || (j>=64 && j<66) || (j>=68 && j<70) || (j>=72 && j<74) || (j>=76 && j<78) || (j>=80 && j<82) 
                	|| (j>=84 && j<86) || (j>=88 && j<90) || (j>=92 && j<94) || (j>=96 && j<98) || (j>=100 && j<102) || (j>=104 && j<106) || (j>=108 && j<110) || 
                	(j>=112 && j<114) || (j>=116 && j<118)     || (j>=120 && j<122) || (j>=124 && j<126)
			)) {
	    tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec2[j]); 
	   } else if (i == 22 + k && ( (j>=2 && j<4) || (j>=6 && j<8) || (j>=10 && j<12) || (j>=14 && j<16) || (j>=18 && j<20) || (j>=22 && j<24) || (j>=26 && j<28)
			|| (j>=30 && j<32) || (j>=34 && j<36) || (j>=38 && j<40) || (j>=42 && j<44) || (j>=46 && j<48) || (j>=50 && j<52) 
			|| (j>=54 && j<56) || (j>=58 && j<60) || (j>=62 && j<64) || (j>=66 && j<68) || (j>=70 && j<72) || (j>=74 && j<76) 
			|| (j>=78 && j<80) || (j>=82 && j<84) || (j>=86 && j<88) || (j>=90 && j<92) || (j>=94 && j<96)
                        || (j>=98 && j<100) || (j>=102 && j<104) || (j>=106 && j<108) || (j>=110 && j<112) || (j>=114 && j<116) 
			|| (j>=118 && j<120) || (j>=122 && j<124) || (j>=126 && j<128) )) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec2[j]); 

	   } else if (i == 23 + k && j % 2 == 0) {
	   
	    tmp_neg = Cudd_Not(var); 
	    tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec2[j]); 
	   
	   } else if (i == 23 + k && j % 2 == 1) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec2[j]); 

	   }
	  
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd_rec2[j]);
      bdd_rec2[j] = tmp;
    }
  }
    
    
    bdd5 = Cudd_bddOr(gbm,bdd_rec2[0],bdd_rec2[1]); 
    Cudd_Ref(bdd5);   
    
    for (k = 2;k<128;k++) {
    bdd5 = Cudd_bddOr(gbm,bdd5,bdd_rec2[k]);
    Cudd_Ref(bdd5);   
     }
 
    bdd6 = Cudd_bddOr(gbm,bdd4,bdd5);
 
    bdd = Cudd_bddAnd(gbm, bdd,bdd6);
 

	 

     for(j = 0;j<128;j++){ 
       for (i = 24; i < 32; i++) {
          var = Cudd_bddIthVar(gbm,i); 
          if(i%8 ==  0) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec3[j]); 
	  }
	  else if(i == 25+k && j < 64 ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec3[j]); 
          }else if(i == 25+k && j >= 64) {
	  tmp = Cudd_bddAnd(gbm, var, bdd_rec3[j]); 
          }
	  else if ( (i == 26 + k) && ( ( j < 32 ) || ( j >= 64 && j < 96 ) ) ) {
          tmp_neg = Cudd_Not(var);
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec3[j]); 
          } else if ( i == 26 + k && ( ( j >= 32 && j < 64 ) || ( j >= 96 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec3[j]); 
	  } else if (i == 27 + k && ( (j<16) || (j>=32 && j<48) || (j>=64 && j<80) || (j>=96 && j<112) ) ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec3[j]); 
	  } else if (i == 27 + k && ( (j >= 16 && j < 32) || ( j >= 48 && j < 64 ) || ( j >= 80 && j < 96 ) || ( j >= 112 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec3[j]); 
          } else if ( i == 28 + k && ( ( j < 8 ) || ( j >= 16 && j < 24) || (j >= 32 && j < 40) || (j>=48 && j<56) || ( j >= 64 && j < 72 ) || 
		    (j >= 80 && j < 88) || (j >= 96 && j < 104) || (j>=112 && j<120) ) ) {
	   tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec3[j]); 
           } else if (i == 28 + k && ( ( j >= 8 && j < 16 ) || ( j >= 24 && j < 32 ) || ( j >= 40 && j < 48) || ( j >= 56 && j < 64) 
			|| (j>72 && j<=80) || (j>=88 && j<96) || (j>=104 && j<112) || (j>=120) ) ) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec3[j]);  
 	   } else if (i == 29 + k && ( (j < 4) || (j >= 8 && j < 12) || (j >= 16 && j < 20) || (j >= 24 && j < 28) || (j >= 32 && j < 36) || (j >= 40 && j < 44)
			|| (j >= 48 && j < 52)  || (j >= 56 && j < 60)|| (j >= 64 && j < 68) || (j >= 72 && j < 76) || (j >= 80 && j < 84) || (j >= 88 && j < 92) 	
			|| (j >= 96 && j < 100) || (j >= 104 && j < 108) || (j >= 112 && j < 116) || (j >= 120 && j < 124))) {
	   tmp_neg = Cudd_Not(var);
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec3[j]); 
	   
	   } else if (i == 29 + k && ( (j>=4 && j<8) || ( j >= 12 && j < 16 ) || ( j >= 20 && j < 24 ) || ( j >= 28 && j < 32 ) || ( j >= 36 && j < 40 ) 
			|| ( j >= 44 && j < 48 ) || ( j >= 52 && j < 56 ) || ( j >= 60 && j < 64 ) || ( j >= 68 && j < 72 ) || ( j >= 76 && j < 80 ) 	  
		        || ( j >= 84 && j < 88 ) || ( j >= 92 && j < 96 ) || ( j >= 100 && j < 104 ) || ( j >= 108 && j < 112 ) 
			|| ( j >= 116 && j < 120  ) 	|| ( j >= 124 && j < 128 ))) {
          
		   tmp = Cudd_bddAnd(gbm,var,bdd_rec3[j]); 
           } else if ( i == 30 + k && ( (j<2) || (j>=4 && j<6)  || (j>=8 && j<10) || (j>=12 && j<14) || (j>=16 && j<18) || (j>=20 && j<22) || (j>=24 && j<26)
			|| (j>=28 && j<30) || (j>=32 && j<34) || (j>=36 && j<38) || (j>=40 && j<42) || (j>=44 && j<46) || (j>=48 && j<50) || (j>=52 && j<54) 	  
			|| (j>=56 && j<58) || (j>=60 && j<62) || (j>=64 && j<66) || (j>=68 && j<70) || (j>=72 && j<74) || (j>=76 && j<78) || (j>=80 && j<82) 
                	|| (j>=84 && j<86) || (j>=88 && j<90) || (j>=92 && j<94) || (j>=96 && j<98) || (j>=100 && j<102) || (j>=104 && j<106) || (j>=108 && j<110) || 
                	(j>=112 && j<114) || (j>=116 && j<118)     || (j>=120 && j<122) || (j>=124 && j<126)
			)) {
	    tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec3[j]); 
	   } else if (i == 30 + k && ( (j>=2 && j<4) || (j>=6 && j<8) || (j>=10 && j<12) || (j>=14 && j<16) || (j>=18 && j<20) || (j>=22 && j<24) || (j>=26 && j<28)
			|| (j>=30 && j<32) || (j>=34 && j<36) || (j>=38 && j<40) || (j>=42 && j<44) || (j>=46 && j<48) || (j>=50 && j<52) 
			|| (j>=54 && j<56) || (j>=58 && j<60) || (j>=62 && j<64) || (j>=66 && j<68) || (j>=70 && j<72) || (j>=74 && j<76) 
			|| (j>=78 && j<80) || (j>=82 && j<84) || (j>=86 && j<88) || (j>=90 && j<92) || (j>=94 && j<96)
                        || (j>=98 && j<100) || (j>=102 && j<104) || (j>=106 && j<108) || (j>=110 && j<112) || (j>=114 && j<116) 
			|| (j>=118 && j<120) || (j>=122 && j<124) || (j>=126 && j<128) )) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec3[j]); 

	   } else if (i == 31 + k && j % 2 == 0) {
	   
	    tmp_neg = Cudd_Not(var); 
	    tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec3[j]); 
	   
	   } else if (i == 31 + k && j % 2 == 1) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec3[j]); 

	   }
	  
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd_rec3[j]);
      bdd_rec3[j] = tmp;
    }
  }
    
    bdd7 = Cudd_bddOr(gbm,bdd_rec3[0],bdd_rec3[1]); 
    Cudd_Ref(bdd7);   
    
    for (k = 2;k<128;k++) {
    bdd7 = Cudd_bddOr(gbm,bdd7,bdd_rec3[k]);
    Cudd_Ref(bdd7);   
     }

     for(j = 0;j<128;j++){ 
       for (i = 24; i < 32; i++) {
          var = Cudd_bddIthVar(gbm,i); 
          if(i%8 ==  0) {
         // tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, var, bdd_rec4[j]); 
	  }
	  else if(i == 25+k && j < 64 ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec4[j]); 
          }else if(i == 25+k && j >= 64) {
	  tmp = Cudd_bddAnd(gbm, var, bdd_rec4[j]); 
          }
	  else if ( (i == 26 + k) && ( ( j < 32 ) || ( j >= 64 && j < 96 ) ) ) {
          tmp_neg = Cudd_Not(var);
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec4[j]); 
          } else if ( i == 26 + k && ( ( j >= 32 && j < 64 ) || ( j >= 96 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec4[j]); 
	  } else if (i == 27 + k && ( (j<16) || (j>=32 && j<48) || (j>=64 && j<80) || (j>=96 && j<112) ) ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec4[j]); 
	  } else if (i == 27 + k && ( (j >= 16 && j < 32) || ( j >= 48 && j < 64 ) || ( j >= 80 && j < 96 ) || ( j >= 112 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec4[j]); 
          } else if ( i == 28 + k && ( ( j < 8 ) || ( j >= 16 && j < 24) || (j >= 32 && j < 40) || (j>=48 && j<56) || ( j >= 64 && j < 72 ) || 
		    (j >= 80 && j < 88) || (j >= 96 && j < 104) || (j>=112 && j<120) ) ) {
	   tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec4[j]); 
           } else if (i == 28 + k && ( ( j >= 8 && j < 16 ) || ( j >= 24 && j < 32 ) || ( j >= 40 && j < 48) || ( j >= 56 && j < 64) 
			|| (j>72 && j<=80) || (j>=88 && j<96) || (j>=104 && j<112) || (j>=120) ) ) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec4[j]);  
 	   } else if (i == 29 + k && ( (j < 4) || (j >= 8 && j < 12) || (j >= 16 && j < 20) || (j >= 24 && j < 28) || (j >= 32 && j < 36) || (j >= 40 && j < 44)
			|| (j >= 48 && j < 52)  || (j >= 56 && j < 60)|| (j >= 64 && j < 68) || (j >= 72 && j < 76) || (j >= 80 && j < 84) || (j >= 88 && j < 92) 	
			|| (j >= 96 && j < 100) || (j >= 104 && j < 108) || (j >= 112 && j < 116) || (j >= 120 && j < 124))) {
	   tmp_neg = Cudd_Not(var);
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec4[j]); 
	   
	   } else if (i == 29 + k && ( (j>=4 && j<8) || ( j >= 12 && j < 16 ) || ( j >= 20 && j < 24 ) || ( j >= 28 && j < 32 ) || ( j >= 36 && j < 40 ) 
			|| ( j >= 44 && j < 48 ) || ( j >= 52 && j < 56 ) || ( j >= 60 && j < 64 ) || ( j >= 68 && j < 72 ) || ( j >= 76 && j < 80 ) 	  
		        || ( j >= 84 && j < 88 ) || ( j >= 92 && j < 96 ) || ( j >= 100 && j < 104 ) || ( j >= 108 && j < 112 ) 
			|| ( j >= 116 && j < 120  ) 	|| ( j >= 124 && j < 128 ))) {
          
		   tmp = Cudd_bddAnd(gbm,var,bdd_rec4[j]); 
           } else if ( i == 30 + k && ( (j<2) || (j>=4 && j<6)  || (j>=8 && j<10) || (j>=12 && j<14) || (j>=16 && j<18) || (j>=20 && j<22) || (j>=24 && j<26)
			|| (j>=28 && j<30) || (j>=32 && j<34) || (j>=36 && j<38) || (j>=40 && j<42) || (j>=44 && j<46) || (j>=48 && j<50) || (j>=52 && j<54) 	  
			|| (j>=56 && j<58) || (j>=60 && j<62) || (j>=64 && j<66) || (j>=68 && j<70) || (j>=72 && j<74) || (j>=76 && j<78) || (j>=80 && j<82) 
                	|| (j>=84 && j<86) || (j>=88 && j<90) || (j>=92 && j<94) || (j>=96 && j<98) || (j>=100 && j<102) || (j>=104 && j<106) || (j>=108 && j<110) || 
                	(j>=112 && j<114) || (j>=116 && j<118)     || (j>=120 && j<122) || (j>=124 && j<126)
			)) {
	    tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec4[j]); 
	   } else if (i == 30 + k && ( (j>=2 && j<4) || (j>=6 && j<8) || (j>=10 && j<12) || (j>=14 && j<16) || (j>=18 && j<20) || (j>=22 && j<24) || (j>=26 && j<28)
			|| (j>=30 && j<32) || (j>=34 && j<36) || (j>=38 && j<40) || (j>=42 && j<44) || (j>=46 && j<48) || (j>=50 && j<52) 
			|| (j>=54 && j<56) || (j>=58 && j<60) || (j>=62 && j<64) || (j>=66 && j<68) || (j>=70 && j<72) || (j>=74 && j<76) 
			|| (j>=78 && j<80) || (j>=82 && j<84) || (j>=86 && j<88) || (j>=90 && j<92) || (j>=94 && j<96)
                        || (j>=98 && j<100) || (j>=102 && j<104) || (j>=106 && j<108) || (j>=110 && j<112) || (j>=114 && j<116) 
			|| (j>=118 && j<120) || (j>=122 && j<124) || (j>=126 && j<128) )) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec4[j]); 

	   } else if (i == 31 + k && j % 2 == 0) {
	   
	    tmp_neg = Cudd_Not(var); 
	    tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec4[j]); 
	   
	   } else if (i == 31 + k && j % 2 == 1) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec4[j]); 

	   }
	  
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd_rec4[j]);
      bdd_rec4[j] = tmp;
    }
  }
    
    
    bdd8 = Cudd_bddOr(gbm,bdd_rec4[0],bdd_rec4[1]); 
    Cudd_Ref(bdd8);   
    
    for (k = 2;k<128;k++) {
    bdd8 = Cudd_bddOr(gbm,bdd8,bdd_rec4[k]);
    Cudd_Ref(bdd8);   
     }
 
    bdd9 = Cudd_bddOr(gbm,bdd7,bdd8);
    bdd = Cudd_bddAnd(gbm,bdd,bdd9);
*/
    DdNode* bdd71;
   
    bdd71 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd71); /*Increases the reference count of a node*/

     for (i = 16; i < 18; i++) {  
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd71); 
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd71);
      bdd71 = tmp;
    }
    
    
    bdd = Cudd_bddAnd(gbm,bdd,bdd71);
    Cudd_Ref(bdd);

    return bdd;

}




DdNode* scrivi_bdd_uno13 (DdManager *gbm, DdNode *bdd, DdNode * var) 
{
     DdNode* bdd_rec[128];
     DdNode* bdd_rec2[128];
     DdNode* bdd_rec3[128];
     DdNode* bdd_rec4[128];

     DdNode *bdd1, *bdd2, *bdd3, *bdd4, *bdd5, *bdd6, *bdd7, *bdd8, *bdd9,*tmp,*tmp_neg;
     bdd = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd); /*Increases the reference count of a node*/
     int i; 
     
     for(i = 0; i < 128; i++){
     bdd_rec[i] = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd_rec[i]); /*Increases the reference count of a node*/
     } 
     for(i = 0; i < 128; i++){
     bdd_rec2[i] = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd_rec2[i]); /*Increases the reference count of a node*/
     } 
     for(i = 0; i < 128; i++){
     bdd_rec3[i] = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd_rec3[i]); /*Increases the reference count of a node*/
     } 
     for(i = 0; i < 128; i++){
     bdd_rec4[i] = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd_rec4[i]); /*Increases the reference count of a node*/
     } 
     
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
     bdd6 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd6); /*Increases the reference count of a node*/
     bdd7 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd7); /*Increases the reference count of a node*/
     bdd8 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd8); /*Increases the reference count of a node*/
   
     
     for (i = 0; i < 8; i++) {
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
     if(i != 0 && i != 3) {
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

int j;int k = 0;
     for(j = 0;j<128;j++){ 
       for (i = 8; i < 16; i++) {
          var = Cudd_bddIthVar(gbm,i); 
          if(i%8 ==  0) {
     //     tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, var, bdd_rec[j]); 
	  }
	  else if(i == 9+k && j < 64 ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
          }else if(i == 9+k && j >= 64) {
	  tmp = Cudd_bddAnd(gbm, var, bdd_rec[j]); 
          }
	  else if ( (i == 10 + k) && ( ( j < 32 ) || ( j >= 64 && j < 96 ) ) ) {
          tmp_neg = Cudd_Not(var);
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
          } else if ( i == 10 + k && ( ( j >= 32 && j < 64 ) || ( j >= 96 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
	  } else if (i == 11 + k && ( (j<16) || (j>=32 && j<48) || (j>=64 && j<80) || (j>=96 && j<112) ) ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	  } else if (i == 11 + k && ( (j >= 16 && j < 32) || ( j >= 48 && j < 64 ) || ( j >= 80 && j < 96 ) || ( j >= 112 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
          } else if ( i == 12 + k && ( ( j < 8 ) || ( j >= 16 && j < 24) || (j >= 32 && j < 40) || (j>=48 && j<56) || ( j >= 64 && j < 72 ) || 
		    (j >= 80 && j < 88) || (j >= 96 && j < 104) || (j>=112 && j<120) ) ) {
	   tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
           } else if (i == 12 + k && ( ( j >= 8 && j < 16 ) || ( j >= 24 && j < 32 ) || ( j >= 40 && j < 48) || ( j >= 56 && j < 64) 
			|| (j>72 && j<=80) || (j>=88 && j<96) || (j>=104 && j<112) || (j>=120) ) ) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]);  
 	   } else if (i == 13 + k && ( (j < 4) || (j >= 8 && j < 12) || (j >= 16 && j < 20) || (j >= 24 && j < 28) || (j >= 32 && j < 36) || (j >= 40 && j < 44)
			|| (j >= 48 && j < 52)  || (j >= 56 && j < 60)|| (j >= 64 && j < 68) || (j >= 72 && j < 76) || (j >= 80 && j < 84) || (j >= 88 && j < 92) 	
			|| (j >= 96 && j < 100) || (j >= 104 && j < 108) || (j >= 112 && j < 116) || (j >= 120 && j < 124))) {
	   tmp_neg = Cudd_Not(var);
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   
	   } else if (i == 13 + k && ( (j>=4 && j<8) || ( j >= 12 && j < 16 ) || ( j >= 20 && j < 24 ) || ( j >= 28 && j < 32 ) || ( j >= 36 && j < 40 ) 
			|| ( j >= 44 && j < 48 ) || ( j >= 52 && j < 56 ) || ( j >= 60 && j < 64 ) || ( j >= 68 && j < 72 ) || ( j >= 76 && j < 80 ) 	  
		        || ( j >= 84 && j < 88 ) || ( j >= 92 && j < 96 ) || ( j >= 100 && j < 104 ) || ( j >= 108 && j < 112 ) 
			|| ( j >= 116 && j < 120  ) 	|| ( j >= 124 && j < 128 ))) {
          
		   tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
           } else if ( i == 14 + k && ( (j<2) || (j>=4 && j<6)  || (j>=8 && j<10) || (j>=12 && j<14) || (j>=16 && j<18) || (j>=20 && j<22) || (j>=24 && j<26)
			|| (j>=28 && j<30) || (j>=32 && j<34) || (j>=36 && j<38) || (j>=40 && j<42) || (j>=44 && j<46) || (j>=48 && j<50) || (j>=52 && j<54) 	  
			|| (j>=56 && j<58) || (j>=60 && j<62) || (j>=64 && j<66) || (j>=68 && j<70) || (j>=72 && j<74) || (j>=76 && j<78) || (j>=80 && j<82) 
                	|| (j>=84 && j<86) || (j>=88 && j<90) || (j>=92 && j<94) || (j>=96 && j<98) || (j>=100 && j<102) || (j>=104 && j<106) || (j>=108 && j<110) || 
                	(j>=112 && j<114) || (j>=116 && j<118)     || (j>=120 && j<122) || (j>=124 && j<126)
			)) {
	    tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   } else if (i == 14 + k && ( (j>=2 && j<4) || (j>=6 && j<8) || (j>=10 && j<12) || (j>=14 && j<16) || (j>=18 && j<20) || (j>=22 && j<24) || (j>=26 && j<28)
			|| (j>=30 && j<32) || (j>=34 && j<36) || (j>=38 && j<40) || (j>=42 && j<44) || (j>=46 && j<48) || (j>=50 && j<52) 
			|| (j>=54 && j<56) || (j>=58 && j<60) || (j>=62 && j<64) || (j>=66 && j<68) || (j>=70 && j<72) || (j>=74 && j<76) 
			|| (j>=78 && j<80) || (j>=82 && j<84) || (j>=86 && j<88) || (j>=90 && j<92) || (j>=94 && j<96)
                        || (j>=98 && j<100) || (j>=102 && j<104) || (j>=106 && j<108) || (j>=110 && j<112) || (j>=114 && j<116) 
			|| (j>=118 && j<120) || (j>=122 && j<124) || (j>=126 && j<128) )) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 

	   } else if (i == 15 + k && j % 2 == 0) {
	   
	    tmp_neg = Cudd_Not(var); 
	    tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   
	   } else if (i == 15 + k && j % 2 == 1) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 

	   }
	  
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd_rec[j]);
      bdd_rec[j] = tmp;
    }
  }
    
    bdd1 = Cudd_bddOr(gbm,bdd_rec[0],bdd_rec[1]); 
    Cudd_Ref(bdd1);   
    
    for (k = 2;k<128;k++) {
    bdd1 = Cudd_bddOr(gbm,bdd1,bdd_rec[k]);
    Cudd_Ref(bdd1);   
     }

    bdd = Cudd_bddAnd(gbm,bdd,bdd1);
    Cudd_Ref(bdd);   
/*
     for(j = 0;j<128;j++){ 
       for (i = 16; i < 24; i++) {
          var = Cudd_bddIthVar(gbm,i); 
          if(i%8 ==  0) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	  }
	  else if(i == 17+k && j < 64 ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
          }else if(i == 17+k && j >= 64) {
	  tmp = Cudd_bddAnd(gbm, var, bdd_rec[j]); 
          }
	  else if ( (i == 18 + k) && ( ( j < 32 ) || ( j >= 64 && j < 96 ) ) ) {
          tmp_neg = Cudd_Not(var);
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
          } else if ( i == 18 + k && ( ( j >= 32 && j < 64 ) || ( j >= 96 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
	  } else if (i == 19 + k && ( (j<16) || (j>=32 && j<48) || (j>=64 && j<80) || (j>=96 && j<112) ) ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	  } else if (i == 19 + k && ( (j >= 16 && j < 32) || ( j >= 48 && j < 64 ) || ( j >= 80 && j < 96 ) || ( j >= 112 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
          } else if ( i == 20 + k && ( ( j < 8 ) || ( j >= 16 && j < 24) || (j >= 32 && j < 40) || (j>=48 && j<56) || ( j >= 64 && j < 72 ) || 
		    (j >= 80 && j < 88) || (j >= 96 && j < 104) || (j>=112 && j<120) ) ) {
	   tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
           } else if (i == 20 + k && ( ( j >= 8 && j < 16 ) || ( j >= 24 && j < 32 ) || ( j >= 40 && j < 48) || ( j >= 56 && j < 64) 
			|| (j>72 && j<=80) || (j>=88 && j<96) || (j>=104 && j<112) || (j>=120) ) ) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]);  
 	   } else if (i == 21 + k && ( (j < 4) || (j >= 8 && j < 12) || (j >= 16 && j < 20) || (j >= 24 && j < 28) || (j >= 32 && j < 36) || (j >= 40 && j < 44)
			|| (j >= 48 && j < 52)  || (j >= 56 && j < 60)|| (j >= 64 && j < 68) || (j >= 72 && j < 76) || (j >= 80 && j < 84) || (j >= 88 && j < 92) 	
			|| (j >= 96 && j < 100) || (j >= 104 && j < 108) || (j >= 112 && j < 116) || (j >= 120 && j < 124))) {
	   tmp_neg = Cudd_Not(var);
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   
	   } else if (i == 21 + k && ( (j>=4 && j<8) || ( j >= 12 && j < 16 ) || ( j >= 20 && j < 24 ) || ( j >= 28 && j < 32 ) || ( j >= 36 && j < 40 ) 
			|| ( j >= 44 && j < 48 ) || ( j >= 52 && j < 56 ) || ( j >= 60 && j < 64 ) || ( j >= 68 && j < 72 ) || ( j >= 76 && j < 80 ) 	  
		        || ( j >= 84 && j < 88 ) || ( j >= 92 && j < 96 ) || ( j >= 100 && j < 104 ) || ( j >= 108 && j < 112 ) 
			|| ( j >= 116 && j < 120  ) 	|| ( j >= 124 && j < 128 ))) {
          
		   tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
           } else if ( i == 22 + k && ( (j<2) || (j>=4 && j<6)  || (j>=8 && j<10) || (j>=12 && j<14) || (j>=16 && j<18) || (j>=20 && j<22) || (j>=24 && j<26)
			|| (j>=28 && j<30) || (j>=32 && j<34) || (j>=36 && j<38) || (j>=40 && j<42) || (j>=44 && j<46) || (j>=48 && j<50) || (j>=52 && j<54) 	  
			|| (j>=56 && j<58) || (j>=60 && j<62) || (j>=64 && j<66) || (j>=68 && j<70) || (j>=72 && j<74) || (j>=76 && j<78) || (j>=80 && j<82) 
                	|| (j>=84 && j<86) || (j>=88 && j<90) || (j>=92 && j<94) || (j>=96 && j<98) || (j>=100 && j<102) || (j>=104 && j<106) || (j>=108 && j<110) || 
                	(j>=112 && j<114) || (j>=116 && j<118)     || (j>=120 && j<122) || (j>=124 && j<126)
			)) {
	    tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   } else if (i == 22 + k && ( (j>=2 && j<4) || (j>=6 && j<8) || (j>=10 && j<12) || (j>=14 && j<16) || (j>=18 && j<20) || (j>=22 && j<24) || (j>=26 && j<28)
			|| (j>=30 && j<32) || (j>=34 && j<36) || (j>=38 && j<40) || (j>=42 && j<44) || (j>=46 && j<48) || (j>=50 && j<52) 
			|| (j>=54 && j<56) || (j>=58 && j<60) || (j>=62 && j<64) || (j>=66 && j<68) || (j>=70 && j<72) || (j>=74 && j<76) 
			|| (j>=78 && j<80) || (j>=82 && j<84) || (j>=86 && j<88) || (j>=90 && j<92) || (j>=94 && j<96)
                        || (j>=98 && j<100) || (j>=102 && j<104) || (j>=106 && j<108) || (j>=110 && j<112) || (j>=114 && j<116) 
			|| (j>=118 && j<120) || (j>=122 && j<124) || (j>=126 && j<128) )) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 

	   } else if (i == 23 + k && j % 2 == 0) {
	   
	    tmp_neg = Cudd_Not(var); 
	    tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   
	   } else if (i == 23 + k && j % 2 == 1) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 

	   }
	  
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd_rec[j]);
      bdd_rec[j] = tmp;
    }
  }
    
    bdd2 = Cudd_bddOr(gbm,bdd_rec[0],bdd_rec[1]); 
    Cudd_Ref(bdd2);   
    
    for (k = 2;k<128;k++) {
    bdd2 = Cudd_bddOr(gbm,bdd2,bdd_rec[k]);
    Cudd_Ref(bdd2);   
     }

    bdd = Cudd_bddAnd(gbm,bdd,bdd2);
    Cudd_Ref(bdd);   
   

     for(j = 0;j<128;j++){ 
       for (i = 24; i < 32; i++) {
          var = Cudd_bddIthVar(gbm,i); 
          if(i%8 ==  0) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	  }
	  else if(i == 25+k && j < 64 ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
          }else if(i == 25+k && j >= 64) {
	  tmp = Cudd_bddAnd(gbm, var, bdd_rec[j]); 
          }
	  else if ( (i == 26 + k) && ( ( j < 32 ) || ( j >= 64 && j < 96 ) ) ) {
          tmp_neg = Cudd_Not(var);
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
          } else if ( i == 26 + k && ( ( j >= 32 && j < 64 ) || ( j >= 96 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
	  } else if (i == 27 + k && ( (j<16) || (j>=32 && j<48) || (j>=64 && j<80) || (j>=96 && j<112) ) ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	  } else if (i == 27 + k && ( (j >= 16 && j < 32) || ( j >= 48 && j < 64 ) || ( j >= 80 && j < 96 ) || ( j >= 112 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
          } else if ( i == 28 + k && ( ( j < 8 ) || ( j >= 16 && j < 24) || (j >= 32 && j < 40) || (j>=48 && j<56) || ( j >= 64 && j < 72 ) || 
		    (j >= 80 && j < 88) || (j >= 96 && j < 104) || (j>=112 && j<120) ) ) {
	   tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
           } else if (i == 28 + k && ( ( j >= 8 && j < 16 ) || ( j >= 24 && j < 32 ) || ( j >= 40 && j < 48) || ( j >= 56 && j < 64) 
			|| (j>72 && j<=80) || (j>=88 && j<96) || (j>=104 && j<112) || (j>=120) ) ) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]);  
 	   } else if (i == 29 + k && ( (j < 4) || (j >= 8 && j < 12) || (j >= 16 && j < 20) || (j >= 24 && j < 28) || (j >= 32 && j < 36) || (j >= 40 && j < 44)
			|| (j >= 48 && j < 52)  || (j >= 56 && j < 60)|| (j >= 64 && j < 68) || (j >= 72 && j < 76) || (j >= 80 && j < 84) || (j >= 88 && j < 92) 	
			|| (j >= 96 && j < 100) || (j >= 104 && j < 108) || (j >= 112 && j < 116) || (j >= 120 && j < 124))) {
	   tmp_neg = Cudd_Not(var);
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   
	   } else if (i == 29 + k && ( (j>=4 && j<8) || ( j >= 12 && j < 16 ) || ( j >= 20 && j < 24 ) || ( j >= 28 && j < 32 ) || ( j >= 36 && j < 40 ) 
			|| ( j >= 44 && j < 48 ) || ( j >= 52 && j < 56 ) || ( j >= 60 && j < 64 ) || ( j >= 68 && j < 72 ) || ( j >= 76 && j < 80 ) 	  
		        || ( j >= 84 && j < 88 ) || ( j >= 92 && j < 96 ) || ( j >= 100 && j < 104 ) || ( j >= 108 && j < 112 ) 
			|| ( j >= 116 && j < 120  ) 	|| ( j >= 124 && j < 128 ))) {
          
		   tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
           } else if ( i == 30 + k && ( (j<2) || (j>=4 && j<6)  || (j>=8 && j<10) || (j>=12 && j<14) || (j>=16 && j<18) || (j>=20 && j<22) || (j>=24 && j<26)
			|| (j>=28 && j<30) || (j>=32 && j<34) || (j>=36 && j<38) || (j>=40 && j<42) || (j>=44 && j<46) || (j>=48 && j<50) || (j>=52 && j<54) 	  
			|| (j>=56 && j<58) || (j>=60 && j<62) || (j>=64 && j<66) || (j>=68 && j<70) || (j>=72 && j<74) || (j>=76 && j<78) || (j>=80 && j<82) 
                	|| (j>=84 && j<86) || (j>=88 && j<90) || (j>=92 && j<94) || (j>=96 && j<98) || (j>=100 && j<102) || (j>=104 && j<106) || (j>=108 && j<110) || 
                	(j>=112 && j<114) || (j>=116 && j<118)     || (j>=120 && j<122) || (j>=124 && j<126)
			)) {
	    tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   } else if (i == 30 + k && ( (j>=2 && j<4) || (j>=6 && j<8) || (j>=10 && j<12) || (j>=14 && j<16) || (j>=18 && j<20) || (j>=22 && j<24) || (j>=26 && j<28)
			|| (j>=30 && j<32) || (j>=34 && j<36) || (j>=38 && j<40) || (j>=42 && j<44) || (j>=46 && j<48) || (j>=50 && j<52) 
			|| (j>=54 && j<56) || (j>=58 && j<60) || (j>=62 && j<64) || (j>=66 && j<68) || (j>=70 && j<72) || (j>=74 && j<76) 
			|| (j>=78 && j<80) || (j>=82 && j<84) || (j>=86 && j<88) || (j>=90 && j<92) || (j>=94 && j<96)
                        || (j>=98 && j<100) || (j>=102 && j<104) || (j>=106 && j<108) || (j>=110 && j<112) || (j>=114 && j<116) 
			|| (j>=118 && j<120) || (j>=122 && j<124) || (j>=126 && j<128) )) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 

	   } else if (i == 31 + k && j % 2 == 0) {
	   
	    tmp_neg = Cudd_Not(var); 
	    tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   
	   } else if (i == 31 + k && j % 2 == 1) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 

	   }
	  
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd_rec[j]);
      bdd_rec[j] = tmp;
    }
  }
    
    bdd4 = Cudd_bddOr(gbm,bdd_rec[0],bdd_rec[1]); 
    Cudd_Ref(bdd4);   
    
    for (k = 2;k<128;k++) {
    bdd4 = Cudd_bddOr(gbm,bdd4,bdd_rec[k]);
    Cudd_Ref(bdd4);   
     }

////    bdd = Cudd_bddAnd(gbm,bdd,bdd4);
    
    
     for(j = 0;j<128;j++){ 
       for (i = 24; i < 32; i++) {
          var = Cudd_bddIthVar(gbm,i); 
          if(i%8 ==  0) {
         // tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, var, bdd_rec2[j]); 
	  }
	  else if(i == 25+k && j < 64 ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec2[j]); 
          }else if(i == 25+k && j >= 64) {
	  tmp = Cudd_bddAnd(gbm, var, bdd_rec2[j]); 
          }
	  else if ( (i == 26 + k) && ( ( j < 32 ) || ( j >= 64 && j < 96 ) ) ) {
          tmp_neg = Cudd_Not(var);
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec2[j]); 
          } else if ( i == 26 + k && ( ( j >= 32 && j < 64 ) || ( j >= 96 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec2[j]); 
	  } else if (i == 27 + k && ( (j<16) || (j>=32 && j<48) || (j>=64 && j<80) || (j>=96 && j<112) ) ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec2[j]); 
	  } else if (i == 27 + k && ( (j >= 16 && j < 32) || ( j >= 48 && j < 64 ) || ( j >= 80 && j < 96 ) || ( j >= 112 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec2[j]); 
          } else if ( i == 28 + k && ( ( j < 8 ) || ( j >= 16 && j < 24) || (j >= 32 && j < 40) || (j>=48 && j<56) || ( j >= 64 && j < 72 ) || 
		    (j >= 80 && j < 88) || (j >= 96 && j < 104) || (j>=112 && j<120) ) ) {
	   tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec2[j]); 
           } else if (i == 28 + k && ( ( j >= 8 && j < 16 ) || ( j >= 24 && j < 32 ) || ( j >= 40 && j < 48) || ( j >= 56 && j < 64) 
			|| (j>72 && j<=80) || (j>=88 && j<96) || (j>=104 && j<112) || (j>=120) ) ) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec2[j]);  
 	   } else if (i == 29 + k && ( (j < 4) || (j >= 8 && j < 12) || (j >= 16 && j < 20) || (j >= 24 && j < 28) || (j >= 32 && j < 36) || (j >= 40 && j < 44)
			|| (j >= 48 && j < 52)  || (j >= 56 && j < 60)|| (j >= 64 && j < 68) || (j >= 72 && j < 76) || (j >= 80 && j < 84) || (j >= 88 && j < 92) 	
			|| (j >= 96 && j < 100) || (j >= 104 && j < 108) || (j >= 112 && j < 116) || (j >= 120 && j < 124))) {
	   tmp_neg = Cudd_Not(var);
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec2[j]); 
	   
	   } else if (i == 29 + k && ( (j>=4 && j<8) || ( j >= 12 && j < 16 ) || ( j >= 20 && j < 24 ) || ( j >= 28 && j < 32 ) || ( j >= 36 && j < 40 ) 
			|| ( j >= 44 && j < 48 ) || ( j >= 52 && j < 56 ) || ( j >= 60 && j < 64 ) || ( j >= 68 && j < 72 ) || ( j >= 76 && j < 80 ) 	  
		        || ( j >= 84 && j < 88 ) || ( j >= 92 && j < 96 ) || ( j >= 100 && j < 104 ) || ( j >= 108 && j < 112 ) 
			|| ( j >= 116 && j < 120  ) 	|| ( j >= 124 && j < 128 ))) {
          
		   tmp = Cudd_bddAnd(gbm,var,bdd_rec2[j]); 
           } else if ( i == 30 + k && ( (j<2) || (j>=4 && j<6)  || (j>=8 && j<10) || (j>=12 && j<14) || (j>=16 && j<18) || (j>=20 && j<22) || (j>=24 && j<26)
			|| (j>=28 && j<30) || (j>=32 && j<34) || (j>=36 && j<38) || (j>=40 && j<42) || (j>=44 && j<46) || (j>=48 && j<50) || (j>=52 && j<54) 	  
			|| (j>=56 && j<58) || (j>=60 && j<62) || (j>=64 && j<66) || (j>=68 && j<70) || (j>=72 && j<74) || (j>=76 && j<78) || (j>=80 && j<82) 
                	|| (j>=84 && j<86) || (j>=88 && j<90) || (j>=92 && j<94) || (j>=96 && j<98) || (j>=100 && j<102) || (j>=104 && j<106) || (j>=108 && j<110) || 
                	(j>=112 && j<114) || (j>=116 && j<118)     || (j>=120 && j<122) || (j>=124 && j<126)
			)) {
	    tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec2[j]); 
	   } else if (i == 30 + k && ( (j>=2 && j<4) || (j>=6 && j<8) || (j>=10 && j<12) || (j>=14 && j<16) || (j>=18 && j<20) || (j>=22 && j<24) || (j>=26 && j<28)
			|| (j>=30 && j<32) || (j>=34 && j<36) || (j>=38 && j<40) || (j>=42 && j<44) || (j>=46 && j<48) || (j>=50 && j<52) 
			|| (j>=54 && j<56) || (j>=58 && j<60) || (j>=62 && j<64) || (j>=66 && j<68) || (j>=70 && j<72) || (j>=74 && j<76) 
			|| (j>=78 && j<80) || (j>=82 && j<84) || (j>=86 && j<88) || (j>=90 && j<92) || (j>=94 && j<96)
                        || (j>=98 && j<100) || (j>=102 && j<104) || (j>=106 && j<108) || (j>=110 && j<112) || (j>=114 && j<116) 
			|| (j>=118 && j<120) || (j>=122 && j<124) || (j>=126 && j<128) )) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec2[j]); 

	   } else if (i == 31 + k && j % 2 == 0) {
	   
	    tmp_neg = Cudd_Not(var); 
	    tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec2[j]); 
	   
	   } else if (i == 31 + k && j % 2 == 1) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec2[j]); 

	   }
	  
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd_rec2[j]);
      bdd_rec2[j] = tmp;
    }
  }
    
    
    bdd5 = Cudd_bddOr(gbm,bdd_rec2[0],bdd_rec2[1]); 
    Cudd_Ref(bdd5);   
    
    for (k = 2;k<128;k++) {
    bdd5 = Cudd_bddOr(gbm,bdd5,bdd_rec2[k]);
    Cudd_Ref(bdd5);   
     }
 
    bdd6 = Cudd_bddOr(gbm,bdd4,bdd5);
 
    bdd = Cudd_bddAnd(gbm, bdd,bdd6);
 

	 

     for(j = 0;j<128;j++){ 
       for (i = 32; i < 40; i++) {
          var = Cudd_bddIthVar(gbm,i); 
          if(i%8 ==  0) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec3[j]); 
	  }
	  else if(i == 33+k && j < 64 ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec3[j]); 
          }else if(i == 33+k && j >= 64) {
	  tmp = Cudd_bddAnd(gbm, var, bdd_rec3[j]); 
          }
	  else if ( (i == 34 + k) && ( ( j < 32 ) || ( j >= 64 && j < 96 ) ) ) {
          tmp_neg = Cudd_Not(var);
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec3[j]); 
          } else if ( i == 34 + k && ( ( j >= 32 && j < 64 ) || ( j >= 96 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec3[j]); 
	  } else if (i == 35 + k && ( (j<16) || (j>=32 && j<48) || (j>=64 && j<80) || (j>=96 && j<112) ) ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec3[j]); 
	  } else if (i == 35 + k && ( (j >= 16 && j < 32) || ( j >= 48 && j < 64 ) || ( j >= 80 && j < 96 ) || ( j >= 112 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec3[j]); 
          } else if ( i == 36 + k && ( ( j < 8 ) || ( j >= 16 && j < 24) || (j >= 32 && j < 40) || (j>=48 && j<56) || ( j >= 64 && j < 72 ) || 
		    (j >= 80 && j < 88) || (j >= 96 && j < 104) || (j>=112 && j<120) ) ) {
	   tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec3[j]); 
           } else if (i == 36 + k && ( ( j >= 8 && j < 16 ) || ( j >= 24 && j < 32 ) || ( j >= 40 && j < 48) || ( j >= 56 && j < 64) 
			|| (j>72 && j<=80) || (j>=88 && j<96) || (j>=104 && j<112) || (j>=120) ) ) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec3[j]);  
 	   } else if (i == 37 + k && ( (j < 4) || (j >= 8 && j < 12) || (j >= 16 && j < 20) || (j >= 24 && j < 28) || (j >= 32 && j < 36) || (j >= 40 && j < 44)
			|| (j >= 48 && j < 52)  || (j >= 56 && j < 60)|| (j >= 64 && j < 68) || (j >= 72 && j < 76) || (j >= 80 && j < 84) || (j >= 88 && j < 92) 	
			|| (j >= 96 && j < 100) || (j >= 104 && j < 108) || (j >= 112 && j < 116) || (j >= 120 && j < 124))) {
	   tmp_neg = Cudd_Not(var);
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec3[j]); 
	   
	   } else if (i == 37 + k && ( (j>=4 && j<8) || ( j >= 12 && j < 16 ) || ( j >= 20 && j < 24 ) || ( j >= 28 && j < 32 ) || ( j >= 36 && j < 40 ) 
			|| ( j >= 44 && j < 48 ) || ( j >= 52 && j < 56 ) || ( j >= 60 && j < 64 ) || ( j >= 68 && j < 72 ) || ( j >= 76 && j < 80 ) 	  
		        || ( j >= 84 && j < 88 ) || ( j >= 92 && j < 96 ) || ( j >= 100 && j < 104 ) || ( j >= 108 && j < 112 ) 
			|| ( j >= 116 && j < 120  ) 	|| ( j >= 124 && j < 128 ))) {
          
		   tmp = Cudd_bddAnd(gbm,var,bdd_rec3[j]); 
           } else if ( i == 38 + k && ( (j<2) || (j>=4 && j<6)  || (j>=8 && j<10) || (j>=12 && j<14) || (j>=16 && j<18) || (j>=20 && j<22) || (j>=24 && j<26)
			|| (j>=28 && j<30) || (j>=32 && j<34) || (j>=36 && j<38) || (j>=40 && j<42) || (j>=44 && j<46) || (j>=48 && j<50) || (j>=52 && j<54) 	  
			|| (j>=56 && j<58) || (j>=60 && j<62) || (j>=64 && j<66) || (j>=68 && j<70) || (j>=72 && j<74) || (j>=76 && j<78) || (j>=80 && j<82) 
                	|| (j>=84 && j<86) || (j>=88 && j<90) || (j>=92 && j<94) || (j>=96 && j<98) || (j>=100 && j<102) || (j>=104 && j<106) || (j>=108 && j<110) || 
                	(j>=112 && j<114) || (j>=116 && j<118)     || (j>=120 && j<122) || (j>=124 && j<126)
			)) {
	    tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec3[j]); 
	   } else if (i == 38 + k && ( (j>=2 && j<4) || (j>=6 && j<8) || (j>=10 && j<12) || (j>=14 && j<16) || (j>=18 && j<20) || (j>=22 && j<24) || (j>=26 && j<28)
			|| (j>=30 && j<32) || (j>=34 && j<36) || (j>=38 && j<40) || (j>=42 && j<44) || (j>=46 && j<48) || (j>=50 && j<52) 
			|| (j>=54 && j<56) || (j>=58 && j<60) || (j>=62 && j<64) || (j>=66 && j<68) || (j>=70 && j<72) || (j>=74 && j<76) 
			|| (j>=78 && j<80) || (j>=82 && j<84) || (j>=86 && j<88) || (j>=90 && j<92) || (j>=94 && j<96)
                        || (j>=98 && j<100) || (j>=102 && j<104) || (j>=106 && j<108) || (j>=110 && j<112) || (j>=114 && j<116) 
			|| (j>=118 && j<120) || (j>=122 && j<124) || (j>=126 && j<128) )) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec3[j]); 

	   } else if (i == 39 + k && j % 2 == 0) {
	   
	    tmp_neg = Cudd_Not(var); 
	    tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec3[j]); 
	   
	   } else if (i == 39 + k && j % 2 == 1) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec3[j]); 

	   }
	  
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd_rec3[j]);
      bdd_rec3[j] = tmp;
    }
  }
    
    bdd7 = Cudd_bddOr(gbm,bdd_rec3[0],bdd_rec3[1]); 
    Cudd_Ref(bdd7);   
    
    for (k = 2;k<128;k++) {
    bdd7 = Cudd_bddOr(gbm,bdd7,bdd_rec3[k]);
    Cudd_Ref(bdd7);   
     }

     for(j = 0;j<128;j++){ 
       for (i = 32; i < 40; i++) {
          var = Cudd_bddIthVar(gbm,i); 
          if(i%8 ==  0) {
         // tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, var, bdd_rec4[j]); 
	  }
	  else if(i == 33+k && j < 64 ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec4[j]); 
          }else if(i == 33+k && j >= 64) {
	  tmp = Cudd_bddAnd(gbm, var, bdd_rec4[j]); 
          }
	  else if ( (i == 34 + k) && ( ( j < 32 ) || ( j >= 64 && j < 96 ) ) ) {
          tmp_neg = Cudd_Not(var);
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec4[j]); 
          } else if ( i == 34 + k && ( ( j >= 32 && j < 64 ) || ( j >= 96 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec4[j]); 
	  } else if (i == 35 + k && ( (j<16) || (j>=32 && j<48) || (j>=64 && j<80) || (j>=96 && j<112) ) ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec4[j]); 
	  } else if (i == 35 + k && ( (j >= 16 && j < 32) || ( j >= 48 && j < 64 ) || ( j >= 80 && j < 96 ) || ( j >= 112 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec4[j]); 
          } else if ( i == 36 + k && ( ( j < 8 ) || ( j >= 16 && j < 24) || (j >= 32 && j < 40) || (j>=48 && j<56) || ( j >= 64 && j < 72 ) || 
		    (j >= 80 && j < 88) || (j >= 96 && j < 104) || (j>=112 && j<120) ) ) {
	   tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec4[j]); 
           } else if (i == 36 + k && ( ( j >= 8 && j < 16 ) || ( j >= 24 && j < 32 ) || ( j >= 40 && j < 48) || ( j >= 56 && j < 64) 
			|| (j>72 && j<=80) || (j>=88 && j<96) || (j>=104 && j<112) || (j>=120) ) ) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec4[j]);  
 	   } else if (i == 37 + k && ( (j < 4) || (j >= 8 && j < 12) || (j >= 16 && j < 20) || (j >= 24 && j < 28) || (j >= 32 && j < 36) || (j >= 40 && j < 44)
			|| (j >= 48 && j < 52)  || (j >= 56 && j < 60)|| (j >= 64 && j < 68) || (j >= 72 && j < 76) || (j >= 80 && j < 84) || (j >= 88 && j < 92) 	
			|| (j >= 96 && j < 100) || (j >= 104 && j < 108) || (j >= 112 && j < 116) || (j >= 120 && j < 124))) {
	   tmp_neg = Cudd_Not(var);
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec4[j]); 
	   
	   } else if (i == 37 + k && ( (j>=4 && j<8) || ( j >= 12 && j < 16 ) || ( j >= 20 && j < 24 ) || ( j >= 28 && j < 32 ) || ( j >= 36 && j < 40 ) 
			|| ( j >= 44 && j < 48 ) || ( j >= 52 && j < 56 ) || ( j >= 60 && j < 64 ) || ( j >= 68 && j < 72 ) || ( j >= 76 && j < 80 ) 	  
		        || ( j >= 84 && j < 88 ) || ( j >= 92 && j < 96 ) || ( j >= 100 && j < 104 ) || ( j >= 108 && j < 112 ) 
			|| ( j >= 116 && j < 120  ) 	|| ( j >= 124 && j < 128 ))) {
          
		   tmp = Cudd_bddAnd(gbm,var,bdd_rec4[j]); 
           } else if ( i == 38 + k && ( (j<2) || (j>=4 && j<6)  || (j>=8 && j<10) || (j>=12 && j<14) || (j>=16 && j<18) || (j>=20 && j<22) || (j>=24 && j<26)
			|| (j>=28 && j<30) || (j>=32 && j<34) || (j>=36 && j<38) || (j>=40 && j<42) || (j>=44 && j<46) || (j>=48 && j<50) || (j>=52 && j<54) 	  
			|| (j>=56 && j<58) || (j>=60 && j<62) || (j>=64 && j<66) || (j>=68 && j<70) || (j>=72 && j<74) || (j>=76 && j<78) || (j>=80 && j<82) 
                	|| (j>=84 && j<86) || (j>=88 && j<90) || (j>=92 && j<94) || (j>=96 && j<98) || (j>=100 && j<102) || (j>=104 && j<106) || (j>=108 && j<110) || 
                	(j>=112 && j<114) || (j>=116 && j<118)     || (j>=120 && j<122) || (j>=124 && j<126)
			)) {
	    tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec4[j]); 
	   } else if (i == 38 + k && ( (j>=2 && j<4) || (j>=6 && j<8) || (j>=10 && j<12) || (j>=14 && j<16) || (j>=18 && j<20) || (j>=22 && j<24) || (j>=26 && j<28)
			|| (j>=30 && j<32) || (j>=34 && j<36) || (j>=38 && j<40) || (j>=42 && j<44) || (j>=46 && j<48) || (j>=50 && j<52) 
			|| (j>=54 && j<56) || (j>=58 && j<60) || (j>=62 && j<64) || (j>=66 && j<68) || (j>=70 && j<72) || (j>=74 && j<76) 
			|| (j>=78 && j<80) || (j>=82 && j<84) || (j>=86 && j<88) || (j>=90 && j<92) || (j>=94 && j<96)
                        || (j>=98 && j<100) || (j>=102 && j<104) || (j>=106 && j<108) || (j>=110 && j<112) || (j>=114 && j<116) 
			|| (j>=118 && j<120) || (j>=122 && j<124) || (j>=126 && j<128) )) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec4[j]); 

	   } else if (i == 39 + k && j % 2 == 0) {
	   
	    tmp_neg = Cudd_Not(var); 
	    tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec4[j]); 
	   
	   } else if (i == 39 + k && j % 2 == 1) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec4[j]); 

	   }
	  
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd_rec4[j]);
      bdd_rec4[j] = tmp;
    }
  }
    
    
    bdd8 = Cudd_bddOr(gbm,bdd_rec4[0],bdd_rec4[1]); 
    Cudd_Ref(bdd8);   
    
    for (k = 2;k<128;k++) {
    bdd8 = Cudd_bddOr(gbm,bdd8,bdd_rec4[k]);
    Cudd_Ref(bdd8);   
     }
 
    bdd9 = Cudd_bddOr(gbm,bdd7,bdd8);
    bdd = Cudd_bddAnd(gbm,bdd,bdd9);
    */
    DdNode* bdd71;
   
    bdd71 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd71); /*Increases the reference count of a node*/

     for (i = 16; i < 18; i++) {  
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd71); 
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd71);
      bdd71 = tmp;
    }
    
    
    bdd = Cudd_bddAnd(gbm,bdd,bdd71);
    Cudd_Ref(bdd);

    return bdd;




}	



DdNode* scrivi_bdd_due13 (DdManager *gbm, DdNode *bdd, DdNode * var) {
     DdNode* bdd_rec[128];
     DdNode* bdd_rec2[128];
     DdNode* bdd_rec3[128];
     DdNode* bdd_rec4[128];

     DdNode *bdd1, *bdd2, *bdd3, *bdd4, *bdd5, *bdd6, *bdd7, *bdd8, *bdd9,*tmp,*tmp_neg;
     bdd = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd); /*Increases the reference count of a node*/
     int i; 
     
     for(i = 0; i < 128; i++){
     bdd_rec[i] = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd_rec[i]); /*Increases the reference count of a node*/
     } 
     for(i = 0; i < 128; i++){
     bdd_rec2[i] = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd_rec2[i]); /*Increases the reference count of a node*/
     } 
     for(i = 0; i < 128; i++){
     bdd_rec3[i] = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd_rec3[i]); /*Increases the reference count of a node*/
     } 
     for(i = 0; i < 128; i++){
     bdd_rec4[i] = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd_rec4[i]); /*Increases the reference count of a node*/
     } 
     
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
     bdd6 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd6); /*Increases the reference count of a node*/
     bdd7 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd7); /*Increases the reference count of a node*/
     bdd8 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd8); /*Increases the reference count of a node*/
   
     
     for (i = 0; i < 8; i++) {
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
     if(i != 0 && i != 3) {
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

int j;int k = 0;
     for(j = 0;j<128;j++){ 
       for (i = 8; i < 16; i++) {
          var = Cudd_bddIthVar(gbm,i); 
          if(i%8 ==  0) {
          //tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, var, bdd_rec[j]); 
	  }
	  else if(i == 9+k && j < 64 ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
          }else if(i == 9+k && j >= 64) {
	  tmp = Cudd_bddAnd(gbm, var, bdd_rec[j]); 
          }
	  else if ( (i == 10 + k) && ( ( j < 32 ) || ( j >= 64 && j < 96 ) ) ) {
          tmp_neg = Cudd_Not(var);
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
          } else if ( i == 10 + k && ( ( j >= 32 && j < 64 ) || ( j >= 96 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
	  } else if (i == 11 + k && ( (j<16) || (j>=32 && j<48) || (j>=64 && j<80) || (j>=96 && j<112) ) ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	  } else if (i == 11 + k && ( (j >= 16 && j < 32) || ( j >= 48 && j < 64 ) || ( j >= 80 && j < 96 ) || ( j >= 112 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
          } else if ( i == 12 + k && ( ( j < 8 ) || ( j >= 16 && j < 24) || (j >= 32 && j < 40) || (j>=48 && j<56) || ( j >= 64 && j < 72 ) || 
		    (j >= 80 && j < 88) || (j >= 96 && j < 104) || (j>=112 && j<120) ) ) {
	   tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
           } else if (i == 12 + k && ( ( j >= 8 && j < 16 ) || ( j >= 24 && j < 32 ) || ( j >= 40 && j < 48) || ( j >= 56 && j < 64) 
			|| (j>72 && j<=80) || (j>=88 && j<96) || (j>=104 && j<112) || (j>=120) ) ) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]);  
 	   } else if (i == 13 + k && ( (j < 4) || (j >= 8 && j < 12) || (j >= 16 && j < 20) || (j >= 24 && j < 28) || (j >= 32 && j < 36) || (j >= 40 && j < 44)
			|| (j >= 48 && j < 52)  || (j >= 56 && j < 60)|| (j >= 64 && j < 68) || (j >= 72 && j < 76) || (j >= 80 && j < 84) || (j >= 88 && j < 92) 	
			|| (j >= 96 && j < 100) || (j >= 104 && j < 108) || (j >= 112 && j < 116) || (j >= 120 && j < 124))) {
	   tmp_neg = Cudd_Not(var);
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   
	   } else if (i == 13 + k && ( (j>=4 && j<8) || ( j >= 12 && j < 16 ) || ( j >= 20 && j < 24 ) || ( j >= 28 && j < 32 ) || ( j >= 36 && j < 40 ) 
			|| ( j >= 44 && j < 48 ) || ( j >= 52 && j < 56 ) || ( j >= 60 && j < 64 ) || ( j >= 68 && j < 72 ) || ( j >= 76 && j < 80 ) 	  
		        || ( j >= 84 && j < 88 ) || ( j >= 92 && j < 96 ) || ( j >= 100 && j < 104 ) || ( j >= 108 && j < 112 ) 
			|| ( j >= 116 && j < 120  ) 	|| ( j >= 124 && j < 128 ))) {
          
		   tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
           } else if ( i == 14 + k && ( (j<2) || (j>=4 && j<6)  || (j>=8 && j<10) || (j>=12 && j<14) || (j>=16 && j<18) || (j>=20 && j<22) || (j>=24 && j<26)
			|| (j>=28 && j<30) || (j>=32 && j<34) || (j>=36 && j<38) || (j>=40 && j<42) || (j>=44 && j<46) || (j>=48 && j<50) || (j>=52 && j<54) 	  
			|| (j>=56 && j<58) || (j>=60 && j<62) || (j>=64 && j<66) || (j>=68 && j<70) || (j>=72 && j<74) || (j>=76 && j<78) || (j>=80 && j<82) 
                	|| (j>=84 && j<86) || (j>=88 && j<90) || (j>=92 && j<94) || (j>=96 && j<98) || (j>=100 && j<102) || (j>=104 && j<106) || (j>=108 && j<110) || 
                	(j>=112 && j<114) || (j>=116 && j<118)     || (j>=120 && j<122) || (j>=124 && j<126)
			)) {
	    tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   } else if (i == 14 + k && ( (j>=2 && j<4) || (j>=6 && j<8) || (j>=10 && j<12) || (j>=14 && j<16) || (j>=18 && j<20) || (j>=22 && j<24) || (j>=26 && j<28)
			|| (j>=30 && j<32) || (j>=34 && j<36) || (j>=38 && j<40) || (j>=42 && j<44) || (j>=46 && j<48) || (j>=50 && j<52) 
			|| (j>=54 && j<56) || (j>=58 && j<60) || (j>=62 && j<64) || (j>=66 && j<68) || (j>=70 && j<72) || (j>=74 && j<76) 
			|| (j>=78 && j<80) || (j>=82 && j<84) || (j>=86 && j<88) || (j>=90 && j<92) || (j>=94 && j<96)
                        || (j>=98 && j<100) || (j>=102 && j<104) || (j>=106 && j<108) || (j>=110 && j<112) || (j>=114 && j<116) 
			|| (j>=118 && j<120) || (j>=122 && j<124) || (j>=126 && j<128) )) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 

	   } else if (i == 15 + k && j % 2 == 0) {
	   
	    tmp_neg = Cudd_Not(var); 
	    tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   
	   } else if (i == 15 + k && j % 2 == 1) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 

	   }
	  
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd_rec[j]);
      bdd_rec[j] = tmp;
    }
  }
    
    bdd1 = Cudd_bddOr(gbm,bdd_rec[0],bdd_rec[1]); 
    Cudd_Ref(bdd1);   
    
    for (k = 2;k<128;k++) {
    bdd1 = Cudd_bddOr(gbm,bdd1,bdd_rec[k]);
    Cudd_Ref(bdd1);   
     }

    bdd = Cudd_bddAnd(gbm,bdd,bdd1);
    Cudd_Ref(bdd);   
/*
     for(j = 0;j<128;j++){ 
       for (i = 16; i < 24; i++) {
          var = Cudd_bddIthVar(gbm,i); 
          if(i%8 ==  0) {
          //tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, var, bdd_rec[j]); 
	  }
	  else if(i == 17+k && j < 64 ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
          }else if(i == 17+k && j >= 64) {
	  tmp = Cudd_bddAnd(gbm, var, bdd_rec[j]); 
          }
	  else if ( (i == 18 + k) && ( ( j < 32 ) || ( j >= 64 && j < 96 ) ) ) {
          tmp_neg = Cudd_Not(var);
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
          } else if ( i == 18 + k && ( ( j >= 32 && j < 64 ) || ( j >= 96 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
	  } else if (i == 19 + k && ( (j<16) || (j>=32 && j<48) || (j>=64 && j<80) || (j>=96 && j<112) ) ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	  } else if (i == 19 + k && ( (j >= 16 && j < 32) || ( j >= 48 && j < 64 ) || ( j >= 80 && j < 96 ) || ( j >= 112 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
          } else if ( i == 20 + k && ( ( j < 8 ) || ( j >= 16 && j < 24) || (j >= 32 && j < 40) || (j>=48 && j<56) || ( j >= 64 && j < 72 ) || 
		    (j >= 80 && j < 88) || (j >= 96 && j < 104) || (j>=112 && j<120) ) ) {
	   tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
           } else if (i == 20 + k && ( ( j >= 8 && j < 16 ) || ( j >= 24 && j < 32 ) || ( j >= 40 && j < 48) || ( j >= 56 && j < 64) 
			|| (j>72 && j<=80) || (j>=88 && j<96) || (j>=104 && j<112) || (j>=120) ) ) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]);  
 	   } else if (i == 21 + k && ( (j < 4) || (j >= 8 && j < 12) || (j >= 16 && j < 20) || (j >= 24 && j < 28) || (j >= 32 && j < 36) || (j >= 40 && j < 44)
			|| (j >= 48 && j < 52)  || (j >= 56 && j < 60)|| (j >= 64 && j < 68) || (j >= 72 && j < 76) || (j >= 80 && j < 84) || (j >= 88 && j < 92) 	
			|| (j >= 96 && j < 100) || (j >= 104 && j < 108) || (j >= 112 && j < 116) || (j >= 120 && j < 124))) {
	   tmp_neg = Cudd_Not(var);
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   
	   } else if (i == 21 + k && ( (j>=4 && j<8) || ( j >= 12 && j < 16 ) || ( j >= 20 && j < 24 ) || ( j >= 28 && j < 32 ) || ( j >= 36 && j < 40 ) 
			|| ( j >= 44 && j < 48 ) || ( j >= 52 && j < 56 ) || ( j >= 60 && j < 64 ) || ( j >= 68 && j < 72 ) || ( j >= 76 && j < 80 ) 	  
		        || ( j >= 84 && j < 88 ) || ( j >= 92 && j < 96 ) || ( j >= 100 && j < 104 ) || ( j >= 108 && j < 112 ) 
			|| ( j >= 116 && j < 120  ) 	|| ( j >= 124 && j < 128 ))) {
          
		   tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
           } else if ( i == 22 + k && ( (j<2) || (j>=4 && j<6)  || (j>=8 && j<10) || (j>=12 && j<14) || (j>=16 && j<18) || (j>=20 && j<22) || (j>=24 && j<26)
			|| (j>=28 && j<30) || (j>=32 && j<34) || (j>=36 && j<38) || (j>=40 && j<42) || (j>=44 && j<46) || (j>=48 && j<50) || (j>=52 && j<54) 	  
			|| (j>=56 && j<58) || (j>=60 && j<62) || (j>=64 && j<66) || (j>=68 && j<70) || (j>=72 && j<74) || (j>=76 && j<78) || (j>=80 && j<82) 
                	|| (j>=84 && j<86) || (j>=88 && j<90) || (j>=92 && j<94) || (j>=96 && j<98) || (j>=100 && j<102) || (j>=104 && j<106) || (j>=108 && j<110) || 
                	(j>=112 && j<114) || (j>=116 && j<118)     || (j>=120 && j<122) || (j>=124 && j<126)
			)) {
	    tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   } else if (i == 22 + k && ( (j>=2 && j<4) || (j>=6 && j<8) || (j>=10 && j<12) || (j>=14 && j<16) || (j>=18 && j<20) || (j>=22 && j<24) || (j>=26 && j<28)
			|| (j>=30 && j<32) || (j>=34 && j<36) || (j>=38 && j<40) || (j>=42 && j<44) || (j>=46 && j<48) || (j>=50 && j<52) 
			|| (j>=54 && j<56) || (j>=58 && j<60) || (j>=62 && j<64) || (j>=66 && j<68) || (j>=70 && j<72) || (j>=74 && j<76) 
			|| (j>=78 && j<80) || (j>=82 && j<84) || (j>=86 && j<88) || (j>=90 && j<92) || (j>=94 && j<96)
                        || (j>=98 && j<100) || (j>=102 && j<104) || (j>=106 && j<108) || (j>=110 && j<112) || (j>=114 && j<116) 
			|| (j>=118 && j<120) || (j>=122 && j<124) || (j>=126 && j<128) )) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 

	   } else if (i == 23 + k && j % 2 == 0) {
	   
	    tmp_neg = Cudd_Not(var); 
	    tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   
	   } else if (i == 23 + k && j % 2 == 1) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 

	   }
	  
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd_rec[j]);
      bdd_rec[j] = tmp;
    }
  }
    
    bdd2 = Cudd_bddOr(gbm,bdd_rec[0],bdd_rec[1]); 
    Cudd_Ref(bdd2);   
    
    for (k = 2;k<128;k++) {
    bdd2 = Cudd_bddOr(gbm,bdd2,bdd_rec[k]);
    Cudd_Ref(bdd2);   
     }

    bdd = Cudd_bddAnd(gbm,bdd,bdd2);
    Cudd_Ref(bdd);   
   
     for(j = 0;j<128;j++){ 
       for (i = 24; i < 32; i++) {
          var = Cudd_bddIthVar(gbm,i); 
          if(i%8 ==  0) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	  }
	  else if(i == 25+k && j < 64 ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
          }else if(i == 25+k && j >= 64) {
	  tmp = Cudd_bddAnd(gbm, var, bdd_rec[j]); 
          }
	  else if ( (i == 26 + k) && ( ( j < 32 ) || ( j >= 64 && j < 96 ) ) ) {
          tmp_neg = Cudd_Not(var);
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
          } else if ( i == 26 + k && ( ( j >= 32 && j < 64 ) || ( j >= 96 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
	  } else if (i == 27 + k && ( (j<16) || (j>=32 && j<48) || (j>=64 && j<80) || (j>=96 && j<112) ) ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	  } else if (i == 27 + k && ( (j >= 16 && j < 32) || ( j >= 48 && j < 64 ) || ( j >= 80 && j < 96 ) || ( j >= 112 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
          } else if ( i == 28 + k && ( ( j < 8 ) || ( j >= 16 && j < 24) || (j >= 32 && j < 40) || (j>=48 && j<56) || ( j >= 64 && j < 72 ) || 
		    (j >= 80 && j < 88) || (j >= 96 && j < 104) || (j>=112 && j<120) ) ) {
	   tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
           } else if (i == 28 + k && ( ( j >= 8 && j < 16 ) || ( j >= 24 && j < 32 ) || ( j >= 40 && j < 48) || ( j >= 56 && j < 64) 
			|| (j>72 && j<=80) || (j>=88 && j<96) || (j>=104 && j<112) || (j>=120) ) ) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]);  
 	   } else if (i == 29 + k && ( (j < 4) || (j >= 8 && j < 12) || (j >= 16 && j < 20) || (j >= 24 && j < 28) || (j >= 32 && j < 36) || (j >= 40 && j < 44)
			|| (j >= 48 && j < 52)  || (j >= 56 && j < 60)|| (j >= 64 && j < 68) || (j >= 72 && j < 76) || (j >= 80 && j < 84) || (j >= 88 && j < 92) 	
			|| (j >= 96 && j < 100) || (j >= 104 && j < 108) || (j >= 112 && j < 116) || (j >= 120 && j < 124))) {
	   tmp_neg = Cudd_Not(var);
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   
	   } else if (i == 29 + k && ( (j>=4 && j<8) || ( j >= 12 && j < 16 ) || ( j >= 20 && j < 24 ) || ( j >= 28 && j < 32 ) || ( j >= 36 && j < 40 ) 
			|| ( j >= 44 && j < 48 ) || ( j >= 52 && j < 56 ) || ( j >= 60 && j < 64 ) || ( j >= 68 && j < 72 ) || ( j >= 76 && j < 80 ) 	  
		        || ( j >= 84 && j < 88 ) || ( j >= 92 && j < 96 ) || ( j >= 100 && j < 104 ) || ( j >= 108 && j < 112 ) 
			|| ( j >= 116 && j < 120  ) 	|| ( j >= 124 && j < 128 ))) {
          
		   tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
           } else if ( i == 30 + k && ( (j<2) || (j>=4 && j<6)  || (j>=8 && j<10) || (j>=12 && j<14) || (j>=16 && j<18) || (j>=20 && j<22) || (j>=24 && j<26)
			|| (j>=28 && j<30) || (j>=32 && j<34) || (j>=36 && j<38) || (j>=40 && j<42) || (j>=44 && j<46) || (j>=48 && j<50) || (j>=52 && j<54) 	  
			|| (j>=56 && j<58) || (j>=60 && j<62) || (j>=64 && j<66) || (j>=68 && j<70) || (j>=72 && j<74) || (j>=76 && j<78) || (j>=80 && j<82) 
                	|| (j>=84 && j<86) || (j>=88 && j<90) || (j>=92 && j<94) || (j>=96 && j<98) || (j>=100 && j<102) || (j>=104 && j<106) || (j>=108 && j<110) || 
                	(j>=112 && j<114) || (j>=116 && j<118)     || (j>=120 && j<122) || (j>=124 && j<126)
			)) {
	    tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   } else if (i == 30 + k && ( (j>=2 && j<4) || (j>=6 && j<8) || (j>=10 && j<12) || (j>=14 && j<16) || (j>=18 && j<20) || (j>=22 && j<24) || (j>=26 && j<28)
			|| (j>=30 && j<32) || (j>=34 && j<36) || (j>=38 && j<40) || (j>=42 && j<44) || (j>=46 && j<48) || (j>=50 && j<52) 
			|| (j>=54 && j<56) || (j>=58 && j<60) || (j>=62 && j<64) || (j>=66 && j<68) || (j>=70 && j<72) || (j>=74 && j<76) 
			|| (j>=78 && j<80) || (j>=82 && j<84) || (j>=86 && j<88) || (j>=90 && j<92) || (j>=94 && j<96)
                        || (j>=98 && j<100) || (j>=102 && j<104) || (j>=106 && j<108) || (j>=110 && j<112) || (j>=114 && j<116) 
			|| (j>=118 && j<120) || (j>=122 && j<124) || (j>=126 && j<128) )) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 

	   } else if (i == 31 + k && j % 2 == 0) {
	   
	    tmp_neg = Cudd_Not(var); 
	    tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   
	   } else if (i == 31 + k && j % 2 == 1) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 

	   }
	  
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd_rec[j]);
      bdd_rec[j] = tmp;
    }
  }
    
    bdd3 = Cudd_bddOr(gbm,bdd_rec[0],bdd_rec[1]); 
    Cudd_Ref(bdd3);   
    
    for (k = 2;k<128;k++) {
    bdd3 = Cudd_bddOr(gbm,bdd3,bdd_rec[k]);
    Cudd_Ref(bdd3);   
     }

    bdd = Cudd_bddAnd(gbm,bdd,bdd3);
    Cudd_Ref(bdd);   
   

	 

     for(j = 0;j<128;j++){ 
       for (i = 32; i < 40; i++) {
          var = Cudd_bddIthVar(gbm,i); 
          if(i%8 ==  0) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec3[j]); 
	  }
	  else if(i == 33+k && j < 64 ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec3[j]); 
          }else if(i == 33+k && j >= 64) {
	  tmp = Cudd_bddAnd(gbm, var, bdd_rec3[j]); 
          }
	  else if ( (i == 34 + k) && ( ( j < 32 ) || ( j >= 64 && j < 96 ) ) ) {
          tmp_neg = Cudd_Not(var);
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec3[j]); 
          } else if ( i == 34 + k && ( ( j >= 32 && j < 64 ) || ( j >= 96 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec3[j]); 
	  } else if (i == 35 + k && ( (j<16) || (j>=32 && j<48) || (j>=64 && j<80) || (j>=96 && j<112) ) ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec3[j]); 
	  } else if (i == 35 + k && ( (j >= 16 && j < 32) || ( j >= 48 && j < 64 ) || ( j >= 80 && j < 96 ) || ( j >= 112 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec3[j]); 
          } else if ( i == 36 + k && ( ( j < 8 ) || ( j >= 16 && j < 24) || (j >= 32 && j < 40) || (j>=48 && j<56) || ( j >= 64 && j < 72 ) || 
		    (j >= 80 && j < 88) || (j >= 96 && j < 104) || (j>=112 && j<120) ) ) {
	   tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec3[j]); 
           } else if (i == 36 + k && ( ( j >= 8 && j < 16 ) || ( j >= 24 && j < 32 ) || ( j >= 40 && j < 48) || ( j >= 56 && j < 64) 
			|| (j>72 && j<=80) || (j>=88 && j<96) || (j>=104 && j<112) || (j>=120) ) ) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec3[j]);  
 	   } else if (i == 37 + k && ( (j < 4) || (j >= 8 && j < 12) || (j >= 16 && j < 20) || (j >= 24 && j < 28) || (j >= 32 && j < 36) || (j >= 40 && j < 44)
			|| (j >= 48 && j < 52)  || (j >= 56 && j < 60)|| (j >= 64 && j < 68) || (j >= 72 && j < 76) || (j >= 80 && j < 84) || (j >= 88 && j < 92) 	
			|| (j >= 96 && j < 100) || (j >= 104 && j < 108) || (j >= 112 && j < 116) || (j >= 120 && j < 124))) {
	   tmp_neg = Cudd_Not(var);
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec3[j]); 
	   
	   } else if (i == 37 + k && ( (j>=4 && j<8) || ( j >= 12 && j < 16 ) || ( j >= 20 && j < 24 ) || ( j >= 28 && j < 32 ) || ( j >= 36 && j < 40 ) 
			|| ( j >= 44 && j < 48 ) || ( j >= 52 && j < 56 ) || ( j >= 60 && j < 64 ) || ( j >= 68 && j < 72 ) || ( j >= 76 && j < 80 ) 	  
		        || ( j >= 84 && j < 88 ) || ( j >= 92 && j < 96 ) || ( j >= 100 && j < 104 ) || ( j >= 108 && j < 112 ) 
			|| ( j >= 116 && j < 120  ) 	|| ( j >= 124 && j < 128 ))) {
          
		   tmp = Cudd_bddAnd(gbm,var,bdd_rec3[j]); 
           } else if ( i == 38 + k && ( (j<2) || (j>=4 && j<6)  || (j>=8 && j<10) || (j>=12 && j<14) || (j>=16 && j<18) || (j>=20 && j<22) || (j>=24 && j<26)
			|| (j>=28 && j<30) || (j>=32 && j<34) || (j>=36 && j<38) || (j>=40 && j<42) || (j>=44 && j<46) || (j>=48 && j<50) || (j>=52 && j<54) 	  
			|| (j>=56 && j<58) || (j>=60 && j<62) || (j>=64 && j<66) || (j>=68 && j<70) || (j>=72 && j<74) || (j>=76 && j<78) || (j>=80 && j<82) 
                	|| (j>=84 && j<86) || (j>=88 && j<90) || (j>=92 && j<94) || (j>=96 && j<98) || (j>=100 && j<102) || (j>=104 && j<106) || (j>=108 && j<110) || 
                	(j>=112 && j<114) || (j>=116 && j<118)     || (j>=120 && j<122) || (j>=124 && j<126)
			)) {
	    tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec3[j]); 
	   } else if (i == 38 + k && ( (j>=2 && j<4) || (j>=6 && j<8) || (j>=10 && j<12) || (j>=14 && j<16) || (j>=18 && j<20) || (j>=22 && j<24) || (j>=26 && j<28)
			|| (j>=30 && j<32) || (j>=34 && j<36) || (j>=38 && j<40) || (j>=42 && j<44) || (j>=46 && j<48) || (j>=50 && j<52) 
			|| (j>=54 && j<56) || (j>=58 && j<60) || (j>=62 && j<64) || (j>=66 && j<68) || (j>=70 && j<72) || (j>=74 && j<76) 
			|| (j>=78 && j<80) || (j>=82 && j<84) || (j>=86 && j<88) || (j>=90 && j<92) || (j>=94 && j<96)
                        || (j>=98 && j<100) || (j>=102 && j<104) || (j>=106 && j<108) || (j>=110 && j<112) || (j>=114 && j<116) 
			|| (j>=118 && j<120) || (j>=122 && j<124) || (j>=126 && j<128) )) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec3[j]); 

	   } else if (i == 39 + k && j % 2 == 0) {
	   
	    tmp_neg = Cudd_Not(var); 
	    tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec3[j]); 
	   
	   } else if (i == 39 + k && j % 2 == 1) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec3[j]); 

	   }
	  
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd_rec3[j]);
      bdd_rec3[j] = tmp;
    }
  }
    
    bdd7 = Cudd_bddOr(gbm,bdd_rec3[0],bdd_rec3[1]); 
    Cudd_Ref(bdd7);   
    
    for (k = 2;k<128;k++) {
    bdd7 = Cudd_bddOr(gbm,bdd7,bdd_rec3[k]);
    Cudd_Ref(bdd7);   
     }

     for(j = 0;j<128;j++){ 
       for (i = 32; i < 40; i++) {
          var = Cudd_bddIthVar(gbm,i); 
          if(i%8 ==  0) {
         // tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, var, bdd_rec4[j]); 
	  }
	  else if(i == 33+k && j < 64 ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec4[j]); 
          }else if(i == 33+k && j >= 64) {
	  tmp = Cudd_bddAnd(gbm, var, bdd_rec4[j]); 
          }
	  else if ( (i == 34 + k) && ( ( j < 32 ) || ( j >= 64 && j < 96 ) ) ) {
          tmp_neg = Cudd_Not(var);
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec4[j]); 
          } else if ( i == 34 + k && ( ( j >= 32 && j < 64 ) || ( j >= 96 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec4[j]); 
	  } else if (i == 35 + k && ( (j<16) || (j>=32 && j<48) || (j>=64 && j<80) || (j>=96 && j<112) ) ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec4[j]); 
	  } else if (i == 35 + k && ( (j >= 16 && j < 32) || ( j >= 48 && j < 64 ) || ( j >= 80 && j < 96 ) || ( j >= 112 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec4[j]); 
          } else if ( i == 36 + k && ( ( j < 8 ) || ( j >= 16 && j < 24) || (j >= 32 && j < 40) || (j>=48 && j<56) || ( j >= 64 && j < 72 ) || 
		    (j >= 80 && j < 88) || (j >= 96 && j < 104) || (j>=112 && j<120) ) ) {
	   tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec4[j]); 
           } else if (i == 36 + k && ( ( j >= 8 && j < 16 ) || ( j >= 24 && j < 32 ) || ( j >= 40 && j < 48) || ( j >= 56 && j < 64) 
			|| (j>72 && j<=80) || (j>=88 && j<96) || (j>=104 && j<112) || (j>=120) ) ) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec4[j]);  
 	   } else if (i == 37 + k && ( (j < 4) || (j >= 8 && j < 12) || (j >= 16 && j < 20) || (j >= 24 && j < 28) || (j >= 32 && j < 36) || (j >= 40 && j < 44)
			|| (j >= 48 && j < 52)  || (j >= 56 && j < 60)|| (j >= 64 && j < 68) || (j >= 72 && j < 76) || (j >= 80 && j < 84) || (j >= 88 && j < 92) 	
			|| (j >= 96 && j < 100) || (j >= 104 && j < 108) || (j >= 112 && j < 116) || (j >= 120 && j < 124))) {
	   tmp_neg = Cudd_Not(var);
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec4[j]); 
	   
	   } else if (i == 37 + k && ( (j>=4 && j<8) || ( j >= 12 && j < 16 ) || ( j >= 20 && j < 24 ) || ( j >= 28 && j < 32 ) || ( j >= 36 && j < 40 ) 
			|| ( j >= 44 && j < 48 ) || ( j >= 52 && j < 56 ) || ( j >= 60 && j < 64 ) || ( j >= 68 && j < 72 ) || ( j >= 76 && j < 80 ) 	  
		        || ( j >= 84 && j < 88 ) || ( j >= 92 && j < 96 ) || ( j >= 100 && j < 104 ) || ( j >= 108 && j < 112 ) 
			|| ( j >= 116 && j < 120  ) 	|| ( j >= 124 && j < 128 ))) {
          
		   tmp = Cudd_bddAnd(gbm,var,bdd_rec4[j]); 
           } else if ( i == 38 + k && ( (j<2) || (j>=4 && j<6)  || (j>=8 && j<10) || (j>=12 && j<14) || (j>=16 && j<18) || (j>=20 && j<22) || (j>=24 && j<26)
			|| (j>=28 && j<30) || (j>=32 && j<34) || (j>=36 && j<38) || (j>=40 && j<42) || (j>=44 && j<46) || (j>=48 && j<50) || (j>=52 && j<54) 	  
			|| (j>=56 && j<58) || (j>=60 && j<62) || (j>=64 && j<66) || (j>=68 && j<70) || (j>=72 && j<74) || (j>=76 && j<78) || (j>=80 && j<82) 
                	|| (j>=84 && j<86) || (j>=88 && j<90) || (j>=92 && j<94) || (j>=96 && j<98) || (j>=100 && j<102) || (j>=104 && j<106) || (j>=108 && j<110) || 
                	(j>=112 && j<114) || (j>=116 && j<118)     || (j>=120 && j<122) || (j>=124 && j<126)
			)) {
	    tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec4[j]); 
	   } else if (i == 38 + k && ( (j>=2 && j<4) || (j>=6 && j<8) || (j>=10 && j<12) || (j>=14 && j<16) || (j>=18 && j<20) || (j>=22 && j<24) || (j>=26 && j<28)
			|| (j>=30 && j<32) || (j>=34 && j<36) || (j>=38 && j<40) || (j>=42 && j<44) || (j>=46 && j<48) || (j>=50 && j<52) 
			|| (j>=54 && j<56) || (j>=58 && j<60) || (j>=62 && j<64) || (j>=66 && j<68) || (j>=70 && j<72) || (j>=74 && j<76) 
			|| (j>=78 && j<80) || (j>=82 && j<84) || (j>=86 && j<88) || (j>=90 && j<92) || (j>=94 && j<96)
                        || (j>=98 && j<100) || (j>=102 && j<104) || (j>=106 && j<108) || (j>=110 && j<112) || (j>=114 && j<116) 
			|| (j>=118 && j<120) || (j>=122 && j<124) || (j>=126 && j<128) )) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec4[j]); 

	   } else if (i == 39 + k && j % 2 == 0) {
	   
	    tmp_neg = Cudd_Not(var); 
	    tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec4[j]); 
	   
	   } else if (i == 39 + k && j % 2 == 1) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec4[j]); 

	   }
	  
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd_rec4[j]);
      bdd_rec4[j] = tmp;
    }
  }
    
    
    bdd8 = Cudd_bddOr(gbm,bdd_rec4[0],bdd_rec4[1]); 
    Cudd_Ref(bdd8);   
    
    for (k = 2;k<128;k++) {
    bdd8 = Cudd_bddOr(gbm,bdd8,bdd_rec4[k]);
    Cudd_Ref(bdd8);   
     }
 
    bdd9 = Cudd_bddOr(gbm,bdd7,bdd8);
    bdd = Cudd_bddAnd(gbm,bdd,bdd9);
     
    for(j = 0;j<128;j++){ 
       for (i = 40; i < 48; i++) {
          var = Cudd_bddIthVar(gbm,i); 
          if(i%8 ==  0) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	  }
	  else if(i == 41+k && j < 64 ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
          }else if(i == 41+k && j >= 64) {
	  tmp = Cudd_bddAnd(gbm, var, bdd_rec[j]); 
          }
	  else if ( (i == 42 + k) && ( ( j < 32 ) || ( j >= 64 && j < 96 ) ) ) {
          tmp_neg = Cudd_Not(var);
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
          } else if ( i == 42 + k && ( ( j >= 32 && j < 64 ) || ( j >= 96 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
	  } else if (i == 43 + k && ( (j<16) || (j>=32 && j<48) || (j>=64 && j<80) || (j>=96 && j<112) ) ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	  } else if (i == 43 + k && ( (j >= 16 && j < 32) || ( j >= 48 && j < 64 ) || ( j >= 80 && j < 96 ) || ( j >= 112 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
          } else if ( i == 44 + k && ( ( j < 8 ) || ( j >= 16 && j < 24) || (j >= 32 && j < 40) || (j>=48 && j<56) || ( j >= 64 && j < 72 ) || 
		    (j >= 80 && j < 88) || (j >= 96 && j < 104) || (j>=112 && j<120) ) ) {
	   tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
           } else if (i == 44 + k && ( ( j >= 8 && j < 16 ) || ( j >= 24 && j < 32 ) || ( j >= 40 && j < 48) || ( j >= 56 && j < 64) 
			|| (j>72 && j<=80) || (j>=88 && j<96) || (j>=104 && j<112) || (j>=120) ) ) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]);  
 	   } else if (i == 45 + k && ( (j < 4) || (j >= 8 && j < 12) || (j >= 16 && j < 20) || (j >= 24 && j < 28) || (j >= 32 && j < 36) || (j >= 40 && j < 44)
			|| (j >= 48 && j < 52)  || (j >= 56 && j < 60)|| (j >= 64 && j < 68) || (j >= 72 && j < 76) || (j >= 80 && j < 84) || (j >= 88 && j < 92) 	
			|| (j >= 96 && j < 100) || (j >= 104 && j < 108) || (j >= 112 && j < 116) || (j >= 120 && j < 124))) {
	   tmp_neg = Cudd_Not(var);
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   
	   } else if (i == 45 + k && ( (j>=4 && j<8) || ( j >= 12 && j < 16 ) || ( j >= 20 && j < 24 ) || ( j >= 28 && j < 32 ) || ( j >= 36 && j < 40 ) 
			|| ( j >= 44 && j < 48 ) || ( j >= 52 && j < 56 ) || ( j >= 60 && j < 64 ) || ( j >= 68 && j < 72 ) || ( j >= 76 && j < 80 ) 	  
		        || ( j >= 84 && j < 88 ) || ( j >= 92 && j < 96 ) || ( j >= 100 && j < 104 ) || ( j >= 108 && j < 112 ) 
			|| ( j >= 116 && j < 120  ) 	|| ( j >= 124 && j < 128 ))) {
          
		   tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
           } else if ( i == 46 + k && ( (j<2) || (j>=4 && j<6)  || (j>=8 && j<10) || (j>=12 && j<14) || (j>=16 && j<18) || (j>=20 && j<22) || (j>=24 && j<26)
			|| (j>=28 && j<30) || (j>=32 && j<34) || (j>=36 && j<38) || (j>=40 && j<42) || (j>=44 && j<46) || (j>=48 && j<50) || (j>=52 && j<54) 	  
			|| (j>=56 && j<58) || (j>=60 && j<62) || (j>=64 && j<66) || (j>=68 && j<70) || (j>=72 && j<74) || (j>=76 && j<78) || (j>=80 && j<82) 
                	|| (j>=84 && j<86) || (j>=88 && j<90) || (j>=92 && j<94) || (j>=96 && j<98) || (j>=100 && j<102) || (j>=104 && j<106) || (j>=108 && j<110) || 
                	(j>=112 && j<114) || (j>=116 && j<118)     || (j>=120 && j<122) || (j>=124 && j<126)
			)) {
	    tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   } else if (i == 46 + k && ( (j>=2 && j<4) || (j>=6 && j<8) || (j>=10 && j<12) || (j>=14 && j<16) || (j>=18 && j<20) || (j>=22 && j<24) || (j>=26 && j<28)
			|| (j>=30 && j<32) || (j>=34 && j<36) || (j>=38 && j<40) || (j>=42 && j<44) || (j>=46 && j<48) || (j>=50 && j<52) 
			|| (j>=54 && j<56) || (j>=58 && j<60) || (j>=62 && j<64) || (j>=66 && j<68) || (j>=70 && j<72) || (j>=74 && j<76) 
			|| (j>=78 && j<80) || (j>=82 && j<84) || (j>=86 && j<88) || (j>=90 && j<92) || (j>=94 && j<96)
                        || (j>=98 && j<100) || (j>=102 && j<104) || (j>=106 && j<108) || (j>=110 && j<112) || (j>=114 && j<116) 
			|| (j>=118 && j<120) || (j>=122 && j<124) || (j>=126 && j<128) )) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 

	   } else if (i == 47 + k && j % 2 == 0) {
	   
	    tmp_neg = Cudd_Not(var); 
	    tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   
	   } else if (i == 47 + k && j % 2 == 1) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 

	   }
	  
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd_rec[j]);
      bdd_rec[j] = tmp;
    }
  }
    
    bdd4 = Cudd_bddOr(gbm,bdd_rec[0],bdd_rec[1]); 
    Cudd_Ref(bdd4);   
    
    for (k = 2;k<128;k++) {
    bdd4 = Cudd_bddOr(gbm,bdd4,bdd_rec[k]);
    Cudd_Ref(bdd4);   
     }

////    bdd = Cudd_bddAnd(gbm,bdd,bdd4);
    
    
     for(j = 0;j<128;j++){ 
       for (i = 40; i < 48; i++) {
          var = Cudd_bddIthVar(gbm,i); 
          if(i%8 ==  0) {
         // tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, var, bdd_rec2[j]); 
	  }
	  else if(i == 41+k && j < 64 ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec2[j]); 
          }else if(i == 41+k && j >= 64) {
	  tmp = Cudd_bddAnd(gbm, var, bdd_rec2[j]); 
          }
	  else if ( (i == 42 + k) && ( ( j < 32 ) || ( j >= 64 && j < 96 ) ) ) {
          tmp_neg = Cudd_Not(var);
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec2[j]); 
          } else if ( i == 42 + k && ( ( j >= 32 && j < 64 ) || ( j >= 96 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec2[j]); 
	  } else if (i == 43 + k && ( (j<16) || (j>=32 && j<48) || (j>=64 && j<80) || (j>=96 && j<112) ) ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec2[j]); 
	  } else if (i == 43 + k && ( (j >= 16 && j < 32) || ( j >= 48 && j < 64 ) || ( j >= 80 && j < 96 ) || ( j >= 112 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec2[j]); 
          } else if ( i == 44 + k && ( ( j < 8 ) || ( j >= 16 && j < 24) || (j >= 32 && j < 40) || (j>=48 && j<56) || ( j >= 64 && j < 72 ) || 
		    (j >= 80 && j < 88) || (j >= 96 && j < 104) || (j>=112 && j<120) ) ) {
	   tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec2[j]); 
           } else if (i == 44 + k && ( ( j >= 8 && j < 16 ) || ( j >= 24 && j < 32 ) || ( j >= 40 && j < 48) || ( j >= 56 && j < 64) 
			|| (j>72 && j<=80) || (j>=88 && j<96) || (j>=104 && j<112) || (j>=120) ) ) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec2[j]);  
 	   } else if (i == 45 + k && ( (j < 4) || (j >= 8 && j < 12) || (j >= 16 && j < 20) || (j >= 24 && j < 28) || (j >= 32 && j < 36) || (j >= 40 && j < 44)
			|| (j >= 48 && j < 52)  || (j >= 56 && j < 60)|| (j >= 64 && j < 68) || (j >= 72 && j < 76) || (j >= 80 && j < 84) || (j >= 88 && j < 92) 	
			|| (j >= 96 && j < 100) || (j >= 104 && j < 108) || (j >= 112 && j < 116) || (j >= 120 && j < 124))) {
	   tmp_neg = Cudd_Not(var);
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec2[j]); 
	   
	   } else if (i == 45 + k && ( (j>=4 && j<8) || ( j >= 12 && j < 16 ) || ( j >= 20 && j < 24 ) || ( j >= 28 && j < 32 ) || ( j >= 36 && j < 40 ) 
			|| ( j >= 44 && j < 48 ) || ( j >= 52 && j < 56 ) || ( j >= 60 && j < 64 ) || ( j >= 68 && j < 72 ) || ( j >= 76 && j < 80 ) 	  
		        || ( j >= 84 && j < 88 ) || ( j >= 92 && j < 96 ) || ( j >= 100 && j < 104 ) || ( j >= 108 && j < 112 ) 
			|| ( j >= 116 && j < 120  ) 	|| ( j >= 124 && j < 128 ))) {
          
		   tmp = Cudd_bddAnd(gbm,var,bdd_rec2[j]); 
           } else if ( i == 46 + k && ( (j<2) || (j>=4 && j<6)  || (j>=8 && j<10) || (j>=12 && j<14) || (j>=16 && j<18) || (j>=20 && j<22) || (j>=24 && j<26)
			|| (j>=28 && j<30) || (j>=32 && j<34) || (j>=36 && j<38) || (j>=40 && j<42) || (j>=44 && j<46) || (j>=48 && j<50) || (j>=52 && j<54) 	  
			|| (j>=56 && j<58) || (j>=60 && j<62) || (j>=64 && j<66) || (j>=68 && j<70) || (j>=72 && j<74) || (j>=76 && j<78) || (j>=80 && j<82) 
                	|| (j>=84 && j<86) || (j>=88 && j<90) || (j>=92 && j<94) || (j>=96 && j<98) || (j>=100 && j<102) || (j>=104 && j<106) || (j>=108 && j<110) || 
                	(j>=112 && j<114) || (j>=116 && j<118)     || (j>=120 && j<122) || (j>=124 && j<126)
			)) {
	    tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec2[j]); 
	   } else if (i == 46 + k && ( (j>=2 && j<4) || (j>=6 && j<8) || (j>=10 && j<12) || (j>=14 && j<16) || (j>=18 && j<20) || (j>=22 && j<24) || (j>=26 && j<28)
			|| (j>=30 && j<32) || (j>=34 && j<36) || (j>=38 && j<40) || (j>=42 && j<44) || (j>=46 && j<48) || (j>=50 && j<52) 
			|| (j>=54 && j<56) || (j>=58 && j<60) || (j>=62 && j<64) || (j>=66 && j<68) || (j>=70 && j<72) || (j>=74 && j<76) 
			|| (j>=78 && j<80) || (j>=82 && j<84) || (j>=86 && j<88) || (j>=90 && j<92) || (j>=94 && j<96)
                        || (j>=98 && j<100) || (j>=102 && j<104) || (j>=106 && j<108) || (j>=110 && j<112) || (j>=114 && j<116) 
			|| (j>=118 && j<120) || (j>=122 && j<124) || (j>=126 && j<128) )) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec2[j]); 

	   } else if (i == 47 + k && j % 2 == 0) {
	   
	    tmp_neg = Cudd_Not(var); 
	    tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec2[j]); 
	   
	   } else if (i == 47 + k && j % 2 == 1) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec2[j]); 

	   }
	  
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd_rec2[j]);
      bdd_rec2[j] = tmp;
    }
  }
    
    
    bdd5 = Cudd_bddOr(gbm,bdd_rec2[0],bdd_rec2[1]); 
    Cudd_Ref(bdd5);   
    
    for (k = 2;k<128;k++) {
    bdd5 = Cudd_bddOr(gbm,bdd5,bdd_rec2[k]);
    Cudd_Ref(bdd5);   
     }
 
    bdd6 = Cudd_bddOr(gbm,bdd4,bdd5);
 
    bdd = Cudd_bddAnd(gbm, bdd,bdd6);
 */
    DdNode* bdd71;
   
    bdd71 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd71); /*Increases the reference count of a node*/

     for (i = 16; i < 18; i++) {  
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd71); 
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd71);
      bdd71 = tmp;
    }
    
    
    bdd = Cudd_bddAnd(gbm,bdd,bdd71);
    Cudd_Ref(bdd);


    return bdd;




}	



DdNode* scrivi_bdd_tre13 (DdManager *gbm, DdNode *bdd, DdNode * var) {

     DdNode* bdd_rec[128];
     DdNode* bdd_rec2[128];
     DdNode* bdd_rec3[128];
     DdNode* bdd_rec4[128];
DdNode* bdd_rec5[128];
     DdNode *bdd1, *bdd2, *bdd3, *bdd4, *bdd5, *bdd6, *bdd7, *bdd8, *bdd9,*tmp,*tmp_neg,*bdd10, *bdd11;
     bdd = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd); /*Increases the reference count of a node*/
     int i; 
     
     for(i = 0; i < 128; i++){
     bdd_rec[i] = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd_rec[i]); /*Increases the reference count of a node*/
     } 
     for(i = 0; i < 128; i++){
     bdd_rec2[i] = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd_rec2[i]); /*Increases the reference count of a node*/
     } 
     for(i = 0; i < 128; i++){
     bdd_rec3[i] = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd_rec3[i]); /*Increases the reference count of a node*/
     } 
     for(i = 0; i < 128; i++){
     bdd_rec4[i] = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd_rec4[i]); /*Increases the reference count of a node*/
     } 
     for(i = 0; i < 128; i++){
     bdd_rec5[i] = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd_rec5[i]); /*Increases the reference count of a node*/
     } 
     
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
     bdd6 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd6); /*Increases the reference count of a node*/
     bdd7 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd7); /*Increases the reference count of a node*/
     bdd8 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd8); /*Increases the reference count of a node*/
     bdd9 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd9); /*Increases the reference count of a node*/
     bdd10 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd10); /*Increases the reference count of a node*/
     bdd11 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd11); /*Increases the reference count of a node*/

   
     
     for (i = 0; i < 8; i++) {
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
     if(i != 0 && i != 3 ) {
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

int j;int k = 0;
     for(j = 0;j<128;j++){ 
       for (i = 8; i < 16; i++) {
          var = Cudd_bddIthVar(gbm,i); 
          if(i%8 ==  0) {
          //tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, var, bdd_rec[j]); 
	  }
	  else if(i == 9+k && j < 64 ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
          }else if(i == 9+k && j >= 64) {
	  tmp = Cudd_bddAnd(gbm, var, bdd_rec[j]); 
          }
	  else if ( (i == 10 + k) && ( ( j < 32 ) || ( j >= 64 && j < 96 ) ) ) {
          tmp_neg = Cudd_Not(var);
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
          } else if ( i == 10 + k && ( ( j >= 32 && j < 64 ) || ( j >= 96 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
	  } else if (i == 11 + k && ( (j<16) || (j>=32 && j<48) || (j>=64 && j<80) || (j>=96 && j<112) ) ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	  } else if (i == 11 + k && ( (j >= 16 && j < 32) || ( j >= 48 && j < 64 ) || ( j >= 80 && j < 96 ) || ( j >= 112 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
          } else if ( i == 12 + k && ( ( j < 8 ) || ( j >= 16 && j < 24) || (j >= 32 && j < 40) || (j>=48 && j<56) || ( j >= 64 && j < 72 ) || 
		    (j >= 80 && j < 88) || (j >= 96 && j < 104) || (j>=112 && j<120) ) ) {
	   tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
           } else if (i == 12 + k && ( ( j >= 8 && j < 16 ) || ( j >= 24 && j < 32 ) || ( j >= 40 && j < 48) || ( j >= 56 && j < 64) 
			|| (j>72 && j<=80) || (j>=88 && j<96) || (j>=104 && j<112) || (j>=120) ) ) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]);  
 	   } else if (i == 13 + k && ( (j < 4) || (j >= 8 && j < 12) || (j >= 16 && j < 20) || (j >= 24 && j < 28) || (j >= 32 && j < 36) || (j >= 40 && j < 44)
			|| (j >= 48 && j < 52)  || (j >= 56 && j < 60)|| (j >= 64 && j < 68) || (j >= 72 && j < 76) || (j >= 80 && j < 84) || (j >= 88 && j < 92) 	
			|| (j >= 96 && j < 100) || (j >= 104 && j < 108) || (j >= 112 && j < 116) || (j >= 120 && j < 124))) {
	   tmp_neg = Cudd_Not(var);
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   
	   } else if (i == 13 + k && ( (j>=4 && j<8) || ( j >= 12 && j < 16 ) || ( j >= 20 && j < 24 ) || ( j >= 28 && j < 32 ) || ( j >= 36 && j < 40 ) 
			|| ( j >= 44 && j < 48 ) || ( j >= 52 && j < 56 ) || ( j >= 60 && j < 64 ) || ( j >= 68 && j < 72 ) || ( j >= 76 && j < 80 ) 	  
		        || ( j >= 84 && j < 88 ) || ( j >= 92 && j < 96 ) || ( j >= 100 && j < 104 ) || ( j >= 108 && j < 112 ) 
			|| ( j >= 116 && j < 120  ) 	|| ( j >= 124 && j < 128 ))) {
          
		   tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
           } else if ( i == 14 + k && ( (j<2) || (j>=4 && j<6)  || (j>=8 && j<10) || (j>=12 && j<14) || (j>=16 && j<18) || (j>=20 && j<22) || (j>=24 && j<26)
			|| (j>=28 && j<30) || (j>=32 && j<34) || (j>=36 && j<38) || (j>=40 && j<42) || (j>=44 && j<46) || (j>=48 && j<50) || (j>=52 && j<54) 	  
			|| (j>=56 && j<58) || (j>=60 && j<62) || (j>=64 && j<66) || (j>=68 && j<70) || (j>=72 && j<74) || (j>=76 && j<78) || (j>=80 && j<82) 
                	|| (j>=84 && j<86) || (j>=88 && j<90) || (j>=92 && j<94) || (j>=96 && j<98) || (j>=100 && j<102) || (j>=104 && j<106) || (j>=108 && j<110) || 
                	(j>=112 && j<114) || (j>=116 && j<118)     || (j>=120 && j<122) || (j>=124 && j<126)
			)) {
	    tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   } else if (i == 14 + k && ( (j>=2 && j<4) || (j>=6 && j<8) || (j>=10 && j<12) || (j>=14 && j<16) || (j>=18 && j<20) || (j>=22 && j<24) || (j>=26 && j<28)
			|| (j>=30 && j<32) || (j>=34 && j<36) || (j>=38 && j<40) || (j>=42 && j<44) || (j>=46 && j<48) || (j>=50 && j<52) 
			|| (j>=54 && j<56) || (j>=58 && j<60) || (j>=62 && j<64) || (j>=66 && j<68) || (j>=70 && j<72) || (j>=74 && j<76) 
			|| (j>=78 && j<80) || (j>=82 && j<84) || (j>=86 && j<88) || (j>=90 && j<92) || (j>=94 && j<96)
                        || (j>=98 && j<100) || (j>=102 && j<104) || (j>=106 && j<108) || (j>=110 && j<112) || (j>=114 && j<116) 
			|| (j>=118 && j<120) || (j>=122 && j<124) || (j>=126 && j<128) )) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 

	   } else if (i == 15 + k && j % 2 == 0) {
	   
	    tmp_neg = Cudd_Not(var); 
	    tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   
	   } else if (i == 15 + k && j % 2 == 1) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 

	   }
	  
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd_rec[j]);
      bdd_rec[j] = tmp;
    }
  }
    
    bdd1 = Cudd_bddOr(gbm,bdd_rec[0],bdd_rec[1]); 
    Cudd_Ref(bdd1);   
    
    for (k = 2;k<128;k++) {
    bdd1 = Cudd_bddOr(gbm,bdd1,bdd_rec[k]);
    Cudd_Ref(bdd1);   
     }

    bdd = Cudd_bddAnd(gbm,bdd,bdd1);
    Cudd_Ref(bdd);   
/*
     for(j = 0;j<128;j++){ 
       for (i = 16; i < 24; i++) {
          var = Cudd_bddIthVar(gbm,i); 
          if(i%8 ==  0) {
          //tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, var, bdd_rec[j]); 
	  }
	  else if(i == 17+k && j < 64 ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
          }else if(i == 17+k && j >= 64) {
	  tmp = Cudd_bddAnd(gbm, var, bdd_rec[j]); 
          }
	  else if ( (i == 18 + k) && ( ( j < 32 ) || ( j >= 64 && j < 96 ) ) ) {
          tmp_neg = Cudd_Not(var);
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
          } else if ( i == 18 + k && ( ( j >= 32 && j < 64 ) || ( j >= 96 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
	  } else if (i == 19 + k && ( (j<16) || (j>=32 && j<48) || (j>=64 && j<80) || (j>=96 && j<112) ) ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	  } else if (i == 19 + k && ( (j >= 16 && j < 32) || ( j >= 48 && j < 64 ) || ( j >= 80 && j < 96 ) || ( j >= 112 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
          } else if ( i == 20 + k && ( ( j < 8 ) || ( j >= 16 && j < 24) || (j >= 32 && j < 40) || (j>=48 && j<56) || ( j >= 64 && j < 72 ) || 
		    (j >= 80 && j < 88) || (j >= 96 && j < 104) || (j>=112 && j<120) ) ) {
	   tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
           } else if (i == 20 + k && ( ( j >= 8 && j < 16 ) || ( j >= 24 && j < 32 ) || ( j >= 40 && j < 48) || ( j >= 56 && j < 64) 
			|| (j>72 && j<=80) || (j>=88 && j<96) || (j>=104 && j<112) || (j>=120) ) ) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]);  
 	   } else if (i == 21 + k && ( (j < 4) || (j >= 8 && j < 12) || (j >= 16 && j < 20) || (j >= 24 && j < 28) || (j >= 32 && j < 36) || (j >= 40 && j < 44)
			|| (j >= 48 && j < 52)  || (j >= 56 && j < 60)|| (j >= 64 && j < 68) || (j >= 72 && j < 76) || (j >= 80 && j < 84) || (j >= 88 && j < 92) 	
			|| (j >= 96 && j < 100) || (j >= 104 && j < 108) || (j >= 112 && j < 116) || (j >= 120 && j < 124))) {
	   tmp_neg = Cudd_Not(var);
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   
	   } else if (i == 21 + k && ( (j>=4 && j<8) || ( j >= 12 && j < 16 ) || ( j >= 20 && j < 24 ) || ( j >= 28 && j < 32 ) || ( j >= 36 && j < 40 ) 
			|| ( j >= 44 && j < 48 ) || ( j >= 52 && j < 56 ) || ( j >= 60 && j < 64 ) || ( j >= 68 && j < 72 ) || ( j >= 76 && j < 80 ) 	  
		        || ( j >= 84 && j < 88 ) || ( j >= 92 && j < 96 ) || ( j >= 100 && j < 104 ) || ( j >= 108 && j < 112 ) 
			|| ( j >= 116 && j < 120  ) 	|| ( j >= 124 && j < 128 ))) {
          
		   tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
           } else if ( i == 22 + k && ( (j<2) || (j>=4 && j<6)  || (j>=8 && j<10) || (j>=12 && j<14) || (j>=16 && j<18) || (j>=20 && j<22) || (j>=24 && j<26)
			|| (j>=28 && j<30) || (j>=32 && j<34) || (j>=36 && j<38) || (j>=40 && j<42) || (j>=44 && j<46) || (j>=48 && j<50) || (j>=52 && j<54) 	  
			|| (j>=56 && j<58) || (j>=60 && j<62) || (j>=64 && j<66) || (j>=68 && j<70) || (j>=72 && j<74) || (j>=76 && j<78) || (j>=80 && j<82) 
                	|| (j>=84 && j<86) || (j>=88 && j<90) || (j>=92 && j<94) || (j>=96 && j<98) || (j>=100 && j<102) || (j>=104 && j<106) || (j>=108 && j<110) || 
                	(j>=112 && j<114) || (j>=116 && j<118)     || (j>=120 && j<122) || (j>=124 && j<126)
			)) {
	    tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   } else if (i == 22 + k && ( (j>=2 && j<4) || (j>=6 && j<8) || (j>=10 && j<12) || (j>=14 && j<16) || (j>=18 && j<20) || (j>=22 && j<24) || (j>=26 && j<28)
			|| (j>=30 && j<32) || (j>=34 && j<36) || (j>=38 && j<40) || (j>=42 && j<44) || (j>=46 && j<48) || (j>=50 && j<52) 
			|| (j>=54 && j<56) || (j>=58 && j<60) || (j>=62 && j<64) || (j>=66 && j<68) || (j>=70 && j<72) || (j>=74 && j<76) 
			|| (j>=78 && j<80) || (j>=82 && j<84) || (j>=86 && j<88) || (j>=90 && j<92) || (j>=94 && j<96)
                        || (j>=98 && j<100) || (j>=102 && j<104) || (j>=106 && j<108) || (j>=110 && j<112) || (j>=114 && j<116) 
			|| (j>=118 && j<120) || (j>=122 && j<124) || (j>=126 && j<128) )) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 

	   } else if (i == 23 + k && j % 2 == 0) {
	   
	    tmp_neg = Cudd_Not(var); 
	    tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   
	   } else if (i == 23 + k && j % 2 == 1) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 

	   }
	  
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd_rec[j]);
      bdd_rec[j] = tmp;
    }
  }
    
    bdd2 = Cudd_bddOr(gbm,bdd_rec[0],bdd_rec[1]); 
    Cudd_Ref(bdd2);   
    
    for (k = 2;k<128;k++) {
    bdd2 = Cudd_bddOr(gbm,bdd2,bdd_rec[k]);
    Cudd_Ref(bdd2);   
     }

    bdd = Cudd_bddAnd(gbm,bdd,bdd2);
    Cudd_Ref(bdd);   
   
     for(j = 0;j<128;j++){ 
       for (i = 24; i < 32; i++) {
          var = Cudd_bddIthVar(gbm,i); 
          if(i%8 ==  0) {
          //tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, var, bdd_rec[j]); 
	  }
	  else if(i == 25+k && j < 64 ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
          }else if(i == 25+k && j >= 64) {
	  tmp = Cudd_bddAnd(gbm, var, bdd_rec[j]); 
          }
	  else if ( (i == 26 + k) && ( ( j < 32 ) || ( j >= 64 && j < 96 ) ) ) {
          tmp_neg = Cudd_Not(var);
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
          } else if ( i == 26 + k && ( ( j >= 32 && j < 64 ) || ( j >= 96 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
	  } else if (i == 27 + k && ( (j<16) || (j>=32 && j<48) || (j>=64 && j<80) || (j>=96 && j<112) ) ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	  } else if (i == 27 + k && ( (j >= 16 && j < 32) || ( j >= 48 && j < 64 ) || ( j >= 80 && j < 96 ) || ( j >= 112 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
          } else if ( i == 28 + k && ( ( j < 8 ) || ( j >= 16 && j < 24) || (j >= 32 && j < 40) || (j>=48 && j<56) || ( j >= 64 && j < 72 ) || 
		    (j >= 80 && j < 88) || (j >= 96 && j < 104) || (j>=112 && j<120) ) ) {
	   tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
           } else if (i == 28 + k && ( ( j >= 8 && j < 16 ) || ( j >= 24 && j < 32 ) || ( j >= 40 && j < 48) || ( j >= 56 && j < 64) 
			|| (j>72 && j<=80) || (j>=88 && j<96) || (j>=104 && j<112) || (j>=120) ) ) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]);  
 	   } else if (i == 29 + k && ( (j < 4) || (j >= 8 && j < 12) || (j >= 16 && j < 20) || (j >= 24 && j < 28) || (j >= 32 && j < 36) || (j >= 40 && j < 44)
			|| (j >= 48 && j < 52)  || (j >= 56 && j < 60)|| (j >= 64 && j < 68) || (j >= 72 && j < 76) || (j >= 80 && j < 84) || (j >= 88 && j < 92) 	
			|| (j >= 96 && j < 100) || (j >= 104 && j < 108) || (j >= 112 && j < 116) || (j >= 120 && j < 124))) {
	   tmp_neg = Cudd_Not(var);
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   
	   } else if (i == 29 + k && ( (j>=4 && j<8) || ( j >= 12 && j < 16 ) || ( j >= 20 && j < 24 ) || ( j >= 28 && j < 32 ) || ( j >= 36 && j < 40 ) 
			|| ( j >= 44 && j < 48 ) || ( j >= 52 && j < 56 ) || ( j >= 60 && j < 64 ) || ( j >= 68 && j < 72 ) || ( j >= 76 && j < 80 ) 	  
		        || ( j >= 84 && j < 88 ) || ( j >= 92 && j < 96 ) || ( j >= 100 && j < 104 ) || ( j >= 108 && j < 112 ) 
			|| ( j >= 116 && j < 120  ) 	|| ( j >= 124 && j < 128 ))) {
          
		   tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
           } else if ( i == 30 + k && ( (j<2) || (j>=4 && j<6)  || (j>=8 && j<10) || (j>=12 && j<14) || (j>=16 && j<18) || (j>=20 && j<22) || (j>=24 && j<26)
			|| (j>=28 && j<30) || (j>=32 && j<34) || (j>=36 && j<38) || (j>=40 && j<42) || (j>=44 && j<46) || (j>=48 && j<50) || (j>=52 && j<54) 	  
			|| (j>=56 && j<58) || (j>=60 && j<62) || (j>=64 && j<66) || (j>=68 && j<70) || (j>=72 && j<74) || (j>=76 && j<78) || (j>=80 && j<82) 
                	|| (j>=84 && j<86) || (j>=88 && j<90) || (j>=92 && j<94) || (j>=96 && j<98) || (j>=100 && j<102) || (j>=104 && j<106) || (j>=108 && j<110) || 
                	(j>=112 && j<114) || (j>=116 && j<118)     || (j>=120 && j<122) || (j>=124 && j<126)
			)) {
	    tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   } else if (i == 30 + k && ( (j>=2 && j<4) || (j>=6 && j<8) || (j>=10 && j<12) || (j>=14 && j<16) || (j>=18 && j<20) || (j>=22 && j<24) || (j>=26 && j<28)
			|| (j>=30 && j<32) || (j>=34 && j<36) || (j>=38 && j<40) || (j>=42 && j<44) || (j>=46 && j<48) || (j>=50 && j<52) 
			|| (j>=54 && j<56) || (j>=58 && j<60) || (j>=62 && j<64) || (j>=66 && j<68) || (j>=70 && j<72) || (j>=74 && j<76) 
			|| (j>=78 && j<80) || (j>=82 && j<84) || (j>=86 && j<88) || (j>=90 && j<92) || (j>=94 && j<96)
                        || (j>=98 && j<100) || (j>=102 && j<104) || (j>=106 && j<108) || (j>=110 && j<112) || (j>=114 && j<116) 
			|| (j>=118 && j<120) || (j>=122 && j<124) || (j>=126 && j<128) )) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 

	   } else if (i == 31 + k && j % 2 == 0) {
	   
	    tmp_neg = Cudd_Not(var); 
	    tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   
	   } else if (i == 31 + k && j % 2 == 1) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 

	   }
	  
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd_rec[j]);
      bdd_rec[j] = tmp;
    }
  }
    
    bdd3 = Cudd_bddOr(gbm,bdd_rec[0],bdd_rec[1]); 
    Cudd_Ref(bdd3);   
    
    for (k = 2;k<128;k++) {
    bdd3 = Cudd_bddOr(gbm,bdd3,bdd_rec[k]);
    Cudd_Ref(bdd3);   
     }

    bdd = Cudd_bddAnd(gbm,bdd,bdd3);
    Cudd_Ref(bdd);   
   

	 

     for(j = 0;j<128;j++){ 
       for (i = 32; i < 40; i++) {
          var = Cudd_bddIthVar(gbm,i); 
          if(i%8 ==  0) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec3[j]); 
	  }
	  else if(i == 33+k && j < 64 ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec3[j]); 
          }else if(i == 33+k && j >= 64) {
	  tmp = Cudd_bddAnd(gbm, var, bdd_rec3[j]); 
          }
	  else if ( (i == 34 + k) && ( ( j < 32 ) || ( j >= 64 && j < 96 ) ) ) {
          tmp_neg = Cudd_Not(var);
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec3[j]); 
          } else if ( i == 34 + k && ( ( j >= 32 && j < 64 ) || ( j >= 96 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec3[j]); 
	  } else if (i == 35 + k && ( (j<16) || (j>=32 && j<48) || (j>=64 && j<80) || (j>=96 && j<112) ) ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec3[j]); 
	  } else if (i == 35 + k && ( (j >= 16 && j < 32) || ( j >= 48 && j < 64 ) || ( j >= 80 && j < 96 ) || ( j >= 112 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec3[j]); 
          } else if ( i == 36 + k && ( ( j < 8 ) || ( j >= 16 && j < 24) || (j >= 32 && j < 40) || (j>=48 && j<56) || ( j >= 64 && j < 72 ) || 
		    (j >= 80 && j < 88) || (j >= 96 && j < 104) || (j>=112 && j<120) ) ) {
	   tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec3[j]); 
           } else if (i == 36 + k && ( ( j >= 8 && j < 16 ) || ( j >= 24 && j < 32 ) || ( j >= 40 && j < 48) || ( j >= 56 && j < 64) 
			|| (j>72 && j<=80) || (j>=88 && j<96) || (j>=104 && j<112) || (j>=120) ) ) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec3[j]);  
 	   } else if (i == 37 + k && ( (j < 4) || (j >= 8 && j < 12) || (j >= 16 && j < 20) || (j >= 24 && j < 28) || (j >= 32 && j < 36) || (j >= 40 && j < 44)
			|| (j >= 48 && j < 52)  || (j >= 56 && j < 60)|| (j >= 64 && j < 68) || (j >= 72 && j < 76) || (j >= 80 && j < 84) || (j >= 88 && j < 92) 	
			|| (j >= 96 && j < 100) || (j >= 104 && j < 108) || (j >= 112 && j < 116) || (j >= 120 && j < 124))) {
	   tmp_neg = Cudd_Not(var);
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec3[j]); 
	   
	   } else if (i == 37 + k && ( (j>=4 && j<8) || ( j >= 12 && j < 16 ) || ( j >= 20 && j < 24 ) || ( j >= 28 && j < 32 ) || ( j >= 36 && j < 40 ) 
			|| ( j >= 44 && j < 48 ) || ( j >= 52 && j < 56 ) || ( j >= 60 && j < 64 ) || ( j >= 68 && j < 72 ) || ( j >= 76 && j < 80 ) 	  
		        || ( j >= 84 && j < 88 ) || ( j >= 92 && j < 96 ) || ( j >= 100 && j < 104 ) || ( j >= 108 && j < 112 ) 
			|| ( j >= 116 && j < 120  ) 	|| ( j >= 124 && j < 128 ))) {
          
		   tmp = Cudd_bddAnd(gbm,var,bdd_rec3[j]); 
           } else if ( i == 38 + k && ( (j<2) || (j>=4 && j<6)  || (j>=8 && j<10) || (j>=12 && j<14) || (j>=16 && j<18) || (j>=20 && j<22) || (j>=24 && j<26)
			|| (j>=28 && j<30) || (j>=32 && j<34) || (j>=36 && j<38) || (j>=40 && j<42) || (j>=44 && j<46) || (j>=48 && j<50) || (j>=52 && j<54) 	  
			|| (j>=56 && j<58) || (j>=60 && j<62) || (j>=64 && j<66) || (j>=68 && j<70) || (j>=72 && j<74) || (j>=76 && j<78) || (j>=80 && j<82) 
                	|| (j>=84 && j<86) || (j>=88 && j<90) || (j>=92 && j<94) || (j>=96 && j<98) || (j>=100 && j<102) || (j>=104 && j<106) || (j>=108 && j<110) || 
                	(j>=112 && j<114) || (j>=116 && j<118)     || (j>=120 && j<122) || (j>=124 && j<126)
			)) {
	    tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec3[j]); 
	   } else if (i == 38 + k && ( (j>=2 && j<4) || (j>=6 && j<8) || (j>=10 && j<12) || (j>=14 && j<16) || (j>=18 && j<20) || (j>=22 && j<24) || (j>=26 && j<28)
			|| (j>=30 && j<32) || (j>=34 && j<36) || (j>=38 && j<40) || (j>=42 && j<44) || (j>=46 && j<48) || (j>=50 && j<52) 
			|| (j>=54 && j<56) || (j>=58 && j<60) || (j>=62 && j<64) || (j>=66 && j<68) || (j>=70 && j<72) || (j>=74 && j<76) 
			|| (j>=78 && j<80) || (j>=82 && j<84) || (j>=86 && j<88) || (j>=90 && j<92) || (j>=94 && j<96)
                        || (j>=98 && j<100) || (j>=102 && j<104) || (j>=106 && j<108) || (j>=110 && j<112) || (j>=114 && j<116) 
			|| (j>=118 && j<120) || (j>=122 && j<124) || (j>=126 && j<128) )) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec3[j]); 

	   } else if (i == 39 + k && j % 2 == 0) {
	   
	    tmp_neg = Cudd_Not(var); 
	    tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec3[j]); 
	   
	   } else if (i == 39 + k && j % 2 == 1) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec3[j]); 

	   }
	  
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd_rec3[j]);
      bdd_rec3[j] = tmp;
    }
  }
    
    bdd7 = Cudd_bddOr(gbm,bdd_rec3[0],bdd_rec3[1]); 
    Cudd_Ref(bdd7);   
    
    for (k = 2;k<128;k++) {
    bdd7 = Cudd_bddOr(gbm,bdd7,bdd_rec3[k]);
    Cudd_Ref(bdd7);   
     }

    bdd = Cudd_bddAnd(gbm,bdd,bdd7);



     
    for(j = 0;j<128;j++){ 
       for (i = 40; i < 48; i++) {
          var = Cudd_bddIthVar(gbm,i); 
          if(i%8 ==  0) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	  }
	  else if(i == 41+k && j < 64 ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
          }else if(i == 41+k && j >= 64) {
	  tmp = Cudd_bddAnd(gbm, var, bdd_rec[j]); 
          }
	  else if ( (i == 42 + k) && ( ( j < 32 ) || ( j >= 64 && j < 96 ) ) ) {
          tmp_neg = Cudd_Not(var);
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
          } else if ( i == 42 + k && ( ( j >= 32 && j < 64 ) || ( j >= 96 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
	  } else if (i == 43 + k && ( (j<16) || (j>=32 && j<48) || (j>=64 && j<80) || (j>=96 && j<112) ) ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	  } else if (i == 43 + k && ( (j >= 16 && j < 32) || ( j >= 48 && j < 64 ) || ( j >= 80 && j < 96 ) || ( j >= 112 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
          } else if ( i == 44 + k && ( ( j < 8 ) || ( j >= 16 && j < 24) || (j >= 32 && j < 40) || (j>=48 && j<56) || ( j >= 64 && j < 72 ) || 
		    (j >= 80 && j < 88) || (j >= 96 && j < 104) || (j>=112 && j<120) ) ) {
	   tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
           } else if (i == 44 + k && ( ( j >= 8 && j < 16 ) || ( j >= 24 && j < 32 ) || ( j >= 40 && j < 48) || ( j >= 56 && j < 64) 
			|| (j>72 && j<=80) || (j>=88 && j<96) || (j>=104 && j<112) || (j>=120) ) ) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]);  
 	   } else if (i == 45 + k && ( (j < 4) || (j >= 8 && j < 12) || (j >= 16 && j < 20) || (j >= 24 && j < 28) || (j >= 32 && j < 36) || (j >= 40 && j < 44)
			|| (j >= 48 && j < 52)  || (j >= 56 && j < 60)|| (j >= 64 && j < 68) || (j >= 72 && j < 76) || (j >= 80 && j < 84) || (j >= 88 && j < 92) 	
			|| (j >= 96 && j < 100) || (j >= 104 && j < 108) || (j >= 112 && j < 116) || (j >= 120 && j < 124))) {
	   tmp_neg = Cudd_Not(var);
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   
	   } else if (i == 45 + k && ( (j>=4 && j<8) || ( j >= 12 && j < 16 ) || ( j >= 20 && j < 24 ) || ( j >= 28 && j < 32 ) || ( j >= 36 && j < 40 ) 
			|| ( j >= 44 && j < 48 ) || ( j >= 52 && j < 56 ) || ( j >= 60 && j < 64 ) || ( j >= 68 && j < 72 ) || ( j >= 76 && j < 80 ) 	  
		        || ( j >= 84 && j < 88 ) || ( j >= 92 && j < 96 ) || ( j >= 100 && j < 104 ) || ( j >= 108 && j < 112 ) 
			|| ( j >= 116 && j < 120  ) 	|| ( j >= 124 && j < 128 ))) {
          
		   tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
           } else if ( i == 46 + k && ( (j<2) || (j>=4 && j<6)  || (j>=8 && j<10) || (j>=12 && j<14) || (j>=16 && j<18) || (j>=20 && j<22) || (j>=24 && j<26)
			|| (j>=28 && j<30) || (j>=32 && j<34) || (j>=36 && j<38) || (j>=40 && j<42) || (j>=44 && j<46) || (j>=48 && j<50) || (j>=52 && j<54) 	  
			|| (j>=56 && j<58) || (j>=60 && j<62) || (j>=64 && j<66) || (j>=68 && j<70) || (j>=72 && j<74) || (j>=76 && j<78) || (j>=80 && j<82) 
                	|| (j>=84 && j<86) || (j>=88 && j<90) || (j>=92 && j<94) || (j>=96 && j<98) || (j>=100 && j<102) || (j>=104 && j<106) || (j>=108 && j<110) || 
                	(j>=112 && j<114) || (j>=116 && j<118)     || (j>=120 && j<122) || (j>=124 && j<126)
			)) {
	    tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   } else if (i == 46 + k && ( (j>=2 && j<4) || (j>=6 && j<8) || (j>=10 && j<12) || (j>=14 && j<16) || (j>=18 && j<20) || (j>=22 && j<24) || (j>=26 && j<28)
			|| (j>=30 && j<32) || (j>=34 && j<36) || (j>=38 && j<40) || (j>=42 && j<44) || (j>=46 && j<48) || (j>=50 && j<52) 
			|| (j>=54 && j<56) || (j>=58 && j<60) || (j>=62 && j<64) || (j>=66 && j<68) || (j>=70 && j<72) || (j>=74 && j<76) 
			|| (j>=78 && j<80) || (j>=82 && j<84) || (j>=86 && j<88) || (j>=90 && j<92) || (j>=94 && j<96)
                        || (j>=98 && j<100) || (j>=102 && j<104) || (j>=106 && j<108) || (j>=110 && j<112) || (j>=114 && j<116) 
			|| (j>=118 && j<120) || (j>=122 && j<124) || (j>=126 && j<128) )) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 

	   } else if (i == 47 + k && j % 2 == 0) {
	   
	    tmp_neg = Cudd_Not(var); 
	    tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   
	   } else if (i == 47 + k && j % 2 == 1) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 

	   }
	  
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd_rec[j]);
      bdd_rec[j] = tmp;
    }
  }
    
    bdd4 = Cudd_bddOr(gbm,bdd_rec[0],bdd_rec[1]); 
    Cudd_Ref(bdd4);   
    
    for (k = 2;k<128;k++) {
    bdd4 = Cudd_bddOr(gbm,bdd4,bdd_rec[k]);
    Cudd_Ref(bdd4);   
     }

////    bdd = Cudd_bddAnd(gbm,bdd,bdd4);
    
    
     for(j = 0;j<128;j++){ 
       for (i = 40; i < 48; i++) {
          var = Cudd_bddIthVar(gbm,i); 
          if(i%8 ==  0) {
         // tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, var, bdd_rec2[j]); 
	  }
	  else if(i == 41+k && j < 64 ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec2[j]); 
          }else if(i == 41+k && j >= 64) {
	  tmp = Cudd_bddAnd(gbm, var, bdd_rec2[j]); 
          }
	  else if ( (i == 42 + k) && ( ( j < 32 ) || ( j >= 64 && j < 96 ) ) ) {
          tmp_neg = Cudd_Not(var);
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec2[j]); 
          } else if ( i == 42 + k && ( ( j >= 32 && j < 64 ) || ( j >= 96 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec2[j]); 
	  } else if (i == 43 + k && ( (j<16) || (j>=32 && j<48) || (j>=64 && j<80) || (j>=96 && j<112) ) ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec2[j]); 
	  } else if (i == 43 + k && ( (j >= 16 && j < 32) || ( j >= 48 && j < 64 ) || ( j >= 80 && j < 96 ) || ( j >= 112 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec2[j]); 
          } else if ( i == 44 + k && ( ( j < 8 ) || ( j >= 16 && j < 24) || (j >= 32 && j < 40) || (j>=48 && j<56) || ( j >= 64 && j < 72 ) || 
		    (j >= 80 && j < 88) || (j >= 96 && j < 104) || (j>=112 && j<120) ) ) {
	   tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec2[j]); 
           } else if (i == 44 + k && ( ( j >= 8 && j < 16 ) || ( j >= 24 && j < 32 ) || ( j >= 40 && j < 48) || ( j >= 56 && j < 64) 
			|| (j>72 && j<=80) || (j>=88 && j<96) || (j>=104 && j<112) || (j>=120) ) ) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec2[j]);  
 	   } else if (i == 45 + k && ( (j < 4) || (j >= 8 && j < 12) || (j >= 16 && j < 20) || (j >= 24 && j < 28) || (j >= 32 && j < 36) || (j >= 40 && j < 44)
			|| (j >= 48 && j < 52)  || (j >= 56 && j < 60)|| (j >= 64 && j < 68) || (j >= 72 && j < 76) || (j >= 80 && j < 84) || (j >= 88 && j < 92) 	
			|| (j >= 96 && j < 100) || (j >= 104 && j < 108) || (j >= 112 && j < 116) || (j >= 120 && j < 124))) {
	   tmp_neg = Cudd_Not(var);
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec2[j]); 
	   
	   } else if (i == 45 + k && ( (j>=4 && j<8) || ( j >= 12 && j < 16 ) || ( j >= 20 && j < 24 ) || ( j >= 28 && j < 32 ) || ( j >= 36 && j < 40 ) 
			|| ( j >= 44 && j < 48 ) || ( j >= 52 && j < 56 ) || ( j >= 60 && j < 64 ) || ( j >= 68 && j < 72 ) || ( j >= 76 && j < 80 ) 	  
		        || ( j >= 84 && j < 88 ) || ( j >= 92 && j < 96 ) || ( j >= 100 && j < 104 ) || ( j >= 108 && j < 112 ) 
			|| ( j >= 116 && j < 120  ) 	|| ( j >= 124 && j < 128 ))) {
          
		   tmp = Cudd_bddAnd(gbm,var,bdd_rec2[j]); 
           } else if ( i == 46 + k && ( (j<2) || (j>=4 && j<6)  || (j>=8 && j<10) || (j>=12 && j<14) || (j>=16 && j<18) || (j>=20 && j<22) || (j>=24 && j<26)
			|| (j>=28 && j<30) || (j>=32 && j<34) || (j>=36 && j<38) || (j>=40 && j<42) || (j>=44 && j<46) || (j>=48 && j<50) || (j>=52 && j<54) 	  
			|| (j>=56 && j<58) || (j>=60 && j<62) || (j>=64 && j<66) || (j>=68 && j<70) || (j>=72 && j<74) || (j>=76 && j<78) || (j>=80 && j<82) 
                	|| (j>=84 && j<86) || (j>=88 && j<90) || (j>=92 && j<94) || (j>=96 && j<98) || (j>=100 && j<102) || (j>=104 && j<106) || (j>=108 && j<110) || 
                	(j>=112 && j<114) || (j>=116 && j<118)     || (j>=120 && j<122) || (j>=124 && j<126)
			)) {
	    tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec2[j]); 
	   } else if (i == 46 + k && ( (j>=2 && j<4) || (j>=6 && j<8) || (j>=10 && j<12) || (j>=14 && j<16) || (j>=18 && j<20) || (j>=22 && j<24) || (j>=26 && j<28)
			|| (j>=30 && j<32) || (j>=34 && j<36) || (j>=38 && j<40) || (j>=42 && j<44) || (j>=46 && j<48) || (j>=50 && j<52) 
			|| (j>=54 && j<56) || (j>=58 && j<60) || (j>=62 && j<64) || (j>=66 && j<68) || (j>=70 && j<72) || (j>=74 && j<76) 
			|| (j>=78 && j<80) || (j>=82 && j<84) || (j>=86 && j<88) || (j>=90 && j<92) || (j>=94 && j<96)
                        || (j>=98 && j<100) || (j>=102 && j<104) || (j>=106 && j<108) || (j>=110 && j<112) || (j>=114 && j<116) 
			|| (j>=118 && j<120) || (j>=122 && j<124) || (j>=126 && j<128) )) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec2[j]); 

	   } else if (i == 47 + k && j % 2 == 0) {
	   
	    tmp_neg = Cudd_Not(var); 
	    tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec2[j]); 
	   
	   } else if (i == 47 + k && j % 2 == 1) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec2[j]); 

	   }
	  
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd_rec2[j]);
      bdd_rec2[j] = tmp;
    }
  }
    
    
    bdd5 = Cudd_bddOr(gbm,bdd_rec2[0],bdd_rec2[1]); 
    Cudd_Ref(bdd5);   
    
    for (k = 2;k<128;k++) {
    bdd5 = Cudd_bddOr(gbm,bdd5,bdd_rec2[k]);
    Cudd_Ref(bdd5);   
     }
 
    bdd6 = Cudd_bddOr(gbm,bdd4,bdd5);
 
    bdd = Cudd_bddAnd(gbm, bdd,bdd6);
 
     for(j = 0;j<128;j++){ 
       for (i = 48; i < 52; i++) {
          var = Cudd_bddIthVar(gbm,i); 
          if(i%8 ==  0) {
         // tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, var, bdd_rec4[j]); 
	  }
	  else if(i == 49+k && j < 64 ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec4[j]); 
          }else if(i == 49+k && j >= 64) {
	  tmp = Cudd_bddAnd(gbm, var, bdd_rec4[j]); 
          }
	  else if ( (i == 50 + k) && ( ( j < 32 ) || ( j >= 64 && j < 96 ) ) ) {
          tmp_neg = Cudd_Not(var);
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec4[j]); 
          } else if ( i == 50 + k && ( ( j >= 32 && j < 64 ) || ( j >= 96 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec4[j]); 
	  } else if (i == 51 + k && ( (j<16) || (j>=32 && j<48) || (j>=64 && j<80) || (j>=96 && j<112) ) ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec4[j]); 
	  } else if (i == 51 + k && ( (j >= 16 && j < 32) || ( j >= 48 && j < 64 ) || ( j >= 80 && j < 96 ) || ( j >= 112 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec4[j]); 
          } else if ( i == 52 + k && ( ( j < 8 ) || ( j >= 16 && j < 24) || (j >= 32 && j < 40) || (j>=48 && j<56) || ( j >= 64 && j < 72 ) || 
		    (j >= 80 && j < 88) || (j >= 96 && j < 104) || (j>=112 && j<120) ) ) {
	   tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec4[j]); 
           } else if (i == 52 + k && ( ( j >= 8 && j < 16 ) || ( j >= 24 && j < 32 ) || ( j >= 40 && j < 48) || ( j >= 56 && j < 64) 
			|| (j>72 && j<=80) || (j>=88 && j<96) || (j>=104 && j<112) || (j>=120) ) ) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec4[j]);  
 	   } else if (i == 53 + k && ( (j < 4) || (j >= 8 && j < 12) || (j >= 16 && j < 20) || (j >= 24 && j < 28) || (j >= 32 && j < 36) || (j >= 40 && j < 44)
			|| (j >= 48 && j < 52)  || (j >= 56 && j < 60)|| (j >= 64 && j < 68) || (j >= 72 && j < 76) || (j >= 80 && j < 84) || (j >= 88 && j < 92) 	
			|| (j >= 96 && j < 100) || (j >= 104 && j < 108) || (j >= 112 && j < 116) || (j >= 120 && j < 124))) {
	   tmp_neg = Cudd_Not(var);
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec4[j]); 
	   
	   } else if (i == 53 + k && ( (j>=4 && j<8) || ( j >= 12 && j < 16 ) || ( j >= 20 && j < 24 ) || ( j >= 28 && j < 32 ) || ( j >= 36 && j < 40 ) 
			|| ( j >= 44 && j < 48 ) || ( j >= 52 && j < 56 ) || ( j >= 60 && j < 64 ) || ( j >= 68 && j < 72 ) || ( j >= 76 && j < 80 ) 	  
		        || ( j >= 84 && j < 88 ) || ( j >= 92 && j < 96 ) || ( j >= 100 && j < 104 ) || ( j >= 108 && j < 112 ) 
			|| ( j >= 116 && j < 120  ) 	|| ( j >= 124 && j < 128 ))) {
          
		   tmp = Cudd_bddAnd(gbm,var,bdd_rec4[j]); 
           } else if ( i == 54 + k && ( (j<2) || (j>=4 && j<6)  || (j>=8 && j<10) || (j>=12 && j<14) || (j>=16 && j<18) || (j>=20 && j<22) || (j>=24 && j<26)
			|| (j>=28 && j<30) || (j>=32 && j<34) || (j>=36 && j<38) || (j>=40 && j<42) || (j>=44 && j<46) || (j>=48 && j<50) || (j>=52 && j<54) 	  
			|| (j>=56 && j<58) || (j>=60 && j<62) || (j>=64 && j<66) || (j>=68 && j<70) || (j>=72 && j<74) || (j>=76 && j<78) || (j>=80 && j<82) 
                	|| (j>=84 && j<86) || (j>=88 && j<90) || (j>=92 && j<94) || (j>=96 && j<98) || (j>=100 && j<102) || (j>=104 && j<106) || (j>=108 && j<110) || 
                	(j>=112 && j<114) || (j>=116 && j<118)     || (j>=120 && j<122) || (j>=124 && j<126)
			)) {
	    tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec4[j]); 
	   } else if (i == 54 + k && ( (j>=2 && j<4) || (j>=6 && j<8) || (j>=10 && j<12) || (j>=14 && j<16) || (j>=18 && j<20) || (j>=22 && j<24) || (j>=26 && j<28)
			|| (j>=30 && j<32) || (j>=34 && j<36) || (j>=38 && j<40) || (j>=42 && j<44) || (j>=46 && j<48) || (j>=50 && j<52) 
			|| (j>=54 && j<56) || (j>=58 && j<60) || (j>=62 && j<64) || (j>=66 && j<68) || (j>=70 && j<72) || (j>=74 && j<76) 
			|| (j>=78 && j<80) || (j>=82 && j<84) || (j>=86 && j<88) || (j>=90 && j<92) || (j>=94 && j<96)
                        || (j>=98 && j<100) || (j>=102 && j<104) || (j>=106 && j<108) || (j>=110 && j<112) || (j>=114 && j<116) 
			|| (j>=118 && j<120) || (j>=122 && j<124) || (j>=126 && j<128) )) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec4[j]); 

	   } else if (i == 55 + k && j % 2 == 0) {
	   
	    tmp_neg = Cudd_Not(var); 
	    tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec4[j]); 
	   
	   } else if (i == 55 + k && j % 2 == 1) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec4[j]); 

	   }
	  
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd_rec4[j]);
      bdd_rec4[j] = tmp;
    }
  }
    
    
    bdd8 = Cudd_bddOr(gbm,bdd_rec4[0],bdd_rec4[1]); 
    Cudd_Ref(bdd8);   
    
    for (k = 2;k<128;k++) {
    bdd8 = Cudd_bddOr(gbm,bdd8,bdd_rec4[k]);
    Cudd_Ref(bdd8);   
     }
 
    //bdd9 = Cudd_bddOr(gbm,bdd7,bdd8);
    //bdd = Cudd_bddAnd(gbm,bdd,bdd9);
     for(j = 0;j<128;j++){ 
       for (i = 48; i < 56; i++) {
          var = Cudd_bddIthVar(gbm,i); 
          if(i%8 ==  0) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec5[j]); 
	  }
	  else if(i == 49+k && j < 64 ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec5[j]); 
          }else if(i == 49+k && j >= 64) {
	  tmp = Cudd_bddAnd(gbm, var, bdd_rec5[j]); 
          }
	  else if ( (i == 50 + k) && ( ( j < 32 ) || ( j >= 64 && j < 96 ) ) ) {
          tmp_neg = Cudd_Not(var);
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec5[j]); 
          } else if ( i == 50 + k && ( ( j >= 32 && j < 64 ) || ( j >= 96 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec5[j]); 
	  } else if (i == 51 + k && ( (j<16) || (j>=32 && j<48) || (j>=64 && j<80) || (j>=96 && j<112) ) ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec5[j]); 
	  } else if (i == 51 + k && ( (j >= 16 && j < 32) || ( j >= 48 && j < 64 ) || ( j >= 80 && j < 96 ) || ( j >= 112 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec5[j]); 
          } else if ( i == 52 + k && ( ( j < 8 ) || ( j >= 16 && j < 24) || (j >= 32 && j < 40) || (j>=48 && j<56) || ( j >= 64 && j < 72 ) || 
		    (j >= 80 && j < 88) || (j >= 96 && j < 104) || (j>=112 && j<120) ) ) {
	   tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec5[j]); 
           } else if (i == 52 + k && ( ( j >= 8 && j < 16 ) || ( j >= 24 && j < 32 ) || ( j >= 40 && j < 48) || ( j >= 56 && j < 64) 
			|| (j>72 && j<=80) || (j>=88 && j<96) || (j>=104 && j<112) || (j>=120) ) ) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec5[j]);  
 	   } else if (i == 53 + k && ( (j < 4) || (j >= 8 && j < 12) || (j >= 16 && j < 20) || (j >= 24 && j < 28) || (j >= 32 && j < 36) || (j >= 40 && j < 44)
			|| (j >= 48 && j < 52)  || (j >= 56 && j < 60)|| (j >= 64 && j < 68) || (j >= 72 && j < 76) || (j >= 80 && j < 84) || (j >= 88 && j < 92) 	
			|| (j >= 96 && j < 100) || (j >= 104 && j < 108) || (j >= 112 && j < 116) || (j >= 120 && j < 124))) {
	   tmp_neg = Cudd_Not(var);
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec5[j]); 
	   
	   } else if (i == 53 + k && ( (j>=4 && j<8) || ( j >= 12 && j < 16 ) || ( j >= 20 && j < 24 ) || ( j >= 28 && j < 32 ) || ( j >= 36 && j < 40 ) 
			|| ( j >= 44 && j < 48 ) || ( j >= 52 && j < 56 ) || ( j >= 60 && j < 64 ) || ( j >= 68 && j < 72 ) || ( j >= 76 && j < 80 ) 	  
		        || ( j >= 84 && j < 88 ) || ( j >= 92 && j < 96 ) || ( j >= 100 && j < 104 ) || ( j >= 108 && j < 112 ) 
			|| ( j >= 116 && j < 120  ) 	|| ( j >= 124 && j < 128 ))) {
          
		   tmp = Cudd_bddAnd(gbm,var,bdd_rec5[j]); 
           } else if ( i == 54 + k && ( (j<2) || (j>=4 && j<6)  || (j>=8 && j<10) || (j>=12 && j<14) || (j>=16 && j<18) || (j>=20 && j<22) || (j>=24 && j<26)
			|| (j>=28 && j<30) || (j>=32 && j<34) || (j>=36 && j<38) || (j>=40 && j<42) || (j>=44 && j<46) || (j>=48 && j<50) || (j>=52 && j<54) 	  
			|| (j>=56 && j<58) || (j>=60 && j<62) || (j>=64 && j<66) || (j>=68 && j<70) || (j>=72 && j<74) || (j>=76 && j<78) || (j>=80 && j<82) 
                	|| (j>=84 && j<86) || (j>=88 && j<90) || (j>=92 && j<94) || (j>=96 && j<98) || (j>=100 && j<102) || (j>=104 && j<106) || (j>=108 && j<110) || 
                	(j>=112 && j<114) || (j>=116 && j<118)     || (j>=120 && j<122) || (j>=124 && j<126)
			)) {
	    tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec5[j]); 
	   } else if (i == 54 + k && ( (j>=2 && j<4) || (j>=6 && j<8) || (j>=10 && j<12) || (j>=14 && j<16) || (j>=18 && j<20) || (j>=22 && j<24) || (j>=26 && j<28)
			|| (j>=30 && j<32) || (j>=34 && j<36) || (j>=38 && j<40) || (j>=42 && j<44) || (j>=46 && j<48) || (j>=50 && j<52) 
			|| (j>=54 && j<56) || (j>=58 && j<60) || (j>=62 && j<64) || (j>=66 && j<68) || (j>=70 && j<72) || (j>=74 && j<76) 
			|| (j>=78 && j<80) || (j>=82 && j<84) || (j>=86 && j<88) || (j>=90 && j<92) || (j>=94 && j<96)
                        || (j>=98 && j<100) || (j>=102 && j<104) || (j>=106 && j<108) || (j>=110 && j<112) || (j>=114 && j<116) 
			|| (j>=118 && j<120) || (j>=122 && j<124) || (j>=126 && j<128) )) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec5[j]); 

	   } else if (i == 55 + k && j % 2 == 0) {
	   
	    tmp_neg = Cudd_Not(var); 
	    tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec5[j]); 
	   
	   } else if (i == 55 + k && j % 2 == 1) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec5[j]); 

	   }
	  
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd_rec5[j]);
      bdd_rec5[j] = tmp;
    }
  }
    
    
    bdd11 = Cudd_bddOr(gbm,bdd_rec5[0],bdd_rec5[1]); 
    Cudd_Ref(bdd11);   
     
    
    for (k = 2;k<128;k++) {
    bdd11 = Cudd_bddOr(gbm,bdd11,bdd_rec5[k]);
    Cudd_Ref(bdd11);   
     }
 
    bdd11 = Cudd_bddOr(gbm,bdd11,bdd8);
    bdd = Cudd_bddAnd(gbm,bdd,bdd11);
    */
    DdNode* bdd71;
   
    bdd71 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd71); /*Increases the reference count of a node*/

     for (i = 16; i < 18; i++) {  
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd71); 
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd71);
      bdd71 = tmp;
    }
    
    
    bdd = Cudd_bddAnd(gbm,bdd,bdd71);
    Cudd_Ref(bdd);

    return bdd;

    

}


DdNode* scrivi_bdd_zerocoap (DdManager *gbm, DdNode *bdd, DdNode * var) {

     DdNode* bdd_rec[128];
     DdNode* bdd_rec2[128];
     DdNode* bdd_rec3[128];
     DdNode* bdd_rec4[128];

     DdNode *bdd1, *bdd2, *bdd3, *bdd4, *bdd5, *bdd6, *bdd7, *bdd8, *bdd9,*tmp,*tmp_neg, *bdd10,*bdd11,*bdd12,*bdd13,*bdd14,*bdd15,*bdd16,*bdd17,*bdd18,*bdd19,*bdd20,
	    *bdd21,*bdd22,*bdd23,*bdd24,*bdd25,*bdd26,*bdd27,*bdd28,*bdd29,*bdd30,
	    *bdd31,*bdd32,*bdd33,*bdd34,*bdd35,*bdd36,*bdd37,*bdd38,*bdd39,*bdd40
,*bdd41,*bdd42,*bdd43,*bdd44,*bdd45,*bdd46,*bdd47,*bdd48,*bdd49,*bdd50,*bdd51,*bdd52,*bdd53,*bdd54,*bdd55,*bdd56,*bdd57,*bdd58,*bdd59,*bdd60,*bdd61,*bdd62,*bdd63,*bdd64,*bdd65,*bdd66,*bdd67,*bdd68,*bdd69,*bdd70,*bdd71,*bdd72,*bdd73,*bdd74,*bdd75,*bdd76,*bdd77,*bdd78,*bdd79,*bdd80;
     bdd = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd); /*Increases the reference count of a node*/
     int i; 
     
     for(i = 0; i < 128; i++){
     bdd_rec[i] = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd_rec[i]); /*Increases the reference count of a node*/
     } 
     for(i = 0; i < 128; i++){
     bdd_rec2[i] = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd_rec2[i]); /*Increases the reference count of a node*/
     } 
     for(i = 0; i < 128; i++){
     bdd_rec3[i] = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd_rec3[i]); /*Increases the reference count of a node*/
     } 
     for(i = 0; i < 128; i++){
     bdd_rec4[i] = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd_rec4[i]); /*Increases the reference count of a node*/
     } 
     
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
     bdd6 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd6); /*Increases the reference count of a node*/
     bdd7 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd7); /*Increases the reference count of a node*/
     bdd8 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd8); /*Increases the reference count of a node*/
     bdd9 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd9); /*Increases the reference count of a node*/
     bdd10 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd10); /*Increases the reference count of a node*/
     bdd11 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd11); /*Increases the reference count of a node*/
     bdd12 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd12); /*Increases the reference count of a node*/
     bdd13 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd13); /*Increases the reference count of a node*/
     bdd14 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd14); /*Increases the reference count of a node*/
     bdd15 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd15); /*Increases the reference count of a node*/
     bdd16 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd16); /*Increases the reference count of a node*/
     bdd17 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd17); /*Increases the reference count of a node*/
     bdd18 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd18); /*Increases the reference count of a node*/
     bdd19 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd19); /*Increases the reference count of a node*/
     bdd20 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd20); /*Increases the reference count of a node*/
     bdd21 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd21); /*Increases the reference count of a node*/
     bdd22 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd22); /*Increases the reference count of a node*/
     bdd23 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd23); /*Increases the reference count of a node*/
     bdd24 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd24); /*Increases the reference count of a node*/
     bdd25 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd25); /*Increases the reference count of a node*/
     bdd26 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd26); /*Increases the reference count of a node*/
     bdd27 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd27); /*Increases the reference count of a node*/
     bdd28 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd28); /*Increases the reference count of a node*/
     bdd29 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd29); /*Increases the reference count of a node*/
     bdd30 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd30); /*Increases the reference count of a node*/
     bdd31 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd31); /*Increases the reference count of a node*/
     bdd32 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd32); /*Increases the reference count of a node*/
     bdd33 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd33); /*Increases the reference count of a node*/
     bdd34 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd34); /*Increases the reference count of a node*/
     bdd35 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd35); /*Increases the reference count of a node*/
     bdd36 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd36); /*Increases the reference count of a node*/
     bdd37 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd37); /*Increases the reference count of a node*/
     bdd38 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd38); /*Increases the reference count of a node*/
     bdd39 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd39); /*Increases the reference count of a node*/
     bdd40 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd40); /*Increases the reference count of a node*/
     bdd41 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd41); /*Increases the reference count of a node*/
     bdd42 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd42); /*Increases the reference count of a node*/
     bdd43 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd43); /*Increases the reference count of a node*/
     bdd44 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd44); /*Increases the reference count of a node*/
     bdd45 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd45); /*Increases the reference count of a node*/
     bdd46 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd46); /*Increases the reference count of a node*/
     bdd47 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd47); /*Increases the reference count of a node*/
     bdd48 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd48); /*Increases the reference count of a node*/
     bdd49 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd49); /*Increases the reference count of a node*/
     bdd50 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd50); /*Increases the reference count of a node*/
     bdd51 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd51); /*Increases the reference count of a node*/
     bdd52 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd52); /*Increases the reference count of a node*/
     bdd53 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd53); /*Increases the reference count of a node*/
     bdd54 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd54); /*Increases the reference count of a node*/
     bdd55 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd55); /*Increases the reference count of a node*/
     bdd56 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd56); /*Increases the reference count of a node*/
     bdd57 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd57); /*Increases the reference count of a node*/
     bdd58 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd58); /*Increases the reference count of a node*/
     bdd59 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd59); /*Increases the reference count of a node*/
     bdd60 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd60); /*Increases the reference count of a node*/
     bdd61 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd61); /*Increases the reference count of a node*/
     bdd62 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd62); /*Increases the reference count of a node*/
     bdd63 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd63); /*Increases the reference count of a node*/
     bdd64 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd64); /*Increases the reference count of a node*/
     bdd65 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd65); /*Increases the reference count of a node*/
     bdd66 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd66); /*Increases the reference count of a node*/
     bdd67 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd67); /*Increases the reference count of a node*/
     bdd68 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd68); /*Increases the reference count of a node*/
     bdd69 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd69); /*Increases the reference count of a node*/
     bdd70 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd70); /*Increases the reference count of a node*/
     bdd71 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd71); /*Increases the reference count of a node*/
     bdd72 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd72); /*Increases the reference count of a node*/
     bdd73 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd73); /*Increases the reference count of a node*/
     bdd74 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd74); /*Increases the reference count of a node*/
     bdd75 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd75); /*Increases the reference count of a node*/
     bdd76 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd76); /*Increases the reference count of a node*/
     bdd77 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd77); /*Increases the reference count of a node*/
     bdd80 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd80); /*Increases the reference count of a node*/
     bdd78 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd78); /*Increases the reference count of a node*/
     bdd79 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd79); /*Increases the reference count of a node*/
  
     for (i = 0; i < 8; i++) {
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
     if(i != 1 ) {
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
     
    
    for (i = 0; i < 8; i++) {
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
      tmp_neg = Cudd_Not(var); /*Perform NOT Boolean operation*/
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd74); /*Perform AND Boolean operation*/
      
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd74);
      bdd74 = tmp;
    }

    bdd = Cudd_bddOr(gbm,bdd,bdd74);
    Cudd_Ref(bdd);
    
    for (i = 0; i < 8; i++) {
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
     if(i != 7 ) {
      tmp_neg = Cudd_Not(var); /*Perform NOT Boolean operation*/
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd75); /*Perform AND Boolean operation*/
      }else{
      tmp = Cudd_bddAnd(gbm,var,bdd75); /*Perform AND Boolean operation*/
     }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd75);
      bdd75 = tmp;
    }

    bdd = Cudd_bddOr(gbm,bdd,bdd75);
    Cudd_Ref(bdd);
    
    for (i = 0; i < 8; i++) {
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
     if(i != 6 ) {
      tmp_neg = Cudd_Not(var); /*Perform NOT Boolean operation*/
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd76); /*Perform AND Boolean operation*/
      }else{
      tmp = Cudd_bddAnd(gbm,var,bdd76); /*Perform AND Boolean operation*/
     }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd76);
      bdd76 = tmp;
    }

    bdd = Cudd_bddOr(gbm,bdd,bdd76);
    Cudd_Ref(bdd);

    for (i = 0; i < 8; i++) {
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
     if(i != 6 && i != 7 ) {
      tmp_neg = Cudd_Not(var); /*Perform NOT Boolean operation*/
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd77); /*Perform AND Boolean operation*/
      }else{
      tmp = Cudd_bddAnd(gbm,var,bdd77); /*Perform AND Boolean operation*/
     }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd77);
      bdd77 = tmp;
    }

    bdd = Cudd_bddOr(gbm,bdd,bdd77);
    Cudd_Ref(bdd);

    for (i = 0; i < 8; i++) {
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
     if(i != 5 ) {
      tmp_neg = Cudd_Not(var); /*Perform NOT Boolean operation*/
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd78); /*Perform AND Boolean operation*/
      }else{
      tmp = Cudd_bddAnd(gbm,var,bdd78); /*Perform AND Boolean operation*/
     }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd78);
      bdd78 = tmp;
    }

    bdd = Cudd_bddOr(gbm,bdd,bdd78);
    Cudd_Ref(bdd);

    for (i = 0; i < 8; i++) {
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
     if(i != 5 && i != 7 ) {
      tmp_neg = Cudd_Not(var); /*Perform NOT Boolean operation*/
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd79); /*Perform AND Boolean operation*/
      }else{
      tmp = Cudd_bddAnd(gbm,var,bdd79); /*Perform AND Boolean operation*/
     }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd79);
      bdd79 = tmp;
    }

    bdd = Cudd_bddOr(gbm,bdd,bdd79);
    Cudd_Ref(bdd);


    for (i = 0; i < 8; i++) {
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
     if(i != 1 && i != 7 ) {
      tmp_neg = Cudd_Not(var); /*Perform NOT Boolean operation*/
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd1); /*Perform AND Boolean operation*/
      }else{
      tmp = Cudd_bddAnd(gbm,var,bdd1); /*Perform AND Boolean operation*/
     }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd1);
      bdd1 = tmp;
    }

    bdd = Cudd_bddOr(gbm,bdd,bdd1);
    Cudd_Ref(bdd);

    for (i = 0; i < 8; i++) {
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
     if(i != 1 && i != 6 ) {
      tmp_neg = Cudd_Not(var); /*Perform NOT Boolean operation*/
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd2); /*Perform AND Boolean operation*/
      }else{
      tmp = Cudd_bddAnd(gbm,var,bdd2); /*Perform AND Boolean operation*/
     }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd2);
      bdd2 = tmp;
    }

    bdd = Cudd_bddOr(gbm,bdd,bdd2);
    Cudd_Ref(bdd);

    for (i = 0; i < 8; i++) {
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
     if(i != 1 && i != 6 && i != 7) {
      tmp_neg = Cudd_Not(var); /*Perform NOT Boolean operation*/
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd3); /*Perform AND Boolean operation*/
      }else{
      tmp = Cudd_bddAnd(gbm,var,bdd3); /*Perform AND Boolean operation*/
     }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd3);
      bdd3 = tmp;
    }

    bdd = Cudd_bddOr(gbm,bdd,bdd3);
    Cudd_Ref(bdd);

    for (i = 0; i < 8; i++) {
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
     if(i != 1 && i != 5 ) {
      tmp_neg = Cudd_Not(var); /*Perform NOT Boolean operation*/
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd4); /*Perform AND Boolean operation*/
      }else{
      tmp = Cudd_bddAnd(gbm,var,bdd4); /*Perform AND Boolean operation*/
     }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd4);
      bdd4 = tmp;
    }

    bdd = Cudd_bddOr(gbm,bdd,bdd4);
    Cudd_Ref(bdd);
    
    for (i = 0; i < 8; i++) {
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
     if(i != 1 && i != 5 && i != 7) {
      tmp_neg = Cudd_Not(var); /*Perform NOT Boolean operation*/
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd5); /*Perform AND Boolean operation*/
      }else{
      tmp = Cudd_bddAnd(gbm,var,bdd5); /*Perform AND Boolean operation*/
     }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd5);
      bdd5 = tmp;
    }

    bdd = Cudd_bddOr(gbm,bdd,bdd5);
    Cudd_Ref(bdd);
    
    for (i = 0; i < 8; i++) {
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
     if(i != 1 && i != 5 && i != 6) {
      tmp_neg = Cudd_Not(var); /*Perform NOT Boolean operation*/
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd6); /*Perform AND Boolean operation*/
      }else{
      tmp = Cudd_bddAnd(gbm,var,bdd6); /*Perform AND Boolean operation*/
     }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd6);
      bdd6 = tmp;
    }

    bdd = Cudd_bddOr(gbm,bdd,bdd6);
    Cudd_Ref(bdd);
    
    for (i = 0; i < 8; i++) {
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
     if(i != 1 && i != 5 && i != 7 && i != 6) {
      tmp_neg = Cudd_Not(var); /*Perform NOT Boolean operation*/
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd7); /*Perform AND Boolean operation*/
      }else{
      tmp = Cudd_bddAnd(gbm,var,bdd7); /*Perform AND Boolean operation*/
     }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd7);
      bdd7 = tmp;
    }

    bdd = Cudd_bddOr(gbm,bdd,bdd7);
    Cudd_Ref(bdd);

    for (i = 0; i < 8; i++) {
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
     if(i != 1 && i != 4) {
      tmp_neg = Cudd_Not(var); /*Perform NOT Boolean operation*/
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd8); /*Perform AND Boolean operation*/
      }else{
      tmp = Cudd_bddAnd(gbm,var,bdd8); /*Perform AND Boolean operation*/
     }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd8);
      bdd8 = tmp;
    }

    bdd = Cudd_bddOr(gbm,bdd,bdd8);
    Cudd_Ref(bdd);


    for (i = 0; i < 8; i++) {
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
     if(i != 1 && i != 4 && i != 7) {
      tmp_neg = Cudd_Not(var); /*Perform NOT Boolean operation*/
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd9); /*Perform AND Boolean operation*/
      }else{
      tmp = Cudd_bddAnd(gbm,var,bdd9); /*Perform AND Boolean operation*/
     }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd9);
      bdd9 = tmp;
    }

    bdd = Cudd_bddOr(gbm,bdd,bdd9);
    Cudd_Ref(bdd);


    for (i = 0; i < 8; i++) {
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
     if(i != 1 && i != 3) {
      tmp_neg = Cudd_Not(var); /*Perform NOT Boolean operation*/
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd10); /*Perform AND Boolean operation*/
      }else{
      tmp = Cudd_bddAnd(gbm,var,bdd10); /*Perform AND Boolean operation*/
     }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd10);
      bdd10 = tmp;
    }

    bdd = Cudd_bddOr(gbm,bdd,bdd10);
    Cudd_Ref(bdd);
    
    
    for (i = 0; i < 8; i++) {
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
     if(i != 1 && i != 3 && i != 7) {
      tmp_neg = Cudd_Not(var); /*Perform NOT Boolean operation*/
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd11); /*Perform AND Boolean operation*/
      }else{
      tmp = Cudd_bddAnd(gbm,var,bdd11); /*Perform AND Boolean operation*/
     }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd11);
      bdd11 = tmp;
    }

    bdd = Cudd_bddOr(gbm,bdd,bdd11);
    Cudd_Ref(bdd);


    for (i = 0; i < 8; i++) {
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
     if(i != 1 && i != 3 && i != 6) {
      tmp_neg = Cudd_Not(var); /*Perform NOT Boolean operation*/
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd12); /*Perform AND Boolean operation*/
      }else{
      tmp = Cudd_bddAnd(gbm,var,bdd12); /*Perform AND Boolean operation*/
     }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd12);
      bdd12 = tmp;
    }

    bdd = Cudd_bddOr(gbm,bdd,bdd12);
    Cudd_Ref(bdd);

    for (i = 0; i < 8; i++) {
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
     if(i != 1 && i != 3 && i != 6 && i != 7) {
      tmp_neg = Cudd_Not(var); /*Perform NOT Boolean operation*/
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd13); /*Perform AND Boolean operation*/
      }else{
      tmp = Cudd_bddAnd(gbm,var,bdd13); /*Perform AND Boolean operation*/
     }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd13);
      bdd13 = tmp;
    }

    bdd = Cudd_bddOr(gbm,bdd,bdd13);
    Cudd_Ref(bdd);


    for (i = 0; i < 8; i++) {
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
     if(i != 1 && i != 3 && i != 5) {
      tmp_neg = Cudd_Not(var); /*Perform NOT Boolean operation*/
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd14); /*Perform AND Boolean operation*/
      }else{
      tmp = Cudd_bddAnd(gbm,var,bdd14); /*Perform AND Boolean operation*/
     }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd14);
      bdd14 = tmp;
    }

    bdd = Cudd_bddOr(gbm,bdd,bdd14);
    Cudd_Ref(bdd);


    for (i = 0; i < 8; i++) {
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
     if(i != 1 && i != 3 && i != 5 && i != 7) {
      tmp_neg = Cudd_Not(var); /*Perform NOT Boolean operation*/
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd15); /*Perform AND Boolean operation*/
      }else{
      tmp = Cudd_bddAnd(gbm,var,bdd15); /*Perform AND Boolean operation*/
     }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd15);
      bdd15 = tmp;
    }

    bdd = Cudd_bddOr(gbm,bdd,bdd15);
    Cudd_Ref(bdd);


    for (i = 0; i < 8; i++) {
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
     if(i != 1 && i != 3 && i != 5 && i != 6) {
      tmp_neg = Cudd_Not(var); /*Perform NOT Boolean operation*/
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd16); /*Perform AND Boolean operation*/
      }else{
      tmp = Cudd_bddAnd(gbm,var,bdd16); /*Perform AND Boolean operation*/
     }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd16);
      bdd16 = tmp;
    }

    bdd = Cudd_bddOr(gbm,bdd,bdd16);
    Cudd_Ref(bdd);


    for (i = 0; i < 8; i++) {
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
     if(i != 1 && i != 3 && i != 5 && i != 7 && i != 6) {
      tmp_neg = Cudd_Not(var); /*Perform NOT Boolean operation*/
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd17); /*Perform AND Boolean operation*/
      }else{
      tmp = Cudd_bddAnd(gbm,var,bdd17); /*Perform AND Boolean operation*/
     }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd17);
      bdd17 = tmp;
    }

    bdd = Cudd_bddOr(gbm,bdd,bdd17);
    Cudd_Ref(bdd);



    for (i = 0; i < 8; i++) {
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
     if(i != 1 && i != 3 && i != 4) {
      tmp_neg = Cudd_Not(var); /*Perform NOT Boolean operation*/
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd18); /*Perform AND Boolean operation*/
      }else{
      tmp = Cudd_bddAnd(gbm,var,bdd18); /*Perform AND Boolean operation*/
     }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd18);
      bdd18 = tmp;
    }

    bdd = Cudd_bddOr(gbm,bdd,bdd18);
    Cudd_Ref(bdd);

    for (i = 0; i < 8; i++) {
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
     if(i != 1 && i != 3 && i != 4 && i != 7) {
      tmp_neg = Cudd_Not(var); /*Perform NOT Boolean operation*/
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd19); /*Perform AND Boolean operation*/
      }else{
      tmp = Cudd_bddAnd(gbm,var,bdd19); /*Perform AND Boolean operation*/
     }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd19);
      bdd19 = tmp;
    }

    bdd = Cudd_bddOr(gbm,bdd,bdd19);
    Cudd_Ref(bdd);

    for (i = 0; i < 8; i++) {
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
     if(i != 1 && i != 2) {
      tmp_neg = Cudd_Not(var); /*Perform NOT Boolean operation*/
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd21); /*Perform AND Boolean operation*/
      }else{
      tmp = Cudd_bddAnd(gbm,var,bdd21); /*Perform AND Boolean operation*/
     }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd21);
      bdd21 = tmp;
    }

    bdd = Cudd_bddOr(gbm,bdd,bdd21);
    Cudd_Ref(bdd);

    
    for (i = 0; i < 8; i++) {
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
     if(i != 1 && i != 2 && i != 7) {
      tmp_neg = Cudd_Not(var); /*Perform NOT Boolean operation*/
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd22); /*Perform AND Boolean operation*/
      }else{
      tmp = Cudd_bddAnd(gbm,var,bdd22); /*Perform AND Boolean operation*/
     }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd22);
      bdd22 = tmp;
    }

    bdd = Cudd_bddOr(gbm,bdd,bdd22);
    Cudd_Ref(bdd);


    for (i = 0; i < 8; i++) {
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
     if(i != 1 && i != 2 && i != 6) {
      tmp_neg = Cudd_Not(var); /*Perform NOT Boolean operation*/
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd23); /*Perform AND Boolean operation*/
      }else{
      tmp = Cudd_bddAnd(gbm,var,bdd23); /*Perform AND Boolean operation*/
     }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd23);
      bdd23 = tmp;
    }

    bdd = Cudd_bddOr(gbm,bdd,bdd23);
    Cudd_Ref(bdd);


    for (i = 0; i < 8; i++) {
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
     if(i != 1 && i != 2 && i != 6 && i != 7) {
      tmp_neg = Cudd_Not(var); /*Perform NOT Boolean operation*/
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd24); /*Perform AND Boolean operation*/
      }else{
      tmp = Cudd_bddAnd(gbm,var,bdd24); /*Perform AND Boolean operation*/
     }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd24);
      bdd24 = tmp;
    }

    bdd = Cudd_bddOr(gbm,bdd,bdd24);
    Cudd_Ref(bdd);


    for (i = 0; i < 8; i++) {
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
     if(i != 1 && i != 2 && i != 5) {
      tmp_neg = Cudd_Not(var); /*Perform NOT Boolean operation*/
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd25); /*Perform AND Boolean operation*/
      }else{
      tmp = Cudd_bddAnd(gbm,var,bdd25); /*Perform AND Boolean operation*/
     }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd25);
      bdd25 = tmp;
    }

    bdd = Cudd_bddOr(gbm,bdd,bdd25);
    Cudd_Ref(bdd);


    for (i = 0; i < 8; i++) {
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
     if(i != 1 && i != 2 && i != 5 && i != 7) {
      tmp_neg = Cudd_Not(var); /*Perform NOT Boolean operation*/
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd26); /*Perform AND Boolean operation*/
      }else{
      tmp = Cudd_bddAnd(gbm,var,bdd26); /*Perform AND Boolean operation*/
     }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd26);
      bdd26 = tmp;
    }

    bdd = Cudd_bddOr(gbm,bdd,bdd26);
    Cudd_Ref(bdd);


    for (i = 0; i < 8; i++) {
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
     if(i != 1 && i != 2 && i != 5 && i != 6) {
      tmp_neg = Cudd_Not(var); /*Perform NOT Boolean operation*/
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd27); /*Perform AND Boolean operation*/
      }else{
      tmp = Cudd_bddAnd(gbm,var,bdd27); /*Perform AND Boolean operation*/
     }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd27);
      bdd27 = tmp;
    }

    bdd = Cudd_bddOr(gbm,bdd,bdd27);
    Cudd_Ref(bdd);

    for (i = 0; i < 8; i++) {
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
     if(i != 1 && i != 2 && i != 5 && i != 6 && i != 7) {
      tmp_neg = Cudd_Not(var); /*Perform NOT Boolean operation*/
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd28); /*Perform AND Boolean operation*/
      }else{
      tmp = Cudd_bddAnd(gbm,var,bdd28); /*Perform AND Boolean operation*/
     }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd28);
      bdd28 = tmp;
    }

    bdd = Cudd_bddOr(gbm,bdd,bdd28);
    Cudd_Ref(bdd);



    for (i = 0; i < 8; i++) {
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
     if(i != 1 && i != 2 && i != 4) {
      tmp_neg = Cudd_Not(var); /*Perform NOT Boolean operation*/
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd29); /*Perform AND Boolean operation*/
      }else{
      tmp = Cudd_bddAnd(gbm,var,bdd29); /*Perform AND Boolean operation*/
     }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd29);
      bdd29 = tmp;
    }

    bdd = Cudd_bddOr(gbm,bdd,bdd29);
    Cudd_Ref(bdd);


    for (i = 0; i < 8; i++) {
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
     if(i != 1 && i != 2 && i != 4 && i != 7) {
      tmp_neg = Cudd_Not(var); /*Perform NOT Boolean operation*/
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd30); /*Perform AND Boolean operation*/
      }else{
      tmp = Cudd_bddAnd(gbm,var,bdd30); /*Perform AND Boolean operation*/
     }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd30);
      bdd30 = tmp;
    }

    bdd = Cudd_bddOr(gbm,bdd,bdd30);
    Cudd_Ref(bdd);

    for (i = 0; i < 8; i++) {
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
     if(i != 1 && i != 2 && i != 3) {
      tmp_neg = Cudd_Not(var); /*Perform NOT Boolean operation*/
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd31); /*Perform AND Boolean operation*/
      }else{
      tmp = Cudd_bddAnd(gbm,var,bdd31); /*Perform AND Boolean operation*/
     }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd31);
      bdd31 = tmp;
    }

    bdd = Cudd_bddOr(gbm,bdd,bdd31);
    Cudd_Ref(bdd);

    for (i = 0; i < 8; i++) {
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
     if(i != 1 && i != 2 && i != 3 & i != 7) {
      tmp_neg = Cudd_Not(var); /*Perform NOT Boolean operation*/
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd32); /*Perform AND Boolean operation*/
      }else{
      tmp = Cudd_bddAnd(gbm,var,bdd32); /*Perform AND Boolean operation*/
     }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd32);
      bdd32 = tmp;
    }

    bdd = Cudd_bddOr(gbm,bdd,bdd32);
    Cudd_Ref(bdd);

    for (i = 0; i < 8; i++) {
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
     if(i != 1 && i != 2 && i != 3 && i != 6) {
      tmp_neg = Cudd_Not(var); /*Perform NOT Boolean operation*/
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd32); /*Perform AND Boolean operation*/
      }else{
      tmp = Cudd_bddAnd(gbm,var,bdd32); /*Perform AND Boolean operation*/
     }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd32);
      bdd32 = tmp;
    }

    bdd = Cudd_bddOr(gbm,bdd,bdd32);
    Cudd_Ref(bdd);


    for (i = 0; i < 8; i++) {
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
     if(i != 1 && i != 2 && i != 3 && i != 6 && i != 7) {
      tmp_neg = Cudd_Not(var); /*Perform NOT Boolean operation*/
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd33); /*Perform AND Boolean operation*/
      }else{
      tmp = Cudd_bddAnd(gbm,var,bdd33); /*Perform AND Boolean operation*/
     }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd33);
      bdd33 = tmp;
    }

    bdd = Cudd_bddOr(gbm,bdd,bdd33);
    Cudd_Ref(bdd);



    for (i = 0; i < 8; i++) {
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
     if(i != 1 && i != 2 && i != 3 && i != 5) {
      tmp_neg = Cudd_Not(var); /*Perform NOT Boolean operation*/
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd34); /*Perform AND Boolean operation*/
      }else{
      tmp = Cudd_bddAnd(gbm,var,bdd34); /*Perform AND Boolean operation*/
     }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd34);
      bdd34 = tmp;
    }

    bdd = Cudd_bddOr(gbm,bdd,bdd34);
    Cudd_Ref(bdd);
    
    
    for (i = 0; i < 8; i++) {
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
     if(i != 1 && i != 2 && i != 3 && i != 5 && i != 7) {
      tmp_neg = Cudd_Not(var); /*Perform NOT Boolean operation*/
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd35); /*Perform AND Boolean operation*/
      }else{
      tmp = Cudd_bddAnd(gbm,var,bdd35); /*Perform AND Boolean operation*/
     }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd35);
      bdd35 = tmp;
    }

    bdd = Cudd_bddOr(gbm,bdd,bdd35);
    Cudd_Ref(bdd);

    for (i = 0; i < 8; i++) {
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
     if(i != 1 && i != 2 && i != 3 && i != 5 && i != 6) {
      tmp_neg = Cudd_Not(var); /*Perform NOT Boolean operation*/
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd36); /*Perform AND Boolean operation*/
      }else{
      tmp = Cudd_bddAnd(gbm,var,bdd36); /*Perform AND Boolean operation*/
     }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd36);
      bdd36 = tmp;
    }

    bdd = Cudd_bddOr(gbm,bdd,bdd36);
    Cudd_Ref(bdd);

    for (i = 0; i < 8; i++) {
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
     if(i != 1 && i != 2 && i != 3 && i != 5 && i != 7 && i != 6) {
      tmp_neg = Cudd_Not(var); /*Perform NOT Boolean operation*/
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd37); /*Perform AND Boolean operation*/
      }else{
      tmp = Cudd_bddAnd(gbm,var,bdd37); /*Perform AND Boolean operation*/
     }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd37);
      bdd37 = tmp;
    }

    bdd = Cudd_bddOr(gbm,bdd,bdd37);
    Cudd_Ref(bdd);

    for (i = 0; i < 8; i++) {
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
     if(i != 1 && i != 2 && i != 3 && i != 4) {
      tmp_neg = Cudd_Not(var); /*Perform NOT Boolean operation*/
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd38); /*Perform AND Boolean operation*/
      }else{
      tmp = Cudd_bddAnd(gbm,var,bdd38); /*Perform AND Boolean operation*/
     }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd38);
      bdd38 = tmp;
    }

    bdd = Cudd_bddOr(gbm,bdd,bdd38);
    Cudd_Ref(bdd);

    for (i = 8; i < 16; i++) {
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
      tmp_neg = Cudd_Not(var); /*Perform NOT Boolean operation*/
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd39); /*Perform AND Boolean operation*/
    
     
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd39);
      bdd39 = tmp;
    }

   for (i = 8; i < 16; i++) {
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
     if (i != 15) { 
     tmp_neg = Cudd_Not(var); /*Perform NOT Boolean operation*/
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd40); /*Perform AND Boolean operation*/
     }else{
      tmp = Cudd_bddAnd(gbm,var,bdd40); /*Perform AND Boolean operation*/
     }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd40);
      bdd40 = tmp;
    }

    bdd50 = Cudd_bddOr(gbm,bdd39,bdd40);
    

    for (i = 8; i < 16; i++) {
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
     if (i != 14) { 
     tmp_neg = Cudd_Not(var); /*Perform NOT Boolean operation*/
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd41); /*Perform AND Boolean operation*/
     }else{
      tmp = Cudd_bddAnd(gbm,var,bdd41); /*Perform AND Boolean operation*/
     }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd41);
      bdd41 = tmp;
    }

    bdd50 = Cudd_bddOr(gbm,bdd50,bdd41);
    
 
    for (i = 8; i < 16; i++) {
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
     if (i != 14 && i != 15) { 
     tmp_neg = Cudd_Not(var); /*Perform NOT Boolean operation*/
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd42); /*Perform AND Boolean operation*/
     }else{
      tmp = Cudd_bddAnd(gbm,var,bdd42); /*Perform AND Boolean operation*/
     }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd42);
      bdd42 = tmp;
    }

    bdd50 = Cudd_bddOr(gbm,bdd50,bdd42);
    
    for (i = 8; i < 16; i++) {
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
     if (i != 13) { 
     tmp_neg = Cudd_Not(var); /*Perform NOT Boolean operation*/
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd43); /*Perform AND Boolean operation*/
     }else{
      tmp = Cudd_bddAnd(gbm,var,bdd43); /*Perform AND Boolean operation*/
     }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd43);
      bdd43 = tmp;
    }

    bdd50 = Cudd_bddOr(gbm,bdd50,bdd43);
     
    for (i = 8; i < 16; i++) {
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
     if (i != 9 && i != 15) { 
     tmp_neg = Cudd_Not(var); /*Perform NOT Boolean operation*/
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd44); /*Perform AND Boolean operation*/
     }else{
      tmp = Cudd_bddAnd(gbm,var,bdd44); /*Perform AND Boolean operation*/
     }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd44);
      bdd44 = tmp;
    }

    bdd50 = Cudd_bddOr(gbm,bdd50,bdd44);
       
    for (i = 8; i < 16; i++) {
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
     if (i != 9 && i != 14) { 
     tmp_neg = Cudd_Not(var); /*Perform NOT Boolean operation*/
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd45); /*Perform AND Boolean operation*/
     }else{
      tmp = Cudd_bddAnd(gbm,var,bdd45); /*Perform AND Boolean operation*/
     }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd45);
      bdd45 = tmp;
    }

    bdd50 = Cudd_bddOr(gbm,bdd50,bdd45);


    for (i = 8; i < 16; i++) {
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
     if (i != 9 && i != 14 && i != 15) { 
     tmp_neg = Cudd_Not(var); /*Perform NOT Boolean operation*/
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd46); /*Perform AND Boolean operation*/
     }else{
      tmp = Cudd_bddAnd(gbm,var,bdd46); /*Perform AND Boolean operation*/
     }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd46);
      bdd46 = tmp;
    }

    bdd50 = Cudd_bddOr(gbm,bdd50,bdd46);


    for (i = 8; i < 16; i++) {
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
     if (i != 9 && i != 13) { 
     tmp_neg = Cudd_Not(var); /*Perform NOT Boolean operation*/
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd46); /*Perform AND Boolean operation*/
     }else{
      tmp = Cudd_bddAnd(gbm,var,bdd46); /*Perform AND Boolean operation*/
     }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd46);
      bdd46 = tmp;
    }

    bdd50 = Cudd_bddOr(gbm,bdd50,bdd46);
    
    for (i = 8; i < 16; i++) {
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
     if (i != 9 && i != 13 && i != 15) { 
     tmp_neg = Cudd_Not(var); /*Perform NOT Boolean operation*/
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd47); /*Perform AND Boolean operation*/
     }else{
      tmp = Cudd_bddAnd(gbm,var,bdd47); /*Perform AND Boolean operation*/
     }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd47);
      bdd47 = tmp;
    }

    bdd50 = Cudd_bddOr(gbm,bdd50,bdd47);
    
    for (i = 8; i < 16; i++) {
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
     if (i != 8 ) { 
     tmp_neg = Cudd_Not(var); /*Perform NOT Boolean operation*/
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd48); /*Perform AND Boolean operation*/
     }else{
      tmp = Cudd_bddAnd(gbm,var,bdd48); /*Perform AND Boolean operation*/
     }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd48);
      bdd48 = tmp;
    }

    bdd50 = Cudd_bddOr(gbm,bdd50,bdd48);
    
    
    for (i = 8; i < 16; i++) {
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
     if (i != 8 && i != 15) { 
     tmp_neg = Cudd_Not(var); /*Perform NOT Boolean operation*/
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd49); /*Perform AND Boolean operation*/
     }else{
      tmp = Cudd_bddAnd(gbm,var,bdd49); /*Perform AND Boolean operation*/
     }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd49);
      bdd49 = tmp;
    }
    
    bdd50 = Cudd_bddOr(gbm,bdd50,bdd49);
    
     for (i = 8; i < 16; i++) {
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
     if (i != 8 && i != 14) { 
     tmp_neg = Cudd_Not(var); /*Perform NOT Boolean operation*/
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd51); /*Perform AND Boolean operation*/
     }else{
      tmp = Cudd_bddAnd(gbm,var,bdd51); /*Perform AND Boolean operation*/
     }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd51);
      bdd51 = tmp;
    }
    
    bdd50 = Cudd_bddOr(gbm,bdd50,bdd51);
    
     for (i = 8; i < 16; i++) {
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
     if (i != 8 && i!= 14 && i != 15) { 
     tmp_neg = Cudd_Not(var); /*Perform NOT Boolean operation*/
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd52); /*Perform AND Boolean operation*/
     }else{
      tmp = Cudd_bddAnd(gbm,var,bdd52); /*Perform AND Boolean operation*/
     }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd52);
      bdd52 = tmp;
    }
    
    bdd50 = Cudd_bddOr(gbm,bdd50,bdd52);
    
     for (i = 8; i < 16; i++) {
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
     if (i != 8 && i!= 13) { 
     tmp_neg = Cudd_Not(var); /*Perform NOT Boolean operation*/
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd53); /*Perform AND Boolean operation*/
     }else{
      tmp = Cudd_bddAnd(gbm,var,bdd53); /*Perform AND Boolean operation*/
     }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd53);
      bdd53 = tmp;
    }
    
    bdd50 = Cudd_bddOr(gbm,bdd50,bdd53);
    
     for (i = 8; i < 16; i++) {
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
     if (i != 8 && i!= 13 && i != 15) { 
     tmp_neg = Cudd_Not(var); /*Perform NOT Boolean operation*/
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd54); /*Perform AND Boolean operation*/
     }else{
      tmp = Cudd_bddAnd(gbm,var,bdd54); /*Perform AND Boolean operation*/
     }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd54);
      bdd54 = tmp;
    }
    
    bdd50 = Cudd_bddOr(gbm,bdd50,bdd54);
    
     for (i = 8; i < 16; i++) {
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
     if (i != 8 && i!= 14 && i != 13) { 
     tmp_neg = Cudd_Not(var); /*Perform NOT Boolean operation*/
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd55); /*Perform AND Boolean operation*/
     }else{
      tmp = Cudd_bddAnd(gbm,var,bdd55); /*Perform AND Boolean operation*/
     }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd55);
      bdd55 = tmp;
    }
    
    bdd50 = Cudd_bddOr(gbm,bdd50,bdd55);
    
     for (i = 8; i < 16; i++) {
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
     if (i != 8 && i!= 12 && i != 13) { 
     tmp_neg = Cudd_Not(var); /*Perform NOT Boolean operation*/
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd56); /*Perform AND Boolean operation*/
     }else{
      tmp = Cudd_bddAnd(gbm,var,bdd56); /*Perform AND Boolean operation*/
     }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd56);
      bdd56 = tmp;
    }
    
    bdd50 = Cudd_bddOr(gbm,bdd50,bdd56);
    
     for (i = 8; i < 16; i++) {
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
     if (i != 8 && i!= 12 && i != 13 && i != 15) { 
     tmp_neg = Cudd_Not(var); /*Perform NOT Boolean operation*/
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd57); /*Perform AND Boolean operation*/
     }else{
      tmp = Cudd_bddAnd(gbm,var,bdd57); /*Perform AND Boolean operation*/
     }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd57);
      bdd57 = tmp;
    }
    
    bdd50 = Cudd_bddOr(gbm,bdd50,bdd57);
    
     for (i = 8; i < 16; i++) {
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
     if (i != 8 && i != 12 && i!= 13 && i != 14 && i != 15) { 
     tmp_neg = Cudd_Not(var); /*Perform NOT Boolean operation*/
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd58); /*Perform AND Boolean operation*/
     }else{
      tmp = Cudd_bddAnd(gbm,var,bdd58); /*Perform AND Boolean operation*/
     }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd58);
      bdd58 = tmp;
    }
    
    bdd50 = Cudd_bddOr(gbm,bdd50,bdd58);
    
    
     for (i = 8; i < 16; i++) {
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
     if (i != 8 && i!= 10) { 
     tmp_neg = Cudd_Not(var); /*Perform NOT Boolean operation*/
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd59); /*Perform AND Boolean operation*/
     }else{
      tmp = Cudd_bddAnd(gbm,var,bdd59); /*Perform AND Boolean operation*/
     }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd59);
      bdd59 = tmp;
    }
    
    bdd50 = Cudd_bddOr(gbm,bdd50,bdd59);
    
     for (i = 8; i < 16; i++) {
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
     if (i != 8 && i!= 10 && i != 15) { 
     tmp_neg = Cudd_Not(var); /*Perform NOT Boolean operation*/
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd60); /*Perform AND Boolean operation*/
     }else{
      tmp = Cudd_bddAnd(gbm,var,bdd60); /*Perform AND Boolean operation*/
     }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd60);
      bdd60 = tmp;
    }
    
    bdd50 = Cudd_bddOr(gbm,bdd50,bdd60);
     
     for (i = 8; i < 16; i++) {
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
     if (i != 8 && i!= 10 && i != 14) { 
     tmp_neg = Cudd_Not(var); /*Perform NOT Boolean operation*/
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd61); /*Perform AND Boolean operation*/
     }else{
      tmp = Cudd_bddAnd(gbm,var,bdd61); /*Perform AND Boolean operation*/
     }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd61);
      bdd61 = tmp;
    }
    
    bdd50 = Cudd_bddOr(gbm,bdd50,bdd61);
     
     for (i = 8; i < 16; i++) {
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
     if (i != 8 && i!= 10 && i!= 14 && i != 15) { 
     tmp_neg = Cudd_Not(var); /*Perform NOT Boolean operation*/
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd62); /*Perform AND Boolean operation*/
     }else{
      tmp = Cudd_bddAnd(gbm,var,bdd62); /*Perform AND Boolean operation*/
     }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd62);
      bdd62 = tmp;
    }
    
    bdd50 = Cudd_bddOr(gbm,bdd50,bdd62);
     
     for (i = 8; i < 16; i++) {
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
     if (i != 8 && i!= 10 && i != 13) { 
     tmp_neg = Cudd_Not(var); /*Perform NOT Boolean operation*/
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd63); /*Perform AND Boolean operation*/
     }else{
      tmp = Cudd_bddAnd(gbm,var,bdd63); /*Perform AND Boolean operation*/
     }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd63);
      bdd63 = tmp;
    }
    
    bdd50 = Cudd_bddOr(gbm,bdd50,bdd63);
     
     for (i = 8; i < 16; i++) {
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
     if (i != 8 && i!= 10 && i!= 13 && i != 15) { 
     tmp_neg = Cudd_Not(var); /*Perform NOT Boolean operation*/
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd64); /*Perform AND Boolean operation*/
     }else{
      tmp = Cudd_bddAnd(gbm,var,bdd64); /*Perform AND Boolean operation*/
     }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd64);
      bdd64 = tmp;
    }
    
    bdd50 = Cudd_bddOr(gbm,bdd50,bdd64);
    
    bdd = Cudd_bddAnd(gbm,bdd,bdd50);
    Cudd_Ref(bdd);
int j,k;
/*
     for(j = 0;j<128;j++){ 
       for (i = 16; i < 24; i++) {
          var = Cudd_bddIthVar(gbm,i); 
          if(i%8 ==  0) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	  }
	  else if(i == 17+k && j < 64 ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
          }else if(i == 17+k && j >= 64) {
	  tmp = Cudd_bddAnd(gbm, var, bdd_rec[j]); 
          }
	  else if ( (i == 18 + k) && ( ( j < 32 ) || ( j >= 64 && j < 96 ) ) ) {
          tmp_neg = Cudd_Not(var);
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
          } else if ( i == 18 + k && ( ( j >= 32 && j < 64 ) || ( j >= 96 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
	  } else if (i == 19 + k && ( (j<16) || (j>=32 && j<48) || (j>=64 && j<80) || (j>=96 && j<112) ) ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	  } else if (i == 19 + k && ( (j >= 16 && j < 32) || ( j >= 48 && j < 64 ) || ( j >= 80 && j < 96 ) || ( j >= 112 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
          } else if ( i == 20 + k && ( ( j < 8 ) || ( j >= 16 && j < 24) || (j >= 32 && j < 40) || (j>=48 && j<56) || ( j >= 64 && j < 72 ) || 
		    (j >= 80 && j < 88) || (j >= 96 && j < 104) || (j>=112 && j<120) ) ) {
	   tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
           } else if (i == 20 + k && ( ( j >= 8 && j < 16 ) || ( j >= 24 && j < 32 ) || ( j >= 40 && j < 48) || ( j >= 56 && j < 64) 
			|| (j>72 && j<=80) || (j>=88 && j<96) || (j>=104 && j<112) || (j>=120) ) ) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]);  
 	   } else if (i == 21 + k && ( (j < 4) || (j >= 8 && j < 12) || (j >= 16 && j < 20) || (j >= 24 && j < 28) || (j >= 32 && j < 36) || (j >= 40 && j < 44)
			|| (j >= 48 && j < 52)  || (j >= 56 && j < 60)|| (j >= 64 && j < 68) || (j >= 72 && j < 76) || (j >= 80 && j < 84) || (j >= 88 && j < 92) 	
			|| (j >= 96 && j < 100) || (j >= 104 && j < 108) || (j >= 112 && j < 116) || (j >= 120 && j < 124))) {
	   tmp_neg = Cudd_Not(var);
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   
	   } else if (i == 21 + k && ( (j>=4 && j<8) || ( j >= 12 && j < 16 ) || ( j >= 20 && j < 24 ) || ( j >= 28 && j < 32 ) || ( j >= 36 && j < 40 ) 
			|| ( j >= 44 && j < 48 ) || ( j >= 52 && j < 56 ) || ( j >= 60 && j < 64 ) || ( j >= 68 && j < 72 ) || ( j >= 76 && j < 80 ) 	  
		        || ( j >= 84 && j < 88 ) || ( j >= 92 && j < 96 ) || ( j >= 100 && j < 104 ) || ( j >= 108 && j < 112 ) 
			|| ( j >= 116 && j < 120  ) 	|| ( j >= 124 && j < 128 ))) {
          
		   tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
           } else if ( i == 22 + k && ( (j<2) || (j>=4 && j<6)  || (j>=8 && j<10) || (j>=12 && j<14) || (j>=16 && j<18) || (j>=20 && j<22) || (j>=24 && j<26)
			|| (j>=28 && j<30) || (j>=32 && j<34) || (j>=36 && j<38) || (j>=40 && j<42) || (j>=44 && j<46) || (j>=48 && j<50) || (j>=52 && j<54) 	  
			|| (j>=56 && j<58) || (j>=60 && j<62) || (j>=64 && j<66) || (j>=68 && j<70) || (j>=72 && j<74) || (j>=76 && j<78) || (j>=80 && j<82) 
                	|| (j>=84 && j<86) || (j>=88 && j<90) || (j>=92 && j<94) || (j>=96 && j<98) || (j>=100 && j<102) || (j>=104 && j<106) || (j>=108 && j<110) || 
                	(j>=112 && j<114) || (j>=116 && j<118)     || (j>=120 && j<122) || (j>=124 && j<126)
			)) {
	    tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   } else if (i == 22 + k && ( (j>=2 && j<4) || (j>=6 && j<8) || (j>=10 && j<12) || (j>=14 && j<16) || (j>=18 && j<20) || (j>=22 && j<24) || (j>=26 && j<28)
			|| (j>=30 && j<32) || (j>=34 && j<36) || (j>=38 && j<40) || (j>=42 && j<44) || (j>=46 && j<48) || (j>=50 && j<52) 
			|| (j>=54 && j<56) || (j>=58 && j<60) || (j>=62 && j<64) || (j>=66 && j<68) || (j>=70 && j<72) || (j>=74 && j<76) 
			|| (j>=78 && j<80) || (j>=82 && j<84) || (j>=86 && j<88) || (j>=90 && j<92) || (j>=94 && j<96)
                        || (j>=98 && j<100) || (j>=102 && j<104) || (j>=106 && j<108) || (j>=110 && j<112) || (j>=114 && j<116) 
			|| (j>=118 && j<120) || (j>=122 && j<124) || (j>=126 && j<128) )) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 

	   } else if (i == 23 + k && j % 2 == 0) {
	   
	    tmp_neg = Cudd_Not(var); 
	    tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   
	   } else if (i == 23 + k && j % 2 == 1) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 

	   }
	  
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd_rec[j]);
      bdd_rec[j] = tmp;
    }
  }
    
    bdd65 = Cudd_bddOr(gbm,bdd_rec[0],bdd_rec[1]); 
    Cudd_Ref(bdd65);   
    
    for (k = 2;k<128;k++) {
    bdd65 = Cudd_bddOr(gbm,bdd65,bdd_rec[k]);
    Cudd_Ref(bdd65);   
     }


     for(j = 0;j<128;j++){ 
       for (i = 16; i < 24; i++) {
          var = Cudd_bddIthVar(gbm,i); 
          if(i%8 ==  0) {
//          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, var, bdd_rec2[j]); 
	  }
	  else if(i == 17+k && j < 64 ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec2[j]); 
          }else if(i == 17+k && j >= 64) {
	  tmp = Cudd_bddAnd(gbm, var, bdd_rec2[j]); 
          }
	  else if ( (i == 18 + k) && ( ( j < 32 ) || ( j >= 64 && j < 96 ) ) ) {
          tmp_neg = Cudd_Not(var);
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec2[j]); 
          } else if ( i == 18 + k && ( ( j >= 32 && j < 64 ) || ( j >= 96 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec2[j]); 
	  } else if (i == 19 + k && ( (j<16) || (j>=32 && j<48) || (j>=64 && j<80) || (j>=96 && j<112) ) ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec2[j]); 
	  } else if (i == 19 + k && ( (j >= 16 && j < 32) || ( j >= 48 && j < 64 ) || ( j >= 80 && j < 96 ) || ( j >= 112 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec2[j]); 
          } else if ( i == 20 + k && ( ( j < 8 ) || ( j >= 16 && j < 24) || (j >= 32 && j < 40) || (j>=48 && j<56) || ( j >= 64 && j < 72 ) || 
		    (j >= 80 && j < 88) || (j >= 96 && j < 104) || (j>=112 && j<120) ) ) {
	   tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec2[j]); 
           } else if (i == 20 + k && ( ( j >= 8 && j < 16 ) || ( j >= 24 && j < 32 ) || ( j >= 40 && j < 48) || ( j >= 56 && j < 64) 
			|| (j>72 && j<=80) || (j>=88 && j<96) || (j>=104 && j<112) || (j>=120) ) ) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec2[j]);  
 	   } else if (i == 21 + k && ( (j < 4) || (j >= 8 && j < 12) || (j >= 16 && j < 20) || (j >= 24 && j < 28) || (j >= 32 && j < 36) || (j >= 40 && j < 44)
			|| (j >= 48 && j < 52)  || (j >= 56 && j < 60)|| (j >= 64 && j < 68) || (j >= 72 && j < 76) || (j >= 80 && j < 84) || (j >= 88 && j < 92) 	
			|| (j >= 96 && j < 100) || (j >= 104 && j < 108) || (j >= 112 && j < 116) || (j >= 120 && j < 124))) {
	   tmp_neg = Cudd_Not(var);
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec2[j]); 
	   
	   } else if (i == 21 + k && ( (j>=4 && j<8) || ( j >= 12 && j < 16 ) || ( j >= 20 && j < 24 ) || ( j >= 28 && j < 32 ) || ( j >= 36 && j < 40 ) 
			|| ( j >= 44 && j < 48 ) || ( j >= 52 && j < 56 ) || ( j >= 60 && j < 64 ) || ( j >= 68 && j < 72 ) || ( j >= 76 && j < 80 ) 	  
		        || ( j >= 84 && j < 88 ) || ( j >= 92 && j < 96 ) || ( j >= 100 && j < 104 ) || ( j >= 108 && j < 112 ) 
			|| ( j >= 116 && j < 120  ) 	|| ( j >= 124 && j < 128 ))) {
          
		   tmp = Cudd_bddAnd(gbm,var,bdd_rec2[j]); 
           } else if ( i == 22 + k && ( (j<2) || (j>=4 && j<6)  || (j>=8 && j<10) || (j>=12 && j<14) || (j>=16 && j<18) || (j>=20 && j<22) || (j>=24 && j<26)
			|| (j>=28 && j<30) || (j>=32 && j<34) || (j>=36 && j<38) || (j>=40 && j<42) || (j>=44 && j<46) || (j>=48 && j<50) || (j>=52 && j<54) 	  
			|| (j>=56 && j<58) || (j>=60 && j<62) || (j>=64 && j<66) || (j>=68 && j<70) || (j>=72 && j<74) || (j>=76 && j<78) || (j>=80 && j<82) 
                	|| (j>=84 && j<86) || (j>=88 && j<90) || (j>=92 && j<94) || (j>=96 && j<98) || (j>=100 && j<102) || (j>=104 && j<106) || (j>=108 && j<110) || 
                	(j>=112 && j<114) || (j>=116 && j<118)     || (j>=120 && j<122) || (j>=124 && j<126)
			)) {
	    tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec2[j]); 
	   } else if (i == 22 + k && ( (j>=2 && j<4) || (j>=6 && j<8) || (j>=10 && j<12) || (j>=14 && j<16) || (j>=18 && j<20) || (j>=22 && j<24) || (j>=26 && j<28)
			|| (j>=30 && j<32) || (j>=34 && j<36) || (j>=38 && j<40) || (j>=42 && j<44) || (j>=46 && j<48) || (j>=50 && j<52) 
			|| (j>=54 && j<56) || (j>=58 && j<60) || (j>=62 && j<64) || (j>=66 && j<68) || (j>=70 && j<72) || (j>=74 && j<76) 
			|| (j>=78 && j<80) || (j>=82 && j<84) || (j>=86 && j<88) || (j>=90 && j<92) || (j>=94 && j<96)
                        || (j>=98 && j<100) || (j>=102 && j<104) || (j>=106 && j<108) || (j>=110 && j<112) || (j>=114 && j<116) 
			|| (j>=118 && j<120) || (j>=122 && j<124) || (j>=126 && j<128) )) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec2[j]); 

	   } else if (i == 23 + k && j % 2 == 0) {
	   
	    tmp_neg = Cudd_Not(var); 
	    tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec2[j]); 
	   
	   } else if (i == 23 + k && j % 2 == 1) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec2[j]); 

	   }
	  
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd_rec2[j]);
      bdd_rec2[j] = tmp;
    }
  }
    
    bdd66 = Cudd_bddOr(gbm,bdd_rec2[0],bdd_rec2[1]); 
    Cudd_Ref(bdd66);   
    
    for (k = 2;k<128;k++) {
    bdd66 = Cudd_bddOr(gbm,bdd66,bdd_rec2[k]);
    Cudd_Ref(bdd66);   
     }

bdd67 = Cudd_bddOr(gbm,bdd65,bdd66);
bdd = Cudd_bddAnd(gbm,bdd,bdd67);
   Cudd_Ref(bdd);   
     
   for(j = 0;j<128;j++){ 
       for (i = 24; i < 32; i++) {
          var = Cudd_bddIthVar(gbm,i); 
          if(i%8 ==  0) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec3[j]); 
	  }
	  else if(i == 25+k && j < 64 ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec3[j]); 
          }else if(i == 25+k && j >= 64) {
	  tmp = Cudd_bddAnd(gbm, var, bdd_rec3[j]); 
          }
	  else if ( (i == 26 + k) && ( ( j < 32 ) || ( j >= 64 && j < 96 ) ) ) {
          tmp_neg = Cudd_Not(var);
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec3[j]); 
          } else if ( i == 26 + k && ( ( j >= 32 && j < 64 ) || ( j >= 96 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec3[j]); 
	  } else if (i == 27 + k && ( (j<16) || (j>=32 && j<48) || (j>=64 && j<80) || (j>=96 && j<112) ) ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec3[j]); 
	  } else if (i == 27 + k && ( (j >= 16 && j < 32) || ( j >= 48 && j < 64 ) || ( j >= 80 && j < 96 ) || ( j >= 112 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec3[j]); 
          } else if ( i == 28 + k && ( ( j < 8 ) || ( j >= 16 && j < 24) || (j >= 32 && j < 40) || (j>=48 && j<56) || ( j >= 64 && j < 72 ) || 
		    (j >= 80 && j < 88) || (j >= 96 && j < 104) || (j>=112 && j<120) ) ) {
	   tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec3[j]); 
           } else if (i == 28 + k && ( ( j >= 8 && j < 16 ) || ( j >= 24 && j < 32 ) || ( j >= 40 && j < 48) || ( j >= 56 && j < 64) 
			|| (j>72 && j<=80) || (j>=88 && j<96) || (j>=104 && j<112) || (j>=120) ) ) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec3[j]);  
 	   } else if (i == 29 + k && ( (j < 4) || (j >= 8 && j < 12) || (j >= 16 && j < 20) || (j >= 24 && j < 28) || (j >= 32 && j < 36) || (j >= 40 && j < 44)
			|| (j >= 48 && j < 52)  || (j >= 56 && j < 60)|| (j >= 64 && j < 68) || (j >= 72 && j < 76) || (j >= 80 && j < 84) || (j >= 88 && j < 92) 	
			|| (j >= 96 && j < 100) || (j >= 104 && j < 108) || (j >= 112 && j < 116) || (j >= 120 && j < 124))) {
	   tmp_neg = Cudd_Not(var);
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec3[j]); 
	   
	   } else if (i == 29 + k && ( (j>=4 && j<8) || ( j >= 12 && j < 16 ) || ( j >= 20 && j < 24 ) || ( j >= 28 && j < 32 ) || ( j >= 36 && j < 40 ) 
			|| ( j >= 44 && j < 48 ) || ( j >= 52 && j < 56 ) || ( j >= 60 && j < 64 ) || ( j >= 68 && j < 72 ) || ( j >= 76 && j < 80 ) 	  
		        || ( j >= 84 && j < 88 ) || ( j >= 92 && j < 96 ) || ( j >= 100 && j < 104 ) || ( j >= 108 && j < 112 ) 
			|| ( j >= 116 && j < 120  ) 	|| ( j >= 124 && j < 128 ))) {
          
		   tmp = Cudd_bddAnd(gbm,var,bdd_rec3[j]); 
           } else if ( i == 30 + k && ( (j<2) || (j>=4 && j<6)  || (j>=8 && j<10) || (j>=12 && j<14) || (j>=16 && j<18) || (j>=20 && j<22) || (j>=24 && j<26)
			|| (j>=28 && j<30) || (j>=32 && j<34) || (j>=36 && j<38) || (j>=40 && j<42) || (j>=44 && j<46) || (j>=48 && j<50) || (j>=52 && j<54) 	  
			|| (j>=56 && j<58) || (j>=60 && j<62) || (j>=64 && j<66) || (j>=68 && j<70) || (j>=72 && j<74) || (j>=76 && j<78) || (j>=80 && j<82) 
                	|| (j>=84 && j<86) || (j>=88 && j<90) || (j>=92 && j<94) || (j>=96 && j<98) || (j>=100 && j<102) || (j>=104 && j<106) || (j>=108 && j<110) || 
                	(j>=112 && j<114) || (j>=116 && j<118)     || (j>=120 && j<122) || (j>=124 && j<126)
			)) {
	    tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec3[j]); 
	   } else if (i == 30 + k && ( (j>=2 && j<4) || (j>=6 && j<8) || (j>=10 && j<12) || (j>=14 && j<16) || (j>=18 && j<20) || (j>=22 && j<24) || (j>=26 && j<28)
			|| (j>=30 && j<32) || (j>=34 && j<36) || (j>=38 && j<40) || (j>=42 && j<44) || (j>=46 && j<48) || (j>=50 && j<52) 
			|| (j>=54 && j<56) || (j>=58 && j<60) || (j>=62 && j<64) || (j>=66 && j<68) || (j>=70 && j<72) || (j>=74 && j<76) 
			|| (j>=78 && j<80) || (j>=82 && j<84) || (j>=86 && j<88) || (j>=90 && j<92) || (j>=94 && j<96)
                        || (j>=98 && j<100) || (j>=102 && j<104) || (j>=106 && j<108) || (j>=110 && j<112) || (j>=114 && j<116) 
			|| (j>=118 && j<120) || (j>=122 && j<124) || (j>=126 && j<128) )) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec3[j]); 

	   } else if (i == 31 + k && j % 2 == 0) {
	   
	    tmp_neg = Cudd_Not(var); 
	    tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec3[j]); 
	   
	   } else if (i == 31 + k && j % 2 == 1) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec3[j]); 

	   }
	  
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd_rec3[j]);
      bdd_rec3[j] = tmp;
    }
  }
    
    bdd68 = Cudd_bddOr(gbm,bdd_rec3[0],bdd_rec3[1]); 
    Cudd_Ref(bdd68);   
    
    for (k = 2;k<128;k++) {
    bdd68 = Cudd_bddOr(gbm,bdd68,bdd_rec3[k]);
    Cudd_Ref(bdd68);   
     }


     for(j = 0;j<128;j++){ 
       for (i = 24; i < 32; i++) {
          var = Cudd_bddIthVar(gbm,i); 
          if(i%8 ==  0) {
          //tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, var, bdd_rec4[j]); 
	  }
	  else if(i == 25+k && j < 64 ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec4[j]); 
          }else if(i == 25+k && j >= 64) {
	  tmp = Cudd_bddAnd(gbm, var, bdd_rec4[j]); 
          }
	  else if ( (i == 26 + k) && ( ( j < 32 ) || ( j >= 64 && j < 96 ) ) ) {
          tmp_neg = Cudd_Not(var);
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec4[j]); 
          } else if ( i == 26 + k && ( ( j >= 32 && j < 64 ) || ( j >= 96 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec4[j]); 
	  } else if (i == 27 + k && ( (j<16) || (j>=32 && j<48) || (j>=64 && j<80) || (j>=96 && j<112) ) ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec4[j]); 
	  } else if (i == 27 + k && ( (j >= 16 && j < 32) || ( j >= 48 && j < 64 ) || ( j >= 80 && j < 96 ) || ( j >= 112 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec4[j]); 
          } else if ( i == 28 + k && ( ( j < 8 ) || ( j >= 16 && j < 24) || (j >= 32 && j < 40) || (j>=48 && j<56) || ( j >= 64 && j < 72 ) || 
		    (j >= 80 && j < 88) || (j >= 96 && j < 104) || (j>=112 && j<120) ) ) {
	   tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec4[j]); 
           } else if (i == 28 + k && ( ( j >= 8 && j < 16 ) || ( j >= 24 && j < 32 ) || ( j >= 40 && j < 48) || ( j >= 56 && j < 64) 
			|| (j>72 && j<=80) || (j>=88 && j<96) || (j>=104 && j<112) || (j>=120) ) ) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec4[j]);  
 	   } else if (i == 29 + k && ( (j < 4) || (j >= 8 && j < 12) || (j >= 16 && j < 20) || (j >= 24 && j < 28) || (j >= 32 && j < 36) || (j >= 40 && j < 44)
			|| (j >= 48 && j < 52)  || (j >= 56 && j < 60)|| (j >= 64 && j < 68) || (j >= 72 && j < 76) || (j >= 80 && j < 84) || (j >= 88 && j < 92) 	
			|| (j >= 96 && j < 100) || (j >= 104 && j < 108) || (j >= 112 && j < 116) || (j >= 120 && j < 124))) {
	   tmp_neg = Cudd_Not(var);
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec4[j]); 
	   
	   } else if (i == 29 + k && ( (j>=4 && j<8) || ( j >= 12 && j < 16 ) || ( j >= 20 && j < 24 ) || ( j >= 28 && j < 32 ) || ( j >= 36 && j < 40 ) 
			|| ( j >= 44 && j < 48 ) || ( j >= 52 && j < 56 ) || ( j >= 60 && j < 64 ) || ( j >= 68 && j < 72 ) || ( j >= 76 && j < 80 ) 	  
		        || ( j >= 84 && j < 88 ) || ( j >= 92 && j < 96 ) || ( j >= 100 && j < 104 ) || ( j >= 108 && j < 112 ) 
			|| ( j >= 116 && j < 120  ) 	|| ( j >= 124 && j < 128 ))) {
          
		   tmp = Cudd_bddAnd(gbm,var,bdd_rec4[j]); 
           } else if ( i == 30 + k && ( (j<2) || (j>=4 && j<6)  || (j>=8 && j<10) || (j>=12 && j<14) || (j>=16 && j<18) || (j>=20 && j<22) || (j>=24 && j<26)
			|| (j>=28 && j<30) || (j>=32 && j<34) || (j>=36 && j<38) || (j>=40 && j<42) || (j>=44 && j<46) || (j>=48 && j<50) || (j>=52 && j<54) 	  
			|| (j>=56 && j<58) || (j>=60 && j<62) || (j>=64 && j<66) || (j>=68 && j<70) || (j>=72 && j<74) || (j>=76 && j<78) || (j>=80 && j<82) 
                	|| (j>=84 && j<86) || (j>=88 && j<90) || (j>=92 && j<94) || (j>=96 && j<98) || (j>=100 && j<102) || (j>=104 && j<106) || (j>=108 && j<110) || 
                	(j>=112 && j<114) || (j>=116 && j<118)     || (j>=120 && j<122) || (j>=124 && j<126)
			)) {
	    tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec4[j]); 
	   } else if (i == 30 + k && ( (j>=2 && j<4) || (j>=6 && j<8) || (j>=10 && j<12) || (j>=14 && j<16) || (j>=18 && j<20) || (j>=22 && j<24) || (j>=26 && j<28)
			|| (j>=30 && j<32) || (j>=34 && j<36) || (j>=38 && j<40) || (j>=42 && j<44) || (j>=46 && j<48) || (j>=50 && j<52) 
			|| (j>=54 && j<56) || (j>=58 && j<60) || (j>=62 && j<64) || (j>=66 && j<68) || (j>=70 && j<72) || (j>=74 && j<76) 
			|| (j>=78 && j<80) || (j>=82 && j<84) || (j>=86 && j<88) || (j>=90 && j<92) || (j>=94 && j<96)
                        || (j>=98 && j<100) || (j>=102 && j<104) || (j>=106 && j<108) || (j>=110 && j<112) || (j>=114 && j<116) 
			|| (j>=118 && j<120) || (j>=122 && j<124) || (j>=126 && j<128) )) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec4[j]); 

	   } else if (i == 31 + k && j % 2 == 0) {
	   
	    tmp_neg = Cudd_Not(var); 
	    tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec4[j]); 
	   
	   } else if (i == 31 + k && j % 2 == 1) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec4[j]); 

	   }
	  
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd_rec4[j]);
      bdd_rec4[j] = tmp;
    }
  }
    
    bdd69 = Cudd_bddOr(gbm,bdd_rec4[0],bdd_rec4[1]); 
    Cudd_Ref(bdd69);   
    
    for (k = 2;k<128;k++) {
    bdd69 = Cudd_bddOr(gbm,bdd69,bdd_rec4[k]);
    Cudd_Ref(bdd69);   
     }
bdd70 = Cudd_bddOr(gbm,bdd68,bdd69);

bdd = Cudd_bddAnd(gbm,bdd,bdd70);

*/
     for (i = 16; i < 18; i++) {  
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
     if (i!=17) { 
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd71); 
     }else {
	     tmp = Cudd_bddAnd(gbm,var,bdd71); /*Perform AND Boolean operation*/
     }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd71);
      bdd71 = tmp;
    }
    
    
    bdd = Cudd_bddAnd(gbm,bdd,bdd71);
    Cudd_Ref(bdd);

    return bdd;

}

//funzioni amqp
DdNode * scrivi_bdd_zeroamqp(DdManager*gbm,DdNode* bdd,DdNode* var) 
{
DdNode* bdd_rec[128];
DdNode* bdd_rec2[128];
DdNode* bdd_rec3[128];
DdNode* bdd_rec4[128];
DdNode* bdd_rec5[128];
DdNode* bdd_rec6[128];
DdNode* bdd_rec7[128];
DdNode* bdd_rec8[128];
DdNode* bdd_rec9[128];
DdNode* bdd_rec10[128];
DdNode* bdd_rec11[128];
DdNode* bdd_rec12[128];

DdNode *bdd1, *bdd2, *bdd3, *bdd4, *bdd5, *bdd6, *bdd7, *bdd8, *bdd9,*tmp,*tmp_neg, *bdd10,*bdd11,*bdd12,*bdd13,*bdd14,*bdd15,*bdd16,*bdd17,*bdd18,*bdd19,*bdd20,*bdd21,*bdd22,*bdd23,*bdd24,*bdd25,*bdd26,*bdd27,*bdd28,*bdd29,*bdd30;
     bdd = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd); /*Increases the reference count of a node*/
     int i; 
     
     for(i = 0; i < 128; i++){
     bdd_rec[i] = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd_rec[i]); /*Increases the reference count of a node*/
     } 
     for(i = 0; i < 128; i++){
     bdd_rec2[i] = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd_rec2[i]); /*Increases the reference count of a node*/
     } 
     for(i = 0; i < 128; i++){
     bdd_rec3[i] = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd_rec3[i]); /*Increases the reference count of a node*/
     } 
     for(i = 0; i < 128; i++){
     bdd_rec4[i] = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd_rec4[i]); /*Increases the reference count of a node*/
     } 
     for(i = 0; i < 128; i++){
     bdd_rec5[i] = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd_rec5[i]); /*Increases the reference count of a node*/
     } 
     for(i = 0; i < 128; i++){
     bdd_rec6[i] = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd_rec6[i]); /*Increases the reference count of a node*/
     } 
     for(i = 0; i < 128; i++){
     bdd_rec7[i] = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd_rec7[i]); /*Increases the reference count of a node*/
     } 
     for(i = 0; i < 128; i++){
     bdd_rec8[i] = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd_rec8[i]); /*Increases the reference count of a node*/
     } 
     for(i = 0; i < 128; i++){
     bdd_rec9[i] = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd_rec9[i]); /*Increases the reference count of a node*/
     } 
     for(i = 0; i < 128; i++){
     bdd_rec10[i] = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd_rec10[i]); /*Increases the reference count of a node*/
     } 
     for(i = 0; i < 128; i++){
     bdd_rec11[i] = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd_rec11[i]); /*Increases the reference count of a node*/
     } 
     for(i = 0; i < 128; i++){
     bdd_rec12[i] = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd_rec12[i]); /*Increases the reference count of a node*/
     } 
     
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
     bdd6 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd6); /*Increases the reference count of a node*/
     bdd7 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd7); /*Increases the reference count of a node*/
     bdd8 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd8); /*Increases the reference count of a node*/
     bdd9 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd9); /*Increases the reference count of a node*/
     bdd10 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd10); /*Increases the reference count of a node*/
     bdd11 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd11); /*Increases the reference count of a node*/
     bdd12 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd12); /*Increases the reference count of a node*/
     bdd13 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd13); /*Increases the reference count of a node*/
     bdd14 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd14); /*Increases the reference count of a node*/
     bdd15 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd15); /*Increases the reference count of a node*/
     bdd16 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd16); /*Increases the reference count of a node*/
     bdd17 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd17); /*Increases the reference count of a node*/
     bdd18 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd18); /*Increases the reference count of a node*/
     bdd19 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd19); /*Increases the reference count of a node*/
     bdd20 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd20); /*Increases the reference count of a node*/
     bdd21 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd21); /*Increases the reference count of a node*/
     bdd22 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd22); /*Increases the reference count of a node*/
     bdd23 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd23); /*Increases the reference count of a node*/
     bdd24 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd24); /*Increases the reference count of a node*/
     bdd25 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd25); /*Increases the reference count of a node*/
     bdd26 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd26); /*Increases the reference count of a node*/
     bdd27 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd27); /*Increases the reference count of a node*/
     bdd28 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd28); /*Increases the reference count of a node*/
     bdd29 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd29); /*Increases the reference count of a node*/
     bdd30 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd30); /*Increases the reference count of a node*/


    for (i = 0; i < 8; i++) {
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
     if (i != 7 ) {
      tmp_neg = Cudd_Not(var); /*Perform NOT Boolean operation*/
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd); /*Perform AND Boolean operation*/
      }else{
      tmp = Cudd_bddAnd(gbm,var,bdd); /*Perform AND Boolean operation*/
     }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd);
      bdd = tmp;
    }

  
    for (i = 0; i < 8; i++) {
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
     if (i != 6 ) {
      tmp_neg = Cudd_Not(var); /*Perform NOT Boolean operation*/
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd1); /*Perform AND Boolean operation*/
      }else{
      tmp = Cudd_bddAnd(gbm,var,bdd1); /*Perform AND Boolean operation*/
     }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd1);
      bdd1 = tmp;
    }

    bdd = Cudd_bddOr(gbm,bdd,bdd1);
    Cudd_Ref(bdd);  
  
    for (i = 0; i < 8; i++) {
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
     if (i != 6 && i != 7 ) {
      tmp_neg = Cudd_Not(var); /*Perform NOT Boolean operation*/
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd2); /*Perform AND Boolean operation*/
      }else{
      tmp = Cudd_bddAnd(gbm,var,bdd2); /*Perform AND Boolean operation*/
     }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd2);
      bdd2 = tmp;
    }

    bdd = Cudd_bddOr(gbm,bdd,bdd2);
    Cudd_Ref(bdd);

    for (i = 0; i < 8; i++) {
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
     if (i != 5 ) {
      tmp_neg = Cudd_Not(var); /*Perform NOT Boolean operation*/
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd3); /*Perform AND Boolean operation*/
      }else{
      tmp = Cudd_bddAnd(gbm,var,bdd3); /*Perform AND Boolean operation*/
     }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd3);
      bdd3 = tmp;
    }

    bdd = Cudd_bddOr(gbm,bdd,bdd3);
    Cudd_Ref(bdd);
     
int j,k;
     for(j = 0;j<128;j++){ 
       for (i = 8; i < 16; i++) {
          var = Cudd_bddIthVar(gbm,i); 
          if(i%8 ==  0) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	  }
	  else if(i == 9+k && j < 64 ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
          }else if(i == 9+k && j >= 64) {
	  tmp = Cudd_bddAnd(gbm, var, bdd_rec[j]); 
          }
	  else if ( (i == 10 + k) && ( ( j < 32 ) || ( j >= 64 && j < 96 ) ) ) {
          tmp_neg = Cudd_Not(var);
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
          } else if ( i == 10 + k && ( ( j >= 32 && j < 64 ) || ( j >= 96 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
	  } else if (i == 11 + k && ( (j<16) || (j>=32 && j<48) || (j>=64 && j<80) || (j>=96 && j<112) ) ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	  } else if (i == 11 + k && ( (j >= 16 && j < 32) || ( j >= 48 && j < 64 ) || ( j >= 80 && j < 96 ) || ( j >= 112 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
          } else if ( i == 12 + k && ( ( j < 8 ) || ( j >= 16 && j < 24) || (j >= 32 && j < 40) || (j>=48 && j<56) || ( j >= 64 && j < 72 ) || 
		    (j >= 80 && j < 88) || (j >= 96 && j < 104) || (j>=112 && j<120) ) ) {
	   tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
           } else if (i == 12 + k && ( ( j >= 8 && j < 16 ) || ( j >= 24 && j < 32 ) || ( j >= 40 && j < 48) || ( j >= 56 && j < 64) 
			|| (j>72 && j<=80) || (j>=88 && j<96) || (j>=104 && j<112) || (j>=120) ) ) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]);  
 	   } else if (i == 13 + k && ( (j < 4) || (j >= 8 && j < 12) || (j >= 16 && j < 20) || (j >= 24 && j < 28) || (j >= 32 && j < 36) || (j >= 40 && j < 44)
			|| (j >= 48 && j < 52)  || (j >= 56 && j < 60)|| (j >= 64 && j < 68) || (j >= 72 && j < 76) || (j >= 80 && j < 84) || (j >= 88 && j < 92) 	
			|| (j >= 96 && j < 100) || (j >= 104 && j < 108) || (j >= 112 && j < 116) || (j >= 120 && j < 124))) {
	   tmp_neg = Cudd_Not(var);
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   
	   } else if (i == 13 + k && ( (j>=4 && j<8) || ( j >= 12 && j < 16 ) || ( j >= 20 && j < 24 ) || ( j >= 28 && j < 32 ) || ( j >= 36 && j < 40 ) 
			|| ( j >= 44 && j < 48 ) || ( j >= 52 && j < 56 ) || ( j >= 60 && j < 64 ) || ( j >= 68 && j < 72 ) || ( j >= 76 && j < 80 ) 	  
		        || ( j >= 84 && j < 88 ) || ( j >= 92 && j < 96 ) || ( j >= 100 && j < 104 ) || ( j >= 108 && j < 112 ) 
			|| ( j >= 116 && j < 120  ) 	|| ( j >= 124 && j < 128 ))) {
          
		   tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 
           } else if ( i == 14 + k && ( (j<2) || (j>=4 && j<6)  || (j>=8 && j<10) || (j>=12 && j<14) || (j>=16 && j<18) || (j>=20 && j<22) || (j>=24 && j<26)
			|| (j>=28 && j<30) || (j>=32 && j<34) || (j>=36 && j<38) || (j>=40 && j<42) || (j>=44 && j<46) || (j>=48 && j<50) || (j>=52 && j<54) 	  
			|| (j>=56 && j<58) || (j>=60 && j<62) || (j>=64 && j<66) || (j>=68 && j<70) || (j>=72 && j<74) || (j>=76 && j<78) || (j>=80 && j<82) 
                	|| (j>=84 && j<86) || (j>=88 && j<90) || (j>=92 && j<94) || (j>=96 && j<98) || (j>=100 && j<102) || (j>=104 && j<106) || (j>=108 && j<110) || 
                	(j>=112 && j<114) || (j>=116 && j<118)     || (j>=120 && j<122) || (j>=124 && j<126)
			)) {
	    tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   } else if (i == 14 + k && ( (j>=2 && j<4) || (j>=6 && j<8) || (j>=10 && j<12) || (j>=14 && j<16) || (j>=18 && j<20) || (j>=22 && j<24) || (j>=26 && j<28)
			|| (j>=30 && j<32) || (j>=34 && j<36) || (j>=38 && j<40) || (j>=42 && j<44) || (j>=46 && j<48) || (j>=50 && j<52) 
			|| (j>=54 && j<56) || (j>=58 && j<60) || (j>=62 && j<64) || (j>=66 && j<68) || (j>=70 && j<72) || (j>=74 && j<76) 
			|| (j>=78 && j<80) || (j>=82 && j<84) || (j>=86 && j<88) || (j>=90 && j<92) || (j>=94 && j<96)
                        || (j>=98 && j<100) || (j>=102 && j<104) || (j>=106 && j<108) || (j>=110 && j<112) || (j>=114 && j<116) 
			|| (j>=118 && j<120) || (j>=122 && j<124) || (j>=126 && j<128) )) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 

	   } else if (i == 15 + k && j % 2 == 0) {
	   
	    tmp_neg = Cudd_Not(var); 
	    tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec[j]); 
	   
	   } else if (i == 15 + k && j % 2 == 1) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec[j]); 

	   }
	  
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd_rec[j]);
      bdd_rec[j] = tmp;
    }
  }
    
    bdd4 = Cudd_bddOr(gbm,bdd_rec[0],bdd_rec[1]); 
    Cudd_Ref(bdd4);   
    
    for (k = 2;k<128;k++) {
    bdd4 = Cudd_bddOr(gbm,bdd4,bdd_rec[k]);
    Cudd_Ref(bdd4);   
     }


     for(j = 0;j<128;j++){ 
       for (i = 8; i < 16; i++) {
          var = Cudd_bddIthVar(gbm,i); 
          if(i%8 ==  0) {
//          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, var, bdd_rec2[j]); 
	  }
	  else if(i == 9+k && j < 64 ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec2[j]); 
          }else if(i == 9+k && j >= 64) {
	  tmp = Cudd_bddAnd(gbm, var, bdd_rec2[j]); 
          }
	  else if ( (i == 10 + k) && ( ( j < 32 ) || ( j >= 64 && j < 96 ) ) ) {
          tmp_neg = Cudd_Not(var);
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec2[j]); 
          } else if ( i == 10 + k && ( ( j >= 32 && j < 64 ) || ( j >= 96 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec2[j]); 
	  } else if (i == 11 + k && ( (j<16) || (j>=32 && j<48) || (j>=64 && j<80) || (j>=96 && j<112) ) ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec2[j]); 
	  } else if (i == 11 + k && ( (j >= 16 && j < 32) || ( j >= 48 && j < 64 ) || ( j >= 80 && j < 96 ) || ( j >= 112 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec2[j]); 
          } else if ( i == 12 + k && ( ( j < 8 ) || ( j >= 16 && j < 24) || (j >= 32 && j < 40) || (j>=48 && j<56) || ( j >= 64 && j < 72 ) || 
		    (j >= 80 && j < 88) || (j >= 96 && j < 104) || (j>=112 && j<120) ) ) {
	   tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec2[j]); 
           } else if (i == 12 + k && ( ( j >= 8 && j < 16 ) || ( j >= 24 && j < 32 ) || ( j >= 40 && j < 48) || ( j >= 56 && j < 64) 
			|| (j>72 && j<=80) || (j>=88 && j<96) || (j>=104 && j<112) || (j>=120) ) ) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec2[j]);  
 	   } else if (i == 13 + k && ( (j < 4) || (j >= 8 && j < 12) || (j >= 16 && j < 20) || (j >= 24 && j < 28) || (j >= 32 && j < 36) || (j >= 40 && j < 44)
			|| (j >= 48 && j < 52)  || (j >= 56 && j < 60)|| (j >= 64 && j < 68) || (j >= 72 && j < 76) || (j >= 80 && j < 84) || (j >= 88 && j < 92) 	
			|| (j >= 96 && j < 100) || (j >= 104 && j < 108) || (j >= 112 && j < 116) || (j >= 120 && j < 124))) {
	   tmp_neg = Cudd_Not(var);
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec2[j]); 
	   
	   } else if (i == 13 + k && ( (j>=4 && j<8) || ( j >= 12 && j < 16 ) || ( j >= 20 && j < 24 ) || ( j >= 28 && j < 32 ) || ( j >= 36 && j < 40 ) 
			|| ( j >= 44 && j < 48 ) || ( j >= 52 && j < 56 ) || ( j >= 60 && j < 64 ) || ( j >= 68 && j < 72 ) || ( j >= 76 && j < 80 ) 	  
		        || ( j >= 84 && j < 88 ) || ( j >= 92 && j < 96 ) || ( j >= 100 && j < 104 ) || ( j >= 108 && j < 112 ) 
			|| ( j >= 116 && j < 120  ) 	|| ( j >= 124 && j < 128 ))) {
          
		   tmp = Cudd_bddAnd(gbm,var,bdd_rec2[j]); 
           } else if ( i == 14 + k && ( (j<2) || (j>=4 && j<6)  || (j>=8 && j<10) || (j>=12 && j<14) || (j>=16 && j<18) || (j>=20 && j<22) || (j>=24 && j<26)
			|| (j>=28 && j<30) || (j>=32 && j<34) || (j>=36 && j<38) || (j>=40 && j<42) || (j>=44 && j<46) || (j>=48 && j<50) || (j>=52 && j<54) 	  
			|| (j>=56 && j<58) || (j>=60 && j<62) || (j>=64 && j<66) || (j>=68 && j<70) || (j>=72 && j<74) || (j>=76 && j<78) || (j>=80 && j<82) 
                	|| (j>=84 && j<86) || (j>=88 && j<90) || (j>=92 && j<94) || (j>=96 && j<98) || (j>=100 && j<102) || (j>=104 && j<106) || (j>=108 && j<110) || 
                	(j>=112 && j<114) || (j>=116 && j<118)     || (j>=120 && j<122) || (j>=124 && j<126)
			)) {
	    tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec2[j]); 
	   } else if (i == 14 + k && ( (j>=2 && j<4) || (j>=6 && j<8) || (j>=10 && j<12) || (j>=14 && j<16) || (j>=18 && j<20) || (j>=22 && j<24) || (j>=26 && j<28)
			|| (j>=30 && j<32) || (j>=34 && j<36) || (j>=38 && j<40) || (j>=42 && j<44) || (j>=46 && j<48) || (j>=50 && j<52) 
			|| (j>=54 && j<56) || (j>=58 && j<60) || (j>=62 && j<64) || (j>=66 && j<68) || (j>=70 && j<72) || (j>=74 && j<76) 
			|| (j>=78 && j<80) || (j>=82 && j<84) || (j>=86 && j<88) || (j>=90 && j<92) || (j>=94 && j<96)
                        || (j>=98 && j<100) || (j>=102 && j<104) || (j>=106 && j<108) || (j>=110 && j<112) || (j>=114 && j<116) 
			|| (j>=118 && j<120) || (j>=122 && j<124) || (j>=126 && j<128) )) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec2[j]); 

	   } else if (i == 15 + k && j % 2 == 0) {
	   
	    tmp_neg = Cudd_Not(var); 
	    tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec2[j]); 
	   
	   } else if (i == 15 + k && j % 2 == 1) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec2[j]); 

	   }
	  
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd_rec2[j]);
      bdd_rec2[j] = tmp;
    }
  }
    
    bdd5 = Cudd_bddOr(gbm,bdd_rec2[0],bdd_rec2[1]); 
    Cudd_Ref(bdd5);   
    
    for (k = 2;k<128;k++) {
    bdd5 = Cudd_bddOr(gbm,bdd5,bdd_rec2[k]);
    Cudd_Ref(bdd5);   
     }

bdd6 = Cudd_bddOr(gbm,bdd4,bdd5);
bdd = Cudd_bddAnd(gbm,bdd,bdd6);
   Cudd_Ref(bdd);   
     
   /* 
     for(j = 0;j<128;j++){ 
       for (i = 16; i < 24; i++) {
          var = Cudd_bddIthVar(gbm,i); 
          if(i%8 ==  0) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec3[j]); 
	  }
	  else if(i == 17+k && j < 64 ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec3[j]); 
          }else if(i == 17+k && j >= 64) {
	  tmp = Cudd_bddAnd(gbm, var, bdd_rec3[j]); 
          }
	  else if ( (i == 18 + k) && ( ( j < 32 ) || ( j >= 64 && j < 96 ) ) ) {
          tmp_neg = Cudd_Not(var);
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec3[j]); 
          } else if ( i == 18 + k && ( ( j >= 32 && j < 64 ) || ( j >= 96 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec3[j]); 
	  } else if (i == 19 + k && ( (j<16) || (j>=32 && j<48) || (j>=64 && j<80) || (j>=96 && j<112) ) ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec3[j]); 
	  } else if (i == 19 + k && ( (j >= 16 && j < 32) || ( j >= 48 && j < 64 ) || ( j >= 80 && j < 96 ) || ( j >= 112 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec3[j]); 
          } else if ( i == 20 + k && ( ( j < 8 ) || ( j >= 16 && j < 24) || (j >= 32 && j < 40) || (j>=48 && j<56) || ( j >= 64 && j < 72 ) || 
		    (j >= 80 && j < 88) || (j >= 96 && j < 104) || (j>=112 && j<120) ) ) {
	   tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec3[j]); 
           } else if (i == 20 + k && ( ( j >= 8 && j < 16 ) || ( j >= 24 && j < 32 ) || ( j >= 40 && j < 48) || ( j >= 56 && j < 64) 
			|| (j>72 && j<=80) || (j>=88 && j<96) || (j>=104 && j<112) || (j>=120) ) ) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec3[j]);  
 	   } else if (i == 21 + k && ( (j < 4) || (j >= 8 && j < 12) || (j >= 16 && j < 20) || (j >= 24 && j < 28) || (j >= 32 && j < 36) || (j >= 40 && j < 44)
			|| (j >= 48 && j < 52)  || (j >= 56 && j < 60)|| (j >= 64 && j < 68) || (j >= 72 && j < 76) || (j >= 80 && j < 84) || (j >= 88 && j < 92) 	
			|| (j >= 96 && j < 100) || (j >= 104 && j < 108) || (j >= 112 && j < 116) || (j >= 120 && j < 124))) {
	   tmp_neg = Cudd_Not(var);
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec3[j]); 
	   
	   } else if (i == 21 + k && ( (j>=4 && j<8) || ( j >= 12 && j < 16 ) || ( j >= 20 && j < 24 ) || ( j >= 28 && j < 32 ) || ( j >= 36 && j < 40 ) 
			|| ( j >= 44 && j < 48 ) || ( j >= 52 && j < 56 ) || ( j >= 60 && j < 64 ) || ( j >= 68 && j < 72 ) || ( j >= 76 && j < 80 ) 	  
		        || ( j >= 84 && j < 88 ) || ( j >= 92 && j < 96 ) || ( j >= 100 && j < 104 ) || ( j >= 108 && j < 112 ) 
			|| ( j >= 116 && j < 120  ) 	|| ( j >= 124 && j < 128 ))) {
          
		   tmp = Cudd_bddAnd(gbm,var,bdd_rec3[j]); 
           } else if ( i == 22 + k && ( (j<2) || (j>=4 && j<6)  || (j>=8 && j<10) || (j>=12 && j<14) || (j>=16 && j<18) || (j>=20 && j<22) || (j>=24 && j<26)
			|| (j>=28 && j<30) || (j>=32 && j<34) || (j>=36 && j<38) || (j>=40 && j<42) || (j>=44 && j<46) || (j>=48 && j<50) || (j>=52 && j<54) 	  
			|| (j>=56 && j<58) || (j>=60 && j<62) || (j>=64 && j<66) || (j>=68 && j<70) || (j>=72 && j<74) || (j>=76 && j<78) || (j>=80 && j<82) 
                	|| (j>=84 && j<86) || (j>=88 && j<90) || (j>=92 && j<94) || (j>=96 && j<98) || (j>=100 && j<102) || (j>=104 && j<106) || (j>=108 && j<110) || 
                	(j>=112 && j<114) || (j>=116 && j<118)     || (j>=120 && j<122) || (j>=124 && j<126)
			)) {
	    tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec3[j]); 
	   } else if (i == 22 + k && ( (j>=2 && j<4) || (j>=6 && j<8) || (j>=10 && j<12) || (j>=14 && j<16) || (j>=18 && j<20) || (j>=22 && j<24) || (j>=26 && j<28)
			|| (j>=30 && j<32) || (j>=34 && j<36) || (j>=38 && j<40) || (j>=42 && j<44) || (j>=46 && j<48) || (j>=50 && j<52) 
			|| (j>=54 && j<56) || (j>=58 && j<60) || (j>=62 && j<64) || (j>=66 && j<68) || (j>=70 && j<72) || (j>=74 && j<76) 
			|| (j>=78 && j<80) || (j>=82 && j<84) || (j>=86 && j<88) || (j>=90 && j<92) || (j>=94 && j<96)
                        || (j>=98 && j<100) || (j>=102 && j<104) || (j>=106 && j<108) || (j>=110 && j<112) || (j>=114 && j<116) 
			|| (j>=118 && j<120) || (j>=122 && j<124) || (j>=126 && j<128) )) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec3[j]); 

	   } else if (i == 23 + k && j % 2 == 0) {
	   
	    tmp_neg = Cudd_Not(var); 
	    tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec3[j]); 
	   
	   } else if (i == 23 + k && j % 2 == 1) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec3[j]); 

	   }
	  
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd_rec3[j]);
      bdd_rec3[j] = tmp;
    }
  }
    
    bdd7 = Cudd_bddOr(gbm,bdd_rec3[0],bdd_rec3[1]); 
    Cudd_Ref(bdd7);   
    
    for (k = 2;k<128;k++) {
    bdd7 = Cudd_bddOr(gbm,bdd7,bdd_rec3[k]);
    Cudd_Ref(bdd7);   
     }


     for(j = 0;j<128;j++){ 
       for (i = 16; i < 24; i++) {
          var = Cudd_bddIthVar(gbm,i); 
          if(i%8 ==  0) {
//          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, var, bdd_rec4[j]); 
	  }
	  else if(i == 17+k && j < 64 ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec4[j]); 
          }else if(i == 17+k && j >= 64) {
	  tmp = Cudd_bddAnd(gbm, var, bdd_rec4[j]); 
          }
	  else if ( (i == 18 + k) && ( ( j < 32 ) || ( j >= 64 && j < 96 ) ) ) {
          tmp_neg = Cudd_Not(var);
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec4[j]); 
          } else if ( i == 18 + k && ( ( j >= 32 && j < 64 ) || ( j >= 96 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec4[j]); 
	  } else if (i == 19 + k && ( (j<16) || (j>=32 && j<48) || (j>=64 && j<80) || (j>=96 && j<112) ) ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec4[j]); 
	  } else if (i == 19 + k && ( (j >= 16 && j < 32) || ( j >= 48 && j < 64 ) || ( j >= 80 && j < 96 ) || ( j >= 112 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec4[j]); 
          } else if ( i == 20 + k && ( ( j < 8 ) || ( j >= 16 && j < 24) || (j >= 32 && j < 40) || (j>=48 && j<56) || ( j >= 64 && j < 72 ) || 
		    (j >= 80 && j < 88) || (j >= 96 && j < 104) || (j>=112 && j<120) ) ) {
	   tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec4[j]); 
           } else if (i == 20 + k && ( ( j >= 8 && j < 16 ) || ( j >= 24 && j < 32 ) || ( j >= 40 && j < 48) || ( j >= 56 && j < 64) 
			|| (j>72 && j<=80) || (j>=88 && j<96) || (j>=104 && j<112) || (j>=120) ) ) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec4[j]);  
 	   } else if (i == 21 + k && ( (j < 4) || (j >= 8 && j < 12) || (j >= 16 && j < 20) || (j >= 24 && j < 28) || (j >= 32 && j < 36) || (j >= 40 && j < 44)
			|| (j >= 48 && j < 52)  || (j >= 56 && j < 60)|| (j >= 64 && j < 68) || (j >= 72 && j < 76) || (j >= 80 && j < 84) || (j >= 88 && j < 92) 	
			|| (j >= 96 && j < 100) || (j >= 104 && j < 108) || (j >= 112 && j < 116) || (j >= 120 && j < 124))) {
	   tmp_neg = Cudd_Not(var);
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec4[j]); 
	   
	   } else if (i == 21 + k && ( (j>=4 && j<8) || ( j >= 12 && j < 16 ) || ( j >= 20 && j < 24 ) || ( j >= 28 && j < 32 ) || ( j >= 36 && j < 40 ) 
			|| ( j >= 44 && j < 48 ) || ( j >= 52 && j < 56 ) || ( j >= 60 && j < 64 ) || ( j >= 68 && j < 72 ) || ( j >= 76 && j < 80 ) 	  
		        || ( j >= 84 && j < 88 ) || ( j >= 92 && j < 96 ) || ( j >= 100 && j < 104 ) || ( j >= 108 && j < 112 ) 
			|| ( j >= 116 && j < 120  ) 	|| ( j >= 124 && j < 128 ))) {
          
		   tmp = Cudd_bddAnd(gbm,var,bdd_rec4[j]); 
           } else if ( i == 22 + k && ( (j<2) || (j>=4 && j<6)  || (j>=8 && j<10) || (j>=12 && j<14) || (j>=16 && j<18) || (j>=20 && j<22) || (j>=24 && j<26)
			|| (j>=28 && j<30) || (j>=32 && j<34) || (j>=36 && j<38) || (j>=40 && j<42) || (j>=44 && j<46) || (j>=48 && j<50) || (j>=52 && j<54) 	  
			|| (j>=56 && j<58) || (j>=60 && j<62) || (j>=64 && j<66) || (j>=68 && j<70) || (j>=72 && j<74) || (j>=76 && j<78) || (j>=80 && j<82) 
                	|| (j>=84 && j<86) || (j>=88 && j<90) || (j>=92 && j<94) || (j>=96 && j<98) || (j>=100 && j<102) || (j>=104 && j<106) || (j>=108 && j<110) || 
                	(j>=112 && j<114) || (j>=116 && j<118)     || (j>=120 && j<122) || (j>=124 && j<126)
			)) {
	    tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec4[j]); 
	   } else if (i == 22 + k && ( (j>=2 && j<4) || (j>=6 && j<8) || (j>=10 && j<12) || (j>=14 && j<16) || (j>=18 && j<20) || (j>=22 && j<24) || (j>=26 && j<28)
			|| (j>=30 && j<32) || (j>=34 && j<36) || (j>=38 && j<40) || (j>=42 && j<44) || (j>=46 && j<48) || (j>=50 && j<52) 
			|| (j>=54 && j<56) || (j>=58 && j<60) || (j>=62 && j<64) || (j>=66 && j<68) || (j>=70 && j<72) || (j>=74 && j<76) 
			|| (j>=78 && j<80) || (j>=82 && j<84) || (j>=86 && j<88) || (j>=90 && j<92) || (j>=94 && j<96)
                        || (j>=98 && j<100) || (j>=102 && j<104) || (j>=106 && j<108) || (j>=110 && j<112) || (j>=114 && j<116) 
			|| (j>=118 && j<120) || (j>=122 && j<124) || (j>=126 && j<128) )) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec4[j]); 

	   } else if (i == 23 + k && j % 2 == 0) {
	   
	    tmp_neg = Cudd_Not(var); 
	    tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec4[j]); 
	   
	   } else if (i == 23 + k && j % 2 == 1) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec4[j]); 

	   }
	  
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd_rec4[j]);
      bdd_rec4[j] = tmp;
    }
  }
    
    bdd8 = Cudd_bddOr(gbm,bdd_rec4[0],bdd_rec4[1]); 
    Cudd_Ref(bdd8);   
    
    for (k = 2;k<128;k++) {
    bdd8 = Cudd_bddOr(gbm,bdd8,bdd_rec4[k]);
    Cudd_Ref(bdd8);   
     }


    bdd9 = Cudd_bddOr(gbm,bdd7,bdd8);

    bdd = Cudd_bddAnd(gbm,bdd,bdd9);
 
    Cudd_Ref(bdd);   
     
   for(j = 0;j<128;j++){ 
       for (i = 24; i < 32; i++) {
          var = Cudd_bddIthVar(gbm,i); 
          if(i%8 ==  0) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec5[j]); 
	  }
	  else if(i == 25+k && j < 64 ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec5[j]); 
          }else if(i == 25+k && j >= 64) {
	  tmp = Cudd_bddAnd(gbm, var, bdd_rec5[j]); 
          }
	  else if ( (i == 26 + k) && ( ( j < 32 ) || ( j >= 64 && j < 96 ) ) ) {
          tmp_neg = Cudd_Not(var);
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec5[j]); 
          } else if ( i == 26 + k && ( ( j >= 32 && j < 64 ) || ( j >= 96 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec5[j]); 
	  } else if (i == 27 + k && ( (j<16) || (j>=32 && j<48) || (j>=64 && j<80) || (j>=96 && j<112) ) ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec5[j]); 
	  } else if (i == 27 + k && ( (j >= 16 && j < 32) || ( j >= 48 && j < 64 ) || ( j >= 80 && j < 96 ) || ( j >= 112 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec5[j]); 
          } else if ( i == 28 + k && ( ( j < 8 ) || ( j >= 16 && j < 24) || (j >= 32 && j < 40) || (j>=48 && j<56) || ( j >= 64 && j < 72 ) || 
		    (j >= 80 && j < 88) || (j >= 96 && j < 104) || (j>=112 && j<120) ) ) {
	   tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec5[j]); 
           } else if (i == 28 + k && ( ( j >= 8 && j < 16 ) || ( j >= 24 && j < 32 ) || ( j >= 40 && j < 48) || ( j >= 56 && j < 64) 
			|| (j>72 && j<=80) || (j>=88 && j<96) || (j>=104 && j<112) || (j>=120) ) ) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec5[j]);  
 	   } else if (i == 29 + k && ( (j < 4) || (j >= 8 && j < 12) || (j >= 16 && j < 20) || (j >= 24 && j < 28) || (j >= 32 && j < 36) || (j >= 40 && j < 44)
			|| (j >= 48 && j < 52)  || (j >= 56 && j < 60)|| (j >= 64 && j < 68) || (j >= 72 && j < 76) || (j >= 80 && j < 84) || (j >= 88 && j < 92) 	
			|| (j >= 96 && j < 100) || (j >= 104 && j < 108) || (j >= 112 && j < 116) || (j >= 120 && j < 124))) {
	   tmp_neg = Cudd_Not(var);
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec5[j]); 
	   
	   } else if (i == 29 + k && ( (j>=4 && j<8) || ( j >= 12 && j < 16 ) || ( j >= 20 && j < 24 ) || ( j >= 28 && j < 32 ) || ( j >= 36 && j < 40 ) 
			|| ( j >= 44 && j < 48 ) || ( j >= 52 && j < 56 ) || ( j >= 60 && j < 64 ) || ( j >= 68 && j < 72 ) || ( j >= 76 && j < 80 ) 	  
		        || ( j >= 84 && j < 88 ) || ( j >= 92 && j < 96 ) || ( j >= 100 && j < 104 ) || ( j >= 108 && j < 112 ) 
			|| ( j >= 116 && j < 120  ) 	|| ( j >= 124 && j < 128 ))) {
          
		   tmp = Cudd_bddAnd(gbm,var,bdd_rec5[j]); 
           } else if ( i == 30 + k && ( (j<2) || (j>=4 && j<6)  || (j>=8 && j<10) || (j>=12 && j<14) || (j>=16 && j<18) || (j>=20 && j<22) || (j>=24 && j<26)
			|| (j>=28 && j<30) || (j>=32 && j<34) || (j>=36 && j<38) || (j>=40 && j<42) || (j>=44 && j<46) || (j>=48 && j<50) || (j>=52 && j<54) 	  
			|| (j>=56 && j<58) || (j>=60 && j<62) || (j>=64 && j<66) || (j>=68 && j<70) || (j>=72 && j<74) || (j>=76 && j<78) || (j>=80 && j<82) 
                	|| (j>=84 && j<86) || (j>=88 && j<90) || (j>=92 && j<94) || (j>=96 && j<98) || (j>=100 && j<102) || (j>=104 && j<106) || (j>=108 && j<110) || 
                	(j>=112 && j<114) || (j>=116 && j<118)     || (j>=120 && j<122) || (j>=124 && j<126)
			)) {
	    tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec5[j]); 
	   } else if (i == 30 + k && ( (j>=2 && j<4) || (j>=6 && j<8) || (j>=10 && j<12) || (j>=14 && j<16) || (j>=18 && j<20) || (j>=22 && j<24) || (j>=26 && j<28)
			|| (j>=30 && j<32) || (j>=34 && j<36) || (j>=38 && j<40) || (j>=42 && j<44) || (j>=46 && j<48) || (j>=50 && j<52) 
			|| (j>=54 && j<56) || (j>=58 && j<60) || (j>=62 && j<64) || (j>=66 && j<68) || (j>=70 && j<72) || (j>=74 && j<76) 
			|| (j>=78 && j<80) || (j>=82 && j<84) || (j>=86 && j<88) || (j>=90 && j<92) || (j>=94 && j<96)
                        || (j>=98 && j<100) || (j>=102 && j<104) || (j>=106 && j<108) || (j>=110 && j<112) || (j>=114 && j<116) 
			|| (j>=118 && j<120) || (j>=122 && j<124) || (j>=126 && j<128) )) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec5[j]); 

	   } else if (i == 31 + k && j % 2 == 0) {
	   
	    tmp_neg = Cudd_Not(var); 
	    tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec5[j]); 
	   
	   } else if (i == 31 + k && j % 2 == 1) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec5[j]); 

	   }
	  
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd_rec5[j]);
      bdd_rec5[j] = tmp;
    }
  }
    
    bdd11 = Cudd_bddOr(gbm,bdd_rec5[0],bdd_rec5[1]); 
    Cudd_Ref(bdd11);   
    
    for (k = 2;k<128;k++) {
    bdd11 = Cudd_bddOr(gbm,bdd11,bdd_rec5[k]);
    Cudd_Ref(bdd11);   
     }


     for(j = 0;j<128;j++){ 
       for (i = 24; i < 32; i++) {
          var = Cudd_bddIthVar(gbm,i); 
          if(i%8 ==  0) {
          //tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, var, bdd_rec6[j]); 
	  }
	  else if(i == 25+k && j < 64 ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec6[j]); 
          }else if(i == 25+k && j >= 64) {
	  tmp = Cudd_bddAnd(gbm, var, bdd_rec6[j]); 
          }
	  else if ( (i == 26 + k) && ( ( j < 32 ) || ( j >= 64 && j < 96 ) ) ) {
          tmp_neg = Cudd_Not(var);
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec6[j]); 
          } else if ( i == 26 + k && ( ( j >= 32 && j < 64 ) || ( j >= 96 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec6[j]); 
	  } else if (i == 27 + k && ( (j<16) || (j>=32 && j<48) || (j>=64 && j<80) || (j>=96 && j<112) ) ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec6[j]); 
	  } else if (i == 27 + k && ( (j >= 16 && j < 32) || ( j >= 48 && j < 64 ) || ( j >= 80 && j < 96 ) || ( j >= 112 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec6[j]); 
          } else if ( i == 28 + k && ( ( j < 8 ) || ( j >= 16 && j < 24) || (j >= 32 && j < 40) || (j>=48 && j<56) || ( j >= 64 && j < 72 ) || 
		    (j >= 80 && j < 88) || (j >= 96 && j < 104) || (j>=112 && j<120) ) ) {
	   tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec6[j]); 
           } else if (i == 28 + k && ( ( j >= 8 && j < 16 ) || ( j >= 24 && j < 32 ) || ( j >= 40 && j < 48) || ( j >= 56 && j < 64) 
			|| (j>72 && j<=80) || (j>=88 && j<96) || (j>=104 && j<112) || (j>=120) ) ) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec6[j]);  
 	   } else if (i == 29 + k && ( (j < 4) || (j >= 8 && j < 12) || (j >= 16 && j < 20) || (j >= 24 && j < 28) || (j >= 32 && j < 36) || (j >= 40 && j < 44)
			|| (j >= 48 && j < 52)  || (j >= 56 && j < 60)|| (j >= 64 && j < 68) || (j >= 72 && j < 76) || (j >= 80 && j < 84) || (j >= 88 && j < 92) 	
			|| (j >= 96 && j < 100) || (j >= 104 && j < 108) || (j >= 112 && j < 116) || (j >= 120 && j < 124))) {
	   tmp_neg = Cudd_Not(var);
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec6[j]); 
	   
	   } else if (i == 29 + k && ( (j>=4 && j<8) || ( j >= 12 && j < 16 ) || ( j >= 20 && j < 24 ) || ( j >= 28 && j < 32 ) || ( j >= 36 && j < 40 ) 
			|| ( j >= 44 && j < 48 ) || ( j >= 52 && j < 56 ) || ( j >= 60 && j < 64 ) || ( j >= 68 && j < 72 ) || ( j >= 76 && j < 80 ) 	  
		        || ( j >= 84 && j < 88 ) || ( j >= 92 && j < 96 ) || ( j >= 100 && j < 104 ) || ( j >= 108 && j < 112 ) 
			|| ( j >= 116 && j < 120  ) 	|| ( j >= 124 && j < 128 ))) {
          
		   tmp = Cudd_bddAnd(gbm,var,bdd_rec6[j]); 
           } else if ( i == 30 + k && ( (j<2) || (j>=4 && j<6)  || (j>=8 && j<10) || (j>=12 && j<14) || (j>=16 && j<18) || (j>=20 && j<22) || (j>=24 && j<26)
			|| (j>=28 && j<30) || (j>=32 && j<34) || (j>=36 && j<38) || (j>=40 && j<42) || (j>=44 && j<46) || (j>=48 && j<50) || (j>=52 && j<54) 	  
			|| (j>=56 && j<58) || (j>=60 && j<62) || (j>=64 && j<66) || (j>=68 && j<70) || (j>=72 && j<74) || (j>=76 && j<78) || (j>=80 && j<82) 
                	|| (j>=84 && j<86) || (j>=88 && j<90) || (j>=92 && j<94) || (j>=96 && j<98) || (j>=100 && j<102) || (j>=104 && j<106) || (j>=108 && j<110) || 
                	(j>=112 && j<114) || (j>=116 && j<118)     || (j>=120 && j<122) || (j>=124 && j<126)
			)) {
	    tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec6[j]); 
	   } else if (i == 30 + k && ( (j>=2 && j<4) || (j>=6 && j<8) || (j>=10 && j<12) || (j>=14 && j<16) || (j>=18 && j<20) || (j>=22 && j<24) || (j>=26 && j<28)
			|| (j>=30 && j<32) || (j>=34 && j<36) || (j>=38 && j<40) || (j>=42 && j<44) || (j>=46 && j<48) || (j>=50 && j<52) 
			|| (j>=54 && j<56) || (j>=58 && j<60) || (j>=62 && j<64) || (j>=66 && j<68) || (j>=70 && j<72) || (j>=74 && j<76) 
			|| (j>=78 && j<80) || (j>=82 && j<84) || (j>=86 && j<88) || (j>=90 && j<92) || (j>=94 && j<96)
                        || (j>=98 && j<100) || (j>=102 && j<104) || (j>=106 && j<108) || (j>=110 && j<112) || (j>=114 && j<116) 
			|| (j>=118 && j<120) || (j>=122 && j<124) || (j>=126 && j<128) )) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec6[j]); 

	   } else if (i == 31 + k && j % 2 == 0) {
	   
	    tmp_neg = Cudd_Not(var); 
	    tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec6[j]); 
	   
	   } else if (i == 31 + k && j % 2 == 1) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec6[j]); 

	   }
	  
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd_rec6[j]);
      bdd_rec6[j] = tmp;
    }
  }
    
    bdd12 = Cudd_bddOr(gbm,bdd_rec6[0],bdd_rec6[1]); 
    Cudd_Ref(bdd12);   
    
    for (k = 2;k<128;k++) {
    bdd12 = Cudd_bddOr(gbm,bdd12,bdd_rec6[k]);
    Cudd_Ref(bdd12);   
     }
bdd13 = Cudd_bddOr(gbm,bdd11,bdd12);

bdd = Cudd_bddAnd(gbm,bdd,bdd13);

    

*/

/*

   for(j = 0;j<128;j++){ 
       for (i = 32; i < 40; i++) {
          var = Cudd_bddIthVar(gbm,i); 
          if(i%8 ==  0) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec7[j]); 
	  }
	  else if(i == 33+k && j < 64 ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec7[j]); 
          }else if(i == 33+k && j >= 64) {
	  tmp = Cudd_bddAnd(gbm, var, bdd_rec7[j]); 
          }
	  else if ( (i == 34 + k) && ( ( j < 32 ) || ( j >= 64 && j < 96 ) ) ) {
          tmp_neg = Cudd_Not(var);
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec7[j]); 
          } else if ( i == 34 + k && ( ( j >= 32 && j < 64 ) || ( j >= 96 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec7[j]); 
	  } else if (i == 35 + k && ( (j<16) || (j>=32 && j<48) || (j>=64 && j<80) || (j>=96 && j<112) ) ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec7[j]); 
	  } else if (i == 35 + k && ( (j >= 16 && j < 32) || ( j >= 48 && j < 64 ) || ( j >= 80 && j < 96 ) || ( j >= 112 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec7[j]); 
          } else if ( i == 36 + k && ( ( j < 8 ) || ( j >= 16 && j < 24) || (j >= 32 && j < 40) || (j>=48 && j<56) || ( j >= 64 && j < 72 ) || 
		    (j >= 80 && j < 88) || (j >= 96 && j < 104) || (j>=112 && j<120) ) ) {
	   tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec7[j]); 
           } else if (i == 36 + k && ( ( j >= 8 && j < 16 ) || ( j >= 24 && j < 32 ) || ( j >= 40 && j < 48) || ( j >= 56 && j < 64) 
			|| (j>72 && j<=80) || (j>=88 && j<96) || (j>=104 && j<112) || (j>=120) ) ) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec7[j]);  
 	   } else if (i == 37 + k && ( (j < 4) || (j >= 8 && j < 12) || (j >= 16 && j < 20) || (j >= 24 && j < 28) || (j >= 32 && j < 36) || (j >= 40 && j < 44)
			|| (j >= 48 && j < 52)  || (j >= 56 && j < 60)|| (j >= 64 && j < 68) || (j >= 72 && j < 76) || (j >= 80 && j < 84) || (j >= 88 && j < 92) 	
			|| (j >= 96 && j < 100) || (j >= 104 && j < 108) || (j >= 112 && j < 116) || (j >= 120 && j < 124))) {
	   tmp_neg = Cudd_Not(var);
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec7[j]); 
	   
	   } else if (i == 37 + k && ( (j>=4 && j<8) || ( j >= 12 && j < 16 ) || ( j >= 20 && j < 24 ) || ( j >= 28 && j < 32 ) || ( j >= 36 && j < 40 ) 
			|| ( j >= 44 && j < 48 ) || ( j >= 52 && j < 56 ) || ( j >= 60 && j < 64 ) || ( j >= 68 && j < 72 ) || ( j >= 76 && j < 80 ) 	  
		        || ( j >= 84 && j < 88 ) || ( j >= 92 && j < 96 ) || ( j >= 100 && j < 104 ) || ( j >= 108 && j < 112 ) 
			|| ( j >= 116 && j < 120  ) 	|| ( j >= 124 && j < 128 ))) {
          
		   tmp = Cudd_bddAnd(gbm,var,bdd_rec7[j]); 
           } else if ( i == 38 + k && ( (j<2) || (j>=4 && j<6)  || (j>=8 && j<10) || (j>=12 && j<14) || (j>=16 && j<18) || (j>=20 && j<22) || (j>=24 && j<26)
			|| (j>=28 && j<30) || (j>=32 && j<34) || (j>=36 && j<38) || (j>=40 && j<42) || (j>=44 && j<46) || (j>=48 && j<50) || (j>=52 && j<54) 	  
			|| (j>=56 && j<58) || (j>=60 && j<62) || (j>=64 && j<66) || (j>=68 && j<70) || (j>=72 && j<74) || (j>=76 && j<78) || (j>=80 && j<82) 
                	|| (j>=84 && j<86) || (j>=88 && j<90) || (j>=92 && j<94) || (j>=96 && j<98) || (j>=100 && j<102) || (j>=104 && j<106) || (j>=108 && j<110) || 
                	(j>=112 && j<114) || (j>=116 && j<118)     || (j>=120 && j<122) || (j>=124 && j<126)
			)) {
	    tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec7[j]); 
	   } else if (i == 38 + k && ( (j>=2 && j<4) || (j>=6 && j<8) || (j>=10 && j<12) || (j>=14 && j<16) || (j>=18 && j<20) || (j>=22 && j<24) || (j>=26 && j<28)
			|| (j>=30 && j<32) || (j>=34 && j<36) || (j>=38 && j<40) || (j>=42 && j<44) || (j>=46 && j<48) || (j>=50 && j<52) 
			|| (j>=54 && j<56) || (j>=58 && j<60) || (j>=62 && j<64) || (j>=66 && j<68) || (j>=70 && j<72) || (j>=74 && j<76) 
			|| (j>=78 && j<80) || (j>=82 && j<84) || (j>=86 && j<88) || (j>=90 && j<92) || (j>=94 && j<96)
                        || (j>=98 && j<100) || (j>=102 && j<104) || (j>=106 && j<108) || (j>=110 && j<112) || (j>=114 && j<116) 
			|| (j>=118 && j<120) || (j>=122 && j<124) || (j>=126 && j<128) )) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec7[j]); 

	   } else if (i == 39 + k && j % 2 == 0) {
	   
	    tmp_neg = Cudd_Not(var); 
	    tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec7[j]); 
	   
	   } else if (i == 39 + k && j % 2 == 1) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec7[j]); 

	   }
	  
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd_rec7[j]);
      bdd_rec7[j] = tmp;
    }
  }
    
    bdd14 = Cudd_bddOr(gbm,bdd_rec7[0],bdd_rec7[1]); 
    Cudd_Ref(bdd14);   
    
    for (k = 2;k<128;k++) {
    bdd14 = Cudd_bddOr(gbm,bdd14,bdd_rec7[k]);
    Cudd_Ref(bdd14);   
     }


     for(j = 0;j<128;j++){ 
       for (i = 32; i < 40; i++) {
          var = Cudd_bddIthVar(gbm,i); 
          if(i%8 ==  0) {
          //tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, var, bdd_rec8[j]); 
	  }
	  else if(i == 33+k && j < 64 ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec8[j]); 
          }else if(i == 33+k && j >= 64) {
	  tmp = Cudd_bddAnd(gbm, var, bdd_rec8[j]); 
          }
	  else if ( (i == 34 + k) && ( ( j < 32 ) || ( j >= 64 && j < 96 ) ) ) {
          tmp_neg = Cudd_Not(var);
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec8[j]); 
          } else if ( i == 34 + k && ( ( j >= 32 && j < 64 ) || ( j >= 96 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec8[j]); 
	  } else if (i == 35 + k && ( (j<16) || (j>=32 && j<48) || (j>=64 && j<80) || (j>=96 && j<112) ) ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec8[j]); 
	  } else if (i == 35 + k && ( (j >= 16 && j < 32) || ( j >= 48 && j < 64 ) || ( j >= 80 && j < 96 ) || ( j >= 112 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec8[j]); 
          } else if ( i == 36 + k && ( ( j < 8 ) || ( j >= 16 && j < 24) || (j >= 32 && j < 40) || (j>=48 && j<56) || ( j >= 64 && j < 72 ) || 
		    (j >= 80 && j < 88) || (j >= 96 && j < 104) || (j>=112 && j<120) ) ) {
	   tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec8[j]); 
           } else if (i == 36 + k && ( ( j >= 8 && j < 16 ) || ( j >= 24 && j < 32 ) || ( j >= 40 && j < 48) || ( j >= 56 && j < 64) 
			|| (j>72 && j<=80) || (j>=88 && j<96) || (j>=104 && j<112) || (j>=120) ) ) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec8[j]);  
 	   } else if (i == 37 + k && ( (j < 4) || (j >= 8 && j < 12) || (j >= 16 && j < 20) || (j >= 24 && j < 28) || (j >= 32 && j < 36) || (j >= 40 && j < 44)
			|| (j >= 48 && j < 52)  || (j >= 56 && j < 60)|| (j >= 64 && j < 68) || (j >= 72 && j < 76) || (j >= 80 && j < 84) || (j >= 88 && j < 92) 	
			|| (j >= 96 && j < 100) || (j >= 104 && j < 108) || (j >= 112 && j < 116) || (j >= 120 && j < 124))) {
	   tmp_neg = Cudd_Not(var);
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec8[j]); 
	   
	   } else if (i == 37 + k && ( (j>=4 && j<8) || ( j >= 12 && j < 16 ) || ( j >= 20 && j < 24 ) || ( j >= 28 && j < 32 ) || ( j >= 36 && j < 40 ) 
			|| ( j >= 44 && j < 48 ) || ( j >= 52 && j < 56 ) || ( j >= 60 && j < 64 ) || ( j >= 68 && j < 72 ) || ( j >= 76 && j < 80 ) 	  
		        || ( j >= 84 && j < 88 ) || ( j >= 92 && j < 96 ) || ( j >= 100 && j < 104 ) || ( j >= 108 && j < 112 ) 
			|| ( j >= 116 && j < 120  ) 	|| ( j >= 124 && j < 128 ))) {
          
		   tmp = Cudd_bddAnd(gbm,var,bdd_rec8[j]); 
           } else if ( i == 38 + k && ( (j<2) || (j>=4 && j<6)  || (j>=8 && j<10) || (j>=12 && j<14) || (j>=16 && j<18) || (j>=20 && j<22) || (j>=24 && j<26)
			|| (j>=28 && j<30) || (j>=32 && j<34) || (j>=36 && j<38) || (j>=40 && j<42) || (j>=44 && j<46) || (j>=48 && j<50) || (j>=52 && j<54) 	  
			|| (j>=56 && j<58) || (j>=60 && j<62) || (j>=64 && j<66) || (j>=68 && j<70) || (j>=72 && j<74) || (j>=76 && j<78) || (j>=80 && j<82) 
                	|| (j>=84 && j<86) || (j>=88 && j<90) || (j>=92 && j<94) || (j>=96 && j<98) || (j>=100 && j<102) || (j>=104 && j<106) || (j>=108 && j<110) || 
                	(j>=112 && j<114) || (j>=116 && j<118)     || (j>=120 && j<122) || (j>=124 && j<126)
			)) {
	    tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec8[j]); 
	   } else if (i == 38 + k && ( (j>=2 && j<4) || (j>=6 && j<8) || (j>=10 && j<12) || (j>=14 && j<16) || (j>=18 && j<20) || (j>=22 && j<24) || (j>=26 && j<28)
			|| (j>=30 && j<32) || (j>=34 && j<36) || (j>=38 && j<40) || (j>=42 && j<44) || (j>=46 && j<48) || (j>=50 && j<52) 
			|| (j>=54 && j<56) || (j>=58 && j<60) || (j>=62 && j<64) || (j>=66 && j<68) || (j>=70 && j<72) || (j>=74 && j<76) 
			|| (j>=78 && j<80) || (j>=82 && j<84) || (j>=86 && j<88) || (j>=90 && j<92) || (j>=94 && j<96)
                        || (j>=98 && j<100) || (j>=102 && j<104) || (j>=106 && j<108) || (j>=110 && j<112) || (j>=114 && j<116) 
			|| (j>=118 && j<120) || (j>=122 && j<124) || (j>=126 && j<128) )) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec8[j]); 

	   } else if (i == 39 + k && j % 2 == 0) {
	   
	    tmp_neg = Cudd_Not(var); 
	    tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec8[j]); 
	   
	   } else if (i == 39 + k && j % 2 == 1) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec8[j]); 

	   }
	  
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd_rec8[j]);
      bdd_rec8[j] = tmp;
    }
  }
    
    bdd15 = Cudd_bddOr(gbm,bdd_rec8[0],bdd_rec8[1]); 
    Cudd_Ref(bdd15);   
    
    for (k = 2;k<128;k++) {
    bdd15 = Cudd_bddOr(gbm,bdd15,bdd_rec8[k]);
    Cudd_Ref(bdd15);   
     }
bdd16 = Cudd_bddOr(gbm,bdd14,bdd15);

bdd = Cudd_bddAnd(gbm,bdd,bdd16);


   for(j = 0;j<128;j++){ 
       for (i = 40; i < 48; i++) {
          var = Cudd_bddIthVar(gbm,i); 
          if(i%8 ==  0) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec9[j]); 
	  }
	  else if(i == 41+k && j < 64 ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec9[j]); 
          }else if(i == 41+k && j >= 64) {
	  tmp = Cudd_bddAnd(gbm, var, bdd_rec9[j]); 
          }
	  else if ( (i == 42 + k) && ( ( j < 32 ) || ( j >= 64 && j < 96 ) ) ) {
          tmp_neg = Cudd_Not(var);
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec9[j]); 
          } else if ( i == 42 + k && ( ( j >= 32 && j < 64 ) || ( j >= 96 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec9[j]); 
	  } else if (i == 43 + k && ( (j<16) || (j>=32 && j<48) || (j>=64 && j<80) || (j>=96 && j<112) ) ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec9[j]); 
	  } else if (i == 43 + k && ( (j >= 16 && j < 32) || ( j >= 48 && j < 64 ) || ( j >= 80 && j < 96 ) || ( j >= 112 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec9[j]); 
          } else if ( i == 44 + k && ( ( j < 8 ) || ( j >= 16 && j < 24) || (j >= 32 && j < 40) || (j>=48 && j<56) || ( j >= 64 && j < 72 ) || 
		    (j >= 80 && j < 88) || (j >= 96 && j < 104) || (j>=112 && j<120) ) ) {
	   tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec9[j]); 
           } else if (i == 44 + k && ( ( j >= 8 && j < 16 ) || ( j >= 24 && j < 32 ) || ( j >= 40 && j < 48) || ( j >= 56 && j < 64) 
			|| (j>72 && j<=80) || (j>=88 && j<96) || (j>=104 && j<112) || (j>=120) ) ) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec9[j]);  
 	   } else if (i == 45 + k && ( (j < 4) || (j >= 8 && j < 12) || (j >= 16 && j < 20) || (j >= 24 && j < 28) || (j >= 32 && j < 36) || (j >= 40 && j < 44)
			|| (j >= 48 && j < 52)  || (j >= 56 && j < 60)|| (j >= 64 && j < 68) || (j >= 72 && j < 76) || (j >= 80 && j < 84) || (j >= 88 && j < 92) 	
			|| (j >= 96 && j < 100) || (j >= 104 && j < 108) || (j >= 112 && j < 116) || (j >= 120 && j < 124))) {
	   tmp_neg = Cudd_Not(var);
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec9[j]); 
	   
	   } else if (i == 45 + k && ( (j>=4 && j<8) || ( j >= 12 && j < 16 ) || ( j >= 20 && j < 24 ) || ( j >= 28 && j < 32 ) || ( j >= 36 && j < 40 ) 
			|| ( j >= 44 && j < 48 ) || ( j >= 52 && j < 56 ) || ( j >= 60 && j < 64 ) || ( j >= 68 && j < 72 ) || ( j >= 76 && j < 80 ) 	  
		        || ( j >= 84 && j < 88 ) || ( j >= 92 && j < 96 ) || ( j >= 100 && j < 104 ) || ( j >= 108 && j < 112 ) 
			|| ( j >= 116 && j < 120  ) 	|| ( j >= 124 && j < 128 ))) {
          
		   tmp = Cudd_bddAnd(gbm,var,bdd_rec9[j]); 
           } else if ( i == 46 + k && ( (j<2) || (j>=4 && j<6)  || (j>=8 && j<10) || (j>=12 && j<14) || (j>=16 && j<18) || (j>=20 && j<22) || (j>=24 && j<26)
			|| (j>=28 && j<30) || (j>=32 && j<34) || (j>=36 && j<38) || (j>=40 && j<42) || (j>=44 && j<46) || (j>=48 && j<50) || (j>=52 && j<54) 	  
			|| (j>=56 && j<58) || (j>=60 && j<62) || (j>=64 && j<66) || (j>=68 && j<70) || (j>=72 && j<74) || (j>=76 && j<78) || (j>=80 && j<82) 
                	|| (j>=84 && j<86) || (j>=88 && j<90) || (j>=92 && j<94) || (j>=96 && j<98) || (j>=100 && j<102) || (j>=104 && j<106) || (j>=108 && j<110) || 
                	(j>=112 && j<114) || (j>=116 && j<118)     || (j>=120 && j<122) || (j>=124 && j<126)
			)) {
	    tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec9[j]); 
	   } else if (i == 46 + k && ( (j>=2 && j<4) || (j>=6 && j<8) || (j>=10 && j<12) || (j>=14 && j<16) || (j>=18 && j<20) || (j>=22 && j<24) || (j>=26 && j<28)
			|| (j>=30 && j<32) || (j>=34 && j<36) || (j>=38 && j<40) || (j>=42 && j<44) || (j>=46 && j<48) || (j>=50 && j<52) 
			|| (j>=54 && j<56) || (j>=58 && j<60) || (j>=62 && j<64) || (j>=66 && j<68) || (j>=70 && j<72) || (j>=74 && j<76) 
			|| (j>=78 && j<80) || (j>=82 && j<84) || (j>=86 && j<88) || (j>=90 && j<92) || (j>=94 && j<96)
                        || (j>=98 && j<100) || (j>=102 && j<104) || (j>=106 && j<108) || (j>=110 && j<112) || (j>=114 && j<116) 
			|| (j>=118 && j<120) || (j>=122 && j<124) || (j>=126 && j<128) )) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec9[j]); 

	   } else if (i == 47 + k && j % 2 == 0) {
	   
	    tmp_neg = Cudd_Not(var); 
	    tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec9[j]); 
	   
	   } else if (i == 47 + k && j % 2 == 1) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec9[j]); 

	   }
	  
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd_rec9[j]);
      bdd_rec9[j] = tmp;
    }
  }
    
    bdd17 = Cudd_bddOr(gbm,bdd_rec9[0],bdd_rec9[1]); 
    Cudd_Ref(bdd11);   
    
    for (k = 2;k<128;k++) {
    bdd17 = Cudd_bddOr(gbm,bdd17,bdd_rec9[k]);
    Cudd_Ref(bdd17);   
     }


     for(j = 0;j<128;j++){ 
       for (i = 40; i < 48; i++) {
          var = Cudd_bddIthVar(gbm,i); 
          if(i%8 ==  0) {
          //tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, var, bdd_rec10[j]); 
	  }
	  else if(i == 41+k && j < 64 ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec10[j]); 
          }else if(i == 41+k && j >= 64) {
	  tmp = Cudd_bddAnd(gbm, var, bdd_rec10[j]); 
          }
	  else if ( (i == 42 + k) && ( ( j < 32 ) || ( j >= 64 && j < 96 ) ) ) {
          tmp_neg = Cudd_Not(var);
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec10[j]); 
          } else if ( i == 42 + k && ( ( j >= 32 && j < 64 ) || ( j >= 96 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec10[j]); 
	  } else if (i == 43 + k && ( (j<16) || (j>=32 && j<48) || (j>=64 && j<80) || (j>=96 && j<112) ) ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec10[j]); 
	  } else if (i == 43 + k && ( (j >= 16 && j < 32) || ( j >= 48 && j < 64 ) || ( j >= 80 && j < 96 ) || ( j >= 112 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec10[j]); 
          } else if ( i == 44 + k && ( ( j < 8 ) || ( j >= 16 && j < 24) || (j >= 32 && j < 40) || (j>=48 && j<56) || ( j >= 64 && j < 72 ) || 
		    (j >= 80 && j < 88) || (j >= 96 && j < 104) || (j>=112 && j<120) ) ) {
	   tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec10[j]); 
           } else if (i == 44 + k && ( ( j >= 8 && j < 16 ) || ( j >= 24 && j < 32 ) || ( j >= 40 && j < 48) || ( j >= 56 && j < 64) 
			|| (j>72 && j<=80) || (j>=88 && j<96) || (j>=104 && j<112) || (j>=120) ) ) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec10[j]);  
 	   } else if (i == 45 + k && ( (j < 4) || (j >= 8 && j < 12) || (j >= 16 && j < 20) || (j >= 24 && j < 28) || (j >= 32 && j < 36) || (j >= 40 && j < 44)
			|| (j >= 48 && j < 52)  || (j >= 56 && j < 60)|| (j >= 64 && j < 68) || (j >= 72 && j < 76) || (j >= 80 && j < 84) || (j >= 88 && j < 92) 	
			|| (j >= 96 && j < 100) || (j >= 104 && j < 108) || (j >= 112 && j < 116) || (j >= 120 && j < 124))) {
	   tmp_neg = Cudd_Not(var);
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec10[j]); 
	   
	   } else if (i == 45 + k && ( (j>=4 && j<8) || ( j >= 12 && j < 16 ) || ( j >= 20 && j < 24 ) || ( j >= 28 && j < 32 ) || ( j >= 36 && j < 40 ) 
			|| ( j >= 44 && j < 48 ) || ( j >= 52 && j < 56 ) || ( j >= 60 && j < 64 ) || ( j >= 68 && j < 72 ) || ( j >= 76 && j < 80 ) 	  
		        || ( j >= 84 && j < 88 ) || ( j >= 92 && j < 96 ) || ( j >= 100 && j < 104 ) || ( j >= 108 && j < 112 ) 
			|| ( j >= 116 && j < 120  ) 	|| ( j >= 124 && j < 128 ))) {
          
		   tmp = Cudd_bddAnd(gbm,var,bdd_rec10[j]); 
           } else if ( i == 46 + k && ( (j<2) || (j>=4 && j<6)  || (j>=8 && j<10) || (j>=12 && j<14) || (j>=16 && j<18) || (j>=20 && j<22) || (j>=24 && j<26)
			|| (j>=28 && j<30) || (j>=32 && j<34) || (j>=36 && j<38) || (j>=40 && j<42) || (j>=44 && j<46) || (j>=48 && j<50) || (j>=52 && j<54) 	  
			|| (j>=56 && j<58) || (j>=60 && j<62) || (j>=64 && j<66) || (j>=68 && j<70) || (j>=72 && j<74) || (j>=76 && j<78) || (j>=80 && j<82) 
                	|| (j>=84 && j<86) || (j>=88 && j<90) || (j>=92 && j<94) || (j>=96 && j<98) || (j>=100 && j<102) || (j>=104 && j<106) || (j>=108 && j<110) || 
                	(j>=112 && j<114) || (j>=116 && j<118)     || (j>=120 && j<122) || (j>=124 && j<126)
			)) {
	    tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec10[j]); 
	   } else if (i == 46 + k && ( (j>=2 && j<4) || (j>=6 && j<8) || (j>=10 && j<12) || (j>=14 && j<16) || (j>=18 && j<20) || (j>=22 && j<24) || (j>=26 && j<28)
			|| (j>=30 && j<32) || (j>=34 && j<36) || (j>=38 && j<40) || (j>=42 && j<44) || (j>=46 && j<48) || (j>=50 && j<52) 
			|| (j>=54 && j<56) || (j>=58 && j<60) || (j>=62 && j<64) || (j>=66 && j<68) || (j>=70 && j<72) || (j>=74 && j<76) 
			|| (j>=78 && j<80) || (j>=82 && j<84) || (j>=86 && j<88) || (j>=90 && j<92) || (j>=94 && j<96)
                        || (j>=98 && j<100) || (j>=102 && j<104) || (j>=106 && j<108) || (j>=110 && j<112) || (j>=114 && j<116) 
			|| (j>=118 && j<120) || (j>=122 && j<124) || (j>=126 && j<128) )) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec10[j]); 

	   } else if (i == 47 + k && j % 2 == 0) {
	   
	    tmp_neg = Cudd_Not(var); 
	    tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec10[j]); 
	   
	   } else if (i == 47 + k && j % 2 == 1) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec10[j]); 

	   }
	  
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd_rec10[j]);
      bdd_rec10[j] = tmp;
    }
  }
    
    bdd18 = Cudd_bddOr(gbm,bdd_rec10[0],bdd_rec10[1]); 
    Cudd_Ref(bdd18);   
    
    for (k = 2;k<128;k++) {
    bdd18 = Cudd_bddOr(gbm,bdd18,bdd_rec10[k]);
    Cudd_Ref(bdd18);   
     }
bdd19 = Cudd_bddOr(gbm,bdd17,bdd18);

bdd = Cudd_bddAnd(gbm,bdd,bdd19);

   for(j = 0;j<128;j++){ 
       for (i = 48; i < 56; i++) {
          var = Cudd_bddIthVar(gbm,i); 
          if(i%8 ==  0) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec11[j]); 
	  }
	  else if(i == 49+k && j < 64 ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec11[j]); 
          }else if(i == 49+k && j >= 64) {
	  tmp = Cudd_bddAnd(gbm, var, bdd_rec11[j]); 
          }
	  else if ( (i == 50 + k) && ( ( j < 32 ) || ( j >= 64 && j < 96 ) ) ) {
          tmp_neg = Cudd_Not(var);
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec11[j]); 
          } else if ( i == 50 + k && ( ( j >= 32 && j < 64 ) || ( j >= 96 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec11[j]); 
	  } else if (i == 51 + k && ( (j<16) || (j>=32 && j<48) || (j>=64 && j<80) || (j>=96 && j<112) ) ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec11[j]); 
	  } else if (i == 51 + k && ( (j >= 16 && j < 32) || ( j >= 48 && j < 64 ) || ( j >= 80 && j < 96 ) || ( j >= 112 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec11[j]); 
          } else if ( i == 52 + k && ( ( j < 8 ) || ( j >= 16 && j < 24) || (j >= 32 && j < 40) || (j>=48 && j<56) || ( j >= 64 && j < 72 ) || 
		    (j >= 80 && j < 88) || (j >= 96 && j < 104) || (j>=112 && j<120) ) ) {
	   tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec11[j]); 
           } else if (i == 52 + k && ( ( j >= 8 && j < 16 ) || ( j >= 24 && j < 32 ) || ( j >= 40 && j < 48) || ( j >= 56 && j < 64) 
			|| (j>72 && j<=80) || (j>=88 && j<96) || (j>=104 && j<112) || (j>=120) ) ) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec11[j]);  
 	   } else if (i == 53 + k && ( (j < 4) || (j >= 8 && j < 12) || (j >= 16 && j < 20) || (j >= 24 && j < 28) || (j >= 32 && j < 36) || (j >= 40 && j < 44)
			|| (j >= 48 && j < 52)  || (j >= 56 && j < 60)|| (j >= 64 && j < 68) || (j >= 72 && j < 76) || (j >= 80 && j < 84) || (j >= 88 && j < 92) 	
			|| (j >= 96 && j < 100) || (j >= 104 && j < 108) || (j >= 112 && j < 116) || (j >= 120 && j < 124))) {
	   tmp_neg = Cudd_Not(var);
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec11[j]); 
	   
	   } else if (i == 53 + k && ( (j>=4 && j<8) || ( j >= 12 && j < 16 ) || ( j >= 20 && j < 24 ) || ( j >= 28 && j < 32 ) || ( j >= 36 && j < 40 ) 
			|| ( j >= 44 && j < 48 ) || ( j >= 52 && j < 56 ) || ( j >= 60 && j < 64 ) || ( j >= 68 && j < 72 ) || ( j >= 76 && j < 80 ) 	  
		        || ( j >= 84 && j < 88 ) || ( j >= 92 && j < 96 ) || ( j >= 100 && j < 104 ) || ( j >= 108 && j < 112 ) 
			|| ( j >= 116 && j < 120  ) 	|| ( j >= 124 && j < 128 ))) {
          
		   tmp = Cudd_bddAnd(gbm,var,bdd_rec11[j]); 
           } else if ( i == 54 + k && ( (j<2) || (j>=4 && j<6)  || (j>=8 && j<10) || (j>=12 && j<14) || (j>=16 && j<18) || (j>=20 && j<22) || (j>=24 && j<26)
			|| (j>=28 && j<30) || (j>=32 && j<34) || (j>=36 && j<38) || (j>=40 && j<42) || (j>=44 && j<46) || (j>=48 && j<50) || (j>=52 && j<54) 	  
			|| (j>=56 && j<58) || (j>=60 && j<62) || (j>=64 && j<66) || (j>=68 && j<70) || (j>=72 && j<74) || (j>=76 && j<78) || (j>=80 && j<82) 
                	|| (j>=84 && j<86) || (j>=88 && j<90) || (j>=92 && j<94) || (j>=96 && j<98) || (j>=100 && j<102) || (j>=104 && j<106) || (j>=108 && j<110) || 
                	(j>=112 && j<114) || (j>=116 && j<118)     || (j>=120 && j<122) || (j>=124 && j<126)
			)) {
	    tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec11[j]); 
	   } else if (i == 54 + k && ( (j>=2 && j<4) || (j>=6 && j<8) || (j>=10 && j<12) || (j>=14 && j<16) || (j>=18 && j<20) || (j>=22 && j<24) || (j>=26 && j<28)
			|| (j>=30 && j<32) || (j>=34 && j<36) || (j>=38 && j<40) || (j>=42 && j<44) || (j>=46 && j<48) || (j>=50 && j<52) 
			|| (j>=54 && j<56) || (j>=58 && j<60) || (j>=62 && j<64) || (j>=66 && j<68) || (j>=70 && j<72) || (j>=74 && j<76) 
			|| (j>=78 && j<80) || (j>=82 && j<84) || (j>=86 && j<88) || (j>=90 && j<92) || (j>=94 && j<96)
                        || (j>=98 && j<100) || (j>=102 && j<104) || (j>=106 && j<108) || (j>=110 && j<112) || (j>=114 && j<116) 
			|| (j>=118 && j<120) || (j>=122 && j<124) || (j>=126 && j<128) )) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec11[j]); 

	   } else if (i == 55 + k && j % 2 == 0) {
	   
	    tmp_neg = Cudd_Not(var); 
	    tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec11[j]); 
	   
	   } else if (i == 55 + k && j % 2 == 1) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec11[j]); 

	   }
	  
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd_rec11[j]);
      bdd_rec11[j] = tmp;
    }
  }
    
    bdd20 = Cudd_bddOr(gbm,bdd_rec11[0],bdd_rec11[1]); 
    Cudd_Ref(bdd20);   
    
    for (k = 2;k<128;k++) {
    bdd20 = Cudd_bddOr(gbm,bdd20,bdd_rec11[k]);
    Cudd_Ref(bdd20);   
     }


     for(j = 0;j<128;j++){ 
       for (i = 48; i < 56; i++) {
          var = Cudd_bddIthVar(gbm,i); 
          if(i%8 ==  0) {
          //tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, var, bdd_rec12[j]); 
	  }
	  else if(i == 49+k && j < 64 ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec12[j]); 
          }else if(i == 49+k && j >= 64) {
	  tmp = Cudd_bddAnd(gbm, var, bdd_rec12[j]); 
          }
	  else if ( (i == 50 + k) && ( ( j < 32 ) || ( j >= 64 && j < 96 ) ) ) {
          tmp_neg = Cudd_Not(var);
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec12[j]); 
          } else if ( i == 50 + k && ( ( j >= 32 && j < 64 ) || ( j >= 96 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec12[j]); 
	  } else if (i == 51 + k && ( (j<16) || (j>=32 && j<48) || (j>=64 && j<80) || (j>=96 && j<112) ) ) {
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec12[j]); 
	  } else if (i == 51 + k && ( (j >= 16 && j < 32) || ( j >= 48 && j < 64 ) || ( j >= 80 && j < 96 ) || ( j >= 112 ) ) ) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec12[j]); 
          } else if ( i == 52 + k && ( ( j < 8 ) || ( j >= 16 && j < 24) || (j >= 32 && j < 40) || (j>=48 && j<56) || ( j >= 64 && j < 72 ) || 
		    (j >= 80 && j < 88) || (j >= 96 && j < 104) || (j>=112 && j<120) ) ) {
	   tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec12[j]); 
           } else if (i == 52 + k && ( ( j >= 8 && j < 16 ) || ( j >= 24 && j < 32 ) || ( j >= 40 && j < 48) || ( j >= 56 && j < 64) 
			|| (j>72 && j<=80) || (j>=88 && j<96) || (j>=104 && j<112) || (j>=120) ) ) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec12[j]);  
 	   } else if (i == 53 + k && ( (j < 4) || (j >= 8 && j < 12) || (j >= 16 && j < 20) || (j >= 24 && j < 28) || (j >= 32 && j < 36) || (j >= 40 && j < 44)
			|| (j >= 48 && j < 52)  || (j >= 56 && j < 60)|| (j >= 64 && j < 68) || (j >= 72 && j < 76) || (j >= 80 && j < 84) || (j >= 88 && j < 92) 	
			|| (j >= 96 && j < 100) || (j >= 104 && j < 108) || (j >= 112 && j < 116) || (j >= 120 && j < 124))) {
	   tmp_neg = Cudd_Not(var);
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec12[j]); 
	   
	   } else if (i == 53 + k && ( (j>=4 && j<8) || ( j >= 12 && j < 16 ) || ( j >= 20 && j < 24 ) || ( j >= 28 && j < 32 ) || ( j >= 36 && j < 40 ) 
			|| ( j >= 44 && j < 48 ) || ( j >= 52 && j < 56 ) || ( j >= 60 && j < 64 ) || ( j >= 68 && j < 72 ) || ( j >= 76 && j < 80 ) 	  
		        || ( j >= 84 && j < 88 ) || ( j >= 92 && j < 96 ) || ( j >= 100 && j < 104 ) || ( j >= 108 && j < 112 ) 
			|| ( j >= 116 && j < 120  ) 	|| ( j >= 124 && j < 128 ))) {
          
		   tmp = Cudd_bddAnd(gbm,var,bdd_rec12[j]); 
           } else if ( i == 54 + k && ( (j<2) || (j>=4 && j<6)  || (j>=8 && j<10) || (j>=12 && j<14) || (j>=16 && j<18) || (j>=20 && j<22) || (j>=24 && j<26)
			|| (j>=28 && j<30) || (j>=32 && j<34) || (j>=36 && j<38) || (j>=40 && j<42) || (j>=44 && j<46) || (j>=48 && j<50) || (j>=52 && j<54) 	  
			|| (j>=56 && j<58) || (j>=60 && j<62) || (j>=64 && j<66) || (j>=68 && j<70) || (j>=72 && j<74) || (j>=76 && j<78) || (j>=80 && j<82) 
                	|| (j>=84 && j<86) || (j>=88 && j<90) || (j>=92 && j<94) || (j>=96 && j<98) || (j>=100 && j<102) || (j>=104 && j<106) || (j>=108 && j<110) || 
                	(j>=112 && j<114) || (j>=116 && j<118)     || (j>=120 && j<122) || (j>=124 && j<126)
			)) {
	    tmp_neg = Cudd_Not(var); 
	   tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec12[j]); 
	   } else if (i == 54 + k && ( (j>=2 && j<4) || (j>=6 && j<8) || (j>=10 && j<12) || (j>=14 && j<16) || (j>=18 && j<20) || (j>=22 && j<24) || (j>=26 && j<28)
			|| (j>=30 && j<32) || (j>=34 && j<36) || (j>=38 && j<40) || (j>=42 && j<44) || (j>=46 && j<48) || (j>=50 && j<52) 
			|| (j>=54 && j<56) || (j>=58 && j<60) || (j>=62 && j<64) || (j>=66 && j<68) || (j>=70 && j<72) || (j>=74 && j<76) 
			|| (j>=78 && j<80) || (j>=82 && j<84) || (j>=86 && j<88) || (j>=90 && j<92) || (j>=94 && j<96)
                        || (j>=98 && j<100) || (j>=102 && j<104) || (j>=106 && j<108) || (j>=110 && j<112) || (j>=114 && j<116) 
			|| (j>=118 && j<120) || (j>=122 && j<124) || (j>=126 && j<128) )) {
          tmp = Cudd_bddAnd(gbm,var,bdd_rec12[j]); 

	   } else if (i == 55 + k && j % 2 == 0) {
	   
	    tmp_neg = Cudd_Not(var); 
	    tmp = Cudd_bddAnd(gbm, tmp_neg, bdd_rec12[j]); 
	   
	   } else if (i == 55 + k && j % 2 == 1) {
            tmp = Cudd_bddAnd(gbm,var,bdd_rec12[j]); 

	   }
	  
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd_rec12[j]);
      bdd_rec12[j] = tmp;
    }
  }
    
    bdd21 = Cudd_bddOr(gbm,bdd_rec12[0],bdd_rec12[1]); 
    Cudd_Ref(bdd21);   
    
    for (k = 2;k<128;k++) {
    bdd21 = Cudd_bddOr(gbm,bdd21,bdd_rec12[k]);
    Cudd_Ref(bdd21);   
     }
bdd22 = Cudd_bddOr(gbm,bdd20,bdd21);

bdd = Cudd_bddAnd(gbm,bdd,bdd22);

*/
    DdNode * bdd71;
    bdd71 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd71); /*Increases the reference count of a node*/

     for (i = 16; i < 18; i++) {  
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
     if (i!=16) { 
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd71); 
     }else {
	     tmp = Cudd_bddAnd(gbm,var,bdd71); /*Perform AND Boolean operation*/
     }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd71);
      bdd71 = tmp;
    }
    
    
    bdd = Cudd_bddAnd(gbm,bdd,bdd71);
    Cudd_Ref(bdd);

    return bdd;


}

DdNode * scrivi_bdd_zeroamqp_2(DdManager * gbm, DdNode* bdd,DdNode*var)  
{

DdNode *bdd1, *bdd2, *bdd3, *bdd4, *bdd5, *bdd6, *bdd7, *bdd8, *bdd9,*tmp,*tmp_neg, *bdd10,*bdd11,*bdd12,*bdd13,*bdd14,*bdd15,*bdd16,*bdd17,*bdd18,*bdd19,*bdd20,*bdd21,*bdd22,*bdd23,*bdd24,*bdd25,*bdd26,*bdd27,*bdd28,*bdd29,*bdd30;
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
     bdd6 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd6); /*Increases the reference count of a node*/
     bdd7 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd7); /*Increases the reference count of a node*/
     bdd8 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd8); /*Increases the reference count of a node*/
     bdd9 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd9); /*Increases the reference count of a node*/
     bdd10 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd10); /*Increases the reference count of a node*/
     bdd11 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd11); /*Increases the reference count of a node*/
     bdd12 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd12); /*Increases the reference count of a node*/
     bdd13 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd13); /*Increases the reference count of a node*/
     bdd14 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd14); /*Increases the reference count of a node*/
     bdd15 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd15); /*Increases the reference count of a node*/
     bdd16 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd16); /*Increases the reference count of a node*/
     bdd17 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd17); /*Increases the reference count of a node*/
     bdd18 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd18); /*Increases the reference count of a node*/
     bdd19 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd19); /*Increases the reference count of a node*/
     bdd20 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd20); /*Increases the reference count of a node*/
     bdd21 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd21); /*Increases the reference count of a node*/
     bdd22 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd22); /*Increases the reference count of a node*/
     bdd23 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd23); /*Increases the reference count of a node*/
     bdd24 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd24); /*Increases the reference count of a node*/
     bdd25 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd25); /*Increases the reference count of a node*/
     bdd26 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd26); /*Increases the reference count of a node*/
     bdd27 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd27); /*Increases the reference count of a node*/
     bdd28 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd28); /*Increases the reference count of a node*/
     bdd29 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd29); /*Increases the reference count of a node*/
     bdd30 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd30); /*Increases the reference count of a node*/


    for (i = 0; i < 8; i++) {
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
     if (i != 1 && i != 7 ) {
      tmp_neg = Cudd_Not(var); /*Perform NOT Boolean operation*/
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd); /*Perform AND Boolean operation*/
      }else{
      tmp = Cudd_bddAnd(gbm,var,bdd); /*Perform AND Boolean operation*/
     }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd);
      bdd = tmp;
    }

  
    for (i = 8; i < 16; i++) {
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
     if (i != 9 && i!=12 && i!=13 && i!=15 ) {
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
 /* 
    for (i = 16; i < 24; i++) {
     var = Cudd_bddIthVar(gbm,i); 
     if (i != 17 && i != 19 && i!=23 ) {
      tmp_neg = Cudd_Not(var); 
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd2);
      }else{
      tmp = Cudd_bddAnd(gbm,var,bdd2); 
     }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd2);
      bdd2 = tmp;
    }

    bdd = Cudd_bddAnd(gbm,bdd,bdd2);
    Cudd_Ref(bdd);
*/
/*
    for (i = 24; i < 32; i++) {
     var = Cudd_bddIthVar(gbm,i); 
     if (i != 25 && i!=27 ) {
      tmp_neg = Cudd_Not(var); 
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd3);
      }else{
      tmp = Cudd_bddAnd(gbm,var,bdd3);
     }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd3);
      bdd3 = tmp;
    }

    bdd = Cudd_bddAnd(gbm,bdd,bdd3);
    Cudd_Ref(bdd);
    
    
    for (i = 32; i < 40; i++) {
     var = Cudd_bddIthVar(gbm,i); 
      tmp_neg = Cudd_Not(var);
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd4);
      
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd4);
      bdd4 = tmp;
    }

    bdd = Cudd_bddAnd(gbm,bdd,bdd4);
    Cudd_Ref(bdd);
 
    for (i = 40; i < 48; i++) {
     var = Cudd_bddIthVar(gbm,i); 
      tmp_neg = Cudd_Not(var); 
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd5); 
      
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd5);
      bdd5 = tmp;
    }

    bdd = Cudd_bddAnd(gbm,bdd,bdd5);
    
    for (i = 48; i < 56; i++) {
     var = Cudd_bddIthVar(gbm,i); 
     if (i != 52 && i!=55 ) {
      tmp_neg = Cudd_Not(var); 
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd6);
      }else{
      tmp = Cudd_bddAnd(gbm,var,bdd6); 
     }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd6);
      bdd6 = tmp;
    }

    bdd = Cudd_bddAnd(gbm,bdd,bdd6);
    Cudd_Ref(bdd);
    
    for (i = 56; i < 64; i++) {
     var = Cudd_bddIthVar(gbm,i); 
     if (i != 63 ) {
      tmp_neg = Cudd_Not(var); 
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd7); 
      }else{
      tmp = Cudd_bddAnd(gbm,var,bdd7);
     }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd7);
      bdd7 = tmp;
    }

    bdd = Cudd_bddAnd(gbm,bdd,bdd7);
    Cudd_Ref(bdd);
    */
    DdNode * bdd71;
    bdd71 = Cudd_ReadOne(gbm); 
     Cudd_Ref(bdd71); /*Increases the reference count of a node*/

     for (i = 16; i < 18; i++) {  
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
     if (i!=16) { 
          tmp_neg = Cudd_Not(var); 
	  tmp = Cudd_bddAnd(gbm, tmp_neg, bdd71); 
     }else {
	     tmp = Cudd_bddAnd(gbm,var,bdd71); /*Perform AND Boolean operation*/
     }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd71);
      bdd71 = tmp;
    }
    
    
    bdd = Cudd_bddAnd(gbm,bdd,bdd71);
    
    
    Cudd_Ref(bdd);
return bdd;
}


DdNode * Cudd_bddPrintCover_Gennaro(DdManager *dd,DdNode *l,DdNode *u)
{
    int *array;
    int q, result;
    DdNode *lb;
    int j = 0;
    int i;
    DdNode *cover;
    array = (int *) malloc(sizeof(int) * Cudd_ReadSize(dd));
    
    DdNode * aa;
    aa = Cudd_ReadOne(dd); /*Returns the logic one constant of the manager*/        
    Cudd_Ref(aa); /*Increases the reference count of a node*/                       
    DdNode *tmp1,*tmp_neg,*var;                                                     
    for (i = 16; i < 18; i++) {  
     var = Cudd_bddIthVar(dd,i); /*Create a new BDD variable*/
     tmp_neg = Cudd_Not(var); /*Perform NOT Boolean operation*/
     tmp1 = Cudd_bddAnd(dd, tmp_neg, aa); /*Perform AND Boolean operation*/         
     Cudd_Ref(tmp1);
     Cudd_RecursiveDeref(dd,aa);                                                    
     aa = tmp1;                                                                     
    }                       
    
    DdNode * bdd71;
    bdd71 = Cudd_ReadOne(dd); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd71); /*Increases the reference count of a node*/

     for (i = 16; i < 18; i++) {  
     var = Cudd_bddIthVar(dd,i); /*Create a new BDD variable*/
     if (i!=17) { 
          tmp_neg = Cudd_Not(var); 
	  tmp1 = Cudd_bddAnd(dd, tmp_neg, bdd71); 
     }else {
	     tmp1 = Cudd_bddAnd(dd,var,bdd71); /*Perform AND Boolean operation*/
     }
      Cudd_Ref(tmp1);
      Cudd_RecursiveDeref(dd,bdd71);
      bdd71 = tmp1;
    }
   aa = Cudd_bddOr(dd,aa,bdd71);
   

    DdNode * bdd72;
    bdd72 = Cudd_ReadOne(dd); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd72); /*Increases the reference count of a node*/

     for (i = 16; i < 18; i++) {  
     var = Cudd_bddIthVar(dd,i); /*Create a new BDD variable*/
     if (i!=16) { 
          tmp_neg = Cudd_Not(var); 
	  tmp1 = Cudd_bddAnd(dd, tmp_neg, bdd72); 
     }else {
	     tmp1 = Cudd_bddAnd(dd,var,bdd72); /*Perform AND Boolean operation*/
     }
      Cudd_Ref(tmp1);
      Cudd_RecursiveDeref(dd,bdd72);
      bdd72 = tmp1;
    }
    
   aa = Cudd_bddOr(dd,aa,bdd72);

    if (array == NULL) return(0);
    lb = l;
    Cudd_Ref(lb);
    cover = Cudd_ReadLogicZero(dd);
    Cudd_Ref(cover);
    while (lb != Cudd_ReadLogicZero(dd)) {
        DdNode *implicant, *prime, *tmp;
        int length;
        implicant = Cudd_LargestCube(dd,lb,&length);
        prime = Cudd_bddMakePrime(dd,implicant,u);
        nn[j] = prime;
        j++;
        //faccio la restrizione!
       	prime = Cudd_bddRestrict (dd, prime, aa);    
	lb = Cudd_bddAnd(dd,lb,Cudd_Not(prime));
        u = Cudd_bddOr(dd,prime,u);
    }
    Cudd_RecursiveDeref(dd,lb);
    DdNode * out;
    out = Cudd_bddOr(dd,nn[0],nn[1]);
    for(i=2;i<j;i++){
    out = Cudd_bddOr(dd,nn[i],out);
    }
    for(i = 0;i<j;i++) {
    Cudd_PrintMinterm(dd,nn[i]);
    }
    
    printf("Numero lista %d\n",j);
    return out;

} /* end of Cudd_bddPrintCover */

DdNode * scrivi_bdd_mqtt_q(DdManager * gbm, DdNode* bdd,DdNode*var)  
{

DdNode *bdd1, *bdd2, *bdd3, *bdd4, *bdd5, *bdd6, *bdd7, *bdd8, *bdd9,*tmp,*tmp_neg, *bdd10,*bdd11,*bdd12,*bdd13,*bdd14,*bdd15,*bdd16,*bdd17,*bdd18,*bdd19,*bdd20,*bdd21,*bdd22,*bdd23,*bdd24,*bdd25,*bdd26,*bdd27,*bdd28,*bdd29,*bdd30;
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
     bdd6 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd6); /*Increases the reference count of a node*/
     bdd7 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd7); /*Increases the reference count of a node*/
     bdd8 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd8); /*Increases the reference count of a node*/
     bdd9 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd9); /*Increases the reference count of a node*/
     bdd10 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd10); /*Increases the reference count of a node*/
     bdd11 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd11); /*Increases the reference count of a node*/
     bdd12 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd12); /*Increases the reference count of a node*/
     bdd13 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd13); /*Increases the reference count of a node*/
     bdd14 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd14); /*Increases the reference count of a node*/
     bdd15 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd15); /*Increases the reference count of a node*/
     bdd16 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd16); /*Increases the reference count of a node*/
     bdd17 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd17); /*Increases the reference count of a node*/
     bdd18 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd18); /*Increases the reference count of a node*/
     bdd19 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd19); /*Increases the reference count of a node*/
     bdd20 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd20); /*Increases the reference count of a node*/
     bdd21 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd21); /*Increases the reference count of a node*/
     bdd22 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd22); /*Increases the reference count of a node*/
     bdd23 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd23); /*Increases the reference count of a node*/
     bdd24 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd24); /*Increases the reference count of a node*/
     bdd25 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd25); /*Increases the reference count of a node*/
     bdd26 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd26); /*Increases the reference count of a node*/
     bdd27 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd27); /*Increases the reference count of a node*/
     bdd28 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd28); /*Increases the reference count of a node*/
     bdd29 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd29); /*Increases the reference count of a node*/
     bdd30 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd30); /*Increases the reference count of a node*/


    for (i = 0; i < 8; i++) {
      var = Cudd_bddIthVar(gbm,i);
      tmp_neg = Cudd_Not(var); 
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd);
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd);
      bdd = tmp;
    }

  
    for (i = 8; i < 16; i++) {
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
     if (i != 11 && i!=14 && i!=13 && i!=15 ) {
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
    
    for (i = 0; i < 8; i++) {
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
     if (i != 7 ) {
      tmp_neg = Cudd_Not(var); /*Perform NOT Boolean operation*/
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd2); /*Perform AND Boolean operation*/
      }else{
      tmp = Cudd_bddAnd(gbm,var,bdd2); /*Perform AND Boolean operation*/
     }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd2);
      bdd2 = tmp;
    }

    for (i = 8; i < 16; i++) {
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
     if (i != 11 && i!=14 && i!=10 ) {
      tmp_neg = Cudd_Not(var); /*Perform NOT Boolean operation*/
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd3); /*Perform AND Boolean operation*/
      }else{
      tmp = Cudd_bddAnd(gbm,var,bdd3); /*Perform AND Boolean operation*/
     }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd3);
      bdd3 = tmp;
    }

    bdd2 = Cudd_bddAnd(gbm,bdd2,bdd3);
    Cudd_Ref(bdd);  


    for (i = 0; i < 8; i++) {
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
     if (i != 6 ) {
      tmp_neg = Cudd_Not(var); /*Perform NOT Boolean operation*/
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd4); /*Perform AND Boolean operation*/
      }else{
      tmp = Cudd_bddAnd(gbm,var,bdd4); /*Perform AND Boolean operation*/
     }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd4);
      bdd4 = tmp;
    }

    for (i = 8; i < 16; i++) {
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
     if (i != 15 && i!=14 && i!=13 ) {
      tmp_neg = Cudd_Not(var); /*Perform NOT Boolean operation*/
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd5); /*Perform AND Boolean operation*/
      }else{
      tmp = Cudd_bddAnd(gbm,var,bdd5); /*Perform AND Boolean operation*/
     }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd5);
      bdd5 = tmp;
    }

    bdd4 = Cudd_bddAnd(gbm,bdd4,bdd5);
    Cudd_Ref(bdd);  


    for (i = 0; i < 8; i++) {
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
     if (i != 7 && i != 6) {
      tmp_neg = Cudd_Not(var); /*Perform NOT Boolean operation*/
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd6); /*Perform AND Boolean operation*/
      }else{
      tmp = Cudd_bddAnd(gbm,var,bdd6); /*Perform AND Boolean operation*/
     }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd6);
      bdd6 = tmp;
    }

    for (i = 8; i < 16; i++) {
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
     if (i != 15 && i!=9 ) {
      tmp_neg = Cudd_Not(var); /*Perform NOT Boolean operation*/
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd7); /*Perform AND Boolean operation*/
      }else{
      tmp = Cudd_bddAnd(gbm,var,bdd7); /*Perform AND Boolean operation*/
     }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd7);
      bdd7 = tmp;
    }

    bdd6 = Cudd_bddAnd(gbm,bdd6,bdd7);
    Cudd_Ref(bdd);  


    for (i = 0; i < 8; i++) {
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
     if (i != 5 ) {
      tmp_neg = Cudd_Not(var); /*Perform NOT Boolean operation*/
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd8); /*Perform AND Boolean operation*/
      }else{
      tmp = Cudd_bddAnd(gbm,var,bdd8); /*Perform AND Boolean operation*/
     }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd8);
      bdd8 = tmp;
    }

    for (i = 8; i < 16; i++) {
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
     if (i != 11 && i!=14 && i!=9 && i!=12 && i!=10 ) {
      tmp_neg = Cudd_Not(var); /*Perform NOT Boolean operation*/
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd9); /*Perform AND Boolean operation*/
      }else{
      tmp = Cudd_bddAnd(gbm,var,bdd9); /*Perform AND Boolean operation*/
     }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd9);
      bdd9 = tmp;
    }

    bdd8 = Cudd_bddAnd(gbm,bdd9,bdd8);
    Cudd_Ref(bdd);  



    for (i = 0; i < 8; i++) {
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
     if (i != 5 && i!=7 ) {
      tmp_neg = Cudd_Not(var); /*Perform NOT Boolean operation*/
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd10); /*Perform AND Boolean operation*/
      }else{
      tmp = Cudd_bddAnd(gbm,var,bdd10); /*Perform AND Boolean operation*/
     }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd10);
      bdd10 = tmp;
    }

    for (i = 8; i < 16; i++) {
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
     if (i != 11 ) {
      tmp_neg = Cudd_Not(var); /*Perform NOT Boolean operation*/
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd11); /*Perform AND Boolean operation*/
      }else{
      tmp = Cudd_bddAnd(gbm,var,bdd11); /*Perform AND Boolean operation*/
     }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd11);
      bdd11 = tmp;
    }

    bdd10 = Cudd_bddAnd(gbm,bdd10,bdd11);
    Cudd_Ref(bdd);  


    for (i = 0; i < 8; i++) {
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
     if (i != 1 && i!= 4) {
      tmp_neg = Cudd_Not(var); /*Perform NOT Boolean operation*/
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd12); /*Perform AND Boolean operation*/
      }else{
      tmp = Cudd_bddAnd(gbm,var,bdd12); /*Perform AND Boolean operation*/
     }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd12);
      bdd12 = tmp;
    }

    for (i = 8; i < 16; i++) {
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
     if (i != 11 && i!=9 && i!=15 && i!=10 ) {
      tmp_neg = Cudd_Not(var); /*Perform NOT Boolean operation*/
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd13); /*Perform AND Boolean operation*/
      }else{
      tmp = Cudd_bddAnd(gbm,var,bdd13); /*Perform AND Boolean operation*/
     }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd13);
      bdd13 = tmp;
    }

    bdd12 = Cudd_bddAnd(gbm,bdd12,bdd13);
    Cudd_Ref(bdd);  

    for (i = 0; i < 8; i++) {
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
     if (i != 1 && i!=3 && i!=7 ) {
      tmp_neg = Cudd_Not(var); /*Perform NOT Boolean operation*/
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd14); /*Perform AND Boolean operation*/
      }else{
      tmp = Cudd_bddAnd(gbm,var,bdd14); /*Perform AND Boolean operation*/
     }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd14);
      bdd14 = tmp;
    }

    for (i = 8; i < 16; i++) {
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
     if (i != 11 && i!=14 ) {
      tmp_neg = Cudd_Not(var); /*Perform NOT Boolean operation*/
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd15); /*Perform AND Boolean operation*/
      }else{
      tmp = Cudd_bddAnd(gbm,var,bdd15); /*Perform AND Boolean operation*/
     }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd15);
      bdd15 = tmp;
    }

    bdd14 = Cudd_bddAnd(gbm,bdd14,bdd15);
    Cudd_Ref(bdd);  




bdd = Cudd_bddOr(gbm,bdd,bdd2);
bdd = Cudd_bddOr(gbm,bdd,bdd4);
bdd = Cudd_bddOr(gbm,bdd,bdd6);
bdd = Cudd_bddOr(gbm,bdd,bdd8);
bdd = Cudd_bddOr(gbm,bdd,bdd10);
bdd = Cudd_bddOr(gbm,bdd,bdd12);
bdd = Cudd_bddOr(gbm,bdd,bdd14);

    
    DdNode * bdd71;
    bdd71 = Cudd_ReadOne(gbm); 
     Cudd_Ref(bdd71); /*Increases the reference count of a node*/

     for (i = 16; i < 18; i++) {  
     var = Cudd_bddIthVar(gbm,i);
	     
     tmp = Cudd_bddAnd(gbm,var,bdd71); /*Perform AND Boolean operation*/
     
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd71);
      bdd71 = tmp;
    }
    
    
    bdd = Cudd_bddAnd(gbm,bdd,bdd71);
    
    Cudd_Ref(bdd);
return bdd;
}


