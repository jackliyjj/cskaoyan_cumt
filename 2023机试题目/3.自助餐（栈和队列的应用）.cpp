#include <stdio.h>

int countStudents(int* students, int studentsSize, int* sandwiches, int sandwichesSize) {
    int likeCircular = 0;
    int likeSquare = 0;

    // Count the number of students who like circular and square sandwiches
    for (int i = 0; i < studentsSize; i++) {
        if (students[i] == 0) {
            likeCircular++;
        } else {
            likeSquare++;
        }
    }

    // Iterate through the sandwiches and simulate the process
    for (int i = 0; i < sandwichesSize; i++) {
        if (sandwiches[i] == 0) {
            // If the sandwich is circular
            if (likeCircular > 0) {
                likeCircular--;
            } else {
                // No more students like circular sandwiches
                return likeSquare;
            }
        } else {
            // If the sandwich is square
            if (likeSquare > 0) {
                likeSquare--;
            } else {
                // No more students like square sandwiches
                return likeCircular;
            }
        }
    }

    // All students got their sandwiches
    return 0;
}

int main() {
    int students[] = {1, 1, 0, 0};
    int sandwiches[] = {0, 1, 0, 1};
    int result = countStudents(students, 4, sandwiches, 4);

    printf("Number of students who couldn't eat lunch: %d\n", result);

    return 0;
}

