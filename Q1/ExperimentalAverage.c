#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <ctype.h>
#include <string.h>


FILE *file;
char line[200];
char *ptr = line;
char s[2] = ",";
char *token;
double a = 0;
double sum = 0;
double average = 0;
int i = 0;
int c;
int count =0;



int main(int argc, char *argv[])
{
	file = fopen(argv[1], "rt"); //opens file.
	if (file == NULL) //if file is empty then prints an error message.
	{
		printf("File not found.\n");
	}
	else //if file is not empty do that.
	{
		while (!feof(file)) //while the file has not reach its end.
		{
			fgets(line,199,file); //gets whatever is in the file.
			
			token = strtok(line, s);
			printf ("%s", token);
			token = strtok(NULL, s);
			
			
			while (token != NULL)
		    {
				//printf (" %s", token);
				count ++;
				a = a + atoi(token); //convert to int
		  		token = strtok (NULL, s);
								
		    }
//			if (feof(file)) //new line if end of file is reached
//				{
//					printf("\n");
//				}
			if (count != 0)
			{
				a = a/count;
				//printf("Average = ");
				printf(" %.2f", a);
				printf("\n");
				a=0;
				count=0;
			}
		}
	}
	fclose(file); //closes file.
}
