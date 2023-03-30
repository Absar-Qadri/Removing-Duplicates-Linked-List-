#include <stdio.h>
#include <stdlib.h>
struct node{
int data;
struct node *next;
};
struct node *head, *tail = NULL;
void addNode(int data) {
struct node *newNode = (struct node*)malloc(sizeof(struct node));
newNode->data = data;
newNode->next = NULL;
if(head == NULL) {
head = newNode;
tail = newNode;
}
else {
tail->next = newNode;
tail = newNode;
}
}
void removeDuplicates() {
struct node *current = head, *index = NULL, *temp = NULL;
if(head == NULL) {
return;
}
else {
while(current != NULL){
temp = current;
index = current->next;
while(index != NULL) {
if(current->data == index->data) {
temp->next = index->next;
}
else {
temp = index;
}
index = index->next;
}
current = current->next;
}
}
}
void display() {
struct node *current = head;
if(head == NULL) {
printf("List is empty \n");
return;
}
while(current != NULL) {
printf("%d ", current->data);
current = current->next;
}
printf("\n");
}
int main()
{
int a[104];
int n;
int i=0;
printf("Enter the number of elements: \n");
scanf("%d",&n);
printf("Enter elements :\n");
for(i=0;i<n;i++)
{
scanf("%d",&a[i]);
addNode(a[i]);
}
removeDuplicates();
printf("List after removing duplicates: \n");
display();
return 0;
}
