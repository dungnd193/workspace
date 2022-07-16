#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct NODE
{
	char hoten[50];
	char shsv[20];
	struct NODE *next;
} SV;

SV *head = NULL;


// ham them vao 
// neu pre = NULL thi them vao dau
// nguoc lai them vao sau pre
SV *add(SV *head, char *hoten, char *shsv, SV* pre)
{
	//1. cap phat bo nho dong cho phan tu moi
	SV *pNew = (SV*)malloc(sizeof(SV));
	strcpy(pNew->hoten, hoten);
	strcpy(pNew->shsv, shsv);
	if(pre == NULL) // them vao dau
	{
		pNew->next = head;
		head = pNew;
	}
	else // chen vao sau pre
	{
		pNew->next = pre->next;
		pre->next = pNew;
	}
	return head;	
}

// ham them vao 
// neu pre = NULL thi them vao dau
// nguoc lai them vao sau pre
void add2(SV **head, char *hoten, char *shsv, SV* pre)
{
	//1. cap phat bo nho dong cho phan tu moi
	SV *pNew = (SV*)malloc(sizeof(SV));
	strcpy(pNew->hoten, hoten);
	strcpy(pNew->shsv, shsv);
	if(pre == NULL) // them vao dau
	{
		pNew->next = *head;
		*head = pNew;
	}
	else // chen vao sau pre
	{
		pNew->next = pre->next;
		pre->next = pNew;
	}
}

void printList(SV *head)
{
	SV *p = head;
	while(p != NULL)
	{
		printf("Hoten: %s, SHSV: %s\n",p->hoten,p->shsv);
		p=p->next;
	}
	printf("\n");
}

SV *find(SV* head, char *shsv)
{
	SV *p = head;
	while(p != NULL)
	{
		if(strcmp(p->shsv,shsv)==0) return p;
		p=p->next;
	}
	return NULL;
}

void freeList(SV **head)
{
	while(*head!=NULL)
	{
		SV *p = (*head)->next;
		free(*head);
		*head = p;
	}
	*head = NULL;
}


// xoa sinh vien co SHSV trung tham so
// neu khong tim thay thi thoi
SV * remove(SV *head, char *shsv) 
{
	SV* p = find (head, shsv);
	if(p==NULL) return head; // shsv can tim ko ton tai
	if(p==head) //phan tu can xoa la dau danh sach
	{
		head = head ->next;
	}
	else // phan tu can xoa o giua/cuoi
	{
		// can tim phan tu truoc vi tri can xoa
		SV* pre = head;
		while(pre->next!=p) pre=pre->next;
		
		// xoa phan tu
		pre->next = p->next;
	}
	free(p);
	return head;
}

int main()
{
	char hoten[50], shsv[20];
	
	
	head = add(head,"C","3", NULL);
	head = add(head,"B","2", NULL);
	head = add(head,"A","1", NULL);
	
	printList(head);
	
    //them D vao sau A
    SV *pre = find(head,"1");
    head = add(head,"D","4",pre);
    printList(head);
    
    printf("Xoa SHSV 2\n");
    head = remove(head,"2");
    printList(head);

    freeList(&head);

    return 0;

}