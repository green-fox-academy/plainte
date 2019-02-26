#include <stdio.h>
#include <stdint.h>

// Use the Computer struct, give values to the fields and print them out in the main!
// Use the Notebook struct, give values to the fields and print them out in the main!

struct Computer {
    float cpu_speed_GHz;
    int ram_size_GB;
    int bits;
};

typedef struct {
    float cpu_speed_GHz;
    int ram_size_GB;
    int bits;
} Notebook;

int main()
{
    struct Computer computer;

    computer.bits = 64;
    computer.cpu_speed_GHz = 2.1;
    computer.ram_size_GB = 8;

    Notebook notebook;

    notebook.bits = 64;
    notebook.cpu_speed_GHz = 2.1;
    notebook.ram_size_GB = 4;

    printf("Computer bits: %d\ncpu_speed: %.2f\nram_size_GB: %d\n",
            computer.bits, computer.cpu_speed_GHz, computer.ram_size_GB);

    printf("Notebook bits: %d\ncpu_speed: %.2f\nram_size_GB: %d\n",
            notebook.bits, notebook.cpu_speed_GHz, notebook.ram_size_GB);

    return 0;
}