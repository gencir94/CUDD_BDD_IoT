
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
     DdNode* bdd_rec2[128];
     DdNode* bdd_rec3[128];
     DdNode* bdd_rec4[128];

     DdNode *bdd1, *bdd2, *bdd3, *bdd4, *bdd5, *bdd6, *bdd7, *bdd8, *bdd9,*tmp,*tmp_neg, *bdd10,*bdd11,*bdd12,*bdd13,*bdd14,*bdd15,*bdd16,*bdd17,*bdd18,*bdd19,*bdd20,
	    *bdd21,*bdd22,*bdd23,*bdd24,*bdd25,*bdd26,*bdd27,*bdd28,*bdd29,*bdd30;
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

     for (i = 32; i < 40; i++) {
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
      tmp_neg = Cudd_Not(var); /*Perform NOT Boolean operation*/
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd10); /*Perform AND Boolean operation*/
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd10);
      bdd10 = tmp;
    }
     for (i = 32; i < 40; i++) {
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
     if(i != 39) {
      tmp_neg = Cudd_Not(var); /*Perform NOT Boolean operation*/
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd11); /*Perform AND Boolean operation*/
      }else{
      tmp = Cudd_bddAnd(gbm,var,bdd11); /*Perform AND Boolean operation*/
     }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd11);
      bdd11 = tmp;
    }
     for (i = 32; i < 40; i++) {
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
     if(i != 38) {
      tmp_neg = Cudd_Not(var); /*Perform NOT Boolean operation*/
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd12); /*Perform AND Boolean operation*/
      }else{
      tmp = Cudd_bddAnd(gbm,var,bdd12); /*Perform AND Boolean operation*/
     }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd12);
      bdd12 = tmp;
    }
     
     for (i = 32; i < 40; i++) {
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
     if(i != 32) {
      tmp_neg = Cudd_Not(var); /*Perform NOT Boolean operation*/
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd13); /*Perform AND Boolean operation*/
      }else{
      tmp = Cudd_bddAnd(gbm,var,bdd13); /*Perform AND Boolean operation*/
     }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd13);
      bdd13 = tmp;
    }
     for (i = 32; i < 40; i++) {
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
     if(i != 32 && i != 38 && i != 39) {
      tmp_neg = Cudd_Not(var); /*Perform NOT Boolean operation*/
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd14); /*Perform AND Boolean operation*/
      }else{
      tmp = Cudd_bddAnd(gbm,var,bdd14); /*Perform AND Boolean operation*/
     }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd14);
      bdd14 = tmp;
    }

    bdd15 = Cudd_bddOr(gbm,bdd10,bdd11);
    bdd15 = Cudd_bddOr(gbm,bdd15,bdd12);
    bdd15 = Cudd_bddOr(gbm,bdd15,bdd13);
    bdd15 = Cudd_bddOr(gbm,bdd15,bdd14);
   
     for (i = 40; i < 48; i++) {
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
      tmp_neg = Cudd_Not(var); /*Perform NOT Boolean operation*/
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd16); /*Perform AND Boolean operation*/
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd16);
      bdd16 = tmp;
    }
     for (i = 40; i < 48; i++) {
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
     if(i != 47) {
      tmp_neg = Cudd_Not(var); /*Perform NOT Boolean operation*/
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd17); /*Perform AND Boolean operation*/
      }else{
      tmp = Cudd_bddAnd(gbm,var,bdd17); /*Perform AND Boolean operation*/
     }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd17);
      bdd17 = tmp;
    }
     for (i = 40; i < 48; i++) {
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
     if(i != 46) {
      tmp_neg = Cudd_Not(var); /*Perform NOT Boolean operation*/
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd18); /*Perform AND Boolean operation*/
      }else{
      tmp = Cudd_bddAnd(gbm,var,bdd18); /*Perform AND Boolean operation*/
     }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd18);
      bdd18 = tmp;
    }
     
     for (i = 40; i < 48; i++) {
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
     if(i != 40) {
      tmp_neg = Cudd_Not(var); /*Perform NOT Boolean operation*/
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd19); /*Perform AND Boolean operation*/
      }else{
      tmp = Cudd_bddAnd(gbm,var,bdd19); /*Perform AND Boolean operation*/
     }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd19);
      bdd19 = tmp;
    }
     for (i = 40; i < 48; i++) {
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
     if(i != 40 && i != 47 && i != 46) {
      tmp_neg = Cudd_Not(var); /*Perform NOT Boolean operation*/
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd20); /*Perform AND Boolean operation*/
      }else{
      tmp = Cudd_bddAnd(gbm,var,bdd20); /*Perform AND Boolean operation*/
     }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd20);
      bdd20 = tmp;
    }

    bdd21 = Cudd_bddOr(gbm,bdd16,bdd17);
    bdd21 = Cudd_bddOr(gbm,bdd21,bdd18);
    bdd21 = Cudd_bddOr(gbm,bdd21,bdd19);
    bdd21 = Cudd_bddOr(gbm,bdd21,bdd20);
    
    bdd = Cudd_bddAnd(gbm,bdd,bdd15);
   
    bdd = Cudd_bddAnd(gbm,bdd,bdd21);
    
     for (i = 48; i < 56; i++) {
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
      tmp_neg = Cudd_Not(var); /*Perform NOT Boolean operation*/
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd22); /*Perform AND Boolean operation*/
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd22);
      bdd22 = tmp;
    }
     for (i = 48; i < 56; i++) {
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
     if(i != 55) {
      tmp_neg = Cudd_Not(var); /*Perform NOT Boolean operation*/
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd23); /*Perform AND Boolean operation*/
      }else{
      tmp = Cudd_bddAnd(gbm,var,bdd23); /*Perform AND Boolean operation*/
     }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd23);
      bdd23 = tmp;
    }
     for (i = 48; i < 56; i++) {
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
     if(i != 54) {
      tmp_neg = Cudd_Not(var); /*Perform NOT Boolean operation*/
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd24); /*Perform AND Boolean operation*/
      }else{
      tmp = Cudd_bddAnd(gbm,var,bdd24); /*Perform AND Boolean operation*/
     }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd24);
      bdd24 = tmp;
    }
     
     for (i = 48; i < 56; i++) {
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
     if(i != 48) {
      tmp_neg = Cudd_Not(var); /*Perform NOT Boolean operation*/
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd25); /*Perform AND Boolean operation*/
      }else{
      tmp = Cudd_bddAnd(gbm,var,bdd25); /*Perform AND Boolean operation*/
     }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd25);
      bdd25 = tmp;
    }
     for (i = 48; i < 56; i++) {
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
     if(i != 48 && i != 54 && i != 55) {
      tmp_neg = Cudd_Not(var); /*Perform NOT Boolean operation*/
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd26); /*Perform AND Boolean operation*/
      }else{
      tmp = Cudd_bddAnd(gbm,var,bdd26); /*Perform AND Boolean operation*/
     }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd26);
      bdd26 = tmp;
    }

    bdd27 = Cudd_bddOr(gbm,bdd22,bdd23);
    bdd27 = Cudd_bddOr(gbm,bdd27,bdd24);
    bdd27 = Cudd_bddOr(gbm,bdd27,bdd25);
    bdd27 = Cudd_bddOr(gbm,bdd27,bdd26);
    
    bdd = Cudd_bddAnd(gbm,bdd,bdd27);
   
    
    return bdd;

}




DdNode* scrivi_bdd_uno (DdManager *gbm, DdNode *bdd, DdNode * var) 
{
     DdNode* bdd_rec[128];
     DdNode* bdd_rec2[128];
     DdNode* bdd_rec3[128];
     DdNode* bdd_rec4[128];

     DdNode *bdd1, *bdd2, *bdd3, *bdd4, *bdd5, *bdd6, *bdd7, *bdd8, *bdd9,*tmp,*tmp_neg, *bdd10,*bdd11,*bdd12,*bdd13,*bdd14,*bdd15,*bdd16,*bdd17,*bdd18,*bdd19,*bdd20,
	    *bdd21,*bdd22,*bdd23,*bdd24,*bdd25,*bdd26,*bdd27,*bdd28,*bdd29,*bdd30;
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

     for (i = 40; i < 48; i++) {
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
      tmp_neg = Cudd_Not(var); /*Perform NOT Boolean operation*/
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd16); /*Perform AND Boolean operation*/
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd16);
      bdd16 = tmp;
    }
     for (i = 40; i < 48; i++) {
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
     if(i != 47) {
      tmp_neg = Cudd_Not(var); /*Perform NOT Boolean operation*/
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd17); /*Perform AND Boolean operation*/
      }else{
      tmp = Cudd_bddAnd(gbm,var,bdd17); /*Perform AND Boolean operation*/
     }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd17);
      bdd17 = tmp;
    }
     for (i = 40; i < 48; i++) {
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
     if(i != 46) {
      tmp_neg = Cudd_Not(var); /*Perform NOT Boolean operation*/
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd18); /*Perform AND Boolean operation*/
      }else{
      tmp = Cudd_bddAnd(gbm,var,bdd18); /*Perform AND Boolean operation*/
     }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd18);
      bdd18 = tmp;
    }
     
     for (i = 40; i < 48; i++) {
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
     if(i != 40) {
      tmp_neg = Cudd_Not(var); /*Perform NOT Boolean operation*/
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd19); /*Perform AND Boolean operation*/
      }else{
      tmp = Cudd_bddAnd(gbm,var,bdd19); /*Perform AND Boolean operation*/
     }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd19);
      bdd19 = tmp;
    }
     for (i = 40; i < 48; i++) {
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
     if(i != 40 && i != 47 && i != 46) {
      tmp_neg = Cudd_Not(var); /*Perform NOT Boolean operation*/
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd20); /*Perform AND Boolean operation*/
      }else{
      tmp = Cudd_bddAnd(gbm,var,bdd20); /*Perform AND Boolean operation*/
     }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd20);
      bdd20 = tmp;
    }

    bdd21 = Cudd_bddOr(gbm,bdd16,bdd17);
    bdd21 = Cudd_bddOr(gbm,bdd21,bdd18);
    bdd21 = Cudd_bddOr(gbm,bdd21,bdd19);
    bdd21 = Cudd_bddOr(gbm,bdd21,bdd20);
    
    bdd = Cudd_bddAnd(gbm,bdd,bdd15);
   
    bdd = Cudd_bddAnd(gbm,bdd,bdd21);
    
     for (i = 48; i < 56; i++) {
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
      tmp_neg = Cudd_Not(var); /*Perform NOT Boolean operation*/
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd22); /*Perform AND Boolean operation*/
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd22);
      bdd22 = tmp;
    }
     for (i = 48; i < 56; i++) {
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
     if(i != 55) {
      tmp_neg = Cudd_Not(var); /*Perform NOT Boolean operation*/
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd23); /*Perform AND Boolean operation*/
      }else{
      tmp = Cudd_bddAnd(gbm,var,bdd23); /*Perform AND Boolean operation*/
     }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd23);
      bdd23 = tmp;
    }
     for (i = 48; i < 56; i++) {
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
     if(i != 54) {
      tmp_neg = Cudd_Not(var); /*Perform NOT Boolean operation*/
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd24); /*Perform AND Boolean operation*/
      }else{
      tmp = Cudd_bddAnd(gbm,var,bdd24); /*Perform AND Boolean operation*/
     }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd24);
      bdd24 = tmp;
    }
     
     for (i = 48; i < 56; i++) {
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
     if(i != 48) {
      tmp_neg = Cudd_Not(var); /*Perform NOT Boolean operation*/
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd25); /*Perform AND Boolean operation*/
      }else{
      tmp = Cudd_bddAnd(gbm,var,bdd25); /*Perform AND Boolean operation*/
     }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd25);
      bdd25 = tmp;
    }
     for (i = 48; i < 56; i++) {
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
     if(i != 48 && i != 54 && i != 55) {
      tmp_neg = Cudd_Not(var); /*Perform NOT Boolean operation*/
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd26); /*Perform AND Boolean operation*/
      }else{
      tmp = Cudd_bddAnd(gbm,var,bdd26); /*Perform AND Boolean operation*/
     }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd26);
      bdd26 = tmp;
    }

    bdd27 = Cudd_bddOr(gbm,bdd22,bdd23);
    bdd27 = Cudd_bddOr(gbm,bdd27,bdd24);
    bdd27 = Cudd_bddOr(gbm,bdd27,bdd25);
    bdd27 = Cudd_bddOr(gbm,bdd27,bdd26);
    
    bdd = Cudd_bddAnd(gbm,bdd,bdd27);
   



    return bdd;




}	



DdNode* scrivi_bdd_due (DdManager *gbm, DdNode *bdd, DdNode * var) {
      DdNode* bdd_rec[128];
     DdNode* bdd_rec2[128];
     DdNode* bdd_rec3[128];
     DdNode* bdd_rec4[128];

     DdNode *bdd1, *bdd2, *bdd3, *bdd4, *bdd5, *bdd6, *bdd7, *bdd8, *bdd9,*tmp,*tmp_neg, *bdd10,*bdd11,*bdd12,*bdd13,*bdd14,*bdd15,*bdd16,*bdd17,*bdd18,*bdd19,*bdd20,
	    *bdd21,*bdd22,*bdd23,*bdd24,*bdd25,*bdd26,*bdd27,*bdd28,*bdd29,*bdd30;
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
     
    for (i = 48; i < 56; i++) {
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
      tmp_neg = Cudd_Not(var); /*Perform NOT Boolean operation*/
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd22); /*Perform AND Boolean operation*/
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd22);
      bdd22 = tmp;
    }
     for (i = 48; i < 56; i++) {
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
     if(i != 55) {
      tmp_neg = Cudd_Not(var); /*Perform NOT Boolean operation*/
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd23); /*Perform AND Boolean operation*/
      }else{
      tmp = Cudd_bddAnd(gbm,var,bdd23); /*Perform AND Boolean operation*/
     }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd23);
      bdd23 = tmp;
    }
     for (i = 48; i < 56; i++) {
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
     if(i != 54) {
      tmp_neg = Cudd_Not(var); /*Perform NOT Boolean operation*/
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd24); /*Perform AND Boolean operation*/
      }else{
      tmp = Cudd_bddAnd(gbm,var,bdd24); /*Perform AND Boolean operation*/
     }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd24);
      bdd24 = tmp;
    }
     
     for (i = 48; i < 56; i++) {
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
     if(i != 48) {
      tmp_neg = Cudd_Not(var); /*Perform NOT Boolean operation*/
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd25); /*Perform AND Boolean operation*/
      }else{
      tmp = Cudd_bddAnd(gbm,var,bdd25); /*Perform AND Boolean operation*/
     }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd25);
      bdd25 = tmp;
    }
     for (i = 48; i < 56; i++) {
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
     if(i != 48 && i != 54 && i != 55) {
      tmp_neg = Cudd_Not(var); /*Perform NOT Boolean operation*/
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd26); /*Perform AND Boolean operation*/
      }else{
      tmp = Cudd_bddAnd(gbm,var,bdd26); /*Perform AND Boolean operation*/
     }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd26);
      bdd26 = tmp;
    }

    bdd27 = Cudd_bddOr(gbm,bdd22,bdd23);
    bdd27 = Cudd_bddOr(gbm,bdd27,bdd24);
    bdd27 = Cudd_bddOr(gbm,bdd27,bdd25);
    bdd27 = Cudd_bddOr(gbm,bdd27,bdd26);
    
    bdd = Cudd_bddAnd(gbm,bdd,bdd27);
   

 


    return bdd;




}	



DdNode* scrivi_bdd_tre (DdManager *gbm, DdNode *bdd, DdNode * var) {

   DdNode* bdd_rec[128];
     DdNode* bdd_rec2[128];
     DdNode* bdd_rec3[128];
     DdNode* bdd_rec4[128];
     DdNode* bdd_rec5[128];

     DdNode *bdd1, *bdd2, *bdd3, *bdd4, *bdd5, *bdd6, *bdd7, *bdd8, *bdd9,*tmp,*tmp_neg, *bdd10,*bdd11,*bdd12,*bdd13,*bdd14,*bdd15,*bdd16,*bdd17,*bdd18,*bdd19,*bdd20,
	    *bdd21,*bdd22,*bdd23,*bdd24,*bdd25,*bdd26,*bdd27,*bdd28,*bdd29,*bdd30;
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


    return bdd;

    

}



