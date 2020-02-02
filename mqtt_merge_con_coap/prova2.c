
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
#include <stdbool.h> 

int k = 0;
DdNode * final[960000];
int gen_ind = 1 ;
int cube = 0;
int spezzo = 0;
DdNode* sub[1000];
int** list;
int**  list_def;

bool* boolArray;
typedef uintptr_t ptruint;


int ddDagInt_gennaro(DdManager* gbm,DdNode * n,int taglio_max)
{
    int tval, eval;
    
    if (Cudd_NodeReadIndex(n) < taglio_max )
    {   
  
	    if (Cudd_IsComplement(n)) {
             
		    tval = ddDagInt_gennaro(gbm,Cudd_Not(Cudd_Regular(Cudd_T(n))),taglio_max);
                    eval = ddDagInt_gennaro(gbm,Cudd_Not(Cudd_Regular(Cudd_E(n))),taglio_max);
   
	    
	    } else {
		    tval = ddDagInt_gennaro(gbm,Cudd_T(n),taglio_max);
                    eval = ddDagInt_gennaro(gbm,Cudd_E(n),taglio_max);
	    
	    }
   
   return(tval + eval);
       
  } else if (Cudd_NodeReadIndex(n) > 3000000)
  
  {
           //istruzione per i nodi fuori range li ingnoro;	            
	   return(0);
  
  } else {
       
        int foglie = (ptruint)n ;  
        printf("le foglie %d\n",foglie);

	int i,j;
        sub[gen_ind] = n;
        Cudd_Ref(sub[gen_ind]);   
        //Cudd_PrintMinterm(gbm,n);
  	
	gen_ind++;
	
	//per vedere se non ho fatto lo stesso percorso.	
	if(boolArray[foglie] == false) {    
    

        boolArray[foglie] = true;
        
	//salvo gli array
       
	
	return(1);
       } else {   
	return(0);
        
        }
       
    } 
}

int Cudd_DagSize_gennaro(DdManager*gbm,DdNode * node,int taglio_max)
{
    int i,j;int** list_visa;
    //list_visa = (int *) malloc(sizeof(int) * Cudd_ReadSize(gbm));
    list_visa = (int **)malloc(4 * sizeof(int *));  
    
    for  ( i = 0; i < 4; i++ ) {
         list_visa[i] = (int *)malloc(Cudd_ReadSize(gbm) * sizeof(int));  
    }
   for (j = 0 ; j < 4 ; j++ ) { 
    for (i = 0; i < Cudd_ReadSize(gbm); i++) {list_visa[j][i] = 2;}
   }
    i = ddDagInt_gennaro(gbm,node,taglio_max);
   

    return(i);

} 




int main() {

    char filename[30];
    DdManager *gbm; /* Global BDD manager. */
    gbm = Cudd_Init(0,0,CUDD_UNIQUE_SLOTS,CUDD_CACHE_SLOTS,0); /* Initialize a new BDD manager. */
    DdNode *bdd,*bdd1,*bdd2,*bdd3,*bdd4,
	 *bdd5,*bdd6,*bdd7,*bdd8,*bdd9,*bdd10,*bdd11,*bdd12,*bdd13,*bdd14,*bdd15,*bdd16,*bdd17,*bdd18,*bdd19,*bdd20,*bdd21,*bdd22,*bdd23,*bdd24,*bdd25,*bdd26,*bdd27,*bdd28,*bdd29,*bdd30,*bdd31,*bdd32,*bdd33,*bdd34,*bdd35,*bdd36,*bdd37,*bdd38,*bdd39,*bdd40,*bdd41,*bdd42,*bdd43,*bdd44,*bdd45,*bdd46,*bdd47,*var;
    DdNode *tmp1;
    

    bdd = scrivi_bdd_zero (gbm, bdd, var); 
    bdd1 = scrivi_bdd_uno(gbm,bdd1,var);
    bdd2 = scrivi_bdd_due(gbm,bdd2,var);
    bdd3 = scrivi_bdd_tre(gbm,bdd3,var); 
    bdd = Cudd_bddOr(gbm,bdd,bdd1); 
    bdd = Cudd_bddOr(gbm,bdd,bdd2); 
    bdd = Cudd_bddOr(gbm,bdd,bdd3); 

    Cudd_Ref(bdd);        
   
    //funzioni connack 
    bdd4 = scrivi_bdd_zero1(gbm, bdd4, var); 
    bdd5 = scrivi_bdd_uno1(gbm,bdd5,var);
    bdd6 = scrivi_bdd_due1(gbm,bdd6,var);
    bdd7 = Cudd_bddOr(gbm,bdd5,bdd6); 
    bdd4 = Cudd_bddAnd(gbm,bdd4,bdd7); 
    
    bdd = Cudd_bddOr(gbm,bdd4,bdd);
   
   //FUNZIONI PUBLISH

    bdd8 = scrivi_bdd_zero2 (gbm, bdd8, var); 
    bdd9 = scrivi_bdd_uno2(gbm,bdd9,var);
    bdd10 = scrivi_bdd_due2(gbm,bdd10,var);
    bdd11 = scrivi_bdd_tre2(gbm,bdd11,var); 
    bdd12 = scrivi_bdd_quattro2(gbm,bdd12,var);
    bdd13 = Cudd_bddOr(gbm,bdd9,bdd10); 
    bdd13 = Cudd_bddOr(gbm,bdd11,bdd13); 
    bdd13 = Cudd_bddOr(gbm,bdd12,bdd13); 

    bdd8 = Cudd_bddAnd(gbm,bdd8,bdd13);


    bdd = Cudd_bddOr(gbm,bdd8,bdd);
    Cudd_Ref(bdd);          

//funzioni puback
    
    bdd14 = scrivi_bdd_zero3 (gbm, bdd14, var); 
    bdd15 = scrivi_bdd_uno3(gbm,bdd15,var);
    bdd14 = Cudd_bddAnd(gbm, bdd14, bdd15);
    Cudd_Ref(bdd);         
 
    bdd = Cudd_bddOr(gbm,bdd14,bdd);
    Cudd_Ref(bdd);       
    
//funzioni pubrec

    bdd16 = scrivi_bdd_zero4 (gbm, bdd16, var); 
    bdd17 = scrivi_bdd_uno4(gbm,bdd17,var);

 bdd16 = Cudd_bddAnd(gbm, bdd16, bdd17);

 bdd = Cudd_bddOr(gbm,bdd16,bdd);

 Cudd_Ref(bdd);

//funzioni pubrel

   bdd18 = scrivi_bdd_zero5 (gbm, bdd18, var); 
    bdd19 = scrivi_bdd_uno5(gbm,bdd19,var);

 bdd18 = Cudd_bddAnd(gbm, bdd18, bdd19);

 bdd = Cudd_bddOr(gbm,bdd18,bdd);

 Cudd_Ref(bdd);

 //funzioni pubcomp

   bdd20 = scrivi_bdd_zero6 (gbm, bdd20, var); 
    bdd21 = scrivi_bdd_uno6(gbm,bdd21,var);

 bdd20 = Cudd_bddAnd(gbm, bdd20, bdd21);

 bdd = Cudd_bddOr(gbm,bdd20,bdd);

 Cudd_Ref(bdd);

 //funzioni subscribe

    bdd22 = scrivi_bdd_zero7 (gbm, bdd22, var); 
    bdd23 = scrivi_bdd_uno7(gbm,bdd23,var);
    bdd24 = scrivi_bdd_due7(gbm,bdd24,var);
    bdd25 = scrivi_bdd_tre7(gbm,bdd25,var); 
    bdd22 = Cudd_bddOr(gbm,bdd22,bdd23); 
    bdd22 = Cudd_bddOr(gbm,bdd22,bdd24); 
    bdd22 = Cudd_bddOr(gbm,bdd22,bdd25); 

    bdd = Cudd_bddOr(gbm,bdd22,bdd);
 
    Cudd_Ref(bdd);

//FUNZIONI UNSUBACK
    
    bdd26 = scrivi_bdd_zero8 (gbm, bdd26, var); 
    bdd27 = scrivi_bdd_uno8(gbm,bdd27,var);

    bdd26 = Cudd_bddAnd(gbm, bdd26, bdd27);
 
    bdd = Cudd_bddOr(gbm,bdd26,bdd);
    
    Cudd_Ref(bdd);

//FUNZIONI UNSUBSCRIBE
   
    bdd28 = scrivi_bdd_zero9 (gbm, bdd28, var); 
    bdd29 = scrivi_bdd_uno9(gbm,bdd29,var);
    bdd30 = scrivi_bdd_due9(gbm,bdd30,var);
    bdd31 = scrivi_bdd_tre9(gbm,bdd31,var); 
    bdd28 = Cudd_bddOr(gbm,bdd28,bdd29); 
    bdd28 = Cudd_bddOr(gbm,bdd28,bdd30); 
    bdd28 = Cudd_bddOr(gbm,bdd28,bdd31); 

     bdd = Cudd_bddOr(gbm,bdd28,bdd);
    
    Cudd_Ref(bdd);

  //FUNZIONI PINGREQ
 
   bdd32 = scrivi_bdd_zero10 (gbm, bdd32, var); 
    bdd = Cudd_bddOr(gbm,bdd32,bdd);
    
    Cudd_Ref(bdd);


   //FUNZIONI PINGRESP
 
    bdd33 = scrivi_bdd_zero11 (gbm, bdd33, var); 
    bdd = Cudd_bddOr(gbm,bdd33,bdd);
    Cudd_Ref(bdd);
  
   //FUNZIONI DISCONNECT 

    bdd34 = scrivi_bdd_zero12 (gbm, bdd34, var); 
    
    bdd = Cudd_bddOr(gbm,bdd34,bdd);
    Cudd_Ref(bdd);
    
    //FUNZIONI SUBACK
    bdd40 = scrivi_bdd_zero13 (gbm, bdd40, var); 
    bdd41 = scrivi_bdd_uno13(gbm,bdd41,var);
    bdd42 = scrivi_bdd_due13(gbm,bdd42,var);
    bdd43 = scrivi_bdd_tre13(gbm,bdd43,var); 
    bdd40 = Cudd_bddOr(gbm,bdd40,bdd41); 
    bdd40 = Cudd_bddOr(gbm,bdd40,bdd42); 
    bdd40 = Cudd_bddOr(gbm,bdd40,bdd43); 
    
    bdd = Cudd_bddOr(gbm,bdd40,bdd);
    Cudd_Ref(bdd);

//funzioni coap
    
bdd44 = scrivi_bdd_zerocoap(gbm,bdd44,var);

bdd = Cudd_bddOr(gbm,bdd44,bdd);
Cudd_Ref(bdd);

//funzioni ampq
bdd45 = scrivi_bdd_zeroamqp(gbm,bdd45,var);
bdd46 = scrivi_bdd_zeroamqp_2(gbm,bdd46,var);
bdd47 = Cudd_bddOr(gbm,bdd45,bdd46);

bdd = Cudd_bddOr(gbm,bdd47,bdd);

// primo algoritmo paper per diminuire dim

//Cudd_bddPrintCover_Gennaro(gbm,bdd,bdd);

    int i,j;
    int h = 0;
    
    //allocazioni dinamiche 

   list = (int **)malloc(4 * sizeof(int *));  
    
    for (i=0; i<4; i++) {
         list[i] = (int *)malloc(Cudd_ReadSize(gbm) * sizeof(int));  
    }


    list_def = (int **)malloc(1000 * sizeof(int *));  

    for (i=0; i<1000; i++) {
         list_def[i] = (int *)malloc(Cudd_ReadSize(gbm) * sizeof(int));  
    }

  //  Cudd_BddToCubeArray(gbm,bdd0, list[0]);
  
 //   Cudd_BddToCubeArray(gbm,bdd1, list[1]);
  //  Cudd_BddToCubeArray(gbm,bdd2, list[2]);
  //  Cudd_BddToCubeArray(gbm,bdd3, list[3]);

     //CALCOLO IL VALORE DI T
    int molti = 8;
    int T;
    int p;


    

    DdNode* tmp,*tmp2,*tmp3,*tmp4,*tmp5 ;
    sub[0] = bdd;
    DdNode* lala[1000];

    lala[0] = bdd; 
     
    tmp = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
    Cudd_Ref(tmp); /*Increases the reference count of a node*/
    tmp2 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
    Cudd_Ref(tmp2); /*Increases the reference count of a node*/

    
    // some random index;
    
    int gen=0;
    int gen2=0;
    int xx = 0;
    int nn = 0;
       int bal = 1;
int mn = 0;

    for(xx = 0;xx<(Cudd_ReadSize(gbm)/8);xx++) {
        
	int sal = gen_ind;
    printf("DAMMIII INTERVALLE %d\n",xx); 
       for(p = 0 ;p<bal; p++) {
    
	 boolArray = (bool *) malloc(sizeof(bool) * 2000000000);
        
	 gen2 = gen_ind;	
	
	 T = Cudd_DagSize_gennaro(gbm,lala[p],molti);
         T = ceil(log2(T));
	
 	 printf("IL VALORE DI T %d\n",T);

        

	 if(T == 0 || T < 0 ) {
               T=1;
 	 }else if(T < 0){ 
	   T = 0;
	
	 } 
	
	 int ll = 0;
         
	 for(i = gen2;i<gen_ind;i++){ 
      
	  if(ll == 0 && T==2) {   	
	   tmp = Cudd_bddIthVar(gbm,molti-T);
	   tmp = Cudd_Not(tmp);
           tmp2 = Cudd_bddIthVar(gbm,molti-(T-1));
	   tmp2 = Cudd_Not(tmp2);
	   tmp = Cudd_bddAnd(gbm,tmp,tmp2);
	  } else if (ll == 1 && T == 2) {
	  tmp = Cudd_bddIthVar(gbm,molti-T);
	  tmp = Cudd_Not(tmp);
          tmp2 = Cudd_bddIthVar(gbm,molti-(T-1));
          tmp = Cudd_bddAnd(gbm,tmp,tmp2);
          } else  if (ll == 2 && T == 2) {
	  tmp = Cudd_bddIthVar(gbm,molti-T);
	  tmp = Cudd_Not(tmp);
          tmp2 = Cudd_bddIthVar(gbm,molti-(T-1));
	  tmp2 = Cudd_Not(tmp2);
	  tmp = Cudd_bddAnd(gbm,tmp,tmp2);
	 } else if (ll == 3 && T == 2) {

	  tmp = Cudd_bddIthVar(gbm,molti-T);
          tmp2 = Cudd_bddIthVar(gbm,molti-(T-1));
	  tmp = Cudd_bddAnd(gbm,tmp,tmp2);

	}else if (ll == 0 && T == 1){
	  tmp = Cudd_bddIthVar(gbm,molti-T);
	  tmp = Cudd_Not(tmp);
        }else if (ll == 1 && T == 1) {
	  tmp = Cudd_bddIthVar(gbm,molti-T);
        }else if(ll == 0 && T == 3) {
	   tmp = Cudd_bddIthVar(gbm,molti-T);
	   tmp = Cudd_Not(tmp);
           tmp2 = Cudd_bddIthVar(gbm,molti-(T-1));
	   tmp2 = Cudd_Not(tmp2);
           tmp3 = Cudd_bddIthVar(gbm,molti-(T-2));
	   tmp3 = Cudd_Not(tmp3);
	   tmp = Cudd_bddAnd(gbm,tmp,tmp2);
           tmp = Cudd_bddAnd(gbm,tmp,tmp3);
         } else if(ll == 1 && T == 3) {
	   tmp = Cudd_bddIthVar(gbm,molti-T);
	   tmp = Cudd_Not(tmp);
           tmp2 = Cudd_bddIthVar(gbm,molti-(T-1));
	   tmp2 = Cudd_Not(tmp2);
           tmp3 = Cudd_bddIthVar(gbm,molti-(T-2));
	   tmp = Cudd_bddAnd(gbm,tmp,tmp2);
           tmp = Cudd_bddAnd(gbm,tmp,tmp3);
         }else if(ll == 2 && T == 3) {
	   tmp = Cudd_bddIthVar(gbm,molti-T);
	   tmp = Cudd_Not(tmp);
           tmp2 = Cudd_bddIthVar(gbm,molti-(T-1));
           tmp3 = Cudd_bddIthVar(gbm,molti-(T-2));
	   tmp3 = Cudd_Not(tmp3);
	   tmp = Cudd_bddAnd(gbm,tmp,tmp2);
           tmp = Cudd_bddAnd(gbm,tmp,tmp3);
         } else if(ll == 3 && T == 3) {
	   tmp = Cudd_bddIthVar(gbm,molti-T);
	   tmp = Cudd_Not(tmp);
           tmp2 = Cudd_bddIthVar(gbm,molti-(T-1));
           tmp3 = Cudd_bddIthVar(gbm,molti-(T-2));
	   tmp = Cudd_bddAnd(gbm,tmp,tmp2);
           tmp = Cudd_bddAnd(gbm,tmp,tmp3);
         } else if(ll == 4 && T == 3) {
	   tmp = Cudd_bddIthVar(gbm,molti-T);
           tmp2 = Cudd_bddIthVar(gbm,molti-(T-1));
	   tmp2 = Cudd_Not(tmp2);
           tmp3 = Cudd_bddIthVar(gbm,molti-(T-2));
	   tmp3 = Cudd_Not(tmp3);
	   tmp = Cudd_bddAnd(gbm,tmp,tmp2);
           tmp = Cudd_bddAnd(gbm,tmp,tmp3);
         } else if(ll == 5 && T == 3) {
	   tmp = Cudd_bddIthVar(gbm,molti-T);
           tmp2 = Cudd_bddIthVar(gbm,molti-(T-1));
	   tmp2 = Cudd_Not(tmp2);
           tmp3 = Cudd_bddIthVar(gbm,molti-(T-2));
	   tmp = Cudd_bddAnd(gbm,tmp,tmp2);
           tmp = Cudd_bddAnd(gbm,tmp,tmp3);
         } else if(ll == 6 && T == 3) {
	   tmp = Cudd_bddIthVar(gbm,molti-T);
           tmp2 = Cudd_bddIthVar(gbm,molti-(T-1));
           tmp3 = Cudd_bddIthVar(gbm,molti-(T-2));
	   tmp3 = Cudd_Not(tmp3);
	   tmp = Cudd_bddAnd(gbm,tmp,tmp2);
           tmp = Cudd_bddAnd(gbm,tmp,tmp3);
         }  else if(ll == 7&& T == 3) {
	   tmp = Cudd_bddIthVar(gbm,molti-T);
           tmp2 = Cudd_bddIthVar(gbm,molti-(T-1));
           tmp3 = Cudd_bddIthVar(gbm,molti-(T-2));
	   tmp = Cudd_bddAnd(gbm,tmp,tmp2);
           tmp = Cudd_bddAnd(gbm,tmp,tmp3);
         } else if(ll == 0 && T == 4) {
	   printf("entro qui\n");
           tmp = Cudd_bddIthVar(gbm,molti-T);
	   tmp = Cudd_Not(tmp);
	   tmp2 = Cudd_bddIthVar(gbm,molti-(T-1));
	   tmp2 = Cudd_Not(tmp2);
	   tmp3 = Cudd_bddIthVar(gbm,molti-(T-2));
	   tmp3 = Cudd_Not(tmp3);
           tmp4 = Cudd_bddIthVar(gbm,molti-(T-3));
	   tmp4 = Cudd_Not(tmp4);
	   tmp = Cudd_bddAnd(gbm,tmp,tmp2);
           tmp = Cudd_bddAnd(gbm,tmp,tmp3);
           tmp = Cudd_bddAnd(gbm,tmp,tmp4);

	 } else if(ll == 1 && T == 4) {
	   tmp = Cudd_bddIthVar(gbm,molti-T);
	   tmp = Cudd_Not(tmp);
           tmp2 = Cudd_bddIthVar(gbm,molti-(T-1));
	   tmp2 = Cudd_Not(tmp2);
           tmp3 = Cudd_bddIthVar(gbm,molti-(T-2));
	   tmp3 = Cudd_Not(tmp3);
           tmp4 = Cudd_bddIthVar(gbm,molti-(T-3));
	   tmp = Cudd_bddAnd(gbm,tmp,tmp2);
           tmp = Cudd_bddAnd(gbm,tmp,tmp3);
           tmp = Cudd_bddAnd(gbm,tmp,tmp4);


	 
	 }else if(ll == 2 && T == 4) {
	   tmp = Cudd_bddIthVar(gbm,molti-T);
	   tmp = Cudd_Not(tmp);
           tmp2 = Cudd_bddIthVar(gbm,molti-(T-1));
           tmp2 = Cudd_Not(tmp2);
           tmp3 = Cudd_bddIthVar(gbm,molti-(T-2));
           tmp4 = Cudd_bddIthVar(gbm,molti-(T-3));
	   tmp4 = Cudd_Not(tmp4);
	   tmp = Cudd_bddAnd(gbm,tmp,tmp2);
           tmp = Cudd_bddAnd(gbm,tmp,tmp3);
           tmp = Cudd_bddAnd(gbm,tmp,tmp4);
	
	 } else if(ll == 3 && T == 4) {
	   tmp = Cudd_bddIthVar(gbm,molti-T);
	   tmp = Cudd_Not(tmp);
           tmp2 = Cudd_bddIthVar(gbm,molti-(T-1));
	   tmp2 = Cudd_Not(tmp2);
           tmp3 = Cudd_bddIthVar(gbm,molti-(T-2));
           tmp4 = Cudd_bddIthVar(gbm,molti-(T-3));
	   tmp = Cudd_bddAnd(gbm,tmp,tmp2);
           tmp = Cudd_bddAnd(gbm,tmp,tmp3);
           tmp = Cudd_bddAnd(gbm,tmp,tmp4);
	            
	 
	 }
	  else if(ll == 4 && T == 4) {
	   tmp = Cudd_bddIthVar(gbm,molti-T);
	   tmp = Cudd_Not(tmp);
           tmp2 = Cudd_bddIthVar(gbm,molti-(T-1));
           tmp3 = Cudd_bddIthVar(gbm,molti-(T-2));
	   tmp3 = Cudd_Not(tmp3);
           tmp4 = Cudd_bddIthVar(gbm,molti-(T-3));
	   tmp4 = Cudd_Not(tmp4);
	   tmp = Cudd_bddAnd(gbm,tmp,tmp2);
           tmp = Cudd_bddAnd(gbm,tmp,tmp3);
           tmp = Cudd_bddAnd(gbm,tmp,tmp4);
         
	  
	  } else if(ll == 5 && T == 4) {
	    
	   tmp = Cudd_bddIthVar(gbm,molti-T);
	   tmp = Cudd_Not(tmp);
           tmp2 = Cudd_bddIthVar(gbm,molti-(T-1));
           tmp3 = Cudd_bddIthVar(gbm,molti-(T-2));
	   tmp3 = Cudd_Not(tmp3);
           tmp4 = Cudd_bddIthVar(gbm,molti-(T-3));
	   tmp = Cudd_bddAnd(gbm,tmp,tmp2);
           tmp = Cudd_bddAnd(gbm,tmp,tmp3);
           tmp = Cudd_bddAnd(gbm,tmp,tmp4);
    	  
	  } else if(ll == 6 && T == 4) {
         
	   tmp = Cudd_bddIthVar(gbm,molti-T);
	   tmp = Cudd_Not(tmp);
           tmp2 = Cudd_bddIthVar(gbm,molti-(T-1));
           tmp3 = Cudd_bddIthVar(gbm,molti-(T-2));
           tmp4 = Cudd_bddIthVar(gbm,molti-(T-3));
	   tmp4 = Cudd_Not(tmp4);
	   tmp = Cudd_bddAnd(gbm,tmp,tmp2);
           tmp = Cudd_bddAnd(gbm,tmp,tmp3);
           tmp = Cudd_bddAnd(gbm,tmp,tmp4);
	  
	  }  else if(ll == 7 && T == 4) {
	   
	   tmp = Cudd_bddIthVar(gbm,molti-T);
	   tmp = Cudd_Not(tmp);
           tmp2 = Cudd_bddIthVar(gbm,molti-(T-1));
           tmp3 = Cudd_bddIthVar(gbm,molti-(T-2));
           tmp4 = Cudd_bddIthVar(gbm,molti-(T-3));
	   tmp = Cudd_bddAnd(gbm,tmp,tmp2);
           tmp = Cudd_bddAnd(gbm,tmp,tmp3);
           tmp = Cudd_bddAnd(gbm,tmp,tmp4);
   
	  } 
           else if(ll == 8 && T == 4) {
	   
	   tmp = Cudd_bddIthVar(gbm,molti-T);
           tmp2 = Cudd_bddIthVar(gbm,molti-(T-1));
	   tmp2 = Cudd_Not(tmp2);
           tmp3 = Cudd_bddIthVar(gbm,molti-(T-2));
	   tmp3 = Cudd_Not(tmp3);
           tmp4 = Cudd_bddIthVar(gbm,molti-(T-3));
	   tmp4 = Cudd_Not(tmp4);
	   tmp = Cudd_bddAnd(gbm,tmp,tmp2);
           tmp = Cudd_bddAnd(gbm,tmp,tmp3);
           tmp = Cudd_bddAnd(gbm,tmp,tmp4);
   
	  }  else if(ll == 9 && T == 4) {
	   
	   tmp = Cudd_bddIthVar(gbm,molti-T);
           tmp2 = Cudd_bddIthVar(gbm,molti-(T-1));
	   tmp2 = Cudd_Not(tmp2);
           tmp3 = Cudd_bddIthVar(gbm,molti-(T-2));
	   tmp3 = Cudd_Not(tmp3);
           tmp4 = Cudd_bddIthVar(gbm,molti-(T-3));
	   tmp = Cudd_bddAnd(gbm,tmp,tmp2);
           tmp = Cudd_bddAnd(gbm,tmp,tmp3);
           tmp = Cudd_bddAnd(gbm,tmp,tmp4);
   
	  }  else if(ll == 10 && T == 4) {
	   
	   tmp = Cudd_bddIthVar(gbm,molti-T);
           tmp2 = Cudd_bddIthVar(gbm,molti-(T-1));
	   tmp2 = Cudd_Not(tmp2);
           tmp3 = Cudd_bddIthVar(gbm,molti-(T-2));
           tmp4 = Cudd_bddIthVar(gbm,molti-(T-3));
	   tmp4 = Cudd_Not(tmp4);
	   tmp = Cudd_bddAnd(gbm,tmp,tmp2);
           tmp = Cudd_bddAnd(gbm,tmp,tmp3);
           tmp = Cudd_bddAnd(gbm,tmp,tmp4);
   
	  }  else if(ll == 11 && T == 4) {
	   
	   tmp = Cudd_bddIthVar(gbm,molti-T);
           tmp2 = Cudd_bddIthVar(gbm,molti-(T-1));
	   tmp2 = Cudd_Not(tmp2);
           tmp3 = Cudd_bddIthVar(gbm,molti-(T-2));
           tmp4 = Cudd_bddIthVar(gbm,molti-(T-3));
	   tmp = Cudd_bddAnd(gbm,tmp,tmp2);
           tmp = Cudd_bddAnd(gbm,tmp,tmp3);
           tmp = Cudd_bddAnd(gbm,tmp,tmp4);
   
	  }  else if(ll == 12 && T == 4) {
	   
	   tmp = Cudd_bddIthVar(gbm,molti-T);
           tmp2 = Cudd_bddIthVar(gbm,molti-(T-1));
	   tmp3 = Cudd_bddIthVar(gbm,molti-(T-2));
	   tmp3 = Cudd_Not(tmp3);
           tmp4 = Cudd_bddIthVar(gbm,molti-(T-3));
	   tmp4 = Cudd_Not(tmp4);
	   tmp = Cudd_bddAnd(gbm,tmp,tmp2);
           tmp = Cudd_bddAnd(gbm,tmp,tmp3);
           tmp = Cudd_bddAnd(gbm,tmp,tmp4);
   
	  }  else if(ll == 13 && T == 4) {
	   
	   tmp = Cudd_bddIthVar(gbm,molti-T);
           tmp2 = Cudd_bddIthVar(gbm,molti-(T-1));
           tmp3 = Cudd_bddIthVar(gbm,molti-(T-2));
	   tmp3 = Cudd_Not(tmp3);
           tmp4 = Cudd_bddIthVar(gbm,molti-(T-3));
	   tmp = Cudd_bddAnd(gbm,tmp,tmp2);
           tmp = Cudd_bddAnd(gbm,tmp,tmp3);
           tmp = Cudd_bddAnd(gbm,tmp,tmp4);
   
	  }  else if(ll == 14 && T == 4) {
	   
	   tmp = Cudd_bddIthVar(gbm,molti-T);
           tmp2 = Cudd_bddIthVar(gbm,molti-(T-1));
           tmp3 = Cudd_bddIthVar(gbm,molti-(T-2));
           tmp4 = Cudd_bddIthVar(gbm,molti-(T-3));
	   tmp4 = Cudd_Not(tmp4);
	   tmp = Cudd_bddAnd(gbm,tmp,tmp2);
           tmp = Cudd_bddAnd(gbm,tmp,tmp3);
           tmp = Cudd_bddAnd(gbm,tmp,tmp4);
   
	  }  else if(ll == 15 && T == 4) {
	   
	   tmp = Cudd_bddIthVar(gbm,molti-T);
           tmp2 = Cudd_bddIthVar(gbm,molti-(T-1));
           tmp3 = Cudd_bddIthVar(gbm,molti-(T-2));
           tmp4 = Cudd_bddIthVar(gbm,molti-(T-3));
	   tmp = Cudd_bddAnd(gbm,tmp,tmp2);
           tmp = Cudd_bddAnd(gbm,tmp,tmp3);
           tmp = Cudd_bddAnd(gbm,tmp,tmp4);
   
	  } 
        
//	Cudd_PrintMinterm(gbm,sub[i]);

        sub[i] = Cudd_bddAnd(gbm,sub[i],tmp); 
        
	lala[mn] = sub[i];
	printf("valore di i: %d\n", i);
        Cudd_PrintMinterm(gbm,lala[mn]);
printf("risultato : %d\n",Cudd_V(lala[mn]));        
	mn++;
	printf("STACCO\n"); 
       
	ll++;
	}

    }

  mn = 0;  
  bal = gen_ind - sal; 
  printf("la differenza %d\n",bal);
  molti = molti + 8;  
    
    }



//bdd = Cudd_BddToAdd(gbm, bdd100); /*Convert BDD to ADD for display purpose*/
//print_dd (gbm, bdd, 2,2);   /*Print the dd to standard output*/

sprintf(filename, "./bdd/graph.dot"); /*Write .dot filename to a string*/
    write_dd(gbm, bdd, filename);  /*Write the resulting cascade dd to a file*/
    Cudd_Quit(gbm);
    return 0; 

}
