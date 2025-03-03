#include <stdio.h>
#include <string.h>

struct BankAccount {
    char account_holder[32];  
    double balance;
    char transaction_memo[64]; 
};

void process_transaction(struct BankAccount *acct) {
    char memo[128]; 
    printf("Enter transaction memo: ");
    gets(memo); 
    
    strcpy(acct->transaction_memo, memo); 
}

void update_credentials(struct BankAccount *acct) {
    char new_name[64];
    printf("Enter new account name: ");
    scanf("%s", new_name); 
    
    strcpy(acct->account_holder, new_name);
}

int main() {
    struct BankAccount acct = {"John Doe", 5000.0, "Initial deposit"};
    
    update_credentials(&acct);
    process_transaction(&acct);
    
    printf("\nAccount Summary:\nName: %s\nBalance: $%.2f\nLast Transaction: %s\n",
           acct.account_holder, acct.balance, acct.transaction_memo);
    return 0;
}
