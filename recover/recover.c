#include <stdio.h>
#include <stdlib.h>
#include<stdint.h>


int main(int argc, char *argv[])
{
    FILE* input = NULL;
    if(!(argc == 2))
    {
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }
    else
    {
        char* file = argv[1];
        input = fopen(file, "r");
        if(input == NULL)
        {
            printf("can't open file\n");
            return 1;
        }
    }
    uint8_t buffer[512];
    int count = 0;
    FILE* output = NULL;
    char filename[8];

    while (fread(&buffer, 512, 1, input) == 1)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if(count != 0)
            {
                fclose(output);
            }

            sprintf(filename, "%03i.jpg", count);
            output = fopen(filename, "w");
            count++;
        }

        if(count != 0)
        {
            fwrite(&buffer, 512, 1, output);
        }
    }

    fclose(input);
    fclose(output);

    return 0;
}