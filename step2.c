#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int find(char*codon, char*seq){

	unsigned char found = 0;
	unsigned long long pos;
	
	for(pos = 0; !found && pos < strlen(seq) - 3; pos++)
		found = !strncmp(codon, seq + pos, 3);
	
	if(found)
	
		return pos;
	
	return -1;		
}

int comptecar(){
 int compteur = 0;
 
 FILE * file;
 
 /* ouverture du fichier */
 if ((file = fopen("6XEZ_P", "r")) == NULL)
  perror("Erreur à l'ouverture du fichier");
 
 else {
   /* parcours du fichier */
   while(fgetc(file) != EOF)
    compteur ++; /* incrémentation du compteur */
 }
 
 printf("Le nombre de caractères du fichier est de : %d\n", compteur);
 
 /* fermeture du fichier */
 fclose(file);

 
}




int main(){

 	











   /* char genome[] = "ACTGTUGAUGACTGCTUGCATUCTCAU";

    printf("%d\n", find("AUG", genome));
	*/
    return 0;
    
 }
