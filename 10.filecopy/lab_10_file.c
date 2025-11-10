//pavan bokare-IT-B-153
/*AIM: Write a C program  that copies the contents of one file to a destination file. This program will read data from one file and copy them to another. The first input that the program will need is the names of the two files: input file ("input.txt") and output file ("output.txt"). Once the two file names have been obtained, the program must open the input file and create and open the output file.*/
#include <stdio.h>

int main() {
    FILE *f1, *f2;
    char ch;

    f1 = fopen("input.txt", "r");
    f2 = fopen("output.txt", "w");

    if(f1 == NULL) {
        printf("Error: input.txt file does not exist.\n");
        return 1;
    }
    while((ch = fgetc(f1)) != EOF) {
        fputc(ch, f2);
    }
    printf("Your file is copied successfully.\n");

    fclose(f1);
    fclose(f2);
    return 0;
}