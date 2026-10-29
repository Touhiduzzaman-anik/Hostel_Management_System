
#include <stdio.h>
#include <string.h>

#define MAX 100

struct Student {
    int id;
    char name[50];
    int room;
};

struct Student students[MAX];
int count = 0;

void addStudent() {
    if (count >= MAX) {
        printf("\nHostel student list is full!\n");
        return;
    }

    printf("\nStudent ID: ");
    scanf("%d", &students[count].id);

    for (int i = 0; i < count; i++) {
        if (students[i].id == students[count].id) {
            printf("This ID already exists!\n");
            return;
        }
    }

    printf("Student Name: ");
    scanf(" %49[^\n]", students[count].name);

    printf(" Room Number: ");
    scanf("%d", &students[count].room);

    count++;

    printf("\nStudent added successfully!\n");
}

void viewStudents() {
    if (count == 0) {
        printf("\nNo student records found.\n");
        return;
    }

    printf("\nHostel Student List\n");

    for (int i = 0; i < count; i++) {
        printf("\nStudent ID: %d\n", students[i].id);
        printf("Name: %s\n", students[i].name);
        printf("Room Number: %d\n", students[i].room);
    }
}

void searchStudent() {
    int searchID;
    int found = 0;

    printf("\nEnter Student ID to search: ");
    scanf("%d", &searchID);

    for (int i = 0; i < count; i++) {
        if (students[i].id == searchID) {
            printf("\nStudent Found!\n");
            printf("ID: %d\n", students[i].id);
            printf("Name: %s\n", students[i].name);
            printf("Room: %d\n", students[i].room);

            found = 1;
            break;
        }
    }

    if (found == 0) {
        printf("\nStudent not found.\n");
    }
}

int main() {
    int choice;

    do {
        printf("\n==============================\n");
        printf("   HOSTEL MANAGEMENT SYSTEM\n");
        printf("==============================\n");
        printf("1. Add New Student\n");
        printf("2. View All Students\n");
        printf("3. Student Details\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent();
                break;

            case 2:
                viewStudents();
                break;

            case 3:
                searchStudent();
                break;

            case 0:
                printf("\nProgram closed.\n");
                break;

            default:
                printf("\nInvalid choice! Try again.\n");
        }

    } while (choice != 0);

    return 0;
}
