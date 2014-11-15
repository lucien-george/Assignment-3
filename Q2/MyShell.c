#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>

char command[200];
char prompt[200];
char temp[200];
int setPrompt(char *str);

int setPrompt(char *str)
{
	char temp[200];
	strcpy(temp, str);
	char *token = strtok(temp," ");
	if (strcasecmp("set", token) != 0)
	{
		return 0;
	}
	token = strtok(NULL, " ");
	if(strcasecmp("prompt", token) != 0)
	{
		return 0;
	}
	return 1;
}

int main(int argc, char *argv[])
{
	strcpy(prompt, "$Lucien George:~ ");
	printf("%s", prompt);
	gets(command);
	while (strcasecmp("quit", command) != 0)
	{
		if(setPrompt(command))
		{
			char *token = strtok(command, " ");
			token = strtok(NULL, " ");
			token = strtok(NULL, " ");
			strcpy(temp, "$");
			strcat(token, "");
			strcpy(prompt, token);
			strcat(prompt, ":~ ");
			strcat(temp, prompt);
<<<<<<< HEAD
			strcpy(prompt, temp);
=======
>>>>>>> 0cded797c93a9a995660d2ce16cb375a12f73698
			
		}
		else
		{
			system(command);
		}
<<<<<<< HEAD
		printf("%s", prompt);
=======
		printf("%s", temp);
>>>>>>> 0cded797c93a9a995660d2ce16cb375a12f73698
		gets(command);
	}
	printf("Process Completed.\n");
	EXIT_SUCCESS;
}