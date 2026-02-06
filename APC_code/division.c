#include "header.h"
int division(Dlist **head1, Dlist **tail1, int sign1, Dlist **head2, Dlist **tail2, int sign2, Dlist **resh, Dlist **rest, int* ressign)
{
    if(sign1 == sign2)
    {
        *ressign = 1;
    }
    else
    {
        *ressign = -1;
    }
    Dlist* subresh = NULL;
    Dlist* subrest = NULL;

    Dlist *newSumH = NULL, *newSumT = NULL;
    Dlist *newQH = NULL, *newQT = NULL;


    Dlist *divresh = NULL, *divrest = NULL;
    Dlist *divsubresh = NULL, *divsubrest = NULL;
    dl_insert_first(&subresh, &subrest, 0);

    Dlist *oneh = NULL, *onet = NULL;
    dl_insert_first(&oneh, &onet, 1);
    dl_insert_first(&divsubresh, &divsubrest, 0);

    *resh = NULL;
    *rest = NULL;

    int sign = 1;

    while(1)
    {

        addition(&subresh, &subrest, 1, head2, tail2, 1, &newSumH, &newSumT, ressign);

        dl_delete_list(&subresh, &subrest);
        subresh = newSumH;
        subrest = newSumT;

        newSumH = NULL;
        newSumT = NULL;

        if(compare(subresh, subrest , *head1, *tail1) > 0)
        {
            break;
        }
        addition(&divsubresh, &divsubrest, 1, &oneh, &onet, 1, &newQH, &newQT, ressign);
        dl_delete_list(&divsubresh, &divsubrest);
        divsubresh = newQH;
        divsubrest = newQT;

        newQH = NULL;
        newQT = NULL;
    }
    *resh = divsubresh;
    *rest = divsubrest;
    return SUCCESS;
}

