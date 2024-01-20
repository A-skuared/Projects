//For a budget manager app the basic requirements are keeping a track on the expenses and balance on the amount of money kept in the account 

#include <stdio.h>

struct Transaction {
    char type;  // 'I' for Income, 'E' for Expense
    float amount;
};

void addTransaction(struct Transaction *budget, int *transactionCount, char type, float amount) {
    budget[*transactionCount].type = type;
    budget[*transactionCount].amount = amount;
    (*transactionCount)++;
}

void displayBalance(struct Transaction *budget, int transactionCount) {
    float balance = 0;
    for (int i = 0; i < transactionCount; i++) {
        if (budget[i].type == 'I') {
            balance += budget[i].amount;
        } else if (budget[i].type == 'E') {
            balance -= budget[i].amount;
        }
    }
    printf("Current Balance: $%.2f\n", balance);
}

void displayTransactions(struct Transaction *budget, int transactionCount) {
    printf("Transaction History:\n");
    for (int i = 0; i < transactionCount; i++) {
        printf("%c: $%.2f\n", budget[i].type, budget[i].amount);
    }
}

void resetBudget(struct Transaction *budget, int *transactionCount) {
    *transactionCount = 0;
    printf("Budget reset to zero.\n");
}

void analyzeSpending(struct Transaction *budget, int transactionCount) {
    float totalIncome = 0, totalExpenses = 0;
    for (int i = 0; i < transactionCount; i++) {
        if (budget[i].type == 'I') {
            totalIncome += budget[i].amount;
        } else if (budget[i].type == 'E') {
            totalExpenses += budget[i].amount;
        }
    }
    printf("Total Income: $%.2f\n", totalIncome);
    printf("Total Expenses: $%.2f\n", totalExpenses);
    printf("Net Savings: $%.2f\n", totalIncome - totalExpenses);
}

void setBudgetLimit(float *budgetLimit) {
    printf("Enter your budget limit: $");
    scanf("%f", budgetLimit);
    printf("Budget limit set to $%.2f\n", *budgetLimit);
}

void checkBudgetLimit(float balance, float budgetLimit, int incomeAmount) {
    if (balance > budgetLimit) {
        printf("Warning: You have exceeded your budget limit!\n");
    } else {
        printf("Budget amount remaining : $%.2f", budgetLimit + balance - incomeAmount);
        printf("You are within your budget limit.\n");
    }
}

void forecastBalance(struct Transaction *budget, int transactionCount, int months) {
    float futureBalance = 0;
    for (int i = 0; i < transactionCount; i++) {
        if (budget[i].type == 'I') {
            futureBalance += budget[i].amount * months;
        } else if (budget[i].type == 'E') {
            futureBalance -= budget[i].amount * months;
        }
    }
    printf("Forecasted Balance in %d months: $%.2f\n", months, futureBalance);
}

int main() {
    struct Transaction budget[100];
    int transactionCount = 0;
    char choice;
    float balance = 0;  // Declare balance variable
    float budgetLimit = 0;
    long int pno;
    char name[50];
    printf("\nWELCOME  TO  WISE WALLET \nA BUDGET MANAGER ALWAYS AT YOUR SERVICE\n");
    printf("WHAT  SHALL  I  CALL  YOU?\n");
    scanf("%s",name);
    printf("PLEASE  ENTER  YOUR  CONTACT  INFORMATION\n");
    scanf("%ld",&pno);

    do {
        printf("\n1. Add Income\n");
        printf("2. Add Expense\n");
        printf("3. Display Balance\n");
        printf("4. Display Transactions\n");
        printf("5. Reset Budget\n");
        printf("6. Analyze Spending\n");
        printf("7. Set Budget Limit\n");
        printf("8. Check Budget Limit\n");
        printf("9. Forecast Balance\n");
        printf("Enter any other KEY to EXIT\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);
        printf("\n");

        switch (choice) {
            case '1':
                printf("Enter income amount: $");
                float incomeAmount;
                scanf("%f", &incomeAmount);
                addTransaction(budget, &transactionCount, 'I', incomeAmount);
                printf("Income added successfully.\n");
                break;

            case '2':
                printf("Enter expense amount: $");
                float expenseAmount;
                scanf("%f", &expenseAmount);
                addTransaction(budget, &transactionCount, 'E', expenseAmount);
                printf("Expense added successfully.\n");
                break;

            case '3':
                displayBalance(budget, transactionCount);
                break;
            
            case '4':
                displayTransactions(budget, transactionCount);
                break;

            case '5':
                resetBudget(budget, &transactionCount);
                break;

            case '6':
                analyzeSpending(budget, transactionCount);
                break;

            case '7':
                setBudgetLimit(&budgetLimit);
                break;

            case '8':
                checkBudgetLimit(balance, budgetLimit, incomeAmount);
                break;

            case '9':
                printf("Enter the number of months for the forecast: ");
                int months;
                scanf("%d", &months);
                forecastBalance(budget, transactionCount, months);
                break;

            default:
                printf("EXITING  WISE WALLET .\n");
        }
    } while (choice != '9');

    return 0;
}


