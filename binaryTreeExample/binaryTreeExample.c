﻿/*
프로그램 내용 : 이진트리 프로그램
실습일 : 2023.05.11
실습자 : 박현규
학번 : 202111678
*/

#include <stdio.h>
#include <stdlib.h>
typedef char TElement;
typedef struct BinTrNode
{
	TElement data;
	struct BinTrNode* left;
	struct BinTrNode* right;
} TNode;
TNode* root;

void init_tree() { root = NULL; }
int is_empty_tree() { return root == NULL; }
TNode* get_root() { return root; }

TNode* create_tree(TElement val, TNode* l, TNode* r)
{
	TNode* n = (TNode*)malloc(sizeof(TNode));
	n->data = val;
	n->left = l;
	n->right = r;
	return n;
}

int count_node(TNode* n)
{
	if (n == NULL) return 0;
	return 1 + count_node(n->left) + count_node(n->right);
}

int count_leaf(TNode* n)
{
	if (n == NULL) return 0;
	if (n->left == NULL && n->right == NULL) return 1;
	else return count_leaf(n->left) + count_leaf(n->right);
}

int count_nonleaf(TNode* n)
{
	if (n == NULL) return 0;
	if (n->left == NULL && n->right == NULL) return 0;
	else return 1+count_nonleaf(n->left) + count_nonleaf(n->right);
}

int calc_height(TNode* n)
{
	int hLeft, hRight;
	if (n == NULL) return 0;
	hLeft = calc_height(n->left);
	hRight = calc_height(n->right);
	return (hLeft > hRight) ? hLeft + 1 : hRight + 1;
}

void preorder(TNode* n)
{
	if(n!=NULL)
	{
		printf("[%c] ", n->data);
		preorder(n->left);
		preorder(n->right);
	}
}

void inorder(TNode* n)
{
	if (n != NULL)
	{
		inorder(n->left);
		printf("[%c] ", n->data);
		inorder(n->right);
	}
}

void postorder(TNode* n)
{
	if (n != NULL)
	{
		postorder(n->left);
		postorder(n->right);
		printf("[%c] ", n->data);
	}
}

#define MAX_QUEUE_SIZE 100
typedef TNode* Element;

Element data[MAX_QUEUE_SIZE];
int front;
int rear;

void error(char* str)
{
	printf("%s\n", str);
	exit(1);
}

void init_queue() { front = rear = 0; }
int is_empty() { return front == rear; }
int is_full() { return front == (rear + 1) % MAX_QUEUE_SIZE; }
int size() { return(rear - front + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE; }

void enqueue(Element val)
{
	if (is_full())
		error(" 큐 포화 에러");
	rear = (rear + 1) % MAX_QUEUE_SIZE;
	data[rear] = val;
}

Element dequeue()
{
	if (is_empty())
		error(" 큐 공백 에러");
	front = (front + 1) % MAX_QUEUE_SIZE;
	return data[front];
}

Element peek()
{
	if (is_empty())
		error(" 큐 공백 에러");
	return data[(front + 1) % MAX_QUEUE_SIZE];
}

void levelorder(TNode* root)
{
	TNode* n;
	if (root == NULL) return;
	init_queue();
	enqueue(root);
	while (!is_empty())
	{
		n = dequeue();
		if (n != NULL)
		{
			printf("[%c] ", n->data);
			enqueue(n->left);
			enqueue(n->right);
		}
	}
}

int main()
{
	TNode* b, * c, * d, * e, * f;

	init_tree();
	d = create_tree('D', NULL, NULL);
	e = create_tree('E', NULL, NULL);
	b = create_tree('B', d, e);
	f = create_tree('F', NULL, NULL);
	c = create_tree('C', f, NULL);
	root = create_tree('A', b, c);

	printf("\n In-Order : ");
	inorder(root);
	printf("\n Pre-Order : ");
	preorder(root);
	printf("\n Post-Order : ");
	postorder(root);
	printf("\n Level-Order : ");
	levelorder(root);
	printf("\n");

	printf(" 노드의 개수 = %d\n", count_node(root));
	printf(" 단말의 개수 = %d\n", count_leaf(root));
	printf(" 비단말의 개수 = %d\n", count_nonleaf(root));
	printf(" 트리의 높이 = %d\n", calc_height(root));
}
