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

void createBillFooter(float total)
{
    printf("\n");
    float discount = 0.1 * total;
    float netTotal = total - discount;
    float vat = 0.075 * netTotal, grandTotal = netTotal + vat;
    printf("--------------------------------------\n");
    printf("Sub Total\t\t\t%.2f", total);
    printf("\nDiscount at 10%s\t\t\t%.2f", "%", discount);
    printf("\n\t\t\t\t-------");
    printf("\nNet Total\t\t\t%.2f", netTotal);
    printf("\nVAT at 7.5%s\t\t\t%.2f", "%", vat);
    printf("\n--------------------------------------");
    printf("\nGrand Total\t\t\t%.2f", grandTotal);
    printf("\n--------------------------------------\n");
}

int main()
{
    int opt;

    printf("\t============KTP. RESTAURANT============");
    printf("\n\n1.Generate Invoice");
    printf("\n2.Show All Invoices");
    printf("\n3.Search Invoice");
    printf("\n4.Exit");

    printf("\n\nPlease select your preferred operation:\t");
    scanf("%d", &opt);

    printf("\n\n");

    return 0;
}