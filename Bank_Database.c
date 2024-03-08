#include <stdio.h>
#include <string.h>
#include"Bank_Database.h"

#define SIZE 5
extern customer_t customer[SIZE];
extern int counter;

void create_customer(void)
{
    if(customer[SIZE-1].id != 0)
    {
        printf("the maximum number of customers is %i so you can't add any more\n",SIZE);
    }
    for (counter=0;counter<SIZE;counter++ )
    {
        if(customer[counter].id == 0 )
        {
            printf("\nplease enter the name of the customer number %i :",counter+1);
            fflush(stdin);
            fgets(customer[counter].name,50,stdin);
            printf("\nplease enter the cash of the customer number %i :",counter+1);
            scanf("%lf",&customer[counter].cash);
            printf("\nplease enter the type of the customer number %i <debit or credit> :",counter+1);
            fflush(stdin);
            fgets(customer[counter].type,7,stdin);
            printf("\nplease enter the id of the customer number %i :",counter+1);
            scanf("%i",&customer[counter].id);
            break;
        }

    }


}

void edit_customer(int id)
{
    for(counter = 0; counter<SIZE;counter++)
    {
            if (id == customer[counter].id)
            {

                printf("please enter the new name:\n");
                fflush(stdin);
                fgets(customer[counter].name,50,stdin);
                printf("please enter the new cash:\n");
                scanf("%lf",&customer[counter].cash);
                printf("please enter the new type <debit or credit>:\n");
                fflush(stdin);
                fgets(customer[counter].type,7,stdin);
                printf("please enter the new id:\n");
                scanf("%i",&customer[counter].id);
                break;
            }
    }

}

void delete_customer(int id)
{
    int i;
    for(i = SIZE-1; i>=0;i--)
    {
            if (id == customer[i].id)
            {
                strcpy(customer[i].name,"");
                customer[i].cash = 0;
                strcpy(customer[i].type,"");
                customer[i].id = 0;
                break;
            }
    }
    while(i != SIZE -1)
    {
        strcpy(customer[i].name,customer[i+1].name);
        customer[i].cash = customer[i+1].cash;
        strcpy(customer[i].type,customer[i+1].type);
        customer[i].id = customer[i+1].id;
        i++;
    }
    customer[SIZE].id = 0;
}

void print_customer_data(int id)
{
    for(counter= 0;counter<SIZE;counter++)
    {
        if(id == customer[counter].id)
        {
            printf("\nthe name of the customer number %i is: %s",counter+1,customer[counter].name);
            printf("the cash of the customer number %i is: %lf",counter+1,customer[counter].cash);
            printf("\nthe type of the customer number %i is: %s",counter+1,customer[counter].type);
            printf("\nthe id of the customer number %i is: %i\n",counter+1,customer[counter].id);
            break;
        }
    }
}

void cash_transfer(int id_from,int id_to,double cashtrans)
{
    int i;
    for(counter=0;counter<SIZE;counter++)
    {
        for(i=0;i<SIZE;i++)
        {
            if(customer[counter].id == id_from && customer[i].id == id_to)
            {
                if(cashtrans<=customer[counter].cash)
                {
                    customer[i].cash += cashtrans;
                    customer[counter].cash-=cashtrans;
                }
                else
                {
                    printf("the money transferred is greater than your cash");
                }
                counter = SIZE;
                break;
            }
        }
    }
}
