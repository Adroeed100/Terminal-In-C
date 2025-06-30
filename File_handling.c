#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int main() {
    
    while(1) {
        char c[50];
        printf(">>> ");
        scanf("%s", &c);
    
        if(strcmpi(c,"mkfile")==0)
        {
            FILE *f;

            f = fopen("welcome.txt", "w");
            if (f == NULL) {
                perror("Error");
                return 1; 
            }
        
            const char *text = "Hello! nigga Wassup";
            fwrite(text, sizeof(char), strlen(text), f);
        
            fclose(f);
        
            printf("File has been created successfully\n");   
        }
        else if(strcmpi(c,"exit")==0)
        {
            return 1;
        }

}
}
