#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100

// Define a structure to store student details
typedef struct {
    int roll_no;
    char name[50];
    int age;
    float marks;
} Student;

// Declare an array to store student records
Student students[MAX_STUDENTS];
int student_count = 0;

// Function prototypes
void addStudent();
void displayStudents();
void searchStudent();
void menu();

int main() {
    int choice;

    do {
        menu();
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                displayStudents();
                break;
            case 3:
                searchStudent();
                break;
            case 4:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

// Function to display the menu
void menu() {
    printf("\n--- Student Management System ---\n");
    printf("1. Add Student\n");
    printf("2. Display All Students\n");
    printf("3. Search for a Student\n");
    printf("4. Exit\n");
}

// Function to add a student record
void addStudent() {
    if (student_count >= MAX_STUDENTS) {
        printf("Error: Cannot add more students. Maximum limit reached!\n");
        return;
    }

    Student new_student;
    printf("Enter Roll Number: ");
    scanf("%d", &new_student.roll_no);
    getchar();  // To consume newline after entering roll number

    printf("Enter Name: ");
    fgets(new_student.name, sizeof(new_student.name), stdin);
    new_student.name[strcspn(new_student.name, "\n")] = '\0';  // Remove trailing newline

    printf("Enter Age: ");
    scanf("%d", &new_student.age);

    printf("Enter Marks: ");
    scanf("%f", &new_student.marks);

    students[student_count++] = new_student;
    printf("Student added successfully!\n");
}

// Function to display all student records
void displayStudents() {
    if (student_count == 0) {
        printf("No students to display.\n");
        return;
    }

    printf("\n--- List of Students ---\n");
    for (int i = 0; i < student_count; i++) {
        printf("Roll No: %d, Name: %s, Age: %d, Marks: %.2f\n",
               students[i].roll_no, students[i].name, students[i].age, students[i].marks);
    }
}

// Function to search for a student by roll number
void searchStudent() {
    if (student_count == 0) {
        printf("No students to search.\n");
        return;
    }

    int roll_no;
    printf("Enter the Roll Number to search for: ");
    scanf("%d", &roll_no);

    for (int i = 0; i < student_count; i++) {
        if (students[i].roll_no == roll_no) {
            printf("Student Found:\n");
            printf("Roll No: %d, Name: %s, Age: %d, Marks: %.2f\n",
                   students[i].roll_no, students[i].name, students[i].age, students[i].marks);
            return;
        }
    }

    printf("Student with Roll Number %d not found.\n", roll_no);
}
