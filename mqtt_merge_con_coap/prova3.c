
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
DdNode * final[96000];
int gen_ind = 1 ;
int cube = 0;
int spezzo = 0;
DdNode* sub[1000];
DdNode* sub_spezzato[10000];
int grande;
int** list;
int**  list_def;

int* codifica_num;
int codifica_ind[100000][1000];
int* codifica_gen_ind;
int leaf_index = 0;

bool* boolArray;
typedef uintptr_t ptruint;

int ddDagInt_gennaro(DdManager* gbm,DdNode * n,int taglio_max,int direzione,int* listone,int loindice)
{
    int tval, eval;
  //  printf("\n");

//printf("la direzione %d %d\n",direzione,Cudd_NodeReadIndex(n));
   // DdNode *s = Cudd_E(n);
   //printf("IL LIVELLO %d E L'INDICE %d TOTALE %d\n",Cudd_ReadIndex(gbm,Cudd_NodeReadIndex(n)),Cudd_NodeReadIndex(n),Cudd_ReadSize(gbm));
    
   if (Cudd_ReadIndex(gbm,Cudd_NodeReadIndex(n)) < Cudd_ReadIndex(gbm,taglio_max) )
    {  
	    //Cudd_PrintMinterm(gbm,n);
listone[loindice] = direzione;
	   
//printf("\n") ;
//DdNode* dai = Cudd_CubeArrayToBdd(gbm,listone);
//Cudd_PrintMinterm(gbm,dai);
	    
if(Cudd_IsComplement(n)){	    
  
  tval = ddDagInt_gennaro(gbm,Cudd_Not(Cudd_Regular(Cudd_T(n))),taglio_max,1,listone,Cudd_NodeReadIndex(n));
  eval = ddDagInt_gennaro(gbm,Cudd_Not(Cudd_Regular(Cudd_E(n))),taglio_max,0,listone,Cudd_NodeReadIndex(n));

} else {

  tval = ddDagInt_gennaro(gbm,Cudd_Regular(Cudd_T(n)),taglio_max,1,listone,Cudd_NodeReadIndex(n));
  eval = ddDagInt_gennaro(gbm,Cudd_Regular(Cudd_E(n)),taglio_max,0,listone,Cudd_NodeReadIndex(n));


}
   return(tval + eval);
       
  } else if (Cudd_NodeReadIndex(n) > 300)
  
  {
           //istruzione per i nodi fuori range li ingnoro;	            
	   return(0);
  
  } else {
printf("vediamo l'array\n"); 

//printf("\n");      
        listone[loindice] = direzione;

        DdNode* dai = Cudd_CubeArrayToBdd(gbm,listone);
        
	Cudd_PrintMinterm(gbm,dai);
        
	int foglie = (ptruint)n ;  
        printf("le foglie %d\n",foglie);
        int foglie2 = foglie>>14;
        printf("le foglie mod %d\n",foglie2);
       
	//Cudd_PrintMinterm(gbm,dai);
	int i,j;

        
//	for (i = 0; i < grande; i++) {
   
//	       	listone[i] = 2;
//        }
	
	sub_spezzato[gen_ind] = dai;
        Cudd_Ref(sub_spezzato[gen_ind]);   
	
	if(boolArray[foglie] == false) {    
         codifica_gen_ind[foglie] = leaf_index;

	}
	codifica_ind[codifica_gen_ind[foglie]][gen_ind] = 1;	
    	
  	gen_ind++;
	
	
	//per vedere se non ho fatto lo stesso percorso.	
	if(boolArray[foglie] == false) {    
    
           boolArray[foglie] = true;
	   codifica_num[leaf_index] = foglie; 
	   leaf_index++;
        
         return(1);
       } else {   
	 return(0);
        
        }
       
    } 
}




int Cudd_DagSize_gennaro(DdManager*gbm,DdNode * node,int taglio_max)
{
    int i,j;
    int* listone;
    DdNode * s = Cudd_E(node);
    DdNode * e = Cudd_T(node);
    
    listone = (int *) malloc(sizeof(int)* Cudd_ReadSize(gbm));

    for (i = 0; i < Cudd_ReadSize(gbm); i++) {
    listone[i] = 2;
    }
   
 
 //  listone[Cudd_NodeReadIndex(node)] = 0;
     
    printf("dammi l'input\n");
    Cudd_PrintMinterm(gbm,node);	
 
     i = ddDagInt_gennaro(gbm,node,taglio_max,0,listone,Cudd_NodeReadIndex(node));
   
  
   
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
/*
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
*/
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
/*
    bdd22 = scrivi_bdd_zero7 (gbm, bdd22, var); 
    bdd23 = scrivi_bdd_uno7(gbm,bdd23,var);
    bdd24 = scrivi_bdd_due7(gbm,bdd24,var);
    bdd25 = scrivi_bdd_tre7(gbm,bdd25,var); 
    bdd22 = Cudd_bddOr(gbm,bdd22,bdd23); 
    bdd22 = Cudd_bddOr(gbm,bdd22,bdd24); 
    bdd22 = Cudd_bddOr(gbm,bdd22,bdd25); 

    bdd = Cudd_bddOr(gbm,bdd22,bdd);
 
    Cudd_Ref(bdd);
*/
//FUNZIONI UNSUBACK
    
    bdd26 = scrivi_bdd_zero8 (gbm, bdd26, var); 
    bdd27 = scrivi_bdd_uno8(gbm,bdd27,var);

    bdd26 = Cudd_bddAnd(gbm, bdd26, bdd27);
 
    bdd = Cudd_bddOr(gbm,bdd26,bdd);
    
    Cudd_Ref(bdd);

//FUNZIONI UNSUBSCRIBE
  /* 
    bdd28 = scrivi_bdd_zero9 (gbm, bdd28, var); 
    bdd29 = scrivi_bdd_uno9(gbm,bdd29,var);
    bdd30 = scrivi_bdd_due9(gbm,bdd30,var);
    bdd31 = scrivi_bdd_tre9(gbm,bdd31,var); 
    bdd28 = Cudd_bddOr(gbm,bdd28,bdd29); 
    bdd28 = Cudd_bddOr(gbm,bdd28,bdd30); 
    bdd28 = Cudd_bddOr(gbm,bdd28,bdd31); 

     bdd = Cudd_bddOr(gbm,bdd28,bdd);
    
    Cudd_Ref(bdd);
*/
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
 /*   
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
*/
//funzioni coap
    
   // bdd44 = scrivi_bdd_zerocoap(gbm,bdd44,var);

   // bdd = Cudd_bddOr(gbm,bdd44,bdd);
   // Cudd_Ref(bdd);

//funzioni ampq
    
  //  bdd45 = scrivi_bdd_zeroamqp(gbm,bdd45,var);
  //  bdd46 = scrivi_bdd_zeroamqp_2(gbm,bdd46,var);
  //  bdd47 = Cudd_bddOr(gbm,bdd45,bdd46);

  //  bdd = Cudd_bddOr(gbm,bdd47,bdd);

// primo algoritmo paper per diminuire dim

//Cudd_bddPrintCover_Gennaro(gbm,bdd,bdd);

    int i,j;
    int h = 0;
    
    //allocazioni dinamiche 

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

 codifica_num = (int *) malloc(sizeof(int)* 20000);
    
    // some random index;
   
    int gen=0;
    int gen2=0;
    int xx = 0;
    int nn = 0;
    int bal = 1;
    int mn = 0;
    grande = Cudd_ReadSize(gbm); 
    DdNode * g1[10000];
    DdNode * g2[10000];

    g2[0] = bdd;
    
    for(i = 0; i < 10000;i++) {
      g1[i] = Cudd_ReadOne(gbm); 
      Cudd_Ref(g1[i]);
    }
/*
 codifica_ind = (int **)malloc(100000 * sizeof(int *));  

    for (i=0; i<1000; i++) {
         codifica_ind[i] = (int *)malloc(1000 * sizeof(int));  
    }
*/
    for(xx = 0;xx<(grande/8);xx++) {
         printf("molti %d\n",molti);  
    
	 boolArray = (bool *) malloc(sizeof(bool) * 2000000000);
         codifica_gen_ind = (int *) malloc(sizeof(int) * 200000000);
    
	 gen2 = gen_ind;	
	 T = Cudd_DagSize_gennaro(gbm,g2[xx],molti);
         T = ceil(log2(T));
	
        if(T == 0) {
           T = 1;
	 }

 	// printf("IL VALORE DI T %d\n",T);
	if (T == 1) {
        tmp = Cudd_bddNewVarAtLevel(gbm,molti+(Cudd_ReadSize(gbm) - grande ));
	} else if (T == 2) {
        tmp3 = Cudd_bddNewVarAtLevel(gbm,molti+(Cudd_ReadSize(gbm) - grande ));
        
	tmp2 = Cudd_bddNewVarAtLevel(gbm,molti+(Cudd_ReadSize(gbm) - grande ));


	}else if (T == 3){
        tmp4 = Cudd_bddNewVarAtLevel(gbm,molti+(Cudd_ReadSize(gbm) - grande ));
        
	tmp2 = Cudd_bddNewVarAtLevel(gbm,molti+(Cudd_ReadSize(gbm) - grande ));
	tmp3 = Cudd_bddNewVarAtLevel(gbm,molti+(Cudd_ReadSize(gbm) - grande ));


   }else if(T == 4) {
        
	tmp5 = Cudd_bddNewVarAtLevel(gbm,molti+(Cudd_ReadSize(gbm) - grande ));
        tmp2 = Cudd_bddNewVarAtLevel(gbm,molti+(Cudd_ReadSize(gbm) - grande ));
	tmp3 = Cudd_bddNewVarAtLevel(gbm,molti+(Cudd_ReadSize(gbm) - grande ));
	tmp4 = Cudd_bddNewVarAtLevel(gbm,molti+(Cudd_ReadSize(gbm) - grande ));



	}


	 int ll = 0;
	 int mm = 0;
         printf("l'indice delle foglie finali %d\n",leaf_index);

    while (mm < leaf_index) {

	  if(ll == 0 && T==2) {   	
	   tmp3 = Cudd_Not(tmp3);
           tmp2 = Cudd_Not(tmp2);
           tmp = Cudd_bddAnd(gbm,tmp3,tmp2);
         } else if (ll == 1 && T == 2) {
	   tmp2 = Cudd_Not(tmp2);
           tmp = Cudd_bddAnd(gbm,tmp3,tmp2);
         } else  if (ll == 2 && T == 2) {
	   tmp3 = Cudd_Not(tmp3);
	   tmp2 = Cudd_Not(tmp2);
           tmp = Cudd_bddAnd(gbm,tmp3,tmp2);
	  } else if (ll == 3 && T == 2) {
           
	   tmp2 = Cudd_Not(tmp2);
           tmp = Cudd_bddAnd(gbm,tmp3,tmp2);
 
	 }else if (ll == 0 && T == 1){
	   tmp = Cudd_Not(tmp);
          }else if (ll == 1 && T == 1) {
	   tmp = Cudd_Not(tmp);
	  }else if(ll == 0 && T == 3) {
	   tmp4 = Cudd_Not(tmp4);
	   tmp2 = Cudd_Not(tmp2);
	   tmp3 = Cudd_Not(tmp3);
           tmp = Cudd_bddAnd(gbm,tmp3,tmp2);
           tmp = Cudd_bddAnd(gbm,tmp,tmp4);
         
	  } else if(ll == 1 && T == 3) {
	   tmp3 = Cudd_Not(tmp3);

           tmp = Cudd_bddAnd(gbm,tmp3,tmp2);
           tmp = Cudd_bddAnd(gbm,tmp,tmp4);
          }else if(ll == 2 && T == 3) {
	   tmp2 = Cudd_Not(tmp2);
	   tmp3 = Cudd_Not(tmp3);
	   
           tmp = Cudd_bddAnd(gbm,tmp3,tmp2);
           tmp = Cudd_bddAnd(gbm,tmp,tmp4);
	  } else if(ll == 3 && T == 3) {
	   tmp3 = Cudd_Not(tmp3);
           
           tmp = Cudd_bddAnd(gbm,tmp3,tmp2);
           tmp = Cudd_bddAnd(gbm,tmp,tmp4);
	  } else if(ll == 4 && T == 3) {
           
           tmp4 = Cudd_Not(tmp4);
	   tmp2 = Cudd_Not(tmp2);
	   tmp3 = Cudd_Not(tmp3);
        
           tmp = Cudd_bddAnd(gbm,tmp3,tmp2);
           tmp = Cudd_bddAnd(gbm,tmp,tmp4);
	  } else if(ll == 5 && T == 3) {
	   tmp3 = Cudd_Not(tmp3);
         
           tmp = Cudd_bddAnd(gbm,tmp3,tmp2);
           tmp = Cudd_bddAnd(gbm,tmp,tmp4);
	  } else if(ll == 6 && T == 3) {
	   tmp2 = Cudd_Not(tmp2);
	   tmp3 = Cudd_Not(tmp3);
	 
           tmp = Cudd_bddAnd(gbm,tmp3,tmp2);
           tmp = Cudd_bddAnd(gbm,tmp,tmp4);
	 }  else if(ll == 7&& T == 3) {
	  
           tmp3 = Cudd_Not(tmp3);
           
           tmp = Cudd_bddAnd(gbm,tmp3,tmp2);
           tmp = Cudd_bddAnd(gbm,tmp,tmp4);
         } else if(ll == 0 && T == 4) {
	   tmp5 = Cudd_Not(tmp5);
	   tmp2 = Cudd_Not(tmp2);
	   tmp3 = Cudd_Not(tmp3);
	   tmp4 = Cudd_Not(tmp4);
           tmp = Cudd_bddAnd(gbm,tmp3,tmp2);
           tmp = Cudd_bddAnd(gbm,tmp,tmp4);
           tmp = Cudd_bddAnd(gbm,tmp,tmp5);

	 } else if(ll == 1 && T == 4) {
	   tmp4 = Cudd_Not(tmp4);
           tmp = Cudd_bddAnd(gbm,tmp3,tmp2);
           tmp = Cudd_bddAnd(gbm,tmp,tmp4);
           tmp = Cudd_bddAnd(gbm,tmp,tmp5);
	 
	 }else if(ll == 2 && T == 4) {
	   
	   tmp3 = Cudd_Not(tmp3);
	   tmp4 = Cudd_Not(tmp4);
           tmp = Cudd_bddAnd(gbm,tmp3,tmp2);
           tmp = Cudd_bddAnd(gbm,tmp,tmp4);
           tmp = Cudd_bddAnd(gbm,tmp,tmp5);
	
	 } else if(ll == 3 && T == 4) {
	            
	   tmp4 = Cudd_Not(tmp4);
           tmp = Cudd_bddAnd(gbm,tmp3,tmp2);
           tmp = Cudd_bddAnd(gbm,tmp,tmp4);
           tmp = Cudd_bddAnd(gbm,tmp,tmp5);
	 
	 }
	  else if(ll == 4 && T == 4) {
	   tmp2 = Cudd_Not(tmp2);
	   
           tmp3 = Cudd_Not(tmp3);
	   tmp4 = Cudd_Not(tmp4);
           tmp = Cudd_bddAnd(gbm,tmp3,tmp2);
           tmp = Cudd_bddAnd(gbm,tmp,tmp4);
           tmp = Cudd_bddAnd(gbm,tmp,tmp5);
	
         
	  
	  } else if(ll == 5 && T == 4) {
	    
	   tmp4 = Cudd_Not(tmp4);
           tmp = Cudd_bddAnd(gbm,tmp3,tmp2);
           tmp = Cudd_bddAnd(gbm,tmp,tmp4);
           tmp = Cudd_bddAnd(gbm,tmp,tmp5);
    	  
	  } else if(ll == 6 && T == 4) {
         
           tmp3 = Cudd_Not(tmp3);
	   tmp4 = Cudd_Not(tmp4);
           tmp = Cudd_bddAnd(gbm,tmp3,tmp2);
           tmp = Cudd_bddAnd(gbm,tmp,tmp4);
           tmp = Cudd_bddAnd(gbm,tmp,tmp5);
	  
	  }  else if(ll == 7 && T == 4) {
	   tmp4 = Cudd_Not(tmp4);
           tmp = Cudd_bddAnd(gbm,tmp3,tmp2);
           tmp = Cudd_bddAnd(gbm,tmp,tmp4);
           tmp = Cudd_bddAnd(gbm,tmp,tmp5);
   
	  } 
           else if(ll == 8 && T == 4) {
	   tmp5 = Cudd_Not(tmp5);
	   tmp2 = Cudd_Not(tmp2);
	   tmp3 = Cudd_Not(tmp3);
	   tmp4 = Cudd_Not(tmp4);
           tmp = Cudd_bddAnd(gbm,tmp3,tmp2);
           tmp = Cudd_bddAnd(gbm,tmp,tmp4);
           tmp = Cudd_bddAnd(gbm,tmp,tmp5);
	   
   
	  }  else if(ll == 9 && T == 4) {
	
	   tmp4 = Cudd_Not(tmp4);
           tmp = Cudd_bddAnd(gbm,tmp3,tmp2);
           tmp = Cudd_bddAnd(gbm,tmp,tmp4);
           tmp = Cudd_bddAnd(gbm,tmp,tmp5);
   
   
	  }  else if(ll == 10 && T == 4) {
	   tmp3 = Cudd_Not(tmp3);
	   tmp4 = Cudd_Not(tmp4);
	   
           tmp = Cudd_bddAnd(gbm,tmp3,tmp2);
           tmp = Cudd_bddAnd(gbm,tmp,tmp4);
           tmp = Cudd_bddAnd(gbm,tmp,tmp5);
   
	  }  else if(ll == 11 && T == 4) {
	   tmp4 = Cudd_Not(tmp4);
           tmp = Cudd_bddAnd(gbm,tmp3,tmp2);
           tmp = Cudd_bddAnd(gbm,tmp,tmp4);
           tmp = Cudd_bddAnd(gbm,tmp,tmp5);
	   
   
	  }  else if(ll == 12 && T == 4) {
	   tmp2 = Cudd_Not(tmp2);
	   tmp3 = Cudd_Not(tmp3);
	   tmp4 = Cudd_Not(tmp4);
           tmp = Cudd_bddAnd(gbm,tmp3,tmp2);
           tmp = Cudd_bddAnd(gbm,tmp,tmp4);
           tmp = Cudd_bddAnd(gbm,tmp,tmp5);
	      
	  }  else if(ll == 13 && T == 4) {
	   tmp4 = Cudd_Not(tmp4);
           tmp = Cudd_bddAnd(gbm,tmp3,tmp2);
           tmp = Cudd_bddAnd(gbm,tmp,tmp4);
           tmp = Cudd_bddAnd(gbm,tmp,tmp5);
	   
   
	  }  else if(ll == 14 && T == 4) {
	   
	   tmp3 = Cudd_Not(tmp3);
	   tmp4 = Cudd_Not(tmp4);
           tmp = Cudd_bddAnd(gbm,tmp3,tmp2);
           tmp = Cudd_bddAnd(gbm,tmp,tmp4);
           tmp = Cudd_bddAnd(gbm,tmp,tmp5);
   
	  }  else if(ll == 15 && T == 4) {
	   
	   tmp4 = Cudd_Not(tmp4);
           tmp = Cudd_bddAnd(gbm,tmp3,tmp2);
           tmp = Cudd_bddAnd(gbm,tmp,tmp4);
           tmp = Cudd_bddAnd(gbm,tmp,tmp5);
   
	  } 
    
	 for(i = gen2;i<gen_ind;i++){ 
	  
   if(codifica_ind[codifica_gen_ind[codifica_num[mm]]][i] == 1) {   	 
  
	 // Cudd_PrintMinterm(gbm,tmp);
	// printf("SPEZZAAA\n"); 
	  sub_spezzato[i] = Cudd_Not(sub_spezzato[i]);
	  sub_spezzato[i] = Cudd_bddOr(gbm,sub_spezzato[i],tmp); 
	
	}


    
 	 }
          
	 ll++;
         mm++;
    
    }

    leaf_index = 0;
for(i = gen2; i<gen_ind;i++) {

     g1[xx]= Cudd_bddAnd(gbm,g1[xx],sub_spezzato[i]); 
     printf("lospezzo\n");
     
  }
  
//  printf("CON COSA FACCIAMO AND  \n");
  
//  Cudd_PrintMinterm(gbm,g2[xx]);
     
  g1[xx] = Cudd_bddAnd(gbm,g1[xx],g2[xx]);
  
  //printf("vediamo g1 senza restrizione\n");
  //Cudd_PrintMinterm(gbm,g1[xx]);

  DdNode * cube;
  DdNode * cube1;
  DdNode * cube2;
  DdNode * cube3;

  cube = Cudd_ReadOne(gbm); 
  Cudd_Ref(cube);
  cube3 = Cudd_ReadOne(gbm); 
  Cudd_Ref(cube3);

  for(i = molti; i < 98; i++) 
  {
   cube1 = Cudd_bddIthVar(gbm,i);
   cube = Cudd_bddAnd(gbm,cube1,cube);
  }
  
  for(i = 0;i<molti;i++) {
   cube2 = Cudd_bddIthVar(gbm,i);
   cube3 = Cudd_bddAnd(gbm,cube3,cube2);
  }


  printf("avanti\n");
  
  g2[xx+1] = Cudd_bddExistAbstract(gbm,g1[xx],cube3);
  
  g1[xx] = Cudd_bddExistAbstract(gbm,g1[xx], cube);
	 
  Cudd_PrintMinterm(gbm,g1[xx]);

  printf("E POI G2 \n");
  
  Cudd_PrintMinterm(gbm,g2[xx+1]);

// Cudd_PrintMinterm(gbm,copy_sub[1]);

    printf("finito\n");

    bdd = Cudd_BddToAdd(gbm, g1[xx]);  
    sprintf(filename, "./bdd/graph.dot"); 
    write_dd(gbm, bdd, filename); 
    ////getchar();
    
  

    
    
  
     molti = molti + 8;  
  
	 
	 
	 
	 }



//bdd = Cudd_BddToAdd(gbm, bdd100); /*Convert BDD to ADD for display purpose*/
//print_dd (gbm, bdd, 2,2);   /*Print the dd to standard output*/

//sprintf(filename, "./bdd/graph.dot"); /*Write .dot filename to a string*/
  //  write_dd(gbm, bdd, filename);  /*Write the resulting cascade dd to a file*/
  

   // Cudd_Quit(gbm);
    return 0; 

}
