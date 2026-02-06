

#include<stdio.h>
#include<string.h>
#include <ctype.h>
#include "header.h"

int main(int argc, char* argv[])
{
    //fuction for validating arguments
    if(validate(argc, argv) == FAILURE)
    {
        printf("Invalid Arguments\n");
        return FAILURE;
    }

    Dlist *head1 = NULL; //initialize the header to NULL
	Dlist *tail1 = NULL; //initialize the tail to NULL

    Dlist *head2 = NULL; //initialize the header to NULL
	Dlist *tail2 = NULL; //initialize the tail to NULL

    Dlist *resh = NULL; //initialize the header to NULL
	Dlist *rest = NULL; //initialize the tail to NULL

    int sign1 = 1, sign2 = 1;
    if(argv[1][0] == '-')
    {
        sign1 = -1;
        convert_str_to_list(argv[1] + 1, &head1, &tail1);  //+1 to skip sign
    }
    else
    {
        convert_str_to_list(argv[1], &head1, &tail1);
    }
    if(argv[3][0] == '-')  // Detect sign of operand1
    {
        sign2 = -1;
        convert_str_to_list(argv[3] + 1, &head2, &tail2);  //+1 to skip sign
    }
    else
    {
        convert_str_to_list(argv[3], &head2, &tail2);
    }

    //Display inputs
    printf("%c", sign1 == -1 ? '-' : ' ');
    print_list(head1);

    printf(" %c", argv[2][0]);

    printf("%c", sign2 == -1 ? '-' : ' ');
    print_list(head2);
    printf(" = ");

    int ressign = 1;

    switch(argv[2][0])
    {
        case '+':
            addition(&head1, &tail1, sign1, &head2, &tail2, sign2, &resh, &rest, &ressign);
            break;
        case '-':
           subtraction(&head1, &tail1, sign1, &head2, &tail2, sign2, &resh, &rest, &ressign);
            break;
        case 'x':
           multiplication(&head1, &tail1, sign1, &head2, &tail2, sign2, &resh, &rest, &ressign);
            break;
        case '/':
            division(&head1, &tail1, sign1, &head2, &tail2, sign2, &resh, &rest, &ressign);
            break;
    }

    trim_leading_zeroes(&resh, &rest);
    printf("%c", ressign == -1 ? '-' : ' ');
    print_list(resh);
    printf("\n");
    //print(head1);

}

