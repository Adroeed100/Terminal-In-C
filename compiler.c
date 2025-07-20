#include <stdio.h>
#include <stdlib.h>

int main() {
    int compileStatus = system("gcc File_handling.c -o Terminal.exe");

    if(compileStatus != 0) {
        printf("Compilation Failed\n");
        return 1;
    }

    int runStatus = system("Terminal.exe");

    if(runStatus != 0) {
        printf("Execution error");
        return 1;
    }
    return 1;
}