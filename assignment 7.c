#include <stdio.h>

struct Student {
    int rollNo;
    char name[50];
    float marks[3];
    float total;
    float percentage;
    char result[10];
};

int main() {
    int n, i, j;

    printf("Enter the number of students: ");
    scanf("%d", &n);

    struct Student s[n];

    for (i = 0; i < n; i++) {
        printf("\n--- Enter details for Student %d ---\n", i + 1);
        
        printf("Roll Number: ");
        scanf("%d", &s[i].rollNo);
        
        printf("Name: ");
        scanf(" %[^\n]", s[i].name); // Reads full name including spaces

        s[i].total = 0;
        int passedAll = 1;

        for (j = 0; j < 3; j++) {
            printf("Marks in Subject %d (out of 100): ", j + 1);
            scanf("%f", &s[i].marks[j]);
            s[i].total += s[i].marks[j];

            if (s[i].marks[j] < 35) {
                passedAll = 0;
            }
        }

        s[i].percentage = s[i].total / 3.0;

        if (passedAll == 1) {
            sprintf(s[i].result, "PASS");
        } else {
            sprintf(s[i].result, "FAIL");
        }
    }

  
    printf("\n====================================================================\n");
    printf("%-10s %-20s %-10s %-12s %-10s\n", "Roll No", "Name", "Total", "Percentage", "Result");
    printf("====================================================================\n");

    for (i = 0; i < n; i++) {
        printf("%-10d %-20s %-10.2f %-11.2f%% %-10s\n", 
               s[i].rollNo, 
               s[i].name, 
               s[i].total, 
               s[i].percentage, 
               s[i].result);
    }

    return 0;
}
