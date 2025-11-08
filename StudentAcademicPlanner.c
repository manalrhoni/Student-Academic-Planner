#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Structure for a course
struct Course {
    char name[50];           // Name of the course (e.g., "Mathematics")
    int chapters;            // Number of chapters covered in the course
    float grade;             // Grade obtained (percentage)
};

// Structure for a task (assignment/exam)
struct Task {
    char description[100];   // Description of the task (e.g., "Submit Math Assignment")
    char course[50];         // Course associated with the task
    int day;                 // Day of the deadline
    int month;               // Month of the deadline
    int year;                // Year of the deadline
};

// Structure for a study session
struct StudySession {
    char subject[50];        // Subject to study (e.g., "Mathematics")
    int startHour;           // Start hour of the session
    int endHour;             // End hour of the session
};

// Function prototypes
void displayMenu();                                  // Display the main menu
void addCourse(struct Course courses[], int *courseCount); // Add a new course
void removeCourse(struct Course courses[], int *courseCount); // Remove a course
void calculateAverageGrade(struct Course courses[], int courseCount); // Calculate average grade
void addTask(struct Task tasks[], int *taskCount);   // Add a new task
void viewTasks(struct Task tasks[], int taskCount);  // View all tasks
void generateStudySchedule(struct StudySession sessions[], int *sessionCount); // Generate study schedule

int main() {
    struct Course courses[10];       // Array to store up to 10 courses
    struct Task tasks[20];           // Array to store up to 20 tasks
    struct StudySession sessions[10]; // Array to store up to 10 study sessions

    int courseCount = 0, taskCount = 0, sessionCount = 0;
    int choice;

    printf("Welcome to the Student Academic Planner for Moroccan Universities!\n");

    while (1) {
        displayMenu(); // Show the menu options
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addCourse(courses, &courseCount); // Add a new course
                break;
            case 2:
                removeCourse(courses, &courseCount); // Remove a course
                break;
            case 3:
                calculateAverageGrade(courses, courseCount); // Calculate average grade
                break;
            case 4:
                addTask(tasks, &taskCount); // Add a new task
                break;
            case 5:
                viewTasks(tasks, taskCount); // View all tasks
                break;
            case 6:
                generateStudySchedule(sessions, &sessionCount); // Generate study schedule
                break;
            case 7:
                printf("Exiting the planner. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

// Display the main menu
void displayMenu() {
    // This function displays the menu options for the user
    printf("\n--- Student Academic Planner Menu ---\n");
    printf("1. Add Course\n"); // Add a new course
    printf("2. Remove Course\n"); // Remove an existing course
    printf("3. Calculate Average Grade\n"); // Calculate the average grade across all courses
    printf("4. Add Task (Assignment/Exam)\n"); // Add a new task (assignment or exam)
    printf("5. View Tasks\n"); // View all tasks with deadlines
    printf("6. Generate Study Schedule\n"); // Generate a study schedule
    printf("7. Exit\n"); // Exit the program
}

// Add a course to the list
void addCourse(struct Course courses[], int *courseCount) {
    // This function allows the user to add a new course to the list
    if (*courseCount >= 10) {
        printf("Maximum number of courses reached!\n");
        return;
    }

    struct Course newCourse;
    printf("Enter course name: "); // Input the name of the course
    scanf("%s", newCourse.name);
    printf("Enter number of chapters covered: "); // Input the number of chapters covered
    scanf("%d", &newCourse.chapters);
    printf("Enter grade (percentage): "); // Input the grade as a percentage
    scanf("%f", &newCourse.grade);

    courses[*courseCount] = newCourse;
    (*courseCount)++;
    printf("Course added successfully!\n");
}

// Remove a course from the list
void removeCourse(struct Course courses[], int *courseCount) {
    // This function allows the user to remove a course from the list
    if (*courseCount == 0) {
        printf("No courses to remove.\n");
        return;
    }

    char courseName[50];
    printf("Enter the name of the course to remove: "); // Input the name of the course to remove
    scanf("%s", courseName);

    int found = 0;
    for (int i = 0; i < *courseCount; i++) {
        if (strcmp(courses[i].name, courseName) == 0) { // Check if the course exists
            for (int j = i; j < *courseCount - 1; j++) {
                courses[j] = courses[j + 1]; // Shift the remaining courses
            }
            (*courseCount)--;
            found = 1;
            printf("Course removed successfully!\n");
            break;
        }
    }

    if (!found) {
        printf("Course not found.\n");
    }
}

// Calculate the average grade across all courses
void calculateAverageGrade(struct Course courses[], int courseCount) {
    // This function calculates the average grade across all courses
    if (courseCount == 0) {
        printf("No courses to calculate average grade.\n");
        return;
    }

    float totalGrades = 0;
    for (int i = 0; i < courseCount; i++) {
        totalGrades += courses[i].grade; // Sum up all grades
    }

    float averageGrade = totalGrades / courseCount; // Calculate the average
    printf("Your average grade is: %.2f%%\n", averageGrade);
}

// Add a task (assignment/exam) to the list
void addTask(struct Task tasks[], int *taskCount) {
    // This function allows the user to add a new task (assignment or exam)
    if (*taskCount >= 20) {
        printf("Maximum number of tasks reached!\n");
        return;
    }

    struct Task newTask;
    printf("Enter task description: "); // Input the task description
    scanf("%s", newTask.description);
    printf("Enter associated course: "); // Input the associated course
    scanf("%s", newTask.course);
    printf("Enter deadline (day month year): "); // Input the deadline
    scanf("%d %d %d", &newTask.day, &newTask.month, &newTask.year);

    tasks[*taskCount] = newTask;
    (*taskCount)++;
    printf("Task added successfully!\n");
}

// View all tasks
void viewTasks(struct Task tasks[], int taskCount) {
    // This function displays all tasks with their deadlines
    if (taskCount == 0) {
        printf("No tasks to display.\n");
        return;
    }

    printf("\n--- Task List ---\n");
    for (int i = 0; i < taskCount; i++) {
        printf("Task %d: %s (%s) - Deadline: %02d/%02d/%d\n",
               i + 1, tasks[i].description, tasks[i].course,
               tasks[i].day, tasks[i].month, tasks[i].year);
    }
}

// Generate a study schedule
void generateStudySchedule(struct StudySession sessions[], int *sessionCount) {
    // This function allows the user to generate a study schedule
    if (*sessionCount >= 10) {
        printf("Maximum number of study sessions reached!\n");
        return;
    }

    struct StudySession newSession;
    printf("Enter subject to study: "); // Input the subject to study
    scanf("%s", newSession.subject);
    printf("Enter start hour: "); // Input the start hour of the session
    scanf("%d", &newSession.startHour);
    printf("Enter end hour: "); // Input the end hour of the session
    scanf("%d", &newSession.endHour);

    sessions[*sessionCount] = newSession;
    (*sessionCount)++;
    printf("Study session added successfully!\n");
}