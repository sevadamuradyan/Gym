#include <stdio.h>
#include <stdlib.h>

struct threeNum
{
   int n1, n2, n3;
};
int main(int argc, char *argv[])
{
	int num1 = atoi(argv[1]);
	FILE *files[num1];
	for(int i = 1; i <= num1; i++)
	{
		char name[12];
		sprintf(name, "Result_%d.txt", i);
		files[i] = fopen(name, "o");
		fprintf(*(files + i), "Hallo, World %d\n", i);
		fclose(*(files + i));
	}
	
	 int num2;
   FILE *fptr;

   if ((fptr = fopen("C:\\text.txt","r")) == NULL){
       printf("Error! opening file");

       
       exit(1);
   }

   fscanf(fptr,"%d", &num2);

   printf("Value of n=%d", num2);
   fclose(fptr); 
   
   struct threeNum num;
   int num3;
   if ((fptr = fopen("C:\\text.bin","rb")) == NULL){
       printf("Error! opening file");

      
       exit(1);
   }
   
   
   fseek(fptr, -sizeof(struct threeNum), SEEK_END);

   for(num3 = 1; num3 < 5; ++num3)
   {
      fread(&num, sizeof(struct threeNum), 1, fptr); 
      printf("n1: %d\tn2: %d\tn3: %d\n", num.n1, num.n2, num.n3);
      fseek(fptr, -2*sizeof(struct threeNum), SEEK_CUR);
   }
   fclose(fptr); 
}
