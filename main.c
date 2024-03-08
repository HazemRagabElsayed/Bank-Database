#include <stdio.h>
#include "Bank_Database.h"

#define SIZE 5
customer_t customer[SIZE];
int counter;

int main()
{
    char choice_check;
    int id_check;
    int id_to;
    double cashtrans;

    while (1)
    {
        printf("Please Select one of the following options :\n"
               "1-create a new customer <press 1 to select this option>"
               "\n2-edit customer <press 2 to select this option>\n"
               "3-delete customer <press 3 to select this option>\n"
               "4-print customer data<press 4 to select this option>\n"
               "5-cash transfer from customer to another <press 5 to select this option>\n"
               "6-exit <press 6 to select this option>");

       printf(" \nplease enter your choice:");
       fflush(stdin);
       scanf("%c",&choice_check);
       printf("%c\n",choice_check);
       if (choice_check == '1')
       {
           create_customer();
       }
       else if (choice_check == '2')
       {
           printf("\nplease enter the id of the customer who you need to change its data :");
           scanf("%i",&id_check);
           edit_customer(id_check);
       }
       else if (choice_check == '3')
       {
           printf("\nplease enter the id of the customer who you need to delete its data :");
           scanf("%i",&id_check);
           delete_customer(id_check);
       }
       else if (choice_check == '4')
       {
           printf("\nplease enter the id of the customer who you need to print its data :");
           scanf("%i",&id_check);
           print_customer_data(id_check);
       }
       else if (choice_check == '5')
       {
           printf("\nplease enter the id of the customer who the money will be transferred from his cash :");
           scanf("%i",&id_check);
           printf("\nplease enter the id of the customer who the money will be transferred to his cash :");
           scanf("%i",&id_to);
           printf("\nplease enter the money which will be transferred :");
           scanf("%lf",&cashtrans);
           cash_transfer(id_check,id_to,cashtrans);
       }
       else if (choice_check == '6')
       {
           break;
       }
    }
return 0;
}

