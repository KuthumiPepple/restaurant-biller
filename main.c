#include <stdio.h>
#include <string.h>

struct items
{
    char item[20];
    float price;
    int qty;
};

struct orders
{
    char customer[50];
    char date[50];
    int numOfItems;
    struct items itm[50];
};

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
    int opt, n;
    struct orders ord;
    float total;
    FILE *fp;
    char saveBill = 'y';

    printf("\t============KTP. RESTAURANT============");
    printf("\n\nPlease select your preferred operation");
    printf("\n\n1.Generate Invoice");
    printf("\n2.Show All Invoices");
    printf("\n3.Search Invoice");
    printf("\n4.Exit");

    printf("\n\nYour choice:\t");
    scanf("%d", &opt);
    fgetc(stdin);

    switch (opt)
    {
    case 1:
        printf("\nPlease enter the name of the customer:\t");
        fgets(ord.customer, 50, stdin);
        ord.customer[strlen(ord.customer) - 1] = 0;
        strcpy(ord.date, __DATE__);
        printf("\nPlease enter the number of items:\t");
        scanf("%d", &n);
        ord.numOfItems = n;

        for (int i = 0; i < n; i++)
        {
            fgetc(stdin);
            printf("\n\n");
            printf("Please enter item %d:\t", i + 1);
            fgets(ord.itm[i].item, 20, stdin);
            ord.itm[i].item[strlen(ord.itm[i].item) - 1] = 0;
            printf("Please enter the quantity:\t");
            scanf("%d", &ord.itm[i].qty);
            printf("Please enter the unit price:\t");
            scanf("%f", &ord.itm[i].price);
            total += ord.itm[i].qty * ord.itm[i].price;
        }

        createBillHeader(ord.customer, ord.date);
        for (int i = 0; i < ord.numOfItems; i++)
        {
            createBillBody(ord.itm[i].item, ord.itm[i].qty, ord.itm[i].price);
        }
        createBillFooter(total);

        printf("\nDo you want to save the invoice? [y/n]: \t");
        scanf("%s", &saveBill);

        if (saveBill == 'y')
        {
            fp = fopen("invoice.dat", "a+");
            fwrite(&ord, sizeof(struct orders), 1, fp);
            if (fwrite != 0)
                printf("\nSuccessfully saved!");
            else
                printf("\nError saving");
            fclose(fp);
        }
        break;

    default:
        break;
    }

    printf("\n\n");

    return 0;
}