#include "header.h"

int validate(int argc, char* argv[])
{
    if(argc != 4)
    {
        return FAILURE;
    }

    if(!(str_isdigit(argv[1]) && str_isdigit(argv[3])) )
    {
        return FAILURE;
    }
    if(strlen(argv[2]) != 1 )
    {
        return FAILURE;
    }
    if(!(argv[2][0] == '+'  || argv[2][0] == '-'|| argv[2][0] == 'x' || argv[2][0] == '/'))
    {
        return FAILURE;
    }
    return SUCCESS;
}

void convert_str_to_list(char* str, Dlist** head, Dlist** tail)
{
    int i = 0;
    while(str[i] != '\0')
    {
        dl_insert_last(head, tail, (str[i] - 48));
        i++;
    }
}

int dl_insert_last(Dlist **head, Dlist **tail, int data)
{
    //create node
    Dlist* new = malloc(sizeof(Dlist));
    
    //validation
    if(new == NULL)
    {
        return FAILURE;
    }
    
    //update
    new->data = data;
    new->next = NULL;
    new->prev = *tail;
    
    //if list empty
    if(*head == NULL)
    {
        *head = new;
        *tail = new;
        return SUCCESS;
    }
    
    (*tail)->next = new;
    *tail = new;
    return SUCCESS;
}

int dl_insert_first(Dlist **head, Dlist **tail, int data)
{
    //create node
    Dlist* new = malloc(sizeof(Dlist));
    
    //validation
    if(new == NULL)
    {
        return FAILURE;
    }
    
    //update
    new->data = data;
    new->next = *head;
    new->prev = NULL;
    
    //if list empty
    if(*head == NULL)
    {
        *head = new;
        *tail = new;
        return SUCCESS;
    }
    
    (*head) = new;
    (*head)->next->prev = new;
    return SUCCESS;

}

void print_list(Dlist *head)
{
	/* Cheking the list is empty or not */
	if (head == NULL)
	{
		printf("INFO : List is empty\n");
	}
	else
	{
	   // printf("Head -> ");
	    while (head)		
	    {
		    /* Printing the list */
		    printf("%d", head -> data);

		    /* Travering in forward direction */
		    head = head -> next;
		    /*if (head)
		        printf("> ");*/
	    }
    	//printf(" Tail\n");
    }
}

int dl_delete_first(Dlist **head, Dlist **tail)
{
    //if list empty
    if(*head == NULL)
    {
        return FAILURE;
    }
    
    //if only 1 node
    if(((*head)->next) == NULL)
    {
        //Dlist* temp = *head;
        free(*head);
        *head = NULL;
        *tail = NULL;
        return SUCCESS;
    }
    //if list not empty
    (*head) = (*head)->next;
    free((*head)->prev);
    (*head)->prev = NULL;
    return SUCCESS;
}

int dl_delete_list(Dlist **head, Dlist **tail)
{
    if(*head == NULL)
    {
        return FAILURE;
    }
    while(*head != NULL)
    {
        dl_delete_first(head, tail);
    }
    return SUCCESS;
}

int str_isdigit(char* str)
{
    int i= 0;
    if(str[i] == '+' || str[i] == '-')
    {
        i++;
    }
    while(str[i] != '\0')
    {
        if(!isdigit(str[i]))
        {
            return 0;
        }
        i++;
    }
    return 1;
}

int compare(Dlist* head1,Dlist* tail1, Dlist* head2, Dlist* tail2)
{
    Dlist* temp1 = tail1;
    Dlist* temp2 = tail2;

    //to find which is greater number
    int count1 = 0, count2 = 0;
    while(temp1 != NULL || temp2 != NULL)
    {

        if(temp1 != NULL)
        {
            count1++;
            temp1 = temp1->prev; 
        }
        if(temp2 != NULL)
        {
            count2++;
            temp2 = temp2->prev; 
        }
    }
    if(count1 > count2)
    {
        return 1;
    }
    else if(count2 > count1)
    {
        return -1;
    }
    else if(count1 == count2)
    {
        temp1 = head1;
        temp2 = head2;
        while(temp1 != NULL && temp1->data == temp2->data)
        {
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        if (temp1 == NULL && temp2 == NULL)
        {
            return 0;
        }
        if(temp1->data >= temp2->data)
        {
            return 1;
        }
        else
        {
            return -1;
        }
    }
}

void trim_leading_zeroes(Dlist **head, Dlist **tail)
{
    while(*head && (*head)->data == 0 && (*head)->next != NULL)
    {
        dl_delete_first(head, tail);
    }
}
