#include "header.h"
int multiplication(Dlist **head1, Dlist **tail1, int sign1, Dlist **head2, Dlist **tail2, int sign2, Dlist **resh, Dlist **rest, int* ressign)
{

    Dlist* temp1 = *tail1, *temp2 = *tail2; 
    Dlist* hR1 = NULL;
    Dlist* T1 = NULL;
    Dlist* hR2 = NULL;
    Dlist* T2 = NULL;

    int count = 0;
    int carry = 0;
    int pro;

    while(temp2 != NULL)
    {
        for(int i = 0; i < count; i++)
        {
            dl_insert_first(&hR1, &T1, 0);
        }
        while(temp1 != NULL)
        {
            pro = temp1->data * temp2->data + carry;
            if(count == 0)
            {
                dl_insert_first(resh, rest, pro % 10);
            }
            else
            {
                dl_insert_first(&hR1, &T1, pro % 10);
            }
            carry = pro / 10;
            temp1 = temp1->prev;
        }
        if(count == 0 && carry != 0)
        {
            dl_insert_first(resh, rest, carry);
            carry = 0;
        }
        else if(carry != 0)
        {
            dl_insert_first(&hR1, &T1, carry);
            carry = 0;
        }
        if(hR1 != NULL)
        {
            addition(resh, rest, sign1, &hR1, &T1, sign1, &hR2, &T2, ressign);
        }
        if(count != 0)
        {
            dl_delete_list(resh, rest);
            dl_delete_list(&hR1, &T1);
            *resh = hR2;
            *rest = T2;
            hR2 = NULL;
            T2 = NULL;
        }
        temp1 = *tail1;
        temp2 = temp2->prev;
        count++;
    }
    
    if(sign1 == sign2)
    {
        *ressign = 1;
    }
    else
    {
        *ressign = -1;
    }
    return SUCCESS;
}
