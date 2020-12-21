#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <sys/stat.h>

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

char get_carGenome(char *fp){
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
  printf("%d", find("ATG", carFile));
     
   fclose(file); 

}


int main(){
 
 get_carGenome("MT873231.1");

   }	
	

 
 
