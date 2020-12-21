#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <sys/stat.h>


int min(int x, int y, int z){
	if(x<y && x<z)
		return x;
	else if(y<x && y<z)	
		return y;
	else if(z<x && z<y)
		return z;		
}	

int find(char*codon, char*seq){

	unsigned char found = 0;
	unsigned long long pos;
	
	for(pos = 0; !found && pos < strlen(seq) - 3; pos++)
		found = !strncmp(codon, seq + pos, 3);
	
	if(found)
	
		return pos;
	
	return -1;		
}

struct stat st;

char *get_carGenome(char *fp){
FILE * file;
file = fopen(fp, "r");

 stat(fp, &st);
 int size = st.st_size;	



 char *carFile = malloc(sizeof(char) * size);
   int i=0;
   while ( ! feof( file ) && (i<size) ) {
        int theCurrentChar;        
        theCurrentChar = fgetc( file );
         carFile[i] = theCurrentChar;

         i++;
    }	

    return carFile; 
   fclose(file); 

}


int main(){
 		
 	int gene_start, gene_stop;
 	int gene_stop1, gene_stop2, gene_stop3;
 	
  gene_start = find("ATG", get_carGenome("demo.txt"));
      printf("gene_start : %d\n",gene_start);
   //
   gene_stop1 = find("UGA", get_carGenome("demo.txt")+ gene_start);
         printf("gene_stop1 : %d\n",gene_stop1);
   gene_stop2 = find("UAG", get_carGenome("demo.txt")+ gene_start);
            printf("gene_stop2 : %d\n",gene_stop2);
   gene_stop3 = find("UAA", get_carGenome("demo.txt")+ gene_start);
 	         printf("gene_stop3 : %d\n",gene_stop3);
 	printf("%d", min(gene_stop1,gene_stop2,gene_stop3));
 }	
	

 
 
