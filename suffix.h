#ifndef Suffix_H

#define Suffix_H

#include<stdio.h>

#include<stdlib.h>

typedef struct Node{

	char key;

	struct Node* child;

	struct Node* brother;

	int flag;

}*PNode;



char* Inversion(char*Pstr,int size_t);

PNode Build_tree(char* path, int reverse);

PNode CreateNullTree();

int Insert_Leaf(char*Pstr, PNode root, PNode father);

int Search_Tree(char*Pstr, PNode root, PNode father, int complete, int rerverse);

PNode Print_Tree(PNode root, PNode father, char *buff, int num, int reverse);

int strandstr(char *path,char *str);

#endif 
