#include <stdio.h> 
#include <stdlib.h> 
#include<string.h> 
struct node 
{ 
int num; 
struct node *next; 
}; 
void create(struct node **); 
void display(struct node *); 
int survivor(struct node **, int); 
int main() 
{ struct node *head = NULL; 
int survive; 
create(&head); 
printf("The persons in circular list are:\n"); 
display(head); 
char a[10]; 
char b[10]; 
int i,l1,l2,x=0,k=0,j; 
printf("Enter the first name\n"); 
scanf("%s",&a); 
printf("Enter the second name\n"); 
scanf("%d",&b); 
l1=strlen(a); 
l2=strlen(b); 
for(i=0;i<l1;i++) 
{ 
x=0; 
for(j=0;j<l2;j++) 
{ 
if(a[i]==b[j]) 
{ 
x=1; 
b[j]=' ';} 
} 
if(x==1) 
a[i]=' '; 
} 
x=0; 
for(i=0;i<l1;i++) 
{ 
if(a[i]!=' ') 
x++; 
} 
for(i=0;i<l2;i++) 
{ 
if(b[i]!=' ') 
x++; 
} 
survive = survivor(&head, x); 
if(survive==1) 
printf("Relationship is friendship"); 
else if(survive==2) 
printf("Relationship is Love"); 
else if(survive==3)printf("Relationship is Affair"); 
else if(survive==4) 
printf("Relationship is Marriage"); 
else if(survive==5) 
printf("Relationship is Enemy"); 
else if(survive==6) 
printf("Relationship is Sister"); 
free(head); 
return 0; 
} 
int survivor(struct node **head, int k) 
{ 
struct node *p, *q; 
int i; 
q = p = *head; 
while (p->next != p) 
{ 
for (i = 0; i < k - 1; i++) 
{ 
q = p; 
p = p->next; 
} 
q->next = p->next; printf("%d has been killed.\n", p->num); 
free(p); 
p = q->next; 
} 
*head = p; 
return (p->num); 
} 
void create (struct node **head) 
{ 
struct node *temp, *rear; 
int a=1, ch; 
do 
{ 
temp = (struct node *)malloc(sizeof(struct node)); 
temp->num = a; 
temp->next = NULL; 
if (*head == NULL) 
{ 
*head = temp; 
} 
else 
{ 
rear->next = temp; 
} 
rear = temp; 
a++; } while (a <= 6); 
rear->next = *head; 
} 
void display(struct node *head) 
{ 
struct node *temp; 
temp = head; 
printf("%d ", temp->num); 
temp = temp->next; 
while (head != temp) 
{ 
printf("%d ", temp->num); 
temp = temp->next; 
} 
printf("\n"); 
}


