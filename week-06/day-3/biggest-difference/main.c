#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// You will write a program that keeps track of exam results.
// First, your program should ask the user how many classes took the exam. Let's say this number is N.
// Then you need to ask how many students took the exam in the first class. Let's say this number is M.
// You need to ask for the name of the class, the the exam results in percentage M times and store them.
// The number of students might be different for each class.
// You need to repeat this N times.
// Make sure you have a separate function that reads the data and returns it.

// Once you have the data write functions for the following questions:
// Which class has the biggest difference between the worst and best exam and how much is the difference?
// Which class has the best exam?
// What is the average of all the exams?
typedef struct
{
    char *name;
    int students;
    float biggest_difference_between_exams;
} classes_t;

int ask_for_number_of_classes();

void how_many_students_take_the_exam(classes_t *cls, int num_of_classes);

void name_of_classes(classes_t *cls, int num_of_classes);

void store_exam_result(classes_t *cls, int num_of_classes, float **exam_res);

char *which_class_has_the_biggest_difference(classes_t *cls, int num_of_classes, float **exam_res);

void which_class_has_the_best_exam(classes_t *cls, int num_of_classes, float **exam_res);

float average_of_all_exams(classes_t *cls, int num_of_classes, float **exam_res);

int main()
{
    // create classes
    classes_t *classes;
    // asks the user how many classes we have (N)
    int number_of_classes = ask_for_number_of_classes();
    // allocate memory for that many classes
    classes = (classes_t *) malloc(number_of_classes * sizeof(classes_t));
    // asks the name of the classes
    name_of_classes(classes, number_of_classes);
    // asks the user how many students took the exam (M)
    how_many_students_take_the_exam(classes, number_of_classes);
    // allocating memory for exam results
    float **exam_results = (float **) malloc(number_of_classes * sizeof(float*));
    for (int i = 0; i < number_of_classes; i++) {
        exam_results[i] = (float *) malloc(classes[i].students * sizeof(float));
    }
    // storing exam results
    store_exam_result(classes, number_of_classes, exam_results);
    // getting biggest difference, printing the class name and the difference
    printf("The %s class has the biggest difference: ", which_class_has_the_biggest_difference(classes, number_of_classes, exam_results));
    for (int j = 0; j < number_of_classes; j++) {
        if (which_class_has_the_biggest_difference(classes, number_of_classes, exam_results) == classes[j].name) {
            printf("%.2f\n", classes[j].biggest_difference_between_exams);
        }
    }
    // class with best exam
    which_class_has_the_best_exam(classes, number_of_classes, exam_results);
    // the average of all the exams
    printf("The average of all the exams: %.2f", average_of_all_exams(classes, number_of_classes, exam_results));
    // deallocate memory
    free(classes);
    free(exam_results);
    return 0;
}

int ask_for_number_of_classes()
{
    int num;
    printf("How many classes did take the exam?\n");
    scanf("%d", &num);
    return num;
}

void how_many_students_take_the_exam(classes_t *cls, int num_of_classes)
{
    for (int i = 0; i < num_of_classes; i++) {
        printf("How many students did take the exam in the %s class?\n", cls[i].name);
        scanf("%d", &cls[i].students);
    }
}

void name_of_classes(classes_t *cls, int num_of_classes)
{
    char temp[50];
    int memory_all;
    for (int i = 0; i < num_of_classes; i++) {
        printf("Please give me the name of the %d class!\n", i);
        memory_all = scanf("%s", temp);
        cls[i].name = (char *) malloc(memory_all * sizeof(char));
        strcpy(cls[i].name, temp);
    }

}

void store_exam_result(classes_t *cls, int num_of_classes, float **exam_res)
{
    for (int i = 0; i < num_of_classes; i++) {
        printf("Please give me the exam results for the %s class!\n", cls[i].name);
        for (int j = 0; j < cls[i].students; j++) {
            scanf("%f", &exam_res[i][j]);
        }
    }
}

char *which_class_has_the_biggest_difference(classes_t *cls, int num_of_classes, float **exam_res)
{
    char *name_of_class = NULL;
    float *difference;
    difference = (float *) malloc(num_of_classes * sizeof(float));
    for (int i = 0; i < num_of_classes; i++) {
        float max_exam = 0;
        float min_exam = exam_res[i][0];
        for (int j = 0; j < cls[i].students; j++) {
            if (max_exam < exam_res[i][j]) {
                max_exam = exam_res[i][j];
            }
        }
        for (int k = 0; k < cls[i].students; k++) {
            if(min_exam > exam_res[i][k]) {
                min_exam = exam_res[i][k];
            }
        }
        float biggest_difference = (max_exam - min_exam);
        difference[i] = biggest_difference;
        cls[i].biggest_difference_between_exams = biggest_difference;

    }
    float max_difference = 0;
    for (int l = 0; l < num_of_classes; l++) {
        if (max_difference < difference[l]) {
            max_difference = difference[l];
            name_of_class = cls[l].name;
        }
    }
    free(difference);
    return name_of_class;
}

void which_class_has_the_best_exam(classes_t *cls, int num_of_classes, float **exam_res)
{
    float *best_exam;
    best_exam = (float *) malloc(num_of_classes * sizeof(float));
    for (int i = 0; i < num_of_classes; i++) {
        float max_exam = 0;
        for (int j = 0; j < cls[i].students; j++) {
            if (max_exam < exam_res[i][j]) {
                max_exam = exam_res[i][j];
            }
        }
        best_exam[i] = max_exam;
    }
    float best = 0;
    for (int j = 0; j < num_of_classes; j++) {
        if (best < best_exam[j]) {
            best = best_exam[j];
        }
    }
    for (int k = 0; k < num_of_classes; k++) {
        if (best == best_exam[k]) {
            printf("The %s class has the best exam: %.2f\n", cls[k].name, best);
        }
    }
    free(best_exam);
}

float average_of_all_exams(classes_t *cls, int num_of_classes, float **exam_res)
{
    float sum = 0;
    int count = 0;
    for (int i = 0; i < num_of_classes; i++) {
        for (int j = 0; j < cls[i].students; j++) {
            sum += exam_res[i][j];
            count++;
        }
    }
    return sum / count;
}