#include "list.hpp"
#include <string.h>
#include <stdio.h>

void sortlist(char list[100][50], int size, int (*compare)(char *, char *))
{
	for(int i=size; i>1; i--)
		for(int j=1; j<i; j++)
			if(compare(list[j-1], list[j])>0)
			{
				char tmp[50];
				strcpy(tmp, list[j-1]);
				strcpy(list[j-1],list[j]);
				strcpy(list[j],tmp);
			}
}

void printList(char list[100][50], int size)
{
	printf("Danh sach:\n");
	for(int i=0; i<size; i++)
		printf("%s\n",list[i]);
	printf("\n");
}
