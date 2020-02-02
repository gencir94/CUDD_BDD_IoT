#include <sys/types.h>
#include <sys/time.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>
#include "cudd.h"

DdNode * savesave[4];
int k = 0; 
DdNode * final[96];
int gen_ind = 0;
static void
ddPrintMintermAux_genna(
  DdManager * dd /**< manager */,
  DdNode * node /**< current node */,
  int * list /**< current recursion path */)
{
    DdNode       *N,*Nv,*Nnv;
    int          i,v;
    unsigned int index;
    N = Cudd_Regular(node);

    if (Cudd_IsConstant(N)) {
        /* Terminal case: Print one cube based on the current recursion
        ** path, unless we have reached the background value (ADDs) or
        ** the logical zero (BDDs).
        */
        if (node != Cudd_ReadBackground(dd) && node != Cudd_Not(Cudd_ReadOne(dd))) {
            for (i = 0; i < Cudd_ReadSize(dd); i++) {
                v = list[i];
                if (v == 0) {
                        //(void) fprintf(Cudd_ReadStdout(dd),"0");
                        if (k==0) {k=1;}
 }else if (v == 1) {// (void) fprintf(Cudd_ReadStdout(dd),"1");
                        if (k==0) {k=1;}
                }
               // else{ //(void)  fprintf(Cudd_ReadStdout(dd),"-");
        //      }  
            }
         //   (void) fprintf(Cudd_ReadStdout(dd)," % g\n", Cudd_V(node));
            //if(k==1){printf("ciao\n");}
        }
    } else {
        Nv  = Cudd_T(N);
        Nnv = Cudd_E(N);
        if (Cudd_IsComplement(node)) {
            Nv  = Cudd_Not(Nv);
            Nnv = Cudd_Not(Nnv);
        }

        index = Cudd_NodeReadIndex(N);
        list[index] = 0;
        ddPrintMintermAux_genna(dd,Nnv,list);
        list[index] = 1;
        ddPrintMintermAux_genna(dd,Nv,list);
        list[index] = 2;
    }
    return;

} /* end of ddPrintMintermAux */

int Cudd_PrintMinterm_genna(
  DdManager * manager,
  DdNode * node)
{
    int i, *list;
    list = (int *) malloc(sizeof(int) * Cudd_ReadSize(manager));

   // if (list == NULL) {
   //     manager->errorCode = CUDD_MEMORY_OUT;
   //     return(0);
  //  }
    for (i = 0; i < Cudd_ReadSize(manager); i++) list[i] = 2;
    ddPrintMintermAux_genna(manager,node,list);
    //FREE(list);
    if (k == 1) {final[gen_ind] = node; k = 0;gen_ind++;}
    return(1);

} /* end of Cudd_PrintMinterm */


DdNode** Cudd_bddPrintCover_Gennaro(DdManager *dd,DdNode *l,DdNode *u)
{
    int *array;
    int q, result;
    DdNode *lb;
    DdNode *cover;
    DdNode **cover_save;
    int i = 0;
    //cover_save = Cudd_ReadOne(dd); /*Returns the logic one constant of the manager*/
     ////Cudd_Ref(cover_save); /*Increases the reference count of a node*/

    array = (int *) malloc(sizeof(int) * Cudd_ReadSize(dd));
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
//	cover_save = Cudd_bddOr(dd,cover_save,prime);
       savesave[i] = prime;
       u = Cudd_bddOr(dd,prime,u);
       lb = Cudd_bddAnd(dd,lb,Cudd_Not(prime));
        Cudd_RecursiveDeref(dd,lb);
i++;
    }

    return savesave;

} /* end of Cudd_bddPrintCover */


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


int main() {
int i;
    char filename[30];
    DdManager *gbm; /* Global BDD manager. */
    gbm = Cudd_Init(0,0,CUDD_UNIQUE_SLOTS,CUDD_CACHE_SLOTS,0); /* Initialize a new BDD manager. */
    DdNode *bdd,*bdd1,*bdd2,*bdd3,*bdd4,
	 *bdd5,*bdd6,*bdd7,*bdd8,*bdd9,*bdd10,*bdd11,*bdd12,*bdd13,*bdd14,*bdd15,*bdd16,*bdd17,*bdd18,*bdd19,*bdd20,*bdd21,*bdd22,*bdd23,*bdd24,*bdd25,*bdd26,*bdd27,*bdd28,*bdd29,*bdd30,*bdd31,*bdd32,*bdd33,*bdd34,*bdd35,*bdd36,*bdd37,*bdd38,*bdd39,*bdd40,*bdd41,*bdd42,*bdd43,*bdd44,*var;
    DdNode *tmp1, *tmp,*tmp_neg;
    bdd = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     Cudd_Ref(bdd); /*Increases the reference count of a node*/
    
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
     //bdd8 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
     //Cudd_Ref(bdd8); /*Increases the reference count of a node*/
   
     
     for (i = 0; i < 5; i++) {
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
    
      tmp_neg = Cudd_Not(var); /*Perform NOT Boolean operation*/
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd); /*Perform AND Boolean operation*/
      /*Perform AND Boolean operation*/
     
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd);
      bdd = tmp;
    }

    Cudd_Ref(bdd);

     for (i = 0; i < 5; i++) {
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
     if(i != 2 && i != 3) {
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
bdd = Cudd_bddOr(gbm,bdd,bdd1);


     for (i = 0; i < 5; i++) {
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
     if(i != 0 && i != 1) {
      tmp_neg = Cudd_Not(var); /*Perform NOT Boolean operation*/
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd2); /*Perform AND Boolean operation*/
      }else{
      tmp = Cudd_bddAnd(gbm,var,bdd2); /*Perform AND Boolean operation*/
     }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd2);
      bdd2 = tmp;
    }

    Cudd_Ref(bdd);
bdd = Cudd_bddOr(gbm,bdd,bdd2);


     for (i = 0; i < 5; i++) {
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
     if( i!=0 && i != 1 && i != 2 && i != 3) {
      tmp_neg = Cudd_Not(var); /*Perform NOT Boolean operation*/
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd3); /*Perform AND Boolean operation*/
      }else{
      tmp = Cudd_bddAnd(gbm,var,bdd3); /*Perform AND Boolean operation*/
     }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd3);
      bdd3 = tmp;
    }

    Cudd_Ref(bdd);
bdd = Cudd_bddOr(gbm,bdd,bdd3);



     for (i = 0; i < 5; i++) {
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
     if(i != 4) {
      tmp_neg = Cudd_Not(var); /*Perform NOT Boolean operation*/
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd4); /*Perform AND Boolean operation*/
      }else{
      tmp = Cudd_bddAnd(gbm,var,bdd4); /*Perform AND Boolean operation*/
     }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd4);
      bdd4 = tmp;
    }

    Cudd_Ref(bdd);
bdd = Cudd_bddOr(gbm,bdd,bdd4);
     
for (i = 0; i < 5; i++) {
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
     if(i!=2&&i!=3&&i != 4) {
      tmp_neg = Cudd_Not(var); /*Perform NOT Boolean operation*/
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd5); /*Perform AND Boolean operation*/
      }else{
      tmp = Cudd_bddAnd(gbm,var,bdd5); /*Perform AND Boolean operation*/
     }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd5);
      bdd5 = tmp;
    }

    Cudd_Ref(bdd);
bdd = Cudd_bddOr(gbm,bdd,bdd5);

for (i = 0; i < 5; i++) {
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
     if(i!=0&&i!=1&&i != 4) {
      tmp_neg = Cudd_Not(var); /*Perform NOT Boolean operation*/
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd6); /*Perform AND Boolean operation*/
      }else{
      tmp = Cudd_bddAnd(gbm,var,bdd6); /*Perform AND Boolean operation*/
     }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd6);
      bdd6 = tmp;
    }

    Cudd_Ref(bdd);
bdd = Cudd_bddOr(gbm,bdd,bdd6);
for (i = 0; i < 5; i++) {
     var = Cudd_bddIthVar(gbm,i); /*Create a new BDD variable*/
     if(i!=0&&i!=1&&i!=2&&i!=3&&i != 4) {
      tmp_neg = Cudd_Not(var); /*Perform NOT Boolean operation*/
      tmp = Cudd_bddAnd(gbm, tmp_neg, bdd7); /*Perform AND Boolean operation*/
      }else{
      tmp = Cudd_bddAnd(gbm,var,bdd7); /*Perform AND Boolean operation*/
     }
      Cudd_Ref(tmp);
      Cudd_RecursiveDeref(gbm,bdd7);
      bdd7 = tmp;
    }

    Cudd_Ref(bdd);
    bdd = Cudd_bddOr(gbm,bdd,bdd7);

//int array = Cudd_bddPrintCover(gbm,bdd,bdd);
//Cudd_bddConstrainDecomp(gbm, bdd);
//int array = Cudd_bddPrintCover(gbm,bdd,bdd);
//printf("ciaosaoosa\n");
Cudd_bddPrintCover(gbm,bdd,bdd);
int a = Cudd_ReadSize(gbm);
printf("LA DIMENSIONE %d \n",a);
//DdNode ** save;
//save = Cudd_bddPrintCover_Gennaro(gbm,bdd,bdd);
//bdd8 = Cudd_bddOr(gbm,save[0],save[1]);
//bdd8 = Cudd_bddOr(gbm,bdd8,save[2]);
//bdd8 = Cudd_bddOr(gbm,bdd8,save[3]);

DdNode** sa;
int j;
sa = Cudd_bddConstrainDecomp(gbm, bdd);
for( j = 0; j<Cudd_ReadSize(gbm);j++) {
Cudd_PrintMinterm_genna(gbm,sa[j]);
}



     //Cudd_Ref(sa); /*Increases the reference count of a node*/
//DdNode *** lol;
//lol[0][0] = Cudd_ReadZero(gbm);

//int AA = Cudd_bddIterDisjDecomp(gbm,save[0],lol);
//printf("dmsamdai %d\n",AA);
//sa =Cudd_bddConstrainDecomp(gbm,bdd);
//for(i=0; i<4;i++){
//DdNode * aaaaa = Cudd_bddOr(gbm,sa[0],sa[2]); 
//aaaaa = Cudd_bddAnd(gbm,aaaaa,sa[1]); 
//aaaaa = Cudd_bddAnd(gbm,aaaaa,sa[3]); 
//for(j = 0;j<gen_ind;j++){
//bdd8 = Cudd_bddAnd(gbm,final[0],final[1]);
//}

for(j = 0;j<gen_ind;j++){
Cudd_PrintMinterm(gbm,final[j]);

}
bdd = Cudd_BddToAdd(gbm, bdd);
print_dd (gbm, bdd, 2,4);   /*Print the dd to standard output*/
//Cudd_bddPrintCover(gbm,bdd8,bdd8);
    
    
    
    sprintf(filename, "./bdd/graph.dot"); /*Write .dot filename to a string*/
    write_dd(gbm, bdd, filename);  /*Write the resulting cascade dd to a file*/
    Cudd_Quit(gbm);

    return 0; 


}
