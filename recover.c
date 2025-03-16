#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // Accept a single command-line argument
    if (argc != 2)
    {
        printf("Usage: ./recover FILE\n");
        return 1;
    }

    // Open the memory card
    FILE *card = fopen(argv[1], "r");

    // Create a buffer for a block of data
    uint8_t buffer[512];

    // While there's still data left to read from the memory card
    while (fread(buffer, 1, 512, card) == 512)
    {
        // Create JPEGs from the data

    }
}
// JPEG?:
    // buffer[0] == 0x && buffer[1] == 0x && buffer[2] == 0x && (buffer[3] & 0xf0) == 0xe0)
// Making a New JPEG:
    // Filenames ###.jpg, starting at 000.jpg
    //sprintf(filename, "%03i.jpg", count);
    //FILE *img = fopen(filename, "w");
// Writing Files
    //fwrite(pointer files to be written to, size of each element, number of elements to write, FILE *outptr):

/*
Open memory card
Repeat until end of card:
    Read 512 bytes into buffer
    If start of new JPEG
        If first JPEG
            ...
        Else
            ...
    Else
        If already found JPEG
            ...
Close any remaining files
*/
