#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <dirent.h>

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

        for (int i = 0; i < command[i] != '\0'; i++) //removes case sensitivity
        {
            command[i] = tolower(command[i]);
        }

        if (count >= 1 && strcmp(command, "mkfile") == 0) //creates a file
        {
            {
                if (count < 2)
                {
                    printf("Error: Please provide appropriate filename\n");
                    continue;
                }
            }

            FILE *f = fopen(filename, "w");
            if (f == NULL)
            {
                perror("Error creating file");
                continue;
            }

            char text[500];
            printf("Enter the text \n");
            fgets(text, sizeof(text), stdin);
            text[strcspn(text, "\n")] = 0;

            fwrite(text, sizeof(char), strlen(text), f);
            fclose(f);
            printf("File '%s' has been created\n", filename);
        }
        else if (strcmp(command, "ls") == 0) //displays the files inside a directory 
        {
            struct dirent *de;
            DIR *dr = opendir(".");

            if (dr == NULL)
            {
                perror("no files in drirectory");
                continue;
            }

            while ((de = readdir(dr)) != NULL)
            {
                printf("%s\t", de->d_name);
            }
            printf("\n");

            closedir(dr);
        }
        else if (count >= 1 && strcmp(command, "mkdir") == 0) //creates a directory 
        {
            if (count < 2)
            {
                printf("Please provide appropriate folder name\n");
                continue;
            }
            else
            {
                if (mkdir(filename) == 0)
                {
                    printf("Foler '%s' created successfully\n", filename);
                }
                else
                {
                    printf("Folder not created not created\n");
                }
            }
        } 
        else if(count>=1 && strcmp(command, "rmdir")==0) //removes directory
        {
            if(count<2) {
                printf("Error: Enter appropriate directory name\n");
                continue;
            }

            if(rmdir(filename) == 0) {
                printf("folder '%s' removed\n", filename);
            } else {
                printf("Error: Cannot remove folder\n");
                continue;
            }

        }
        else if(count>=1 && strcmp(command, "rmfile")==0) //removes a file
        {
            if(count<2) {
                printf("Error: Enter appropriate filename\n");
                continue;
            }

            if(remove(filename)==0) {
                printf("File '%s' removed\n", filename);
            } else {
                printf("Error: Cannot remove file\n");
            }

        }
        else if (strcmp(command, "exit") == 0) //exits the terminal 
        {
            break;
        }
        else //if the command is invalid
        {
            printf("Unknown command.\n");
        }
    }
    return 0;
}
