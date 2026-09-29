#include <stdio.h>

int main()
{
    char name[50];
    char bestName[50] = "";
    float price;
    float budget;
    float lowestPrice = 0;
    int registered;
    int documentsComplete;
    int qualifiedCount = 0;
    int i;
    int numSuppliers;

    printf("Enter available budget: ");
    scanf("%f", &budget);
    printf("How many suppliers? ");
    scanf("%d", &numSuppliers);

    for (i = 1; i <= numSuppliers; i++)
    {
        printf("\n--- Supplier %d ---\n", i);
        printf("Name: ");
        scanf("%49s", name);
        printf("Tender price: ");
        scanf("%f", &price);
        printf("Registered? (1=Yes, 0=No): ");
        scanf("%d", &registered);
        printf("Documents complete? (1=Yes, 0=No): ");
        scanf("%d", &documentsComplete);

        if (registered == 1 && documentsComplete == 1 && price <= budget)
        {
            printf("%s: Qualified\n", name);

            /* track the lowest-priced qualified supplier */
            if (qualifiedCount == 0 || price < lowestPrice)
            {
                lowestPrice = price;
                snprintf(bestName, sizeof(bestName), "%s", name);
            }
            qualifiedCount++;
        }
        else
        {
            printf("%s: Disqualified\n", name);
        }
    }

    if (qualifiedCount > 0)
    {
        printf("\nPreferred Supplier: %s (%.2f)\n", bestName, lowestPrice);
    }
    else
    {
        printf("\nNo qualified suppliers.\n");
    }

    return 0;
}
