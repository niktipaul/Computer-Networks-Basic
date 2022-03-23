// Write a program to implement cp command


#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){

    FILE *from_copy_file, *to_copy_file;

    from_copy_file = fopen(argv[1],"r");
    to_copy_file = fopen(argv[2],"w");

    char current;
    do{
        current = fgetc(from_copy_file);

        if (current != EOF)
            fputc(current,to_copy_file);

    }while(current !=  EOF);


    fclose(from_copy_file);
    fclose(to_copy_file);
    return 0;

}
