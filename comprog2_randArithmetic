#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int addition(int items),subtraction(int items), multiplication(int items), division(int items), menu();

int main()
{
    int n =3,cor;
    srand(time(NULL));
    switch(menu()){
        case 1:
                system("cls");
                cor = addition(n);
                printf("You got %d correct answer out of %d\n", cor, n);
                break;
        case 2:
                system("cls");
                cor = subtraction(n);
                printf("You got %d correct answer out of %d\n", cor, n);
                break;
        case 3:
                system("cls");
                cor = multiplication(n);
                printf("You got %d correct answer out of %d\n", cor, n);
                break;
        case 4:
                system("cls");
                cor = division(n);
                printf("You got %d correct answer out of %d\n", cor, n);
                break;
        case 5: printf("Exited successfully");exit(0);
        default: printf("Choose only from 1 to 5!\n");
    }



    return 0;
}
int addition(int items){
    int i,a,b,ans, c = 0;
    for (i = 1; i<= items; i++){
        a= rand()%10+1;
        b= rand()%10+1;
        printf("\n%d. What is %d + %d?\n", i, a, b);
        scanf("%d", &ans);
        if (ans == a + b){
            printf("Correct!\n");
            c++;
        }else {printf("Shunga! the correct answer is %d\n", a+b);}
    }
    return c;
}
int subtraction(int items){
    int i,a,b,ans, c = 0;
    for (i = 1; i<= items; i++){
        a= rand()%5+6;
        b= rand()%5+1;
        printf("\n%d. What is %d - %d?\n", i, a, b);
        scanf("%d", &ans);
        if (ans == a - b){
            printf("Correct!\n");
            c++;
        }else {printf("Shunga! the correct answer is %d\n", a-b);}
    }
    return c;
}
int multiplication(int items){
    int i,a,b,ans, c = 0;
    for (i = 1; i<= items; i++){
        a= rand()%10+1;
        b= rand()%10+1;
        printf("\n%d. What is %d x %d?\n", i, a, b);
        scanf("%d", &ans);
        if (ans == a * b){
            printf("Correct!\n");
            c++;
        }else {printf("Shunga! the correct answer is %d\n", a*b);}
    }
    return c;
}
int division(int items){
    int i,a,b,ans, c = 0;
    for (i = 1; i<= items; i++){
        do{
        a= rand()%10+1;
        b= rand()%10+1;
        }while(a%b !=0);
        printf("\n%d. What is %d / %d?\n", i, a, b);
        scanf("%d", &ans);
        if (ans == a / b){
            printf("Correct!\n");
            c++;
        }else {printf("Shunga! the correct answer is %d\n", a/b);}
    }
    return c;
}
int menu(){
    int op;
    printf("Menu\n1.)Addition\n2.)Subtraction\n3.)Multiplication\n4.)Division\n5.)Exit\nEnter (1-5) only\n");
    scanf("%d", &op);
    return op;
}


