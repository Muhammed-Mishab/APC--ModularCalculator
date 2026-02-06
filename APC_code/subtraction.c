#include "header.h"
int subtraction(Dlist **head1, Dlist **tail1, int sign1, Dlist **head2, Dlist **tail2, int sign2, Dlist **resh, Dlist **rest, int* ressign)
{
    //temparay pointers for traversing
    Dlist* temp1 = *tail1;
    Dlist* temp2 = *tail2;

    Dlist* tempr = *resh;

    int cmp = compare(*head1, *tail1, *head2, *tail2);

    if(cmp == 1)  // |a| > |b|
    {
        temp1 = *tail1;
        temp2 = *tail2;
        if(sign1 == -1 && sign2 == 1) //-a - b = -(a+b) 
        {
            addition(head1, tail1, 1, head2, tail2, 1, resh, rest, ressign);
            *ressign = -1;
            return SUCCESS;
        }
        else if(sign1 == 1 && sign2 == -1) //a--b = a + b
        {
            addition(head1, tail1, 1, head2, tail2, 1, resh, rest, ressign);
            *ressign = 1;
            return SUCCESS;
        }
    }
    else if(cmp == -1) //|b| > |a|
    {
        //swap pointers
        temp1 = *tail2;
        temp2 = *tail1;
        if(sign1 == -1 && sign2 == 1) 
        {
            addition(head1, tail1, 1, head2, tail2, 1, resh, rest, ressign);
            *ressign = -1;
            return SUCCESS;
        }
        else if(sign1 == 1 && sign2 == -1)
        {
            addition(head1, tail1, 1, head2, tail2, 1, resh, rest, ressign);
            *ressign = 1;
            return SUCCESS;
        }
        else if(sign1 == -1 && sign2 == -1)
        {
            *ressign = 1;
        }
        else
        {
            *ressign = -1;
        }
    }
    else if(cmp == 0)  //|a| == |b|
    {
        if(sign1 == sign2)
        {
            *ressign = 1;
        }
        else if(sign1 = -1 && sign2 == 1)
        {
            addition(head1, tail1, 1, head2, tail2, 1, resh, rest, ressign);
            *ressign = -1;
            return SUCCESS;
        }
        else
        {
            addition(head1, tail1, 1, head2, tail2, 1, resh, rest, ressign);
            *ressign = 1;
            return SUCCESS;
        }

    }

    //int borrow = 0;
    while(temp1 != NULL || temp2 != NULL)
    {
        int diff;

        if (temp2 == NULL)
        {
            diff = temp1->data;
        }

        else if(temp1->data >= temp2->data)
        {
            diff = temp1->data - temp2->data;
        }
        else
        {
            //code for borrow
            Dlist *borrow = temp1;
            while(borrow->prev->data == 0)  //checks for non zero digit to borrow from
            {
                borrow = borrow->prev;
            }
            borrow->prev->data--;   //decrements after borrowing

            while(borrow != temp1)   //changes these zeroes to 9 after borrowing
            {
                borrow->data = 9;
                borrow = borrow->next;
            }
            diff = (temp1->data + 10) - temp2->data;
        }

        dl_insert_first(resh, rest, diff);

        if(temp1 != NULL)
        {
            temp1 = temp1->prev; //moves temp1 forward
        }
        if(temp2 != NULL)
        {
            temp2 = temp2->prev;  //moves temp2 forward
        }
    }
    return SUCCESS;
}