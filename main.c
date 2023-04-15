#include <stdio.h>

void createBillHeader(char name[50], char date[30])
{
    printf("\n\n");
    printf("\t  KTP Restaurant");
    printf("\n\t ----------------");
    printf("\nDate: %s", date);
    printf("\nInvoice To: %s", name);
    printf("\n");
    printf("--------------------------------------\n");
    printf("Items\t\t");
    printf("Qty\t\t");
    printf("Total\t\t");
    printf("\n--------------------------------------");
    printf("\n\n");
}

void createBillBody(char item[30], int qty, float price)
{
    printf("%s\t\t", item);
    printf("%d\t\t", qty);
    printf("%.2f\t\t", price * qty);
    printf("\n");
}

int main()
{
    return 0;
}