#include <stdio.h>
#include <string.h>

/* Digimon database!
 * You should store the following data in a structure
 *  - the name of the digimon (which is shorter than 128 characters)
 *  - the age of the digimon (in years)
 *  - the health of the digimon (between 0-100)
 *  - the name of the tamer (which is shorter than 256 characters)
 *  - the digivolution level of the digimon (as a custom type, see below)
 *
 * You should store the digivolution level in an enumeration
 * the valid digivolution levels are:
 *  - baby
 *  - in-training
 *  - rookie
 *  - champion
 *  - ultimate
 *  - mega
 *
 * The digimons are stored in an array.
 *
 * Write the following functions:
 * 1) Get minimum health index
 *      - parameters:
 *          - array
 *          - array length
 *      - it returns the index of the minimal health digimon in the "array"
 * 2) Get same digivolution level count
 *      - parameters:
 *          - array
 *          - array length
 *          - digivolution level
 *      - it returns the count of digimons which are at "digivolution level"
 * 3) Get same tamer count
 *      - parameters:
 *          - array
 *          - array length
 *          - tamer name
 *      - it returns the count of the digimons which have the same tamer as "tamer name"
 * 4) Get average health of the same tamer
 *      - parameters:
 *          - array
 *          - array length
 *          - tamer name
 *      - it returns the average health of the digimons which have the same tamer as "tamer name"
 *
 * Don't forget to handle invalid inputs (NULL pointers, invalid values etc.)
 */
enum digivolution
{
    BABY,
    IN_TRAINING,
    ROOKIE,
    CHAMPION,
    ULTIMATE,
    MEGA
};

typedef struct digimon
{
    char name[125];
    int age;
    int hp;
    char tamer_name[254];
    enum digivolution d_level;
} digimon_t;

int get_minimum_health_index(digimon_t *digimons, int array_length);

int get_digivolution_count(digimon_t *digimons, int array_length, enum digivolution dgvlt);

int get_same_tamer_count(digimon_t *digimons, int array_length, const char *tamer_name);

int get_average_health(digimon_t *digimons, int array_length, const char *tamer_name);

int main()
{
    digimon_t digimons[10];
    //creating HP for digimons
    digimons[0].hp = 100;
    digimons[1].hp = 90;
    digimons[2].hp = 80;
    digimons[3].hp = 70;
    digimons[4].hp = 81;
    digimons[5].hp = 20;
    digimons[6].hp = 35;
    digimons[7].hp = 55;
    digimons[8].hp = 72;
    digimons[9].hp = 99;
    int digimons_length = sizeof(digimons) / sizeof(*digimons);
    //printing out the index of lowest health digimon
    printf("The minimum health digimon's index is %d\n", get_minimum_health_index(digimons, digimons_length));
    //creating ENUM DIGIVOLUTION for digimons
    digimons[0].d_level = BABY;
    digimons[1].d_level = BABY;
    digimons[2].d_level = IN_TRAINING;
    digimons[3].d_level = IN_TRAINING;
    digimons[4].d_level = ROOKIE;
    digimons[5].d_level = ULTIMATE;
    digimons[6].d_level = CHAMPION;
    digimons[7].d_level = ULTIMATE;
    digimons[8].d_level = ULTIMATE;
    digimons[9].d_level = MEGA;
    printf("Found %d digimons with the same digivolution level\n", get_digivolution_count(digimons, digimons_length, ULTIMATE));
    //creating tamer name for digimons
    char *tamer_name1 = "Peter";
    char *tamer_name2 = "Daniel";
    char *tamer_name3 = "Lilla";
    char *tamer_name4 = "Hannah";
    strcpy(digimons[0].tamer_name, tamer_name1);
    strcpy(digimons[1].tamer_name, tamer_name2);
    strcpy(digimons[2].tamer_name, tamer_name2);
    strcpy(digimons[3].tamer_name, tamer_name3);
    strcpy(digimons[4].tamer_name, tamer_name4);
    strcpy(digimons[5].tamer_name, tamer_name2);
    strcpy(digimons[6].tamer_name, tamer_name1);
    strcpy(digimons[7].tamer_name, tamer_name3);
    strcpy(digimons[8].tamer_name, tamer_name4);
    strcpy(digimons[9].tamer_name, tamer_name4);
    //printing out the amount of given tamer name found
    printf("%d digimons has the same tamer\n", get_same_tamer_count(digimons, digimons_length, tamer_name1));
    //printing the average health for digimons
    printf("The average health of the digimons whose tamer is the same is: ");
    printf("%d\n", get_average_health(digimons, digimons_length, tamer_name4));
    return 0;
}

int get_minimum_health_index(digimon_t *digimons, int array_length)
{
    int min_health = digimons[0].hp;
    int index = 0;
    for (int i = 0; i < array_length; i++) {
        if (digimons[i].hp < min_health) {
            min_health = digimons[i].hp;
            index = i;
        }
    }
    return index;
}

int get_digivolution_count(digimon_t *digimons, int array_length, enum digivolution dgvlt)
{
    int count = 0;
    for (int i = 0; i < array_length; i++) {
        if (digimons[i].d_level == dgvlt) {
            count++;
        }
    }
    return count;
}

int get_same_tamer_count(digimon_t *digimons, int array_length, const char *tamer_name)
{
    int count = 0;
    for (int i = 0; i < array_length; i++) {
        int n = stricmp(digimons[i].tamer_name, tamer_name);
        if (n == 0) {
            count++;
        }
    }
    return count;
}

int get_average_health(digimon_t *digimons, int array_length, const char *tamer_name)
{
    int sum = 0;
    int count = 0;
    for (int i = 0; i < array_length; i++) {
        int n = stricmp(digimons[i].tamer_name, tamer_name);
        if (n == 0) {
            sum += digimons[i].hp;
            count++;
        }
    }
    return sum / count; //average health
}
