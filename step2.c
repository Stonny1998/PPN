#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_BUFFER 1024
int find(char*codon, char*seq){

	unsigned char found = 0;
	unsigned long long pos;
	
	for(pos = 0; !found && pos < strlen(seq) - 3; pos++)
		found = !strncmp(codon, seq + pos, 3);
	
	if(found)
	
		return pos;
	
	return -1;		
}

void comptecar(){
 
 int compteur = 0;

 FILE * file;
 
 
 file = fopen("6XEZ_P", "r");
 if (file == NULL){
  perror("Erreur à l'ouverture du fichier");}
 
 else {
   int n;
   char buffer[MAX_BUFFER];
   while((n = fread(buffer, sizeof(char), MAX_BUFFER, file)))
      {
       for (int i = 0; i < n; i++)
		putchar(buffer[i]);
   }
   int tab_car = malloc(sizeof(char) * n);
   tab_car = buffer;		 
   return tab_car;
}


 fclose(file); 
}


/*
int comptecar(){
 
 int compteur = 0;
 char * tab_car;
 FILE * file;
 int nb_car;
 
 file = fopen("6XEZ_P", "r");
 if (file == NULL){
  perror("Erreur à l'ouverture du fichier");}
 
 else {

   while(fgetc(file) != EOF)
    compteur ++; 
 }

return compteur;
 

 fclose(file); 
}
*/

int main(){

	comptecar();


 }
