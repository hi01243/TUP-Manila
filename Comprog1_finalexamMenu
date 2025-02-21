#include <stdio.h>

int main() {
    int program;
    char backMenu;

    do {
        printf("-------------------------\n");
        printf("Menu:\n");
        printf("1. Array\n");
        printf("2. Nested loop\n");
        printf("3. Sequential program\n");
        printf("4. Conditional program\n");
        printf("5. Loops Program\n");
        printf("6. Credits\n");
        printf("7. Exit\n");
        printf("-------------------------\n");
        printf("Enter a program of your choice (1-7): ");
        scanf("%d", &program);
        printf("\n");

        switch (program) {
            case 1: {
                int n, i, sum = 0;
                printf("This program will calculate the sum of the numbers in an Array.\n");
                printf("\n");
                printf("Enter the number of elements: ");
                scanf("%d", &n);
                printf("\n");
                int numbers[n];
                printf("Enter the numbers:\n");
                for (i = 0; i < n; i++) {
                    scanf("%d", &numbers[i]);
                }

                for (i = 0; i < n; i++) {
                    sum += numbers[i];
                }
                printf("-------------------------\n");
                printf("The sum of the elements is: %d\n", sum);
                break;
            }

            case 2: {
                printf("This program will give you a table of multiplication.\n");
                printf("\n");
                int n;
                printf("Enter how many tables you want: ");
                scanf("%d", &n);
                printf("\n");
                for (int i = 1; i <= n; i++) {
                    printf("Multiplication table for %d:\n", i);
                    for (int j = 1; j <= 10; j++) {
                        printf("%d x %d = %d\n", i, j, i * j);
                    }
                    printf("\n");
                }
                break;
            }

            case 3: {
                printf("This program will give you the volume of a rectangular prism.\n");

                int len, wid, hei, area;
                printf("Enter the length: ");
                scanf("%d", &len);
                printf("Enter the width: ");
                scanf("%d", &wid);
                printf("Enter the height: ");
                scanf("%d", &hei);
                area = len * wid *hei;
                printf("-------------------------\n");
                printf("The volume of the rectangular prism is %d\n", area);
                break;
            }

            case 4: {
                printf("This program will tell the academic honor based on the GWA.\n");
                float gwa;
                printf("Enter the GWA (1-5): ");
                scanf("%f", &gwa);
                if (gwa >= 1.00 && gwa <= 1.20) {
                    printf("-------------------------\n");
                    printf("Summa Cum Laude\n");
                } else if (gwa >= 1.21 && gwa <= 1.45) {
                    printf("-------------------------\n");
                    printf("Magna Cum Laude\n");
                } else if (gwa >= 1.46 && gwa <= 1.75) {
                    printf("-------------------------\n");
                    printf("Cum Laude\n");
                } else {
                    printf("-------------------------\n");
                    printf("None\n");
                }
                break;
            }

            case 5: {
                printf("This program will give the factorial of a number.\n");
                int num, i = 1, factorial = 1;
                printf("Enter a number: ");
                scanf("%d", &num);
                while (i <= num) {
                    factorial *= i;
                    i++;
                }
                printf("-------------------------\n");
                printf("%d factorial is %d\n", num, factorial);
                break;
            }

            case 6: {
                printf("This program was made by:\n");
                printf("-------------------------\n");
                printf("Name: Flores, Earl John C.\n");
                printf("Student Number: TUPM-24-0366\n");
                printf("Course/Section: BSCS-1A\n");
                printf("-------------------------\n");
                printf("What was your favorite topic in C programming and why?\n");
                printf("-------------------------\n");
                printf("\nMy favorite topic in C programming was the conditional statements because when I understood its concept, I realized that professional programmers make tons of conditional statements to create a flawless program. For example in games, I realized that it took thousands of conditional statements to fit all the possibility that a user might do. This conditional statement might be easy to understand and make, but its crucial for programs to run well.");
                break;
            }

            case 7:
                printf("-------------------------\n");
                printf("Exited Successfully!");
                printf("-------------------------\n");
                return 0;
                break;

            default:
                printf("Invalid number\n");
                break;
        }

        printf("\nDo you want to go back to the menu? \nEnter Y for Yes / N for No: ");
        scanf(" %c", &backMenu);

    } while (backMenu == 'Y' || backMenu == 'y');

    return 0;
}
