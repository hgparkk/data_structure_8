/*
프로그램 내용 : 수식트리 프로그램
실습일 : 2023.05.11
실습자 : 박현규
학번 : 202111678
*/

#include <stdio.h>
#include <stdlib.h>
typedef int TElement;
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

int evaluate(TNode* n)
{
	int op1, op2;
	if (n == NULL) return 0;
	if (n->left == NULL && n->right == NULL) return n->data;
	else
	{
		op1 = evaluate(n->left);
		op2 = evaluate(n->right);
		switch (n->data)
		{
		case '+': return op1 + op2;
		case '-': return op1 - op2;
		case '*': return op1 * op2;
		case '/': return op1 / op2;
		}
		return 0;
	}
}

int main()
{
	TNode* n1, * n2, * n3, * n4, * n5, * n6;

	n1 = create_tree(3, NULL, NULL);
	n2 = create_tree(2, NULL, NULL);
	n3 = create_tree('*', n1, n2);
	n4 = create_tree(5, NULL, NULL);
	n5 = create_tree(6, NULL, NULL);
	n6 = create_tree('-', n4, n5);
	root = create_tree('+', n3, n6);
	printf(" 계산 결과 = %d\n", evaluate(root));
}
