
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
DdNode * risultato[10000];
int ind_risultato = 0;

/*
int * Cudd_bddPrintCover_Gennaro(DdManager *dd,DdNode *l,DdNode *u)                 
{   
    int *array;
    int q, result;                                                                  
    DdNode *lb;                                                                     
    int j = 0;
                                                                        
    int i;
    DdNode *cover;
    array = (int *) malloc(sizeof(int) * Cudd_ReadSize(dd));                        
    
    if (array == NULL) return(0);                                                   
    lb = l;
    Cudd_Ref(lb);
    cover = Cudd_ReadLogicZero(dd);                                                 
    Cudd_Ref(cover);
    DdNode * aa;
    aa = Cudd_ReadOne(dd); 
    Cudd_Ref(aa); 
    DdNode * bb;
    bb = Cudd_ReadOne(dd);
    Cudd_Ref(bb); 
    DdNode * cc;
    aa = Cudd_ReadOne(dd); 
    Cudd_Ref(cc); 
    
    DdNode *tmp1,*tmp_neg,*var,*tmp2;
    for (i = 96; i < 98; i++) {
     var = Cudd_bddIthVar(dd,i); 
     tmp_neg = Cudd_Not(var); 
     tmp1 = Cudd_bddAnd(dd, tmp_neg, aa); 
     Cudd_Ref(tmp1);
     Cudd_RecursiveDeref(dd,aa);
     aa = tmp1;
    }
    
    for (i = 96; i < 98; i++) {
     var = Cudd_bddIthVar(dd,i);
     
     if(i != 97){
       tmp_neg = Cudd_Not(var); 
       tmp1 = Cudd_bddAnd(dd, tmp_neg, bb);
     
     }else{

       tmp1 = Cudd_bddAnd(dd, var, bb);
     }
     Cudd_Ref(tmp1);
     Cudd_RecursiveDeref(dd,bb);
     bb = tmp1;
    }
    
    for (i = 96; i < 98; i++) {
     var = Cudd_bddIthVar(dd,i);
     
     if(i != 96){
       tmp_neg = Cudd_Not(var); 
       tmp1 = Cudd_bddAnd(dd, tmp_neg, cc);
     
     }else{

       tmp1 = Cudd_bddAnd(dd, var, cc);
     }
     Cudd_Ref(tmp1);
     Cudd_RecursiveDeref(dd,cc);
     cc = tmp1;
    }
    
   aa = Cudd_bddOr(dd,aa,bb); 
   aa = Cudd_bddOr(dd,aa,cc); 

 while (lb != Cudd_ReadLogicZero(dd)) {                                          
        DdNode *implicant, *prime, *tmp;                                            
        int length; 
        implicant = Cudd_LargestCube(dd,lb,&length);                                
	if (implicant == NULL) {
	    Cudd_RecursiveDeref(dd,lb);
	   // FREE(array);
	    return(0);
	}
       
	Cudd_Ref(implicant); 
	
	prime = Cudd_bddMakePrime(dd,implicant,u);                                  
	Cudd_Ref(prime);
	Cudd_RecursiveDeref(dd,implicant);
	final[j] = prime;                                                         
 	j++;
        printf("dsadas %d\n",j);
        
//Faccio la restrizione
         prime = Cudd_bddRestrict(dd, prime, aa);
         lb = Cudd_bddAnd(dd,lb,Cudd_Not(prime));   
         u = Cudd_bddOr(dd,prime,u);
       }
    Cudd_RecursiveDeref(dd,lb);
    printf("Numero lista %d\n",j);
    DdNode * out;
   // out = Cudd_ReadOne(dd);
    for(i=0;i<j;i++) {
    out = Cudd_bddOr(dd,final[i],out);
    }
    return array;
    
}
*/
int ddDagInt_gennaro(DdManager* gbm,DdNode * n,int taglio_max,int direzione,int* listone,int loindice,int* sen_ind,int block)
{
    int tval, eval;
  //  printf("\n");

//printf("la direzione %d %d\n",direzione,Cudd_NodeReadIndex(n));
   // DdNode *s = Cudd_E(n);
   //printf("IL LIVELLO %d E L'INDICE %d TOTALE %d\n",Cudd_ReadIndex(gbm,Cudd_NodeReadIndex(n)),Cudd_NodeReadIndex(n),Cudd_ReadSize(gbm));
    
   if (Cudd_ReadIndex(gbm,Cudd_NodeReadIndex(n)) < Cudd_ReadIndex(gbm,taglio_max) )
    {  
	    //Cudd_PrintMinterm(gbm,n);
	    
	    if(block!=0){
              listone[loindice] = direzione;
	      loindice++; 
	    }

	    sen_ind[block] = Cudd_NodeReadIndex(n);
            block++;
	    //printf("dammi l'indice: %d\n", Cudd_NodeReadIndex(n));
	    
//printf("\n") ;
//DdNode* dai = Cudd_CubeArrayToBdd(gbm,listone);
//Cudd_PrintMinterm(gbm,dai);
	    
if(Cudd_IsComplement(n)){	    
  
  tval = ddDagInt_gennaro(gbm,Cudd_Not(Cudd_Regular(Cudd_T(n))),taglio_max,1,listone,loindice,sen_ind,block);
  eval = ddDagInt_gennaro(gbm,Cudd_Not(Cudd_Regular(Cudd_E(n))),taglio_max,0,listone,loindice,sen_ind,block);

} else {

  tval = ddDagInt_gennaro(gbm,Cudd_Regular(Cudd_T(n)),taglio_max,1,listone,loindice,sen_ind,block);
  eval = ddDagInt_gennaro(gbm,Cudd_Regular(Cudd_E(n)),taglio_max,0,listone,loindice,sen_ind,block);


}
   return(tval + eval);
       
  } else if (Cudd_IsConstant(n))
  
  {
           //istruzione per i nodi fuori range li ingnoro;	            
	  
	  return(0);
  
  } else {

        listone[loindice] = direzione;

	int a[Cudd_ReadSize(gbm)];
	
	int k;
 
	for(k=0;k<Cudd_ReadSize(gbm);k++) {a[k] = 2;}
        
	for(k=0;k<block;k++) {
        a[sen_ind[k]]=listone[k];
	}
	DdNode* dai = Cudd_CubeArrayToBdd(gbm,a);
        
       
       
	int foglie = (ptruint)n ;  

	int i,j;

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
    int* sen_ind;
    DdNode * s = Cudd_E(node);
    DdNode * e = Cudd_T(node);
    
    listone = (int *) malloc(sizeof(int)* Cudd_ReadSize(gbm));
    sen_ind = (int *) malloc(sizeof(int)* Cudd_ReadSize(gbm));

    for (i = 0; i < Cudd_ReadSize(gbm); i++) {
      listone[i] = 2;
      sen_ind[i] = 0;
    }
   
 
     i = ddDagInt_gennaro(gbm,node,taglio_max,0,listone,0,sen_ind,0);
   
  
   
  return(i);
   
} 

int checkg1_gennaro_ricorsivo(DdManager * gbm,DdNode * n,int direzione, int* listone,int loindice,int*sen_ind,int block,bool check ) 
{

int tval, eval;
if( (Cudd_IsConstant(Cudd_E(n))) && (Cudd_IsConstant(Cudd_T(n)))) {
	
        int i;
        if(Cudd_V(Cudd_E(n))==1) {
	listone[loindice] = 0;
	}else if (Cudd_V(Cudd_T(n))==1) {
	listone[loindice] = 1;
        }
        sen_ind[loindice] = Cudd_NodeReadIndex(n);
	loindice++;
	int a[Cudd_ReadSize(gbm)];
	
	int k; 
	for(k=0;k<Cudd_ReadSize(gbm);k++) {a[k] = 2;}
        
	for(k=0;k<loindice;k++) {
        
        
	 if (check == false) {

	a[sen_ind[k]]=listone[k];

	} else {
        if ((sen_ind[k] != 96)&&(sen_ind[k]!=97)) {
        
		a[sen_ind[k]]=listone[k];
	        
	}

	}
	
   }

      DdNode* dai = Cudd_CubeArrayToBdd(gbm,a);
      risultato[ind_risultato] = dai;
	
     
      ind_risultato++; 

      return 0;

}else if (Cudd_IsConstant(Cudd_E(n))&&!Cudd_IsConstant(Cudd_T(n))) {
  
	listone[loindice] = 1;
        sen_ind[loindice] = Cudd_NodeReadIndex(n);

	if(Cudd_NodeReadIndex(n)<96) {check = true;}
        
	loindice++;

  
tval = checkg1_gennaro_ricorsivo(gbm,Cudd_T(n),1,listone,loindice,sen_ind,block,check);
return 0;

} else if (!Cudd_IsConstant(Cudd_E(n))&&Cudd_IsConstant(Cudd_T(n))) {
 
  
	listone[loindice] = 0;
        sen_ind[loindice] = Cudd_NodeReadIndex(n);
	if(Cudd_NodeReadIndex(n)<96) {check = true;}
        
        loindice++;

        eval = checkg1_gennaro_ricorsivo(gbm,Cudd_E(n),0,listone,loindice,sen_ind,block,check);
	

	
return 0;

} else {
   
  
    listone[loindice] = 1;
    sen_ind[loindice] = Cudd_NodeReadIndex(n);
    loindice++;
    if(Cudd_NodeReadIndex(n)<96) {check = true;}

	

   tval = checkg1_gennaro_ricorsivo(gbm,Cudd_T(n),1,listone,loindice,sen_ind,block,check);
   

   loindice--;
   listone[loindice] = 0;
   loindice++;

   eval = checkg1_gennaro_ricorsivo(gbm,Cudd_E(n),0,listone,loindice,sen_ind,block,check);

return 0;   

}	


	



}

DdNode * checkg1_gennaro (DdManager * gbm, DdNode * g1) {
    
    int i,j;
    DdNode* track; 
    int* listone;
    int* sen_ind;
    //DdNode*risultato;
    //risultato = Cudd_ReadOne(gbm);
    DdNode * s = Cudd_E(g1);
    DdNode * e = Cudd_T(g1);
    
    listone = (int *) malloc(sizeof(int)* Cudd_ReadSize(gbm));
    sen_ind = (int *) malloc(sizeof(int)* Cudd_ReadSize(gbm));

    for (i = 0; i < Cudd_ReadSize(gbm); i++) {
      listone[i] = 2;
      sen_ind[i] = 2;
   
    }
   
     //printf("dammi l'input MODDATO\n");
     //Cudd_PrintMinterm(gbm,g1);	
; 
     i = checkg1_gennaro_ricorsivo(gbm,g1,0,listone,0,sen_ind,0,false);

     if(ind_risultato == 1) {
     track = risultato[0];
     } else {

     track = Cudd_bddOr(gbm,risultato[0],risultato[1]);

     for(i = 2;i<ind_risultato;i++) {
       track = Cudd_bddOr(gbm,track,risultato[i]);
     }
  }
	     printf("IL RISULTATO FINALE \n");
//for(i = 0;i<ind_risultato;i++){     
//Cudd_PrintMinterm(gbm,track);

//}	
//printf("IL RISULTATO FINALE_FINITO \n");
ind_risultato = 0;

return track;
}


int stampa_ricorsivo_gennaro (DdManager* gbm,DdNode * n,FILE* outfile,int somma,bool check,int* vedo,int* listone,int loindice,int* T,int t_index,int codifica,int* T2,char*label,int cod_index,int stopper) {
  
  int tval, eval;
    
  if (Cudd_IsConstant(n)) {
    
    int i;
    int ris=0;
    int ris_mask=0;
    int maschera[7];
    bool mask = false;
    int lk = 7;
    int copia_listone[8];
   printf("Scrivo array\n"); 
    for ( i = 0; i < 8; i++ ) {
    printf("%d",listone[i]);
    copia_listone[i] = listone[i];
	if (listone[i] == 2) {
          mask = true;
          maschera[i] = 0; 
	  listone[i] = 0;
        } else {
          maschera[i] = 1; 
        }

   
     	ris = ris + (pow(2,lk)*listone[i]);
       	ris_mask = ris_mask + (pow(2,lk)*maschera[i]);
   
       	lk--;
    }
    printf("\n");
      

    if(check == true) {
        if ((vedo[0]==0) && (vedo[1]==0)) {
            fprintf(outfile,"printf(\"E' un pacchetto mqtt\\n\"); exit(0);\n");

	    }else if((vedo[0]==0) && (vedo[1]==1)) {
            fprintf(outfile,"printf(\"E' un pacchetto coap\\n\"); exit(0);\n");
	    
	    }else if((vedo[0]==1) && (vedo[1]==0)) {
            fprintf(outfile,"printf(\"E' un pacchetto amqp\\n\"); exit(0);\n");

	    }else if(vedo[1]==2){
            fprintf(outfile,"printf(\"E' un pacchetto mqtt o coap\\n\"); exit(0);\n");
	    
	    
	    }
  } else {
  
   if(mask ==false) {
     
     fprintf(outfile,"if (in == %d) { \n",ris);
     int cod=0;
     int pp = t_index-1; 
     for ( i = 0; i < t_index; i++ ) {
             cod = cod + (pow(2,pp)*T2[i]);
	     pp--;
     }

   fprintf(outfile,"return %d; \n",cod);
   
   } else {
   
     int a = ris & ris_mask;
     fprintf(outfile,"if ((in&%d) == %d) { \n",ris_mask,a);
   
     int cod = 0;
     int pa = t_index-1;
     
     for (i = 0; i < t_index; i++){
        
	cod = cod + ( pow ( 2, pa ) * T2[i]);
	pa--;
   }
   
    fprintf(outfile,"return %d; \n",cod);
   
   
   }

   fprintf(outfile,"}\n");
}

    for ( i = 0; i < 8; i++ ) {
    listone[i] = copia_listone[i];    
    
    }

   
	

 return 0 ;
  
  } else {
   
   //NODO CHE VA DA ENTRAMBI LE PARTI 


if ( ( !Cudd_IsConstant (Cudd_T(n) ) ) && ( !Cudd_IsConstant ( Cudd_E(n) ) ) ) {  
    
      if( ( Cudd_NodeReadIndex(n) > 97) && (Cudd_NodeReadIndex(n) < somma) ) {
	   
	    T[cod_index] = 1;
            cod_index++;
            codifica --;
       
       
      if (codifica == 0) {
	    

  	    int i;
	    int ris = 0;
	    int ij = cod_index - 1; 
	    for ( i = 0; i < cod_index; i++) {
	       ris = ris + pow(2,ij)*T[i];
	       ij--;
	    }
	  
	    if(strcmp(label,"if") == 0) { 
	   
	       fprintf(outfile,"if (T == %d) { \n",ris);
	       label = "else";
	     
	    } else {
	    
	       fprintf(outfile,"else if (T == %d) { \n",ris);

	     }

	    } 
            
	    
   
      }
      else if ( (Cudd_NodeReadIndex(n) < 96 ) ) {
          
	  listone[Cudd_NodeReadIndex(n)-stopper] = 1;
   
      } else if (Cudd_NodeReadIndex(n) >= somma) {
          T2[t_index] = 1;
          t_index++;
  
      } else if (Cudd_NodeReadIndex(n) == 96) {
          
	  check = true;
          vedo[0] = 1;
      
      } else if (Cudd_NodeReadIndex(n) == 97) {
          
	  vedo[1] = 1;
          check = true;
    }

 

  tval = stampa_ricorsivo_gennaro(gbm,Cudd_T(n),outfile,somma,check,vedo,listone,loindice,T,t_index,codifica,T2,label,cod_index,stopper);
   
 if(Cudd_NodeReadIndex(n) < 96) { 
  listone[Cudd_NodeReadIndex(n)-stopper] = 2;
 }
  if( ( Cudd_NodeReadIndex(n) > 97) && (Cudd_NodeReadIndex(n) < somma) ) {
	    
	  cod_index--;
	  T[cod_index] = 0;
          cod_index++;
           
	  if (codifica == 0) {
	    int i;
	    int ris = 0;
	    int ij = cod_index - 1;
	   
	    for ( i = 0; i < cod_index; i++) {
              ris = ris + pow( 2 , ij ) * T[i];
	      ij--;
	    }
	    
	     fprintf(outfile,"} else if (T == %d) { \n",ris);
	   
	    } 
            
	   
      } else if (Cudd_NodeReadIndex(n) < 96) {
	    
	    listone[Cudd_NodeReadIndex(n)-stopper] = 0;
	  
      } else if (Cudd_NodeReadIndex(n) >= somma) {
      
	    t_index--;
	    T2[t_index] = 0;
            t_index++;

      } else if (Cudd_NodeReadIndex(n) == 96) {
            
	    check = true;
            vedo[0] = 0;
 
       }else if (Cudd_NodeReadIndex(n) == 97) {
            
	    vedo[1] = 0;
            check = true;
    }

 

 
  eval = stampa_ricorsivo_gennaro(gbm,Cudd_E(n),outfile,somma,check,vedo,listone,loindice,T,t_index,codifica,T2,"else",cod_index,stopper);
 
 if(Cudd_NodeReadIndex(n) < 96) { 
   listone[Cudd_NodeReadIndex(n)-stopper] = 2;
 }

  if( ( Cudd_NodeReadIndex(n) > 97) && (Cudd_NodeReadIndex(n) < somma) ) {

   if(codifica == 0) {
   
      fprintf(outfile,"}\n");
  
  }
 
  }

   } else if ( ( !Cudd_IsConstant (Cudd_E(n) ) ) && (Cudd_IsConstant( Cudd_T(n) ) ) ) {  
      

  if( (Cudd_NodeReadIndex(n) > 97) && (Cudd_NodeReadIndex(n) < somma) ) {
           
            
	T[cod_index] = 0;
        cod_index++;
	codifica --;
       
        
      if (codifica == 0) {
	    int i;
	    int ris = 0;
	    int ij = cod_index-1;

	    for ( i = 0; i < cod_index; i++) {
              
	      ris = ris + pow(2,ij)*T[i];
	      ij--;
	    
	    }
	    
	    
	     fprintf(outfile,"if (T == %d) { \n",ris);
	    
	    
  }

} else if (Cudd_NodeReadIndex(n) < 96) {
            
	    listone[Cudd_NodeReadIndex(n)-stopper] = 0;
    
    }else if(Cudd_NodeReadIndex(n) >= somma){

	    T2[t_index] = 0;
            t_index++;

    } else if (Cudd_NodeReadIndex(n) == 96) {
      
	    check = true;
            vedo[0] = 0;
   
    } else if (Cudd_NodeReadIndex(n) == 97) {
   
	    vedo[1] = 0;
            check = true;
    }

eval = stampa_ricorsivo_gennaro(gbm,Cudd_E(n),outfile,somma,check,vedo,listone,loindice,T,t_index,codifica,T2,label,cod_index,stopper);
 
if(Cudd_NodeReadIndex(n)<96) { 

       	listone[Cudd_NodeReadIndex(n)-stopper] = 2;

 }

 if( ( Cudd_NodeReadIndex(n) > 97) && (Cudd_NodeReadIndex(n) < somma) ) {

   if(codifica == 0) { 
    
	   fprintf(outfile,"}\n");
   }

}

   
} else if ( (Cudd_IsConstant( Cudd_E(n) ) ) && ( !Cudd_IsConstant(Cudd_T(n) ) ) ) {  


	if( (Cudd_NodeReadIndex(n) > 97) && (Cudd_NodeReadIndex(n) < somma) ) {

	    T[cod_index] = 1;
            cod_index++;
            codifica --;
       
        

	    if (codifica == 0) {
	      int i;
	      int ris = 0;
	      int ij = cod_index - 1;
	    
	      for ( i = 0; i < cod_index; i++) {
                ris = ris + pow(2,ij) * T[i];
	        ij--;
	      }
	    
	      fprintf(outfile,"if (T == %d) { \n",ris);
	   		   
	    
            } 
}

else if ( Cudd_NodeReadIndex(n) < 96) {
     
     listone[Cudd_NodeReadIndex(n)-stopper] = 1;
    
    } else if(Cudd_NodeReadIndex(n) >= somma) {

	    T2[t_index] = 1;
            t_index++;

    } else if (Cudd_NodeReadIndex(n) == 96) {
       check = true;

       vedo[0] = 1 ; 
    } else if (Cudd_NodeReadIndex(n) == 97) {
       vedo[1] = 1;
       check = true;
    }





eval = stampa_ricorsivo_gennaro(gbm,Cudd_T(n),outfile,somma,check,vedo,listone,loindice,T,t_index,codifica,T2,label,cod_index,stopper);

if(Cudd_NodeReadIndex(n) < 96) { 

 listone[Cudd_NodeReadIndex(n)-stopper] = 2;
 }

if( ( Cudd_NodeReadIndex(n) > 97) && (Cudd_NodeReadIndex(n) < somma) ) {
 

	  if (codifica == 0 ) {     
             
		  fprintf(outfile,"}\n");

          }
  }

} else {

if (Cudd_V(Cudd_T(n)) == 1){


	if (Cudd_NodeReadIndex(n)>=somma) {
 
	      	T2[t_index] = 1;
                t_index++;

     	} else if (Cudd_NodeReadIndex(n) == 97) {
 
	      	vedo[1] = 1;
		check = true;
 
 
       	}else if (Cudd_NodeReadIndex(n) == 96) {
 
	       	vedo[0] = 1;
                vedo[1] = 2;
                check = true;
 
        }

tval = stampa_ricorsivo_gennaro(gbm,Cudd_T(n),outfile,somma,check,vedo,listone,loindice,T,t_index,codifica,T2,label,cod_index,stopper);

if(Cudd_NodeReadIndex(n) < 96) { 

 listone[Cudd_NodeReadIndex(n)-stopper] = 2;

}

 

} else  if ((Cudd_V(Cudd_E(n))) == 1) {


	if (Cudd_NodeReadIndex(n) >= somma) {
   
		T2[t_index] = 0;
		t_index++;

         } else if (Cudd_NodeReadIndex(n) == 97) {
	 
	      vedo[1] = 0;
              check = true;
 

         }else if (Cudd_NodeReadIndex(n) == 96) {

	      vedo[0] = 0;
              vedo[1] = 2;
              check = true;
  }


  eval = stampa_ricorsivo_gennaro(gbm,Cudd_E(n),outfile,somma,check,vedo,listone,loindice,T,t_index,codifica,T2,label,cod_index,stopper);
 
  if(Cudd_NodeReadIndex(n) < 96) { 

    listone[Cudd_NodeReadIndex(n)-stopper] = 2;
 }

}

}

}

}




int stampa_gennaro(DdManager*gbm,DdNode * node,FILE* outfile,int codifica,int somma,int stopper)
{
    
    int *listone;    
    listone = (int *) malloc(sizeof(int)* Cudd_ReadSize(gbm));
    
    int i;
    
    for (i = 0; i < Cudd_ReadSize(gbm); i++) {
      listone[i] = 2;
    }


    int vedo[2];

    vedo[0]=2;
    vedo[1]=2;
  
    int T[codifica];
    int T2[codifica];
   
    for(i = 0; i < codifica; i++) {
      T[i] = 2;
      T2[i] = 2;
    }
  
    
   i = stampa_ricorsivo_gennaro(gbm,node,outfile,somma,false,vedo,listone,0,T,0,codifica,T2,"if",0,stopper);



} 





int main() {

    char filename[30];
    DdManager *gbm; /* Global BDD manager. */
    gbm = Cudd_Init(0,0,CUDD_UNIQUE_SLOTS,CUDD_CACHE_SLOTS,0); /* Initialize a new BDD manager. */

    DdNode *bdd,*bdd1,*bdd2,*bdd3,*bdd4,
    *bdd5,*bdd6,*bdd7,
    *bdd8,*bdd9,*bdd10,
    *bdd11,*bdd12,*bdd13,
    *bdd14,*bdd15,*bdd16,
    *bdd17,*bdd18,*bdd19,
    *bdd20,*bdd21,*bdd22,
    *bdd23,*bdd24,*bdd25,
    *bdd26,*bdd27,
    *bdd28,*bdd29,*bdd30,
    *bdd31,*bdd32,*bdd33,
    *bdd34,*bdd35,*bdd36,
    *bdd37,*bdd38,*bdd39,
    *bdd40,*bdd41,*bdd42,
    *bdd43,*bdd44,*bdd45,
    *bdd46,*bdd47,*var;
    
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
    //bdd5 = scrivi_bdd_uno1(gbm,bdd5,var);
   // bdd6 = scrivi_bdd_due1(gbm,bdd6,var);
   // bdd7 = Cudd_bddOr(gbm,bdd5,bdd6); 
   // bdd4 = Cudd_bddAnd(gbm,bdd4,bdd7); 
    bdd = Cudd_bddOr(gbm,bdd4,bdd);
  
   //FUNZIONI PUBLISH

    bdd8 = scrivi_bdd_zero2 (gbm, bdd8, var); 
    bdd9 = scrivi_bdd_uno2(gbm,bdd9,var);
  //  bdd10 = scrivi_bdd_due2(gbm,bdd10,var);
  //  bdd11 = scrivi_bdd_tre2(gbm,bdd11,var); 
  //  bdd12 = scrivi_bdd_quattro2(gbm,bdd12,var);
  //  bdd13 = Cudd_bddOr(gbm,bdd9,bdd10); 
 //   bdd13 = Cudd_bddOr(gbm,bdd11,bdd13); 
 //   bdd13 = Cudd_bddOr(gbm,bdd12,bdd13); 

    bdd8 = Cudd_bddAnd(gbm,bdd8,bdd9);


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
 //   bdd23 = scrivi_bdd_uno7(gbm,bdd23,var);
//    bdd24 = scrivi_bdd_due7(gbm,bdd24,var);
 //   bdd25 = scrivi_bdd_tre7(gbm,bdd25,var); 
//    bdd22 = Cudd_bddOr(gbm,bdd22,bdd23); 
//    bdd22 = Cudd_bddOr(gbm,bdd22,bdd24); 
//    bdd22 = Cudd_bddOr(gbm,bdd22,bdd25); 
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
  //  bdd29 = scrivi_bdd_uno9(gbm,bdd29,var);
  //  bdd30 = scrivi_bdd_due9(gbm,bdd30,var);
 //   bdd31 = scrivi_bdd_tre9(gbm,bdd31,var); 
 //   bdd28 = Cudd_bddOr(gbm,bdd28,bdd29); 
 //   bdd28 = Cudd_bddOr(gbm,bdd28,bdd30); 
 //   bdd28 = Cudd_bddOr(gbm,bdd28,bdd31); 
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

    //funzioni mqtt-q
    
    //DdNode* bdd48;
    //bdd48=scrivi_bdd_mqtt_q(gbm,bdd48,var);
    
  //  bdd = Cudd_bddOr(gbm,bdd48,bdd);

// primo algoritmo paper per diminuire dim


    int i,j;
    int h = 0;
    
    //allocazioni dinamiche 

     //CALCOLO IL VALORE DI T
    int molti = 4;
    int T;
    int p;
  


    

    DdNode* tmp,*tmp2,*tmp3,*tmp4,*tmp5 ;
    sub[0] = bdd;
    DdNode* copy_bdd = bdd;
    DdNode* lala[1000];
    Cudd_PrintMinterm(gbm,copy_bdd);

    lala[0] = bdd; 
     
    tmp = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
    Cudd_Ref(tmp); /*Increases the reference count of a node*/
    tmp2 = Cudd_ReadOne(gbm); /*Returns the logic one constant of the manager*/
    Cudd_Ref(tmp2); /*Increases the reference count of a node*/

    codifica_num = (int *) malloc(sizeof(int)* 20000);
    
    // some random index;
   
    int gen = 0;
    int gen2 = 0;
    int xx = 0;
    int nn = 0;
    int bal = 1;
    int mn = 0;
    grande = Cudd_ReadSize(gbm); 
    DdNode * g1[10000];
    DdNode * g2[10000];

    int codifica[100];

    int somma[100];

    int grand ;


    g2[0] = bdd;
    
    for(i = 0; i < 10000;i++) {
      g1[i] = Cudd_ReadOne(gbm); 
      Cudd_Ref(g1[i]);
    }

    for(xx = 0;xx<(grande/4)+1;xx++) {
         
	printf("molti %d\n",molti);  
	    
	grand = Cudd_ReadSize(gbm);
	somma[xx] = Cudd_ReadSize(gbm);
    
	boolArray = (bool *) malloc(sizeof(bool) * 2000000000);
        codifica_gen_ind = (int *) malloc(sizeof(int) * 200000000);
    
	gen2 = gen_ind;	
	T = Cudd_DagSize_gennaro(gbm,g2[xx],molti);
        T = ceil(log2(T));
	
        if(T == 0) {
           T = 1;
	 }

	codifica[xx] = T;

	if (T == 1) {
        
	tmp = Cudd_bddNewVarAtLevel(gbm,molti+(Cudd_ReadSize(gbm) - grande ));
	
	}else if (T == 2){
        
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

    while (mm < leaf_index) {

	  if(ll == 0 && T == 2) {   	
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
	  
	  } else if(ll == 7 && T == 3) {
	  
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
    
	 for(i = gen2;i < gen_ind;i++) { 
	  
           if(codifica_ind[codifica_gen_ind[codifica_num[mm]]][i] == 1) {   	 
  
	     sub_spezzato[i] = Cudd_Not(sub_spezzato[i]);
	     sub_spezzato[i] = Cudd_bddOr(gbm,sub_spezzato[i],tmp); 
	
	}


    
     }
          
	 ll++;
         mm++;
    
    }

    leaf_index = 0;

    for(i = gen2; i < gen_ind; i++) {

      g1[xx]= Cudd_bddAnd(gbm,g1[xx],sub_spezzato[i]); 
        
    }
  
  g1[xx] = Cudd_bddAnd(gbm,g1[xx],g2[xx]);
  
  DdNode * cube;
  DdNode * cube1;
  DdNode * cube2;
  DdNode * cube3;

  cube = Cudd_ReadOne(gbm); 
  Cudd_Ref(cube);
  cube3 = Cudd_ReadOne(gbm); 
  Cudd_Ref(cube3);

  for(i = molti; i < 18; i++) 
  {
   cube1 = Cudd_bddIthVar(gbm,i);
   cube = Cudd_bddAnd(gbm,cube1,cube);
  }
  
  for(i = 0; i < molti; i++) {
   cube2 = Cudd_bddIthVar(gbm,i);
   cube3 = Cudd_bddAnd(gbm,cube3,cube2);
  }

  for(i = grande; i < Cudd_ReadSize(gbm) - T; i++){
   cube2 = Cudd_bddIthVar(gbm,i);
   cube3 = Cudd_bddAnd(gbm,cube3,cube2);

  }

  printf("G1\n");
  
  g2[xx+1] = Cudd_bddExistAbstract(gbm,g1[xx],cube3);
  
  g1[xx] = Cudd_bddExistAbstract(gbm,g1[xx],cube);
	
  bdd = Cudd_BddToAdd(gbm, g1[xx]);  
  
 // g1[xx] =  checkg1_gennaro(gbm,bdd);
 
  Cudd_PrintMinterm(gbm,g1[xx]);
  
  printf("E POI G2 \n");
  
  Cudd_PrintMinterm(gbm,g2[xx+1]);

  printf("finito\n");

  bdd = Cudd_BddToAdd(gbm, g1[xx]);  
  sprintf(filename, "./bdd/graph.dot"); 
  write_dd(gbm, bdd, filename); 
printf("Il numero dei percorsi : %f\n",Cudd_CountPath(g1[xx]));

  
  getchar();
    
  molti = molti + 4;  
  
	 
   }

  printf("il bdd originale \n");
  Cudd_PrintMinterm(gbm,copy_bdd);
  printf("il bdd originale CON COVER \n");
  Cudd_bddPrintCover(gbm,copy_bdd,copy_bdd);

printf("IL RISULTATO FINALE dopo IL TAGLIO \n");

for(i=0;i<grande/4;i++){
  
  Cudd_PrintMinterm(gbm,g1[i]);
  printf("col cover\n");
  Cudd_bddPrintCover(gbm,g1[i],g1[i]);
//  printf("col cover gennaro\n");
//  Cudd_bddPrintCover_Gennaro(gbm,g1[i],g1[i]);

}
    FILE *outfile;
    outfile = fopen("aaaa.c","w");
 
    fprintf(outfile,"#include<stdio.h>\n");

    fprintf(outfile,"#include<stdlib.h>\n");
    
    int cod = 1;
    int stopper = 0;
    for (i = 0; i < (grande / 8) + 1; i++ ) {

      fprintf(outfile,"int check_%d (int in,int T) { \n",i);
      
      Cudd_PrintMinterm(gbm,g1[i]);
      bdd = Cudd_BddToAdd(gbm, g1[i]);  
      stampa_gennaro(gbm,bdd,outfile,cod,somma[i],stopper);
      cod = codifica[i];
      stopper = stopper + 8;
      fprintf(outfile,"printf(\"Non è un pacchetto IoT\\n\"); exit(0);\n");
      fprintf(outfile,"}"); 
      fprintf(outfile,"\n"); 
      
      print_dd(gbm,g1[i],2,4); 
    
    }

    fprintf(outfile,"int main () { \n");
    fprintf(outfile,"int in[%d];\n",12);
    fprintf(outfile,"int T;\n",Cudd_ReadSize(gbm));
   
    for (i = ( grande / 8); i > 0; i-- ) {
      fprintf(outfile,"check_%d(in[%d],\n",i,i);
    }
  
    fprintf(outfile,"check_%d(in[0],T\n",0);
  
    for (i = (grande/8); i>=0; i-- ) {
     fprintf(outfile,")",i);
    }
  
    fprintf(outfile,";",i);
 
    fprintf(outfile,"\n}"); 

    fclose(outfile);
 print_dd(gbm,copy_bdd,2,4); 

//for(i=0;i<grande/8;i++){
//  Cudd_bddPrintCover(gbm,g1[i],g1[i]);

//}


//bdd = Cudd_BddToAdd(gbm, bdd100); /*Convert BDD to ADD for display purpose*/
//print_dd (gbm, bdd, 2,2);   /*Print the dd to standard output*/

//sprintf(filename, "./bdd/graph.dot"); /*Write .dot filename to a string*/
//write_dd(gbm, bdd, filename);  /*Write the resulting cascade dd to a file*/
  

   // Cudd_Quit(gbm);
    return 0; 

}
