//Note: Ther is an error in removing players if there are more than 1

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct player {
	char *name;
	struct player *next;
} Player;

char* pop(Player **head);
char* my_remove_by_index(Player ** head, int n);

int main() {
	int flag = 0;
	printf("Hello, user!\n");

	Player * first = NULL;
	//head = malloc(sizeof(Player));
	Player * head = NULL;

	while (flag != 5)
	{
		printf("\nMenu:\n1)Add player\n2)Remove player\n3)Print players\n4)Clear list\n5)Exit");
		printf("\nPress the number of operation:");
		scanf("%d", &flag);
		
		switch (flag)
		{
			case 1: //adding the player
				printf("\nWhat is the name of a new player? - ");
				char *newName = malloc(sizeof(char) * 256);
				scanf("%s", newName);
				Player * newNode = malloc(sizeof(Player));
				newNode->name = newName;
				newNode->next = NULL;

				if (first == NULL) {
					first = newNode;
					head = first;
				}
				else
				{
					head->next = newNode;
					head = head->next;
				}

				printf("\nName is %s", head->name);
				break;
			case 2://removing by index
				if (head == NULL)
				{
					printf("There're no players in list!");
					break;
				}
				else
				{
					int ind = -1;
					printf("What is the index of the player you want to remove ? -");
					scanf("%d", &ind);
					char* name = my_remove_by_index(&first, ind);
					printf("\nHis/her name was - %s", name);
				}
				break;
			case 3://printing
				if (first == NULL)
					break;
				else
				{
					int count = 0;
					Player * current = NULL;
					current = first;
					while (current != NULL)
					{
						printf("\n(%d) Name: %s ->", count, current->name);
						current = current->next;
						++count;
					}
				}
				break;
			case 4://clearing the list
				;
				Player *current = first;
				Player *next;

				while (current != head->next)
				{
					next = current->next;
					free(current);
					current = next;
				}
				//first = NULL;
				break;
			case 5:
				return 0;
			}
		}
	return 0;
}

char* pop(Player **head)
{
	char* retval = "";
	Player * next_node = NULL;

	if (*head == NULL) {
		return "-";
	}

	next_node = (*head)->next;
	retval = (*head)->name;
	free(*head);
	*head = next_node;

	return retval;
}

char* my_remove_by_index(Player ** first, int index) {
	int i = 0;
	char* retval = "";
	Player * start = NULL;
	Player * deleted = *first;
	Player * next = NULL;

	if (index == 0) {
		retval = pop(&deleted);
	}
	else {
		int i = 0;
		while (i < index - 1){
			deleted = deleted->next;
			++i;
		}
		start = deleted;
		deleted = deleted->next;
		next = deleted->next;
		if (next == NULL){
			retval = deleted->name;
			pop(&deleted);
		} else {
			retval = deleted->name;
			start->next = next;
			free(deleted);
		}
	}
	return retval;
}