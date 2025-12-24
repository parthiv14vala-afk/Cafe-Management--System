#include <stdio.h>

int token = 0, tokens[50], payment_counter = 0;

int main_page();
int menu_order();
void Bill_show(int id[], int q[], int counter);
void Bill_Payment();

int main()
{
    printf("###################################\n");
    printf("###################################\n");
    printf("##  Welcome to PV's Cafe ^_^ ##\n");
    printf("###################################\n");
    printf("###################################\n");
    
    
    int choice;
    do {
        choice = main_page();
        switch (choice) {
            case 1:
                menu_order(); 
                break;
            case 2:
                Bill_Payment();
                break;
            case 3:
                printf("\nDipali's Cafe\n\n");
                printf("This session order received : %d\n", token);
                printf("This session bill paid      : %d\n\n", payment_counter);
                if (payment_counter < token)
                {
                    printf("No. of payment remaining: %d\n", token - payment_counter);
                }
                printf("\nThank You..!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    } while (choice != 3); 

    return 0;
}

int main_page()
{
    printf("\nQuality food...Serves good.(^_^)\n");
    printf("1.New Order\n");
    printf("2.Bill Payment\n");
    printf("3.Exit \n");

    printf("\nEnter Your Choice:");
    int choice;
    
    if(scanf("%d", &choice) != 1) {
        while(getchar() != '\n'); 
        return 0; 
    }
    return choice;
}

void Bill_show(int id[], int q[], int counter)
{
    int n;
    int i, sum = 0;
    
    int costs[8] = {120, 40, 70, 90, 65, 230, 25, 25}; 
    char items[8][16] = {"Beef Burger", "Hot Dog", "Donuts", "French Fries", "Ice Cream", "Sweets", "Coca-Cola", "Mirinda"};
    
    printf("\nYour Bill:\n      Item(s)     Quantity   Cost\n");

    for (i = 0; i < counter; i++)
    {
        
        printf("%d. %s %d piece(s) %d\n", i + 1, items[id[i] - 1], q[i], q[i] * costs[id[i] - 1]);
        sum = sum + (costs[id[i] - 1] * q[i]);
    }

    printf("\nTotal = %d\n", sum);
    if (token < 50) {
    token++;
    tokens[token] = sum;
    } else {
    printf("Token limit reached!\n");
    }

    printf("\tYour token number is %d. \nUse this token while paying the bill.\n", token);
}

int menu_order()
{
    int id[50], q[50], counter = 0; 
    int decision;
    int ordering = 1;

    while(ordering)
    {
        printf("\nFOOD MENU\n\n");
        printf("************************************\n");
        printf("1.Burger .............................120/-\t \n");
        printf("2.Hot Dog ............................40/-\n");
        printf("3.Donuts .............................70/-\t \n");
        printf("4.French Fries .......................90/-\t \n");
        printf("5.Ice Cream ..........................65/-\t  \n");
        printf("6.Sweets .............................230/-\t \n");
        printf("7.Coca-Cola ..........................25/-\n");
        printf("8.Mirinda   ..........................25/-\n");
        printf("************************************\n");

        printf("Order your dish: (Enter 0 to finish order)\n");
        for (;;)
        {
            printf("Enter Food ID: ");
            scanf("%d", &id[counter]);
            if (id[counter] == 0)
            {
                break; 
            }
            printf("Enter Quantity: ");
            scanf("%d", &q[counter]);
            counter++;
        }

        printf("\nThanks for your order.\n We are getting ready the dishes.Until then, have some selfies with friends.");
        printf("Enjoy!!!!\n\nEnter 1 to check your bill\n Enter 2 to continue ordering (back to menu)\n Enter 3 to go to main menu\n\n Enter your choice: ");
        scanf("%d", &decision);

        if (decision == 1)
        {
            if (counter > 0) {
                Bill_show(id, q, counter);
            } else {
                printf("Cannot show bill for an empty order.\n");
            }
            ordering = 0; 
        }
        else if (decision == 2)
        {
            continue;
        }
        else if (decision == 3)
        {
            ordering = 0; 
        }
    }
    return 0; 
}

void Bill_Payment()
{
    int k, n, cash;
    int paying = 1; 

    while(paying)
    {
        payment_counter++;
        printf("\nEnter your token number: ");
        scanf("%d", &k);
        
        if (k > token || k <= 0 || tokens[k] == 0) {
            printf("Invalid or already paid token number.\n");
            continue;
        }

        printf("\nYour Total Bill is = %d", tokens[k]);
        do {
            printf("\nPay your bill: ");
            scanf("%d", &cash);
            if (cash < tokens[k])
            {
                printf("You have to pay %d more.\n", tokens[k] - cash);
            }
        } while (cash < tokens[k]);


        printf("\nThanks for your payment. Have a great day!!!!\n");
        tokens[k] = 0; 
        
        printf("\n<Enter 1 to pay another bill.>\n<Enter 2 to go back main menu>\nEnter your choice: \t");
        scanf("%d", &n);
        
        if (n == 2)
        {
            paying = 0; 
        }
    }
}
