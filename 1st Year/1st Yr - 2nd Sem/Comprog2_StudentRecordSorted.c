#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 20
char name[MAX][31];
int q1[MAX],q2[MAX],q3[MAX];
float ave;
int last;

void sort();
void upd(char n[]);
void edisp(char n[]);
void init();
void add(char n[],int qz1,int qz2,int qz3);
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
                add(n, qz1,qz2,qz3);
                break;
            case 2:
                system("cls");
                printf("Enter name: ");
                scanf(" %[^\n]", n);
                upd(n);
                break;
            case 3:
                system("cls");
                printf("Input name: ");
                scanf(" %[^\n]", n);
                del(n);
                break;
            case 4:
                system("cls");
                display();
                break;
            case 5:
                system("cls");
                printf("Enter name: "); scanf(" %[^\n]", n);
                edisp(n);
                break;
            case 6:
                save();
                exit(0);
            default:
                printf("Invalid option\n");
                getchar();
        }
    }
    return 0;
}

void init(){
    last = -1;
}

int isfull(){
    return (last ==MAX-1);

}
int isempty(){
    return (last==-1);
}
void add(char n[],int qz1, int qz2, int qz3){
    if(isfull()){
        printf("Student record is full\n");
        system("pause");
    }else if(isDup(n)){
        printf("Student already recorded\n");
        getchar();
        getchar();
    }
    else {
        last ++;
        strcpy(name[last], n);
        q1[last] = qz1;
        q2[last] = qz2;
        q3[last] = qz3;
        sort();
    }
}
int isDup(char n[]){
    for (int i = 0;i <= last; i++){
        if (strcasecmp(n, name[i])== 0){
            return 1;}
    }
    return 0;
}

int find(char n[]){
    for(int i =0; i<=last; i++){
        if (strcasecmp(n, name[i]) == 0){
          return i;
          }
    }
    return -1;
}
void del(char n[]){
    int p = find(n);
    if(isempty()){
        printf("Record is empty\n");
        system("pause");
    }else {
        if (p<0){
            printf("Name not found\n");
            system("pause");}
        else{
        for (int i = p; i < last; i++){
            strcpy(name[i],name[i+1]);
            q1[i] = q1[i+1];
            q2[i] = q2[i+1];
            q3[i] = q3[i+1];
        }
        last--;
        printf("Record deleted successfully\n");
        system("pause");
        }
    }
}

float computeAve(int qz1,int qz2,int qz3){
    return (qz1 + qz2 +qz3)/ 3.0;
}

void display(){
    system("cls");
    float ave;
    if(isempty()){
        printf("No record yet\n");
    }else{
        printf("---------------------------------------------------------\n");
        printf("| NAME\t\tQUIZ 1\tQUIZ 2\tQUIZ 3\tAVERAGE\t REMARKS\n");
        printf("---------------------------------------------------------\n");
        for (int i = 0; i <= last; i++){
            ave = computeAve(q1[i],q2[i],q3[i]);
            printf("|%d.) %s\t %d\t %d\t %d\t %4.2f\t %s\n", i+1, name[i], q1[i], q2[i],q3[i], ave, ave >= 75? "PASSED":"FAILED");
        }
        printf("---------------------------------------------------------\n");
    }
    system("pause");
}
int menu(){
    system("cls");
    int c;
    printf("STUDENT RECORD\n1. Add a record\n2. Update a record\n3. Delete a record\n4. Display all records\n5. Display a record\n6. Exit\nInput (1-6): ");
    scanf("%d", &c);
    return c;
    }


void save(){
    FILE *fp;
    fp = fopen("bscs-1a.txt","w+");
    if (fp==NULL){
        printf("File not found.\n");
        system("pause");
    }else {
           for (int i = 0; i<=last; i++){
            ave = computeAve(q1[i],q2[i],q3[i]);
            fprintf(fp, "%s\t%d\t%d\t%d\n", name[i], q1[i], q2[i],q3[i]);
           }
    fclose(fp);
    printf("Recorded successfully");
    }
}

void retrieve() {
    FILE *fp;
    char n[31];
    int qz1, qz2, qz3;
    fp = fopen("bscs-1a.txt", "r");
    if (fp == NULL) {
        printf("No records found.\n");
        return;
    }
    while (fscanf(fp, "%30[^\t]\t%d\t%d\t%d\n", n, &qz1, &qz2, &qz3) == 4) {
        add(n, qz1, qz2, qz3);
    }
    fclose(fp);
}

void edisp(char n[]){
    int p = find(n);
    float ave;
    if (p<0){
        printf("Not found\n");
    }else{
        printf("---------------------------------------------------------\n");
        printf("| NAME\t\tQUIZ 1\tQUIZ 2\tQUIZ 3\tAVERAGE\t REMARKS\n");
        printf("---------------------------------------------------------\n");
        ave = computeAve(q1[p],q2[p],q3[p]);
        printf("|%s\t %d\t %d\t %d\t %4.2f\t %s\n", name[p], q1[p], q2[p],q3[p], ave, ave >= 75? "PASSED":"FAILED");
        printf("---------------------------------------------------------\n");
    }
    system("pause");
}

void upd(char n[]){
    int p = find(n), q, nrec;
    system("cls");
    float ave;
    if (p<0){
        printf("Not found\n");
    }else{
        printf("---------------------------------------------------------\n");
        printf("| NAME\t\tQUIZ 1\tQUIZ 2\tQUIZ 3\tAVERAGE\t REMARKS\n");
        printf("---------------------------------------------------------\n");
        ave = computeAve(q1[p],q2[p],q3[p]);
        printf("|%s\t %d\t %d\t %d\t %4.2f\t %s\n", name[p], q1[p], q2[p],q3[p], ave, ave >= 75? "PASSED":"FAILED");
        printf("---------------------------------------------------------\n");
        do {
            printf("Enter the quiz to change (1-3): ");
            scanf("%d", &q);
            if (q < 1 || q > 3) {
                printf("\nInvalid input. Try again.\n");
            }
        } while (q < 1 || q > 3);
        printf("Input new score: ");
        scanf("%d", &nrec);
        if (q == 1){
                q1[p] = nrec;
                edisp(n);
        }else if (q == 2){
                q2[p] = nrec;
                edisp(n);
        }else {
            q3[p] = nrec;
            edisp(n);
            }
    }
    getchar();
    getchar();
}

void sort(){
    char tname[31];
    int tq1,tq2,tq3;
    for (int i = 0;i < last; i++){
        for (int j = i +1;j < last +1; j++){
            if(strcasecmp(name[i], name[j]) > 0){
                strcpy(tname, name[i]);
                strcpy(name[i], name[j]);
                strcpy(name[j], tname);
                tq1 = q1[i];
                q1[i] = q1[j];
                q1[j] = tq1;
                tq2 = q2[i];
                q2[i] = q2[j];
                q2[j] = tq2;
                tq3 = q3[i];
                q3[i] = q3[j];
                q3[j] = tq3;
            }
        }
    }
}




