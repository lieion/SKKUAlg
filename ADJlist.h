#ifndef ADJtree_H
#define ADJtree_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
#include <string.h>

#pragma warning (disable : 4996)
typedef enum { false, true } bool;
typedef struct city {
	char name;
	int pos_x;
	int pos_y;
} City;

typedef struct node {
	struct node* next;
	int data;
	int tm;
}NODE;

typedef struct link
{
	NODE* head;
	int len;
} LinkedList;




LinkedList Adjlist[50];

int pathCheck(char random_path[100][3], int num);
void random_City_Position(City* city);
void insertNode( char start, char dest, int times);
void init_Node();
void PrintList(int i);
void make_ADJlist();










#endif