#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define MAX_LEN 15

typedef struct _Node {
	int data;
	struct _Node *next;
}Node;

void InitList(Node* now);
void AddList(Node* now, int n);
void rInvert(Node* r, Node* head,int n);
Node* lInvert(Node* right, Node* left, int n);
void Print(Node* r);

int main() {
	int num;
	Node *head = (Node*)malloc(sizeof(Node));
	Node *right = (Node*)malloc(sizeof(Node));

	InitList(head);
	AddList(head,MAX_LEN);
	printf("The Original List: ");
	Print(head->next);
	printf("\n");
	printf("Enter n : ");
	scanf("%d", &num);

	printf("------------------------------------------------------------\n");
	printf("Implement (a)\n\n");

	rInvert(right, head, num);
	

	while (1);
}

void InitList(Node* head) {
	head->next = NULL;
}

void AddList(Node* head,int n) {
	for (int i = 1; i < n; i++) {
		Node* newNode = (Node*)malloc(sizeof(Node));
		
		newNode->data= i;
		head->next = newNode;
		head = newNode;
	}
	InitList(head);
}

void rInvert(Node* r, Node* head, int n) {
	int i = 0;
	Node* middle;
	Node* trail;
	Node* temp;

	Node *right;
	Node *left;

	middle = NULL;
	while ((i<=n)&&(head!=NULL)) {
		trail = middle;
		middle = head;
		head = head->next;
		middle->next = trail;
		r = head;
		i++;
	}

	printf("when n=%d, Print Left to Right (rlist): ",n);

	Print(r);

	printf("when n=%d, Print Right to Left (llist): ", n);
	left = middle;
	Print(middle);


	printf("------------------------------------------------------------\n");
	printf("Implement (b)\n\n");
	n = n - 4;
	right = r;
	temp = lInvert(right, left, n);
	printf("when n=%d, Print Right to Left (llist): ", n);
	Print(temp);
}

Node* lInvert(Node* right, Node* left, int n) {
	int i = 0;
	Node* middle;

	middle = NULL;
	while ((i <= n) && (left ->next != NULL)) {
		middle = left;
		left = left->next;
		middle->next = right;
		right = middle;
		i++;
	}
	printf("when n=%d, Print Left to Right (rlist): ", n);
	Print(right);

	return left;
}

void Print(Node* r) {
	while (r->next != NULL) {
		printf("%4d", r->data);
		r = r->next;
	}
	printf("\n");
}