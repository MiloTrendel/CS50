#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }

    FILE *input = fopen(argv[1], "r");

    if (input == NULL)
    {
        printf("Could not open file\n");
        return 2;
    }

    unsigned char buffer[512];

    int image_count = 0;

    FILE *output = NULL;

    char *filename = malloc(8 * sizeof(char));

    while (fread(buffer, sizeof(char), 512, input))
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if (image_count > 0)
            {
                fclose(output);
            }
            sprintf(filename, "%03i.jpg", image_count);
            output = fopen(filename, "w");
            image_count++;
        }
        if (output != NULL)
        {
            fwrite(buffer, sizeof(char), 512, output);
        }
    }
    free(filename);
    fclose(output);
    fclose(input);

    return 0;
}