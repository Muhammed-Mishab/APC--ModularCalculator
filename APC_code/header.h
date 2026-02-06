#ifndef HEAD_H
#define HEAD_H

#include <stdio.h>
#include<string.h>
#include <ctype.h>
#include <stdlib.h>

#define SUCCESS 1
#define FAILURE 0

typedef struct node
{
	int data;
	struct node *prev;
	struct node *next;
}Dlist;

int validate(int argc, char* argv[]);
int str_isdigit(char* str);
void convert_str_to_list(char* str, Dlist** head, Dlist** tail);
int addition(Dlist **head1, Dlist **tail1, int sign1, Dlist **head2, Dlist **tail2, int sign2, Dlist **resh, Dlist **rest, int* ressign);
int subtraction(Dlist **head1, Dlist **tail1, int sign1, Dlist **head2, Dlist **tail2, int sign2, Dlist **resh, Dlist **rest, int* ressign);
int multiplication(Dlist **head1, Dlist **tail1, int sign1, Dlist **head2, Dlist **tail2, int sign2, Dlist **resh, Dlist **rest, int* ressign);
int division(Dlist **head1, Dlist **tail1, int sign1, Dlist **head2, Dlist **tail2, int sign2, Dlist **resh, Dlist **rest, int* ressign);

int dl_insert_first(Dlist **head, Dlist **tail, int data);
int dl_insert_last(Dlist **head, Dlist **tail, int data);
int dl_delete_first(Dlist **head, Dlist **tail);
//int dl_delete_last(Dlist **head, Dlist **tail);
int dl_delete_list(Dlist **head, Dlist **tail);
void print_list(Dlist *head);
int compare(Dlist* head1, Dlist* tail1, Dlist* head2, Dlist* tail2);
void trim_leading_zeroes(Dlist **head, Dlist **tail);

#endif