#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <dirent.h> 
#include "uses.h"

int main()
{
    while (1)
    {
        char input[100];
        char command[20];
        char filename[80];

        printf(">>> ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = 0;

        int count = sscanf(input, "%s %s", command, filename);

        for (int i = 0; i < command[i] != '\0'; i++)
        {
            command[i] = tolower(command[i]);
        }

        if (count >= 1 && strcmp(command, "mkfile") == 0) {
        {
            if (count < 2)
            {
                printf("Error: Please provide appropriate filename\n");
                continue;
            }
        }
        char text[500];
        printf("Enter the text \n");
        fgets(text, sizeof(text), stdin);
        text[strcspn(text, "\n")] = 0;
        
        if (strlen(text) == 0)
        {
            printf("File was not created (no text provided) \n");
            continue;
        }
        else
        {
            FILE *f = fopen(filename, "w");
            if (f == NULL)
            {
                perror("Error creating file");
                continue;
            }
            fwrite(text, sizeof(char), strlen(text), f);
            fclose(f);
            printf("File '%s' has been created\n", filename);
        }
    }
    else if(strcmp(command, "ls") == 0)
    {
        struct dirent *de;
        DIR *dr = opendir(".");

        if(dr == NULL) {
            perror("No file in the directory");
            continue;
        }

        while((de = readdir(dr)) != NULL) 
        {
            printf("%s\n", de->d_name);
        }

        closedir(dr);
    }    
    else if (strcmp(command, "exit") == 0)
    {
        break;
    }
    else
    {
        printf("Unknown command.\n");
    }
}
return 0;
}
