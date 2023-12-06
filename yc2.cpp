#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
int main()
{
	FILE * fp;
	char filename[67], ch;
		printf("FILENAME: ");
		gets(filename);
	if ((fp = fopen (filename, "r")) == NULL ) //mo tap tin de ghi
	{
		printf("Open file error \n");
		exit(1);
	}
while ((ch =  getc(fp)) != EOF ) // doc den khi het tap tin
	printf("%c",ch);
fclose(fp);
return 0;
}
