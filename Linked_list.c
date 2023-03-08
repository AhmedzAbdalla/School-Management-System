#include "Linked_list.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

static float my_rand = 1.1; // for generating random IDs for students
char subject [6][10]= {"Maths" , "Arabic", "English" , "Science", "Biology", "History"};

 static void swap(student * ptr1 , student * ptr2 )
 {
        ptr1->next_node->next_node = ptr2->next_node;
        ptr2->next_node = ptr1->next_node;
        ptr1->next_node = ptr2;
 }
 /*===========================================*/
std_return create_list(linked_list *const ls)
{
    std_return ret;
    if(NULL == ls)
    {
            ret= list_not_exist;
    }
    else
    {
        ls->list_head=NULL;
        ls->list_size=0;
        printf("list created successfully\n");
        ret = list_created_successfully;
    }
    return ret;
}
/*================================================*/

std_return insert_node ( linked_list *const ls)
{
    std_return ret;
    if(NULL != ls)
    {
        student * new_node= NULL;
        student * last_node= NULL; //for traversing
        new_node = (student*)malloc(sizeof(student));
        if(NULL !=new_node )
        {
            if(NULL == ls->list_head)
            {
                student * mask = (student*)malloc(sizeof(student));
                ls->list_head= mask;
                new_node->next_node=NULL;
                mask->next_node=new_node;
                mask->std_ID=170;
                ls->list_size=1;
            }
            else
            {

                new_node->next_node=NULL;
                last_node=ls->list_head;
                while (last_node->next_node != NULL)
                {
                    last_node= last_node->next_node;
                }
                last_node->next_node= new_node;
                (ls->list_size)++;
            }
        printf("Please enter the name of Student\n");
        gets((new_node->std_name));
        ret = node_created;

        /*Generating Random ID of each student*/
        while( 1 )
        {
            new_node->std_ID = (unsigned int ) (1000 * log(my_rand));
            my_rand +=0.3;
            if( new_node->std_ID !=170)
            {
                break;
            }
        }


        printf("Please enter the address of Student\n");
        gets(new_node->std_address);
        fflush(stdin);
        printf("Please enter the birth day of Student\n");

        //validate user data
        while(1)
        {
            scanf("%d", &(new_node->std_birth_day));
            fflush(stdin);
            if( ((new_node->std_birth_day)>=1) && (new_node->std_birth_day)<=30 )
            {
                break;
            }
            printf("please enter valid birth day!!!\n");
        }

        printf("Please enter the birth month of Student\n");
        while(1)
        {
            scanf("%d", &(new_node->std_birth_month));
            fflush(stdin);
            if(((new_node->std_birth_month)>=1) && ((new_node->std_birth_month)<=12) )
            {
                break;
            }
            printf("please enter valid birth month!!!\n");
        }

        printf("Please enter the birth year of Student\n");
        while(1)
        {
            scanf("%d", &(new_node->std_birth_year));
            fflush(stdin);
            if(((new_node->std_birth_year)>=2015) && ((new_node->std_birth_year)<=2017) )
            {
                break;
            }
            printf("please enter valid birth year!!!\n");
        }

        printf("Please enter the mobile number of Student\n");
        scanf("%d", &(new_node->std_number));
        fflush(stdin);

        }

        else
        {
            printf("Cannot create new node\n");
            ret = node_not_created;
        }
    }
    else
    {
        printf("list not existed!!!\n");
        ret = list_not_exist;
    }

    return ret;
}

/*=========================================================*/

std_return view_list (const  linked_list * ls , const char sort_type)
{
    printf("no of nodes = %i\n", ls->list_size);
    std_return ret;
    student * traverse= NULL;
    student * temp1= NULL;
    student * temp2= NULL;
    unsigned int i =0;
    unsigned int j =0;
    if(NULL != ls)
    {

        switch (sort_type)
        {
            // alphabetically ascending sorting
            //bubble sort
        case 'a':
             for( i=0 ; i<= ls->list_size ; i++)
            {
                traverse=ls->list_head;
                for( j =0 ; j< (ls->list_size) - i - 1 ; j++)
                {
                    temp1= traverse;
                    temp2= temp1->next_node->next_node;
                    if(temp2 ==NULL )
                    {
                        break;
                    }
                        if( strcmp( temp1->next_node->std_name , (temp2->std_name ) )>0 )
                        {
                            swap( temp1, temp2 );
                        }
                        traverse=traverse->next_node;
                }
            }
            break;
            // sorting according to score
        case 's':
             for( i=0 ; i<= ls->list_size ; i++)
            {
                traverse=ls->list_head;
                for( j =0 ; j< (ls->list_size) - i - 1 ; j++)
                {
                    temp1= traverse;
                    temp2= temp1->next_node->next_node;
                    if(temp2 ==NULL )
                    {
                        break;
                    }
                        if( temp1->next_node->std_score[0] < temp2->std_score[0]  )
                        {
                            swap( temp1, temp2 );
                        }
                        traverse=traverse->next_node;
                }
            }
            break;
        default:
            break;
        }

        ret = ok;
    }
    else
    {
        ret = list_not_exist;
    }
    return ret;
}

/*==================================================*/

std_return delete_student ( linked_list *const ls , const unsigned int std_ID)
{
    std_return ret;
    student * traverse= NULL;
    student * temp= NULL;
    if ( (NULL != ls && (std_ID != 170)) )
    {
        traverse = ls->list_head;
        temp=traverse;
        while( (traverse->std_ID != std_ID) && (traverse->next_node!=NULL ))
        {
            temp=traverse;
            traverse=traverse->next_node;
        }
        if( (traverse->std_ID == std_ID) )
        {
            temp->next_node =  traverse->next_node;
            printf("name of id %i is:\"%s\"\n", std_ID , traverse->std_name);
            free(traverse);
            ret = std_deleted;
            (ls->list_size)--;
        }
        else
        {
            ret = std_not_found;
        }

    }
    else
    {
        ret = list_not_exist;
    }
    return ret;
}


/*====================================================*/
std_return std_score(const linked_list *const ls , const unsigned int std_ID)
{
    std_return ret;
    char i=0;
    student * traverse= NULL;
    if ( NULL != ls && (170 != std_ID))
    {
        traverse = ls->list_head;
        while( (traverse->std_ID != std_ID) && (traverse->next_node!=NULL ))
        {
            traverse=traverse->next_node;
        }
        if( (traverse->std_ID == std_ID))
        {
            printf("name of id %i is:\"%s\"\n", std_ID,traverse->std_name);
            for(i=0 ; i<6;i++)
            {
                while( 1 )
                {
                    printf("Enter the degree of %s: ", subject[i]);
                    scanf("%f", &(traverse->std_score[i]));
                    fflush(stdin);
                    if( (traverse->std_score[i]) <=100 )
                    {
                        break;
                    }
                    printf("=>please enter a valid degree\n");
                }

                (traverse->std_cum_score)+= (traverse->std_score[i]);
                ret = ok;
            }
            traverse->std_cum_score = (traverse->std_cum_score)/ 6;

        }
        else
        {
            ret = std_not_found;
        }

    }
    else
    {
        ret = list_not_exist;
    }
    return ret;
}

/*============================================================*/
std_return std_edit(const linked_list *const ls , const unsigned int std_ID)
{
    std_return ret;
    unsigned int i=0;
    student * traverse= NULL;
    unsigned int node_counter=0;
    if ( NULL != ls && (170 != std_ID) )
    {
        traverse = ls->list_head;
        while( (traverse->std_ID != std_ID) && (traverse->next_node!=NULL ))
        {
            traverse=traverse->next_node;
            node_counter++;
        }
        if( (traverse->std_ID == std_ID))
        {
            printf("name of id %i is:\"%s\"\n", std_ID,traverse->std_name);
            printf("=> 1) Edit the student name\n");
            printf("=> 2) Edit the student address\n");
            printf("=> 3) Edit the student mobile number\n");
            printf("=> 4) Edit the student birth date\n");
            printf("=> 5) Cancel\n");
            scanf("%d",&i);
            fflush(stdin);
            switch(i)
            {
            case 1:
                printf("enter the new name\n");
                gets((traverse->std_name));
                break;
            case 2 :
                printf("Enter the new address\n");
                gets(traverse->std_address);
                break;
            case 3 :
                printf("Enter the new mobile number\n");
                scanf("%d", &(traverse->std_number));
                break;
            case 4:
                printf("Please enter the birth day of Student\n");
                while(1)
                {
                    scanf("%d", &(traverse->std_birth_day));
                    fflush(stdin);
                    if(((traverse->std_birth_day)>=1) && ((traverse->std_birth_day)<=30) )
                    {
                        break;
                    }
                    printf("please enter valid birth day!!!\n");
                }

                printf("Please enter the birth month of Student\n");
                while(1)
                {
                    scanf("%d", &(traverse->std_birth_month));
                    fflush(stdin);
                    if(((traverse->std_birth_month)>=1) && ((traverse->std_birth_month)<=12) )
                    {
                        break;
                    }
                    printf("please enter valid birth month!!!\n");
                }

                printf("Please enter the birth year of Student\n");
                while(1)
                {
                    scanf("%d", &(traverse->std_birth_year));
                    fflush(stdin);
                    if(((traverse->std_birth_year)>=2015) && ((traverse->std_birth_year)<=2017) )
                    {
                        break;
                    }
                    printf("please enter valid birth year!!!\n");
                }
                break;
            case 5:
                break;
            default:
                printf("INVALID OPTION\n");
                break;
            }

        }
        else
        {
            ret = std_not_found;
        }

    }
    else
    {
        ret = list_not_exist;
    }
    return ret;
}
/*==============================================================*/
std_return std_info_all(const linked_list * ls)
{
    std_return ret;
    student * traverse= NULL;
    if(NULL != ls)
    {
        traverse=ls->list_head;
        printf("Name \t\t ID\t\t Address \t\t BirthDay\t\t Grade\t\t Mobile NO.\n");
        printf("=====================================================================================================================\n");

       traverse = traverse->next_node;
        if(1 )
        {
           while(NULL !=traverse)
            {
                printf("%s\t",traverse->std_name);
                printf("%d\t\t",traverse->std_ID);
                printf("%s\t\t",traverse->std_address);
                printf("%d/%d/%d\t\t",traverse->std_birth_day,traverse->std_birth_month,traverse->std_birth_year);
                printf("%0.2f\t\t",traverse->std_cum_score);
                printf("%d",traverse->std_number);
                printf("\n-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
                printf("\n");

                traverse = traverse->next_node;

            }
            ret = ok;
        }
        else
        {
            ret = list_empty;
        }


    }
    else
    {
        ret = list_not_exist;
    }
    return ret;
}

/*=====================================================*/
void sorted_names(const linked_list * ls)
{
    printf("=>no of elements = %i\n", ls->list_size);
}

/*=========================================================*/

