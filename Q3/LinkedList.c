#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//#define ENGLISH
#define FRENCH

struct node //each node of linked list
{
	char content[300]; //content in each node
	struct node* next; //creating next node
};

int main()
{
	char word[300]; //create an array of char to store the word the user is going to type each time

	#ifdef ENGLISH
		printf("Welcome to the infinite string storage program.\n");
		printf("Only the first word of each input will be printed.\n");
		printf("type ***END*** to print your list of words.");
		printf("Input a word:");
	#endif
	#ifdef FRENCH
		printf("Bonjour, bienvenue au programme ayant une mémoire infinie.\n");
		printf("Rien que le premier mot entré a chaque fois sera enregistrer.\n");
		printf("Entrez ***END*** pour afficher votre list.\n");
		printf("Entrez un mot:");
	#endif

	fgets(word,299,stdin);
	sscanf(word,"%s",word); //takes only one word
	if (strcmp(word,"***END***")==0) //exiting program
	{
		exit(0);
	}

	struct node* head=(struct node*)malloc(sizeof(struct node)); //head of list
	strcpy(head->content,word); //gives a string to the content
	head->next = NULL;

	#ifdef ENGLISH
		printf("Input a word:");
	#endif
	#ifdef FRENCH
		printf("Entrez un mot:");
	#endif
		fgets(word,299,stdin);
		sscanf(word,"%s",word); //takes only one word

	while(strcmp(word,"***END***")!=0) //the user must enter ***END*** to print the Linked List.
	{									//While the user does not enter ***END*** the contents will still get every first word of the input
		struct node* conductor; //conduct through the linked list
		conductor=head; //conductor is head

		while (conductor -> next!=NULL) //while next is not null conductor is next
		{
			conductor = conductor -> next;//goes on till end of file
		}

		
		struct node* newNode=(struct node*)malloc(sizeof(struct node)); //creating a new node
		conductor -> next=newNode;
		strcpy(newNode->content,word); //the new node gets the content
		newNode -> next=NULL;

		#ifdef ENGLISH
			printf("Input a word:");
		#endif
		#ifdef FRENCH
			printf("Entrez un mot:");
		#endif
		fgets(word,299,stdin);
		sscanf(word,"%s",word); //same as before takes only one word from the input
	}

	struct node* conductor;
	conductor=head;
	printf("\n");
	#ifdef ENGLISH
	printf("The linked list is: ");
	#endif
	#ifdef FRENCH
	printf("La liste est: ");
	#endif
	while (conductor -> next!=NULL)
	{
		printf("%s ",conductor->content);
		conductor = conductor->next;
	}
	printf("%s ",conductor->content);

	conductor=head;
	struct node* temp;
	while(conductor!=NULL)
	{
		temp=conductor->next; //next node is in temp
		free(conductor); //deletes conductor (current node)
		conductor=temp; //next node is current
	}

	return 0;
}