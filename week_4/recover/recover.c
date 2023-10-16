#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t  BYTE;

int main(int argc, char *argv[])
{

    // Checking if the user entered a correct input:
    if (argc != 2) {
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }

    // Opening the file in argv[1]
    FILE *infile = fopen(argv[1], "r");

    // Validating that there's a file in argv[1]
    if (infile == NULL) {
        printf("Could not open file\n");
        return 1;
    }

    BYTE buffer[512];
    int num_subtitute = 0;
    FILE *image_recovered = NULL;

    while (fread(buffer, 512, 1, infile) == 1) {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff &&
            (buffer[3] & 0xf0) == 0xe0) {
            if (image_recovered != NULL)
                fclose(image_recovered);
            char filename[8];

            sprintf(filename, "%03i.jpg", num_subtitute);
            image_recovered = fopen(filename, "w");
            if (image_recovered == NULL) {
                printf("Couldn't open file\n");
                return 1;
            }
            num_subtitute++;
        }

        if (image_recovered != NULL)
            fwrite(buffer, 512, 1, image_recovered);
    }

    if (image_recovered != NULL)
        fclose(image_recovered);
    fclose(infile);
}
