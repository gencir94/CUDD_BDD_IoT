
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

       return bdd;

}




DdNode* scrivi_bdd_uno (DdManager *gbm, DdNode *bdd, DdNode * var) 
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

    return bdd1;


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
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
     
      tmp_neg = Cudd_Not(var); /*Perform NOT Boolean operation*/
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd2); /*Perform AND Boolean operation*/
    
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd2);
      bdd2 = tmp;
    }
   
    bdd = Cudd_bddAnd(gbm,bdd,bdd2);
    Cudd_Ref(bdd);
    
    for (i = 40; i < 48; i++) {
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
     if(i != 45){
      tmp_neg = Cudd_Not(var); /*Perform NOT Boolean operation*/
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd3); /*Perform AND Boolean operation*/
     }else{
      tmp = Cudd_bddAnd(gbm, var, bdd3); /*Perform AND Boolean operation*/
     }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd3);
      bdd3 = tmp;
    }
    
    bdd = Cudd_bddAnd(gbm,bdd,bdd3);
    Cudd_Ref(bdd);
    
    for (i = 48; i < 56; i++) {
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
     if(i != 49 && i!= 52 && i != 53 && i != 55){
      tmp_neg = Cudd_Not(var); /*Perform NOT Boolean operation*/
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd4); /*Perform AND Boolean operation*/
     }else{
      tmp = Cudd_bddAnd(gbm, var, bdd4); /*Perform AND Boolean operation*/
     }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd4);
      bdd4 = tmp;
    }
    
    bdd = Cudd_bddAnd(gbm,bdd,bdd4);
    Cudd_Ref(bdd);
    
    for (i = 56; i < 64; i++) {
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
     if(i != 57 && i!= 59 && i != 63 ){
      tmp_neg = Cudd_Not(var); /*Perform NOT Boolean operation*/
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd5); /*Perform AND Boolean operation*/
     }else{
      tmp = Cudd_bddAnd(gbm, var, bdd5); /*Perform AND Boolean operation*/
     }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd5);
      bdd5 = tmp;
    }

    bdd = Cudd_bddAnd(gbm,bdd,bdd5);
    Cudd_Ref(bdd);
    
    for (i = 64; i < 72; i++) {
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
     if(i != 65 && i!= 67 && i != 69 ){
      tmp_neg = Cudd_Not(var); /*Perform NOT Boolean operation*/
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd6); /*Perform AND Boolean operation*/
     }else{
      tmp = Cudd_bddAnd(gbm, var, bdd6); /*Perform AND Boolean operation*/
     }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd6);
      bdd6 = tmp;
    }
    
     bdd = Cudd_bddAnd(gbm,bdd,bdd6);
     Cudd_Ref(bdd);
    
    for (i = 72; i < 80; i++) {
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
     if(i != 73 && i!= 75 && i != 77 ){
      tmp_neg = Cudd_Not(var); /*Perform NOT Boolean operation*/
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd7); /*Perform AND Boolean operation*/
     }else{
      tmp = Cudd_bddAnd(gbm, var, bdd7); /*Perform AND Boolean operation*/
     }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd7);
      bdd7 = tmp;
    }
     
    bdd = Cudd_bddAnd(gbm,bdd,bdd7);
    Cudd_Ref(bdd);
    
for (i = 80; i < 88; i++) {
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
     if(i != 85){
      tmp_neg = Cudd_Not(var); /*Perform NOT Boolean operation*/
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd8); /*Perform AND Boolean operation*/
     }else{
      tmp = Cudd_bddAnd(gbm, var, bdd8); /*Perform AND Boolean operation*/
     }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd8);
      bdd8 = tmp;
    }
     bdd = Cudd_bddAnd(gbm,bdd,bdd8);




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
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
     
      tmp_neg = Cudd_Not(var); /*Perform NOT Boolean operation*/
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd2); /*Perform AND Boolean operation*/
    
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd2);
      bdd2 = tmp;
    }
   
    bdd = Cudd_bddAnd(gbm,bdd,bdd2);
    Cudd_Ref(bdd);
    
    for (i = 48; i < 56; i++) {
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
     if(i != 53){
      tmp_neg = Cudd_Not(var); /*Perform NOT Boolean operation*/
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd3); /*Perform AND Boolean operation*/
     }else{
      tmp = Cudd_bddAnd(gbm, var, bdd3); /*Perform AND Boolean operation*/
     }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd3);
      bdd3 = tmp;
    }
    
    bdd = Cudd_bddAnd(gbm,bdd,bdd3);
    Cudd_Ref(bdd);
    
    for (i = 56; i < 64; i++) {
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
     if(i != 57 && i!= 60 && i != 61 && i != 63){
      tmp_neg = Cudd_Not(var); /*Perform NOT Boolean operation*/
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd4); /*Perform AND Boolean operation*/
     }else{
      tmp = Cudd_bddAnd(gbm, var, bdd4); /*Perform AND Boolean operation*/
     }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd4);
      bdd4 = tmp;
    }
    
    bdd = Cudd_bddAnd(gbm,bdd,bdd4);
    Cudd_Ref(bdd);
    
    for (i = 64; i < 72; i++) {
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
     if(i != 65 && i!= 67 && i != 71 ){
      tmp_neg = Cudd_Not(var); /*Perform NOT Boolean operation*/
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd5); /*Perform AND Boolean operation*/
     }else{
      tmp = Cudd_bddAnd(gbm, var, bdd5); /*Perform AND Boolean operation*/
     }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd5);
      bdd5 = tmp;
    }

    bdd = Cudd_bddAnd(gbm,bdd,bdd5);
    Cudd_Ref(bdd);
    
    for (i = 72; i < 80; i++) {
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
     if(i != 73 && i!= 75 && i != 77 ){
      tmp_neg = Cudd_Not(var); /*Perform NOT Boolean operation*/
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd6); /*Perform AND Boolean operation*/
     }else{
      tmp = Cudd_bddAnd(gbm, var, bdd6); /*Perform AND Boolean operation*/
     }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd6);
      bdd6 = tmp;
    }
    
     bdd = Cudd_bddAnd(gbm,bdd,bdd6);
     Cudd_Ref(bdd);
    
    for (i = 80; i < 88; i++) {
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
     if(i != 81 && i!= 83 && i != 85 ){
      tmp_neg = Cudd_Not(var); /*Perform NOT Boolean operation*/
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd7); /*Perform AND Boolean operation*/
     }else{
      tmp = Cudd_bddAnd(gbm, var, bdd7); /*Perform AND Boolean operation*/
     }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd7);
      bdd7 = tmp;
    }
     
    bdd = Cudd_bddAnd(gbm,bdd,bdd7);
    Cudd_Ref(bdd);
    
for (i = 88; i < 96; i++) {
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
     if(i != 93){
      tmp_neg = Cudd_Not(var); /*Perform NOT Boolean operation*/
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd8); /*Perform AND Boolean operation*/
     }else{
      tmp = Cudd_bddAnd(gbm, var, bdd8); /*Perform AND Boolean operation*/
     }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd8);
      bdd8 = tmp;
    }
     bdd = Cudd_bddAnd(gbm,bdd,bdd8);


return bdd;

    

}



