#include <string.h>
#include <stdlib.h>
#include <stdio.h>






FILE *abre_arquivo(const char *arquivo){

	//abrindo um arquivo

	if (arquivo !=NULL){
		return fopen(arquivo, "r");
	}
	return NULL;
}

//funcao fech arquivo
int fecha_arquivo(FILE *arq){
    if (arq==NULL) return 1;
	 if (fclose(arq)==0){

	return 0 ;
	 }
	 return 1;
}

//func free matrix
 void libera_mat(char **mat, int lin, int col){

    if (mat==NULL) return ;
    if (col < 0 || lin < 0 )return;//operacao invalida
    for (int i=0; i < lin; lin++){
      //liberando as linhas
      free(mat[i]);

    }
    //libera toda a amatriz
    free(mat);

 }


 //func maze
 int maze(char** mat, int n, int m, int lin , int col){
   if (lin < 0 || col < 0 || lin >= n || col >= m   ){
      return 0;
   }

   if (lin == (n-2) && col == (m-1) ){
     return 0;
   }
   if (mat[lin][col]== ' '){
      return 1;
   }
   else{
     mat[lin][col] = '-';
   }
   if (maze(mat,n,m,lin-1, col) || maze(mat,n,m,lin+1, col) || maze(mat,n,m,lin, col - 1) || maze(mat,n,m,lin, col + 1)){
     return 1;
   }
   else{
     mat[lin][col]=' ';
     return 0;
     }
}

 int main (){

   FILE* ptr_arquivo = abre_arquivo(argv[1]);

   if (arq ==NULL){
        fecha_arquivo(arq);

     return NULL;
   }



  	fgetc(arq);

  	if(feof(arq))  {

  	    fclose(arq);
  	    return NULL;
  	}

      rewind(arq);//reiniciando o arquivo

  	;
  	int cont=0;
  	int num=1;
  	char * vet = (char *)calloc(num,sizeof(char*));
  	if (vet!=NULL){
  		while(fscanf(arq,"%lf", &vet[cont]) && !feof(arq)) {

  			cont=cont +1;
  			num=num+1;


        vet = (char *)realloc(vet,num * sizeof(char));
        if (vet==NULL){
          free(vet);
          return NULL;
        }
      }
      if (vet[cont] != '\0'){
          vet[cont]='\0';
      }FILE* ptr_arquivo = abre_arquivo(argv[1]);
      fecha_arquivo(arq);
      int lin = 0;
      int col = 0;
      while (vet[col]==' '){
          col++;FILE* ptr_arquivo = abre_arquivo(argv[1]);


      }
  		lin = (cont/col);
  	}
    int **mat;//ponteiro para o vetor
    if(lin < 0 || col < 0 )return NULL;
    mat= (int **)calloc(lin, sizeof(int*));

    for (int i=0; i<lin; i++){FILE* ptr_arquivo = abre_arquivo(argv[1]);
      mat[i]=(int *)calloc(col,sizeof(int));
      if(mat[i]==NULL) return NULL;//nao alocou memoria
    }
    for (int h=0; h < lin ; h++){
      for (int l=0; l < col ; l++){
    maze(mat, h, l, lin ,  col);
      }
    }
    for ( int i1=0; i1<lin; i1 ++ )
  	{
  		for ( int j1=0; j1<col; j1 ++ )
  		{
  			if( i1 != lin && j1 != col-1 ) printf("%c", matriz[i1][j1]);
  		}
  		if ( i1 != lin-1 ) printf("\n");
  	}

    free(vet);
  	libera_mat(lin, col, mat);



   return 0;
 }
