#include "AvlTree.h"
#include "Util.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

static position singleRotateWithLeft(position k2);
static position doubleRotateWithLeft(position k2);
static position singleRotateWithRight(position k2);
static position doubleRotateWithRight(position k2);
static int height(position p)
{
	if (p == NULL)
		return -1;
	else
		return p->height;
}

static position singleRotateWithLeft(position k2)
{
	position k1 = k2->left;
	k2->left = k1->right;
	k1->right = k2;

	k2->height = max(height(k2->left), height(k2->right)) + 1;
	k1->height = max(height(k1->left), height(k1->right)) + 1;
	return k1;
}

static position doubleRotateWithLeft(position k2)
{
	k2->left = singleRotateWithRight(k2->left);
	return singleRotateWithLeft(k2);
}

static position singleRotateWithRight(position k2)
{
	position k1 = k2->right;
	k2->right = k1->left;
	k1->left = k2;
	
	k2->height = max(height(k2->left), height(k2->right)) + 1;
	k1->height = max(height(k1->left), height(k1->right)) + 1;
	return k1;
}

static position doubleRotateWithRight(position k2)
{
	k2->right = singleRotateWithLeft(k2->right);
	return singleRotateWithRight(k2);
}

AvlTree insert(int x, AvlTree T)
{
	if (T == NULL)
	{
		T = (AvlTree)malloc(sizeof(struct AvlNode));
		if (T == NULL)
			error("Out of space");
		else
		{
			T->element = x; T->height = 0;
			T->left = T->right = NULL;
		}
	}
	else if (x < T->element)
	{
		T->left = insert(x, T->left);
		if (height(T->left) - height(T->right) == 2)
		{
			if (x < T->left->element)
				T = singleRotateWithLeft(T);
			else if (x > T->left->element)
				T = doubleRotateWithLeft(T);
		}
	
	}
	else if (x > T->element)
	{
		T->right = insert(x, T->right);
		if (height(T->right) - height(T->left) == 2)
		{
			if (x < T->right->element)
				T = doubleRotateWithRight(T);
			else if (x > T->right->element)
				T = singleRotateWithRight(T);
		}
	}
	T->height = max(height(T->right), height(T->left)) + 1;
	return T;
}

void print(AvlTree T)
{
	if (T == NULL)
		return;
	else
	{
		print(T->left);
		printf("%d %d\n", T->element, T->height);
		print(T->right);
	}
}