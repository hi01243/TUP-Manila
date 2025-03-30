#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define MAX 50
#define items 5
int adSc[items], subSc[items], mulSc[items], divSc[items], last;
char name[MAX][31],password[MAX][31],user[31] = "",pass[31];
float average;
int add(char u[]);
int subtract(char u[]);
int multi(char u[]);
int divide(char u[]);
float compAve(int asc,int ssc,int msc,int dvc);
int menu();
int gameMenu();
void init();
int isFull();
int isEmpty();
int fPass(char u[],char p[]);
int find(char n[]);
int login();
int signin(char u[],char p[]);
void sort(char n[]);
int lead();
void save();
void retrieve();
void reloc(char n[],char p[], int aSc, int sSc, int mSc, int dSc);

int main (){
    int n;
    init();
    retrieve();
    while(1){
        switch(menu()){
        case 1:
            system("cls");
            if(login()==-1){getchar();break;}
            lead();
            while(1){
                system("cls");
                int choice = gameMenu();
                if(choice == 6){save(); break;}
                switch(choice){
                    case 1:
                        system("cls"); lead(); break;
                    case 2:
                        system("cls"); printf("Addition Game\n");
                        srand(time(NULL));
                        n = add(user);
                        printf("You got %d out of %d\n", n,items);
                        system("pause"); continue;
                    case 3:
                        system("cls"); printf("Subtraction Game\n");
                        srand(time(NULL));
                        n = subtract(user);
                        printf("You got %d out of %d\n", n,items);
                        system("pause"); continue;
                    case 4:
                        system("cls"); printf("Multiplication Game\n");
                        srand(time(NULL));
                        n = multi(user);
                        printf("You got %d out of %d\n", n,items);
                        system("pause"); continue;
                    case 5:
                        system("cls"); printf("Division Game\n");
                        srand(time(NULL));
                        n = divide(user);
                        printf("You got %d out of %d\n", n,items);
                        system("pause"); continue;
                    default: printf("Enter 1-6 ONLY!\n");getchar();getchar();continue;
                    }
            }break;
        case 2:
            system("cls");
            printf("Player Sign-in\n");
            printf("--------------------------\n");
            printf("Enter username: "); scanf(" %[^\n]", user);
            if(find(user) !=-1){
                printf("Player already exists\n");
                system("pause"); break;
            }
            printf("Enter password: ");scanf(" %[^\n]", pass);
            signin(user,pass); break;
        case 3:
            printf("Recorded Successfully.\nThank you for playing.\n");
            save(); exit(0);
        default: printf("Enter 1-3 ONLY!\n"); getchar();break;
        }
    }return 0;
}


void init(){
    last = -1;
}
int isFull(){
    return(last == MAX-1);
}
int isEmpty(){
    return (last == -1);
}
int find(char n[]){
    for (int i = 0; i<= last; i++){
        if(strcasecmp(n,name[i])==0){
            return i;
        }
    }return -1;
}
int fPass(char u[],char p[]){
    int i,nIndex = find(u);
    for (int i = 0; i<= last; i++){
        if(strcasecmp(p,password[nIndex])==0){
            return i;
        }
    }return -1;
}
int signin(char u[],char p[]){
    if(isFull()){
        printf("Number of players is full\n");
        system("pause");
        return 0;
    }
    if(find(u)!=-1){
        printf("Player already exists!\n");
        return 0;
    }
    last++;
    strcpy(name[last],u);
    strcpy(password[last],p);
    adSc[last] = 0;
    subSc[last] = 0;
    mulSc[last] = 0;
    divSc[last] = 0;
    return 0;
}
int login(){
    if (last == -1){
        printf("Sign-up first to play.\n");
        return -1;
    }
    printf("Player Log-in\n");
    printf("--------------------------\n");
    printf("Enter username: "); scanf(" %[^\n]", user);
    if(find(user) == -1){
            printf("Player does not exist yet. Sign up first.\n");
            return -1;
        }
    printf("Enter password: ");scanf(" %[^\n]", pass);
    if(fPass(user,pass) == -1){
        printf("Wrong password\n");
        return -1;
    }
    printf("Welcome, %s!\n",user);
    return 0;
}
int add(char u[]){
    int x, y, c = 0, ans;
    for(int i=1;i<=items;i++){
    x = rand() %10+1;
    y = rand() %10+1;
    printf("%d.) %d + %d = ",i,x,y);
    scanf("%d",&ans);
    if(ans== x+y){
        printf("Correct\n");
        c++;}else printf("Wrong, the correct answer is %d\n", x+y);
    }
    adSc[find(u)] = c;
    sort(user);return c;
}
int subtract(char u[]){
    int x, y, c = 0, ans,tem;
    for(int i=1;i<=items;i++){
    x = rand()%10+1;
    y = rand()%10+1;
    while(x<y){x = rand()%10+1;y = rand()%10+1;}
    printf("%d.) %d - %d = ",i,x,y);
    scanf("%d",&ans);
    if(ans== x-y){
        printf("Correct\n");
        c++;}else printf("Wrong, the correct answer is %d\n", x-y);
    }
    subSc[find(u)] = c;
    sort(user);return c;
}
int multi(char u[]){
    int x, y, c = 0, ans;
    for(int i=1;i<=items;i++){
    x = rand() %10+1;
    y = rand() %10+1;
    printf("%d.) %d x %d = ",i,x,y);
    scanf("%d",&ans);
    if(ans== x*y){
        printf("Correct\n");
        c++;}else printf("Wrong, the correct answer is %d\n", x*y);
    }
    mulSc[find(u)] = c;
    sort(user);return c;
}
int divide(char u[]){
    int x, y, c = 0, ans,tem;
    for(int i=1;i<=items;i++){
    x = rand()%100+1;
    y = rand()%100+1;
    while(x%y != 0){
    x = rand()%100+1;
    y = rand()%100+1;
    }
    printf("%d.) %d / %d = ",i,x,y);
    scanf("%d",&ans);
    if(ans== x/y){
        printf("Correct\n");
        c++;}else printf("Wrong, the correct answer is %d\n", x/y);
    }
    divSc[find(u)] = c;
    sort(user); return c;
}
int menu(){
    int op;
    printf("--------------------------\n");
    printf("Basic Arithmetic Game\n");
    printf("--------------------------\n");
    printf("1. Log-in\n2. Sign-in\n3. Save and Exit\n");
    printf("Enter (1-3): "); scanf("%d",&op);
    return op;
}
int gameMenu(){
    int gop;
    printf("--------------------------\n");
    printf("Basic Arithmetic Game\n");
    printf("--------------------------\n");
    printf("1. Leaderboards\n");
    printf("2. Addition\n3. Subtraction\n4. Multiplication\n5. Division\n6. Return to Main Menu\n");
    printf("Enter (1-6): "); scanf("%d",&gop);
    return gop;
}
int lead(){
    system("cls");
    printf("---------------------\n");
    printf("Leaderboards\n");
    printf("---------------------\n");
    printf("\tName\tScore +\tScore -\tScore x\t Score /\n");
    printf("--------------------------------------------------\n");
    for (int i = 0;i<=last;i++){
        printf("%d.) %s\t%d\t%d\t%d\t%d\n", i+1, name[i],adSc[i],subSc[i],mulSc[i],divSc[i]);
    }
    system("pause");
    return 1;
}
float compAve(int asc,int ssc,int msc,int dvc){
    return (asc + ssc + msc + dvc)/4.0;
}
int locatePos(char u[]){
    int i,nIndex = find(u);
    for(i=0; i<=last;i++){
        if(compAve(adSc[nIndex],subSc[nIndex],mulSc[nIndex],divSc[nIndex]) > compAve(adSc[i],subSc[i],mulSc[i],divSc[i]))
           return i;

    }return last + 1;
}
void sort(char u[]){
    char tname[31],tpass[31];
    int tAdd,tSub,tMul,tDiv, i,j;
    for (i = 0; i <=last; i++){
        for (j = i + 1; j <last; j++){
            if(compAve(adSc[i],subSc[i],mulSc[i],divSc[i])<compAve(adSc[j],subSc[j],mulSc[j],divSc[j])){
                strcpy(tname, name[i]);
                strcpy(name[i],name[j]);
                strcpy(name[j], tname);

                strcpy(tpass, password[i]);
                strcpy(password[i],password[j]);
                strcpy(password[j],tpass);

                tAdd = adSc[i];
                adSc[i] = adSc[j];
                adSc[j] = tAdd;

                tSub = subSc[i];
                subSc[i] = subSc[j];
                subSc[j] = tSub;

                tMul = mulSc[i];
                mulSc[i] = mulSc[j];
                mulSc[j] = tMul;

                tDiv = divSc[i];
                divSc[i] = divSc[j];
                divSc[j] = tDiv;
            }
        }
    }

}
void save(){
    FILE *fp = fopen("leaderboards.txt","w+");
    if (fp == NULL){
        printf("File not found.\n");
        system("pause");
    }else{
        for (int i = 0; i <=last; i++){
            fprintf(fp,"%s\n%s\n%d %d %d %d\n", name[i],password[i],adSc[i],subSc[i],mulSc[i],divSc[i]);
        }
    fclose(fp);
    }
}

void retrieve(){
    FILE *fp = fopen("leaderboards.txt","r+");
    char n[31],p[31];
    int aSc,sSc,mSc,dSc;
    if(fp == NULL){
        printf("No player yet\n");
        return;
    }
    while(!feof(fp)){
        fscanf(fp, " %[^\n]\n%[^\n]\n%d %d %d %d\n",n, p,&aSc,&sSc,&mSc,&dSc);
        reloc(n,p,aSc,sSc,mSc,dSc);
    }
    fclose(fp);
}
void reloc(char n[], char p[],int aSc, int sSc, int mSc, int dSc){
    last++;
    strcpy(name[last], n);
    strcpy(password[last], p);
    adSc[last] = aSc;
    subSc[last] = sSc;
    mulSc[last] = mSc;
    divSc[last] = dSc;
}

