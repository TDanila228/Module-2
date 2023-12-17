#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "replace.h"

void replace_to_0(const char* inputFileName, const char* outputFileName)
{
    FILE* inputFile;
    FILE* outputFile;
    errno_t errInput, errOutput;

    errInput = fopen_s(&inputFile, inputFileName, "r");
    errOutput = fopen_s(&outputFile, outputFileName, "w");

    if (errInput != 0 || errOutput != 0 || inputFile == NULL || outputFile == NULL)
    {
        printf("Error. Files not found.\n");
        return;
    }

    char buffer[9999];
    while (fgets(buffer, sizeof(buffer), inputFile) != NULL)
    {
        char* pos = strstr(buffer, "-+");
        while (pos != NULL)
        {
            *pos = '0';
            memmove(pos + 1, pos + 2, strlen(pos + 2) + 1);
            pos = strstr(pos + 1, "-+");
        }
        fputs(buffer, outputFile);
    }

    fclose(inputFile);
    fclose(outputFile);
}