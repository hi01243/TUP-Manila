#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 20
char name[MAX][31], remarks[MAX][10];
int q1[MAX],q2[MAX],q3[MAX];
float average[MAX];
int last;

void init();
void add(char n[],int qz1,int qz2,int qz3,float ave, char r[]);
int isfull();
int isempty();
int find(char n[]);
void del(char n[]);
void display();
int menu();
void save();
void retrieve();
float computeAve(int q1,int q2,int q3);

int main(){
    int qz1,qz2,qz3;
    float ave;
    char n[31], r[10];
    init();
    retrieve();
    while(1){
        switch(menu()){
            case 1:
                system("cls");
                printf("Input student's name: ");
                scanf(" %[^\n]", n);
                printf("Enter score on quiz 1: ");
                scanf("%d", &qz1);
                printf("Enter score on quiz 2: ");
                scanf("%d", &qz2);
                printf("Enter score on quiz 3: ");
                scanf("%d", &qz3);
                ave = computeAve(qz1,qz2,qz3);
                if(ave >= 75){
                    strcpy(r, "PASSED");
                }else {strcpy(r, "FAILED");}
                add(n, qz1,qz2,qz3,ave, r);
                break;
            case 2:
                system("cls");
                printf("Input name: ");
                scanf(" %[^\n]", n);
                del(n);
                break;
            case 3:
                display();
                system("cls");
                break;
            case 4:
                save();
                exit (0);
            default:
                printf("Invalid option\n");
                system("pause");
        }
    }
    return 0;
}

void init(){
    last = -1;
}

int isfull(){
    //if(last == MAX-1)
        return (last ==MAX-1);

}
int isempty(){
    //if (last == -1)
        return (last==-1);
}
void add(char n[],int qz1, int qz2, int qz3, float ave, char r[]){
    if(isfull()){
        printf("Student record is full\n");
        system("pause");
    }else if(find(n) != -1){
        printf("Student already recorded\n");
        system("pause");
    }
    else {
        last ++;
        strcpy(name[last], n);
        q1[last] = qz1;
        q2[last] = qz2;
        q3[last] = qz3;
        average[last] = ave;
        strcpy(remarks[last], r);
        printf("Record added successfully\n");
        //A[last] = x;

    }
}
int find(char n[]){
    for(int i =0; i<=last; i++){
        if (strcasecmp(n,name[i]) == 0)
            return i;
    }
    return -1;
}
void del(char n[]){
    int p = find(n);
    if(isempty()){
        printf("Record is empty\n");
        system("pause");
    }else if(p < 0){
            printf("Not found\n");
            system("pause");
    }else{
        for (int i = p; i < last; i++){
            strcpy(name[i],name[i+1]);
            q1[i] = q1[i+1];
            q2[i] = q2[i+1];
            q3[i] = q3[i+1];
            average[i] = average[i+1];
            strcpy(remarks[i], remarks[i+1]);
        }
        last--;
        printf("Record deleted successfully\n");
        system("pause");
    }
}


float computeAve(int qz1,int qz2,int qz3){
    return (qz1 + qz2 +qz3)/ 3.0;
}

void display(){
    system("cls");
    if(isempty()){
        printf("No record yet\n");
    }else{
        printf("---------------------------------------------------------\n");
        printf("| NAME\t\tQUIZ 1\tQUIZ 2\tQUIZ 3\tAVERAGE\t REMARKS\n");
        printf("---------------------------------------------------------\n");
        for (int i = 0; i <= last; i++){
            printf("|%d.) %s\t %d\t %d\t %d\t %4.2f\t %s\n", i+1, name[i], q1[i], q2[i],q3[i], average[i], remarks[i]);
        }
        printf("---------------------------------------------------------\n");
    }
    system("pause");
}
int menu(){
    int c;
    printf("1. Add a record\n");
    printf("2, Delete a record\n");
    printf("3. Display all\n");
    printf("4. Exit\n");
    printf("Select (1-4): ");
    scanf("%d", &c);
    if (c < 1 || c > 4){
        while (getchar() != '\n');
        printf("Invalid option");
        system("pause");
        return -1;
    }
    if (c < 1 || c > 4) {
        printf("Invalid option. Try again.\n");
        return -1;
    return c;
    }
}

void save(){
    FILE *fp;
    fp = fopen("bscs-1a.txt","w+");
    if (fp==NULL){
        printf("File Error.\n");
        system("pause");
    }else {
           for (int i = 0; i<=last; i++){
            fprintf(fp, "%s\t%d\t%d\t%d\t%4.2f\t%s\n", name[i], q1[i], q2[i],q3[i], average[i], remarks[i]);
           }
    fclose(fp);
    printf("Recorded successfully");
    }
}

void retrieve() {
    FILE *fp;
    char n[31], r[10];
    int q1,q2,q3;
    float ave;
    fp = fopen("bscs-1a.txt", "r+");
    if (fp == NULL) {
        printf("No Records.\n");
        system("pause");
    }while (fscanf(fp, "%[^\t]\t%d\t%d\t%d\t%f\t%[^\n]\n", n, &q1, &q2, &q3, &ave, r) == 6) {
        add(n, q1, q2, q3, ave, r);}
    fclose(fp);
    }


4. Comprog2_FunctionsgetRec

#include <stdio.h>
#include <stdlib.h>
#define MAX 3

int q1[MAX],q2[MAX],q3[MAX];
char name[MAX][31];

void getRec();
void display();
float computeAve(int q1,int q2, int q3);

int main(){
    getRec(name, q1,q2,q3);
    system("cls");
    display(name,q1,q2,q3);
    return 0;
}

void getRec(char n[][31],int q1[],int q2[], int q3[]){
    for (int i = 0; i < MAX; i++){
        printf("Enter the student's name: ");
        scanf(" %[^\n]", n[i]);
        printf("Quiz 1 score: ");
        scanf("%d", &q1[i]);
        printf("Quiz 2 score: ");
        scanf("%d", &q2[i]);
        printf("Quiz 3 score: ");
        scanf("%d", &q3[i]);
        getchar();
    }
}

void display(char n[][31],int q1[],int q2[], int q3[]){
    printf("---------------------------------------------------------\n");
    printf("|Name\t\tQuiz 1\tQuiz 2\tQuiz 3\tAverage\tRemarks |\n");
    printf("---------------------------------------------------------\n");
    for (int i = 0; i < MAX; i++){
        float ave = computeAve(q1[i],q2[i],q3[i]);
        printf("|%d.%s\t%d\t%d\t%d\t%4.3f\t%s |\n", i+1, n[i], q1[i],q2[i],q3[i],ave,ave >=75? "PASSED!":"FAILED!");
    }
    printf("---------------------------------------------------------\n");
}

float computeAve(int q1,int q2, int q3){
    return (q1 + q2 + q3)/3.0;
}
