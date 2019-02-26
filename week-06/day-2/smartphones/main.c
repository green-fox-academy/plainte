#include <stdio.h>

/* Create a smartphone register application
 * Read the content of smartphones.txt and store the informations in a structure called "smartphone:
 * - the name of the gadget (which is shorter than 256 characters) (Don't bother with the underscore('_') character, it's the part of the name)
 * - the year of the release (e.g. 2016)
 * - the type of the screen size (as a custom type, see below)
 *
 * In the file the size is given in cm but you should store the screen size type in an enumeration ("screen_size"),
 * the valid types are:
 *  - BIG -> (>= 15 cm)
 *  - MEDIUM -> (>= 12 cm)
 *  - SMALL -> (< 12 cm)
 *
 * The smartphones should be stored in an array.
 *
 * Implement the following functions:
 * - get_oldest_phone()
 *    - it should return the name of oldest device
 *    - it is up to you how your function declaration looks like (return type and arguments)
 * - get_screen_size_count()
 *    - it returns the count of phones which has "screen_size" size
 *    - it is up to you how your function declaration looks like (return type and arguments)
 *
 * Your main function should invoke these functions and print the following:
 * The ..... is the oldest device in the database
 * There are .... phones with BIG (>= 15 cm) screen size
 * There are .... phones with SMALL (< 12 cm) screen size
 *
 *
 * Additionally, you need to create a new file(prices.txt) that looks like this:
 * <NAME> <PRICE>
 * <NAME> <PRICE>
 * .
 * .
 * .
 *
 * To calculate the price use the following method. The base price of every phone is 300$.
 * If the size is SMALL, that adds 0$ to the value
 * If the size is MEDIUM, that adds 100$ to the value
 * If the size is BIG, that doubles the base price.
 *
 * The price also depends on the age. For every year that passed since its release,
 * the phone loses 50$ but the maximum value that it can lose because of the age is 250$
 */
enum screen_size_type
{
    BIG,
    MEDIUM,
    SMALL
};

typedef struct smartphone
{
    char name[254];
    int year;
    enum screen_size_type size_type;
} smartphone_t;

void read_file_into_structure(const char *path, smartphone_t *smartphone, int s_length);

int count_lines_in_file(const char *path);

char *get_oldest_phone(smartphone_t *smartphone, int s_length);

int get_screen_size_count(smartphone_t *smartphone, int s_length, enum screen_size_type scrs);

int main()
{
    // count lines counting lines in file
    smartphone_t smartphones[count_lines_in_file("../phones.txt")];
    int smartphones_length = sizeof(smartphones) / sizeof(*smartphones);
    //read file into structure
    read_file_into_structure("../phones.txt", smartphones, smartphones_length);
    // test if reading was successful
    for (int i = 0; i < smartphones_length; i++) {
        printf("%s %d %d\n", smartphones[i].name, smartphones[i].year, smartphones[i].size_type);
    }
    // test get_oldest_phone function
    printf("The oldest phone in the file is: %s\n", get_oldest_phone(smartphones, smartphones_length));
    // test get_screen_size_count function
    printf("The given size was found: %d times\n", get_screen_size_count(smartphones,smartphones_length, BIG));
    return 0;
}

void read_file_into_structure(const char *path, smartphone_t *smartphone, int s_length)
{
    FILE *fptr = fopen(path, "r");

    if (fptr == NULL) {
        printf("The file does not exist!\n");
    }
    int size;
    int i = 0;
    while (fscanf(fptr, "%s %d %d", smartphone[i].name, &smartphone[i].year, &size)) {
        if (i > s_length) {
            break;
        } else {
            if (size < 12) {
                smartphone[i].size_type = SMALL;
                i++;
            } else if (size >= 12 && size < 15) {
                smartphone[i].size_type = MEDIUM;
                i++;
            } else if (size >= 15) {
                smartphone[i].size_type = BIG;
                i++;
            }
        }
    }
}

int count_lines_in_file(const char *path)
{
    FILE *fptr = fopen(path, "r");
    int ch = 0;
    int lines = 1;
    if (fptr == NULL) {
        return 0;
    }
    while(!feof(fptr)) {
        ch = fgetc(fptr);
        if (ch == '\n') {
            lines++;
        }
    }
    return lines;
}

char *get_oldest_phone(smartphone_t *smartphone, int s_length)
{
    int index = 0;
    int oldest_phone = smartphone[0].year;
    for (int i = 0; i < s_length; i++) {
        if (smartphone[i].year < oldest_phone) {
            oldest_phone = smartphone[i].year;
            index = i;
        }
    }
    return smartphone[index].name;
}

int get_screen_size_count(smartphone_t *smartphone, int s_length, enum screen_size_type scrs)
{
    int count = 0;
    for (int i = 0; i < s_length; i++) {
        if (smartphone[i].size_type == scrs) {
            count++;
        }
    }
    return count;
}
