#ifndef _AvlTree_H
struct AvlNode;
typedef struct AvlNode *position;
typedef struct AvlNode *AvlTree;

AvlTree makeEmpty(AvlTree T);
position find(int x, AvlTree T);
position findMin(AvlTree T);
position findMax(AvlTree T);
AvlTree insert(int x, AvlTree T);
AvlTree del(int x, AvlTree T);
int retrieve(position p);
void print(AvlTree T);
#endif

struct AvlNode
{
	int element;
	AvlTree left;
	AvlTree right;
	int height;
};