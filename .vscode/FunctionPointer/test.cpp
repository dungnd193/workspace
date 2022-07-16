#include "list.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int compare_case_sensitive(char *s1, char *s2)
{
	return strcmp(s1,s2);
}

int compare_nocase_sensitive(char *s1, char *s2)
{
	int i=0;
	while(i<strlen(s1) && i<strlen(s2))
	{
		if(toupper(s1[i])>toupper(s2[i])) return 1;
		else if(toupper(s1[i])<toupper(s2[i])) return -1;
		i++;
	}
	if(strlen(s1)==strlen(s2)) return 0;
	else if(strlen(s1)>strlen(s2)) return 1;
	return -1;
}

// tach ra phan ten rieng: Nguyen Van Dung --> Dung
// so sanh ten rieng truoc, neu ten rieng trung nhau thi moi so sanh den ho
// so sanh khong phan biet hoa/thuong
char* tachten(char *fullname)
{
	int idx = -1;
	for(idx=strlen(fullname)-1; idx>=0; idx--)
		if(fullname[idx]==' ') break;
	int i = 0;
	char * ret = (char*)malloc(50*sizeof(char));
	for(idx = idx+1; idx<strlen(fullname); idx++)
	{
		ret[i] = fullname[idx];
		i++;
	}
	ret[i] = '\0';
	return ret;
}
int compare_name_nocase_sensitive(char *s1, char *s2)
{
	// CODE
	// tách tên trong hoten day du
	
}

int main()
{
	char list[5][50]={"Dung", "Tran Xuan Dung", "Nguyen Thi Hoa", "Le Thi Ha", "Hoang Hai"};
	int n=5;
	printf("%s --> %s\n",list[0], tachten(list[0]));
	
	printList(list,n);
	sortlist(list,n,compare_nocase_sensitive);
	printList(list,n);
	
	return 0;
}
