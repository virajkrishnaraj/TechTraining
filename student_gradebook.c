#include <stdio.h>

int main() {
    struct Grade {
        char name[50];
        int score;
    };
    struct Grade gradebook[] = {
        {"Assignment 1", 80},
        {"Assignment 2", 90},
        {"Exam 1", 85}
    };

    int total_score = 0;
    int count = sizeof(gradebook) / sizeof(gradebook[0]);
    for (int i = 0; i < count; i++) {
        total_score += gradebook[i].score;
    }
    float average_grade = (float)total_score / count;

    printf("Gradebook Details:\n");
    for (int i = 0; i < count; i++) {
        printf("%s: %d\n", gradebook[i].name, gradebook[i].score);
    }
    printf("\nTotal Score: %d\n", total_score);
    printf("Average Grade: %.2f\n", average_grade);

    return 0;
}
