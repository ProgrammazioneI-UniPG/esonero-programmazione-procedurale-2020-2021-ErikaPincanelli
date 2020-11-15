#include <stdio.h>
#include <stdlib.h> // libreria per usare rand() e srand ()
#include <time.h> // libreria per utilizzare time()
#include <string.h>


char M[128];
char K[128];
char R[128];
int scelta;
time_t t;
int main(){
  int i=0,n,N=0,lung_K=0,contrlung=0;
  char ch;
  system("clear");
  printf ("inserisci la stringa M non maggiore di 128 caratteri:\n");
  ch=getchar();
  while(ch != '\n' && N<128)
  {
     M[N++]=ch;
     ch=getchar();
  }
  //for (i = 0; i < N; i++)
    //putchar(M[i]);
    printf ("\nhai inserito %d",N);
    printf (" caratteri: %s\n",M);
    //if (N>12)
    //printf ("\nhai inserito più di 128 caratteri: %d\n",N);
    //printf ("\nhai inserito: %s\n",M);

    //return 0;
    // con la funzione getchar() immetto la variabile.
    // con la funzione putchar() visualizzo la variabile immessa.

do{
  printf("\ncome vuoi procedere:\n\n");
  printf("1.inserisci la chiave k:\n");
  printf("2.genera una chiave k casuale:\n");
  printf("se digiti un numero diverso da 1 o 2 esci\n");
  printf("\nfai la tua scelta:\n");
  scanf("%d",&scelta);
  if(scelta>2){
    printf("\narrivederci\n");
    return 0;
  }

}while (scelta !=1 && scelta !=2);

switch (scelta) {
  case 1: //inserisco manualmente la chiave K
  printf("inserisci la chiave K con almeno: %d",N);
  printf (" caratteri\n");
  fgets(K, 128, stdin);
do {
  (contrlung==0);
  fgets(K, 128, stdin); // legge da tastiera
  lung_K=strlen(K);
  printf("la lunghezza di k è: %d\n",(lung_K)-1); // scrive ciò che ho immesso
  if (((lung_K)-1)<N)
  printf ("hai inserito una chiave K troppo corta, per favore inseriscine una più lunga:  ");
  else {
    printf ("\nla chiave K inserita è:\t\t\t%s",K);
    //contrlung==1;
    }
} while (((lung_K)-1)<N);
printf ("la variabile M è:\t\t\t%s",M);
//printf ("\nla chiave K è:\t\t\t\t%s",K);

for(int i = 0; i < (lung_K)-1; i++){
  R[i] = M[i] ^ K[i];
  //printf("%d\n",M[i]);
  //printf("%d\n",K[i]);
  //printf("%d\n",R[i]);
}
printf("\nlo XOR tra la stringa M e la chiave K è:");
for(int i = 0; i < (lung_K)-1; i++){
  printf("%d",R[i]);
}
printf("\n");

for(int i = 0; i < (lung_K)-1; i++){
  M[i] = R[i] ^ K[i];
  //printf("%d\n",K[i]);
  //printf("%d\n",R[i]);
  //printf("%d\n",M[i]);
}
printf("\nla variabile d'origine è:");
for(int i = 0; i < (lung_K)-1; i++){
  printf("%c",M[i]);
}
printf("\n");

return 0;

case 2: //sto generando la chive K random
srand((unsigned)time(&t));
printf("la chiave K random generata è :\t\t");
for(int i=0; i < (N);i++){
K[i]=rand()%(128-32)+32;
//printf("la chiave random generata è %c",K[i]);
printf("%c",K[i]);
//printf("la chiave random generata è %x\n",K[i]);
//stampa e genera un numero random da 0 a 127
}
//M[i]=M;
printf ("\nla variabile M è:\t\t\t");
//for(int i=0; i < (N-1);i++){
  printf ("%s",M);
  printf ("\n");

//}
//printf ("\nla chiave K è: %x\n",K[i]);

//lung_K=strlen(K);
//printf("%d\n",lung_K);
//printf("%d\n",K[i]);
//printf("%d\n",M[i]);
printf("\nlo XOR tra la stringa M e la chiave K è:");
for(int i = 0; i < (N); i++){
R[i] = M[i] ^ K[i];
//printf("%d\n",M[i]);
//for(int i = 0; i < (N-1); i++){
printf("%c",R[i]);
}

printf("\n");

for(int i = 0; i < (N); i++){
M[i] = R[i] ^ K[i];

}
printf("\n");
printf("la variabile d'origine è:");
for(int i = 0; i < (N); i++){
printf("%c",M[i]);
}
printf("\n");
return 0;
}
}
