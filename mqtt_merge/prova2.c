
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
    DdNode *bdd,*bdd1,*bdd2,*bdd3,*bdd4,
	 *bdd5,*bdd6,*bdd7,*bdd8,*bdd9,*bdd10,*bdd11,*bdd12,*bdd13,*bdd14,*bdd15,*bdd16,*bdd17,*bdd18,*bdd19,*bdd20,*bdd21,*bdd22,*bdd23,*bdd24,*bdd25,*bdd26,*bdd27,*bdd28,*bdd29,*bdd30,*bdd31,*bdd32,*bdd33,*bdd34,*bdd35,*bdd36,*bdd37,*bdd38,*bdd39,*bdd40,*bdd41,*bdd42,*bdd43,*bdd44,*var;
    DdNode *tmp1;
    

    bdd = scrivi_bdd_zero (gbm, bdd, var); 
    bdd1 = scrivi_bdd_uno(gbm,bdd1,var);
    bdd2 = scrivi_bdd_due(gbm,bdd2,var);
    bdd3 = scrivi_bdd_tre(gbm,bdd3,var); 
    bdd = Cudd_bddOr(gbm,bdd,bdd1); 
    bdd = Cudd_bddOr(gbm,bdd,bdd2); 
    bdd = Cudd_bddOr(gbm,bdd,bdd3); 

    Cudd_Ref(bdd);          /*Update the reference count for the node just created.*/
   
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
    Cudd_Ref(bdd);          /*Update the reference count for the node just created.*/

//funzioni puback
    
    bdd14 = scrivi_bdd_zero3 (gbm, bdd14, var); 
    bdd15 = scrivi_bdd_uno3(gbm,bdd15,var);
    bdd14 = Cudd_bddAnd(gbm, bdd14, bdd15);
    Cudd_Ref(bdd);          /*Update the reference count for the node just created.*/
 
    bdd = Cudd_bddOr(gbm,bdd14,bdd);
    Cudd_Ref(bdd);          /*Update the reference count for the node just created.*/
    
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
 
   // le mie prove!

   bdd37 = bdd; //f-
   bdd38 = bdd;  //f+
   int l; 
   bdd39 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
   Cudd_Ref(bdd39); /*Increases the reference count of a node*/
 
   for(l=0;l<3;l++){ 
   bdd35 = Cudd_LargestCube(gbm,bdd37, NULL); //c
   bdd36 = Cudd_bddMakePrime(gbm,bdd35,bdd38);  //p
   bdd39 = Cudd_bddOr(gbm,bdd39,bdd36);

   bdd38 = Cudd_bddOr(gbm,bdd38,bdd36);
   bdd37 = Cudd_bddAnd(gbm,bdd37,bdd36);
   }

    bdd = Cudd_BddToAdd(gbm, bdd); /*Convert BDD to ADD for display purpose*/
     
    print_dd (gbm, bdd, 2,4);   /*Print the dd to standard output*/
    sprintf(filename, "./bdd/graph.dot"); /*Write .dot filename to a string*/
    write_dd(gbm, bdd, filename);  /*Write the resulting cascade dd to a file*/
    Cudd_Quit(gbm);
    return 0; 

}
