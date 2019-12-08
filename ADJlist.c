#include "RBtree.h"
#include "ADJlist.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>


int pathCheck(char random_path[100][3], int num) {
	for (int i = 0; i < num; i++) {
		if ((random_path[i][0] == random_path[num][0] && random_path[i][1] == random_path[num][1]) || (random_path[i][0] == random_path[num][1] && random_path[i][1] == random_path[num][0])) {
			return 1;
		}
	}
	return 0;
}

void random_City_Position(City* city) {
	
	
	for (int i = 0; i < 26; i++) {
		city[i].name = i + 'a';
		city[i].pos_x = rand() % 6000 - 3000;
		city[i].pos_y = rand() % 6000 - 3000;
	}
}
void insertNode(char start, char dest, int times) {
	int tstart = start - 'a';
	NODE* cur, * Newnode;
	Newnode = (NODE*)malloc(sizeof(NODE));
	Newnode->next = NULL;
	Newnode->data = dest;
	cur = Adjlist[tstart].head->next;
	if ((Adjlist[tstart].len == 0)) {
		Newnode->next = cur;
		Adjlist[tstart].head->next = Newnode;
		Adjlist[tstart].len++;
	}
	else if (cur->data > Newnode->data) {
		Newnode->next = cur;
		Adjlist[tstart].head->next = Newnode;
		Adjlist[tstart].len++;
	}
	else {
		while (1) {

			if (cur->next == NULL) {
				cur->next = Newnode;
				Adjlist[tstart].len++;
				break;
			}
			else if (Newnode->data < cur->next->data) {
				Newnode->next = cur->next;
				cur->next = Newnode;
				Adjlist[tstart].len++;
				break;
			}
			else {
				cur = cur->next;
			}
		}
	}
}

void init_Node() {
	
	for (int i = 0; i < 26; i++) {
		Adjlist[i].head = (NODE*)malloc(sizeof(NODE));
		Adjlist[i].head->next = NULL;
		Adjlist[i].len = 0;
	}
}
void PrintList(int i) {
	printf("%c\n", i);
	i = i - 'a';
	NODE* cur;
	int dec;
	printf("갈 수 있는 여행지: ");
	cur = Adjlist[i].head->next;
	while (!cur == NULL) {
		printf("%c ", cur->data);
		cur = cur->next;

	}
	printf("\n");
}


void make_ADJlist() {
	srand(time(NULL));
	init_Node();
	char random_path[100][3];

	for (int i = 0; i < 100; i++) {
		random_path[i][0] = (rand() % 26) + 'a'; // 0은 출발
		random_path[i][1] = (rand() % 26) + 'a'; // 1은 도착
		random_path[i][2] = (rand() % 24); //출발 시간
		if ((random_path[i][0] == random_path[i][1]) || pathCheck(random_path, i)) {
			i--;
			continue;
		}
	}

	for (int i = 0; i < 100; i++) {
		char start = random_path[i][0];
		char dest = random_path[i][1];
		int times = random_path[i][2];
		insertNode(start,dest, times);
		
	}
}

