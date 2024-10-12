#include <stdio.h>
#include <stdlib.h>

// Function to calculate the first weekday of the year
int get_1st_weekday(int year) {
    int day;
    // Calculate the day of the week for January 1st of the given year
    // The formula accounts for leap years and uses modulo 7 to get the weekday
    day = (((year - 1) * 365) + ((year - 1) / 4) - ((year - 1) / 100) + ((year) / 400) + 1) % 7;
    return day;
}

// Function to print the calendar for the specified year
void print_calendar(int year, int monthDay[], char *Months[], int StartingDay) {
    int day, weekDay;

    // Loop through each month
    for (int month = 0; month < 12; month++) {
        int daysInMonth = monthDay[month]; // Get the number of days in the current month
        printf("\n------------------------------%s------------------------------\n", Months[month]);
        printf("\n  Sunday  Monday  Tuesday  Wednesday  Thursday  Friday  Saturday\n\n");

        // Print leading spaces for the first week
        for (weekDay = 0; weekDay < StartingDay; weekDay++) {
            printf("        "); // 8 spaces for alignment
        }

        // Print the days of the month
        for (day = 1; day <= daysInMonth; day++) {
            printf("%8d", day); // Print day with formatting for alignment
            if (++weekDay > 6) { // Move to the next line after Saturday
                printf("\n");
                weekDay = 0; // Reset weekDay to start from Sunday
            }
        }
        StartingDay = weekDay; // Update StartingDay for the next month
    }
}

int main() {
    system("Color 1D"); // Change console color (Windows specific)
    int year, StartingDay;
    printf("Enter the year: ");
    scanf("%d", &year); // Get the year input from the user

    // Array of month names
    char *Months[] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };

    // Array containing the number of days in each month
    int monthDay[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // Check for leap year
    // If the year is a leap year, set February to have 29 days
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
        monthDay[1] = 29; // February has 29 days in a leap year
    }

    StartingDay = get_1st_weekday(year); // Get the starting day of the year
    print_calendar(year, monthDay, Months, StartingDay); // Print the calendar

    return 0; // End of the program
}
