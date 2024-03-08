#ifndef BANK_DATABASE_H_INCLUDED
#define BANK_DATABASE_H_INCLUDED

typedef struct
{
    char name[50];
    double cash;
    char type[7];
    int id;
}customer_t;

void create_customer(void);
void edit_customer(int id);
void delete_customer(int id);
void print_customer_data(int id);
void cash_transfer(int id_from,int id_to,double cashtrans);

#endif // BANK_DATABASE_H_INCLUDED
