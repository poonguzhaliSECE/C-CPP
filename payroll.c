#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMPLOYEES 100
#define MAX_DAYS 31

struct Employee {
    int id;
    char name[50];
    float salary;
    int attendance[MAX_DAYS];
    int leavesTaken;
    float performanceRating;
    char goals[100];
};

void addEmployee(struct Employee employees[], int *employeeCount) {
    printf("Enter employee details:\n");

    printf("Employee ID: ");
    scanf("%d", &employees[*employeeCount].id);

    printf("Employee Name: ");
    scanf("%s", employees[*employeeCount].name);

    printf("Employee Salary: ");
    scanf("%f", &employees[*employeeCount].salary);

    for (int i = 0; i < MAX_DAYS; i++) {
        employees[*employeeCount].attendance[i] = 0;
    }

    employees[*employeeCount].leavesTaken = 0;
    employees[*employeeCount].performanceRating = 0.0;

    printf("Employee added successfully!\n");
    (*employeeCount)++;
}

void markAttendance(struct Employee employees[], int employeeCount) {
    int employeeId, day;

    printf("Enter employee ID for attendance: ");
    scanf("%d", &employeeId);

    for (int i = 0; i < employeeCount; i++) {
        if (employees[i].id == employeeId) {
            printf("Enter day (1-%d) for attendance: ", MAX_DAYS);
            scanf("%d", &day);

            if (day >= 1 && day <= MAX_DAYS) {
                employees[i].attendance[day - 1] = 1;
                printf("Attendance marked for employee ID %d on day %d.\n", employeeId, day);
            } else {
                printf("Invalid day. Please enter a day between 1 and %d.\n", MAX_DAYS);
            }

            return;
        }
    }

    printf("Employee with ID %d not found.\n", employeeId);
}

void takeLeave(struct Employee employees[], int employeeCount) {
    int employeeId, days;

    printf("Enter employee ID for leave: ");
    scanf("%d", &employeeId);

    for (int i = 0; i < employeeCount; i++) {
        if (employees[i].id == employeeId) {
            printf("Enter number of days for leave: ");
            scanf("%d", &days);

            if (days > 0) {
                employees[i].leavesTaken += days;
                printf("Leave granted for employee ID %d for %d days.\n", employeeId, days);
            } else {
                printf("Invalid number of days. Please enter a positive value.\n");
            }

            return;
        }
    }

    printf("Employee with ID %d not found.\n", employeeId);
}

void evaluatePerformance(struct Employee employees[], int employeeCount) {
    int employeeId;
    float rating;
    char goals[100];

    printf("Enter employee ID for performance evaluation: ");
    scanf("%d", &employeeId);

    for (int i = 0; i < employeeCount; i++) {
        if (employees[i].id == employeeId) {
            printf("Enter performance rating (0.0-5.0): ");
            scanf("%f", &rating);

            if (rating >= 0.0 && rating <= 5.0) {
                employees[i].performanceRating = rating;

                printf("Enter goals for the employee:\n");
                scanf("%s", employees[i].goals);

                printf("Performance evaluated and goals set for employee ID %d.\n", employeeId);
            } else {
                printf("Invalid rating. Please enter a rating between 0.0 and 5.0.\n");
            }

            return;
        }
    }

    printf("Employee with ID %d not found.\n", employeeId);
}

void displayEmployeeDetails(struct Employee employees[], int employeeCount) {
    int employeeId;

    printf("Enter employee ID for details: ");
    scanf("%d", &employeeId);

    for (int i = 0; i < employeeCount; i++) {
        if (employees[i].id == employeeId) {
            printf("\nEmployee Details for %s (ID %d):\n", employees[i].name, employeeId);
            printf("Salary: %.2f\n", employees[i].salary);
            printf("Leaves Taken: %d\n", employees[i].leavesTaken);
            printf("Performance Rating: %.2f\n", employees[i].performanceRating);
            printf("Goals: %s\n", employees[i].goals);
            printf("Attendance:\n");

            for (int day = 0; day < MAX_DAYS; day++) {
                printf("Day %d: %s\n", day + 1, employees[i].attendance[day] ? "Present" : "Absent");
            }

            return;
        }
    }

    printf("Employee with ID %d not found.\n", employeeId);
}

int main() {
    struct Employee employees[MAX_EMPLOYEES];
    int employeeCount = 0;
    int choice;

    do {
        printf("\nEmployee Management System\n");
        printf("1. Add Employee\n");
        printf("2. Mark Attendance\n");
        printf("3. Take Leave\n");
        printf("4. Evaluate Performance and Set Goals\n");
        printf("5. Display Employee Details\n");
        printf("6. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEmployee(employees, &employeeCount);
                break;

            case 2:
                markAttendance(employees, employeeCount);
                break;

            case 3:
                takeLeave(employees, employeeCount);
                break;

            case 4:
                evaluatePerformance(employees, employeeCount);
                break;

            case 5:
                displayEmployeeDetails(employees, employeeCount);
                break;

            case 6:
                printf("Exiting Employee Management System. Goodbye!\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while (1);

    return 0;
}
