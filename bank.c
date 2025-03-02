#include <stdio.h>
#include <string.h>

struct Bank{
    char accountNum[1000];
    float balance;
    int PIN;
    char owner[100];
} crAcct;
void createAccount(struct Bank crAcct[],int *index){
    for(int i = 0;i<*index;i++){
        printf("enter the account Number:");
        scanf("%s",crAcct[i].accountNum);
        printf("enter the balance:");
        scanf("%f",&crAcct[i].balance);
        printf("enter the PIN:");
        scanf("%d",&crAcct[i].PIN);
    }

}
void depo(struct Bank crAcct[],int index,int PIN,char AcctNum[1000],float deposit){
    int found = 0;
    for(int i = 0;i<index;i++){
        if(strcmp(AcctNum,crAcct[i].accountNum)==0){
            found = 1;
            printf("enter the PIN:");
            scanf("%d",&PIN);
            if(PIN==crAcct[i].PIN){
                printf("enter the deposit amount:");
                scanf("%f",&deposit);
                crAcct[i].balance = crAcct[i].balance+deposit;
                printf("Transcation successful.\nThe current balance in your account = %f",crAcct[i].balance);
            }
            else{
                printf("PIN does not match\n");
            }
            break;
        }
    }
    if(!found){
        printf("Account is not found\n");
    }
}
void witDra(struct Bank crAcct[],int index,int PIN,char AcctNum[1000],float withdrawl){
    int found = 0;
    for(int i = 0;i<index;i++){
        if(strcmp(AcctNum,crAcct[i].accountNum)==0){
            found = 1;
            printf("enter the PIN:");
            scanf("%d",&PIN);
            if(PIN==crAcct[i].PIN){
               printf("enter the amount to be withdrawn:");
               scanf("%f",&withdrawl);
               if(withdrawl<=crAcct[i].balance){
                crAcct[i].balance = crAcct[i].balance-withdrawl;
                printf("Transaction successful\n.The current balance in your accout is %f",crAcct[i].balance);
               }
               else{
                printf("insufficient balance\n");
               }
          
            }
            else{
                printf("PIN does not match\n");
            }
            break;
        }

       
    }
    if(!found){
        printf("Account is not found\n");
    }
}
void checkBal(struct Bank crAcct[],int index,int PIN,char accountNumber[100]){
    int found = 0;
    for(int i = 0;i<index;i++){
        if(strcmp(accountNumber,crAcct[i].accountNum)==0){
              found = 1;
              printf("enter the PIN:");
              scanf("%d",&PIN);
              if(PIN==crAcct[i].PIN){
                printf("the current balance = %f",crAcct[i].balance);
              }
              else{
                printf("PIN not found\n");
              }
        }
        break;
    }
    if(!found){
        printf("Account not found\n");
    }
}
int main(){
    int count,choice;
    int PIN;
    float deposit,withdrawl;
    char op;
    char accountNumber[100];
    struct Bank account[100];
    printf("if you want to be a member of this business you need to register yourself by creating an account.\nAre you a member of this bank.\n(Y/N)??\n");
scanf("%s",&op);
if(op=='y'){
    do{
        printf("which option would you like to execute.\n1.Deposit an amount\n2.Withdraw an amount\n3.Check your balance\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            printf("enter the account Number:");
            scanf("%s",accountNumber);
            depo(account,count,PIN,accountNumber,deposit);
            break;

            case 2:
            printf("enter the account Number:");
            scanf("%s",accountNumber);
            witDra(account,count,PIN,accountNumber,withdrawl);
            break;

            case 3:
            printf("enter the account Number:");
            scanf("%s",accountNumber);
            checkBal(account,count,PIN,accountNumber);
            break;

            case 4:printf("bye\n");
            break;

        }
    }
    while(choice!=4);
  
}
else if(op=='n'){
    printf("enter the count\n");
    scanf("%d",&count);
    createAccount(account,&count);
    do{ 
    printf("which option would you like to execute.\n1.Deposit an amount\n2.Withdraw an amount\n3.Check your balance\n4.exit\n");
    scanf("%d",&choice);
           switch(choice){
            case 1:
            printf("enter the account Number:");
            scanf("%s",accountNumber);
            depo(account,count,PIN,accountNumber,deposit);
            break;

            case 2:
            printf("enter the account Number:");
            scanf("%s",accountNumber);
            witDra(account,count,PIN,accountNumber,withdrawl);
            break;

            case 3:
            printf("enter the account Number:");
            scanf("%s",accountNumber);
            checkBal(account,count,PIN,accountNumber);
            break;

            case 4:printf("bye\n");
            break;
    }

    
}
while(choice!=4);
}
else{
printf("invalid option\n");
}
return 0;
}