#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10

char name[MAX][31];
int quiz[MAX][3];
float ave;
int last;

void init();
int isfull();
int isempty();
int find(char n[]);
void del(char n[]);
void add(char n[], int q1, int q2, int q3);
void display();
float avg(int a, int b, int c);
int menu();
void save();
void retrieve();
int isDup(char n[]);

int main() {
    char n[31];
    int q1, q2, q3;

    init();
    retrieve();

    while (1) {
        switch (menu()) {
            case 1:
                system("cls"); printf("Input Name: "); fgets(n, sizeof(n), stdin); n[strcspn(n, "\n")] = '\0'; printf("Input Quiz 1: "); scanf("%d", &q1); printf("Input Quiz 2: "); scanf("%d", &q2);
                printf("Input Quiz 3: "); scanf("%d", &q3); getchar(); add(n, q1, q2, q3); break;
            case 2:
                system("cls"); printf("Input Name: "); fgets(n, sizeof(n), stdin); n[strcspn(n, "\n")] = '\0'; del(n); break;
            case 3:
                display(); break;
            case 4: save(); exit(0);
            default:
                printf("1 to 4 only.\n"); printf("Press any key to continue...\n"); getchar();
        }
    }

    return 0;
}

void init() {
    last = -1;
}

int isfull() {
    return (last == MAX - 1);
}

int isempty() {
    return (last == -1);
}

int find(char n[]) {
    int i;
    for (i = 0; i <= last; i++) {
        if (strcmp(n, name[i]) == 0)
            return i;
    }
    return -1;
}

void del(char n[]) {
    int p, i;
    if (isempty()) {
        printf("Array is empty.\n");
        printf("Press any key to continue...\n");
        getchar();
    } else {
        p = find(n);
        if (p < 0) {
            printf("Not found.\n");
            printf("Press any key to continue...\n");
            getchar();
        } else {
            for (i = p; i < last; i++) {
                strcpy(name[i], name[i + 1]);
                quiz[i][0] = quiz[i + 1][0];
                quiz[i][1] = quiz[i + 1][1];
                quiz[i][2] = quiz[i + 1][2];
            }
            last--;
            printf("Record of %s is successfully deleted.\n", n);
            printf("Press any key to continue...\n");
            getchar();
        }
    }
}

void add(char n[], int q1, int q2, int q3) {
    if (isfull()) {
        printf("Array is full.\n");
        printf("Press any key to continue...\n");
        getchar();
    } else if (isDup(n)) {
        printf("Duplicate record found. Record not added.\n");
        printf("Press any key to continue...\n");
        getchar();
    } else {
        last++;
        strcpy(name[last], n);
        quiz[last][0] = q1;
        quiz[last][1] = q2;
        quiz[last][2] = q3;

    }
}

int isDup(char n[]) {
    int i;
    for (i = 0; i <= last; i++) {
        if (strcmp(n, name[i]) == 0)
            return 1;
    }
    return 0;
}

void display() {
    int i;
    system("cls");
    printf("==================================================================\n");
    printf("| NAME            | QUIZ 1 | QUIZ 2 | QUIZ 3 | AVERAGE | REMARKS |\n");
    printf("==================================================================\n");

    for (i = 0; i <= last; i++) {
        ave = avg(quiz[i][0],quiz[i][1],quiz[i][2]);
        printf("%d.) %s\t\t%d\t%d\t%d\t%.2f\t%s\n", i + 1, name[i], quiz[i][0], quiz[i][1], quiz[i][2], ave, ave>=75.0? "PASSED":"FAILED");

     /*   if (ave >= 75.0)
            printf("PASSED\n");
        else
            printf("FAIL\n");*/
    }
    printf("Press any key to continue...\n");
    getchar();
}

int menu() {
    int op;
    system("cls");
    printf("Menu\n");
    printf("1. Add a Record\n");
    printf("2. Delete a Record\n");
    printf("3. Display All\n");
    printf("4. Exit\n");
    printf("\nSelect(1-4): ");
    scanf("%d", &op);
    getchar();
    return op;
}

void save() {
    FILE *fp;
    int i;
    fp = fopen("StudentRecord2.txt", "w");
    if (fp == NULL) {
        printf("File Error.\n");
        printf("Press any key to continue...\n");
        getchar();
        return;
    }
    for (i = 0; i <= last; i++) {
        fprintf(fp, "%s\n%d %d %d\n", name[i], quiz[i][0], quiz[i][1], quiz[i][2]);
    }
    fclose(fp);
}

void retrieve() {
    FILE *fp;
    int q1, q2, q3;
    char n[31];
    fp = fopen("StudentRecord2.txt", "r");
    if (fp == NULL) {
        printf("File Error.\n");
        printf("Press any key to continue...\n");
        getchar();
        return;
    }
    while (!feof(fp)) {
        fscanf(fp, " %[^\n]\n%d %d %d\n", n, &q1, &q2, &q3);
        add(n, q1, q2, q3);
    }
    fclose(fp);
}
float avg(int a , int b, int c){
 return (a+b+c)/3.0;
}
