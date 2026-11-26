#include <stdio.h>

int isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int getFirstDayOfYear(int year) {
    int day = (year - 1) * 365 + (year - 1) / 4 - (year - 1) / 100 + (year - 1) / 400 + 1;
    return day % 7;
}

int main() {
    int year, month, day, daysInMonth, startingDay;

    char *months[] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };

    int monthDays[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    printf("Enter the year: ");
    if (scanf("%d", &year) != 1 || year < 1) {
        printf("Invalid year entered.\n");
        return 1;
    }

    if (isLeapYear(year)) {
        monthDays[1] = 29;
    }

    startingDay = getFirstDayOfYear(year);

    printf("\n==================== CALENDAR - %d ====================\n", year);

    for (month = 0; month < 12; month++) {
        daysInMonth = monthDays[month];

        printf("\n  ------------ %s ------------\n", months[month]);
        printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

        for (int space = 0; space < startingDay; space++) {
            printf("     ");
        }

        for (day = 1; day <= daysInMonth; day++) {
            printf("%5d", day);

            if (++startingDay > 6) {
                startingDay = 0;
                printf("\n");
            }
        }
        printf("\n");
    }

    return 0;
}
