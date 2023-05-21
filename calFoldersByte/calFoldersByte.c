/*
프로그램 내용 : 폴더의 용량 계산 프로그램
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

int calc_size(TNode* n)
{
	if (n == NULL) return 0;
	return n->data + calc_size(n->left)+calc_size(n->right);
}

void main()
{
	TNode* m2, * m3, * m4, * m5;

	m4 = create_tree(200, NULL, NULL);
	m5 = create_tree(500, NULL, NULL);
	m3 = create_tree(100, m4, m5);
	m2 = create_tree(50, NULL, NULL);
	root = create_tree(0, m2, m3);
	printf(" 촐더 용량 = %d KB\n", calc_size(root));
}