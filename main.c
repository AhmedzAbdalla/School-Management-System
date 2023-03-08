#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#include "Linked_list.h"
int main()
{
    unsigned int option=0;
    unsigned int std_ID=0;
    std_return my_ret;
    linked_list my_list;
    create_list(&my_list);
    while(1)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
        printf("\n************************* Welcome to NTI Project *************************\n\n");
        printf("=>Main Menu\n");
        printf("================================================================\n");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
        printf("=> 1) Add New Student\n");
        printf("=> 2) Edit Student Information\n");
        printf("=> 3) Delete Student\n");
        printf("=> 4) Add/update Student Score\n");
        printf("=> 5) List All Students Information\n");
        printf("=> 6) List All Students alphabetically\n");
        printf("=> 7) List All Students according to score\n");
        printf("=> 8) Exit\n");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);
        printf("\n******* Enter your option *******\n");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);

        while(1)
        {
            scanf("%i",&option);
            fflush(stdin);
            if(option >=1 && option <=8)
            {
                break;
            }
            printf("please enter a valid option!!\n");
        }
        switch(option)
        {
        case 1:
            my_ret = insert_node(&my_list);
            printf("\n-------------------------------------------\n");
            printf("=>return status: %d\n",my_ret);
            printf("=>no of elements = %i\n", my_list.list_size);
            printf("\n-------------------------------------------\n");
            break;
        case 2:

            if( !(my_list.list_size == 0) )
            {
                printf("Enter Student ID\n");
                scanf("%i",&std_ID);
                fflush(stdin);
                my_ret = std_edit(&my_list,std_ID);
                printf("\n-------------------------------------------\n");
                printf("=>return status: %d\n",my_ret);
                printf("=>no of elements = %i\n", my_list.list_size);
                printf("\n-------------------------------------------\n");
            }
            else
            {
                printf("=>List is empty\n");
            }

            break;
        case 3:
            if( !(my_list.list_size == 0) )
            {
                printf("Enter Student ID\n");
                scanf("%i",&std_ID);
                fflush(stdin);
                my_ret = delete_student(&my_list , std_ID);
                printf("\n-------------------------------------------\n");
                printf("=>return status: %d\n",my_ret);
                printf("=>no of elements = %i\n", my_list.list_size);
                printf("\n-------------------------------------------\n");
            }
            else
            {
                printf("=>List is empty\n");
            }
            break;
        case 4:
            if( !(my_list.list_size == 0) )
            {
                printf("Enter Student ID\n");
                scanf("%i",&std_ID);
                fflush(stdin);
                my_ret = std_score(&my_list,std_ID);
                printf("\n-------------------------------------------\n");
                printf("=>return status: %d\n",my_ret);
                printf("=>no of elements = %i\n", my_list.list_size);
                printf("\n-------------------------------------------\n");
            }
            else
            {
                printf("=>List is empty\n");
            }
            break;
        case 5:
            if( !(my_list.list_size == 0) )
            {
                my_ret = std_info_all(&my_list);
                printf("\n-------------------------------------------\n");
                printf("=>return status: %d\n",my_ret);
                printf("=>no of elements = %i\n", my_list.list_size);
                printf("\n-------------------------------------------\n");
            }
            else
            {
                printf("=>List is empty\n");
            }
            break;
        case 6:
            if( !(my_list.list_size == 0) )
            {
                view_list(&my_list , 'a');
                std_info_all(&my_list);
                printf("=>no of elements = %i\n", my_list.list_size);;
            }
            else
            {
                printf("=>List is empty\n");
            }
            break;
        case 7:
            if( !(my_list.list_size == 0) )
            {
                view_list(&my_list , 's');
                std_info_all(&my_list);
                printf("=>no of elements = %i\n", my_list.list_size);
            }
            else
            {
                printf("=>List is empty\n");
            }
            break;
        case 8:
            exit(1);
        }
    }

    return 0;
}
