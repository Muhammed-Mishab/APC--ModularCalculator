#include "header.h"

int addition(Dlist **head1, Dlist **tail1, int sign1, Dlist **head2, Dlist **tail2, int sign2, Dlist **resh, Dlist **rest, int* ressign)
{
    if(sign1 == -1 && sign2 == -1)
    {
        *ressign = -1;
    }
    else if(sign1 == 1 && sign2 == -1) 
    {
        subtraction(head1, tail1, 1, head2, tail2, 1, resh, rest, ressign);
        if(compare(*head1, *tail1, *head2, *tail2) >= 1)
        {
            *ressign = 1;
        }
        return SUCCESS;
    }
    else if(sign1 == -1 && sign2 == 1) 
    {
        subtraction(head2, tail2, 1, head1, tail1, 1, resh, rest, ressign);
        if(compare(*head1, *tail1, *head2, *tail2) > 1)
        {
            *ressign = -1;
        }
        return SUCCESS;
    }

    //temparary pointers for traversing
    Dlist* temp1 = *tail1;  
    Dlist* temp2 = *tail2;

    int carry = 0;  //carry initializing
    while(temp1 != NULL || temp2 != NULL)
    {
        int sum;
        if(temp1 == NULL)
        {
            sum = temp2->data + carry;
        }
        else if (temp2 == NULL)
        {
            sum = temp1->data + carry;
        }
        else
        {
            sum = temp1->data + temp2->data + carry;
        }
        carry = sum / 10;

        dl_insert_first(resh, rest, sum % 10);  //insert reminder to the result

        if(temp1 != NULL)
        {
            temp1 = temp1->prev;
        }
        if(temp2 != NULL)
        {
            temp2 = temp2->prev;
        }
    }
    if(carry)  //checking if carry is left behind
    {
        dl_insert_first(resh, rest, carry);
    }
    return SUCCESS;
}